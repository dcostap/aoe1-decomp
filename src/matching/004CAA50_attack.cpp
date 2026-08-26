// compact combat attack wrapper first
// expected basin: a pre-attack owner/permission check, optional owner-side callback, then base combat attack

#include "../../include/t_c_obj_context.h"

unsigned char TRIBE_Combat_Object::attack(RGE_Static_Object* target,
                                          RGE_Combat_Object* other) {
    if (this->context->field_124 >= 0 && target != 0 && target->owner->id > 0) {
        target->owner->make_new_object(0x70, this->field_38, this->field_3C,
                                       this->field_40, 0);
    }
    return RGE_Combat_Object::attack(target, other);
}
