class TRIBE_Game {
public:
    char gap_0[0xAC4];
    unsigned char arr_[1];
    int playerColor(int i);
};

int TRIBE_Game::playerColor(int i) {
    return this->arr_[i];
}
