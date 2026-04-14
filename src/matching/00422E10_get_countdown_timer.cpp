class RGE_Base_Game {
public:
    char gap_0[0x9D8];
    int arr_[1];
    void get_countdown_timer(int index, int *out);
};

void RGE_Base_Game::get_countdown_timer(int index, int *out) {
    *out = this->arr_[index];
}
