struct AIPlay {
    char data[0x608];
};

class AIPlayBook {
public:
    int vfptr;
    int numberPlays;
    char gap_08[0x44];
    AIPlay* plays;

    AIPlay* play(int index);
};

AIPlay* AIPlayBook::play(int index) {
    if (this->plays != 0 && index >= 0 && index < this->numberPlays)
        return this->plays + index;
    return 0;
}
