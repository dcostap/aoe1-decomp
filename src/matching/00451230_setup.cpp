#include "../../include/m_dg_obj_context.h"

int RGE_Master_Doppleganger_Object::setup(
    RGE_Master_Doppleganger_Object* param_1) {
    RGE_Master_Animated_Object::setup(param_1);
    this->master_type = 0x19;
    this->fog_flag = 3;
    return 1;
}
