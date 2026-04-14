class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xAD5];
    unsigned char field_AD9;
    int fullTechTree();
};

int TRIBE_Game::fullTechTree() { return this->field_AD9; }
