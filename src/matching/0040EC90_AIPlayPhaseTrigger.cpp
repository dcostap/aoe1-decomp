// 0040EC90 AIPlayPhaseTrigger(unsigned char, int, int, unsigned char,
//                             unsigned char, int)

AIPlayPhaseTrigger::AIPlayPhaseTrigger(unsigned char type,
                                       int value1,
                                       int value2,
                                       unsigned char phase,
                                       unsigned char nextPhase,
                                       int randomness) {
    this->typeValue = type;
    this->value1Value = value1;
    this->value2Value = value2;
    this->phaseValue = phase;
    this->nextPhaseValue = nextPhase;
    this->randomnessValue = randomness;
}
