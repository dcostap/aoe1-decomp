#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2776];
    int resourceLevel_;

    int resourceLevel() const;
};
#endif
int TRIBE_Game::resourceLevel() const { return this->tribe_game_options.resourceLevelValue; }
