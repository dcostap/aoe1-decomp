// VA: 0041FBC0 RGE_Base_Game::make_font (207 B)
// PDB source: basegame.cpp, lines 2936-2964
// Attempt log:
// baseline: natural LOGFONTA construction from the target assembly: language charset
// parsing, zeroed LOGFONT, MulDiv height, strikeout/quality fields, and strcpy face name.
// probe 2: added the explicit binary-observed zero/weight/byte field stores; this
// restored the original 207-byte frame/body shape under the default flags.
// probe 3: ordered weight and charset with the declared LOGFONTA fields; exact
// match, including the delayed parameter loads and inline strcpy schedule.

#include <string.h>

extern "C" int __cdecl atoi(const char*);
extern "C" __declspec(dllimport) int __stdcall MulDiv(int, int, int);
extern "C" __declspec(dllimport) void* __stdcall CreateFontIndirectA(void*);

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int vf04();
    virtual int vf08();
    virtual int vf0C();
    virtual int vf10();
    virtual int vf14();
    virtual int vf18();
    virtual int vf1C();
    virtual char* get_string(long id, char* buf, int maxlen);

    void* make_font(void* dc, char* name, int size, int weight, int strikeout);
};

struct LOGFONTA {
    int lfHeight;
    int lfWidth;
    int lfEscapement;
    int lfOrientation;
    int lfWeight;
    char lfItalic;
    char lfUnderline;
    char lfStrikeOut;
    char lfCharSet;
    char lfOutPrecision;
    char lfClipPrecision;
    char lfQuality;
    char lfPitchAndFamily;
    char lfFaceName[32];
};

void* RGE_Base_Game::make_font(void* dc, char* name, int size, int weight, int strikeout)
{
    char str[256];
    LOGFONTA logfont;
    char charset;

    this->get_string(0x65, str, 0x100);
    charset = (char)atoi(str);
    memset(&logfont, 0, sizeof(logfont));
    logfont.lfHeight = -MulDiv(size, 0x60, 0x48);
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfWeight = weight;
    logfont.lfItalic = 0;
    logfont.lfUnderline = 0;
    logfont.lfStrikeOut = (char)strikeout;
    logfont.lfCharSet = charset;
    logfont.lfOutPrecision = 0;
    logfont.lfClipPrecision = 0;
    logfont.lfQuality = 2;
    logfont.lfPitchAndFamily = 2;
    strcpy(logfont.lfFaceName, name);
    return CreateFontIndirectA(&logfont);
}
