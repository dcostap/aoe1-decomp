#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum ResourceLevel { ResourceLevel_Unknown = 0 };
    char gap_04[2776];
    int resourceLevel_;

    void setResourceLevel(ResourceLevel);
};
#endif
void TRIBE_Game::setResourceLevel(TRIBE_Game::ResourceLevel val) {
    this->tribe_game_options.resourceLevelValue = (int)val;
}
