
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
		uint8_t  recordByte;
		uint16_t recordWord;

		Type() { memset(this, 0, sizeof *this); }

		uint8_t rawByte(const size_t index) const
		{
			assert(index < sizeof *this);
			return reinterpret_cast<const uint8_t*>(this)[index];
		}

		uint16_t rawWord(const size_t index) const
		{
			assert(index < sizeof *this / 2);
			return reinterpret_cast<const uint16_t*>(this)[index];
		}

		uint32_t rawDoubleWord(const size_t index) const
		{
			assert(index < sizeof *this / 4);
			return reinterpret_cast<const uint32_t*>(this)[index];
		}

		uint64_t rawQuadWord() const
		{
			return *reinterpret_cast<const uint64_t*>(this);
		}
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

	bool load(File& file);

	std::string typeName(const uint16_t index) const;

private:
	template <typename Entry>
	bool load(File& inputFile, std::vector<Entry>& outputList);

	void loadNames(File& input);

	std::string functionName(const Type& type) const;

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


bool TDS::load(File& file)
{
	if (!file.read(&header, sizeof header))
	{
		printf("Failed to read header, wrong TDS file %s\n", file.filename());
		return false;
	}

	// TODO: check header

	if (   !load(file, symbols)
		|| !load(file, modules)
		|| !load(file, sources)
		|| !load(file, lines)
		|| !load(file, scopes)
		|| !load(file, segments)
		|| !load(file, correlations)
		|| !load(file, types)
		|| !load(file, members)
		|| !load(file, scopeClasses)
		|| !load(file, moduleClasses))
	{
		return false;
	}

	if (!file.seek(header.dataCount, SEEK_CUR))
	{
		printf("Failed to seek to names table in file %s\n", file.filename());
		return false;
	}

	loadNames(file);

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

void TDS::loadNames(File& input)
{
	names.reserve(header.nameCount + 1);
	names.push_back(std::string());

	for (;;)
	{
		std::string name;

		while (const int ch = input.readChar())
		{
			if ('\0' == ch || EOF == ch)
			{
				break;
			}

			name += char(ch);
		}

		if (name.empty() || input.isEOF())
		{
			break;
		}

		names.push_back(name);
	}
}


static const char* GetTypeName(const uint16_t id)
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
		"Local Handle"
	};
	
	return id < sizeof TYPE_NAMES / sizeof TYPE_NAMES[0]
		? TYPE_NAMES[id]
		: "Bad Type ID";
}

static std::string GetRange(const TDS::Type& type, const TDS::Type& extended, const uint64_t range)
{
	if (extended.rawQuadWord() == range)
	{
		return std::string();
	}

	char buffer[256] = {};

	snprintf(buffer, sizeof buffer, "Range <%X,%X>  Parent %hX",
		extended.rawDoubleWord(0), extended.rawDoubleWord(1), type.rawWord(3));

	return buffer;
}

static const char* GetMemoryModel(const TDS::Type& type)
{
	static const char* MODEL_NAMES[] =
	{
		"near C ",
		"near PASCAL ",
		"-- unused lang 2 -- ",
		"interrupt ",
		"far C ",
		"far PASCAL ",
		"-- unused lang 6 -- ",
		"interrupt "
	};

	return MODEL_NAMES[type.recordByte & 7];
}

std::string TDS::typeName(const uint16_t index) const
{
	// TODO: check for recursive types

	if (types.size() <= index)
	{
		return std::string();
	}

	const Type& type = types[index];
	const uint16_t typeID = type.id;

	std::string result = GetTypeName(typeID);

	if (names.size() <= type.name)
	{
		return result;
	}

	const std::string& name = names[type.name];

	if (!name.empty())
	{
		result += " '" + name + "' ";
	}

	const Type& extended = (types.size() - 1 > index)
		? types[index + 1]
		: Type();
	char addChars[256] = {};

	switch (typeID)
	{
	case 3: // pascal string
		snprintf(addChars, sizeof addChars, "max %hhX ", type.recordByte);
		break;

	case 4: // int8_t
		result += GetRange(type, extended, 0x0000007FFFFFFF80ULL);
		break;

	case 5: // int16_t
		result += GetRange(type, extended, 0x00007FFFFFFF8000ULL);
		break;

	case 6: // int32_t
		result += GetRange(type, extended, 0x7FFFFFFF80000000ULL);
		break;

	case 8: // uint8_t
		result += GetRange(type, extended, 0x000000FF00000000ULL);
		break;

	case 9: // uint16_t
		result += GetRange(type, extended, 0x0000FFFF00000000ULL);
		break;

	case 10: // uint32_t
		result += GetRange(type, extended, 0xFFFFFFFF00000000ULL);
		break;

	case 22: // far pointers
	case 25:
	case 53:
		result += (0 == type.recordByte ? "" : "huge " ) + typeName(type.recordWord);
		break;

	case 35: // function
		result += functionName(type);
		break;

	// TODO: add other types

	default:
		break;
	}

	result += addChars;

	return result;
}

std::string TDS::functionName(const Type& type) const
{
	std::string result;

	if (type.recordByte & 0x40)
	{
		result += "nested ";
	}

	result += GetMemoryModel(type);

	if (type.recordByte & 0x80)
	{
		result += "varargs ";
	}

	result += "returns ";
	result += 0 == type.recordWord
		? "Unknown"
		: typeName(type.recordWord);

	return result;
}


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
		uint8_t  reserved[32];
		uint32_t newHeaderOffset;

		OldHeader() { memset(this, 0, sizeof *this); }
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

		NewHeader() { memset(this, 0, sizeof *this); }
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

		Segment() { memset(this, 0, sizeof *this); }
	};

#pragma pack(pop)

	OldHeader oldHeader;
	NewHeader newHeader;

	std::vector<Segment> segments;

	TDS tds;

	bool load(const char* const filename);

	std::string segmentName(const uint16_t index) const;

private:
	bool loadOldHeader(File& input);
	bool loadNewHeader(File& input);
	bool loadSegments (File& input);
	bool loadDebugInfo(File& input);

};


bool Executable::load(const char* const filename)
{
	File file(filename);

	if (!file.isOpened())
	{
		printf("Unable to open file %s\n", filename);
		return false;
	}

	return loadOldHeader(file)
		&& loadNewHeader(file)
		&& loadSegments (file)
		&& loadDebugInfo(file);
}


bool Executable::loadOldHeader(File& input)
{
	if (!input.read(&oldHeader, sizeof oldHeader))
	{
		printf("Failed to read old executable header from file %s\n", input.filename());
		return false;
	}

	if (0x5A4D != oldHeader.signature)
	{
		printf("Input file %s is not an executable file\n", input.filename());
		return false;
	}

	return true;
}

bool Executable::loadNewHeader(File& input)
{
	const long newHeaderOffset = static_cast<long>(oldHeader.newHeaderOffset);

	if (!input.seek(newHeaderOffset, SEEK_SET))
	{
		printf("Failed to seek to new header offset in file %s\n", input.filename());
		return false;
	}

	if (!input.read(&newHeader, sizeof newHeader))
	{
		printf("Failed to read new executable header from file %s\n", input.filename());
		return false;
	}

	if (0x454E != newHeader.signature)
	{
		printf("Input file %s is not a new executable file\n", input.filename());
		return false;
	}

	return true;
}

bool Executable::loadSegments(File& input)
{
	segments.push_back(Segment());

	for (uint16_t i = 0; i < newHeader.segmentCount; ++i)
	{
		Segment segment;

		if (!input.read(&segment, sizeof segment))
		{
			printf("Failed to read segment information from file %s\n", input.filename());
			return false;
		}

		segments.push_back(segment);
	}

	return true;
}

bool Executable::loadDebugInfo(File& input)
{
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

	if (!input.seek(tdsOffset, SEEK_SET))
	{
		printf("Failed to seek to TDS in file %s\n", input.filename());
		return false;
	}

	static const uint8_t DEBUG_INFO_HEADER[] =
	{
		 'N',  'B',  '0',  '2', 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	};

	uint8_t buffer[sizeof DEBUG_INFO_HEADER];

	if (!input.read(buffer, sizeof buffer))
	{
		printf("Failed to read debug information header from file %s\n", input.filename());
		return false;
	}

	if (0 != memcmp(DEBUG_INFO_HEADER, buffer, sizeof buffer))
	{
		printf("Unknown debug information header in file %s\n", input.filename());
		return false;
	}

	return tds.load(input);
}


std::string Executable::segmentName(const uint16_t index) const
{
	if (0 == index || segments.size() <= index)
	{
		return std::string();
	}

	const char* const prefix = (segments[index].flags & SEGMENT_DATA)
		? "dseg"
		: "cseg";

	char name[7];
	snprintf(name, sizeof name, "%s%02hu", prefix, index);

	return name;
}


//---------------------------------------------------------------------------


struct Script
{
	enum SymbolCategory
	{
		SYMBOL_INVALID = -1,

		SYMBOL_CODE = 0,
		SYMBOL_DATA,
		SYMBOL_STACK,
		SYMBOL_IMPORT
	};

	struct Symbol
	{
		std::string name;
		std::string type;

		SymbolCategory category;

		uint16_t segment;
		uint16_t offset;
		uint16_t size;

		std::string importedName;

		std::vector<Symbol> locals;

		Symbol()
		: category(SYMBOL_INVALID)
		, offset(UINT16_MAX)
		, size(0)
		{
		}
	};

	struct File
	{
		std::string name;

		uint16_t segment;
		uint16_t startOffset;
		uint16_t endOffset;

		File()
		: segment(0)
		, startOffset(0)
		, endOffset(0)
		{
		}
	};

	struct Line
	{
		uint16_t segment;
		uint16_t offset;

		uint16_t line;

		Line()
		: segment(0)
		, offset(0)
		, line(0)
		{
		}
	};

	std::vector<Symbol> symbols;
	std::vector<File> files;
	std::vector<Line> lines;

	explicit Script(const Executable& source);

	void generate(FILE* output) const;

private:
	const Executable& source;

	void makeSymbolList();
	void makeFileAndLineLists();

	Symbol makeSymbol(const size_t index);
	void makeGlobalSymbolsUnique();

	// Without implementation
	Script(const Script&);
	Script& operator=(const Script&);

};


Script::Script(const Executable& source)
: source(source)
{
	makeSymbolList();
	makeFileAndLineLists();
}


void Script::makeSymbolList()
{
	const std::vector<TDS::Symbol>& sourceSymbols = source.tds.symbols;

	for (size_t i = 1, ei = sourceSymbols.size(); i < ei; ++i)
	{
		const TDS::Symbol& srcSym = sourceSymbols[i];

		if (0 == srcSym.segment
			|| (source.segments.size() <= srcSym.segment
				&& (source.tds.names.size() <= srcSym.offset
					|| 0 == srcSym.offset)))
		{
			// Skip stack or value limit symbol
			continue;
		}

		Symbol dstSym = makeSymbol(i);

		for (auto scope = source.tds.scopes.begin(), es = source.tds.scopes.end();
			es != scope; ++scope)
		{
			if (i != scope->symbol || 0 == scope->count)
			{
				continue;
			}

			for (uint16_t j = 0; j < scope->count; ++j)
			{
				const uint16_t localIndex = scope->index + j;
				const TDS::Symbol& srcLocal = sourceSymbols[localIndex];

				if (0 == srcLocal.segment && 0 == srcLocal.offset)
				{
					continue;
				}

				const Symbol dstLocal = makeSymbol(localIndex);
				dstSym.locals.push_back(dstLocal);
			}
		}

		symbols.push_back(dstSym);
	}

	makeGlobalSymbolsUnique();
}

static void EraseSubString(std::string& str, const char* const sub)
{
	const size_t pos = str.find(sub);

	if (std::string::npos != pos)
	{
		str.erase(pos, strlen(sub));
	}
}

void Script::makeFileAndLineLists()
{
	// TODO: add range checks

	const TDS& tds = source.tds;
	const std::vector<TDS::Correlation>& correlations = tds.correlations;

	for (size_t i = 1, ei = correlations.size(); i < ei; ++i)
	{
		const TDS::Correlation& corr = correlations[i];

		const TDS::Segment& segment = tds.segments[corr.segmentIndex];
		const TDS::Source& srcFile = tds.sources[corr.fileIndex];

		uint16_t startOffset = UINT16_MAX;
		uint16_t endOffset = 0;

		for (uint16_t j = corr.lineIndex; j < corr.lineIndex + corr.lineCount; ++j)
		{
			const TDS::Line& srcLine = tds.lines[j];

			Line dstLine;
			dstLine.line     = srcLine.line;
			dstLine.segment  = segment.codeSegment;
			dstLine.offset   = srcLine.offset;

			lines.push_back(dstLine);

			if (UINT16_MAX == startOffset)
			{
				startOffset = srcLine.offset;
			}

			endOffset = srcLine.offset;
		}

		std::string filename = tds.names[srcFile.name];

		// Specific to PS10.EXE:
		// Remove unneeded parts of source file names
		EraseSubString(filename, "CHASM.SRC\\");
		EraseSubString(filename, "\\BP\\PROPAS\\");

		File dstFile;
		dstFile.name        = filename;
		dstFile.segment     = segment.codeSegment;
		dstFile.startOffset = startOffset;
		dstFile.endOffset   = endOffset + (UINT16_MAX == endOffset ? 0 : 1);

		files.push_back(dstFile);
	}
}


Script::Symbol Script::makeSymbol(const size_t index)
{
	// TODO: add range checks

	const TDS::Symbol& srcSym = source.tds.symbols[index];

	Symbol result;
	result.name = source.tds.names[srcSym.name];
	result.type = source.tds.typeName(srcSym.type);

	if (srcSym.segment & 0x4000)
	{
		char importedName[64] = {};
		snprintf(importedName, sizeof importedName, "%s_%u",
			source.tds.names[srcSym.offset].c_str(), srcSym.segment & 0x3FFF);

		result.importedName = importedName;
		result.category     = SYMBOL_IMPORT;
	}
	else
	{
		result.segment = srcSym.segment;
		result.offset  = srcSym.offset;

		if (0 == srcSym.segment)
		{
			result.category = SYMBOL_STACK;
		}
		else if (source.segments[srcSym.segment].flags & Executable::SEGMENT_DATA)
		{
			result.category = SYMBOL_DATA;
			result.size     = source.tds.types[srcSym.type].size;
		}
		else
		{
			result.category = SYMBOL_CODE;
		}
	}

	return result;
}

void Script::makeGlobalSymbolsUnique()
{
	std::set<std::string> uniqueSymbols;

	for (auto symbol = symbols.begin(); symbols.end() != symbol; ++symbol)
	{
		if (SYMBOL_IMPORT == symbol->category)
		{
			continue;
		}

		if ("VGA" == symbol->name)
		{
			// Specific to PS10.EXE:
			// Fix "failed to add constant VGA=9" error
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


static void GeneratePrologue(FILE* output)
{
	fputs(
		"from idaapi import *\n"
		"\n"
		"get_inf_structure().s_cmtflg = SW_RPTCMT | SW_ALLCMT | SW_LINNUM\n"
		"\n"
		"def make_ea(segment, offset):\n"
		"  return getnseg(segment - 1).startEA + offset\n"
		"\n"
		"def make_func(segment, offset, name, type):\n"
		"  ea = make_ea(segment, offset)\n"
		"  old_name = get_name(BADADDR, ea)\n"
		"  if None == old_name or '@' != old_name[0]:\n"
		"    set_name(ea, name, SN_CHECK)\n"
		"  if create_insn(ea):\n"
		"    autoWait()\n"
		"  if add_func(ea, BADADDR):\n"
		"    autoWait()\n"
		"  func = get_func(ea)\n"
		"  cmt = get_func_cmt(func, 1)\n"
		"  if None == cmt or 0 == len(cmt):\n"
		"    cmt = type\n"
		"  else:\n"
		"    cmt += '\\n' + type\n"
		"  set_func_cmt(func, cmt, 1)\n"
		"  return func\n"
		"\n"
		"def make_data(segment, offset, name, type, size):\n"
		"  ea = make_ea(segment, offset)\n"
		"  set_name(ea, name, SN_CHECK)\n"
		"  set_cmt(ea, type, 1)\n"
		"  do_unknown_range(ea, size, DOUNK_SIMPLE)\n"
		"  if 1 == size:\n"
		"    doByte(ea, 1)\n"
		"  elif 2 == size:\n"
		"    doWord(ea, 2)\n"
		"  elif 4 == size:\n"
		"    doDwrd(ea, 4)\n"
		"  else:\n"
		"    do_data_ex(ea, FF_BYTE, size, BADADDR)\n"
		"\n"
		"def make_import(imported_name, name, type):\n"
		"  ea = get_name_ea(BADADDR, imported_name)\n"
		"  set_name(ea, name, SN_CHECK)\n"
		"  set_cmt(ea, type, 1)\n"
		"\n"
		"def make_local(func, offset, name, type):\n"
		"  offset += func.frsize\n"
		"  frame = get_frame(func)\n"
		"  set_member_name(frame, offset, name)\n"
		"  member = None\n"
		"  try:\n"
		"    member = get_member(frame, offset)\n"
		"  except OverflowError:\n"
		"    pass\n"
		"  if member:\n"
		"    set_member_cmt(member, type, 1)\n"
		"\n"
		"def make_src_file(segment, start_offset, end_offset, filename):\n"
		"  start_addr = make_ea(segment, start_offset)\n"
		"  end_addr = make_ea(segment, end_offset)\n"
		"  add_sourcefile(start_addr, end_addr, filename)\n"
		"\n"
		"def make_src_line(segment, offset, line):\n"
		"  set_source_linnum(make_ea(segment, offset), line)\n"
		"\n", output);
}

static void GeneratePS10Specifics(FILE* output)
{
	// Fix a few "can't rename byte as '...' because"
	// "this byte can't have a name (it is a tail byte)" errors
	// Although it's better than undefine whole data segment
	fputs(
		"do_unknown(0x36CDC, DOUNK_SIMPLE)\n"
		"do_unknown(0x44A82, DOUNK_SIMPLE)\n"
		"do_unknown(0x44B5C, DOUNK_SIMPLE)\n"
		"do_unknown(0x44E34, DOUNK_SIMPLE)\n"
		"do_unknown(0x45B62, DOUNK_SIMPLE)\n"
		"\n", output);

	// Global variable initialization functions for Pascal units
	fputs(
		"make_func(2, 0x2070, '__CspRndrInit', '')\n"
		"make_func(3, 0x3756, '__CsDemoInit', '')\n"
		"make_func(4, 0x32cb, '__Cs3dm2Init', '')\n"
		"make_func(5, 0x84ea, '__CsActInit', '')\n"
		"make_func(6, 0x6ff8, '__CspUtlInit', '')\n"
		"make_func(7, 0x2cdd, '__CsMenuInit', '')\n"
		"make_func(8, 0x6b43, '__CspBioInit', '')\n"
		"make_func(9, 0x2685, '__SoundIPInit', '')\n"
		"\n", output);

	// Program entry function has BP-based frame
	fputs(
		"func = get_func(get_name_ea(BADADDR, 'PROGRAM'))\n"
		"func.flags &= ~FUNC_NORET\n"
		"func.flags |= FUNC_FRAME\n"
		"reanalyze_function(func)\n"
		"\n", output);
}

void Script::generate(FILE* output) const
{
	assert(NULL != output);

	GeneratePrologue(output);
	GeneratePS10Specifics(output);

	for (auto symbol = symbols.begin(), es = symbols.end(); es != symbol; ++symbol)
	{
		const char* const name = symbol->name.c_str();
		const char* const type = symbol->type.c_str();

		switch (symbol->category)
		{
		case SYMBOL_CODE:
			fprintf(output, "func = make_func(%hu, 0x%04hx, \"%s\", \"%s\")\n",
				symbol->segment, symbol->offset, name, type);

			for (auto local = symbol->locals.begin(), el = symbol->locals.end();
				 el != local; ++local)
			{
				if (SYMBOL_STACK != local->category)
				{
					continue;
				}

				fprintf(output, "make_local(func, %hi, \"%s\", \"%s\")\n",
					static_cast<int16_t>(local->offset), local->name.c_str(), local->type.c_str());
			}
			break;

		case SYMBOL_IMPORT:
			fprintf(output, "make_import(\"%s\", \"%s\", \"%s\")\n",
				symbol->importedName.c_str(), name, type);
			break;

		default:
			fprintf(output, "make_data(%hu, 0x%04hx, \"%s\", \"%s\", %hu)\n",
				symbol->segment, symbol->offset, name, type, symbol->size);
			break;
		}
	}

	fputs("\n", output);

	for (auto file = files.begin(), last = files.end(); last != file; ++file)
	{
		fprintf(output, "make_src_file(%hu, 0x%04hx, 0x%04hx, \"%s\")\n",
			file->segment, file->startOffset, file->endOffset, file->name.c_str());
	}

	fputs("\n", output);

	for (auto line = lines.begin(), last = lines.end(); last != line; ++line)
	{
		fprintf(output, "make_src_line(%hu, 0x%04hx, %hu)\n",
			line->segment, line->offset, line->line);
	}

	fputs("\nrefresh_idaview_anyway()\n", output);
}


//---------------------------------------------------------------------------


int main(int argc, char** argv)
{
	if (argc < 2)
	{
		puts("Usage: tds2idapy new-executable-file [output-file]");
		return EXIT_SUCCESS;
	}

	Executable executable;

	const bool result = executable.load(argv[1]);

	if (result)
	{
		FILE* output = stdout;

		if (argc >= 3)
		{
			const char* const filename = argv[2];
			
			output = fopen(filename, "w");

			if (NULL == output)
			{
				printf("Unable to open output file %s\n", filename);
				return EXIT_FAILURE;
			}
		}

		const Script script(executable);
		script.generate(output);

		if (output != stdout)
		{
			fclose(output);
		}
	}

	return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
