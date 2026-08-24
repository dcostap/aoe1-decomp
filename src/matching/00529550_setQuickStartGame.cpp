#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4492];
    unsigned char quickStartGame_;

    void setQuickStartGame(unsigned char);
};
#endif
void TRIBE_Game::setQuickStartGame(unsigned char val) { this->quick_start_game = val; }
