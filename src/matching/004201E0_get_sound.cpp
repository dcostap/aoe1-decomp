void* RGE_Base_Game::get_sound(int i) {
    if (!this->sound_arr_ptr) return 0;
    return this->sound_arr_ptr[i];
}
