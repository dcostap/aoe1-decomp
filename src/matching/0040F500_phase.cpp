struct AIPlayPhase {
    char data[0x8C];
};

class AIPlayBook {
public:
    int vfptr;
    int numberPlays;
    char gap_08[0x88];
    AIPlayPhase phases[10];

    AIPlayPhase* phase(int index);
};

AIPlayPhase* AIPlayBook::phase(int index) {
    if (index >= 0 && index < 10)
        return this->phases + index;
    return 0;
}
