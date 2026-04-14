class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2684];
    int mapType_;

    int mapType() const;
};
int TRIBE_Game::mapType() const { return this->mapType_; }
