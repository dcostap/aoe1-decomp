// VA: 0040F9B0 AIPlay::groupGivenCommandOnPhase
// PDB: aipbook.cpp lines 645-658 (132 bytes, 58 asm lines)
// Default flags. No inline asm/hacks.

// AIPlayPhase::command() defined elsewhere (0040F110 already matching)

class AIPlayPhase_Entry_0040F110 {
public:
    char data[16];
};

class AIPlayPhase {
public:
    AIPlayPhase_Entry_0040F110 entries_[5];
    char triggers_area_[0x8C - 0x50];

    AIPlayPhase_Entry_0040F110* command(int index);
};

class AIPlay {
public:
    char pad_00[0x90];
    AIPlayPhase phases[10];

    int groupGivenCommandOnPhase(int groupValue, int typeValue, int phaseIndex);
};

int AIPlay::groupGivenCommandOnPhase(int groupValue, int typeValue, int phaseIndex)
{
    if (groupValue < 0 || groupValue >= 5)
        return -1;
    if (phaseIndex < 0 || phaseIndex >= 10)
        return -1;

    AIPlayPhase* phase = &this->phases[phaseIndex];
    for (int i = 0; i < 5; i++) {
        AIPlayPhase_Entry_0040F110* cmd = phase->command(i);
        if ((unsigned int)cmd->data[0] == (unsigned int)groupValue) {
            AIPlayPhase_Entry_0040F110* cmd2 = phase->command(i);
            int t = (unsigned char)cmd2->data[1];
            if (t == typeValue) {
                return i;
            }
        }
    }
    return -1;
}
