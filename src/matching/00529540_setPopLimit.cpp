#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2786];
    unsigned char popLimit_;

    void setPopLimit(unsigned char);
};
#endif
void TRIBE_Game::setPopLimit(unsigned char val) { this->tribe_game_options.popLimitValue = val; }
