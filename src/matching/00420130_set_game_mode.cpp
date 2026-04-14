class RGE_Base_Game {
public:
    char gap_0[0x1B4];
    int field_1B4;
    int field_1B8;
    void set_game_mode(int a, int b);
};

void RGE_Base_Game::set_game_mode(int a, int b) {
    this->field_1B4 = a;
    this->field_1B8 = b;
}
