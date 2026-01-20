#pragma once
#include "common.h"
#include "RGE_Effects.h"

class TRIBE_Effects : public RGE_Effects {
public:
    // Virtuals (best-effort)
    virtual ~TRIBE_Effects(); // vt[0] (0x0)
    virtual void save(int param_1); // vt[1] (0x4)
    virtual void do_effect(short param_1, RGE_Player* param_2); // vt[2] (0x8)

};
static_assert(sizeof(TRIBE_Effects) == 0xC, "Size mismatch");
