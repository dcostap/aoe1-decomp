#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum MapSize { MapSize_Unknown = 0 };
    char gap_04[2680];
    int mapSize_;

    MapSize mapSize() const;
};
#endif
TRIBE_Game::MapSize TRIBE_Game::mapSize() const {
    return (TRIBE_Game::MapSize)this->tribe_game_options.mapSizeValue;
}
