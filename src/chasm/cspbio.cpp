
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

#include "cspbio.h"

#include "soundip/soundip.h"


namespace CSPBIO
{

namespace
{

class BigFile : private OC::BinaryFile
{
public:
    typedef std::stringbuf Buffer;

    const bool isInternal() { return m_isInternal; }
    void setInternal(const bool on) { m_isInternal = on; }

    // Opens big file and loads its entry table
    void initialize(const OC::Path& path);

    // Creates buffer and reads file into it
    Buffer* read(const OC::Path& path, std::streamsize& size, std::streamoff& offset);

    // Extracts all files into directory with given path
    // If no path provided output directory is named dump within user's directory
    void dumpContent(const OC::Path& path = OC::Path());

private:
    struct Entry
    {
        OC::String      filename;
        std::streamsize size;
        std::streamoff  offset;
    };

    typedef std::vector<Entry> EntryTable;
    EntryTable m_entryTable;  // FileTable

    bool m_isInternal;  // Internal
};


void BigFile::initialize(const OC::Path& path)
{
    if (!m_isInternal)
    {
        return;
    }

    open(path);

    if (!is_open())
    {
        DoHalt(OC::Format("Cannot open file %1%, permission denied or file system error.") % BaseFile);
    }

    Uint32 magic;
    *this >> magic;

    static const Sint32 CSM_ID = 0x64695343; // 'CSid'

    if (CSM_ID != magic)
    {
        DoHalt(OC::Format("Bad header in file %1%.") % BaseFile);
    }

    Uint16 fileCount;
    *this >> fileCount;

    for (Uint16 i = 0; i < fileCount; ++i)
    {
        const OC::String filename = readString(12);

        Sint32 size, offset;
        *this >> size >> offset;

        const Entry entry = { filename, size, offset };

        m_entryTable.push_back(entry);
    }
}

BigFile::Buffer* BigFile::read(const OC::Path& path, std::streamsize& size, std::streamoff& offset)
{
    SDL_assert(!path.empty());

    OC::String filename = path.filename().generic_string();
    boost::algorithm::to_upper(filename);

    LastFName = filename;

    OC_FOREACH(const Entry& entry, m_entryTable)
    {
        if (entry.filename == filename)
        {
            size   = entry.size;
            offset = entry.offset;

            seekg(offset, beg);

            // TODO: error handling

            std::stringbuf* buffer = new std::stringbuf();

            for (std::streamsize bytesLeft = size; bytesLeft > 0; /* EMPTY */)
            {
                char bytes[4096];

                const std::streamsize bytesToRead = std::min(bytesLeft, std::streamsize(sizeof bytes));
                const std::streamsize bytesRead = OC::BinaryInputStream::read(bytes, bytesToRead);

                buffer->sputn(bytes, bytesRead);

                bytesLeft -= bytesRead;
            }

            return buffer;
        }
    }

    return NULL;
}

void BigFile::dumpContent(const OC::Path& path)
{
    SDL_assert(m_isInternal);
    SDL_assert(!m_entryTable.empty());
    SDL_assert(is_open());

    const OC::Path dumpPath = path.empty()
        ? OC::FileSystem::GetUserPath("dump")
        : path;

    OC::FileSystem::CreateDirectories(dumpPath);

    OC_FOREACH(const Entry& entry, m_entryTable)
    {
        seekg(entry.offset);

        const OC::Path outPath = dumpPath / entry.filename;
        OC::BinaryFile outFile(outPath, std::ios::out);

        for (std::streamsize bytesLeft = entry.size; bytesLeft > 0; /* EMPTY */)
        {
            char buffer[4096];

            const std::streamsize bytesToRead = std::min(bytesLeft, std::streamsize(sizeof buffer));
            const std::streamsize bytesRead = OC::BinaryInputStream::read(buffer, bytesToRead);

            outFile.write(buffer, bytesRead);

            bytesLeft -= bytesRead;
        }
    }
}


BigFile s_bigFile;

} // unnamed namespace


// ===========================================================================


Resource::Resource()
: m_buffer(NULL)
, m_size(0)
, m_offset(0)
{
}

Resource::~Resource()
{
    delete m_buffer;
}

const bool Resource::is_open() const
{
    return NULL != m_buffer;
}

std::streambuf* Resource::open(const OC::Path& path, const FlagsType flags)
{
    SDL_assert(NULL == m_buffer);

    LastFName = path;

    if (UserMaps)
    {
        openExternal(AddonPath / path, flags);
    }
    else if (s_bigFile.isInternal())
    {
        m_buffer = s_bigFile.read(path, m_size, m_offset);

        if ((flags & PATH_MUST_EXIST) && NULL == m_buffer)
        {
            DoHalt(OC::Format("Cannot find file %1% within %2%") % path % BaseFile);
        }
    }
    else
    {
        openExternal(BaseFile / path, flags);
    }

    return m_buffer;
}

void Resource::openExternal(const OC::Path& path, const FlagsType flags)
{
    if (OC::FileSystem::IsPathExist(path))
    {
        boost::filesystem::filebuf* buffer = new boost::filesystem::filebuf();
        buffer->open(path, std::ios::in | std::ios::binary);

        if (buffer->is_open())
        {
            m_buffer = buffer;
        }
        else if (flags & PATH_MUST_EXIST)
        {
            DoHalt(OC::Format("Cannot open file %1%, permission denied or file system error.") % path);
        }
    }

    if (NULL != m_buffer)
    {
        m_size = m_buffer->pubseekoff(0, std::ios::end);
        m_buffer->pubseekoff(0, std::ios::beg);
    }
}


TextResource::TextResource(const OC::Path& path, const FlagsType flags)
{
    rdbuf(open(path, flags));
}


BinaryResource::BinaryResource(const OC::Path& path, const FlagsType flags)
{
    rdbuf(open(path, flags));
}


// ===========================================================================


void TPoint3di::load(OC::BinaryInputStream& stream)
{
    stream >> X;
    stream >> Y;
    stream >> Z;
}


void TPoint2D::load(OC::BinaryInputStream& stream)
{
    stream >> sX;
    stream >> sY;
}


TFace::TFace()
{
    SDL_zerop(this);
}

void TFace::load(OC::BinaryInputStream& stream)
{
    stream >> V1;
    stream >> V2;
    stream >> V3;
    stream >> V4;

    stream >> TAx;
    stream >> TAy;
    stream >> TBx;
    stream >> TBy;
    stream >> TCx;
    stream >> TCy;
    stream >> TDx;
    stream >> TDy;

    stream >> Next;
    stream >> Distant;

    stream >> TNum;
    stream >> Flags;

    stream >> SprOFs;
}


TOHeader::TOHeader()
: VCount(0)
, FCount(0)
, TH(0)
{

}

static void AdjustFaceCoord(Uint16& coord)
{
    coord = coord * 256 + 128;
}

void TOHeader::load(const OC::Path& filename)
{
    BinaryResource file(filename);

    load(file);

    TH *= 64;
    TPtr.resize(TH);

    file.readArray(TPtr);

    ChI(file);

    for (Uint16 i = 0; i < FCount; ++i)
    {
        TFace& face = Faces[i];

        const Uint8 b = face.Flags >> 4;
        face.TNum = 0 == b ? 0 : Uint8(1 << (b - 1));

        face.SprOFs *= 64;

        AdjustFaceCoord(face.TAx);
        AdjustFaceCoord(face.TAy);
        AdjustFaceCoord(face.TBx);
        AdjustFaceCoord(face.TBy);
        AdjustFaceCoord(face.TCx);
        AdjustFaceCoord(face.TCy);
        AdjustFaceCoord(face.TDx);
        AdjustFaceCoord(face.TDy);
    }
}

void TOHeader::load(OC::BinaryInputStream& stream)
{
    OC_FOREACH(TFace& face, Faces)
    {
        face.load(stream);
    }

    OC_FOREACH(TPoint3di& vertex, OVert)
    {
        vertex.load(stream);
    }

    OC_FOREACH(TPoint3di& vertex, RVert)
    {
        vertex.load(stream);
    }

    OC_FOREACH(TPoint3di& vertex, ShVert)
    {
        vertex.load(stream);
    }

    OC_FOREACH(TPoint2D& vertex, ScVert)
    {
        vertex.load(stream);
    }

    stream >> VCount;
    stream >> FCount;
    stream >> TH;
}


// ===========================================================================


TSepPartInfo::TSepPartInfo()
: ATimeA(0)
, ATimeB(0)
, FallSound(0)
{

}


// ===========================================================================


void InitModule()
{
    InitVideo();

    static const OC::String DATA_FILE_NAME      = "csm.bin";
    static const OC::String DATA_DIRECTORY_NAME = "chasmdat/";

    BaseFile = OC::FileSystem::GetBasePath(DATA_FILE_NAME);

    if (OC::FileSystem::IsPathExist(BaseFile))
    {
        s_bigFile.setInternal(true);
    }
    else
    {
        BaseFile = OC::FileSystem::GetUserPath(DATA_FILE_NAME);

        if (OC::FileSystem::IsPathExist(BaseFile))
        {
            s_bigFile.setInternal(true);
        }
        else
        {
            BaseFile = OC::FileSystem::GetBasePath(DATA_DIRECTORY_NAME);

            if (!OC::FileSystem::IsPathExist(BaseFile))
            {
                BaseFile = OC::FileSystem::GetUserPath(DATA_DIRECTORY_NAME);

                if (!OC::FileSystem::IsPathExist(BaseFile))
                {
                    // TODO: more detailed message
                    DoHalt("Cannot find game resource file or directory.");
                }
            }
        }
    }

    s_bigFile.initialize(BaseFile);

    SDL_Log("Loading from: %s", BaseFile.string().c_str());
}


// ===========================================================================


TPic::TPic()
: m_width(0)
, m_height(0)
{

}

TPic::TPic(const char* const filename)
: m_width(0)
, m_height(0)
{
    load(filename);
}

void TPic::load(const char* const filename)
{
    BinaryResource celFile(filename);

    celFile.seekg(2); // skip 0x9119 magic
    celFile >> m_width;
    celFile >> m_height;

    const size_t dataSize = m_width * m_height;
    m_data.resize(dataSize);

    celFile.seekg(CEL_DATA_OFFSET);
    celFile.readArray(m_data);

    CSPBIO::ChI(celFile);
}

void TPic::load(OC::BinaryInputStream& stream)
{
    SDL_assert(stream.good());

    stream >> m_width;
    stream >> m_height;
    stream >> m_centerX;

    const size_t dataSize = m_width * m_height;
    m_data.resize(dataSize);

    stream.readArray(m_data);

    CSPBIO::ChI(stream);
}


// ===========================================================================


TPlayerInfo::TPlayerInfo()
: PlHx(0)
, PlHy(0)
, Plhz0(0)
, PlLz(0)
, v(0)
, sv(0)
, rv(0)
, vz(0)
, ev(0)
, evfi(0)
, PlFi(0)
, ksFlags(0)
, FTime(0)
, Phase(0)
, WFlags(0)
, Frags(0)
, Armor(0)
, Life(0)
, PFlags(0)
, PlayerID(0)
, Active(false)
, PColor(0)
, PliCa(0)
, PliSa(0)
, Plhz(0)
, PlRz(0)
, ms_dvx(0)
, ms_dvy(0)
, PTime(0)
, PlColorN(0)
, PlCurGun(0)
, PlRepairTime(0)
, ReDelay(0)
, InvTime(0)
, GodTime(0)
, RefTime(0)
, LastTime(0)
{
    SDL_zero(Ammo);
}


// ===========================================================================


TObj3DInfo::TObj3DInfo()
: GoRad(0)
, ACode(0)
, ShadowOn(0)
, BMPObj(0)
, BMPz(0)
, BlowUp(0)
, BlowLimit(0)
, SFXid(0)
, BSFXid(0)
, LoZ(0)
, HiZ(0)
, Animated(false)
, Morphed(false)
, FTime(0)
, ATime(0)
{

}


TPicPack::TPicPack()
: NFrames()
{
    
}


TObjBMPInfo::TObjBMPInfo()
: Oz(0)
, bmpFlags(0)
, Frames(0)
, CurFrame(0)
{

}


TGunInfo::TGunInfo()
: RockType(0)
, RZ0(0)
, DAmmo(0)
, AmmoLimit(0)
, StartCount(0)
, RcCount(0)
, GunYShift(0)
, RepairTime(0)
, PATime(0)
, PSTime(0)
{
    
}


TBlowInfo::TBlowInfo()
: NFrames(0)
, Flags(0)
, GlassMode(0)
{
    
}


TRocketInfo::TRocketInfo()
: BlowType(0)
, GForce(0)
, ActionR(0)
, CheckR(0)
, Power(0)
, rFlags(0)
, SmokeID(0)
, ATime(0)
{
    
}


// ===========================================================================


Uint16 QPifagorA32(/*...*/);
void getmousestate(/*...*/);
Sint16 GetJoyX(/*...*/);
Sint16 GetJoyY(/*...*/);
void StosW(/*...*/);
void StosEW(/*...*/);
void movsw(/*...*/);
bool ExistFile(/*...*/);
void movsD(/*...*/);
void settimer(/*...*/);
void Beep(/*...*/);
bool FExistFile(/*...*/);
void FadeOut(/*...*/);
void FadeIn(/*...*/);

void DoHalt(const char* const message)
{
    // TODO...

    if (0 == strcmp(message, "NQUIT"))
    {
        // TODO: show credits

        exit(EXIT_SUCCESS);
    }

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", message, NULL);

    exit(EXIT_FAILURE);
}

void DoHalt(const OC::String& message)
{
    DoHalt(message.c_str());
}

void DoHalt(const OC::Format& message)
{
    DoHalt(message.str());
}

void DoHaltSDLError(const char* const message)
{
    DoHalt(OC::Format("%1%\nSDL returned error:\n%2%") % message % SDL_GetError());
}


void ChI(const std::ios& stream)
{
    SDL_assert(stream.good());

    if (!stream.good())
    {
        DoHalt(OC::Format("Error while reading %1%, permission denied or file system error.") % LastFName);
    }
}

void CalcDir(/*...*/);
Sint16 Max(/*...*/);
Sint16 Min(/*...*/);
Sint8 Sgn(/*...*/);
void SetCurPicTo(/*...*/);

void LoadAnimation(const OC::String& filename, const Uint16 modelVertexCount, Point3DList& vertices, Uint16& time)
{
    if (filename.empty())
    {
        return;
    }

    const OC::Path animationPath = OC::String::npos == filename.find("ani/")
        ? "ani/" + filename
        : filename;

    BinaryResource animationFile(animationPath);

    Uint16 animationVertexCount;
    animationFile >> animationVertexCount;

    if (modelVertexCount != animationVertexCount)
    {
        DoHalt(OC::Format("Error while loading animation file %1%. "
            "Animation and Model file contain different vertexes count.") % filename);
    }

    // Actual vertex count is file size without 2 header bytes divided by size of TPoint3di object
    // (it's hard-coded to avoid possible alignment issues)
    animationVertexCount = Uint16((animationFile.size() - 2) / 6);

    vertices.resize(animationVertexCount);

    OC_FOREACH(TPoint3di& vertex, vertices)
    {
        vertex.load(animationFile);
    }

    time = (animationVertexCount / modelVertexCount - 1) * 8;

    ChI(animationFile);
}

void LoadPOH(const OC::String& filename, TOHeader& model)
{
    if (filename.empty())
    {
        return;
    }

    const OC::Path modelPath = filename.size() > 12  // TODO: better check
        ? filename
        : "models/" + filename;
    model.load(modelPath);

    // Most of LoadPOH() code moved to TOHeader::load()
}

void ScanLoHi(Sint16& loZ, Sint16& hiZ, const TOHeader& model)
{
    loZ =  10000;
    hiZ = -10000;

    for (Uint16 n = 0; n < model.VCount; ++n)
    {
        const Sint16 z = model.OVert[n].Z;

        loZ = std::min(loZ, z);
        hiZ = std::max(hiZ, z);
    }

    loZ -= 96;

    if (loZ < 0)
    {
        loZ = 0;
    }
}

void ScanLowHigh(/*...*/);

void InitCaracter(const size_t monsterNumber)
{
    const size_t monsterIndex = monsterNumber - FIRST_MONSTER_INDEX;
    SDL_assert(monsterIndex < MonstersInfo.size());

    TMonsterInfo& monster = MonstersInfo[monsterIndex];
    BinaryResource characterFile("caracter/" + monster.CarName);

    boost::array<Uint16, 3> sounds;

    characterFile.seekg(64);                // skip AniMap
    characterFile.readArray(sounds);        // read GSND
    characterFile.seekg(32, std::ios::cur); // skip SFXSize and SFXVol

    for (size_t i = 0; i < sounds.size(); ++i)
    {
        SepPartInfo[monsterIndex + i].FallSound = sounds[i];
    }

    TOHeader header;
    header.load(characterFile);

    ChI(characterFile);

    ScanWH(monster.MWidth, monster.MHeight, header);

    Sint16 loZ, hiZ;
    ScanLoHi(loZ, hiZ, header);

    if (loZ > 320)
    {
        monster.MHeight -= loZ;
    }

    if (120 == monsterNumber)
    {
        monster.MWidth = 256;
    }
}

void UpLoadCaracter(/*...*/);
void ReleaseCaracter(/*...*/);

void LoadSound(const OC::String& /*filename*/, const size_t /*index*/)
{
    // TODO...
}

void LoadAmb(/*...*/);
void AllocVideo(/*...*/);
void AllocMemory(/*...*/);

namespace
{

void LoadRGBTable(const char* const filename, RGBTable& table)
{
    BinaryResource tableFile(filename);
    tableFile.readArray(table, 0xFF00);
}

} // unnamed namespace

void LoadCommonParts()
{
    for (size_t i = 0; i < SinTab.size(); ++i)
    {
        static const OC::Float op1 = OC::Float(M_PI); // OC::Real(0x2182, 0xDAA2, 0x490F).convert<OC::Float>();
        static const OC::Float op2 = 2.0f;            // OC::Real(0x0082, 0x0000, 0x0000).convert<OC::Float>();
        static const OC::Float op3 = 1024.0f;         // OC::Real(0x008B, 0x0000, 0x0000).convert<OC::Float>();
        static const OC::Float op4 = 4096.0f;         // OC::Real(0x008D, 0x0000, 0x0000).convert<OC::Float>();

        SinTab[i] = OC::Round<Sint16>(SDL_sin(op1 * op2 * i / op3) * op4);
    }

    SDL_Log("Loading environment...");

    ConsolePtr.load("common/console.cel");

    LoadRGBTable("common/chasm.rgb",   RGBTab25);
    LoadRGBTable("common/chasm60.rgb", RGBTab60);

    for (size_t i = 0; i < 256; ++i)
    {
        RGBTab60[0xFF00 + i] = RGBTab60[(i << 8) + 0xFF] = Uint8(i);
    }

    for (size_t i = 0; i < 255; ++i)  // TODO: ??? 256
    {
        RGBTab60[i] = RGBTab25[i] = Uint8(i);
    }

    Fonts.load("common/font256.cel");

    for (Uint16 j = 0; j < CharSize.size(); ++j)
    {
        Uint16 w = 0;

        const Uint16 x = j & 15;
        const Uint16 y = j / 16;

        for (Uint16 xx = 1; xx < 11; ++xx)
        {
            for (Uint16 yy = 0; yy < 7; ++yy)
            {
                const size_t pos = y * 2560 + yy * 256 + x * 16 + xx + 2 + 512;

                if (Fonts.data(pos) != 0xFF)
                {
                    w = xx;
                }
            }
        }

        CharSize[j] = ++w;
    }

    BigFont.load("common/bfont2.cel");
    LitFont.load("common/lfont2.cel");
    WIcons.load("common/wicons.cel");
    ColorMap.load("common/fadetab.cel");

    for (size_t n = 0; n < 52; ++n)
    {
        ColorMap.setData(n * 256 + 255, 0xFF);
    }

    LoadGround();

    BinaryResource paletteFile("common/chasm2.pal");
    paletteFile.readArray(Palette);

    BinaryResource asciiTableFile("common/chasm.key");
    asciiTableFile.readArray(ASCII_Tab);
}

void CheckMouse(/*...*/);

void RemoveEqual(OC::String& string)
{
    const size_t equalPos = string.find('=');
    if (OC::String::npos == equalPos)
    {
        return;
    }

    string.erase(0, equalPos + 1);

    const size_t semiPos = string.find(';');
    if (OC::String::npos != semiPos)
    {
        string.erase(semiPos);
    }

    boost::algorithm::trim(string);
    boost::algorithm::to_lower(string); // to_upper() originally
}


static const char* const EMPTY_LEVEL_NAME = ".";

void ScanLevels()
{
    for (size_t i = 0, count = LevelNames.size(); i < count; ++i)
    {
        OC::String& levelName = LevelNames[i];
        levelName = EMPTY_LEVEL_NAME;

        const OC::String filename = (OC::Format("level%1$02i/resource.%1$02i") % (i + 1)).str();
        TextResource levelFile(filename, Resource::PATH_MAY_NOT_EXIST);

        if (!levelFile.is_open())
        {
            continue;
        }

        for (;;)
        {
            levelName = levelFile.readLine();
            boost::algorithm::trim(levelName);

            ChI(levelFile);

            if (!levelName.empty())
            {
                break;
            }
        }

        static const char* const NAME_PREFIX = "#name=";
        static size_t NAME_PREFIX_LENGTH = SDL_strlen(NAME_PREFIX);

        if (levelName.find(NAME_PREFIX) != 0)
        {
            continue;
        }

        levelName = levelName.substr(NAME_PREFIX_LENGTH);
        boost::algorithm::trim(levelName);

        OC::String& shortName = ShortNames[i];
        shortName = levelName;

        if (CalcStringLen(shortName) > 132)
        {
            do
            {
                shortName.resize(shortName.size() - 1);
            }
            while (CalcStringLen(shortName) > 122);

            shortName += "...";
        }
    }
}

void FindNextLevel(/*...*/);

void LoadGraphics()
{
    SDL_Log("Reading graphics information:");

    TextResource info("chasm.inf");

    for (;;)
    {
        OC::String line = info.readLine();

        ChI(info);

        static const struct
        {
            const char* section;
            void (*function)(TextResource&);
        }
        loadingFunctions[] =
        {
            { "[MONSTERS]",    LoadMonsters   },
            { "[BMP_OBJECTS]", LoadBMPObjects },
            { "[3D_OBJECTS]",  Load3dObjects  },
            { "[ROCKETS]",     LoadRockets    },
            { "[GIBS]",        LoadGibs       },
            { "[BLOWS]",       LoadBlows      },
            { "[WEAPONS]",     LoadGunsInfo   },
            { "[SOUNDS]",      LoadSounds     }
        };

        for (size_t i = 0; i < SDL_TABLESIZE(loadingFunctions); ++i)
        {
            if (loadingFunctions[i].section == line)
            {
                loadingFunctions[i].function(info);
            }
        }

        if ("END." == line)
        {
            break;
        }
    }

    if (EMPTY_LEVEL_NAME == LevelNames[LevelN])
    {
        LevelN = 1;
    }
}

void LoadGround()
{
    VesaTiler.load("common/vesatile.cel");
    Status.load("common/status2.cel");
    Ground.load("common/ground.cel");

    Loading.load("common/loading.cel");
    LoadingW = Loading.width();
    LoadingH = Loading.height();
}

void DoSetPalette(const TPalette& palette)
{
    if (NULL == g_surface)
    {
        return;
    }

    // Convert 64-color palette to 256-color
    TPalette palette256;

    for (size_t n = 0; n < TPalette::size(); ++n)
    {
        const RGB& srcColor = palette[n];
        RGB& dstColor = palette256[n];

        dstColor.r = srcColor.r * 4;
        dstColor.g = srcColor.g * 4;
        dstColor.b = srcColor.b * 4;
    }

    SDL_SetPaletteColors(g_surface->format->palette, &palette256[0], 0, int(TPalette::size()));
}

namespace
{

inline Uint8 ApplyContast(const Uint8 color, const Sint16 coeff)
{
    OC::Float br = coeff / 63.0f; // OC::Real(0x0086, 0x0000, 0x7C00).convert<OC::Float>();
    br -= br * br;
    br *= 16.0f;                  // OC::Real(0x0085, 0x0000, 0x0000).convert<OC::Float>();

    return Uint8(color * (Contrast - 7) * OC::Round<Sint16>(br) / 128 + color);
}

inline Uint8 ApplyColor(const Uint8 color, const Sint16 coeff)
{
    const OC::Float br = (Color - 7) / 8.0f; // OC::Real(0x0084, 0x0000, 0x0000).convert<OC::Float>();
    const Sint16 l = OC::Round<Sint16>((color - coeff) * br) + color;

    return Uint8(OC::Clamp(Sint16(0), l, Sint16(63)));
}

inline Uint8 ApplyBrightness(const Uint8 color, const Sint16 coeff)
{
    const OC::Float br = 1.0f    // OC::Real(0x0081, 0x0000, 0x0000).convert<OC::Float>()
        - (Bright - 7) / 196.0f; // OC::Real(0x0088, 0x0000, 0x4400).convert<OC::Float>()

    Sint16 l = 64 - OC::Round<Sint16>((64 - color) * br);

    if (coeff < 3)
    {
        l = l * coeff / 3;
    }

    return Uint8(OC::Clamp(Sint16(0), l, Sint16(63)));
}

} // unnamed namespace


void SetPalette()
{
    for (size_t n = 0; n < TPalette::size(); ++n)
    {
        const RGB& color = Palette[n];

        const Uint8 coeff = std::max(std::max(color.r, color.g), color.b);
        Pal[n].r = ApplyContast(color.r, coeff);
        Pal[n].g = ApplyContast(color.g, coeff);
        Pal[n].b = ApplyContast(color.b, coeff);
    }

    for (size_t n = 0; n < TPalette::size(); ++n)
    {
        RGB& color = Pal[n];

        const Sint16 coeff = (Sint16(color.r) + Sint16(color.g) + Sint16(color.b)) / 3;
        color.r = ApplyColor(color.r, coeff);
        color.g = ApplyColor(color.g, coeff);
        color.b = ApplyColor(color.b, coeff);
    }

    for (size_t n = 0; n < TPalette::size(); ++n)
    {
        RGB& color = Pal[n];

        const Sint16 coeff = std::max(std::max(color.r, color.g), color.b);
        color.r = ApplyBrightness(color.r, coeff);
        color.g = ApplyBrightness(color.g, coeff);
        color.b = ApplyBrightness(color.b, coeff);
    }

    DoSetPalette(Pal);
}

void AddEvent(/*...*/);
void AddEvVoice(/*...*/);
void Hline(/*...*/);
void Vline(/*...*/);
void HBrline(/*...*/);
void VBrline(/*...*/);
void DrawKey(/*...*/);
void DrawBrKey(/*...*/);
void BrightBar(/*...*/);
void ShowMap(/*...*/);

Uint16 CalcStringLen(const OC::String& string)
{
    Uint16 result = 0;

    OC_FOREACH(const OC::String::value_type ch, string)
    {
        result += ' ' == ch ? 4 : CharSize[ch];
    }

    return result;
}

void ReInitViewConst(/*...*/);
void AddBlowLight(/*...*/);
void _AddBlowLight(/*...*/);
void AddBlow(/*...*/);
void BlowSpark(/*...*/);
void BlowSmoke(/*...*/);
void BlowShootSmoke(/*...*/);

void PutConsMessage(const OC::String& message)
{
    const OC::String lastLine = ConsoleComm.back();

    ConsoleComm.pop_back();
    ConsoleComm.pop_front();
    ConsoleComm.push_back(message);
    ConsoleComm.push_back(lastLine);

    SDL_Log(message.c_str());
}

void PutConsMessage2(const OC::String& message)
{
    PutConsMessage(message); // TODO ...
}

void PutConsMessage3(const OC::String& message)
{
    PutConsMessage(message); // TODO ...
}

Uint16 ServerVersion;
Sint32 Long1;
Uint8 LB;
bool UserMaps;
OC::String::value_type ConsoleCommands[546];
OC::String::value_type ncNames[24];
Sint16 ncSDivs[5];
Sint16 ncYDelta[3];
VideoPos__Element VideoPos[4];
Uint8 ReColorShift[8];
OC::String::value_type OnOff[10];
Sint16 Fr;
Sint16 Fr2;
Sint16 Frr;
void* ShadowMap;
void* WShadowMap;
void* ShadowMap2;
void* WShadowMap2;
Uint16 FlSegs[256];
TPic Pc;
TPic CurPic;
Uint16 CurPicSeg;
Uint16 ShadowSeg;
Uint16 WShadowSeg;
Uint16 ShadowSeg2;
Uint16 WShadowSeg2;
Uint16 cwc;
Uint16 CurShOfs;
Uint16 CMP0;
Uint16 XORMask;

OC::String::value_type* GFXindex;
boost::array<OC::String, 64> ShortNames;
boost::array<OC::String, 64> LevelNames;
TPic ColorMap; // cm_ofs
Uint8 FloorMap[4096];
Uint8 CellMap[4096];
Uint8* AltXTab;
TLight* Lights;
TTPort__Element* Tports;
void* PImPtr[120];
Uint16 PImSeg[120];
Uint8 WallMask[120];
boost::array<TObjBMPInfo, 4> ObjBMPInf;
boost::array<TObj3DInfo, 96> Obj3DInf;
Uint16 LinesH1[847];
Uint16 LinesH2[847];
TLinesBuf LinesBUF;
THoleItem* HolesList;
Uint8 SpryteUsed[120];
boost::array<Uint16, 201> Mul320;
boost::array<Sint32, 701> MulSW;
boost::array<Sint16, 1024> SinTab;
TLoc* Map;
std::list<OC::String> ConsHistory;
Uint8* VMask;
Uint8* Flags;
Uint8* DarkMap;
Uint8* AmbMap;
Uint8* TeleMap;
Uint8* FloorZHi;
Uint8* FloorZLo;
EndCamera__Type EndCamera;
TEvent EventsList[16];
TFrame* FramesList;
TBlow* BlowsList;
TMonster MonstersList[90];
TRocket RocketList[64];
TSepPart SepList[32];
TMine MinesList[16];
TBlowLight BlowLights[32];
boost::array<TMonsterInfo, 23> MonstersInfo;
boost::array<TRocketInfo, 32> RocketsInfo;
boost::array<TSepPartInfo, 90> SepPartInfo;
boost::array<TBlowInfo, 24> BlowsInfo;
std::vector<TReObject> ReObjects;
std::vector<TAmmoBag> AmmoBags;
bool FFlags[64];

TPic Fonts;
TPic BigFont;
TPic LitFont;
TPic WIcons;

TPalette Palette;
TPalette Pal;

OC::BinaryInputStream& operator>>(OC::BinaryInputStream& stream, RGB& value)
{
    stream >> value.r;
    stream >> value.g;
    stream >> value.b;

    value.a = 255;

    return stream;
}

boost::array<Uint16, 256> CharSize;
boost::array<TGunInfo, 9> GunsInfo;
NetPlace__Element NetPlace[32];
void* VGA;
TPic Ground;
TPic Status;
TPic Loading;
TPic VesaTiler;
void* SkyPtr;

RGBTable RGBTab25;
RGBTable RGBTab60;

Uint16 LoadPos;
Uint16 LoadingH;
Uint16 LoadingW;
OC::Path AddonPath;
OC::Real ca;
OC::Real sa;
Sint16 RShadeDir;
Sint16 RShadeLev;
Sint16 LastRShadeLev;
Sint16 BShadeDir;
Sint16 BShadeLev;
Sint16 LastBShadeLev;
Sint16 GShadeDir;
Sint16 GShadeLev;
Sint16 LastGShadeLev;
Uint16 MenuCode = 4;
Uint16 CSCopy;
Uint16 LoadSaveY = 0;
Uint16 OptionsY = 0;
Uint8 NetMode;
Uint8 TeamMode;
Uint8 SHRC;
TMonster Ms;
Sint16 Skill = 1;
Sint16 MyNetN = 0;
Sint16 bpx;
Sint16 bpy;
TPic ConsolePtr;
ConsoleText ConsoleComm(7);
Sint16 ConsY = 0;
Sint16 ConsDY = 0;
Sint16 ConsMode;
Sint16 ConsMainY = 0;
Sint16 ConsMenu;
Sint16 HistCnt = 4;
Sint16 CurHist = 5;
Sint16 MenuMode;
Sint16 MenuMainY;
Uint8 MSsens;
Sint16 DisplaySett[3];
Sint16 Contrast;
Sint16 Color;
Sint16 Bright;
Sint16 LandZ;
Sint16 CeilZ;
Sint16 EndDelay;
Uint16 Hz;
Uint16 Hz2;
Uint16 DMax;
Uint16 Dy;
Uint16 DDY;
Uint16 oldy;
Uint16 _x1;
Uint16 _x2;
Uint16 _X;
Uint16 sl;
Uint16 slp;
Uint16 t1;
Uint16 Times10Sum;
Uint16 _Times10Sum;
Uint16 Frames10Count;
Uint16 CurTime;
Uint16 LastGunNumber;
Uint16 GunShift;
Uint16 RespawnTime = 8400;
Uint16 ys31;
Uint16 ys32;
Uint16 ys11;
Uint16 ys12;
Uint16 ys21;
Uint16 ys22;
Uint16 sh1;
Uint16 sh2;
Uint16 mysy;
Uint16 ObjectsLoaded;
Uint16 WeaponsCount;
Uint16 MCount;
Uint16 TotalKills;
Uint16 TotalKeys;
Uint16 RCount;
Uint16 BCount;
Uint16 DCount;
Uint16 FCount;
Uint16 LCount;
Uint16 LtCount;
Uint16 SCount;
Uint16 TCount;
Uint16 MnCount;
Uint16 AmCount;
Uint16 ReCount;
Uint16 HolCount;
Uint16 SFXSCount;
Uint16 InfoLen;
Uint16 Di0;
Uint16 Dx0;
Uint16 Recsize;
Uint16 MTime;
Uint16 WeaponFTime;
Uint16 WeaponPhase;
Uint16 j;
Uint16 w;
Uint16 BLevelDef = 320;
Uint16 BLevel0;
Uint16 BLevelW;
Uint16 BlevelC;
Uint16 BLevelF;
Uint16 VgaSeg;
Uint16 RGBSeg;
Uint16 PSeg;
Uint16 POfs;
Uint16 PImBSeg;
Uint16 ImSeg;
Uint16 ImOfs;
Uint16 Ims;
Uint16 ImSegS;
Uint16 MyDeath;
Uint16 ObjectX;
Uint16 ObjectY;
Uint16 ObjSeg;
Uint16 HlBr;
Uint16 HLxx;
Uint16 HLh1;
Uint16 Hlh2;
Uint16 Hlhr1;
Uint16 Hlhr2;
Uint16 HLRH;
Uint16 HLFh;
Uint16 YMin1;
Uint16 YMin2;
Uint16 Nlines;
Uint16 NLines1;
Uint16 takt;
Uint16 MsTakt;
Uint16 b0;
Uint16 b1;
bool WeaponActive;
Sint32 CellV;
Sint32 FloorV;
Sint32 HLSt;
Sint16 WXSize;
Sint16 isa;
Sint16 ica;
Sint16 ica2;
Sint16 isa2;
Sint16 isa4;
Sint16 ica4;
Sint16 SxS;
Sint16 Sx11;
Sint16 Sx21;
Sint16 Sx1;
Sint16 Sx2;
Sint16 DShift;
Sint16 Dir;
Sint16 WpnShx;
Sint16 WpnShy;
Sint16 lvz;
Sint16 hvz;
Sint16 GunDx;
Sint16 GunDy;
Sint16 ShakeLevel;
Sint16 LookVz;
Sint16 _LookVz;
Sint16 v1x;
Sint16 v1y;
Sint16 v2x;
Sint16 v2y;
Sint16 nx;
Sint16 ny;
Sint16 HS;
Sint16 Hx;
Sint16 Hy;
Sint16 HMx;
Sint16 HMy;
Sint16 ehx;
Sint16 ehy;
Sint16 ehz;
Sint16 x;
Sint16 y;
Sint16 mi;
Sint16 MapR;
Sint16 LevelN = 1;
Sint16 ox;
Sint16 HRv;
Uint16 HksFlags;
Uint16 HFi;
Uint16 EHFi;
bool FirstTakt;
bool InfoPage = true;
bool NextL;
bool SERVER = false;
bool CLIENT = false;
bool Paused;
bool Monsters = true;
bool Animation = true;
bool TimeInd;
bool FullMap;
bool EndOfTheGame;
bool ClipMode = false;
bool IamDead;
bool Slow = false;
bool Spline = true;
bool Ranking;
bool NewSecond;
bool OAnimate;
bool MapMode;
bool ExMode;
bool Chojin = false;
bool TabMode;
bool SafeLoad;
bool EpisodeReset;
bool AlwaysRun;
bool ReverseMouse;
bool SkyVisible;
bool MenuOn;
bool Console = false;
bool Cocpit = true;
bool GameActive;
Uint8 SecCounter;
void (*TimerInt)() = NULL;
void (*KbdInt)() = NULL;
Sint32 EDI0;
Sint32 Edi1;
Sint32 mEDX;
Sint32 Ll;
Sint32 Time0;
Sint32 Time;
Sint32 ZTime;
Sint32 k;
Sint32 RealTime;
Sint32 LastMouseTime;
Sint32 LastPainTime;
Sint32 StartUpRandSeed = Sint32(time(NULL));
Sint32 MSRND;
TLoc L;
Uint16 VPSize;   // was Sint32
Uint16 VideoH;   // was Sint32
Uint16 VideoW;   // was Sint32
Uint16 VideoBPL; // was Sint32
Uint16 VideoEX;
Uint16 VideoEY;
Uint16 VideoCX;
Uint16 VideoCY;
bool VideoIsFlat;
Uint16 WinW;
Uint16 WinW2;
Uint16 WinSX;
Uint16 WinEX;
Uint16 WinSY;
Uint16 WinEY;
Uint16 WinH;
Uint16 WinH2u;
Uint16 WinH2d;
Uint16 WinCY;
Uint16 WallH;
Uint16 WallW;
Uint16 ObjectW;
Uint16 WinB;
Uint16 WinB3;
Uint16 WinE;
Uint16 WinE3;
Sint16 WMapX1;
Sint16 WMapX2;
Sint16 WMapY1;
Sint16 WMapY2;
Sint16 WMapX;
Sint16 WMapY;
Sint16 mpk_x;
Sint16 mpk_y;
Sint16 mps = 0x30;
Sint16 WinW2i;
Sint16 StepMove;
Sint16 FLeftEnd;
Sint16 FRightEnd;
Sint16 CLeftEnd;
Sint16 CRightEnd;
Sint16 FLE160;
Sint16 DNpy;
Sint16 DNpx;
Sint16 FMapDx;
Sint16 FMapDy;
Sint16 FShwDx;
Sint16 FShwDy;
Uint16 HXiFF;
Uint16 FloorW;
Uint16 FloorDiv;
Uint16 TMy;
Uint16 DNp;
Uint16 FCurMapOfs;
Uint16 FMx;
Uint16 FMy;
Sint32 Esl;
Sint32 Io0;
Sint32 SlY2;
Sint32 SLy;
Sint16 tx1;
Sint16 tx2;
Sint16 ty1;
Sint16 ty2;
Sint16 _ty1;
Sint16 DDark;
Uint16 WShadowOfs;
Uint16 CMPOfs;
Uint16 XOfsMask;
Uint16 Cnt;
Uint16 FromOfs;
Uint16 FullH;
Uint16 yf0;
Uint16 yf1;
Uint16 yf2;
Uint16 ScrollK;
Uint8 Double;
Sint16 RSize;
Sint16 rrx;
Sint16 rry;
Sint16 nhxi;
Sint16 nhyi;
Sint16 aLwx;
Sint16 aLWy;
Sint16 DSh;
Sint16 LWx;
Sint16 LWy;
Sint16 Rx;
Sint16 Ry;
Sint16 R;
bool KeysState[128];
Uint8 KBDBuf[16];
Uint16 KBDBufCnt;
Uint8 KeysID[16];
Uint8 _FrontOn;
Uint8 _BackOn;
Uint8 _LeftOn;
Uint8 _RightOn;
Uint8 _SLeftOn;
Uint8 _SRightOn;
Uint8 _JumpOn;
Uint8 _FireOn;
Uint8 _ChangOn;
Uint8 _StrafeOn;
Uint8 _SpeedUpOn;
Uint8 _MLookOn;
Uint8 _MLookT;
Uint8 _ViewUpOn;
Uint8 _ViewCntrOn;
Uint8 _ViewDnOn;
Uint8 Ms1ID;
Uint8 Ms2ID;
Uint8 ms3id;
bool kbViewUp;
bool kbViewDn;
bool kbViewCntr;
bool VCenterMode;
Uint8 c;
Uint8 kod;
Uint8 key;
boost::array<Uint8, 256> ASCII_Tab;
OC::Path LastFName;
OC::String::value_type S[256];
//Dos::Registers Regs;
Sint16 JoyX;
Sint16 JoyY;
Sint16 JoyCrX;
Sint16 JoyCrY;
Sint16 JoyMnX;
Sint16 JoyMnY;
Sint16 JoyMxX;
Sint16 JoyMxY;
bool JoyStick = false;
bool JoyKeyA;
bool JoyKeyB;
Sint16 MsX;
Sint16 MsY;
Sint16 MsButt;
Sint16 MsV;
Sint16 MLookTime;
Sint16 LastMouseX;
Sint16 LastMouseY;
Sint16 MsRv;
Sint16 MsVV;
Sint16 Msvvi;
Sint16 msrvi;
bool MouseD;
bool MsKeyA;
bool MsKeyB;
bool MsKeyC;
bool MLookOn;
bool RecordDemo = false;
bool PlayDemo = true;
bool IPXPresent;
Uint8 NGMode = 0;
Uint8 NGTeam;
Uint8 NGSkill = 1;
Uint8 NGLevel = 1;
Uint8 NGCard;
Uint8 NGPort;
Uint8 NGBaud;
Uint8 NGColor;
OC::String::value_type NGNick[9];
OC::String SelfNick = "UNKNOWN";
Uint8 SelfColor = 1;
TInfo_Struct* PInfoStruct;
bool MSCDEX;
Sint16 LCDTrack;
Sint16 CDTrack;
Sint32 CDTime;
boost::array<TPlayerInfo, 8> Players;
Uint8 LastBorn;
Uint8 LevelChanges[16];
Uint16 ProcState[4];
OC::String::value_type NetMessage[33];
MessageRec__Element MessageRec[4];
ProcMessage__Type ProcMessage;
Uint8 VESAError;
Uint16 VESABank;
Uint16 VESABankShift;
Uint8 VESA_CurrColor;
bool VESAPresent;
bool VESA20Compliant;
Uint16 VESAVersion;
Uint16 TotalMemory;
Uint16 FLATSelector;
Sint32 VESA20Addr;
ModesList__Type ModesList;
TDPMIRegs DRegs;
bool NETMonitor;
bool InBrifing;
Uint8 VideoOwners[4];
Uint16 CurOwner;
Uint16 CurVideoMode = 1;
Uint16 LastVideoMode;
ServerSaved__Type ServerSaved;
Sint16 CurWindow;

bool TextSeek(/*...*/);
void ShowFinalScreen(/*...*/);
void Wait_R(/*...*/);

void LoadPicsPacket(const OC::String& filename, TPicPack& packet)
{
    BinaryResource packetFile(filename);

    packetFile >> packet.NFrames;

    const size_t dataSize = size_t(packetFile.size()) - sizeof packet.NFrames;
    packet.PData.resize(dataSize);
    packetFile.readArray(packet.PData);

    ChI(packetFile);

    packet.FrameOfs.fill(Uint16(-1));

    Uint16 frame = 0;
    Uint16 offset = 0;

    while (frame < packet.NFrames)
    {
        packet.FrameOfs[frame] = offset;

        // ??? size * size + header
        offset += packet.PData[offset] * packet.PData[offset + 2] + 6;

        ++frame;
    }
}

void ScanWH(Sint16& width, Sint16& height, const TOHeader& model)
{
    Sint16 wx = 0;
    Sint16 wy = 0;

    for (Uint16 n = 0; n < model.VCount; ++n)
    {
        const TPoint3di& vertex = model.OVert[n];

        wx = std::max(OC::Abs(vertex.X), wx);
        wy = std::max(OC::Abs(vertex.Y), wy);

        height = std::max(vertex.Z, height);
    }

    width = (wx + wy) / 12 + 20;
    height += 32;
}

void AllocFloors(/*...*/);

namespace
{

template <typename CountType, typename StorageType>
void ValidateCount(CountType& count, const StorageType& objects)
{
    const typename StorageType::size_type storageSize = objects.size();
    SDL_assert(storageSize >= count);

    count = std::min(count, CountType(storageSize));
}

OC::String ReadFileNameAfterEqual(TextResource& info)
{
    OC::String result = info.readLine();

    RemoveEqual(result);
    boost::algorithm::replace_all(result, "\\", "/");
    
    return result;
}

}; // unnamed namespace

void LoadSounds(TextResource& info)
{
/*
    if (1 >= SoundIP::sCard)
    {
        return;
    }
*/

    SDL_Log("Load Sound Data...");

    for (size_t i = 0; /* EMPTY */; ++i)
    {
        const OC::String filename = ReadFileNameAfterEqual(info);

        if ("[SOUNDS_END]" == filename)
        {
            break;
        }

        LoadSound("sfx/" + filename, i);
    }
}

void LoadBMPObjects(TextResource& info)
{
    SDL_Log(" Loading Objects...");

    info >> ObjectsLoaded;
    info.skipLine();

    ValidateCount(ObjectsLoaded, ObjBMPInf);

    for (size_t i = 0; i < ObjectsLoaded; ++i)
    {
        TObjBMPInfo& bmp = ObjBMPInf[i];

        Uint16 sh, gl, hl, n;

        info >> sh >> gl >> hl;
        info >> bmp.Oz;
        info >> n >> n;

        // TODO: flags
        bmp.bmpFlags = (1 == sh ? 2 : 0)
            + (1 == gl ? 1 : 0)
            + (1 == hl ? 4 : 0);

        OC::String filename;
        info >> filename;

        info.skipLine();

        BinaryResource objectFile("obj/" + filename);

        objectFile >> bmp.Frames;
        objectFile >> bmp.CurFrame;

        ValidateCount(bmp.Frames, bmp.Pics);

        for (size_t j = 0; j < bmp.Frames; ++j)
        {
            bmp.Pics[j].load(objectFile);
        }
    }
}

void Load3dObjects(TextResource& info)
{
    SDL_Log(" Loading 3D Objects...");

    Uint16 count;
    info >> count;
    info.skipLine();

    ValidateCount(count, Obj3DInf);

    for (size_t i = 0; i < count; ++i)
    {
        while (';' == info.peek())
        {
            info.skipLine();
        }

        TObj3DInfo& object = Obj3DInf[i];

        info >> object.GoRad;
        info >> object.ShadowOn;

        info >> object.BMPObj;
        info >> object.BMPz;

        info >> object.ACode;

        info >> object.BlowUp;
        info >> object.BlowLimit;

        info >> object.SFXid;
        info >> object.BSFXid;

        OC::String modelFileName, animationFileName;

        {
            const OC::String filenames = info.readLine();
            OC::StringStream filenamesStream(filenames);
            filenamesStream >> modelFileName >> animationFileName;
        }

        ChI(info);

        object.Morphed = true;

        if (!animationFileName.empty() && '%' == animationFileName[0])
        {
            animationFileName.erase(0, 1);

            object.Morphed = false;
        }

        object.BMPz *= 32;

        if (object.BMPObj > 0)
        {
            --object.BMPObj;
        }

        LoadPOH(modelFileName, object.POH);
        LoadAnimation(animationFileName, object.POH.VCount, object.PAni, object.ATime);

        ScanLoHi(object.LoZ, object.HiZ, object.POH);
    }
}

void LoadRockets(TextResource& info)
{
    SDL_Log(" Loading Rockets...");

    Uint16 count;
    info >> count;
    info.skipLine();

    ValidateCount(count, RocketsInfo);

    for (size_t i = 0; i < count; ++i)
    {
        TRocketInfo& rocket = RocketsInfo[i];

        info.skipLine();

        const OC::String modelFileName     = ReadFileNameAfterEqual(info);
        const OC::String animationFileName = ReadFileNameAfterEqual(info);

        LoadPOH(modelFileName, rocket.POH);
        LoadAnimation(animationFileName, rocket.POH.VCount, rocket.PAni, rocket.ATime);

        info >> rocket.BlowType;
        info >> rocket.GForce;
        info >> rocket.ActionR;
        info >> rocket.CheckR;
        info >> rocket.Power;

        static const size_t FLAG_MASKS[] =
        {
            TRocketInfo::FLAG_REFLECTION,
            TRocketInfo::FLAG_FULL_BRIGHT,
            TRocketInfo::FLAG_LIGHT,
            TRocketInfo::FLAG_AUTO,
            TRocketInfo::FLAG_AUTO_2,
            TRocketInfo::FLAG_FAST
        };

        info.readFlags(rocket.rFlags, FLAG_MASKS, SDL_TABLESIZE(FLAG_MASKS));

        info >> rocket.SmokeID;
        info.skipLine();
    }
}

void LoadGibs(TextResource& info)
{
    SDL_Log(" Loading Gibs...");

    for (size_t i = 0; i < SepPartInfo.size(); ++i)
    {
        TSepPartInfo& sepPart = SepPartInfo[i];

        OC::String filename = ReadFileNameAfterEqual(info);

        if ("#end" == filename)
        {
            break;
        }

        sepPart.FallSound = 73;

        const size_t soundPos = filename.find("s:");

        if (OC::String::npos != soundPos
            && filename.size() > soundPos + 2)
        {
            const int soundNum = SDL_atoi(&filename[soundPos + 2]);
            sepPart.FallSound = Uint16(soundNum);

            filename.erase(soundPos);
            boost::algorithm::trim(filename);
        }

        LoadPOH(filename, sepPart.POH);
    }
}

void LoadBlows(TextResource& info)
{
    SDL_Log(" Loading Blows...");

    Uint16 count;
    info >> count;
    info.skipLine();

    ValidateCount(count, BlowsInfo);

    for (size_t i = 0; i < count; ++i)
    {
        TBlowInfo& blow = BlowsInfo[i];

        info >> blow.GlassMode;

        static const size_t FLAG_MASKS[] =
        {
            TBlowInfo::FLAG_HALF_SIZE,
            TBlowInfo::FLAG_SMOOKING,
            TBlowInfo::FLAG_LOOPED,
            TBlowInfo::FLAG_GRAVITY,
            TBlowInfo::FLAG_JUMP,
            TBlowInfo::FLAG_LIGHT_ON
        };

        info.readFlags(blow.Flags, FLAG_MASKS, SDL_TABLESIZE(FLAG_MASKS));

        OC::String filename;
        info >> filename;
        info.skipLine();

        LoadPicsPacket("bmp/" + filename, blow.Frames);

        blow.NFrames = blow.Frames.NFrames;
    }
}

void LoadMonsters(TextResource& info)
{
    SDL_Log(" Loading Monsters...");

    Uint16 count;
    info >> count;
    info.skipLine();

    ValidateCount(count, MonstersInfo);

    for (size_t i = 0; i < count; ++i)
    {
        TMonsterInfo& monster = MonstersInfo[i];

        info >> monster.CarName;

        info >> monster.Radius;
        info >> monster.CRad;

        info >> monster.Speed;
        info >> monster.RSpeed;

        info >> monster.Life;
        info >> monster.KickPower;
        info >> monster.Rocket;
        info >> monster.SepLimit;

        info.skipLine();

        InitCaracter(i + FIRST_MONSTER_INDEX);
    }

    MonstersInfo[2].MWidth -= 12;
}

void LoadGunsInfo(TextResource& info)
{
    SDL_Log(" Loading Weapons...");

    info >> WeaponsCount;
    info.skipLine();

    ValidateCount(WeaponsCount, GunsInfo);

    for (size_t i = 0; i < WeaponsCount; ++i)
    {
        TGunInfo& weapon = GunsInfo[i];

        const OC::String modelFilename = ReadFileNameAfterEqual(info);
        LoadPOH(modelFilename, weapon.POH);

        const OC::String staticFileName = ReadFileNameAfterEqual(info);
        LoadAnimation(staticFileName, weapon.POH.VCount, weapon.PAStat, weapon.PSTime);

        const OC::String attackFileName = ReadFileNameAfterEqual(info);
        LoadAnimation(attackFileName, weapon.POH.VCount, weapon.PAAttack, weapon.PATime);

        info >> weapon.RockType;
        info >> weapon.RepairTime;
        info >> weapon.GunYShift;
        info >> weapon.RZ0;
        info >> weapon.DAmmo;
        info >> weapon.AmmoLimit;
        info >> weapon.StartCount;
        info >> weapon.RcCount;

        info.skipLine();
    }
}

void CLine(/*...*/);
void Line(/*...*/);
void HBrline0(/*...*/);
void InitNormalViewHi(/*...*/);
void InitMonitorView(/*...*/);

OC::Path BaseFile;

} // namespace CSPBIO
