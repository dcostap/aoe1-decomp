#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2785];
    unsigned char deathMatch_;

    void setDeathMatch(unsigned char);
};
#endif
void TRIBE_Game::setDeathMatch(unsigned char val) { this->tribe_game_options.deathMatchValue = val; }
