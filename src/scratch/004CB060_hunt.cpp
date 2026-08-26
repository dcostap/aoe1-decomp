// VA: 004CB060 TRIBE_Combat_Object::hunt
// Canonical ownership: t_c_obj_context.h owns the complete combat/action ABI.
// FLAGS: config/flags/004CB060_hunt.rsp

#include "../../include/t_c_obj_context.h"

int TRIBE_Combat_Object::hunt(int object_id, int force) {
    RGE_Static_Object* target = owner_data->world->object(object_id);
    if (target == 0)
        return 0;

    if (force == 0 && actions->have_action() == 1 &&
        actions->get_action()->get_target_obj() == target &&
        actions->get_action()->type() == 0x6E) {
        return 1;
    }

    if (actions->have_action() == 1 &&
        actions->get_action()->type() == 0x6E) {
        actions->get_action()->set_target(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* action_id = make_action(target, target->world_x,
                                      target->world_y, target->world_z);
    if (action_id == 0)
        return 0;

    TRIBE_Action_Hunt* new_action =
        new TRIBE_Action_Hunt(this, action_id, target);
    if (new_action == 0)
        return 0;

    actions->delete_list();
    add_action(new_action);
    return 1;
}
