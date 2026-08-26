TShape* RGE_Base_Game::get_shape(int i) {
    if (!this->shapes) return 0;
    return this->shapes[i];
}
