// 0040F2E0 AIPlay constructor
// The scalar prefix is an inline subobject so its initialization precedes the
// typed group and phase member constructors, as shown by the original calls.

class AIPlayGroup {
public:
    char data[0x0C];
    AIPlayGroup();
};

class AIPlayPhase {
public:
    char data[0x8C];
    AIPlayPhase();
};

class AIPlayHeader {
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

    AIPlayHeader() {
        this->minimumNumberUnitsValue = 1;
        this->typeValue = 1;
        this->overflowValue = 1;
        this->maximumNumberUnitsValue = 0xFF;
        this->powerValue = 0;
        this->intelligenceValue = 0x32;
        this->deathPercentageValue = 0x32;
    }
};

class AIPlay {
public:
    AIPlayHeader header;
    AIPlayGroup groups[5];
    char pad_8F[1];
    AIPlayPhase phases[10];
    AIPlay();
};

AIPlay::AIPlay() {
    for (int j = 0; j < 5; j++) {
        this->header.targetTypeValue[j] = 5;
        this->header.targetCharacteristicValue[j] = 5;
    }
}
