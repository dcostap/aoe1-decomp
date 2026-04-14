class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2700];
    int victoryAmount_;

    int victoryAmount() const;
};
int TRIBE_Game::victoryAmount() const { return this->victoryAmount_; }
