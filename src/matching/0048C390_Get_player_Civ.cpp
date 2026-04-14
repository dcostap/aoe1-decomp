class RGE_Scenario {
public:
    char gap_0[0x190C];
    int arr_[16];
    int Get_player_Civ(int index);
};

int RGE_Scenario::Get_player_Civ(int index) {
    if (index < 0 || index >= 16) return 0;
    return this->arr_[index];
}
