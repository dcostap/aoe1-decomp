class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2773];
    char fullTechTree_;

    void setFullTechTree(int);
};
void TRIBE_Game::setFullTechTree(int val) { this->fullTechTree_ = val; }
