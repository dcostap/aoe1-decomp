#pragma once
#include "../common.h"

class RGE_Effects {
public:
    RGE_Effect* effects;                     // 0x4
    long effect_num;                         // 0x8

    RGE_Effects(int param_1);
    RGE_Effects(char* param_1);
    virtual ~RGE_Effects();
    virtual void save(int param_1);
    virtual void do_effect(short param_1, RGE_Player* param_2);
};

static_assert(sizeof(RGE_Effects) == 0xC, "RGE_Effects Size Mismatch");
static_assert(offsetof(RGE_Effects, effect_num) == 0x8, "RGE_Effects Offset Mismatch");

