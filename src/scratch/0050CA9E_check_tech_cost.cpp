#ifndef TECH_GROUP_CONTEXT
// 0050CA9E TRIBE_Player_Tech::check_tech_cost
// No PDB source. 391 bytes. __thiscall, ret 8.
//
// BINARY AUDIT: The normal-function inventory owns 0050CA9E-0050CC24. The
// previous function ends at 0050CA9E and start_research starts at 0050CC25.
// The qualified target symbol is
// ?check_tech_cost@TRIBE_Player_Tech@@QAEEFPAF@Z. Direct callers are
// tech_cost, start_research, and the PDB-backed TRIBE_Player wrapper at
// 00513D70. No call or tail jump leaves this body.
// BINARY NOTE: The local object starts at [ebp-18h]. Its fields are i, attr,
// tech, carry, cost, and has_carry at offsets 0, 4, 8, 0xc, 0x10, and 0x14.
// The observed [ebp-20h] integer conversion temp and [ebp-1ch] saved this are
// outside that 0x18-byte object. No union or manual packing is required.
// BINARY NOTE: Signed short indexing, null output checks, unchecked attribute
// indexing, short output stores, and the initial dereference order are kept.
// These preserve malformed-input behavior and fault order.
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
// - a fresh pass tested target-order top-level scalar declarations, declaration
//   initializers, function-scope i, branch/loop-scope cost, byte/attr order, and
//   const tech; these stayed at 16, 24, or 32 bytes and were reverted.
// - a 12-case /Od declaration-order lab found only two 391-byte codegen groups,
//   both nonexact; no ordinary top-level declaration order recovered the homes.
// BINARY NOTE: The six live loop and cost values occupy one contiguous private
// local window. A typed local object reproduces that window without aliases,
// address escapes, or changes to the member and resource access order.
// SOURCE HYPOTHESIS: Check_Tech_Temps is the simplest period-plausible model
// for that private state. The target has no PDB source record, so this local
// type is not a PDB-proven declaration. Its exact field order is codegen-active.
// A fresh checker gives MATCH, 0.0000%, for the reduced local object.

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

#endif

unsigned char TRIBE_Player_Tech::check_tech_cost(short param_1, short* param_2)
{
    struct Check_Tech_Temps {
        int i;
        int attr;
        Tech_Entry* tech;
        float carry;
        float cost;
        unsigned char has_carry;
    };
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
