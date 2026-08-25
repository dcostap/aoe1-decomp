// VA: 004305D0 RGE_Combat_Object::release_being_worked_on
// Source: com_obj.cpp lines 550-562

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_release.h"
#endif

void RGE_Combat_Object::release_being_worked_on(RGE_Static_Object* target) {
    RGE_Animated_Object::release_being_worked_on(target);
    if (target->id >= 0) {
        notify(target->id, value_4, 0x2BB, target->master_obj->object_group, 0, 0);
    }
}
