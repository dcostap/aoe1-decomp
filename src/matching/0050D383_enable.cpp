// matched candidate: /Od debug-style no-PDB TRIBE_Player_Tech state mutator

struct Tech_Player_Tree {
    float research_done;
    short state;
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;

    void enable(short param_1);
};

void TRIBE_Player_Tech::enable(short param_1)
{
    int i;

    if (param_1 < 0) {
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state == -1) {
                this->tech_player_tree[i].state = 0;
            }
        }
    } else if (this->tech_player_tree[param_1].state == -1) {
        this->tech_player_tree[param_1].state = 0;
    }
}
