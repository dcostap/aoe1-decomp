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

class XYZ {
public:
    char data[0x0C];
    void init(int, int, int);
};

class AIPlayStatus {
public:
    char groupings[0x190];
    int playNumberValue;
    int targetValue;
    char originalPointValue[0x0C];
    int originalHitPointsValue[5];
    unsigned char currentPhaseValue;
    char pad_1B9[3];
    int savedAttackerValue;
    unsigned long lastPhaseChangeTimeValue;
    unsigned char deviationValue;
    char pad_end[3];
    AIPlayStatus();
};

AIPlayStatus::AIPlayStatus() {
    unsigned char* p;
    int i;

    this->playNumberValue = -1;
    this->targetValue = -1;
    ((XYZ*)&this->originalPointValue[0])->init(0, 0, 0);
    this->currentPhaseValue = 0xFD;
    this->savedAttackerValue = -1;
    this->lastPhaseChangeTimeValue = 0;
    this->deviationValue = 0;

    p = (unsigned char*)&this->groupings[5];
    i = 0x32;
    do {
        *(int*)(p - 5) = -1;
        p[-1] = 0xFF;
        *p = 0xFF;
        p += 8;
        i--;
    } while (i != 0);

    for (int j = 0; j < 5; j++) {
        this->originalHitPointsValue[j] = -1;
    }
}
