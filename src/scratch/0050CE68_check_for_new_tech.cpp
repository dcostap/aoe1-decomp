// /Od debug-style no-PDB TRIBE_Player_Tech::check_for_new_tech
// Full behavior rewrite; current mismatch is local-slot topology/control-shape.

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
    Tech_Entry* tech;
    short i;
    unsigned char changed;
    short active_count;
    unsigned char prereq_done;
    short prereq_count;
    short j;

    active_count = 0;
    tech = this->base_tech->tech_tree;
    do {
        changed = 0;
        for (i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state < 2) {
                if (this->tech_player_tree[i].state > -1) {
                    active_count++;
                    prereq_done = 0;
                    prereq_count = 0;
                    for (j = 0; j < 4; j++) {
                        if (tech[i].pre_reqs[j] >= 0) {
                            prereq_count++;
                            if (this->tech_player_tree[tech[i].pre_reqs[j]].state == 3) {
                                prereq_done++;
                            }
                        }
                    }
                    if ((int)prereq_done >= (int)tech[i].pre_reqs_required) {
                        int temp;
                        temp = tech[i].research;
                        if (!(this->tech_player_tree[i].research_done < (float)temp)) {
                            do_tech(i);
                            active_count--;
                            changed = 1;
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
                }
            } else {
                if (this->tech_player_tree[i].state == 2) {
                    active_count++;
                }
            }
        }
    } while (changed);
    if (active_count == 0) {
        if (this->owner->player_attributes->attributes[0x27] == 0.0f) {
            this->owner->player_attributes->attributes[0x27] = 1.0f;
        }
    }
    return 1;
}
