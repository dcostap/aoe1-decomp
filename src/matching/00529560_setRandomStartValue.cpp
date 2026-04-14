class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4496];
    int randomStartValue_;

    void setRandomStartValue(int);
};
void TRIBE_Game::setRandomStartValue(int val) { this->randomStartValue_ = val; }
