#ifndef ACT_TRAN_SHARED_CONTEXT
#include "../../include/act_tran_context.h"
#endif

int RGE_Action_Transport::move_to(RGE_Static_Object* object, float x, float y, float z) {
    this->field_20 = x;
    this->field_24 = y;
    *(int*)((char*)this + 0x1C) = 0;
    this->field_28 = z;
    this->set_state(0x0B);
    return 1;
}
