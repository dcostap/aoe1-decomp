

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::set_focus(int v) {
    this->TScreenPanel::set_focus(v);
    if (this->have_focus) {
        rge_base_game->set_windows_mouse(0);
    } else {
        rge_base_game->set_windows_mouse(1);
    }
}
