#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2700];
    int victoryAmount_;

    int victoryAmount() const;
};
#endif
int TRIBE_Game::victoryAmount() const { return this->tribe_game_options.victoryAmountValue; }
