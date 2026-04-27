// get_state (00472810, 8 bytes, Pnl_btn.cpp)
// returns this->cur_state
#include "game_globals.h"
#include "game_types.h"

class TButtonPanel {
public:
    unsigned char _pad[0x1F6];
    short cur_state;  // +0x1F6
};

int TButtonPanel::get_state() {
    return cur_state;
}
