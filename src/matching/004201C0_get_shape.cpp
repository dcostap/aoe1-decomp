class RGE_Base_Game {
public:
    char gap_0[0x5C];
    void **arr_ptr;
    void *get_shape(int i);
};

void *RGE_Base_Game::get_shape(int i) {
    if (!this->arr_ptr) return 0;
    return this->arr_ptr[i];
}
