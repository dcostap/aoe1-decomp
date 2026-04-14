class T_Scenario {
public:
    char gap_0[0x4BE8];
    int field_4BE8;
    void Set_victory_all_flag(int v);
};

void T_Scenario::Set_victory_all_flag(int v) {
    if (v < 0) v = 0;
    if (v > 1) v = 1;
    this->field_4BE8 = v;
}
