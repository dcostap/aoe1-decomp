// VA: 0040F9B0 AIPlay::groupGivenCommandOnPhase (132 bytes)
// Using union to force stack spill + dword reload

struct AIPlayPhaseCommand {
    unsigned char field_0;
    unsigned char field_1;
    char gap_02[2];
    int field_4;
    int field_8;
    int field_C;
};

struct AIPlayPhaseTrigger {
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
    AIPlayPhaseCommand commands[5];
    AIPlayPhaseTrigger triggers[3];
    AIPlayPhaseCommand *command(int index);
};

class AIPlay {
public:
    char pad_00[0x90];
    AIPlayPhase phases[10];
    int groupGivenCommandOnPhase(int groupValue, int typeValue, int phaseIndex);
};

int AIPlay::groupGivenCommandOnPhase(int groupValue, int typeValue, int phaseIndex) {
    if (groupValue < 0 || groupValue >= 5) return -1;
    if (phaseIndex < 0 || phaseIndex >= 10) return -1;

    AIPlayPhase* phase = &this->phases[phaseIndex];
    for (int cmdIdx = 0; cmdIdx < 5; cmdIdx++) {
        AIPlayPhaseCommand* cmd = phase->command(cmdIdx);
        if ((unsigned int)cmd->field_0 == (unsigned int)groupValue) {
            AIPlayPhaseCommand* cmd2 = phase->command(cmdIdx);
            // Force dword read: write byte, read dword
            unsigned char uc = cmd2->field_1;
            volatile unsigned int dummy;
            *(unsigned char*)&dummy = uc;
            unsigned int typeVal = dummy;
            if (typeVal == (unsigned int)typeValue) {
                return cmdIdx;
            }
        }
    }
    return -1;
}

AIPlayPhaseCommand *AIPlayPhase::command(int index) {
    if (index < 0 || index >= 5) return 0;
    return &this->commands[index];
}
