class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2772];
    char randomizePositions_;

    void setRandomizePositions(int);
};
void TRIBE_Game::setRandomizePositions(int val) { this->randomizePositions_ = val; }
