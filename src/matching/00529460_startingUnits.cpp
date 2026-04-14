class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAE0];
    unsigned char field_AE4;
    int startingUnits();
};

int TRIBE_Game::startingUnits() { return this->field_AE4; }
