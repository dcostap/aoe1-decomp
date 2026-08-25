extern "C" double __cdecl sqrt(double value);
#pragma intrinsic(sqrt)

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_range.h"
#endif

int RGE_Combat_Object::inAttackRange(RGE_Static_Object* obj) {
    float radius_distance;
    float max_distance;
    float range_x;
    float range_y;

    range_x = master_obj->range_30;
    range_y = master_obj->range_34;
    radius_distance = range_x * range_x + range_y * range_y;
    radius_distance = (float)sqrt((double)radius_distance);
    max_distance = weaponRange() + radius_distance - -0.300000012f;
    if (distance_to_object(obj) <= max_distance) {
        return 1;
    }
    return 0;
}
