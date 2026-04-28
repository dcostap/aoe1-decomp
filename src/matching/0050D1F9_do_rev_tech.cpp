// matched candidate: /Od debug-style no-PDB recursive reverse-tech helper

struct Tech_Player_Tree {
    float research_done;
    short state;
};

struct Tech_Entry {
    char gap_00[0x04];
    short pre_reqs[4];
    char gap_0C[0x30];
};

struct TRIBE_Tech {
    Tech_Entry* tech_tree;
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;

    unsigned char do_tech(short param_1);
    void do_rev_tech(short param_1);
};

void TRIBE_Player_Tech::do_rev_tech(short param_1)
{
    int i;
    int tech;

    for (i = 0; i < 4; i++) {
        tech = this->base_tech->tech_tree[param_1].pre_reqs[i];
        if (tech >= 0 && this->tech_player_tree[tech].state < 3) {
            if (this->tech_player_tree[tech].state >= 0) {
                this->do_rev_tech((short)tech);
            }
        }
    }
    this->do_tech(param_1);
}
