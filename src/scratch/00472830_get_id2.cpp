// get_id2 (00472830, 15 bytes, Pnl_btn.cpp)
// returns this->id2[this->cur_state]
#include "game_globals.h"
#include "game_types.h"

class TButtonPanel {
public:
    unsigned char _pad[0xF4];
    long id[9];        // +0xF4
    long id2[9];       // +0x118
    unsigned char _pad2[0x3C];
    short cur_state;  // +0x1F6
};

long TButtonPanel::get_id2() {
    return id2[cur_state];
}
