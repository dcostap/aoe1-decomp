#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    enum MapType { MapType_Unknown = 0 };
    char gap_04[2684];
    int mapType_;

    void setMapType(MapType);
};
#endif
void TRIBE_Game::setMapType(TRIBE_Game::MapType val) {
    this->tribe_game_options.mapTypeValue = (int)val;
}
