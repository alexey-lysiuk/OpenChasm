
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

#include "tds2ida.py.h"


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

    bool load(File& file);

private:
    bool loadOldHeader(File& input);
    bool loadNewHeader(File& input);
    bool loadSegments (File& input);
    bool loadDebugInfo(File& input);

};


bool Executable::load(File& file)
{
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
        segment != first; ++segment)
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

    return true;
}


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

    enum TypeOfType
    {
        TYPE_VOID,
        TYPE_BASIC_LITERAL_STRING,
        TYPE_BASIC_DYNAMIC_STRING,
        TYPE_PASCAL_STRING,
        TYPE_SIGNED_CHAR,
        TYPE_SIGNED_INT,
        TYPE_SIGNED_LONG,
        TYPE_SIGNED_QUAD,
        TYPE_UNSIGNED_CHAR,
        TYPE_UNSIGNED_INT,
        TYPE_UNSIGNED_LONG,
        TYPE_UNSIGNED_QUAD,
        TYPE_PASCAL_CHARACTER,
        TYPE_FLOAT,
        TYPE_PASCAL_6BYTE_REAL,
        TYPE_DOUBLE,
        TYPE_LONG_DOUBLE,
        TYPE_4BYTE_BCD,
        TYPE_8BYTE_BCD,
        TYPE_10BYTE_BCD,
        TYPE_COBOL_BCD,
        TYPE_NEAR_POINTER,
        TYPE_FAR_POINTER,
        TYPE_SEGMENT_POINTER,
        TYPE_NEAR386,
        TYPE_FAR386,
        TYPE_C_ARRAY,
        TYPE_VERY_LARGE_ARRAY,
        TYPE_PASCAL_ARRAY,
        TYPE_BASIC_ARRAY_DESCRIPTOR,
        TYPE_STRUCT,
        TYPE_UNION,
        TYPE_VERY_LARGE_STRUCT,
        TYPE_VERY_LARGE_UNION,
        TYPE_ENUM,
        TYPE_FUNCTION,
        TYPE_LABEL,
        TYPE_SET,
        TYPE_PASCAL_TEXT_FILE,
        TYPE_PASCAL_BINARY_FILE,
        TYPE_PASCAL_BOOLEAN,
        TYPE_PASCAL_ENUM,
        TYPE_RAW_PWORD,
        TYPE_RAW_TBYTE,
        TYPE_PROTOTYPE,
        TYPE_SPECIAL_FUNCTION,
        TYPE_CLASS,
        TYPE_UNKNOWN_TYPE_2F,
        TYPE_HANDLE_POINTER,
        TYPE_UNKNOWN_TYPE_31,
        TYPE_UNKNOWN_TYPE_32,
        TYPE_MEMBER_POINTER,
        TYPE_NEAR_REFERENCE_POINTER,
        TYPE_FAR_REFERENCE_POINTER,
        TYPE_WORD_BOOLEAN,
        TYPE_LONG_BOOLEAN,
        TYPE_NEW_MEMBER_PTR,
        TYPE_UNKNOWN_TYPE_39,
        TYPE_UNKNOWN_TYPE_3A,
        TYPE_UNKNOWN_TYPE_3B,
        TYPE_UNKNOWN_TYPE_3C,
        TYPE_UNKNOWN_TYPE_3D,
        TYPE_GLOBAL_HANDLE,
        TYPE_LOCAL_HANDLE,

        TYPES_COUNT
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

        bool isPascalString() const
        {
            return TYPE_PASCAL_STRING == id;
        }

        bool isPascalArray() const
        {
            return TYPE_PASCAL_ARRAY == id;
        }

        bool isStruct() const
        {
            return TYPE_STRUCT == id;
        }

        bool isPascalEnum() const
        {
            return TYPE_PASCAL_ENUM == id;
        }

        bool hasExtendedTypeInfo() const
        {
            return TYPE_VOID == id 
                || (id >= TYPE_SIGNED_CHAR && id <= TYPE_DOUBLE)
                || isPascalArray()
                || isPascalEnum();
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

    Executable               executable;

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

    // The same as generated by TDUMP
    std::string typeString(const size_t typeIndex) const;

    bool isGlobalSymbol(const size_t symbolIndex) const;

    class TypeIterator
    {
    public:
        explicit TypeIterator(const std::vector<Type>& types)
        : m_types(&types)
        , m_index(1)
        {
        }

        const Type* type() const
        {
            return m_index < m_types->size()
                ? &(*m_types)[m_index]
                : NULL;
        }

        size_t index() const
        {
            return m_index;
        }

        bool hasNext() const
        {
            return m_index < m_types->size();
        }

        void operator++()
        {
            if (m_index >= m_types->size())
            {
                return;
            }

            const Type* const type = this->type();
            assert(NULL != type);

            if (type->hasExtendedTypeInfo())
            {
                ++m_index;
            }

            ++m_index;
        }

    private:
        const std::vector<Type>* m_types;
        size_t m_index;
    };

    TypeIterator typeIterator() const
    {
        return TypeIterator(types);
    }

private:
    template <typename Entry>
    bool load(File& inputFile, std::vector<Entry>& outputList);

    void loadNames(File& input);

    void addModuleNames();
    void renameReservedWords();
    void makeGlobalSymbolsUnique();
    void assignMissingTypeNames();
    void applyPS10Specific();

    template <typename Item>
    std::string findNameForType(const std::vector<Item>& collection, const size_t typeIndex) const;

    std::string functionTypeString(const Type& type) const;

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

    if (!executable.load(file))
    {
        return false;
    }

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

    addModuleNames();
    renameReservedWords();
    makeGlobalSymbolsUnique();
    assignMissingTypeNames();
    applyPS10Specific();

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

void TDS::addModuleNames()
{
    // Turbo Debugger behavior is to iterate over modules only and to ignore scopes
    // However this leaves too many symbols (and all types) without module names

    for (size_t moduleIndex = 1, moduleCount = modules.size();
        moduleIndex < moduleCount; ++moduleIndex)
    {
        const Module& module = modules[moduleIndex];
        const Scope& scope = scopes[moduleIndex];

        const size_t symbolEndIndex = moduleIndex < moduleCount - 1
            ? scopes[moduleIndex + 1].index
            : symbols.size();

        for (size_t symbolIndex = scope.index; symbolIndex < symbolEndIndex; ++symbolIndex)
        {
            const Symbol& symbol = symbols[symbolIndex];
            const size_t typeFlags = symbol.flags & 7;

            if (typeFlags > 0 && 6 != typeFlags)
            {
                // Module names must be assigned to types and global symbols only
                continue;
            }

            names[symbol.name] = names[module.name] + "::" + names[symbol.name];
        }
    }
}

void TDS::renameReservedWords()
{
    static const char* RESERVED_NAMES[] = 
    {
        "VGA", // Fix "failed to add constant VGA=9" error
        "AX", "BX", "CX", "DX", "BP", "SI", "DI", "CS", "DS", "ES", "SS"
        "AH", "AL", "BH", "BL", "CH", "CL", "DH", "DL"
    };

    static const size_t RESERVED_NAME_COUNT = sizeof(RESERVED_NAMES) / sizeof(RESERVED_NAMES[0]);

    std::set<std::string> reservedNames;

    for (size_t i = 0; i < RESERVED_NAME_COUNT; ++i)
    {
        reservedNames.insert(RESERVED_NAMES[i]);
    }

    for (auto name = names.begin(), last = names.end(); name != last; ++name)
    {
        std::string upperName = *name;
        std::transform(upperName.begin(), upperName.end(), upperName.begin(), toupper);

        if (reservedNames.end() != reservedNames.find(upperName))
        {
            name->insert(0, "__");
        }
    }
}

void TDS::makeGlobalSymbolsUnique()
{
    std::set<std::string> uniqueSymbols;

    for (size_t i = 1, ei = symbols.size(); i < ei; ++i)
    {
        if (!isGlobalSymbol(i))
        {
            continue;
        }

        Symbol& symbol = symbols[i];
        const std::string& name = names[symbol.name];

        if (uniqueSymbols.end() != uniqueSymbols.find(name))
        {
            std::string newName;
            unsigned counter = 0;

            do
            {
                char buffer[256];
                snprintf(buffer, sizeof buffer, "%s__%u", name.c_str(), counter++);

                newName = buffer;
            }
            while (uniqueSymbols.end() != uniqueSymbols.find(newName));

            symbol.name = static_cast<uint16_t>(names.size());
            names.push_back(newName);

            uniqueSymbols.insert(newName);
        }

        uniqueSymbols.insert(name);
    }
}

void TDS::assignMissingTypeNames()
{
    for (TypeIterator i = typeIterator(); i.hasNext(); ++i)
    {
        const Type& type = *i.type();

        if (0 != type.name
            || !(type.isStruct() || type.isPascalEnum()))
        {
            continue;
        }

        const size_t index = i.index();
        std::string name = findNameForType(symbols, index);

        if (name.empty())
        {
            name = findNameForType(members, index);
        }

        if (!name.empty())
        {
            types[index].name = static_cast<uint16_t>(names.size());
            names.push_back(name);
        }
    }
}

template <typename Item>
std::string TDS::findNameForType(const std::vector<Item>& collection, const size_t typeIndex) const
{
    assert(!collection.empty());

    for (size_t i = 1, ei = collection.size(); i < ei; ++i)
    {
        const Item& item = collection[i];

        if (typeIndex == item.type)
        {
            return names[item.name] + "__Type";
        }

        const TDS::Type& symbolType = types[item.type];

        if (symbolType.isPascalArray() && typeIndex == symbolType.recordWord)
        {
            return names[item.name] + "__Element";
        }
    }

    return std::string();
}

void TDS::applyPS10Specific()
{
    auto name = std::find(names.begin(), names.end(), "A__Type");

    if (names.end() != name)
    {
        *name = "__PPoint"; // Guessed name, find name heuristic fails on it
    }

    for (TDS::TypeIterator i = typeIterator(); i.hasNext(); ++i)
    {
        const Type& type = *i.type();

        if (0 != type.name || !type.isStruct() || 4 != type.size)
        {
            continue;
        }

        types[i.index()].name = uint16_t(names.size());
        names.push_back("Free_vert__Element");
    }
}


static const char* GetTypeString(const uint16_t id)
{
    static const char* TYPE_NAMES[TDS::TYPES_COUNT] =
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

    return id < TDS::TYPES_COUNT 
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

std::string TDS::typeString(const size_t typeIndex) const
{
    // TODO: check for recursive types

    if (types.size() <= typeIndex)
    {
        return std::string();
    }

    const Type& type = types[typeIndex];
    std::string result = GetTypeString(type.id);

    if (names.size() <= type.name)
    {
        return result;
    }

    const std::string& name = names[type.name];

    if (!name.empty())
    {
        result += " '" + name + "' ";
    }

    const Type& extended = (types.size() - 1 > typeIndex)
        ? types[typeIndex + 1]
        : Type();
    char addChars[256] = {};

    switch (type.id)
    {
    case TYPE_PASCAL_STRING:
        snprintf(addChars, sizeof addChars, "max %hhX ", type.recordByte);
        break;

    case TYPE_SIGNED_CHAR:
        result += GetRange(type, extended, 0x0000007FFFFFFF80ULL);
        break;

    case TYPE_SIGNED_INT:
        result += GetRange(type, extended, 0x00007FFFFFFF8000ULL);
        break;

    case TYPE_SIGNED_LONG:
        result += GetRange(type, extended, 0x7FFFFFFF80000000ULL);
        break;

    case TYPE_UNSIGNED_CHAR:
        result += GetRange(type, extended, 0x000000FF00000000ULL);
        break;

    case TYPE_UNSIGNED_INT:
        result += GetRange(type, extended, 0x0000FFFF00000000ULL);
        break;

    case TYPE_UNSIGNED_LONG:
        result += GetRange(type, extended, 0xFFFFFFFF00000000ULL);
        break;

    case TYPE_FAR_POINTER:
    case TYPE_FAR386:
    case TYPE_FAR_REFERENCE_POINTER:
        result += (0 == type.recordByte ? "" : "huge " ) + typeString(type.recordWord);
        break;

    case TYPE_FUNCTION:
        result += functionTypeString(type);
        break;

    // TODO: add other types

    default:
        break;
    }

    result += addChars;

    return result;
}

std::string TDS::functionTypeString(const Type& type) const
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
        : typeString(type.recordWord);

    return result;
}


bool TDS::isGlobalSymbol(const size_t symbolIndex) const
{
    const TDS::Symbol& symbol = symbols[symbolIndex];

    // Return false for stack or value limit symbols

    return 0 != symbol.segment
        && (symbol.segment < executable.segments.size()
        || (symbol.offset < names.size() && 0 != symbol.offset));
}


//---------------------------------------------------------------------------


static void GeneratePS10Specifics(FILE* output)
{
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
}


static std::string GetTypeName(const TDS& tds, const size_t typeIndex)
{
    const TDS::Type& type = tds.types[typeIndex];

    switch (type.id)
    {
    case TDS::TYPE_VOID:
        return "void";

    case TDS::TYPE_PASCAL_STRING:
        return "oc::string::value_type";

    case TDS::TYPE_SIGNED_CHAR:
        return "Sint8";

    case TDS::TYPE_SIGNED_INT:
        return "Sint16";

    case TDS::TYPE_SIGNED_LONG:
        return "Sint32";

    case TDS::TYPE_SIGNED_QUAD:
        return "Sint64";

    case TDS::TYPE_UNSIGNED_CHAR:
        return "Uint8";

    case TDS::TYPE_UNSIGNED_INT:
        return "Uint16";

    case TDS::TYPE_UNSIGNED_LONG:
        return "Uint32";

    case TDS::TYPE_UNSIGNED_QUAD:
        return "Uint64";

    case TDS::TYPE_PASCAL_CHARACTER:
        return "char";

    case TDS::TYPE_FLOAT:
        return "float";

    case TDS::TYPE_PASCAL_6BYTE_REAL:
        return "oc::real";

    case TDS::TYPE_DOUBLE:
        return "double";

    case TDS::TYPE_LONG_DOUBLE:
        return "long double";

    // TODO...

    case TDS::TYPE_NEAR_POINTER:
    case TDS::TYPE_FAR_POINTER:
    {
        const TDS::Type& pointedType = tds.types[type.recordWord];

        if (TDS::TYPE_FUNCTION == pointedType.id)
        {
            const std::string typeName = GetTypeName(tds, pointedType.recordWord);
            return typeName.empty()
                ? "void (*)()"
                : typeName + " (*)()";
        }
        else
        {
            const std::string typeName = GetTypeName(tds, type.recordWord);
            return typeName.empty()
                ? "void*"
                : typeName + '*';
        }
    }

    case TDS::TYPE_PASCAL_ARRAY:
        return GetTypeName(tds, type.recordWord);

    case TDS::TYPE_PASCAL_BOOLEAN:
        return "bool";

    default: 
        return tds.names[type.name].c_str();
    }
}

static const char* GetTypeFlags(const TDS& tds, const size_t typeIndex)
{
    const TDS::Type& type = tds.types[typeIndex];

    switch (type.id)
    {
    case TDS::TYPE_PASCAL_STRING:
        return "FF_ASCI";

    case TDS::TYPE_SIGNED_CHAR:
    case TDS::TYPE_UNSIGNED_CHAR:
    case TDS::TYPE_PASCAL_CHARACTER:
    case TDS::TYPE_PASCAL_BOOLEAN:
        return "FF_BYTE";

    case TDS::TYPE_SIGNED_INT:
    case TDS::TYPE_UNSIGNED_INT:
        return "FF_WORD";

    case TDS::TYPE_SIGNED_LONG:
    case TDS::TYPE_UNSIGNED_LONG:
    case TDS::TYPE_FAR_POINTER:
        return "FF_DWRD";

    case TDS::TYPE_SIGNED_QUAD:
    case TDS::TYPE_UNSIGNED_QUAD:
        return "FF_QWRD";

    // TODO...

    case TDS::TYPE_PASCAL_ARRAY:
        return GetTypeFlags(tds, type.recordWord);

    case TDS::TYPE_STRUCT:
        return "FF_STRU";

    default:
        return "0";
    }
}

static uint16_t GetElementSize(const TDS& tds, const size_t typeIndex)
{
    const TDS::Type& type = tds.types[typeIndex];

    switch (type.id)
    {
    case TDS::TYPE_PASCAL_STRING:
        return 1;

    case TDS::TYPE_PASCAL_ARRAY:
        return GetElementSize(tds, type.recordWord);

    default:
        return type.size;
    }
}

static void GenerateTypes(const TDS& tds, FILE* const scriptOutput, FILE* const headerOutput)
{
    for (TDS::TypeIterator i = tds.typeIterator(); i.hasNext(); ++i)
    {
        const TDS::Type& type = *i.type();

        if (!type.isStruct() && !type.isPascalEnum())
        {
            continue;
        }

        const char* const typeName = tds.names[type.name].c_str();

        const bool isEnum = type.isPascalEnum(); // Otherwise, it's a struct

        if (isEnum)
        {
            fprintf(scriptOutput, "enum = add_enum(BADADDR, \"%s\", 0)\n", typeName);
            fprintf(headerOutput, "enum %s\n{\n", typeName);
        }
        else
        {
            fprintf(scriptOutput, "struc = make_struc(\"%s\")\n", typeName);
            fprintf(headerOutput, "struct %s\n{\n", typeName);
        }

        const std::vector<TDS::Member>& members = tds.members;
        const uint16_t startIndex = isEnum
            ? tds.types[i.index() + 1].rawWord(2)
            : type.recordWord;

        uint16_t offset = 0;

        for (size_t j = startIndex, ej = members.size(); j < ej; ++j)
        {
            const TDS::Member& member = members[j];

            static const uint8_t INFO_NEW_OFFSET  = 0x40;
            static const uint8_t INFO_END_OF_TYPE = 0x80;

            if (INFO_NEW_OFFSET == member.info)
            {
                // TODO: support for variant records as unions in C/C++
                break;
            }

            const char* const memberName = tds.names[member.name].c_str();
            const TDS::Type& memberType = tds.types[member.type];
            const uint16_t memberSize = isEnum ? 0 : memberType.size;

            if (isEnum)
            {
                fprintf(scriptOutput, "add_enum_member(enum, '%s', %hu)\n",
                    memberName, member.type);
                fprintf(headerOutput, "\t%s = %hu;\n", memberName, member.type);
            }
            else
            {
                const std::string memberTypeName = GetTypeName(tds, member.type);
                const uint16_t elementSize = GetElementSize(tds, member.type);

                fprintf(scriptOutput, "make_struc_member(struc, '%s', %hu, '%s', %hu, %hu, %s)\n",
                    memberName, offset, memberTypeName.c_str(), memberSize,
                    elementSize, GetTypeFlags(tds, member.type));

                if (memberType.isPascalArray() || memberType.isPascalString())
                {
                    fprintf(headerOutput, "\t%s %s[%i];\n", memberTypeName.c_str(), memberName,
                        memberSize / elementSize);
                }
                else
                {
                    fprintf(headerOutput, "\t%s %s;\n", memberTypeName.c_str(), memberName);
                }
            }

            if (INFO_END_OF_TYPE == member.info)
            {
                break;
            }

            offset += memberSize;
        }

        fputs("};\n\n", headerOutput);
    }

    fputs("\n", scriptOutput);
}


static void GenerateSymbols(const TDS& tds, FILE* const scriptOutput, FILE* const headerOutput)
{
    const std::vector<TDS::Symbol>& symbols = tds.symbols;

    for (size_t i = 1, ei = symbols.size(); i < ei; ++i)
    {
        const TDS::Symbol& symbol = symbols[i];

        if (!tds.isGlobalSymbol(i))
        {
            continue;
        }

        const std::string typeNameTD = tds.typeString(symbol.type);
        const char* const symbolName = tds.names[symbol.name].c_str();

        const TDS::Type& type = tds.types[symbol.type];

        if (symbol.segment & 0x4000)
        {
            char importedName[64] = {};
            snprintf(importedName, sizeof importedName, "%s_%u",
                tds.names[symbol.offset].c_str(), symbol.segment & 0x3FFF);

            fprintf(scriptOutput, "make_import(\"%s\", \"%s\", \"%s\")\n",
                importedName, symbolName, typeNameTD.c_str());
        }
        else if (tds.executable.segments[symbol.segment].flags & Executable::SEGMENT_DATA)
        {
            const std::string typeName = GetTypeName(tds, symbol.type);
            const uint16_t elementSize = GetElementSize(tds, symbol.type);

            fprintf(scriptOutput, "make_data(%hu, 0x%04hx, '%s', '%s', %hu, %hu, %s)\n",
                symbol.segment, symbol.offset, 
                symbolName, typeName.c_str(),
                type.size, elementSize,
                GetTypeFlags(tds, symbol.type));

            if (type.isPascalArray() || type.isPascalString())
            {
                fprintf(headerOutput, "extern %s %s[%i];\n", typeName.c_str(), symbolName,
                    type.size / elementSize);
            }
            else
            {
                fprintf(headerOutput, "extern %s %s;\n", typeName.c_str(), symbolName);
            }
        }
        else
        {
            fprintf(scriptOutput, "func = make_func(%hu, 0x%04hx, \"%s\", \"%s\")\n",
                symbol.segment, symbol.offset, symbolName, typeNameTD.c_str());

            const TDS::Type& returnType = tds.types[type.recordWord];
            const std::string returnTypeName = GetTypeName(tds, type.recordWord);

            const std::string headerPrefix = type.recordByte & 0x40
                ? "// /* nested */ "
                : "";

            if (returnType.isPascalArray() || returnType.isPascalString())
            {
                fprintf(headerOutput, "%s%s[%i] %s(/*...*/);\n", headerPrefix.c_str(),
                    returnTypeName.c_str(), returnType.size / GetElementSize(tds, type.recordWord), symbolName);
            }
            else
            {
                fprintf(headerOutput, "%s%s %s(/*...*/);\n", headerPrefix.c_str(), returnTypeName.c_str(), symbolName);
            }

            for (auto scope = tds.scopes.begin(), last = tds.scopes.end();
                last != scope; ++scope)
            {
                if (i != scope->symbol)
                {
                    continue;
                }

                for (uint16_t j = 0; j < scope->count; ++j)
                {
                    const uint16_t localIndex = scope->index + j;
                    const TDS::Symbol& local = symbols[localIndex];

                    if ((0 == local.segment && 0 == local.offset)
                        || tds.isGlobalSymbol(localIndex))
                    {
                        continue;
                    }

                    fprintf(scriptOutput, "make_local(func, %hi, '%s', '%s', %hu, %hu, %s)\n",
                        static_cast<int16_t>(local.offset),
                        tds.names[local.name].c_str(), GetTypeName(tds, local.type).c_str(),
                        tds.types[local.type].size, GetElementSize(tds, local.type),
                        GetTypeFlags(tds, local.type));
                }
            }
        }
    }

    fputs("\n", scriptOutput);
}


static void EraseSubString(std::string& str, const char* const sub)
{
    const size_t pos = str.find(sub);

    if (std::string::npos != pos)
    {
        str.erase(pos, strlen(sub));
    }
}

static void GenerateSources(const TDS& tds, FILE* const output)
{
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
            const TDS::Line& line = tds.lines[j];

            fprintf(output, "make_src_line(%hu, 0x%04hx, %hu)\n",
                segment.codeSegment, line.offset, line.line);

            if (UINT16_MAX == startOffset)
            {
                startOffset = line.offset;
            }

            endOffset = line.offset;
        }

        std::string filename = tds.names[srcFile.name];

        // Specific to PS10.EXE:
        // Remove unneeded parts of source file names
        EraseSubString(filename, "CHASM.SRC\\");
        EraseSubString(filename, "\\BP\\PROPAS\\");

        if (endOffset < UINT16_MAX)
        {
            ++endOffset;
        }

        fprintf(output, "make_src_file(%hu, 0x%04hx, 0x%04hx, \"%s\")\n",
            segment.codeSegment, startOffset, endOffset, filename.c_str());

        fputs("\n", output);
    }
}


static void GenerateScript(const TDS& tds, FILE* const scriptOutput, FILE* const headerOutput)
{
    assert(NULL != scriptOutput);
    assert(NULL != headerOutput);

    fwrite(tds2ida_py, tds2ida_py_len, 1, scriptOutput);

    GeneratePS10Specifics(scriptOutput);

    // TODO: add range checks for all generator functions

    GenerateTypes(tds, scriptOutput, headerOutput);
    GenerateSymbols(tds, scriptOutput, headerOutput);
    GenerateSources(tds, scriptOutput);

    fputs("refresh_idaview_anyway()\n", scriptOutput);
}


//---------------------------------------------------------------------------


int main(int argc, char** argv)
{
    if (argc < 4)
    {
        puts("Usage: tds2idapy new-executable-file output-script-file output-header-file");
        return EXIT_SUCCESS;
    }

    TDS tds;

    if (!tds.load(argv[1]))
    {
        puts("No output files generated");
        return EXIT_FAILURE;
    }

    const char* const scriptFilename = argv[2];
    FILE* const scriptOutput = fopen(scriptFilename, "w");

    if (NULL == scriptOutput)
    {
        printf("Unable to open output script file %s\n", scriptFilename);
        return EXIT_FAILURE;
    }

    const char* const headerFilename = argv[3];
    FILE* const headerOutput = fopen(headerFilename, "w");

    if (NULL == headerOutput)
    {
        printf("Unable to open output header file %s\n", headerFilename);
        return EXIT_FAILURE;
    }

    GenerateScript(tds, scriptOutput, headerOutput);

    fclose(headerOutput);
    fclose(scriptOutput);

    return EXIT_SUCCESS;
}
