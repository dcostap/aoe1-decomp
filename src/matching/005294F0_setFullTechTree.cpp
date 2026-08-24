#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2773];
    char fullTechTree_;

    void setFullTechTree(int);
};
#endif
void TRIBE_Game::setFullTechTree(int val) { this->tribe_game_options.fullTechTreeValue = (unsigned char)val; }
