#pragma once
#include "common.h"

class TRIBE_Effects : public RGE_Effects {
public:

    virtual void do_effect(short param_1, RGE_Player* param_2); // vt0[2]+0x8=0x50D4D0
    TRIBE_Effects(int param_1);
    ~TRIBE_Effects();
    TRIBE_Effects(char* param_1);
    void do_tech_effect(short param_1, RGE_Player* param_2);
};

static_assert(sizeof(TRIBE_Effects) == 0xC, "TRIBE_Effects Size Mismatch");

