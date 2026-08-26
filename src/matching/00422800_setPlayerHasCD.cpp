void RGE_Base_Game::setPlayerHasCD(int player, int hasCD) {
    unsigned char val = this->cdAndVersion_[player];
    val = (val & 0xFE) | hasCD;
    this->cdAndVersion_[player] = val;
}
