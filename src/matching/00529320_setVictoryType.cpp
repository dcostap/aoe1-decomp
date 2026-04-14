class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[0xA88];
    int victoryType_;
    int victoryAmount_;

    void setVictoryType(int, int);
};
void TRIBE_Game::setVictoryType(int type, int amount) {
    this->victoryType_ = type;
    this->victoryAmount_ = amount;
}
