class T_Scenario {
public:
    char gap_0[0x4BF4];
    int arr_[320];
    void ClearDisabledTechnologies();
};

void T_Scenario::ClearDisabledTechnologies() {
    for (int i = 0; i < 320; i++) this->arr_[i] = 1;
}
