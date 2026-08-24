#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2780];
    int startingAge_;

    int startingAge() const;
};
#endif
int TRIBE_Game::startingAge() const { return this->tribe_game_options.startingAgeValue; }
