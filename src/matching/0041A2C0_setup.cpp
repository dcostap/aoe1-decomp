#ifndef ANI_OBJ_SHARED_CONTEXT
#include "../../include/ani_obj_context.h"
#endif

int RGE_Animated_Object::setup(RGE_Master_Animated_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    RGE_Static_Object::setup((RGE_Master_Static_Object*)param_1, param_2, param_3, param_4, param_5);
#ifdef ANI_OBJ_SHARED_CONTEXT
    this->type = 0x14;
#else
    this->field_4E = 0x14;
#endif
    this->speed = 0;
    this->set_sleep_flag(0);
    return 1;
}
