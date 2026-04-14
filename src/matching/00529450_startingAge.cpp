class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2780];
    int startingAge_;

    int startingAge() const;
};
int TRIBE_Game::startingAge() const { return this->startingAge_; }
