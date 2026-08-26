// numberLines (0047DC30, 8 bytes, Pnl_txt.cpp)
// simple getter returning this->num_lines
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

// local stub for TTextPanel (partial)
#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char _pad[0xF8];
    short num_lines; // +0xF8
    int numberLines() const;
};
#endif

int TTextPanel::numberLines() const {
    return num_lines;
}
