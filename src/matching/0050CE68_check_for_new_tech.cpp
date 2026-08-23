// /Od debug-style no-PDB TRIBE_Player_Tech::check_for_new_tech
// The PDB has no source record for this function.
// BINARY NOTE: The normal inventory owns 0050CE68-0050D079. The previous
// cancel_research body ends at 0050CE67 and save starts at 0050D07A. No tail
// jump or parent-owned fragment overlaps this body.
// BINARY NOTE: The qualified owner is
// ?check_for_new_tech@TRIBE_Player_Tech@@QAEEXZ. Direct callers are the two
// constructors (0050C4EE, 0050C554), undo_tech (0050C5D4), do_tech
// (0050C644), TRIBE_Player::scenario_load (00512887), and
// T_Scenario::set_player_tech (0052C355).
// BINARY NOTE: The frame is 0x24. The scan state occupies one contiguous 0x1c
// local window at [ebp-1c] through [ebp-4]. Word and byte accesses show four-
// byte homes. The explicit gaps below preserve those observed offsets.
// BINARY NOTE: The function keeps the technology list walk, resource rereads,
// narrow fields, do_tech call, publication, and shipped fault order.
// EXACT CANDIDATE: Fresh checker result is MATCH, 530 bytes, 0.0000%.
// ORIGINAL BUG: changed is reset on every pass and is never set. The shipped
// loop therefore does not repeat after this function changes a state.

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
    struct Check_New_Tech_Temps {
        Tech_Entry* tech;
        short i;
        char gap_after_i[2];
        short j;
        char gap_after_j[2];
        unsigned char prereq_done;
        char gap_after_prereq_done[3];
        short prereq_count;
        char gap_after_prereq_count[2];
        short active_count;
        char gap_after_active_count[2];
        unsigned char changed;
    };
    Check_New_Tech_Temps temps;

    temps.active_count = 0;
    temps.tech = this->base_tech->tech_tree;
    do {
        temps.changed = 0;
        for (temps.i = 0; temps.i < this->tech_player_tree_num; temps.i++) {
            if (this->tech_player_tree[temps.i].state < 2 &&
                this->tech_player_tree[temps.i].state > -1) {
                    temps.active_count++;
                    temps.prereq_done = 0;
                    temps.prereq_count = 0;
                    for (temps.j = 0; temps.j < 4; temps.j++) {
                        if (temps.tech[temps.i].pre_reqs[temps.j] >= 0) {
                            temps.prereq_count++;
                            if (this->tech_player_tree[temps.tech[temps.i].pre_reqs[temps.j]].state == 3) {
                                temps.prereq_done++;
                            }
                        }
                    }
                    if (temps.prereq_done >= temps.tech[temps.i].pre_reqs_required) {
                        if ((float)(int)temps.tech[temps.i].research <= this->tech_player_tree[temps.i].research_done) {
                            do_tech(temps.i);
                            temps.active_count--;
                        } else {
                            if (this->tech_player_tree[temps.i].state < 1) {
                                this->tech_player_tree[temps.i].state = 1;
                            }
                        }
                    } else {
                        if (this->tech_player_tree[temps.i].state > 0) {
                            this->tech_player_tree[temps.i].state = 0;
                        }
                }
            } else {
                if (this->tech_player_tree[temps.i].state == 2) {
                    temps.active_count++;
                }
            }
        }
    } while (temps.changed);
    if (temps.active_count == 0) {
        if (this->owner->player_attributes->attributes[0x27] == DAT_005766d8) {
            this->owner->player_attributes->attributes[0x27] = 1.0f;
        }
    }
    return 1;
}
