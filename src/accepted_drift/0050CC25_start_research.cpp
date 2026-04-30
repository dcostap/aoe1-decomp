// 0050CC25 TRIBE_Player_Tech::start_research
// STATUS: parked - 11 bytes remaining (3.29%)
//
// Remaining diff: 6 single-byte slot swaps between attr (int) and cost (float)
// Original: cost=[ebp-4], attr=[ebp-0Ch]
// Rebuilt:  attr=[ebp-4], cost=[ebp-0Ch]
//
// Tried: all 24 declaration orders (none fixed float-vs-int placement),
//   `double cost` (bigger frame, 141 bytes diff),
//   `int cost_int` with inline (float) casts (missing 6 bytes),
//   `Player_Attributes* pa` temp (bigger function),
//   `cost > attr` comparison (19 bytes vs 11),
//   `(float)` vs `(float)(int)` cast (no change),
//   `long attr` (no change),
//   various scopes/bracketing (no improvement).
//
// Conclusion: VC5's float-vs-int stack slot heuristic differs between
// the original TU (tribe_ai.obj) and isolated scratch TU. No source-level
// fix found within reasonable attempts. Park at 11 bytes.

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

    unsigned char check_tech_cost(short param_1, short* param_2);
    unsigned char start_research(short param_1, unsigned char param_2, short* param_3);
};

unsigned char TRIBE_Player_Tech::start_research(short param_1, unsigned char param_2, short* param_3)
{
    Tech_Entry* tech;
    int i;
    float cost;
    int attr;

    tech = this->base_tech->tech_tree + param_1;
    if (this->check_tech_cost(param_1, param_3)) {
        if (param_2) {
            for (i = 0; i < 3; i++) {
                attr = tech->attribute[i];
                if (attr >= 0 && tech->attribute_used[i] != 0) {
                    cost = (float)(int)tech->attribute_cost[i];
                    if (this->owner->player_attributes->attributes[attr] < cost) {
                        this->owner->player_attributes->attributes[3] =
                            this->owner->player_attributes->attributes[3] - (cost - this->owner->player_attributes->attributes[attr]);
                        this->owner->player_attributes->attributes[attr] = 0.0f;
                    } else {
                        this->owner->player_attributes->attributes[attr] =
                            this->owner->player_attributes->attributes[attr] - cost;
                    }
                }
            }
            this->tech_player_tree[param_1].state = 2;
        }
        return 1;
    }
    if (param_3) {
        *param_3 = -1;
    }
    return 0;
}
