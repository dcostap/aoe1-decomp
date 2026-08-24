#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2684];
    int mapType_;

    void setMapType(int);
};
#endif
void TRIBE_Game::setMapType(int val) { this->tribe_game_options.mapTypeValue = val; }
