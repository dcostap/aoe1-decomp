#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum Age { Age_Unknown = 0 };
    char gap_04[2780];
    int startingAge_;

    void setStartingAge(Age);
};
#endif
void TRIBE_Game::setStartingAge(TRIBE_Game::Age val) {
    this->tribe_game_options.startingAgeValue = (int)val;
}
