class RGE_Scenario {
public:
    char gap_0[0x194C];
    int arr_[16];
    void Set_player_Active(int index, int val);
};

void RGE_Scenario::Set_player_Active(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->arr_[index] = val;
}
