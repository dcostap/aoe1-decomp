class Tech_Tree_rea {
public:
    short get_state(short tech_id);
};

class TRIBE_Player_rea {
public:
    int researchEverAvailable(int tech_id);
    char gap_00[0x220];
    Tech_Tree_rea* tech_tree;
};

int TRIBE_Player_rea::researchEverAvailable(int tech_id) {
    short state;

    state = this->tech_tree->get_state((short)tech_id);
    if (state != 3 && state != -1)
        return 1;
    return 0;
}
