// 004D32F0 TRIBE_Action_Trade::get_wait_sprite
// Source: tact_trd.cpp lines 646-653
// The fallback reads the master sprite at the proven +0x18 field.

#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

RGE_Sprite* TRIBE_Action_Trade::get_wait_sprite(void) {
    TRIBE_Action_Trade* action = this;
    RGE_Task* task = action->task;
    short task_facet = task->attribute_type;

    if (task_facet != (short)0xFFFF && task_facet == action->obj->facet
        && (int)action->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return action->obj->master_obj->sprite;
}
