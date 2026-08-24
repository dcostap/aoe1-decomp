#include "../../include/pnl_scr_context.h"

long TScreenPanel::setup(TDrawArea* draw_area, char* text, long id, unsigned char flag, int param5) {
    return TEasy_Panel::setup(draw_area, 0, 0, -1, 1, 0, 0, 0, 0, param5) != 0;
}
