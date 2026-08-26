// VA: 004CB450 TRIBE_Combat_Object::repair(int, int)
// Canonical ownership is the shipped TRIBE_Combat_Object class.
// Accepted-drift review: the action tests, retarget, owner notification,
// task creation, constructor, list deletion, publication, and results match.
// FLAGS: /nologo /c /O2 /Oy /GX

#include "../../include/t_c_obj_context.h"

int TRIBE_Combat_Object::repair(int id, int flag) {
    RGE_Static_Object* obj = this->owner->world->object(id);
    if (obj != 0) {
        if (flag == 0 && this->actions->have_action() == 1 &&
            this->actions->get_action()->get_target_obj() == obj &&
            this->actions->get_action()->type() == 0x6A) {
            goto success;
        }

        if (this->actions->have_action() == 1 &&
            this->actions->get_action()->type() == 0x6A) {
            this->actions->get_action()->work(obj, obj->world_x,
                                              obj->world_y, obj->world_z);
            goto success;
        }

        if (this->owner->info->field_270 != 0) {
            this->set_only_action((RGE_Action*)this->owner->info->field_270);
        }

        RGE_Task* task = this->getTask(obj, obj->world_x, obj->world_y,
                                       obj->world_z);
        if (task != 0) {
            TRIBE_Action_Repair* repair_action =
                new TRIBE_Action_Repair(this, task, obj);
            if (repair_action != 0) {
                this->actions->delete_list();
                this->set_only_action(repair_action);
                goto success;
            }
        }
    }

    return 0;

success:
    return 1;
}
