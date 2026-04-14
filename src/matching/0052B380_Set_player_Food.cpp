struct Entry_0052B380 {
    char data[16];
};

class T_Scenario {
public:
    char gap_0[0x1998];
    Entry_0052B380 entries_[16];
    void Set_player_Food(int index, int val);
};

void T_Scenario::Set_player_Food(int index, int val) {
    if (index < 0 || index >= 16) return;
    *(int*)&this->entries_[index] = val;
}
