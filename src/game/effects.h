#pragma once
#include "common.h"

class RGE_Effects {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Effect* effects;                     // 0x4
    long effect_num;                         // 0x8

    virtual void save(int param_1);                         // vt0[1]+0x4=0x4494B0
    virtual void do_effect(short param_1, RGE_Player* param_2); // vt0[2]+0x8=0x4495C0
    RGE_Effects(int param_1);
    RGE_Effects(char* param_1);
    ~RGE_Effects();
};

static_assert(sizeof(RGE_Effects) == 0xC, "RGE_Effects Size Mismatch");

