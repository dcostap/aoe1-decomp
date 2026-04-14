class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2776];
    int resourceLevel_;

    void setResourceLevel(int);
};
void TRIBE_Game::setResourceLevel(int val) { this->resourceLevel_ = val; }
