// tried the straight array fill; VC5 moved the loop into a different basin
// current gap is only the fill loop shape/register allocation around unitsOriginalHitPointsValue
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

    void setSpecificCommander(int value, TribeMainDecisionAIModule* md);
    void removeUnits(TribeMainDecisionAIModule* md);
};

void TacticalAIGroup::removeUnits(TribeMainDecisionAIModule* md) {
    setSpecificCommander(-1, md);
    numberUnitsValue = 0;

    int* piVar1 = unitsOriginalHitPointsValue;
    int iVar2 = 0x28;
    do {
        piVar1[-0x28] = -1;
        *piVar1 = -1;
        piVar1 = piVar1 + 1;
        iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
}
