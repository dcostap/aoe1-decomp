#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_0[0xAC4];
    unsigned char arr_[1];
    int playerColor(int i);
};
#endif

int TRIBE_Game::playerColor(int i) {
    return this->tribe_game_options.playerColorValue[i];
}
