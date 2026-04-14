class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2684];
    int mapType_;

    void setMapType(int);
};
void TRIBE_Game::setMapType(int val) { this->mapType_ = val; }
