// VA: 00424810
// color_log(unsigned char param_1, unsigned char param_2, int param_3)
// Source: Colorlog.cpp lines 13-68

// Draws colored rectangles on primary/draw surfaces using DirectDraw Blt with
// destination color-key override. Draws two rows (param_1, then param_2) with
// positions based on param_3 offset.

// attempt 1: natural C translation of guard chain + RECT/DDBLTFX setup + 4 Blt calls
//            -> compiles to EXACT size (442 bytes!) but register allocation differs
//            stack frame 0x80 vs 0x8C (12 bytes smaller, likely DDBLTFX struct size)

extern unsigned char do_color_log;   // 62C584h
extern void* rge_base_game;          // 62C574h

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

struct IDirectDrawSurface;

struct IDirectDrawSurfaceVtbl {
    void* gap_00[5];  // skip to slot 5 (index 5 = offset 0x14)
    long (__stdcall *Blt)(IDirectDrawSurface* this_, tagRECT* dest, void* src, tagRECT* src_rect, unsigned long flags, void* fx);
};

struct IDirectDrawSurface {
    IDirectDrawSurfaceVtbl* lpVtbl;
};

struct _DDBLTFX {
    unsigned long dwSize;
    unsigned long dwDDFX;
    char gap_08[0x48];
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

struct TDrawArea {
    char gap_00[0x18];
    int Width;                          // +0x18
    char gap_1C[0x20];
    IDirectDrawSurface* DrawSurface;    // +0x3C
};

struct TDrawSystem {
    char gap_00[0x04];
    void* Wnd;                          // +0x04
    char gap_08[0x04];
    TDrawArea* DrawArea;                // +0x0C
    char gap_10[0x0C];
    IDirectDrawSurface* PrimarySurface; // +0x1C
    char gap_20[0x459];
    unsigned char ScreenMode;           // +0x479
};

struct RGE_Base_Game {
    char gap_00[0x48];
    TDrawSystem* draw_system;           // +0x48
    char gap_4C[0x164];
    int prog_mode;                      // +0x1B0
};

extern "C" int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);

void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3) {
    RGE_Base_Game* game;
    TDrawSystem* sys;
    IDirectDrawSurface* surface;
    int y_base;
    tagRECT back_dest;
    tagRECT scr_dest;
    tagPOINT point;
    _DDBLTFX ddbltfx;
    unsigned long flags;

    if (do_color_log == 0)
        return;

    game = (RGE_Base_Game*)rge_base_game;
    if (game == 0)
        return;

    if (game->prog_mode < 2)
        return;

    sys = game->draw_system;
    if (sys == 0)
        return;

    surface = sys->PrimarySurface;
    if (surface == 0)
        return;

    back_dest.right = 0;
    point.x = 10;
    y_base = (sys->DrawArea->Width / 2) + (2 - param_3) * 20;
    back_dest.top = y_base;
    back_dest.bottom = y_base + 10;
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
    flags = 0x1000400;

    // Blt #1: primary surface with scr_dest and param_1 color
    sys->PrimarySurface->lpVtbl->Blt(sys->PrimarySurface, &scr_dest, 0, 0, flags, &ddbltfx);

    // Blt #2: draw surface with back_dest and param_1 color
    back_dest.top = 100;
    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_1;
    sys->DrawArea->DrawSurface->lpVtbl->Blt(sys->DrawArea->DrawSurface, &back_dest, 0, 0, flags, &ddbltfx);

    // Row 2: increment all positions by 10 and use param_2
    scr_dest.top += 10;
    back_dest.left += 10;
    back_dest.top = 100;
    scr_dest.bottom += 10;

    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_2;

    // Blt #3: primary surface with offset positions and param_2 color
    sys->PrimarySurface->lpVtbl->Blt(sys->PrimarySurface, &scr_dest, 0, 0, flags, &ddbltfx);

    // Blt #4: draw surface with offset positions and param_2 color
    ddbltfx.dwDDFX = 100;
    ddbltfx.dwColorSpaceLowValue = param_2;
    sys->DrawArea->DrawSurface->lpVtbl->Blt(sys->DrawArea->DrawSurface, &back_dest, 0, 0, flags, &ddbltfx);
}
