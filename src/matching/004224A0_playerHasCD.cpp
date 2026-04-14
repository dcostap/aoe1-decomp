class RGE_Base_Game {
public:
    char gap_0[0x98A];
    unsigned char arr_[1];
    int playerHasCD(int i);
};

int RGE_Base_Game::playerHasCD(int i) {
    return this->arr_[i] & 0x1;
}
