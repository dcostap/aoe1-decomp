// numberDrawLines (0047DC40, 8 bytes, Pnl_txt.cpp)
// simple getter returning this->draw_lines
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char _pad[0xFA];
    short draw_lines; // +0xFA
    int numberDrawLines() const;
};
#endif

int TTextPanel::numberDrawLines() const {
    return draw_lines;
}
