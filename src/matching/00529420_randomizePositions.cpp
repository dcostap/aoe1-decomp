#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAD4];
    unsigned char field_AD8;
    int randomizePositions();
};
#endif

int TRIBE_Game::randomizePositions() { return this->tribe_game_options.randomizePositionsValue; }
