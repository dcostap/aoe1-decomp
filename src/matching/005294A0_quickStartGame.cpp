#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4492];
    unsigned char quickStartGame_;

    unsigned char quickStartGame();
};
#endif
unsigned char TRIBE_Game::quickStartGame() { return this->quick_start_game; }
