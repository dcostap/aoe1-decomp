#include "../../include/t_b_obj_context.h"

int TRIBE_Building_Object::explore_terrain(RGE_Player* player, unsigned char value, int param) {
    if (this->built != 0) {
        return RGE_Static_Object::explore_terrain(player, value, param);
    }
    return RGE_Static_Object::explore_terrain(player, 1, param);
}
