// VA: 0048F530 TribeAchievementsScreen::wnd_proc (146 B)
// PDB source: scr_ach.cpp
// Attempt log:
// try 1: replaced free-function shim with natural member/class surface and dllimport IsIconic.
// Exact finish: PDB-qualified owner is TribeAchievementsScreen::wnd_proc in
// scr_ach.cpp, lines 922-936, with the body ending at 0048F5C1.
// Exact finish: fresh VC5 rebuild matched 146/146 bytes, all four ordered
// calls, both returns, and the owning symbol. Removing the dead local shim did
// not change codegen.

#include "../../include/scr_ach_context.h"

long TribeAchievementsScreen::wnd_proc(void* h1, unsigned int msg, unsigned int w, long l)
{
    if (msg == 0x10 && confirmed_close == 0) {
        confirmed_close = 1;
        int mode = rge_base_game->prog_mode;
        if (mode == 5 || mode == 4 || mode == 6 || mode == 7) {
            if (IsIconic(draw_surface->hwnd) == 0) {
                popupYesNoDialog(get_string(0xC1D), 0, 0x1C2, 100);
                return 1;
            }
        }
    }
    return TPanel::wnd_proc(h1, msg, w, l);
}
