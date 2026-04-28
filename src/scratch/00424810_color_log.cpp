// VA: 00424810 color_log
// Source: Colorlog.cpp lines 13-68
// void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3)
// size: 442 bytes (correct), frame: sub esp, 8Ch (matched)
// First mismatch at byte 17

// Progress:
// - DDBLTFX tail[8] padding matched frame to 0x8C
// - guard chain + struct ops produce correct size
// - remaining gap: register alloc (xor ecx vs test reg), struct offset shifts

extern unsigned char do_color_log;
extern void* rge_base_game;

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
    void* gap_00[5];
    long (__stdcall *Blt)(IDirectDrawSurface* this_, tagRECT* dest, void* src, tagRECT* src_rect, unsigned long flags, void* fx);
};

struct IDirectDrawSurface {
    IDirectDrawSurfaceVtbl* lpVtbl;
};

struct _DDBLTFX {
    unsigned long dwSize;
    unsigned long dwDDFX;
    char gap_08[0x4C];
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
    char tail[8];
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

extern "C" int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);

void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3) {
    RGE_Base_Game* game;
    TDrawSystem* sys;
    IDirectDrawSurface* surface;

    if (do_color_log == 0) return;
    game = (RGE_Base_Game*)rge_base_game;
    if (game == 0) return;
    if (game->prog_mode < 2) return;
    sys = game->draw_system;
    if (sys == 0) return;
    surface = sys->PrimarySurface;
    if (surface == 0) return;

    {
        char frame_pad[8];
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

        sys->PrimarySurface->lpVtbl->Blt(sys->PrimarySurface, &scr_dest, 0, 0, 0x1000400, &ddbltfx);

        back_dest.top = 100;
        ddbltfx.dwDDFX = 100;
        ddbltfx.dwColorSpaceLowValue = param_1;
        sys->DrawArea->DrawSurface->lpVtbl->Blt(sys->DrawArea->DrawSurface, &back_dest, 0, 0, 0x1000400, &ddbltfx);

        scr_dest.top += 10;
        back_dest.left += 10;
        back_dest.top = 100;
        scr_dest.bottom += 10;

        ddbltfx.dwDDFX = 100;
        ddbltfx.dwColorSpaceLowValue = param_2;

        sys->PrimarySurface->lpVtbl->Blt(sys->PrimarySurface, &scr_dest, 0, 0, 0x1000400, &ddbltfx);

        ddbltfx.dwDDFX = 100;
        ddbltfx.dwColorSpaceLowValue = param_2;
        sys->DrawArea->DrawSurface->lpVtbl->Blt(sys->DrawArea->DrawSurface, &back_dest, 0, 0, 0x1000400, &ddbltfx);
    }
}
