#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;
};
static_assert(sizeof(RGE_RMM_Cliffs_Generator) == 0x508, "Size mismatch");
