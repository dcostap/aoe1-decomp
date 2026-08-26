#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum VictoryType { VictoryType_Unknown = 0 };
    char gap_04[2696];
    int victoryType_;

    VictoryType victoryType() const;
};
#endif
TRIBE_Game::VictoryType TRIBE_Game::victoryType() const {
    return (TRIBE_Game::VictoryType)this->tribe_game_options.victoryTypeValue;
}
