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
// - a typed loop-temporary aggregate with fields for i, attr, tech, carry,
//   cost, and has_carry reached 10 bytes but swapped the this and conversion homes.
// - restoring the natural anonymous integer-to-float cast with that aggregate
//   placed the compiler temporary at the target -20h home and matched all 391 bytes.
// - an explicit self alias regressed to 398 bytes and was reverted; the final
//   source keeps direct member ownership and the typed local aggregate.
// POLICY HOLD: the anonymous Check_Tech_Temps aggregate only controls local
// homes. It has no proven source ownership. Keep this exact diagnostic in
// scratch until a normal local declaration model emits the same code.

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

struct Check_Tech_Temps {
    int i;
    int attr;
    Tech_Entry* tech;
    float carry;
    float cost;
    unsigned char has_carry;
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
    Check_Tech_Temps temps;

    temps.tech = this->base_tech->tech_tree + param_1;
    temps.carry = this->owner->player_attributes->attributes[3];

    if (this->owner->player_attributes->attributes[0x1d] < 1.0) {
        temps.carry = 0.0f;
        temps.has_carry = 0;
    } else {
        temps.has_carry = 1;
    }
    if (this->tech_player_tree[param_1].state == 1) {
        for (temps.i = 0; temps.i < 3; temps.i++) {
            temps.attr = temps.tech->attribute[temps.i];
            if (temps.attr >= 0 && temps.tech->attribute_used[temps.i] != 0) {
                temps.cost = (float)(int)temps.tech->attribute_cost[temps.i];
                if (temps.has_carry && temps.attr == 3) {
                    temps.carry = temps.carry - temps.cost;
                    if (temps.carry < 0.0f) {
                        if (param_2) {
                            *param_2 = (short)temps.attr;
                        }
                        return 0;
                    }
                }
                if (this->owner->player_attributes->attributes[temps.attr] < temps.cost) {
                    if (temps.carry + this->owner->player_attributes->attributes[temps.attr] < temps.cost) {
                        if (param_2) {
                            *param_2 = (short)temps.attr;
                        }
                        return 0;
                    }
                    temps.carry = temps.carry - (temps.cost - this->owner->player_attributes->attributes[temps.attr]);
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
