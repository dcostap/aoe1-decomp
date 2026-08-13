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
// - Recovered the original word-add topology with total += (short)(cost -
//   (short)available): size 878, 15-byte positional diff, and exact call/block
//   regions. Declaration order and a reference owner did not move local homes.
// - Fresh probes permuted total/tech/carry declarations, scoped carry to the
//   call-to-cleanup region, marked carry volatile, and initialized const tech;
//   all retained or duplicate the same 15-byte displacement-only mismatch.
//   A named 0xc-byte local frame aggregate with the proven pointer/short/byte
//   offsets restored the oracle homes and matched all 878 bytes. FLAGS:
//   config/flags/0050C730_tech_cost.rsp

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
struct Tech_Cost_Temps {
    Tech_Entry* tech;
    short total;
    char gap_06[2];
    unsigned char can_use_carry;
};

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
    Tech_Cost_Temps temps;

    temps.tech = this->base_tech->tech_tree + param_1;
    temps.total = 0;
    *attr1 = -1;
    *cost1 = 0;
    *attr2 = -1;
    *cost2 = 0;
    *attr3 = -1;
    *cost3 = 0;

    temps.can_use_carry = this->check_tech_cost(param_1, 0);
    if (this->owner->player_attributes->attributes[0x1d] < 1.0) {
        temps.can_use_carry = 0;
    }

    if (temps.tech->attribute_used[0] != 0) {
        *attr1 = temps.tech->attribute[0];
        if (*attr1 >= 0) {
            *cost1 = temps.tech->attribute_cost[0];
            if (this->owner->player_attributes->attributes[*attr1] < (float)(int)*cost1) {
                if (temps.can_use_carry) {
                    temps.total += (short)(*cost1 - (short)this->owner->player_attributes->attributes[*attr1]);
                    *cost1 = (short)this->owner->player_attributes->attributes[*attr1];
                }
            }
        }
    }

    if (temps.tech->attribute_used[1] != 0) {
        *attr2 = temps.tech->attribute[1];
        if (*attr2 >= 0) {
            *cost2 = temps.tech->attribute_cost[1];
            if (this->owner->player_attributes->attributes[*attr2] < (float)(int)*cost2) {
                if (temps.can_use_carry) {
                    temps.total += (short)(*cost2 - (short)this->owner->player_attributes->attributes[*attr2]);
                    *cost2 = (short)this->owner->player_attributes->attributes[*attr2];
                }
            }
        }
    }

    if (temps.tech->attribute_used[2] != 0) {
        *attr3 = temps.tech->attribute[2];
        if (*attr3 >= 0) {
            *cost3 = temps.tech->attribute_cost[2];
            if (this->owner->player_attributes->attributes[*attr3] < (float)(int)*cost3) {
                if (temps.can_use_carry) {
                    temps.total += (short)(*cost3 - (short)this->owner->player_attributes->attributes[*attr3]);
                    *cost3 = (short)this->owner->player_attributes->attributes[*attr3];
                }
            }
        }
    }

    if (temps.total > 0) {
        if (*attr1 == 3 || *attr1 == -1) {
            *attr1 = 3;
            *cost1 += temps.total;
        } else if (*attr2 == 3 || *attr2 == -1) {
            *attr2 = 3;
            *cost2 += temps.total;
        } else if (*attr3 == 3 || *attr3 == -1) {
            *attr3 = 3;
            *cost3 = temps.total;
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
