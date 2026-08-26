#ifndef DPL_OBJ_SHARED_CONTEXT
#include "../../include/dpl_obj_context.h"
#endif

int RGE_Doppleganger_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Animated_Object::setup(param_1, param_2);
    int x = (int)(long)(this->y);
    this->type = 0x19;
    int y = (int)(long)(this->x);
    this->MapAddress = (unsigned long*)unified_map_offsets[x] + y;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    return 1;
}
