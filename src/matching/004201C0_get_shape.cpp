void* RGE_Base_Game::get_shape(int i) {
    if (!this->shape_arr_ptr) return 0;
    return this->shape_arr_ptr[i];
}
