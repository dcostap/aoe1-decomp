// VA: 0040FBB0 AIPlay::locationsOnMap (122 bytes)
// Nested loop over phases and commands, checking type==1 bounds on map
// sizeof(AIPlayPhase)=0x8C: 5 commands * 0x10 + 3 triggers * 0x14

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
    int locationsOnMap(int x1, int y1, int x2, int y2);
};

AIPlayPhaseCommand *AIPlayPhase::command(int index) {
    if (index < 0 || index >= 5) return 0;
    return &this->commands[index];
}

int AIPlay::locationsOnMap(int x1, int y1, int x2, int y2) {
    AIPlayPhase *phase = &this->phases[0];
    int phaseIdx = 0;

    do {
        int cmdIdx = 0;
        do {
            AIPlayPhaseCommand *cmd = phase->command(cmdIdx);
            if (cmd->field_1 == 1) {
                int px = cmd->field_4 + x1;
                int py = cmd->field_8 + y1;
                if (px < 0 || py < 0 || x2 <= px || y2 <= py) {
                    return 0;
                }
            }
            cmdIdx++;
        } while (cmdIdx < 5);

        phase++;
        phaseIdx++;
        if (phaseIdx > 9) {
            return 1;
        }
    } while (1);
}
