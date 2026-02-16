#pragma once
#include "common.h"
#include "Tech_Player_Tree.h"

struct TRIBE_Player_Tech {
    TRIBE_Player_Tech(int param_1, TRIBE_Tech* param_2, RGE_Player* param_3, uchar param_4);
    TRIBE_Player_Tech(TRIBE_Tech* param_1, RGE_Player* param_2, uchar param_3);
    ~TRIBE_Player_Tech();

    short get_tech_state(short param_1);
    uchar check_tech_cost(short param_1, short* param_2);
    uchar start_research(short param_1, uchar param_2, short* param_3);
    uchar do_tech(short param_1);
    uchar undo_tech(short param_1);
    void do_rev_tech(short param_1);
    uchar rev_tech(short param_1);
    uchar research(short param_1, float param_2);
    void tech_cost(short param_1, short* param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7);
    void check_for_new_tech();
    void save(int param_1);
    void enable(short param_1);
    void disable(short param_1);

    Tech_Player_Tree* tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech* base_tech;
    RGE_Player* owner;
};
static_assert(sizeof(TRIBE_Player_Tech) == 0x10, "Size mismatch");
