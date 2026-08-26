// get_id (00472820, 15 bytes, Pnl_btn.cpp)
// returns this->id[this->cur_state]
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    unsigned char _pad[0xF4];
    long id[9];        // +0xF4
    unsigned char _pad2[0x62];
    short cur_state;  // +0x1F6
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::get_id() {
    return id[cur_state];
}
