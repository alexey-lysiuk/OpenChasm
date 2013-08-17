
/*
**---------------------------------------------------------------------------
** OpenChasm - Free software reconstruction of Chasm: The Rift game
** Copyright (C) 2013 Alexey Lysiuk
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

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stdint.h>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <vector>


class File
{
public:
	explicit File(const char* const name)
	: m_file(fopen(name, "rb"))
	, m_name(name)
	{

	}

	~File()
	{
		if (NULL != m_file)
		{
			fclose(m_file);
			m_file = NULL;
		}
	}

	bool isOpened() const
	{
		return NULL != m_file;
	}

	const char* filename() const
	{
		return m_name.c_str();
	}

	bool read(void* const buffer, const size_t length)
	{
		assert(NULL != m_file);
		return length == fread(buffer, 1, length, m_file);
	}

	bool seek(const long offset, const int origin)
	{
		assert(NULL != m_file);
		return 0 == fseek(m_file, offset, origin);
	}

	int readChar()
	{
		assert(NULL != m_file);
		return fgetc(m_file);
	}

	bool isEOF() const
	{
		assert(NULL != m_file);
		return feof(m_file) > 0;
	}

private:
	FILE*       m_file;
	std::string m_name;

	// Without implementation
	File(const File&);
	File& operator=(const File&);

};


//---------------------------------------------------------------------------


// Turbo Debugger Symbols (TDS)
// All structures are packed to 1-byte boundary so expect unaligned access
// All numbers are little endian

struct TDS
{
#pragma pack(push, 1)

	struct Symbol
	{
		uint16_t name;
		uint16_t type;

		uint16_t offset;
		uint16_t segment;

		uint8_t  flags;

		Symbol() { memset(this, 0, sizeof *this); }
	};

	struct Module
	{
		uint16_t name;

		uint8_t  language;
		uint8_t  flags;

		uint16_t symbolIndex;
		uint16_t symbolCount;

		uint16_t sourceIndex;
		uint16_t sourceCount;

		uint16_t correlationIndex;
		uint16_t correlationCount;

		Module() { memset(this, 0, sizeof *this); }
	};

	struct Source
	{
		uint16_t name;
		uint32_t date;

		Source() { memset(this, 0, sizeof *this); }
	};

	struct Line
	{
		uint16_t line;
		uint16_t offset;

		Line() { memset(this, 0, sizeof *this); }
	};

	struct Scope
	{
		uint16_t index;
		uint16_t count;

		uint16_t parentScope;
		uint16_t symbol;

		uint16_t offset;
		uint16_t length;

		Scope() { memset(this, 0, sizeof *this); }
	};

	struct Segment
	{
		uint16_t moduleIndex;
		uint16_t codeSegment;
		uint16_t codeOffset;
		uint16_t codeLength;
		uint16_t scopeIndex;
		uint16_t scopeCount;
		uint16_t correlationIndex;
		uint16_t correlationCount;

		Segment() { memset(this, 0, sizeof *this); }
	};

	struct Correlation
	{
		uint16_t segmentIndex;
		uint16_t fileIndex;
		uint16_t lineIndex;
		uint16_t lineCount;

		Correlation() { memset(this, 0, sizeof *this); }
	};

	struct Type
	{
		uint8_t  id;
		uint16_t name;
		uint16_t size;
		uint8_t  record[3];

		Type() { memset(this, 0, sizeof *this); }
	};

	struct Member
	{
		uint8_t info;
		uint16_t name;
		uint16_t type;

		Member() { memset(this, 0, sizeof *this); }
	};

	// TODO:
	// - Class Table
	// - Parent Table
	// - Overload Table

	struct ScopeClass
	{
		uint16_t index;
		uint16_t count;

		ScopeClass() { memset(this, 0, sizeof *this); }
	};

	struct ModuleClass
	{
		uint16_t classIndex;
		uint16_t classCount;

		uint16_t overloadIndex;
		uint16_t overloadCount;

		ModuleClass() { memset(this, 0, sizeof *this); }
	};


	struct Header
	{
		uint16_t magic;
		uint16_t version;

		uint32_t poolSize;

		uint16_t nameCount;
		uint16_t typeCount;
		uint16_t memberCount;
		uint16_t symbolCount;
		uint16_t globalSymbolCount;
		uint16_t moduleCount;
		uint16_t localSymbolCount;
		uint16_t scopeCount;
		uint16_t lineCount;
		uint16_t sourceCount;
		uint16_t segmentCount;
		uint16_t correlationCount;
		uint8_t  unused1[11];

		uint16_t dataCount;
		uint8_t  unused2[3];

		uint16_t classCount;
		uint16_t globalClassCount;
		uint16_t parentEntryCount;
		uint16_t overloadEntryCount;
		uint16_t scopeClassCount;
		uint16_t moduleClassCount;
		uint16_t coverageCount;
		uint8_t  unused3[2];

		Header() { memset(this, 0, sizeof *this); }

		template <typename Entry> uint16_t count() const;

	};

#pragma pack(pop)

	Header                   header;
	std::vector<Symbol>      symbols;
	std::vector<Module>      modules;
	std::vector<Source>      sources;
	std::vector<Line>        lines;
	std::vector<Scope>       scopes;
	std::vector<Segment>     segments;
	std::vector<Correlation> correlations;
	std::vector<Type>        types;
	std::vector<Member>      members;
	std::vector<ScopeClass>  scopeClasses;
	std::vector<ModuleClass> moduleClasses;
	std::vector<std::string> names;

	bool load(const char* const filename);
	bool load(File& file);

private:
	template <typename Entry>
	bool load(File& inputFile, std::vector<Entry>& outputList);

};


template<> uint16_t TDS::Header::count<TDS::Symbol     >() const { return symbolCount;      }
template<> uint16_t TDS::Header::count<TDS::Module     >() const { return moduleCount;      }
template<> uint16_t TDS::Header::count<TDS::Source     >() const { return sourceCount;      }
template<> uint16_t TDS::Header::count<TDS::Line       >() const { return lineCount;        }
template<> uint16_t TDS::Header::count<TDS::Scope      >() const { return scopeCount;       }
template<> uint16_t TDS::Header::count<TDS::Segment    >() const { return segmentCount;     }
template<> uint16_t TDS::Header::count<TDS::Correlation>() const { return correlationCount; }
template<> uint16_t TDS::Header::count<TDS::Type       >() const { return typeCount;        }
template<> uint16_t TDS::Header::count<TDS::Member     >() const { return memberCount;      }
template<> uint16_t TDS::Header::count<TDS::ScopeClass >() const { return scopeClassCount;  }
template<> uint16_t TDS::Header::count<TDS::ModuleClass>() const { return moduleClassCount; }


bool TDS::load(const char* const filename)
{
	File file(filename);

	if (!file.isOpened())
	{
		printf("Unable to open file %s\n", filename);
		return false;
	}

	return load(file);
}

bool TDS::load(File& file)
{
	if (!file.read(&header, sizeof header))
	{
		printf("Failed to read header, wrong TDS file %s\n", file.filename());
		return false;
	}

	// TODO: check header

	if (   !load(file, symbols      )
		|| !load(file, modules      )
		|| !load(file, sources      )
		|| !load(file, lines        )
		|| !load(file, scopes       )
		|| !load(file, segments     )
		|| !load(file, correlations )
		|| !load(file, types        )
		|| !load(file, members      )
		|| !load(file, scopeClasses )
		|| !load(file, moduleClasses))
	{
		return false;
	}

	if (!file.seek(header.dataCount, SEEK_CUR))
	{
		printf("Failed to seek to names table in file %s\n", file.filename());
		return false;
	}

	names.reserve(header.nameCount + 1);
	names.push_back(std::string());

	while (true)
	{
		std::string name;

		while (const int ch = file.readChar())
		{
			if ('\0' == ch || EOF == ch)
			{
				break;
			}

			name += ch;
		}

		if (name.empty() || file.isEOF())
		{
			break;
		}

		names.push_back(name);
	}

	return true;
}

template <typename Entry>
bool TDS::load(File& input, std::vector<Entry>& output)
{
	const size_t count = header.count<Entry>();

	output.reserve(count + 1);
	output.push_back(Entry());

	for (uint16_t i = 0; i < count; ++i)
	{
		Entry entry;

		if (!input.read(&entry, sizeof entry))
		{
			printf("Failed to read entry from file %s\n", input.filename());
			return false;
		}

		output.push_back(entry);
	}

	return true;
}


static TDS s_tds;


//---------------------------------------------------------------------------


struct Executable
{
#pragma pack(push, 1)

	struct OldHeader
	{
		uint16_t signature;
		uint16_t bytesInLastBlock;
		uint16_t blocksInFile;
		uint16_t numRelocs;
		uint16_t header_paragraphs;
		uint16_t minExtraParagraphs;
		uint16_t maxExtraParagraphs;
		uint16_t ss;
		uint16_t sp;
		uint16_t checksum;
		uint16_t ip;
		uint16_t cs;
		uint16_t relocTableOffset;
		uint16_t overlay_number;
	};

	struct NewHeader
	{
		uint16_t signature;
		uint8_t  linkerVersion;
		uint8_t  linkerRevision;
		uint16_t entryTableOffset;
		uint16_t entryTableLength;
		uint32_t crc;
		uint16_t flags;
		uint16_t autoDataSegment;
		uint16_t initHeapSize;
		uint16_t initStackSize;
		uint32_t entryPoint;
		uint32_t stackPoint;
		uint16_t segmentCount;
		uint16_t moduleReferenceCount;
		uint16_t nonResidentNameSize;
		uint16_t segmentOffset;         // relative to new EXE header
		uint16_t resourceOffset;        // relative to new EXE header
		uint16_t residentNameOffset;    // relative to new EXE header
		uint16_t moduleReferenceOffset; // relative to new EXE header
		uint16_t importNameOffset;      // relative to new EXE header
		uint32_t nonResidentNameOffset; // relative to beginning of file
		uint16_t movableEntryCount;
		uint16_t sectorAlignmentShift;
		uint16_t resourceCount;
		uint8_t  loaderType;            // target OS
		uint8_t  unused[9];
	};

	enum SegmentType
	{
		SEGMENT_CODE = 0,
		SEGMENT_DATA = 1
	};

	struct Segment
	{
		uint16_t sectorOffset;
		uint16_t length;
		uint16_t flags;
		uint16_t allocationSize;
	};

#pragma pack(pop)

	OldHeader oldHeader;
	NewHeader newHeader;

	std::vector<Segment> segments;

	bool load(const char* const filename);
};


bool Executable::load(const char* const filename)
{
	File file(filename);

	if (!file.isOpened())
	{
		printf("Unable to open file %s\n", filename);
		return false;
	}

	if (!file.read(&oldHeader, sizeof oldHeader))
	{
		printf("Failed to read old executable header from file %s\n", filename);
		return false;
	}

	if (0x5A4D != oldHeader.signature)
	{
		printf("Input file %s is not an executable file\n", filename);
		return false;
	}

	if (!file.seek(0x3C, SEEK_SET))
	{
		printf("Failed to seek to new header offset in file %s\n", file.filename());
		return false;
	}

	uint32_t newHeaderOffset;

	if (!file.read(&newHeaderOffset, sizeof newHeaderOffset))
	{
		printf("Failed to read new executable header offset from file %s\n", filename);
		return false;
	}

	if (!file.seek(static_cast<long>(newHeaderOffset), SEEK_SET))
	{
		printf("Failed to seek to new header offset in file %s\n", file.filename());
		return false;
	}

	if (!file.read(&newHeader, sizeof newHeader))
	{
		printf("Failed to read new executable header from file %s\n", filename);
		return false;
	}

	if (0x454E != newHeader.signature)
	{
		printf("Input file %s is not a new executable file\n", filename);
		return false;
	}

	for (uint16_t i = 0; i < newHeader.segmentCount; ++i)
	{
		Segment segment;

		if (!file.read(&segment, sizeof segment))
		{
			printf("Failed to read segment information from file %s\n", filename);
			return false;
		}

		segments.push_back(segment);
	}

	long tdsOffset = 0;

	for (auto segment = segments.rbegin(), first = segments.rend();
		segment != first; 
		++segment)
	{
		if (segment->sectorOffset > 0 && segment->length > 0)
		{
			tdsOffset = (segment->sectorOffset << newHeader.sectorAlignmentShift) + segment->length;
			break;
		}
	}

	// TODO: it's still not a TDS offset :(

	if (!file.seek(tdsOffset, SEEK_SET))
	{
		printf("Failed to seek to TDS in file %s\n", file.filename());
		return false;
	}

	return s_tds.load(file);
}


static Executable s_executable;


//---------------------------------------------------------------------------


const char* GetTypeName(const uint16_t name)
{
	static const char* TYPE_NAMES[] = 
	{
		"void",
		"BASIC literal string",
		"BASIC dynamic string",
		"PASCAL string",
		"signed char",
		"signed int",
		"signed long",
		"signed quad",
		"unsigned char",
		"unsigned int",
		"unsigned long",
		"unsigned quad",
		"PASCAL character",
		"float",
		"PASCAL 6-byte real",
		"double",
		"long double",
		"4-byte BCD",
		"8-byte BCD",
		"10-byte BCD",
		"cobol BCD",
		"near pointer ",
		"far pointer ",
		"segment pointer ",
		"near386",
		"far386",
		"c array",
		"very large array",
		"PASCAL array",
		"BASIC array descriptor",
		"struct",
		"union",
		"very large struct",
		"very large union",
		"enum",
		"function ",
		"label",
		"set",
		"PASCAL text file",
		"PASCAL binary file",
		"PASCAL boolean",
		"PASCAL enum",
		"raw pword",
		"raw tbyte",
		"prototype",
		"special function",
		"class",
		"-- Unknown type 2F --",
		"handle pointer",
		"-- Unknown type 31 --",
		"-- Unknown type 32 --",
		"member pointer",
		"near reference pointer ",
		"far reference pointer ",
		"Word Boolean",
		"Long Boolean",
		"new member ptr",
		"-- Unknown type 39 --",
		"-- Unknown type 3A --",
		"-- Unknown type 3B --",
		"-- Unknown type 3C --",
		"-- Unknown type 3D --",
		"Global Handle",
		"Local Handle",
		"static ",
		"absolute ",
		"auto ",
		"Pascal var ",
		"register ",
		"Pascal const ",
		"typedef ",
		"tag ",
		"-",
		"_ES",
		"_CS",
		"_SS",
		"_DS",
		"_FS",
		"_GS",
		"near C",
		"near PASCAL",
		"-- unused lang 2 --",
		"interrupt",
		"far C",
		"far PASCAL",
		"-- unused lang 6 --",
		"interrupt",
		"AX",
		"CX",
		"DX",
		"BX",
		"SP",
		"BP",
		"SI",
		"DI",
		"AL",
		"CL",
		"DL",
		"BL",
		"AH",
		"CH",
		"DH",
		"BH",
		"ES",
		"CS",
		"SS",
		"DS",
		"FS",
		"GS",
		"EAX",
		"ECX",
		"EDX",
		"EBX",
		"ESP",
		"EBP",
		"ESI",
		"EDI",
		"ST(0)",
		"ST(1)",
		"ST(2)",
		"ST(3)",
		"ST(4)",
		"ST(5)",
		"ST(6)",
		"ST(7)"
	};

	return name < sizeof(TYPE_NAMES) / sizeof(TYPE_NAMES[0])
		? TYPE_NAMES[name]
		: "";
}

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

	for (auto symbol = s_tds.symbols.begin(); s_tds.symbols.end() != symbol; ++symbol)
	{
		const char* const symbolName = s_tds.names[symbol->name].c_str();

		if ('\0' == symbolName[0])
		{
			continue;
		}

		if (symbol->segment > 0xC000 && symbol->offset < s_tds.names.size())
		{
			printf("\tMakeName(LocByName(\"%s_%u\"), \"%s\");\n",
				s_tds.names[symbol->offset].c_str(), symbol->segment & 0x3FFF, symbolName);
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

		printf("\tea = MK_FP(SegByName(\"%s\"), 0x%04hx);\n\tMakeName(ea, \"%s\");\n",
			SEGMENT_NAMES[symbol->segment], symbol->offset, symbolName);

		const std::string& typeNameStr = s_tds.names[s_tds.types[symbol->type].name];
		const char* const typeName = typeNameStr.empty()
			? GetTypeName(s_tds.types[symbol->type].id)
			: typeNameStr.c_str();

		if ('\0' == typeName[0])
		{
			continue;
		}

		// HARDCODE: select comment type depending on segment: code or data
		if (symbol->segment < 10)
		{
			printf("\tSetFunctionCmt(ea, \"%s\", 1);\n", typeName); // Code segment
		}
		else
		{
			printf("\tMakeRptCmt(ea, \"%s\");\n", typeName); // Data segment
		}

		// TODO: local symbols
	}

	puts("}");
}


//---------------------------------------------------------------------------


int main(int argc, char** argv)
{
	if (argc < 2)
	{
		puts("Usage: tds2idc new-executable-file");
		return EXIT_SUCCESS;
	}

	//const bool result = s_tds.load(argv[1]);
	const bool result = s_executable.load(argv[1]);

	MakeScript();

	return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
