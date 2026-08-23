#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseTrigger {
public:
    char typeValue;
    char gap_01[3];
    int value1Value;
    int value2Value;
    char phaseValue;
    char nextPhaseValue;

    AIPlayPhaseTrigger();
};
#endif

AIPlayPhaseTrigger::AIPlayPhaseTrigger() {
    typeValue = 0;
    value1Value = -1;
    value2Value = -1;
    phaseValue = 0;
    nextPhaseValue = 0;
}
