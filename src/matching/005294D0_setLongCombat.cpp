class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2771];
    char longCombat_;

    void setLongCombat(int);
};
void TRIBE_Game::setLongCombat(int val) { this->longCombat_ = val; }
