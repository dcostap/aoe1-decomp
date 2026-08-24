// 004D33C0 TRIBE_Action_Trade::work
// Source: tact_trd.cpp lines 697-727
// Size: 162 bytes, no EH, ret 10h

#ifndef TACT_TRD_SHARED_CONTEXT
#include "..\..\include\tact_trd_context.h"
#define TACT_TRD_SHARED_CONTEXT 1
#endif

int TRIBE_Action_Trade::work(RGE_Static_Object* obj, float x, float y, float z)
{
    if (obj != 0) {
        if (obj == this->target_obj) {
            if (this->state == 4 || this->state == 6 || this->state == 7) {
                return 1;
            }
        }

        // Check owner/id match.
        if (obj->owner == ((RGE_Static_Object*)this->action_obj)->owner) {
            if (obj->master_obj->id == this->obj->master_obj->id2) {
                this->set_target_obj2(obj);
                this->set_state(8);
                return 1;
            }
        }

        this->set_target_obj(obj);
        this->set_state(4);
        return 1;
    }

    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0xB);
    return 1;
}
