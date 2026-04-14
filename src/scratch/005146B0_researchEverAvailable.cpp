class Tech_Tree_rea {
public:
    short get_state(int tech_id);
};

class TRIBE_Player_rea {
public:
    int researchEverAvailable(int tech_id);
    char gap_00[0x220];
    Tech_Tree_rea* tech_tree;
};

int TRIBE_Player_rea::researchEverAvailable(int tech_id) {
    short state = this->tech_tree->get_state(tech_id);
    if (state == 3) return 0;
    if (state == (short)0xFFFF) return 0;
    return 1;
}
