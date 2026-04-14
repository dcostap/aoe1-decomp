class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    char gap_0[0xA9C];
    int array_AA0[1];
    int scenarioPlayer(int idx);
};

int TRIBE_Game::scenarioPlayer(int idx) { return this->array_AA0[idx]; }
