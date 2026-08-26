// Canonical ownership: t_c_obj_context.h owns the complete combat/action ABI.
// The body preserves the target, task, constructor, delete, and add order.
// FLAGS: config/flags/004CB300_heal.rsp (/GX)

#include "../../include/t_c_obj_context.h"

int TRIBE_Combat_Object::heal(int id, int flag) {
    RGE_Static_Object* target = this->game->world->object(id);
    if (target == 0)
        return 0;

    if (flag == 0 && this->action_list->have_action() == 1 &&
        this->action_list->get_action()->get_target_obj() == target &&
        this->action_list->get_action()->type() == 0x69)
        return 1;

    if (this->action_list->have_action() == 1 &&
        this->action_list->get_action()->type() == 0x69) {
        this->action_list->get_action()->set_target(target, target->x,
                                                     target->y, target->z);
        return 1;
    }

    RGE_Task* task = this->make_action(target, target->x, target->y,
                                       target->z);
    if (task == 0)
        return 0;

    TRIBE_Action_Heal* action =
        new TRIBE_Action_Heal((RGE_Action_Object*)this, task, target);
    if (action == 0)
        return 0;

    this->action_list->delete_list();
    this->add_action(action);
    return 1;
}
