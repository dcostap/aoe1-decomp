#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2785];
    unsigned char deathMatch_;

    unsigned char deathMatch();
};
#endif
unsigned char TRIBE_Game::deathMatch() { return this->tribe_game_options.deathMatchValue; }
