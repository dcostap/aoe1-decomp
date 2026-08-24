#ifndef T_C_OBJ_CONTEXT_H
#include "../../include/t_c_obj_context.h"
#endif

unsigned char TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int param) const {
    if (param == 0x32 || param == 0x2D) return 1;
    return 0;
}
