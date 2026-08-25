// player.cpp:734-749, 102 bytes.
// The grouped player context shifts four virtual calls by one slot.
// Keep this source observed until binary evidence resolves the class hierarchy.
#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

RGE_Static_Object* RGE_Player::make_scenario_obj(float x, float y, float z, short typeID, unsigned char objType, float param6) {
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* master = this->master_objects[typeID];
    if (master != 0) {
        obj = (RGE_Static_Object*)master->make_new_obj(this, x, y, z);
        if (objType >= 7) {
            obj->destroy_obj();
        } else if (objType > 2) {
            obj->die_die_die();
        } else {
            obj->new_angle(param6);
        }
    }
    return obj;
}
