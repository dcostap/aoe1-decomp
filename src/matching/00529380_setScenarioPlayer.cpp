class TRIBE_Game {
public:
    char gap_0[0xAA0];
    int arr_[1];
    void setScenarioPlayer(int i, int v);
};

void TRIBE_Game::setScenarioPlayer(int i, int v) {
    this->arr_[i] = v;
}
