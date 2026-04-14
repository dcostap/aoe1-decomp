class RGE_Base_Game {
public:
    char gap_0[0x9D8];
    int arr_[1];
    void reset_countdown_timer(int i);
};

void RGE_Base_Game::reset_countdown_timer(int i) {
    this->arr_[i] = -1;
}
