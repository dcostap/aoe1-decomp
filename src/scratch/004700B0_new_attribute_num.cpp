#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

void RGE_Player::new_attribute_num(short attrib, float value) {
    if (attrib < 0) {
        return;
    }
    if (attrib >= this->attribute_num) {
        return;
    }
    this->attributes[(int)attrib] = value;
}
