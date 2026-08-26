#ifndef ANI_OBJ_SHARED_CONTEXT
#include "../../include/ani_obj_context.h"
#endif

void RGE_Animated_Object::release_being_worked_on(RGE_Static_Object* object) {
    RGE_Static_Object::release_being_worked_on(object);
    RGE_Static_Object::set_sleep_flag(0);
}
