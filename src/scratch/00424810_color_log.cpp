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
// - fresh structural probes for explicit == 0 guards, a volatile base pointer,
//   positive base scope, extern global declarations, a polymorphic base class,
//   and assignment-in-guard draw-system ownership were codegen duplicates.
//   Combining the draw-system and primary-surface guards worsened to 374 bytes;
//   all variants were restored.
// - recovery pass: the target stores an initial 10-pixel background RECT, a
//   POINT at the computed position, then a transformed primary RECT.  The
//   primary surface receives the initial-role RECT; the draw area receives the
//   background-role RECT.  A scalar POINT or renamed RECT variant did not
//   change VC5 output, so the period POINT form is retained.
// - current: C linkage, six-slot DirectDraw Blt, IAT ClientToScreen, and the
//   reviewed rge_base_game ownership are modeled.  Size, frame, calls, and
//   boundary align.  The remaining mismatch starts at the shared zero/test
//   guard basin and continues through local register coloring.  Final check:
//   442 bytes, 0x8C frame, five calls, 178 differing bytes, 72.39% shape.
// - Main-agent review rejected that final metric basin. Its POINT coordinates
//   and RECT roles changed the observed drawing behavior. The source below
//   restores the natural target-backed local and screen rectangles.
//   Final validation emits 452 bytes with five aligned calls and 418 differing
//   bytes. The frame remains 0x8C.


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

extern "C" void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3) {
    if (!do_color_log)
        return;
    RGE_Base_Game* game = rge_base_game;
    if (!game)
        return;
    if (game->prog_mode < 2)
        return;

    TDrawSystem* sys = game->draw_system;
    if (!sys)
        return;
    if (!sys->PrimarySurface)
        return;

    tagRECT back_dest;
    tagRECT scr_dest;
    tagPOINT point;
    _DDBLTFX ddbltfx;

    back_dest.left = (sys->DrawArea->Width / 2) + (2 - param_3) * 20;
    back_dest.top = 0;
    back_dest.right = back_dest.left + 10;
    back_dest.bottom = 10;

    point.x = back_dest.left;
    point.y = 0;

    if (sys->ScreenMode == 2) {
        ClientToScreen(sys->Wnd, &point);
    }

    scr_dest.left = point.x;
    scr_dest.top = point.y;
    scr_dest.right = point.x + 10;
    scr_dest.bottom = point.y + 10;

    ddbltfx.dwSize = 0;
    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_1;

    sys->PrimarySurface->Blt(&scr_dest, 0, 0, 0x1000400, &ddbltfx);

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_1;
    sys->DrawArea->DrawSurface->Blt(&back_dest, 0, 0, 0x1000400, &ddbltfx);

    scr_dest.top += 10;
    back_dest.top += 10;
    scr_dest.bottom += 10;
    back_dest.bottom += 10;

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_2;

    sys->PrimarySurface->Blt(&scr_dest, 0, 0, 0x1000400, &ddbltfx);

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_2;
    sys->DrawArea->DrawSurface->Blt(&back_dest, 0, 0, 0x1000400, &ddbltfx);
}
