#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAE0];
    unsigned char field_AE4;
    int startingUnits();
};
#endif

int TRIBE_Game::startingUnits() { return this->tribe_game_options.startingUnitsValue; }
