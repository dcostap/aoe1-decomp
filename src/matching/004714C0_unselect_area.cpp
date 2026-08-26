#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::unselect_area(void) {
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
}
