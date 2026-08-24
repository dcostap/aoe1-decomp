// get_state (00472810, 8 bytes, Pnl_btn.cpp)
// returns this->cur_state
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    unsigned char _pad[0x1F6];
    short cur_state;  // +0x1F6
};
#endif /* PNL_BTN_SHARED_CONTEXT */

int TButtonPanel::get_state() {
    return cur_state;
}
