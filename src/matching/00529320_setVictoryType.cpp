#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[0xA88];
    int victoryType_;
    int victoryAmount_;

    void setVictoryType(int, int);
};
#endif
void TRIBE_Game::setVictoryType(int type, int amount) {
    this->tribe_game_options.victoryTypeValue = type;
    this->tribe_game_options.victoryAmountValue = amount;
}
