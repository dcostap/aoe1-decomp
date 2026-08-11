// /Od debug-style no-PDB TRIBE_Player_Tech::tech_cost
// Attempt log:
// - Baseline typed Tech_Entry/owner reconstruction: 883 bytes; extra EDI and
//   total-left arithmetic were the first structural drift.
// - Reversing the shortage predicate to available < integer cost preserved the
//   original FPU evaluation order; block-scoped adjusted-cost locals widened
//   the frame and were rolled back.
// - Evaluating the cost-minus-available term before total removed EDI and
//   reached 879 bytes / 602 positional diff; explicit short result casts and
//   compound short fallback additions reached 875 bytes / 281 instructions,
//   57-byte edit diff, and are retained as the best clean source shape.
// - Remaining drift is localized but unresolved: compiler homes tech at
//   [ebp-4] and carry at [ebp-0xc] instead of the oracle's [ebp-0xc]/[ebp-4],
//   with associated branch spans; no source-level slot fix was found within
//   the 10-hypothesis budget. FLAGS: config/flags/0050C730_tech_cost.rsp

#include <stdlib.h>

struct Tech_Player_Tree {
    float research_done;
    short state;
};

struct Tech_Entry {
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short civilization;
    short full_tech_mode;
    unsigned char button_location;
    char gap_27;
    short button_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

struct Player_Attributes { float attributes[0x40]; };
struct RGE_Player { char gap_00[0x50]; Player_Attributes* player_attributes; };
struct TRIBE_Tech { Tech_Entry* tech_tree; };

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    unsigned char check_tech_cost(short param_1, short* param_2);
    void tech_cost(short param_1, short* attr1, short* cost1, short* attr2, short* cost2, short* attr3, short* cost3);
};

void TRIBE_Player_Tech::tech_cost(short param_1, short* attr1, short* cost1, short* attr2, short* cost2, short* attr3, short* cost3)
{
    short total;
    unsigned char can_use_carry;
    Tech_Entry* tech;

    tech = this->base_tech->tech_tree + param_1;
    total = 0;
    *attr1 = -1;
    *cost1 = 0;
    *attr2 = -1;
    *cost2 = 0;
    *attr3 = -1;
    *cost3 = 0;

    can_use_carry = this->check_tech_cost(param_1, 0);
    if (this->owner->player_attributes->attributes[0x1d] < 1.0) {
        can_use_carry = 0;
    }

    if (tech->attribute_used[0] != 0) {
        *attr1 = tech->attribute[0];
        if (*attr1 >= 0) {
            *cost1 = tech->attribute_cost[0];
            if (this->owner->player_attributes->attributes[*attr1] < (float)(int)*cost1) {
                if (can_use_carry) {
                    total = (short)((*cost1 - (short)this->owner->player_attributes->attributes[*attr1]) + total);
                    *cost1 = (short)this->owner->player_attributes->attributes[*attr1];
                }
            }
        }
    }

    if (tech->attribute_used[1] != 0) {
        *attr2 = tech->attribute[1];
        if (*attr2 >= 0) {
            *cost2 = tech->attribute_cost[1];
            if (this->owner->player_attributes->attributes[*attr2] < (float)(int)*cost2) {
                if (can_use_carry) {
                    total = (short)((*cost2 - (short)this->owner->player_attributes->attributes[*attr2]) + total);
                    *cost2 = (short)this->owner->player_attributes->attributes[*attr2];
                }
            }
        }
    }

    if (tech->attribute_used[2] != 0) {
        *attr3 = tech->attribute[2];
        if (*attr3 >= 0) {
            *cost3 = tech->attribute_cost[2];
            if (this->owner->player_attributes->attributes[*attr3] < (float)(int)*cost3) {
                if (can_use_carry) {
                    total = (short)((*cost3 - (short)this->owner->player_attributes->attributes[*attr3]) + total);
                    *cost3 = (short)this->owner->player_attributes->attributes[*attr3];
                }
            }
        }
    }

    if (total > 0) {
        if (*attr1 == 3 || *attr1 == -1) {
            *attr1 = 3;
            *cost1 += total;
        } else if (*attr2 == 3 || *attr2 == -1) {
            *attr2 = 3;
            *cost2 += total;
        } else if (*attr3 == 3 || *attr3 == -1) {
            *attr3 = 3;
            *cost3 = total;
        }
    }

    if (*cost1 <= 0) {
        *attr1 = -1;
    }
    if (*cost2 <= 0) {
        *attr2 = -1;
    }
    if (*cost3 <= 0) {
        *attr3 = -1;
    }
}
