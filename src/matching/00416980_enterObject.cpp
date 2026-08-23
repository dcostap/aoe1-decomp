#include "../../include/aiuaimod_context.h"

int UnitAIModule::enterObject(int param_1, int param_2) {
    if ((param_2 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->enter(param_1, param_2) == 1) {
            this->setCurrentAction(0x269);
            this->setCurrentTarget(param_1, -1.0f, -1.0f, -1.0f);
            return 1;
        }
    }
    return 0;
}
