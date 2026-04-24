// TRIBE_Player_Tech::undo_tech (0050C5A7, 62 bytes)

struct TechPlayerEntry {
    char gap_00[4];
    short state;
    char gap_06[2];
};

class TRIBE_Player_Tech {
public:
    TechPlayerEntry* tech_player_tree;

    unsigned char undo_tech(short param_1);
    void check_for_new_tech();
};

unsigned char TRIBE_Player_Tech::undo_tech(short param_1) {
    if (this->tech_player_tree[param_1].state >= 1) {
        this->tech_player_tree[param_1].state = 0;
        check_for_new_tech();
        return 1;
    }
    return 0;
}
