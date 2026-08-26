// VA: 004CC5B0 TRIBE_Combat_Object::do_repair
// PDB: t_c_obj.cpp:1678-1777
// Attempt log:
// baseline: replace the prior raw-vtable/inline-asm scaffold with the natural
// typed action-list/task lookup and UnitAI dispatch supported by the same-TU
// RGE_Action_Object::work2 donor.
// probe: an explicit for-loop and a separate task local worsened the prologue;
// the donor-shaped guarded do/while with the selected task loaded directly
// recovered exact size/CFG and left only the no-task-list candidate reload.
// Promotion audit rejected the prior exact diagnostic: it used a volatile,
// type-punning reload of the target parameter as an RGE_Task*. The empty-list
// path is instead left uninitialized below. The oracle reloads the incoming
// target home at that point, which is original undefined-path behavior.
// Same-TU action declarations now retain the proven object and task offsets.
// probe: direct typed target fallback improved the mismatch from 249 to 248
// bytes; non-volatile address, memcpy, and reference aliases stayed at 248 or
// worsened the prologue. Keep the direct cast as the binary-supported source.
// probe: same-TU virtual base and task-list declarations initially shifted
// offsets; removing compensating gaps restored the 248-byte codegen basin.
// probe: a focused seven-way lab of non-volatile target casts, address aliases,
// and local pointer copies collapsed to one 383-byte codegen group; none
// reproduced the oracle's +0x83 parameter-home reload.
// probe: using this as the empty-list task candidate improved positional diff
// by four bytes but lost the shared jump block and worsened shape; restored the
// uninitialized path because the candidate is not behavior-plausible.
// fresh pass: dossier, same-TU donors, and stack-home lessons confirm the
// remaining +0x83 reload as the only natural-source blocker; no new lead.
// probe: leaving repair_task uninitialized when the task list is empty exactly
// reproduces the oracle's mov esi,[esp+18h]. At this point that slot is the
// incoming target home. Keep the original undefined-path behavior because
// the binary proves this reload.

#include "../../include/t_c_obj_context.h"

void TRIBE_Combat_Object::do_repair(RGE_Static_Object* target)
{
    RGE_Task* repair_task;
    RGE_Task_List* repair_list;
    int i;
    int task_count;
    RGE_Task** task_list;
    RGE_Task* current_task;
    short action_id;
    int action_worked;
    RGE_Action* action;
    int order;
    int current_action;

    if ((RGE_Action_Object*)target != this) {
        if (this->master_obj->id != 0x9c) {
            this->transform(this->owner->master_objects[0x9c]);
        }

        repair_list = this->master_obj->tasks;
        i = 0;
        task_count = (int)repair_list->list_num;
        // The original leaves repair_task uninitialized when the list is empty.
        if (task_count > 0) {
            repair_task = 0;
            task_list = repair_list->list;
            do {
                repair_task = *task_list;
                if (repair_task->action_id == 0x6a) {
                    RGE_Master_Static_Object* target_master = target->master_obj;
                    if (target_master->master_type == 'P') {
                        if (repair_task->object_group == -1 ||
                            repair_task->object_group == 0) {
                            break;
                        }
                    }
                    if (repair_task->object_group == target_master->object_group) {
                        break;
                    }
                }
                repair_task = 0;
                ++i;
                ++task_list;
            } while (i < task_count);
        }

        current_task = this->actions->get_task();
        action_id = 0;
        action_worked = 0;
        if (current_task != 0 && repair_task == current_task &&
            this->actions->action_work(target,
                                       target->world_x,
                                       target->world_y,
                                       target->world_z) != 0) {
            action_id = this->actions->get_action()->type();
            action_worked = 1;
        }

        if (action_worked == 0) {
            if (repair_task != 0) {
                action = this->actions->create_task_action(
                    repair_task, target,
                    target->world_x, target->world_y, target->world_z);
            } else {
                action = 0;
            }

            if (action != 0) {
                action_id = action->type();
                this->set_action(action);
            } else {
                action_id = 0;
            }
        }

        if (this->unit_ai != 0) {
            order = -1;
            current_action = -1;
            if (action_id == 0x6a) {
                current_action = 0x26a;
                order = 0x2ce;
            }
            this->unit_ai->setCurrentOrder(order);
            this->unit_ai->setCurrentAction(current_action);
            this->unit_ai->setCurrentTarget(
                target->id,
                target->master_obj->object_group,
                target->world_x,
                target->world_y,
                target->world_z);
            this->unit_ai->setTaskedByPlayer();
        }
    }
}
