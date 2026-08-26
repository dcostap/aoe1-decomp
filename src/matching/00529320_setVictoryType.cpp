#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum VictoryType { VictoryType_Unknown = 0 };
    char gap_04[0xA88];
    int victoryType_;
    int victoryAmount_;

    void setVictoryType(VictoryType, int);
};
#endif
void TRIBE_Game::setVictoryType(TRIBE_Game::VictoryType type, int amount) {
    this->tribe_game_options.victoryTypeValue = type;
    this->tribe_game_options.victoryAmountValue = amount;
}
