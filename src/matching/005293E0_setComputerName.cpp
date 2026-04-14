class TRIBE_Game {
public:
    char gap_0[0xACD];
    unsigned char arr_[1];
    void setComputerName(int i, unsigned char v);
};

void TRIBE_Game::setComputerName(int i, unsigned char v) {
    this->arr_[i] = v;
}
