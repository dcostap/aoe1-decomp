#include "../com_obj_phase2_context.h"

float RGE_Combat_Object::currentTargetY() const {
    if (action_list->have_action() == 1) {
        return action_list->get_action()->targetY();
    }
    return -1.0f;
}
