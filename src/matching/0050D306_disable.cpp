#ifndef TECH_GROUP_CONTEXT
// matched candidate: /Od debug-style no-PDB TRIBE_Player_Tech state mutator

struct Tech_Player_Tree {
    float research_done;
    short state;
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;

    void disable(short param_1);
};

#endif

void TRIBE_Player_Tech::disable(short param_1)
{
    int i;

    if (param_1 < 0) {
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state != 3) {
                this->tech_player_tree[i].state = -1;
            }
        }
    } else if (this->tech_player_tree[param_1].state != 3) {
        this->tech_player_tree[param_1].state = -1;
    }
}
