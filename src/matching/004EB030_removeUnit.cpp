// 004EB030 TacticalAIGroup::removeUnit(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 324-341
// Attempt log:
// - Replaced old one-field stub with full Ghidra logic and real C++ member
//   surface.  Vtable +0xCC dispatch is modeled with dummy virtual slots.
// - Exact match: use an explicit pointer plus `while (i < 40)` scan. This keeps
//   the parameter load before saved-register pushes and emits the original
//   memory compare at the loop top instead of a peeled first-element load.

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
    int removeUnit(int unit, TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::removeUnit(int unit, TribeMainDecisionAIModule* md)
{
    int commander;
    int i;
    int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == unit) {
            commander = this->commanderValue;
            if (unit == commander) {
                this->setSpecificCommander(-1, md);
            }
            else if (commander != -1) {
                md->player->cmdCC(commander, unit);
            }
            this->unitsValue[i] = -1;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue - 1;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}
