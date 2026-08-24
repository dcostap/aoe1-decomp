#include "../../include/act_entr_context.h"

RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3)
    : RGE_Action(param_1, 1) {
    XYPoint start;
    XYPoint dest;
    XYPoint rVal;
    RGE_Action* action;

    this->action_type = 3;
    this->task = param_2;
    this->set_target_obj(param_3);
    if (param_3 == 0) {
        return;
    }

    this->target_x = param_3->world_x;
    this->target_y = param_3->world_y;
    this->target_z = param_3->world_z;

    if (param_3->actionState() == 2) {
        if (param_3->more_room() == 1) {
            if (this->obj->owner->computerPlayer() == 0) {
                goto line_path;
            }
        }

        if (this->obj->owner->computerPlayer() == 1) {
            goto line_path;
        }
    }

    if (param_3->actionState() == 11) {
        action = ((RGE_Action_Object*)param_3)->actions->get_action();
        if (action->target2ID == 0) {
            goto line_path;
        }
    }

    if (param_3->actionState() == 11) {
        action = ((RGE_Action_Object*)param_3)->actions->get_action();
        this->target_x = action->targetX();
        action = ((RGE_Action_Object*)param_3)->actions->get_action();
        this->target_y = action->targetY();
    }

    return;

line_path:
    dest.x = (int)param_1->world_x;
    dest.y = (int)param_1->world_y;
    start.x = (int)param_3->world_x;
    start.y = (int)param_3->world_y;

    if (param_1->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
        this->target_x = (float)rVal.x + 0.5f;
        this->target_y = (float)rVal.y + 0.5f;
        param_3->moveTo((float)rVal.x, (float)rVal.y, param_3->world_z, 0.5f, 1);
    } else {
        this->target_x = param_3->world_x;
        this->target_y = param_3->world_y;
        param_3->moveTo(param_1->world_x, param_1->world_y, param_3->world_z, 0.5f, 1);
    }
}
