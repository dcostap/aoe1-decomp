class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[2785];
    unsigned char deathMatch_;

    unsigned char deathMatch() const;
};
unsigned char TRIBE_Game::deathMatch() const { return this->deathMatch_; }
