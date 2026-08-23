// VA: 00417510 UnitAIModule::exploreAndDestroy(int, int, int)
// PDB source: aiuaimod.cpp lines 3772-3785
// Match: 101/101 bytes, 0.0000%

#include "../../include/aiuaimod_context.h"

int UnitAIModule::exploreAndDestroy(int param_1, int param_2, int param_3) {
    if ((param_3 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->explore(param_1, param_2, param_3) == 1) {
            this->setCurrentAction(0x26F);
            this->setCurrentTarget(-1, (float)param_1, (float)param_2, 1.0f);
            return 1;
        }
    }
    return 0;
}
