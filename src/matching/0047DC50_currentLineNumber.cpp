// currentLineNumber (0047DC50, 8 bytes, Pnl_txt.cpp)
// simple getter returning this->cur_line
#include "../../include/game_globals.h"
#include "../../include/game_types.h"

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char _pad[0x100];
    short cur_line; // +0x100
    int currentLineNumber() const;
};
#endif

int TTextPanel::currentLineNumber() const {
    return cur_line;
}
