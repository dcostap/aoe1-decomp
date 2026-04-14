class T_Scenario {
public:
    char gap_0[0x4BA8];
    int arr_[1];
    void SetPlayerAlliedVictory(int i, int v);
};

void T_Scenario::SetPlayerAlliedVictory(int i, int v) {
    this->arr_[i] = v;
}
