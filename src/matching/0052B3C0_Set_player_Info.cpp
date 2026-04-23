struct Player_Start_Info {
    int gold;
    int wood;
    int food;
    int stone;
};

class T_Scenario {
public:
    char gap_00[0x1990];
    Player_Start_Info player_info[16];

    void Set_player_Info(int player, Player_Start_Info* info);
};

void T_Scenario::Set_player_Info(int player, Player_Start_Info* info) {
    if ((player >= 0) && (player < 16)) {
        this->player_info[player] = *info;
    }
}
