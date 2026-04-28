// matched candidate: /Od debug-style no-PDB cancel research

struct Tech_Player_Tree {
    float research_done;
    short state;
};

struct Tech_Entry {
    char gap_00[0x0E];
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D[0x1F];
};

struct Player_Attributes {
    float attributes[0x40];
};

struct RGE_Player {
    char gap_00[0x50];
    Player_Attributes* player_attributes;
};

struct TRIBE_Tech {
    Tech_Entry* tech_tree;
};

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    unsigned char cancel_research(short param_1, unsigned char param_2);
};

unsigned char TRIBE_Player_Tech::cancel_research(short param_1, unsigned char param_2)
{
    Tech_Entry* tech;
    short i;

    tech = this->base_tech->tech_tree + param_1;
    if (this->tech_player_tree[param_1].state == 2) {
        if (param_2) {
            for (i = 0; i < 3; i++) {
                if (tech->attribute[i] >= 0 && tech->attribute_used[i] != 0) {
                    this->owner->player_attributes->attributes[tech->attribute[i]] =
                        (float)(int)tech->attribute_cost[i] + this->owner->player_attributes->attributes[tech->attribute[i]];
                }
            }
        }
        this->tech_player_tree[param_1].state = 1;
        this->tech_player_tree[param_1].research_done = 0.0f;
        return 1;
    }
    return 0;
}
