class Friendliness {
public:
    int Attitude[16];
};

class T_Scenario {
public:
    char gap_0[0x47A8];
    Friendliness Opponent[16];

    void Set_player_attitude(int player, int target, int attitude);
};

void T_Scenario::Set_player_attitude(int player, int target, int attitude) {
    if (((attitude == 1) || (attitude == 3) || (attitude == 0)) &&
        ((player >= 0) && (player < 0x10) && (target >= 0) && (target < 0x10))) {
        this->Opponent[player].Attitude[target] = attitude;
    }
}
