#include "../../include/aiuaimod_context.h"

int UnitAIModule::seekAndDestroy(int param_1, int param_2, int param_3, int param_4) {
    if ((param_4 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->attack(param_1, param_4) == 1) {
            this->setCurrentAction(0x26E);
            this->setCurrentTarget(param_1, (float)param_2, (float)param_3, 1.0f);
            return 1;
        }
    }
    return 0;
}
