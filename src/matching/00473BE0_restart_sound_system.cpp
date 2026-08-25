class TDigital;

#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif

extern RGE_Base_Game* rge_base_game;

int TButtonPanel::restart_sound_system(void) {
    if (this->sound_number != -1) {
        this->sound = rge_base_game->get_sound(this->sound_number);
    }
    return 1;
}
