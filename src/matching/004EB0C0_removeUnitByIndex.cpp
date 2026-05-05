// 004EB0C0 TacticalAIGroup::removeUnitByIndex(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 347-360
// Attempt log:
// - Replaced stub with Ghidra logic and dummy-virtual vtable +0xCC dispatch.

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class PlayerVTableCC {
public:
    VPAD32(0) VPAD16(32) VPAD2(48) VPAD1(50)
    virtual void cmdCC(int commander, int unit);
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    PlayerVTableCC* player;
};

class TacticalAIGroup {
public:
    char gap_00[0x1C];
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;

    void setSpecificCommander(int commander, TribeMainDecisionAIModule* md);
    int removeUnitByIndex(int index, TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::removeUnitByIndex(int index, TribeMainDecisionAIModule* md)
{
    int unit;
    int commander;

    if (index >= 0 && index < 40) {
        unit = this->unitsValue[index];
        commander = this->commanderValue;
        if (unit == commander) {
            this->setSpecificCommander(-1, md);
        }
        else if (commander != -1) {
            md->player->cmdCC(commander, unit);
        }
        this->unitsValue[index] = -1;
        this->unitsOriginalHitPointsValue[index] = -1;
        this->numberUnitsValue = this->numberUnitsValue - 1;
        return 1;
    }
    return 0;
}
