// compact button-disable loop first
// expected basin: iterate the 12 drop-down buttons, toggle each button's active state, and clear ids/help on unused ones

#if !defined(SCR_GAME_TU_CONTEXT)
 #include "../../include/scr_game_context.h"

#endif

void TRIBE_Screen_Game::disable_unused_buttons(void) {
    TRIBE_Panel_Button** p = this->button_panel;
    int count = 12;

    do {
        if ((*p)->in_use == 0) {
            ((TButtonPanel*)*p)->set_active(0);
            ((TButtonPanel*)*p)->set_id(0, 0, -1);
            ((TPanel*)*p)->set_help_info(-1, -1);
        } else {
            ((TButtonPanel*)*p)->set_active(1);
        }
        p++;
    } while (--count != 0);
}
