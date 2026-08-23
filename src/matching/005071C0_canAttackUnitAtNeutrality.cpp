#include "../../include/taiuaimd_context.h"

// PDB ownership gives a public virtual TribeSoldierUnitAIModule method.

int TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int value) {
    if (value == 0x3 || value == 0x1B || value == 0x4 || value == 0x15 || value == 0x2 || value == 0x14)
        return 0;
    return 1;
}
