class RGE_Base_Game {
public:
    char gap_0[0x1558];
    int field_1558;
    int IsPaused();
};

int RGE_Base_Game::IsPaused() {
    return this->field_1558 == 4;
}
