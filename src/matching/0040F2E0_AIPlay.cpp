// 0040F2E0 AIPlay constructor
// Diff: tail loop uses lea (edx=ecx+eax) vs add+inc approach
// Trying: explicit for-loop with array indexing

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

    // Use explicit for loop with member array access
    for (int j = 0; j < 5; j++) {
        this->targetTypeValue[j] = 5;
        this->targetCharacteristicValue[j] = 5;
    }
}
