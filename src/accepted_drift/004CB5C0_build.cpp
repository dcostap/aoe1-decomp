// VA: 004CB5C0 TRIBE_Combat_Object::build(int, int)
// Canonical ownership is the shipped TRIBE_Combat_Object class.
// The action tests, task creation, constructor, list deletion, publication,
// and zero/one results retain the reviewed accepted-drift behavior.
// FLAGS: config/flags/004CB5C0_build.rsp (/GX)

#include "../../include/t_c_obj_context.h"

int TRIBE_Combat_Object::build(int id, int flag) {
    RGE_Static_Object* result;
    RGE_Task* task;

    result = this->owner->world->object(id);
    if (result != 0) {
        if (flag == 0) {
            if (this->actions->have_action() == 1) {
                if (this->actions->get_action()->get_target_obj() == result &&
                    this->actions->get_action()->type() == 0x65) {
                    result = (RGE_Static_Object*)1;
                    goto done;
                }
            }
        }

        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->type() == 0x65) {
                this->actions->get_action()->work(result, result->world_x,
                                                  result->world_y,
                                                  result->world_z);
                result = (RGE_Static_Object*)1;
                goto done;
            }
        }

        task = this->getTask(result, result->world_x, result->world_y,
                             result->world_z);
        if (task == 0) {
            result = (RGE_Static_Object*)task;
            goto done;
        }

        TRIBE_Action_Build* build_action =
            new TRIBE_Action_Build((RGE_Action_Object*)this, task, result);
        result = (RGE_Static_Object*)build_action;
        if (build_action == 0)
            goto done;

        this->actions->delete_list();
        this->set_only_action(build_action);
        result = (RGE_Static_Object*)1;
    }

done:
    return (int)result;
}
