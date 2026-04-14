class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_04[4492];
    unsigned char quickStartGame_;

    void setQuickStartGame(unsigned char);
};
void TRIBE_Game::setQuickStartGame(unsigned char val) { this->quickStartGame_ = val; }
