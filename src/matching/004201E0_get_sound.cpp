class RGE_Base_Game {
public:
    char gap_0[0x6C];
    void **arr_ptr;
    void *get_sound(int i);
};

void *RGE_Base_Game::get_sound(int i) {
    if (!this->arr_ptr) return 0;
    return this->arr_ptr[i];
}
