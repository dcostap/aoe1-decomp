#ifndef AIPBOOK_CANONICAL_TU
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
};

class AIPlayPhase {
public:
    char commands[0x50];
    AIPlayPhaseTrigger triggers[3];
    int addTrigger(AIPlayPhaseTrigger& trigger);
};
#endif

int AIPlayPhase::addTrigger(AIPlayPhaseTrigger& trigger) {
    int i = 0;
    while (i < 3) {
        if (this->triggers[i].typeValue == 0) {
            this->triggers[i].typeValue = trigger.typeValue;
            this->triggers[i].value1Value = trigger.value1Value;
            this->triggers[i].value2Value = trigger.value2Value;
            this->triggers[i].phaseValue = trigger.phaseValue;
            this->triggers[i].nextPhaseValue = trigger.nextPhaseValue;
            this->triggers[i].randomnessValue = trigger.randomnessValue;
            return 1;
        }
        i++;
    }
    return 0;
}
