TDigital* RGE_Base_Game::get_sound(int i) {
    if (!this->sounds) return 0;
    return this->sounds[i];
}
