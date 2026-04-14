class RGE_Base_Game {
public:
    char gap_0[0x98A];
    unsigned char arr_[1];
    void setPlayerCDAndVersion(int i, unsigned char v);
};

void RGE_Base_Game::setPlayerCDAndVersion(int i, unsigned char v) {
    this->arr_[i] = v;
}
