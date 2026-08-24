#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2688];
    int animals_;

    void setAnimals(int);
};
#endif
void TRIBE_Game::setAnimals(int val) { this->tribe_game_options.animalsValue = val; }
