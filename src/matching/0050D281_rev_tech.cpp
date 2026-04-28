// matched candidate: /Od debug-style no-PDB reverse-tech traversal

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
    unsigned char rev_tech(short param_1);
};

unsigned char TRIBE_Player_Tech::rev_tech(short param_1)
{
    int i;
    int j;

    this->do_tech(param_1);
    for (i = 0; i < this->tech_player_tree_num; i++) {
        for (j = 0; j < 4; j++) {
            if (this->base_tech->tech_tree[i].pre_reqs[j] == param_1) {
                this->do_rev_tech((short)i);
            }
        }
    }
    return 1;
}
