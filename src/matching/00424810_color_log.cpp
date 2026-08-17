// VA: 00424810 color_log
// Source: Colorlog.cpp lines 13-68
// void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3)
// size: 442 bytes, frame: sub esp, 8Ch
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
// - exact recovery: period VC5 <windows.h> and <ddraw.h> declarations restored
//   the native RECT, POINT, DDBLTFX, IDirectDrawSurface, and ClientToScreen
//   codegen basin.  A local offset and the target-supported RECT update order
//   produce exact size, frame, boundary, calls, and bytes.  Validation is
//   442 bytes, 0x8C frame, five aligned calls, and 0 differing bytes.


#include <windows.h>
#include <ddraw.h>

struct TDrawArea {
    char gap_00[0x18];
    int Width;
    char gap_1C[0x20];
    IDirectDrawSurface* DrawSurface;
};

struct TDrawSystem {
    char gap_00[0x04];
    HWND Wnd;
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

extern RGE_Base_Game* rge_base_game;
extern unsigned char do_color_log;

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

    RECT back_dest;
    RECT scr_dest;
    POINT point;
    DDBLTFX ddbltfx;

    int offset = 2 - param_3;
    offset *= 20;
    back_dest.left = (sys->DrawArea->Width / 2) + offset;
    back_dest.right = back_dest.left + 10;
    back_dest.top = 0;
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

    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = param_1;

    sys->PrimarySurface->Blt(&scr_dest, 0, 0, 0x1000400, &ddbltfx);

    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = param_1;
    sys->DrawArea->DrawSurface->Blt(&back_dest, 0, 0, 0x1000400, &ddbltfx);

    back_dest.top = back_dest.top + 10;
    back_dest.bottom = back_dest.bottom + 10;
    scr_dest.top = scr_dest.top + 10;
    scr_dest.bottom = scr_dest.bottom + 10;

    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = param_2;

    sys->PrimarySurface->Blt(&scr_dest, 0, 0, 0x1000400, &ddbltfx);

    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = param_2;
    sys->DrawArea->DrawSurface->Blt(&back_dest, 0, 0, 0x1000400, &ddbltfx);
}
