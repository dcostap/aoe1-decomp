// tried the raw-storage layout so the ctor calls can happen after the scalar stores
// tried direct member-array construction, then raw helper calls, then a tweaked tail fill loop
// remaining mismatch is localized to the final target-array fill sequence (first mismatch at byte 93)
class AIPlayGroup {
public:
    char data[0x0C];
    void init(void);
};

class AIPlayPhase {
public:
    char data[0x8C];
    void init(void);
};

class AIPlay {
public:
    char nameValue[65];
    unsigned char minimumNumberUnitsValue;
    unsigned char maximumNumberUnitsValue;
    unsigned char typeValue;
    unsigned char targetTypeValue[5];
    unsigned char targetCharacteristicValue[5];
    unsigned char powerValue;
    unsigned char overflowValue;
    unsigned char intelligenceValue;
    unsigned char deathPercentageValue;
    unsigned char numberGroupsValue;
    char groups[0x3C];
    char pad_8F[1];
    char phases[0x578];
    AIPlay();
};

AIPlay::AIPlay() {
    this->minimumNumberUnitsValue = 1;
    this->typeValue = 1;
    this->overflowValue = 1;
    this->maximumNumberUnitsValue = 0xFF;
    this->powerValue = 0;
    this->intelligenceValue = 0x32;
    this->deathPercentageValue = 0x32;

    AIPlayGroup* group = (AIPlayGroup*)&this->groups[0];
    int i = 0;
    while (i < 5) {
        group->init();
        group = (AIPlayGroup*)((char*)group + 0x0C);
        i++;
    }

    AIPlayPhase* phase = (AIPlayPhase*)&this->phases[0];
    i = 0;
    while (i < 10) {
        phase->init();
        phase = (AIPlayPhase*)((char*)phase + 0x8C);
        i++;
    }

    int ecx = 0xFFFFFFB7;
    unsigned char* p = &this->targetCharacteristicValue[0];
    int edx;
    ecx -= (int)this;
    do {
        p[-5] = 5;
        *p = 5;
        p++;
        edx = ecx + (int)p;
    } while (edx < 5);
}
