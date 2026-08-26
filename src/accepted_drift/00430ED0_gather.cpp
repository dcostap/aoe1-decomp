// VA: 00430ED0 RGE_Combat_Object::gather
// Source: com_obj.cpp lines 988-1040
// Accepted drift: the remaining difference is a return-register choice in the
// compiler's EH tail. The source keeps the original task and action flow.

#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::gather(int object_id, int force) {
    RGE_Static_Object* target = this->player->world->object(object_id);
    RGE_Task* task;
    RGE_Action_Gather* action;
    RGE_Static_Object* result = target;
    if (target == 0) {
        goto done;
    }

    if (force == 0 &&
        this->action_list->have_action() == 1 &&
        this->action_list->get_action()->get_target_obj() == target &&
        this->action_list->get_action()->type() == 5) {
        goto success;
    }

    if (this->action_list->have_action() == 1 &&
        this->action_list->get_action()->type() == 5) {
        this->action_list->get_action()->set_target_obj(target);
        goto success;
    }

    task = this->create_gather_task(target, target->world_x, target->world_y, target->world_z);
    if (task == 0) {
        result = 0;
        goto done;
    }

    action = new RGE_Action_Gather(this, task, target);
    result = (RGE_Static_Object*)action;
    if (action == 0) {
        goto done;
    }

    this->action_list->delete_list();
    this->add_action(action);
success:
    result = (RGE_Static_Object*)1;
done:
    return (int)result;
}
