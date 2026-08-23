// VA: 00416910 UnitAIModule::explore (101 B)
// PDB source: aiuaimod.cpp lines 3309-3322

#include "../../include/aiuaimod_context.h"

int UnitAIModule::explore(int param_1, int param_2, int param_3)
{
    if (param_3 != 0 || this->currentActionValue == -1) {
        if (this->objectValue->explore(param_1, param_2, param_3) == 1) {
            this->setCurrentAction(0x25D);
            this->setCurrentTarget(-1, (float)param_1, (float)param_2, 1.0f);
            return 1;
        }
    }
    return 0;
}
