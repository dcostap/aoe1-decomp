// VA: 00403C60 RGE_Action_Gather::get_move_sprite
// PDB source: ACT_GATH.cpp.  The task and action-object fields are canonical.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

RGE_Sprite* RGE_Action_Gather::get_move_sprite() {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->attribute_type_held == task_facet) {
            if ((int)this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->move_sprite;
}
