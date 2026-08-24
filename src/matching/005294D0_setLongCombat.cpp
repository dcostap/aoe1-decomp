#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2771];
    char longCombat_;

    void setLongCombat(int);
};
#endif
void TRIBE_Game::setLongCombat(int val) { this->tribe_game_options.longCombatValue = (unsigned char)val; }
