#include "../../include/m_dg_obj_context.h"

// m_dg_obj.cpp lines 24-27.
RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(
    RGE_Master_Doppleganger_Object* param_1, int param_2)
    : RGE_Master_Animated_Object(param_1, 0) {
    if (param_2 != 0) {
        setup(param_1);
    }
}
