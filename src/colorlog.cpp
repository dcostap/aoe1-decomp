// PDB source module: C:\\msdev\\work\\age1_x1\\Colorlog.cpp.
// This file owns the module's handwritten definition.

#include "../include/colorlog.h"
#include "../include/basegame.h"
#include "../include/drawarea.h"
#include "../include/rge_base_game_global.h"

void __cdecl color_log(unsigned char param_1, unsigned char param_2, int param_3) {
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
