#include "../../include/act_obj_context.h"

void RGE_Action_Object::set_task(short task_id) {
    RGE_Task* task;
    RGE_Action* action;

    task = ((RGE_Master_Action_Object*)this->master_obj)->get_task(task_id);
    if (task != 0) {
        action = this->actions->create_task_action(task, 0, -1.0f, -1.0f, -1.0f);
        if (action != 0) {
            this->set_action(action);
        }
    }
}
