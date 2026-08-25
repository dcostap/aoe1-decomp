#include "../world_phase2_context.h"

int RGE_Game_World::removeObject(int param_1) {
    int edx = param_1;

    if (edx < 0) {
        int esi = this->maxNumberNegativeObjectsValue;
        int eax = edx;
        eax = -eax;
        if (eax < esi) {
            this->negativeObjectsValue[eax] = 0;
            return 1;
        }
    }
    if ((edx > -1) && (edx < this->maxNumberObjectsValue)) {
        this->objectsValue[edx] = 0;
        return 1;
    }
    return 0;
}
