class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAD2];
    unsigned char field_AD6;
    int allowTrading();
};

int TRIBE_Game::allowTrading() { return this->field_AD6; }
