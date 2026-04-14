class RGE_Base_Game {
public:
    char gap_0[0x994];
    unsigned char arr_[1];
    void setPlayerTeam(int i, unsigned char v);
};

void RGE_Base_Game::setPlayerTeam(int i, unsigned char v) {
    this->arr_[i] = v;
}
