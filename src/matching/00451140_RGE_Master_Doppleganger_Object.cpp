#include "../../include/m_dg_obj_context.h"

// m_dg_obj.cpp lines 33-36.
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Animated_Object(param_1, param_2, param_3, 0) {
    if (param_4 != 0) {
        setup(param_1, param_2, param_3);
    }
}
