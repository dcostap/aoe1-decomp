// VA: 00424810 color_log
// Source: Colorlog.cpp lines 13-68
// void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3)
// size: 442 bytes (correct), frame: sub esp, 8Ch (matched)
//
// Attempts:
// - baseline: typed RECT/POINT/DDBLTFX, DrawSystem/DrawArea, and four Blts;
//   frame/size matched but the imported call and absolute globals were unresolved.
// - behavior: bound do_color_log (0x62C584), rge_base_game (0x62C574), and
//   ClientToScreen to their proven IAT/global surfaces; all five calls aligned.
// - control-flow/liveness: positive guards, scoped DrawSystem, and guard-form
//   variants left the xor-zero/test and local-slot basin unchanged.
// - layout: full 0x64 DDBLTFX plus real six-slot DirectDraw virtual Blt improved
//   the diagnostic diff; removing artificial frame padding was codegen-neutral.
// - expression/local probes were either duplicates or grew the function to 450
//   bytes; restored the best 442-byte typed source.
// - serial natural null guards improved the structural diff to 349 bytes and
//   54.35% shape similarity; truthiness spelling and a guard-only surface local
//   were duplicates, so the serial guard form remains the best source shape.
// - left in scratch: calls/size/frame match, but guard/register coloring and
//   RECT/DDBLTFX stack-slot scheduling remain nonexact.


struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPOINT {
    long x;
    long y;
};

struct _DDBLTFX {
    unsigned long dwSize;
    unsigned long dwDDFX;
    unsigned long dwROP;
    unsigned long dwDDROP;
    unsigned long dwRotationAngle;
    unsigned long dwZBufferOpCode;
    unsigned long dwZBufferLow;
    unsigned long dwZBufferHigh;
    unsigned long dwZBufferBaseDest;
    unsigned long dwZDestConstBitDepth;
    unsigned long dwZDestConst;
    unsigned long dwZSrcConstBitDepth;
    unsigned long dwZSrcConst;
    unsigned long dwAlphaEdgeBlendBitDepth;
    unsigned long dwAlphaEdgeBlend;
    unsigned long dwReserved;
    unsigned long dwAlphaDestConstBitDepth;
    unsigned long dwAlphaDestConst;
    unsigned long dwAlphaSrcConstBitDepth;
    unsigned long dwAlphaSrcConst;
    unsigned long dwFillColor;
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
    unsigned long dwSrcColorSpaceLowValue;
    unsigned long dwSrcColorSpaceHighValue;
};

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(tagRECT* dest, IDirectDrawSurface* src,
                               tagRECT* src_rect, unsigned long flags,
                               _DDBLTFX* fx);
};

struct TDrawArea {
    char gap_00[0x18];
    int Width;
    char gap_1C[0x20];
    IDirectDrawSurface* DrawSurface;
};

struct TDrawSystem {
    char gap_00[0x04];
    void* Wnd;
    char gap_08[0x04];
    TDrawArea* DrawArea;
    char gap_10[0x0C];
    IDirectDrawSurface* PrimarySurface;
    char gap_20[0x459];
    unsigned char ScreenMode;
};

struct RGE_Base_Game {
    char gap_00[0x48];
    TDrawSystem* draw_system;
    char gap_4C[0x164];
    int prog_mode;
};

// USER32 import is referenced through the IAT in the original.
extern "C" int (__stdcall * const ClientToScreen)(void* hWnd, tagPOINT* point);

#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define do_color_log (*(unsigned char*)0x62C584)

void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3) {
    if (!do_color_log)
        return;
    if (!rge_base_game)
        return;
    if (rge_base_game->prog_mode < 2)
        return;

    TDrawSystem* sys = rge_base_game->draw_system;
    if (!sys)
        return;
    if (!sys->PrimarySurface)
        return;

    tagRECT scr_dest;
    tagRECT back_dest;
    tagPOINT point;
    _DDBLTFX ddbltfx;

    back_dest.right = 0;
    point.x = 10;
    back_dest.top = (sys->DrawArea->Width / 2) + (2 - param_3) * 20;
    back_dest.bottom = back_dest.top + 10;
    ddbltfx.dwSize = 0;
    point.y = back_dest.top;

    if (sys->ScreenMode == 2) {
        ClientToScreen(sys->Wnd, &point);
    }

    scr_dest.top = point.y;
    scr_dest.right = ddbltfx.dwSize;
    scr_dest.bottom = point.y + 10;
    back_dest.left = ddbltfx.dwSize + 10;

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_1;

    sys->PrimarySurface->Blt(&scr_dest, 0, 0, 0x1000400, &ddbltfx);

    back_dest.top = 100;
    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_1;
    sys->DrawArea->DrawSurface->Blt(&back_dest, 0, 0, 0x1000400, &ddbltfx);

    scr_dest.top += 10;
    back_dest.left += 10;
    back_dest.top = 100;
    scr_dest.bottom += 10;

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_2;

    sys->PrimarySurface->Blt(&scr_dest, 0, 0, 0x1000400, &ddbltfx);

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_2;
    sys->DrawArea->DrawSurface->Blt(&back_dest, 0, 0, 0x1000400, &ddbltfx);
}
