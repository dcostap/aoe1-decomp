int RGE_Base_Game::playerHasCD(int i) {
    return this->cdAndVersion_[i] & 1;
}
