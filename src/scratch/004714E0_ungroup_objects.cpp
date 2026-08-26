#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::ungroup_objects(void) {
    RGE_Static_Object** object = this->sel_list;
    int count = 0;

    for (int i = 0; i < 0x19; ++i) {
        if (count >= this->sel_count) {
            break;
        }
        if (*object != 0) {
            ++count;
            (*object)->selected_group = 0;
        }
        ++object;
    }
}
