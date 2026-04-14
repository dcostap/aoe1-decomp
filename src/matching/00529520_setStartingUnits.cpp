class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2784];
    char startingUnits_;

    void setStartingUnits(int);
};
void TRIBE_Game::setStartingUnits(int val) { this->startingUnits_ = val; }
