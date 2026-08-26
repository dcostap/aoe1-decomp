void RGE_Base_Game::setPlayerVersion(int player, unsigned char version) {
    unsigned char v = version << 1;
    unsigned char old = this->cdAndVersion_[player];
    v = v | (old & 1);
    this->cdAndVersion_[player] = v;
}
