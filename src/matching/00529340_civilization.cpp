#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_0[0xA94];
    unsigned char arr_[1];
    int civilization(int i);
};
#endif

int TRIBE_Game::civilization(int i) {
    return this->tribe_game_options.civilizationValue[i];
}
