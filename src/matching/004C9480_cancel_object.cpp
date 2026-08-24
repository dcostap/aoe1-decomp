#include "../../include/t_b_obj_context.h"
void TRIBE_Building_Object::cancel_object() {
    if (this->field_48 < 2) {
        this->cancel_build();
    } else {
        TRIBE_Combat_Object::cancel_object();
    }
}
