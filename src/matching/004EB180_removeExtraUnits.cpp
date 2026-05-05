// 004EB180 TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 377-390
// Attempt log:
// - Replaced stub with Ghidra logic and real C++ member/direct-call surface.

class TribeMainDecisionAIModule;

class TacticalAIGroup {
public:
    char gap_00[0x1C];
    int unitsValue[80];
    int numberUnitsValue;
    int desiredNumberUnitsValue;

    int removeUnitByIndex(int index, TribeMainDecisionAIModule* md);
    int removeExtraUnits(TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::removeExtraUnits(TribeMainDecisionAIModule* md)
{
    int number;
    int desired;
    int i;
    int* unit;

    number = this->numberUnitsValue;
    desired = this->desiredNumberUnitsValue;
    if (number > desired && number > 0) {
        i = 0;
        if (desired < number) {
            unit = this->unitsValue;
            while (1) {
                if (i >= 40) {
                    return 1;
                }
                if (*unit != -1) {
                    this->removeUnitByIndex(i, md);
                }
                i = i + 1;
                unit = unit + 1;
                if (this->desiredNumberUnitsValue < this->numberUnitsValue) {
                    continue;
                }
                break;
            }
        }
        return 1;
    }
    return 0;
}
