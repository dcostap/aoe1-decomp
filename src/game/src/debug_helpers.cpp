#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TDrawSystem.h"
#include "../include/TDrawArea.h"
#include <timeapi.h>
#include <stdlib.h>
#include <string.h>

ulong debug_timeGetTime(const char* file, int line) {
    return timeGetTime();
}

void debug_srand(const char* file, int line, unsigned int seed) {
    srand(seed);
}

int debug_rand(const char* file, int line) {
    return rand();
}

void write_draw_log(char* msg) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041B620
    if (draw_log != nullptr) {
        fprintf(draw_log, "%s", msg);
        fflush(draw_log);
    }
}

void write_draw_log2(char* msg) {
    // Fully verified. Source of truth: basegame.cpp.decomp @ 0x0041B650
    if (draw_log != nullptr) {
        fprintf(draw_log, "%s", msg);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}

void color_log(int a, int b, int c) {
    // Fully verified. Source of truth: colorlog.cpp.asm @ 0x00424810
    const uchar param_1 = (uchar)(a & 0xFF);
    const uchar param_2 = (uchar)(b & 0xFF);
    const int param_3 = c;

    if (do_color_log == 0) {
        return;
    }
    if (rge_base_game == nullptr) {
        return;
    }
    if (rge_base_game->prog_mode < 2) {
        return;
    }

    TDrawSystem* const draw_system = rge_base_game->draw_system;
    if (draw_system == nullptr) {
        return;
    }
    if (draw_system->PrimarySurface == nullptr) {
        return;
    }

    // Original uses DrawArea->Width/2 (yes, Width) for the Y placement.
    const int top = (draw_system->DrawArea->Width / 2) + (2 - param_3) * 0x14;

    tagPOINT point;
    point.x = 10;
    point.y = top;

    tagRECT back_dest;
    back_dest.left = point.x;
    back_dest.top = point.y;
    back_dest.right = point.x + 10;
    back_dest.bottom = point.y + 10;

    tagRECT scr_dest = back_dest;
    if (draw_system->ScreenMode == 2) {
        tagPOINT screen_point = point;
        ClientToScreen((HWND)draw_system->Wnd, &screen_point);
        scr_dest.left = screen_point.x;
        scr_dest.top = screen_point.y;
        scr_dest.right = screen_point.x + 10;
        scr_dest.bottom = screen_point.y + 10;
    }

    _DDBLTFX ddbltfx;
    memset(&ddbltfx, 0, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);

    // First square: param_1
    ddbltfx.dwFillColor = (DWORD)param_1;
    draw_system->PrimarySurface->Blt(&scr_dest, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    draw_system->DrawArea->DrawSurface->Blt(&back_dest, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);

    // Second square: param_2 (X offset by +10 for both client/screen rects)
    scr_dest.left += 10;
    scr_dest.right += 10;
    back_dest.left += 10;
    back_dest.right += 10;

    ddbltfx.dwFillColor = (DWORD)param_2;
    draw_system->PrimarySurface->Blt(&scr_dest, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    draw_system->DrawArea->DrawSurface->Blt(&back_dest, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
}
