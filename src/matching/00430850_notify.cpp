#include "../com_obj_phase2_context.h"

void RGE_Combat_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (object_state == 2) {
        if (unitAIValue != 0) {
            if (unitAIValue->notify(param_1, param_2, param_3, param_4, param_5, param_6) != 0) {
                return;
            }
        }
        if (param_3 != 0x2BB) {
            owner->notify(param_1, param_2, param_3, param_4, param_5, param_6);
        }
    }
}
