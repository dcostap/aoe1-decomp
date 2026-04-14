class TRIBE_Game {
public:
    char gap_0[0xA94];
    unsigned char arr_[1];
    int civilization(int i);
};

int TRIBE_Game::civilization(int i) {
    return this->arr_[i];
}
