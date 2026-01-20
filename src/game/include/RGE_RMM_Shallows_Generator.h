#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module {
public:
    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    RGE_Shallows_Info info;
};
static_assert(sizeof(RGE_RMM_Shallows_Generator) == 0x34C, "Size mismatch");
