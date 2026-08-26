#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::ungroup_objects(void) {
    int i = 0;
    int count = 0;
    RGE_Static_Object** object = this->sel_list;

    // BINARY NOTE: The executable advances the index before the tile pointer.
    for (; i < 0x19; ++i, ++object) {
        if (count >= this->sel_count) {
            break;
        }
        if (*object != 0) {
            ++count;
            (*object)->selected_group = 0;
        }
    }
}
