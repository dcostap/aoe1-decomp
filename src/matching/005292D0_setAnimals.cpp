class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2688];
    int animals_;

    void setAnimals(int);
};
void TRIBE_Game::setAnimals(int val) { this->animals_ = val; }
