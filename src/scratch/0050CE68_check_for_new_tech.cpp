// /Od debug-style no-PDB TRIBE_Player_Tech::check_for_new_tech
// Full behavior rewrite; current mismatch is local-slot topology/control-shape.
// Attempts: baseline typed scan was 534 bytes/232 diff; direct temp<=research_done
// plus removal of unsupported changed=1 reached 530 bytes/39 diff.  The natural
// (float)(int) research cast supplies the hidden -24h FILD home and, with the
// binary-proven DAT_005766d8 double, reaches 530 bytes/21 diff, 87.10% shape.
// Reordered/for-header locals were codegen duplicates; function-scope temp was
// worse.  Remaining drift is five swapped local homes (tech/changed/prereq_done/
// prereq_count/j; this and the hidden FILD temp now match), with no call/CFG gap.
// The natural typed prerequisite comparison also produced duplicate codegen;
// keep it because it removes unnecessary promotion casts from the source.
// Claim orch-50CE68-a: nested counter scopes worsened block shape; late
// declarations, declaration reordering, volatile qualifiers, and unsigned
// counter width were duplicates. Restored this clean source; the remaining
// blocker is the proven five-way VC5 local-home rotation.
// Probe luna-50CE68-r1: an initialized tech declaration moved the setup block
// and worsened the diff to 36 bytes; restored the separate natural assignment.
// Declaring tech before the scalar locals emitted the same 21-byte code; kept
// the clean declaration order because it is clearer and remains the baseline.
// Probe luna-50CE68-r2: inner-block j scope and the donor TU stdlib context were
// exact codegen duplicates; signed byte flags worsened size and CFG. A full
// declaration-cycle reorder also stayed at 21 bytes. Restored clean source.
// Probe luna-50CE68-r4: tested function-scope j, late or initialized scalar
// declarations, explicit changed != 0, and outer-index prefix increment; all
// were duplicates. Scoping tech or either prerequisite counter, a while-loop
// rewrite, and a named research temp worsened structure. Restored clean source;
// no evidence-backed natural lead remains for the five-way local-home rotation.

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

extern double DAT_005766d8;

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;

    unsigned char do_tech(short param_1);
    unsigned char check_for_new_tech();
};

unsigned char TRIBE_Player_Tech::check_for_new_tech()
{
    short active_count;
    short i;
    short prereq_count;
    unsigned char changed;
    unsigned char prereq_done;
    Tech_Entry* tech;

    active_count = 0;
    tech = this->base_tech->tech_tree;
    do {
        changed = 0;
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state < 2 &&
                this->tech_player_tree[i].state > -1) {
                    active_count++;
                    prereq_done = 0;
                    prereq_count = 0;
                    for (short j = 0; j < 4; j++) {
                        if (tech[i].pre_reqs[j] >= 0) {
                            prereq_count++;
                            if (this->tech_player_tree[tech[i].pre_reqs[j]].state == 3) {
                                prereq_done++;
                            }
                        }
                    }
                    if (prereq_done >= tech[i].pre_reqs_required) {
                        if ((float)(int)tech[i].research <= this->tech_player_tree[i].research_done) {
                            do_tech(i);
                            active_count--;
                        } else {
                            if (this->tech_player_tree[i].state < 1) {
                                this->tech_player_tree[i].state = 1;
                            }
                        }
                    } else {
                        if (this->tech_player_tree[i].state > 0) {
                            this->tech_player_tree[i].state = 0;
                        }
                    }
            } else {
                if (this->tech_player_tree[i].state == 2) {
                    active_count++;
                }
            }
        }
    } while (changed);
    if (active_count == 0) {
        if (this->owner->player_attributes->attributes[0x27] == DAT_005766d8) {
            this->owner->player_attributes->attributes[0x27] = 1.0f;
        }
    }
    return 1;
}
