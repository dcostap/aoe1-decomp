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

    unsigned char convertToIntType(char* text);
    AIPlayPhaseTrigger(char* type, int value1, int value2, unsigned char phase, unsigned char nextPhase, int randomness);
};

AIPlayPhaseTrigger::AIPlayPhaseTrigger(char* type, int value1, int value2, unsigned char phase, unsigned char nextPhase, int randomness) {
    typeValue = convertToIntType(type);
    value1Value = value1;
    value2Value = value2;
    phaseValue = phase;
    nextPhaseValue = nextPhase;
    randomnessValue = randomness;
}
