
/*
**---------------------------------------------------------------------------
** OpenChasm - Free software reconstruction of Chasm: The Rift game
** Copyright (C) 2013, 2014 Alexey Lysiuk
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**---------------------------------------------------------------------------
*/

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <vector>


static std::vector<std::string> s_tdump;


// --------------------------------------------------------------------------


struct Symbol
{
	std::string name;

	static const uint16_t DEFAULT_VALUE = 0xFFFF;

	uint16_t segment; // for non-import symbol only
	uint16_t offset;  // for non-import symbol only

	uint16_t type;
	uint16_t ordinal; // for import only

	uint16_t localsIndex;
	uint16_t localsCount;

	Symbol()
	: segment(DEFAULT_VALUE)
	, offset(DEFAULT_VALUE)
	, type(DEFAULT_VALUE)
	, ordinal(DEFAULT_VALUE)
	, localsIndex(DEFAULT_VALUE)
	, localsCount(0)
	{
	}
};


typedef std::vector<Symbol> SymbolList;
static SymbolList s_symbols;


static void MakeGlobalSymbolsUnique()
{
	std::set<std::string> uniqueSymbols;

	for (auto symbol = s_symbols.begin(); s_symbols.end() != symbol; ++symbol)
	{
		if (0 == symbol->segment || symbol->segment > 11)
		{
			// HARDCODE: this is not code or data segment
			continue;
		}

		if ("VGA" == symbol->name)
		{
			// HARDCODE: fix "failed to add constant VGA=9" error
			symbol->name = "_VGA";
		}

		if (uniqueSymbols.end() != uniqueSymbols.find(symbol->name))
		{
			std::string newName;
			int counter = 0;

			do
			{
				char buf[16] = {};
				snprintf(buf, sizeof(buf), "__%X", counter++);

				newName = symbol->name + buf;
			}
			while (uniqueSymbols.end() != uniqueSymbols.find(newName));

			symbol->name = newName;
		}

		uniqueSymbols.insert(symbol->name);
	}

}

static bool LoadSymbols()
{
	// Symbol indices start with 1
	s_symbols.push_back(Symbol());

	auto it = std::find(s_tdump.begin(), s_tdump.end(), "Local Symbols");

	if (s_tdump.end() == it)
	{
		puts("Unable to find symbols in TDUMP text");
		return false;
	}

	// Skip marker and following empty line
	std::advance(it, 2);

	// Formats:
	//   XXXX: XXXX:XXXX Type: XXXX Class: X BP: X Offs: XX [xXXX]  Symbol
	//   XXXX: KERNEL  .dDD   Type: XXXX Class: X BP: X Offs: XX [xXXX]  Symbol
	// Where:
	//   X - hex digit, x - optional hex digit,
	//   D - decimal digit, d - optional decimal digit,

	for (/* EMPTY */; s_tdump.end() != it; ++it)
	{
		if (it->empty())
		{
			break;
		}

		Symbol symbol;
		int dummy;
		char name[128] = {};

		int result = sscanf(it->c_str(),
			"%4x: %4hx:%4hx Type: %4hx Class: %1x BP: %1x Offs: %2x [%x] %s",
			&dummy, &symbol.segment, &symbol.offset, &symbol.type, &dummy, &dummy, &dummy, &dummy, name);

		if (1 == result)
		{
			result = sscanf(it->c_str(),
				"%4x: KERNEL .%hu Type: %4hx Class: %1x BP: %1x Offs: %2x [%x] %s",
				&dummy, &symbol.ordinal, &symbol.type, &dummy, &dummy, &dummy, &dummy, name);
		}

		if (8 != result && 9 != result)
		{
			printf("Failed to parse symbol at line %lu\n", it - s_tdump.begin());
			return false;
		}

		symbol.name = name;

		s_symbols.push_back(symbol);
	};

	MakeGlobalSymbolsUnique();

	return true;
}


// --------------------------------------------------------------------------


bool LoadScopes()
{
	auto it = std::find_if(s_tdump.begin(), s_tdump.end(), [](const std::string& line)
	{
		return 0 == line.find("Scopes Table");
	});

	if (s_tdump.end() == it)
	{
		puts("Unable to find scopes in TDUMP text");
		return false;
	}

	// Skip marker and following empty line
	std::advance(it, 2);

	// Format:
	//   Scope # XXX:
    //     Autos Index:        XXXX    Autos Count:        XXXX
    //     Parent Scope:       XXXX    Function Symbol:    XXXX
    //     Scope Offset:       XXXX    Scope Length:       XXXX

	bool isParseOk = true;

	while (0 == it->find("  Scope #"))
	{
		uint16_t index, count, parent, function;

		int parseResult = sscanf((++it)->c_str(), 
			" Autos Index: %4hx Autos Count: %4hx", &index, &count);

		if (2 != parseResult)
		{
			isParseOk = false;
			break;
		}

		parseResult = sscanf((++it)->c_str(), 
			" Parent Scope: %4hx Function Symbol: %4hx", &parent, &function);

		if (2 != parseResult)
		{
			isParseOk = false;
			break;
		}

		// TODO: handle FFFF function symbol (module scope)

		if (0xFFFE != function && 0xFFFF != function)
		{
			if (0 == function || s_symbols.size() <= function || 0 == index)
			{
				isParseOk = false;
				break;
			}

			Symbol& symbol = s_symbols[function];
			symbol.localsIndex = index;
			symbol.localsCount = count;
		}

		// Skip last unused and empty lines
		std::advance(it, 3);
	}

	if (!isParseOk)
	{
		printf("Failed to parse scope at line %lu\n", it - s_tdump.begin());
	}

	return isParseOk;
}


// --------------------------------------------------------------------------


struct Type
{
	std::string name;
	uint16_t size;

	Type()
	: size(0)
	{
	}
};


typedef std::vector<Type> TypeList;
static TypeList s_types;


bool LoadTypes()
{
	auto it = std::find_if(s_tdump.begin(), s_tdump.end(), [](const std::string& line)
	{
		return 0 == line.find("Types Table");
	});

	if (s_tdump.end() == it)
	{
		puts("Unable to find types in TDUMP text");
		return false;
	}

	// Skip marker and following empty line
	std::advance(it, 2);

	// Format:
	//   Type Number:  XXX  name-of-type
	//	   Type ID:         XX		Type Name:     XXXX
	//	   Type Size:     XXXX		Type Record:   XX XXXX

	bool isParseOk = true;

	while (true)
	{
		const char* const MARKER = "  Type Number:";

		if (0 != it->find(MARKER))
		{
			// Skip hex sequence line and try again
			std::advance(it, 2);

			if (0 != it->find(MARKER))
			{
				break;
			}
		}

		// Type number (index) begins with position 15, name begins with position 21
		// Type numbers (indices) start with 1

		if (it->size() < 22)
		{
			isParseOk = false;
			break;
		}

		const char* const line = it->c_str();
		const unsigned long index = strtol(&line[15], NULL, 16);

		Type type;
		type.name = &line[21];

		if (type.name.empty() || 0 == index)
		{
			isParseOk = false;
			break;
		}

		// Skip unused line
		std::advance(it, 2);

		const int parseResult = sscanf(it->c_str(), " Type Size: %4hx Type Record:", &type.size);

		if (1 != parseResult)
		{
			isParseOk = false;
			break;
		}

		// Fill gaps between types to simplify indexing
		while (s_types.size() < index)
		{
			s_types.push_back(Type());
		}

		s_types.push_back(type);

		// Skip empty line
		std::advance(it, 2);
	}

	if (!isParseOk)
	{
		printf("Failed to parse type at line %lu\n", it - s_tdump.begin());
	}

	return isParseOk;
}


// --------------------------------------------------------------------------


void MakeScript()
{
	puts("#include <idc.idc>\n\nstatic main()\n{\n\tauto ea;\n");

	// HARDCODE: fix a few "can't rename byte as '...' "
	// "because this byte can't have a name (it is a tail byte)." errors
	puts(
		"\tMakeUnkn(0x36CD6, DOUNK_SIMPLE);\n"
		"\tMakeUnkn(0x36CDE, DOUNK_SIMPLE);\n"
		"\tMakeUnkn(0x44A82, DOUNK_SIMPLE);\n"
		"\tMakeUnkn(0x44B5C, DOUNK_SIMPLE);\n"
		"\tMakeUnkn(0x44E34, DOUNK_SIMPLE);\n"
		"\tMakeUnkn(0x45B62, DOUNK_SIMPLE);\n");

	for (auto symbol = s_symbols.begin(); s_symbols.end() != symbol; ++symbol)
	{
		if (Symbol::DEFAULT_VALUE != symbol->ordinal)
		{
			printf("\tMakeName(LocByName(\"KERNEL_%hu\"), \"%s\");\n",
				   symbol->ordinal, symbol->name.c_str());
			continue;
		}

		if (0 == symbol->segment || symbol->segment > 11)
		{
			// HARDCODE: this is not code or data segment
			continue;
		}

		static const char* SEGMENT_NAMES[] = // HARDCODE
		{
			"",
			"cseg01", "cseg02", "cseg03", "cseg04", "cseg05",
			"cseg06", "cseg07", "cseg08", "cseg09", "cseg10",
			"dseg11", "dseg12", 
		};

		const char* const segmentName = SEGMENT_NAMES[symbol->segment];
		const char* const symbolName = symbol->name.c_str();
		const char* const typeName = s_types[symbol->type].name.c_str();

		printf("\tea = MK_FP(SegByName(\"%s\"), 0x%04hx);\n\tMakeName(ea, \"%s\");\n",
			segmentName, symbol->offset, symbolName);

		// HARDCODE: select comment depending on segment
		if (symbol->segment < 10)
		{
			printf("\tSetFunctionCmt(ea, \"%s\", 1);\n", typeName); // Code segment
		}
		else
		{
			printf("\tMakeRptCmt(ea, \"%s\");\n", typeName); // Data segment
		}

		for (uint16_t i = 0; i < symbol->localsCount; ++i)
		{
			const Symbol& localSymbol = s_symbols[symbol->localsIndex + i];
			const char* const localSymbolName = localSymbol.name.c_str();

			if (0 ==localSymbol.segment)
			{
				printf("\tMakeLocal(ea, 0, \"[bp%+hi]\", \"%s\");\n",
					int16_t(localSymbol.offset), localSymbolName);
			}
			else
			{
				// TODO: figure out why a few global symbols are marked as locals
				// Pascal inner/nested functions ???
				printf("\t// Symbol '%s' is global\n", localSymbolName);
			}
		}
	}

	puts("}");
}


// --------------------------------------------------------------------------


static void EraseChar(std::string& str, const char ch)
{
	while (true)
	{
		const size_t pos = str.find_last_of(ch);

		if (std::string::npos == pos)
		{
			return;
		}

		str.erase(pos, 1);
	}
}


// --------------------------------------------------------------------------


int main(int argc, char** argv)
{
	if (argc < 2)
	{
		puts("Usage: tdump2idc tdump_text_file");
		return EXIT_SUCCESS;
	}

	FILE* f = fopen(argv[1], "r");

	if (NULL == f)
	{
		printf("Unable to open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	while (!feof(f))
	{
		char buf[1024];
		fgets(buf, sizeof(buf), f);

		std::string line = buf;
		EraseChar(line, '\n');
		EraseChar(line, '\r');

		s_tdump.push_back(line);
	}

	fclose(f);

	const bool result = LoadSymbols() && LoadScopes() && LoadTypes();

	MakeScript();

	return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
