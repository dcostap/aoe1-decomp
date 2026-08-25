unsigned long RGE_Base_Game::get_accum_time(int i) {
    return *(unsigned long *)((char *)&this->data_ + (i << 5));
}
