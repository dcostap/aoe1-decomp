class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2785];
    unsigned char deathMatch_;

    void setDeathMatch(unsigned char);
};
void TRIBE_Game::setDeathMatch(unsigned char val) { this->deathMatch_ = val; }
