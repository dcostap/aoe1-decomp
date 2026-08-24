#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2780];
    int startingAge_;

    void setStartingAge(int);
};
#endif
void TRIBE_Game::setStartingAge(int val) { this->tribe_game_options.startingAgeValue = val; }
