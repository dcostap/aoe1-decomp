class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2776];
    int resourceLevel_;

    int resourceLevel() const;
};
int TRIBE_Game::resourceLevel() const { return this->resourceLevel_; }
