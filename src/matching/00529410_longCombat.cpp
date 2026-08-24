#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAD3];
    unsigned char field_AD7;
    int longCombat();
};
#endif

int TRIBE_Game::longCombat() { return this->tribe_game_options.longCombatValue; }
