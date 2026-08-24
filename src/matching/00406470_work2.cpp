// VA: 00406470 RGE_Action_Object::work2
// PDB source: act_obj.cpp lines 266-462
// The module uses the reviewed action-object, task-list, action, and player
// declarations.  This source no longer creates placeholder virtual slots.

#include "../../include/act_obj_context.h"

void RGE_Action_Object::work2(RGE_Static_Object* target,
                              float x, float y, float z,
                              unsigned char flag)
{
    int skip;
    RGE_Task* task;
    RGE_Action* action;
    RGE_Task* current_task;
    short action_id;
    RGE_Master_Static_Object* other;
    int i;
    int order;
    int current_action;

    if ((RGE_Action_Object*)target != this) {
        task = ((RGE_Master_Action_Object*)this->master_obj)->tasks->get_target_task(
            this, target, x, y, z);
        if (task == 0 && ((RGE_Master_Action_Object*)this->master_obj)->task_by_group != 0) {
            i = 0;
            for (; i < this->owner->master_object_num; i++) {
                other = this->owner->master_objects[i];
                if (other != 0 &&
                    other->object_group == this->master_obj->object_group &&
                    other->master_type == this->master_obj->master_type &&
                    ((RGE_Master_Action_Object*)other)->task_by_group ==
                        ((RGE_Master_Action_Object*)this->master_obj)->task_by_group) {
                    task = ((RGE_Master_Action_Object*)other)->tasks->get_target_task(
                        this, target, x, y, z);
                    if (task != 0) {
                        this->transform(other);
                        break;
                    }
                }
            }
        }

        current_task = this->actions->get_task();
        skip = 0;
        action_id = -1;
        if (current_task != 0 && task == current_task &&
            this->actions->action_work(target, x, y, z) != 0) {
            action_id = this->actions->get_action()->type();
            skip = 1;
        }

        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->get_target_obj() == target &&
                this->actions->get_action()->type() == 9) {
                if (this->actions->get_action()->work(target, x, y, z) != 0) {
                    action_id = this->actions->get_action()->type();
                    skip = 1;
                }
            }
        }

        if (skip == 0) {
            if (task != 0) {
                action = this->actions->create_task_action(task, target, x, y, z);
            } else {
                action = 0;
            }
            if (action != 0) {
                action_id = action->action_id();
                this->set_action(action);
            } else {
                action_id = 1;
                this->move_to(target, x, y, z);
            }
        }

        if (this->unitAIValue != 0) {
            order = -1;
            current_action = -1;
            switch (action_id) {
            case 9:
                current_action = 0x258;
                order = 0x2BC;
                break;
            case 0x65:
                current_action = 0x25A;
                order = 0x2BE;
                break;
            case 3:
                current_action = 0x269;
                order = 0x2CD;
                break;
            case 4:
                current_action = 0x25D;
                order = 0x2C1;
                break;
            case 5:
                current_action = 0x261;
                order = 0x2C5;
                break;
            case 1:
                current_action = 0x262;
                order = 0x2C6;
                break;
            case 0x6E:
                current_action = 0x265;
                order = 0x2C9;
                break;
            case 0x0C:
                current_action = 0x266;
                order = 0x2CA;
                break;
            case 0x6F:
                current_action = 0x267;
                order = 0x2CB;
                break;
            case 0x68:
                current_action = 0x25C;
                order = 0x2C0;
                break;
            case 0x69:
                current_action = 0x25B;
                order = 0x2BF;
                break;
            case 0x6A:
                current_action = 0x26A;
                order = 0x2CE;
                break;
            }

            this->unitAIValue->setCurrentOrder(order);
            this->unitAIValue->setCurrentAction(current_action);
            if (target != 0) {
                this->unitAIValue->setCurrentTarget(
                    target->id,
                    target->master_obj->object_group,
                    x, y, z);
            } else {
                this->unitAIValue->setCurrentTarget(-1, -1, x, y, z);
            }
            this->unitAIValue->setTaskedByPlayer();
        }
    }
}
