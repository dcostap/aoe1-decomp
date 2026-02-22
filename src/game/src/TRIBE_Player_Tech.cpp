#include "../include/TRIBE_Player_Tech.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_History_Info.h"
#include "../include/TRIBE_Tech.h"
#include "../include/RGE_Player.h"
#include "../include/globals.h"

// Source of truth: bucket_050C.cpp.decomp + bucket_050D.cpp.decomp

TRIBE_Player_Tech::TRIBE_Player_Tech(int param_1, TRIBE_Tech* param_2, RGE_Player* param_3, uchar param_4) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C3A5
    rge_read(param_1, &this->tech_player_tree_num, 2);
    this->base_tech = param_2;
    this->owner = param_3;
    if (this->tech_player_tree_num > 0) {
        this->tech_player_tree = (Tech_Player_Tree*)calloc(8, (int)this->tech_player_tree_num);
        for (short i = 0; i < this->tech_player_tree_num; i++) {
            if (save_game_version > 7.03f) {
                rge_read(param_1, &this->tech_player_tree[i], 4);
            } else {
                rge_read(param_1, &this->tech_player_tree[i], 2);
            }
            rge_read(param_1, &this->tech_player_tree[i].state, 2);
        }
        if (param_4 != 0) {
            for (short i = 0; i < this->tech_player_tree_num; i++) {
                if (this->tech_player_tree[i].state == 3) {
                    this->tech_player_tree[i].state = 1;
                    do_tech(i);
                }
            }
            check_for_new_tech();
        }
    }
}

TRIBE_Player_Tech::TRIBE_Player_Tech(TRIBE_Tech* param_1, RGE_Player* param_2, uchar param_3) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C4FC
    this->base_tech = param_1;
    this->owner = param_2;
    this->tech_player_tree_num = param_1->tech_tree_num;
    if (this->tech_player_tree_num > 0) {
        this->tech_player_tree = (Tech_Player_Tree*)calloc(8, (int)this->tech_player_tree_num);
    }
    if (param_3 != 0) {
        check_for_new_tech();
    }
}

TRIBE_Player_Tech::~TRIBE_Player_Tech() {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C562
    if (this->tech_player_tree != nullptr) {
        free(this->tech_player_tree);
        this->tech_player_tree = nullptr;
    }
}

short TRIBE_Player_Tech::get_tech_state(short param_1) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C58C
    return this->tech_player_tree[param_1].state;
}

uchar TRIBE_Player_Tech::do_tech(short param_1) {
    // Fully verified. Source of truth: bucket_050C.decomp @ 0x0050C5E5
    if (this->tech_player_tree[param_1].state < 3 && this->tech_player_tree[param_1].state >= 0) {
        this->tech_player_tree[param_1].state = 3;
        this->base_tech->do_tech(param_1, this->owner);
        check_for_new_tech();

        TRIBE_Player* owner_player = (TRIBE_Player*)this->owner;
        if (owner_player != nullptr && owner_player->history != nullptr) {
            if (param_1 == 0x65) {
                owner_player->history->add_history_event(0);
            } else if (param_1 == 0x66) {
                owner_player->history->add_history_event(1);
            } else if (param_1 == 0x67) {
                owner_player->history->add_history_event(2);
            }
        }
        return 1;
    }
    return 0;
}

uchar TRIBE_Player_Tech::undo_tech(short param_1) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C5A7
    bool was_active = this->tech_player_tree[param_1].state > 0;
    if (was_active) {
        this->tech_player_tree[param_1].state = 0;
        check_for_new_tech();
    }
    return was_active;
}

void TRIBE_Player_Tech::do_rev_tech(short param_1) {
    // Source of truth: bucket_050D.decomp @ 0x0050D1F9
    for (int i = 0; i < 4; i++) {
        short prereq = this->base_tech->tech_tree[param_1].pre_reqs[i];
        int prereq_index = (int)prereq;
        if (prereq_index >= 0 && this->tech_player_tree[prereq_index].state < 3) {
            if (this->tech_player_tree[prereq_index].state >= 0) {
                do_rev_tech(prereq);
            }
        }
    }
    do_tech(param_1);
}

uchar TRIBE_Player_Tech::rev_tech(short param_1) {
    // Source of truth: bucket_050D.decomp @ 0x0050D281
    do_tech(param_1);
    for (int i = 0; i < this->tech_player_tree_num; i++) {
        for (int j = 0; j < 4; j++) {
            if (this->base_tech->tech_tree[i].pre_reqs[j] == param_1) {
                do_rev_tech((short)i);
            }
        }
    }
    return 1;
}

uchar TRIBE_Player_Tech::research(short param_1, float param_2) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C6AD
    if (this->tech_player_tree[param_1].state == 2) {
        this->tech_player_tree[param_1].research_done += param_2;
        if (this->tech_player_tree[param_1].research_done < (float)(int)this->base_tech->tech_tree[param_1].research) {
            return 1;
        } else {
            do_tech(param_1);
            return 0;
        }
    }
    return 0;
}

// Fully verified. Source of truth: bucket_050D.decomp @ 0x0050D0FA
short TRIBE_Player_Tech::get_progress(short param_1) {
    if (this->tech_player_tree[param_1].state == 2) {
        short research_required = this->base_tech->tech_tree[param_1].research;
        if (research_required > 0) {
            return (short)((this->tech_player_tree[param_1].research_done * 100.0f) / (float)research_required);
        }
        return 100;
    }
    if (this->tech_player_tree[param_1].state == 3) {
        return 100;
    }
    return 0;
}

// Fully verified. Source of truth: bucket_050D.decomp @ 0x0050D178
char* TRIBE_Player_Tech::get_name(short param_1) {
    return this->base_tech->tech_tree[param_1].name;
}

uchar TRIBE_Player_Tech::check_tech_cost(short param_1, short* param_2) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050CA9E
    Tech_Tree* tt = this->base_tech->tech_tree;
    float gold_pool = this->owner->attributes[3];
    bool has_trade = this->owner->attributes[0x1d] >= 1.0f;
    if (!has_trade) {
        gold_pool = 0.0f;
    }
    if (this->tech_player_tree[param_1].state == 1) {
        for (int i = 0; i < 3; i++) {
            short attr_idx = tt[param_1].attribute[i];
            int idx = (int)attr_idx;
            if (idx >= 0 && tt[param_1].attribute_used[i] != 0) {
                float cost = (float)(int)tt[param_1].attribute_cost[i];
                if (has_trade && idx == 3 && (gold_pool -= cost, gold_pool < 0.0f)) {
                    if (param_2 != nullptr) {
                        *param_2 = attr_idx;
                    }
                    return 0;
                }
                if (this->owner->attributes[idx] < cost) {
                    if (gold_pool + this->owner->attributes[idx] < cost) {
                        if (param_2 != nullptr) {
                            *param_2 = attr_idx;
                        }
                        return 0;
                    }
                    gold_pool -= (cost - this->owner->attributes[idx]);
                }
            }
        }
        return 1;
    } else {
        if (param_2 != nullptr) {
            *param_2 = -1;
        }
        return 0;
    }
}

uchar TRIBE_Player_Tech::start_research(short param_1, uchar param_2, short* param_3) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050CC25
    Tech_Tree* tt = this->base_tech->tech_tree;
    uchar result = check_tech_cost(param_1, param_3);
    if (result == 0) {
        if (param_3 != nullptr) {
            *param_3 = -1;
        }
        return 0;
    }
    if (param_2 != 0) {
        for (int i = 0; i < 3; i++) {
            int idx = (int)tt[param_1].attribute[i];
            if (idx >= 0 && tt[param_1].attribute_used[i] != 0) {
                float cost = (float)(int)tt[param_1].attribute_cost[i];
                if (cost <= this->owner->attributes[idx]) {
                    this->owner->attributes[idx] -= cost;
                } else {
                    this->owner->attributes[3] -= (cost - this->owner->attributes[idx]);
                    this->owner->attributes[idx] = 0.0f;
                }
            }
        }
        this->tech_player_tree[param_1].state = 2;
    }
    return 1;
}

// Fully verified. Source of truth: bucket_050C.decomp @ 0x0050CD73
uchar TRIBE_Player_Tech::cancel_research(short param_1, uchar param_2) {
    Tech_Tree* tt = this->base_tech->tech_tree;
    if (this->tech_player_tree[param_1].state == 2) {
        if (param_2 != 0) {
            for (short i = 0; i < 3; ++i) {
                int attr_index = (int)tt[param_1].attribute[i];
                if ((attr_index >= 0) && (tt[param_1].attribute_used[i] != 0)) {
                    this->owner->attributes[attr_index] =
                        this->owner->attributes[attr_index] + (float)(int)tt[param_1].attribute_cost[i];
                }
            }
        }
        this->tech_player_tree[param_1].state = 1;
        this->tech_player_tree[param_1].research_done = 0.0f;
        return 1;
    }
    return 0;
}

void TRIBE_Player_Tech::tech_cost(short param_1, short* param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7) {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050C730
    // Simplified version - returns tech costs without trade gold substitution logic
    Tech_Tree* tt = this->base_tech->tech_tree;
    *param_2 = -1;
    *param_3 = 0;
    *param_4 = -1;
    *param_5 = 0;
    *param_6 = -1;
    *param_7 = 0;
    if (tt[param_1].attribute_used[0] != 0) {
        *param_2 = tt[param_1].attribute[0];
        if (*param_2 >= 0) {
            *param_3 = tt[param_1].attribute_cost[0];
        }
    }
    if (tt[param_1].attribute_used[1] != 0) {
        *param_4 = tt[param_1].attribute[1];
        if (*param_4 >= 0) {
            *param_5 = tt[param_1].attribute_cost[1];
        }
    }
    if (tt[param_1].attribute_used[2] != 0) {
        *param_6 = tt[param_1].attribute[2];
        if (*param_6 >= 0) {
            *param_7 = tt[param_1].attribute_cost[2];
        }
    }
    if (*param_3 < 1) *param_2 = -1;
    if (*param_5 < 1) *param_4 = -1;
    if (*param_7 < 1) *param_6 = -1;
}

void TRIBE_Player_Tech::check_for_new_tech() {
    // Source of truth: bucket_050C.cpp.decomp @ 0x0050CE68
    Tech_Tree* tt = this->base_tech->tech_tree;
    short pending_count = 0;
    for (short i = 0; i < this->tech_player_tree_num; i++) {
        if (this->tech_player_tree[i].state < 2 && this->tech_player_tree[i].state >= 0) {
            pending_count++;
            uchar met = 0;
            for (short j = 0; j < 4; j++) {
                if (tt[i].pre_reqs[j] >= 0 && this->tech_player_tree[tt[i].pre_reqs[j]].state == 3) {
                    met++;
                }
            }
            if ((short)(unsigned short)met < tt[i].pre_reqs_required) {
                if (this->tech_player_tree[i].state > 0) {
                    this->tech_player_tree[i].state = 0;
                }
            } else if (this->tech_player_tree[i].research_done < (float)(int)tt[i].research) {
                if (this->tech_player_tree[i].state < 1) {
                    this->tech_player_tree[i].state = 1;
                }
            } else {
                do_tech(i);
            }
        } else if (this->tech_player_tree[i].state == 2) {
            pending_count++;
        }
    }
    if (pending_count == 0 && this->owner->attributes[0x27] == 0.0f) {
        this->owner->attributes[0x27] = 1.0f;
    }
}

void TRIBE_Player_Tech::save(int param_1) {
    // Source of truth: bucket_050D.cpp.decomp @ 0x0050D07A
    rge_write(param_1, &this->tech_player_tree_num, 2);
    for (short i = 0; i < this->tech_player_tree_num; i++) {
        rge_write(param_1, &this->tech_player_tree[i], 4);
        rge_write(param_1, &this->tech_player_tree[i].state, 2);
    }
}

void TRIBE_Player_Tech::enable(short param_1) {
    // Source of truth: bucket_050D.cpp.decomp @ 0x0050D383
    if (param_1 < 0) {
        for (int i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state == -1) {
                this->tech_player_tree[i].state = 0;
            }
        }
    } else if (this->tech_player_tree[param_1].state == -1) {
        this->tech_player_tree[param_1].state = 0;
    }
}

void TRIBE_Player_Tech::disable(short param_1) {
    // Source of truth: bucket_050D.cpp.decomp @ 0x0050D306
    if (param_1 < 0) {
        for (int i = 0; i < this->tech_player_tree_num; i++) {
            if (this->tech_player_tree[i].state != 3) {
                this->tech_player_tree[i].state = -1;
            }
        }
    } else if (this->tech_player_tree[param_1].state != 3) {
        this->tech_player_tree[param_1].state = -1;
    }
}
