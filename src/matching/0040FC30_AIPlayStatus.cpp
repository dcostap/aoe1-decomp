// VA: 0040FC30 AIPlayStatus::AIPlayStatus
//
// Attempt log:
// - Prior scratch matched behavior and exact size, with only return-value restore drift: `mov eax,esi` emitted after
//   final hit-point stores instead of after the first store.
// - SpruceGlow tried result locals before/after first hit-point store, use-result-all, volatile result, raw stores,
//   and comma/no-op forms; all kept the same tail restore drift.
// - SpruceGlow MATCH: spell the five originalHitPoints stores as a small `for (int j=0; j<5; j++)` loop. VC5 unrolls
//   it into the original five stores and places `mov eax, esi` at the required point.
// Result: MATCH locally with `python tools/check_function.py --va 0040FC30`.

#ifndef AIPBOOK_CANONICAL_TU
class XYZ {
public:
    char data[0x0C];
    XYZ(int, int, int);
};

struct GroupingStruct {
    int id;
    unsigned char groupType;
    unsigned char unitType;
    char gap_06[2];
};

class AIPlayStatus {
public:
    GroupingStruct groupings[50];
    int playNumberValue;
    int targetValue;
    XYZ originalPointValue;
    int originalHitPointsValue[5];
    unsigned char currentPhaseValue;
    char pad_1B9[3];
    int savedAttackerValue;
    unsigned long lastPhaseChangeTimeValue;
    unsigned char deviationValue;
    char pad_end[3];
    AIPlayStatus();
};
#endif

AIPlayStatus::AIPlayStatus()
    : playNumberValue(-1),
      targetValue(-1),
      originalPointValue(0, 0, 0) {
    int i;

    this->currentPhaseValue = 0xFD;
    this->savedAttackerValue = -1;
    this->lastPhaseChangeTimeValue = 0;
    this->deviationValue = 0;

    for (i = 0; i < 50; i++) {
        this->groupings[i].id = -1;
        this->groupings[i].groupType = 0xFF;
        this->groupings[i].unitType = 0xFF;
    }

    for (int j = 0; j < 5; j++) {
        this->originalHitPointsValue[j] = -1;
    }
}
