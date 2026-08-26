#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_0[0xACD];
    unsigned char arr_[1];
    void setComputerName(int i, int v);
};
#endif

void TRIBE_Game::setComputerName(int i, int v) {
    this->tribe_game_options.computerNameValue[i] = v;
}
