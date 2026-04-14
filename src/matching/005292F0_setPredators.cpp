class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2692];
    int predators_;

    void setPredators(int);
};
void TRIBE_Game::setPredators(int val) { this->predators_ = val; }
