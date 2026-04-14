class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2696];
    int victoryType_;

    int victoryType() const;
};
int TRIBE_Game::victoryType() const { return this->victoryType_; }
