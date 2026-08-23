// numberLines (0047DC30, 8 bytes, Pnl_txt.cpp)
// simple getter returning this->num_lines
#include "game_globals.h"
#include "game_types.h"

// local stub for TTextPanel (partial)
class TTextPanel {
public:
    unsigned char _pad[0xF8];
    short num_lines; // +0xF8
};

int TTextPanel::numberLines() {
    return num_lines;
}
