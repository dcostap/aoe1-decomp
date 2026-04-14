class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2680];
    int mapSize_;

    int mapSize() const;
};
int TRIBE_Game::mapSize() const { return this->mapSize_; }
