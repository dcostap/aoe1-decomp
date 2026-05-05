// 004EAFA0 TacticalAIGroup::addUnit(int,TribeMainDecisionAIModule*)
// Source: taitacmd.cpp lines 303-319
// Attempt log:
// - Replaced old one-slot stub with full Ghidra logic and real C++ member
//   surface.  Vtable +0xC8 dispatch is modeled with dummy virtual slots.
// - Exact match: using `while (i < 40)` for the scan (not do-while) prevents
//   VC5 from peeling/preloading the first array element and matches the original
//   push-edi, xor-index, memory-cmp loop top.

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TimeList {
public:
    char gap_00[4];
    unsigned long next;
};

class PlayerVTableC8 {
public:
    VPAD32(0) VPAD16(32) VPAD2(48)
    virtual void cmdC8(int commander, int unit, int amount);

    char gap_04[0x38];
    TimeList* list;
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xF0];
    PlayerVTableC8* player;
};

class TacticalAIGroup {
public:
    char gap_00[0x1C];
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    char gap_168[0x32C - 0x168];
    unsigned long lastAddedUnitTimeValue;

    int addUnit(int unit, TribeMainDecisionAIModule* md);
};

int TacticalAIGroup::addUnit(int unit, TribeMainDecisionAIModule* md)
{
    int i;
    volatile int* p;

    i = 0;
    p = this->unitsValue;
    while (i < 40) {
        if (*p == -1) {
            this->unitsValue[i] = unit;
            this->unitsOriginalHitPointsValue[i] = -1;
            this->numberUnitsValue = this->numberUnitsValue + 1;
            if (this->commanderValue != -1) {
                md->player->cmdC8(this->commanderValue, unit, 0x40800000);
            }
            this->lastAddedUnitTimeValue = md->player->list->next;
            return 1;
        }
        i = i + 1;
        p = p + 1;
    }
    return 0;
}
