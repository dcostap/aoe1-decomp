// 004D3340 TRIBE_Action_Trade::move_to
// Source: tact_trd.cpp lines 669-690
// Size: 125 bytes, no EH, ret 10h
//
// The action hierarchy and target slots come from the tact_trd module context.

#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

int TRIBE_Action_Trade::move_to(RGE_Static_Object* obj, float x, float y, float z)
{
    if (obj != 0) {
        if (obj->owner == this->obj->owner) {
            if (obj->master_obj->id == this->obj->master_obj->id2) {
                if (obj == this->target_obj2 && this->state == 8) {
                    return 1;
                }
                this->set_target_obj2(obj);
                this->set_state(8);
                return 1;
            }
        }
    }

    // Null path: store in field-offset order.
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0xB);
    return 1;
}
