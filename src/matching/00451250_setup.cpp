#include "../../include/m_dg_obj_context.h"

int RGE_Master_Doppleganger_Object::setup(
    int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    RGE_Master_Animated_Object::setup(param_1, param_2, param_3);
    this->master_type = 0x19;
    return 1;
}
