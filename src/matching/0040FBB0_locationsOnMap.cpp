// VA: 0040FBB0 AIPlay::locationsOnMap (122 bytes)
//
// Attempt log:
// - Initial scratch used outer do/while with inner do/while. Core loop matched, but VC5 placed the success epilogue
//   after an inverted `jge; jmp outer` pair, shifting the failure epilogue and branch displacements (edit diff 30).
// - SpruceGlow tries 1-3: explicit success return at bottom and positive/nested bounds forms did not change the
//   epilogue placement. Try 4 for-loops changed early loop setup and was worse.
// - SpruceGlow try 5 MATCH: use while-loops for both outer phase scan and inner command scan. VC5 rotates the loops
//   into the original layout: failure epilogue remains at the end, success epilogue before it, and the outer loop uses
//   `jl` backedge directly instead of `jge` + `jmp`.
// Result: MATCH locally with `python tools/check_function.py --va 0040FBB0`.

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

int AIPlay::locationsOnMap(int x1, int y1, int x2, int y2) {
    int phaseIdx = 0;
    AIPlayPhase *phase = &this->phases[0];

    while (phaseIdx < 10) {
        int cmdIdx = 0;
        while (cmdIdx < 5) {
            AIPlayPhaseCommand *cmd = phase->command(cmdIdx);
            if (cmd->field_1 == 1) {
                int px = cmd->field_4 + x1;
                int py = cmd->field_8 + y1;
                if (px < 0 || py < 0 || px >= x2 || py >= y2) {
                    return 0;
                }
            }
            cmdIdx++;
        }
        phase++;
        phaseIdx++;
    }
    return 1;
}
