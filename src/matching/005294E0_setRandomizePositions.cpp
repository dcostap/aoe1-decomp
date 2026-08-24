#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2772];
    char randomizePositions_;

    void setRandomizePositions(int);
};
#endif
void TRIBE_Game::setRandomizePositions(int val) { this->tribe_game_options.randomizePositionsValue = (unsigned char)val; }
