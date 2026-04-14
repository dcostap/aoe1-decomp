class RGE_Base_Game {
public:
    char gap_0[0x9B0];
    int arr_[1];
    void setPlayerID(int i, int v);
};

void RGE_Base_Game::setPlayerID(int i, int v) {
    this->arr_[i] = v;
}
