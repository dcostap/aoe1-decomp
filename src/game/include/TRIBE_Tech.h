#pragma once
#include "common.h"
#include "Tech_Tree.h"

class TRIBE_World;

struct TRIBE_Tech {
    TRIBE_Tech(int param_1, TRIBE_World* param_2);
    TRIBE_Tech(char* param_1);
    ~TRIBE_Tech();
    void save(int param_1);
    long get_help_message(short param_1);
    long get_help_page(short param_1);
    long get_hotkey(short param_1);
    void do_tech(short param_1, RGE_Player* param_2);

    Tech_Tree* tech_tree;
    short tech_tree_num;
    TRIBE_World* world;
};
static_assert(sizeof(TRIBE_Tech) == 0xC, "Size mismatch");
