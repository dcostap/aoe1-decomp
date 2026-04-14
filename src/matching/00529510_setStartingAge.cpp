class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2780];
    int startingAge_;

    void setStartingAge(int);
};
void TRIBE_Game::setStartingAge(int val) { this->startingAge_ = val; }
