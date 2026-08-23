#include "../../include/aiuaimod_context.h"

int UnitAIModule::moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) {
    int result;

    if (param_5 != 0 || this->currentActionValue == -1) {
        result = this->objectValue->moveTo(param_1, param_2, param_3, param_4, param_5);
        if (result == 1) {
            this->setCurrentAction(0x262);
            this->setCurrentTarget(-1, param_1, param_2, param_3);
            return 1;
        }
    }
    return 0;
}
