// numberDrawLines (0047DC40, 8 bytes, Pnl_txt.cpp)
// simple getter returning this->draw_lines
#include "game_globals.h"
#include "game_types.h"

class TTextPanel {
public:
    unsigned char _pad[0xFA];
    short draw_lines; // +0xFA
};

int TTextPanel::numberDrawLines() {
    return draw_lines;
}
