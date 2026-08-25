#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_current_target.h"
#endif

int RGE_Combat_Object::currentTargetID() const {
    if (action_list->have_action() == 1) {
        if (action_list->get_action()->get_target_obj() != 0) {
            return action_list->get_action()->get_target_obj()->object_id;
        }
    }
    return -1;
}
