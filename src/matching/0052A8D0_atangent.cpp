#ifndef AOE1_TRIG_TU_CONTEXT
#include "../trig_tu_context.h"
#endif

float TRIGONOMETRY::atangent(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->atane[index];
}
