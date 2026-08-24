#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2692];
    int predators_;

    void setPredators(int);
};
#endif
void TRIBE_Game::setPredators(int val) { this->tribe_game_options.predatorsValue = val; }
