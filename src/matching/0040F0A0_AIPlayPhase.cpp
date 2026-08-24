#ifndef AIPBOOK_CANONICAL_TU
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
#endif

AIPlayPhase::AIPlayPhase() {
    initialize();
}
