// VA: 00403C90 RGE_Action_Gather::get_wait_sprite
// PDB source: ACT_GATH.cpp.  The task, master, and action-object fields are canonical.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

RGE_Sprite* RGE_Action_Gather::get_wait_sprite() {
    RGE_Task* task = this->task;
    short value = task->attribute_type;
    if (value != (short)0xFFFF &&
        value == this->obj->attribute_type_held &&
        (int)this->obj->attribute_amount_held > 0 &&
        task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return this->obj->master_obj->sprite;
}
