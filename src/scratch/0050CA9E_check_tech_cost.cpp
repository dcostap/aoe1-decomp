// 0050CA9E TRIBE_Player_Tech::check_tech_cost
// No PDB source. 391 bytes. __thiscall, ret 8.
//
// Attempt log:
// - probes 1-5: permutation of declarations → 32 stack offset diffs
// - probe 6: local struct → 35 diffs (worse)
// - probe 7: int has_carry → 42% diff (broken, reverted)
// - probe 8: variant lab template → 24 variants, all fail (syntax)
// - probes 9-18: brute-force 10 declaration orders → ALL 8.18% diff (same!)
// CONCLUSION: VC5 assigns stack slots independently of declaration order.
// Remaining 32 diffs are ALL single-byte [ebp+XX] displacement values that
// VC5 determines via internal heuristic (type grouping + liveness).
// Cannot be forced from pure C++ source. Left in scratch.

struct Tech_Player_Tree {
    float research_done;
    short state;
};

struct Tech_Entry {
    char gap_00[0x0E];
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D[0x01];
    short research;
    char gap_20[0x1C];
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
};

unsigned char TRIBE_Player_Tech::check_tech_cost(short param_1, short* param_2)
{
    Tech_Entry* tech;
    float carry;
    unsigned char has_carry;
    int i;
    int attr;
    float cost;

    tech = this->base_tech->tech_tree + param_1;
    carry = this->owner->player_attributes->attributes[3];
    if (this->owner->player_attributes->attributes[0x1d] < 1.0) {
        carry = 0.0f;
        has_carry = 0;
    } else {
        has_carry = 1;
    }
    if (this->tech_player_tree[param_1].state == 1) {
        for (i = 0; i < 3; i++) {
            attr = tech->attribute[i];
            if (attr >= 0 && tech->attribute_used[i] != 0) {
                cost = (float)(int)tech->attribute_cost[i];
                if (has_carry && attr == 3) {
                    carry = carry - cost;
                    if (carry < 0.0f) {
                        if (param_2) {
                            *param_2 = (short)attr;
                        }
                        return 0;
                    }
                }
                if (this->owner->player_attributes->attributes[attr] < cost) {
                    if (carry + this->owner->player_attributes->attributes[attr] < cost) {
                        if (param_2) {
                            *param_2 = (short)attr;
                        }
                        return 0;
                    }
                    carry = carry - (cost - this->owner->player_attributes->attributes[attr]);
                }
            }
        }
        return 1;
    }
    if (param_2) {
        *param_2 = -1;
    }
    return 0;
}
