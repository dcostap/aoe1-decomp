#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4496];
    int randomStartValue_;

    int randomStartValue() const;
};
#endif
int TRIBE_Game::randomStartValue() { return this->random_start_value; }
