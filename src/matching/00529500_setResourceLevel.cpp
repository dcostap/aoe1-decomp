#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2776];
    int resourceLevel_;

    void setResourceLevel(int);
};
#endif
void TRIBE_Game::setResourceLevel(int val) { this->tribe_game_options.resourceLevelValue = val; }
