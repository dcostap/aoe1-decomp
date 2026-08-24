#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2696];
    int victoryType_;

    int victoryType() const;
};
#endif
int TRIBE_Game::victoryType() const { return this->tribe_game_options.victoryTypeValue; }
