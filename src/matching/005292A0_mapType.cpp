#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum MapType { MapType_Unknown = 0 };
    char gap_04[2684];
    int mapType_;

    MapType mapType() const;
};
#endif
TRIBE_Game::MapType TRIBE_Game::mapType() const {
    return (TRIBE_Game::MapType)this->tribe_game_options.mapTypeValue;
}
