#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2784];
    char startingUnits_;

    void setStartingUnits(int);
};
#endif
void TRIBE_Game::setStartingUnits(int val) { this->tribe_game_options.startingUnitsValue = (unsigned char)val; }
