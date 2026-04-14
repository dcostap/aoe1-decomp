class T_Scenario {
public:
    char gap_0[0xC];
    unsigned char field_C;
    char gap_D[0x5133];
    int field_5140;
    void SetMPVictory(int v);
};

void T_Scenario::SetMPVictory(int v) {
    this->field_5140 = v;
    if (v != 4) this->field_C = 1;
}
