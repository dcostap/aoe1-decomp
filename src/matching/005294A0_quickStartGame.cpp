class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4492];
    unsigned char quickStartGame_;

    unsigned char quickStartGame() const;
};
unsigned char TRIBE_Game::quickStartGame() const { return this->quickStartGame_; }
