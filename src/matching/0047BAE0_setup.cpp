#include "../../include/pnl_scr_context.h"

long TScreenPanel::setup(TDrawArea* draw_area, char* text, long id, int value) {
    return TEasy_Panel::setup(draw_area, 0, text, id, 1, 0, 0, 0, 0, value) != 0;
}
