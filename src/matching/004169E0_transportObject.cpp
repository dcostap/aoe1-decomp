#include "../../include/aiuaimod_context.h"

int UnitAIModule::transportObject(float param_1, float param_2, float param_3, int param_4) {
    if ((param_4 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->transport(param_1, param_2, param_3, param_4) == 1) {
            this->setCurrentAction(0x266);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}
