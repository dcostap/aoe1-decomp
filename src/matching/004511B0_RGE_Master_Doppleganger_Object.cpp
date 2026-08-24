#include "../../include/m_dg_obj_context.h"

// m_dg_obj.cpp lines 42-45.
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3,
    short param_4, int param_5)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, param_4, 0) {
    if (param_5 != 0) {
        setup(param_1, param_2, param_3, param_4);
    }
}
