class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2770];
    char allowTrading_;

    void setAllowTrading(int);
};
void TRIBE_Game::setAllowTrading(int val) { this->allowTrading_ = val; }
