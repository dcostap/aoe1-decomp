// VA: 004CA790 TRIBE_Combat_Object::die_die_die
// Canonical ownership is the shipped t_c_obj class surface.

#include "../../include/t_c_obj_context.h"

void TRIBE_Combat_Object::die_die_die() {
    if (field_48 == 2) {
        float val = *(float*)((int)unit_type->field_50 + 0xE4);
        if (val >= 1.0f) {
            RGE_Action* action = action_list->get_action();
            if (action != 0) {
                short type = action->type();
                if (type == 0x68) {
                    TRIBE_Action_Convert* convert =
                        (TRIBE_Action_Convert*)action;
                    convert->martyrdom();
                }
            }
        }
    }
    RGE_Static_Object::die_die_die();
}
