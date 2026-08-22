#include "../../include/t_c_obj_heal_context.h"

int TRIBE_Combat_Object::can_debark() {
    if (this->can_debark_master->value_8F != 7) {
        return 0;
    }
    return this->can_debark_state->value_08 != 0;
}
