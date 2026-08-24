#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_00[0x1198];
    unsigned long computerNameUsed[0x28];

    void resetRandomComputerName();
};
#endif

void TRIBE_Game::resetRandomComputerName() {
    int i;

    for (i = 0; i < 0x28; i++) {
        ((unsigned long*)this->computerNameUsed)[i] = 0;
    }
}
