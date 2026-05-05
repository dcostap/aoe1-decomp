// 004EB3A0 TacticalAIGroup::setSpecificCommander(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 490-509
// Attempt log:
// - Replaced stub with full commander clear/set and member-list notification.
// - Exact match: initializing the live count before materializing the source
//   pointer (`count = 0; src = ...`) makes VC5 allocate count to EDI and reuse
//   ESI for the countdown, matching the original loop.

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class PlayerCommanderVTable {
public:
    VPAD32(0) VPAD16(32) VPAD1(48)
    virtual void cmdC4(int commander, int* units, int count, int amount);
    VPAD2(50)
    virtual void cmdD0(int commander);
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    PlayerCommanderVTable* player;
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
};

void TacticalAIGroup::setSpecificCommander(int commander, TribeMainDecisionAIModule* md)
{
    int temp[40];
    int* src;
    int* dst;
    int remaining;
    int count;
    int unit;

    if (this->commanderValue != -1) {
        md->player->cmdD0(this->commanderValue);
    }
    this->commanderValue = commander;
    if (commander != -1) {
        count = 0;
        src = this->unitsValue;
        dst = temp;
        for (remaining = 40; remaining != 0; remaining = remaining - 1) {
            unit = *src;
            *dst = unit;
            if (unit != -1) {
                count = count + 1;
                dst = dst + 1;
            }
            src = src + 1;
        }
        md->player->cmdC4(commander, temp, count, 0x40800000);
    }
}
