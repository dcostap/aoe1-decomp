#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2770];
    char allowTrading_;

    void setAllowTrading(int);
};
#endif
void TRIBE_Game::setAllowTrading(int val) { this->tribe_game_options.allowTradingValue = (unsigned char)val; }
