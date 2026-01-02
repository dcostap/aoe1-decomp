#pragma once
#include "../common.h"

class TRIBE_Tech {
public:
    short tech_tree_num;                     // 0x4
    TRIBE_World* world;                      // 0x8

    TRIBE_Tech(int param_1, TRIBE_World* param_2);
    TRIBE_Tech(char* param_1);
    virtual ~TRIBE_Tech();
    virtual uchar do_tech(short param_1, RGE_Player* param_2);
    virtual void save(int param_1);
    virtual long get_help_message(short param_1);
    virtual long get_help_page(short param_1);
    virtual long get_hotkey(short param_1);
};

static_assert(sizeof(TRIBE_Tech) == 0xC, "TRIBE_Tech Size Mismatch");
static_assert(offsetof(TRIBE_Tech, world) == 0x8, "TRIBE_Tech Offset Mismatch");

