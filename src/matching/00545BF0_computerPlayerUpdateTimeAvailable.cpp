class TRIBE_Game {
public:
    char gap_0[0xF8];
    unsigned int field_F8;
    int computerPlayerUpdateTimeAvailable();
};
int TRIBE_Game::computerPlayerUpdateTimeAvailable() {
    return 0 < this->field_F8;
}
