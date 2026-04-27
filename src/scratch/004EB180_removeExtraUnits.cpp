// attempt 1: direct TacticalAIGroup compaction loop with member call to removeUnitByIndex and reload-on-iterate basin
// attempt 2: switch to the decompiler-style slot pointer + do/while shape; the first pass came in 3 bytes short, so this is a size-basin probe
// attempt 3: re-align the compare algebra and loop-cap spelling to the asm order; the mismatch moved right onto the first branch pair
// attempt 4: fall back to the decompiler's exact branching skeleton; the remaining drift is now just block layout and compare spelling around the loop gate
// attempt 5: try the original current-vs-desired compare order plus an explicit 0x28 cap; the earlier basin proved the right size, so this is the last small branch-shape probe
// blocker: size is correct, but the compare/loop-gate basin still emits the wrong early branch layout (cmp/jcc target spacing and loop-cap form); leaving it in scratch rather than forcing a false exact match
#include "..\..\include\game_types.h"

class TribeMainDecisionAIModule;

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;

    int removeUnitByIndex(int index, TribeMainDecisionAIModule* param_1);
    int removeExtraUnits(TribeMainDecisionAIModule* param_1);
};

int TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule* param_1) {
    int iVar1;
    int* piVar2;
    int iVar3;

    iVar1 = this->numberUnitsValue;
    if (iVar1 > this->desiredNumberUnitsValue && 0 < iVar1) {
        iVar3 = 0;
        if (iVar1 > this->desiredNumberUnitsValue) {
            piVar2 = this->unitsValue;
            do {
                if (0x28 <= iVar3) {
                    return 1;
                }
                if (*piVar2 != -1) {
                    this->removeUnitByIndex(iVar3, param_1);
                }
                iVar3 = iVar3 + 1;
                piVar2 = piVar2 + 1;
            } while (this->desiredNumberUnitsValue < this->numberUnitsValue);
        }
        return 1;
    }
    return 0;
}
