#ifndef AOE1_TRIG_TU_CONTEXT
#include "../trig_tu_context.h"
#endif

float TRIGONOMETRY::cos360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->cose360[index];
}
