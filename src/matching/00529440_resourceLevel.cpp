#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum ResourceLevel { ResourceLevel_Unknown = 0 };
    char gap_04[2776];
    int resourceLevel_;

    ResourceLevel resourceLevel();
};
#endif
TRIBE_Game::ResourceLevel TRIBE_Game::resourceLevel() {
    return (TRIBE_Game::ResourceLevel)this->tribe_game_options.resourceLevelValue;
}
