#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2684];
    int mapType_;

    int mapType() const;
};
#endif
int TRIBE_Game::mapType() const { return this->tribe_game_options.mapTypeValue; }
