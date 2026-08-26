// 004308C0 RGE_Combat_Object::attack(int target_id, int force)
// Attempt log:
// 1: Natural reconstruction from packet, modeled after matching 00430A90 attack(float,float,float,int); with /GX flag, close but initial object lookup used [this+0x0c] directly instead of owner->world.
// 2: Model +0x0c as owner/player with world at +0x3c, matching original first call and special group branch.
// FLAGS: config/flags/004308C0_attack.rsp uses /GX for original EH frame.

#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::attack(int target_id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(target_id);
    if (target == 0) {
        return 0;
    }

    if (force == 0) {
        if (this->action_list->have_action() == 1) {
            if (this->action_list->get_action()->get_target_obj() == target) {
                if (this->action_list->get_action()->type() == 9) {
                    return 1;
                }
                if (this->action_list->get_action()->type() == 7) {
                    return 1;
                }
            }
        }
    }

    if (this->action_list->have_action() == 1) {
        if (this->action_list->get_action()->get_target_obj() == target) {
            if (this->action_list->get_action()->type() == 9) {
                this->action_list->get_action()->work(target, target->x, target->y, target->z);
                return 1;
            }
        }
    }

    if (this->master->object_group == 4) {
        int value = *(int*)((char*)this->owner + 0x24);
        value = *(int*)((char*)value + 0x14c);
        if (value != 0) {
            this->set_something(value);
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, target, 0, 0, 0,
        this->master->field_114, this->master->field_138, this->master->field_124, this->master->field_12a);
    if (action == 0) {
        return 0;
    }
    this->action_list->delete_list();
    this->set_only_action(action);
    return 1;
}
