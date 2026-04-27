// currentLineNumber (0047DC50, 8 bytes, Pnl_txt.cpp)
// simple getter returning this->cur_line
#include "game_globals.h"
#include "game_types.h"

class TTextPanel {
public:
    unsigned char _pad[0x100];
    short cur_line; // +0x100
};

int TTextPanel::currentLineNumber() {
    return cur_line;
}
