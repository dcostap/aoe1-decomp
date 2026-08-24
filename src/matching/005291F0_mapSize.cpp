#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2680];
    int mapSize_;

    int mapSize() const;
};
#endif
int TRIBE_Game::mapSize() const { return this->tribe_game_options.mapSizeValue; }
