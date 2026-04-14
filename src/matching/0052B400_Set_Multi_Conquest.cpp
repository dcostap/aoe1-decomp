class T_Scenario {
public:
    char gap_0[0x1A90];
    int MP_Conquest;

    void Set_conquest_victory(int flag);
    void Set_Multi_Conquest(int param);
};

void T_Scenario::Set_Multi_Conquest(int param) {
    if (param) {
        this->MP_Conquest = 1;
        this->Set_conquest_victory(1);
    } else {
        this->MP_Conquest = 0;
        this->Set_conquest_victory(0);
    }
}
