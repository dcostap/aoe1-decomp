#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

RGE_Sprite* TRIBE_Action_Trade::get_move_sprite(void) {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->facet == task_facet) {
            if ((int)this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->move_sprite;
}
