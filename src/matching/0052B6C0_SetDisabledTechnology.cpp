class T_Scenario {
public:
    char gap_00[0x4BF4];
    int DisabledTechnology[16][20];

    void SetDisabledTechnology(int param1, int param2, int param3);
};

void T_Scenario::SetDisabledTechnology(int param1, int param2, int param3) {
    DisabledTechnology[param1][param2] = param3;
}
