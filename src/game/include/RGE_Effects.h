#pragma once
#include "common.h"

class RGE_Effects {
public:
    RGE_Effects(int param_1);
    RGE_Effects(char* param_1);

    // Virtuals (best-effort)
    virtual ~RGE_Effects(); // vt[0] (0x0)
    virtual void save(int param_1); // vt[1] (0x4)
    virtual void do_effect(short param_1, RGE_Player* param_2); // vt[2] (0x8)

    RGE_Effect* effects;
    long effect_num;
};
static_assert(sizeof(RGE_Effects) == 0xC, "Size mismatch");
