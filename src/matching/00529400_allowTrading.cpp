#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAD2];
    unsigned char field_AD6;
    int allowTrading();
};
#endif

int TRIBE_Game::allowTrading() { return this->tribe_game_options.allowTradingValue; }
