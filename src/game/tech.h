#pragma once
#include "common.h"

class TRIBE_Player_Tech {
public:
    Tech_Player_Tree* tech_player_tree;      // 0x0
    short tech_player_tree_num;              // 0x4
    TRIBE_Tech* base_tech;                   // 0x8
    RGE_Player* owner;                       // 0xC

    TRIBE_Player_Tech(int param_1, TRIBE_Tech* param_2, RGE_Player* param_3, uchar param_4);
    TRIBE_Player_Tech(TRIBE_Tech* param_1, RGE_Player* param_2, uchar param_3);
    ~TRIBE_Player_Tech();
    short get_tech_state(short param_1);
    uchar undo_tech(short param_1);
    uchar do_tech(short param_1);
    uchar research(short param_1, float param_2);
    void tech_cost(short param_1, short* param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7);
    uchar check_tech_cost(short param_1, short* param_2);
    uchar start_research(short param_1, uchar param_2, short* param_3);
    uchar cancel_research(short param_1, uchar param_2);
    uchar check_for_new_tech();
    void save(int param_1);
    short get_progress(short param_1);
    char* get_name(short param_1);
    short get_string_id(short param_1);
    short get_string_id2(short param_1);
    uchar get_button_location(short param_1);
    void do_rev_tech(short param_1);
    uchar rev_tech(short param_1);
    void disable(short param_1);
    void enable(short param_1);
    long get_help_message(short param_1);
    long get_help_page(short param_1);
    long get_hotkey(short param_1);
};

static_assert(sizeof(TRIBE_Player_Tech) == 0x10, "TRIBE_Player_Tech Size Mismatch");

class TRIBE_Tech {
public:
    Tech_Tree* tech_tree;                    // 0x0
    short tech_tree_num;                     // 0x4
    TRIBE_World* world;                      // 0x8

    TRIBE_Tech(int param_1, TRIBE_World* param_2);
    TRIBE_Tech(char* param_1);
    ~TRIBE_Tech();
    uchar do_tech(short param_1, RGE_Player* param_2);
    void save(int param_1);
    long get_help_message(short param_1);
    long get_help_page(short param_1);
    long get_hotkey(short param_1);
};

static_assert(sizeof(TRIBE_Tech) == 0xC, "TRIBE_Tech Size Mismatch");
