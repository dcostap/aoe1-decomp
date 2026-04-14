class RGE_Base_Game {
public:
    char gap_0[0x98A];
    unsigned char arr_[1];
    int playerVersion(int i);
};

int RGE_Base_Game::playerVersion(int i) {
    return this->arr_[i] >> 1;
}
