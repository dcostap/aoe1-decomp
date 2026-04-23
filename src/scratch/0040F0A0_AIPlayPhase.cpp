class AIPlayPhaseCommand {
public:
    unsigned char field_0;
    unsigned char field_1;
    int field_4;
    int field_8;
    int field_C;
    AIPlayPhaseCommand();
};

class AIPlayPhaseTrigger {
public:
    unsigned char typeValue;
    char gap_01[3];
    int value1Value;
    int value2Value;
    unsigned char phaseValue;
    unsigned char nextPhaseValue;
    char gap_0E[2];
    int randomnessValue;
    AIPlayPhaseTrigger();
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand commands[5];
    AIPlayPhaseTrigger triggers[3];

    AIPlayPhase();
    void initialize();
};

AIPlayPhase::AIPlayPhase() {
    initialize();
}

void AIPlayPhase::initialize() {
    unsigned char* p = &this->commands[0].field_1;
    int i = 5;
    do {
        *p = 0;
        p += 0x10;
        i--;
    } while (i != 0);

    p = &this->triggers[0].typeValue;
    i = 3;
    do {
        *p = 0;
        p += 0x14;
        i--;
    } while (i != 0);
}
