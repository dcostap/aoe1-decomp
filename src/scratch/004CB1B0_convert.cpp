// VA: 004CB1B0 TRIBE_Combat_Object::convert
// Canonical ownership is the t_c_obj context. The body keeps the reviewed
// target, task, constructor, delete, and add order.
// FLAGS: config/flags/004CB1B0_convert.rsp

#include "../../include/t_c_obj_context.h"

int TRIBE_Combat_Object::convert(int object_id, int force) {
    RGE_Static_Object* target;
    RGE_Task* action_id;
    TRIBE_Action_Convert* action;
    int result;

    target = owner_data->world->object(object_id);
    if (target == 0) {
        result = 0;
        goto end;
    }

    if (force == 0 && actions->have_action() == 1 &&
        actions->get_action()->get_target_obj() == target &&
        actions->get_action()->type() == 0x68) {
        result = 1;
        goto end;
    }

    if (actions->have_action() == 1 &&
        actions->get_action()->type() == 0x68) {
        actions->get_action()->set_target(target, target->world_x,
                                          target->world_y, target->world_z);
        result = 1;
        goto end;
    }

    action_id = make_action(target, target->world_x, target->world_y,
                            target->world_z);
    if (action_id == 0) {
        result = 0;
        goto end;
    }

    action = new TRIBE_Action_Convert(this, action_id, target);
    if (action == 0) {
        result = 0;
        goto end;
    }

    actions->delete_list();
    add_action(action);
    result = 1;
end:
    return result;
}
