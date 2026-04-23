// natural constructor ordering with a manual XYZ call and the 50-slot grouping fill
// tried moving the raw-storage layout and constructor-call order around
// remaining mismatch is localized: EAX is restored after the final hit-point stores instead of before them
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

    this->originalHitPointsValue[0] = -1;
    volatile AIPlayStatus* result = this;
    result->originalHitPointsValue[1] = -1;
    result->originalHitPointsValue[2] = -1;
    result->originalHitPointsValue[3] = -1;
    result->originalHitPointsValue[4] = -1;
}
