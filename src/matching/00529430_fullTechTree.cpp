#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAD5];
    unsigned char field_AD9;
    int fullTechTree();
};
#endif

int TRIBE_Game::fullTechTree() { return this->tribe_game_options.fullTechTreeValue; }
