class TDigital;

#ifndef PNL_BTN_SHARED_CONTEXT
#include "../../include/pnl_btn_context.h"

#endif

void TButtonPanel::stop_sound_system(void) {
    if (this->sound != 0) {
        this->sound = 0;
    }
}
