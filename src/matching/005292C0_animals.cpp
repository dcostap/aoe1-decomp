class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2688];
    int animals_;

    int animals() const;
};
int TRIBE_Game::animals() const { return this->animals_; }
