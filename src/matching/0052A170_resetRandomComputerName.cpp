class TRIBE_Game {
public:
    char gap_00[0x1198];
    unsigned long computerNameUsed[0x28];

    void resetRandomComputerName();
};

void TRIBE_Game::resetRandomComputerName() {
    int i;

    for (i = 0; i < 0x28; i++) {
        this->computerNameUsed[i] = 0;
    }
}
