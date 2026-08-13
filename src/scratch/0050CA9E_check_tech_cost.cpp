// 0050CA9E TRIBE_Player_Tech::check_tech_cost
// No PDB source. 391 bytes. __thiscall, ret 8.
//
// Attempt log:
// - baseline: typed Tech_Entry scan, default flags, 32 positional diffs.
// - bool/char predicate and declaration-initializer variants were codegen duplicates.
// - natural lexical scopes for i/attr/cost improved to 16 diffs (4.09%); this is kept.
// - for-header i and loop-scope/inner-init cost were duplicates; top-scope cost regressed to 32.
// - short attr changed size to 401 bytes and was reverted; no ABI evidence supports it.
// - focused pointer/reference + byte-predicate lab: one malformed extraction basin, no eligible lead.
// - fresh pass: function-scope i worsened to 24 bytes; explicit int cost worsened to 26;
//   nested guard changed size/CFG; compound assignment, stdlib/full-class context, and
//   complete TRIBE_Tech layout were codegen duplicates and were reverted.
// Remaining 16 bytes are local [ebp+XX] displacement coloring only; calls, CFG, size,
// frame, and all non-stack instruction bytes match. Left in scratch pending a compiler
// slot-allocation lead. Target homes tech/i/cost at -10h/-18h/-8h; rebuilt homes them
// at -8h/-10h/-18h. Source remains the simplest typed reconstruction.
// - loop-scope cost declaration before attr with delayed assignment was a codegen duplicate;
//   it did not rotate the target cost/index homes and was reverted.

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
    Tech_Entry* tech = this->base_tech->tech_tree + param_1;
    float carry = this->owner->player_attributes->attributes[3];
    unsigned char has_carry;

    if (this->owner->player_attributes->attributes[0x1d] < 1.0) {
        carry = 0.0f;
        has_carry = 0;
    } else {
        has_carry = 1;
    }
    if (this->tech_player_tree[param_1].state == 1) {
        int i;
        for (i = 0; i < 3; i++) {
            int attr;
            attr = tech->attribute[i];
            if (attr >= 0 && tech->attribute_used[i] != 0) {
                float cost = (float)(int)tech->attribute_cost[i];
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
