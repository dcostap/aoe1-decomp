// tried a direct nested scan, then a more decompiler-shaped outer/inner loop split
// kept the command/compare semantics, but VC5 still drifts in the prolog register assignment
// current mismatch starts at the entry setup, before the phase/command loop body
// leaving this in scratch as a known near-match after several source-shape probes
class AIPlayPhase_Entry_0040F110 {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char pad_02[2];
    int value1Value;
    int value2Value;
    int value3Value;
};

class AIPlayPhase {
public:
    AIPlayPhase_Entry_0040F110 *command(int index) const;
};

class AIPlay {
public:
    char pad_00[0x90];
    AIPlayPhase phases[10];
    int locationsOnMap(int x1, int y1, int x2, int y2);
};

int AIPlay::locationsOnMap(int x1, int y1, int x2, int y2) {
    int phaseCount = 0;
    int commandCount;
    AIPlayPhase* phase = &this->phases[0];

    do {
        commandCount = 0;
        do {
            AIPlayPhase_Entry_0040F110* command = phase->command(commandCount);
            if (command->typeValue == 1) {
                int px = command->value1Value + x1;
                int py = command->value2Value + y1;
                if (px < 0 || py < 0 || x2 <= px || y2 <= py) {
                    return 0;
                }
            }
            commandCount++;
        } while (commandCount < 5);
        phase++;
        phaseCount++;
        if (phaseCount > 9) {
            return 1;
        }
    } while (1);
}
