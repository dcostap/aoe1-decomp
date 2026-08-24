#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2688];
    int animals_;

    int animals() const;
};
#endif
int TRIBE_Game::animals() const { return this->tribe_game_options.animalsValue; }
