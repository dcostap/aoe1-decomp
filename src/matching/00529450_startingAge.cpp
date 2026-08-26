#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum Age { Age_Unknown = 0 };
    char gap_04[2780];
    int startingAge_;

    Age startingAge();
};
#endif
TRIBE_Game::Age TRIBE_Game::startingAge() {
    return (TRIBE_Game::Age)this->tribe_game_options.startingAgeValue;
}
