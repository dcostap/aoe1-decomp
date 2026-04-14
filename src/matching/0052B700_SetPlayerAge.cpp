class T_Scenario {
public:
    char gap_0[0x5100];
    int arr_[1];
    void SetPlayerAge(int i, int v);
};

void T_Scenario::SetPlayerAge(int i, int v) {
    this->arr_[i] = v;
}
