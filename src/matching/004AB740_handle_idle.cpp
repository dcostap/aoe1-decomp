// 004AB740 TRIBE_Screen_Sed::handle_idle
// Working pass: model real member calls and layout; debug file as array symbol.

#include "../../include/scr_sed_context.h"

long TRIBE_Screen_Sed::handle_idle() {
    if (rge_base_game->prog_mode == 7) {
        unsigned long now = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp, 0x8B1);
        if (last_update_time - now >= update_interval) {
            if (panel_system.modalPanel() == 0) {
                main_view->set_redraw(1);
                if (last_map_redraw_time - now >= map_redraw_interval) {
                    map_view->set_redraw(1);
                    last_map_redraw_time = now;
                }
            }
        }
    }
    return TPanel::handle_idle();
}
