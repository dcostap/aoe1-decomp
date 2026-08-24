#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_0[0xACD];
    unsigned char arr_[1];
    int computerName(int i);
};
#endif

int TRIBE_Game::computerName(int i) {
    return this->tribe_game_options.computerNameValue[i];
}
