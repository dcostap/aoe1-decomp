class T_Scenario {
public:
    char gap_0[0x4BF0];
    int field_4BF0;
    void SetSPWhich(int v);
};

void T_Scenario::SetSPWhich(int v) {
    if (v < 0) v = 0;
    if (v > 16) v = 15;
    this->field_4BF0 = v;
}
