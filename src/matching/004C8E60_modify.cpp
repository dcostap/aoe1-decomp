#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::modify(float value, unsigned char attribute) {
    if (attribute != 0x11) {
        TRIBE_Combat_Object::modify(value, attribute);
        return;
    }
    this->field_35 = (unsigned char)value;
}
