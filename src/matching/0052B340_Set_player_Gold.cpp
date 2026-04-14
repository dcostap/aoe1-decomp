struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

class T_Scenario {
public:
    char gap_0[0x1990];
    Player_Start_Info player_info[16];

    void Set_player_Gold(int param_1, int param_2);
};

void T_Scenario::Set_player_Gold(int param_1, int param_2) {
    if (param_1 < 0 || param_1 >= 16)
        return;
    this->player_info[param_1].Gold = param_2;
}
