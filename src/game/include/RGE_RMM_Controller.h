#pragma once
#include "common.h"
#include "RGE_Random_Map_Module.h"

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    // Virtuals (best-effort)
    virtual uchar generate(); // vt[0] (0x0)

};
static_assert(sizeof(RGE_RMM_Controller) == 0x30, "Size mismatch");
