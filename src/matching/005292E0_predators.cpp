#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2692];
    int predators_;

    int predators() const;
};
#endif
int TRIBE_Game::predators() const { return this->tribe_game_options.predatorsValue; }
