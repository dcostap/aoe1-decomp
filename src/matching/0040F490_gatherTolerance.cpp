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
    AIPlayPhaseTrigger* trigger(int index);
};

class AIPlay {
public:
    AIPlayPhase* phase(int index);
    int gatherTolerance(int, int param_2);
};

int AIPlay::gatherTolerance(int, int param_2) {
    AIPlayPhase* phase_0 = phase(param_2);
    if (phase_0 == 0) {
        return 2;
    }

    int i = 0;
    while (i < 3) {
        AIPlayPhaseTrigger* trigger_0 = phase_0->trigger(i);
        if (trigger_0 != 0 && trigger_0->typeValue == 1) {
            return trigger_0->value1Value;
        }
        i++;
    }

    return 2;
}
