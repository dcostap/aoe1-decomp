#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4496];
    int randomStartValue_;

    void setRandomStartValue(int);
};
#endif
void TRIBE_Game::setRandomStartValue(int val) { this->random_start_value = val; }
