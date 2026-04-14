class TRIBE_Game {
public:
    char gap_0[0xAC4];
    unsigned char arr_[1];
    void setPlayerColor(int i, unsigned char v);
};

void TRIBE_Game::setPlayerColor(int i, unsigned char v) {
    this->arr_[i] = v;
}
