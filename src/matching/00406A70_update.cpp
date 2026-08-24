#include "../../include/act_obj_context.h"

unsigned char RGE_Action_Object::update()
{
    if (actionFile != 0) {
        int action_value;
        int action_state_value;

        if (this->actions->have_action() != 0) {
            action_value = this->actions->get_action()->type();
            action_state_value = this->actions->get_action()->state;
        } else {
            action_value = -1;
            action_state_value = -1;
        }

        if (this->lastActionValue != action_value ||
            this->lastActionStateValue != action_state_value) {
            fprintf(actionFile, "t%d, %d,%d,%d,%d,%d\n",
                    this->owner->world->world_time,
                    this->id,
                    this->lastActionValue,
                    this->lastActionStateValue,
                    action_value,
                    action_state_value);
            this->lastActionValue = action_value;
            this->lastActionStateValue = action_state_value;
        }
    }

    unsigned char result = RGE_Animated_Object::update();
    unsigned char state = this->object_state;

    if (state > 2) {
        if (this->actions->list != 0) {
            this->actions->delete_list();
            return result;
        }
    } else {
        if (this->actions->list == 0) {
            if (state == 2 &&
                ((RGE_Master_Action_Object*)this->master_obj)->default_task != -1) {
                this->set_task(((RGE_Master_Action_Object*)this->master_obj)->default_task);
                return result;
            }
        } else {
            if (this->inside_obj != 0) {
                this->actions->inside_obj_update();
                return result;
            }

            unsigned char action_result = this->actions->update();
            if (action_result == 3 || action_result == 1) {
                this->actions->remove_action();
            }
        }
    }

    return result;
}
