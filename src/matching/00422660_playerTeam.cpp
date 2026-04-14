class RGE_Base_Game {
public:
    char gap_0[0x994];
    unsigned char arr_[1];
    int playerTeam(int i);
};

int RGE_Base_Game::playerTeam(int i) {
    return this->arr_[i];
}
