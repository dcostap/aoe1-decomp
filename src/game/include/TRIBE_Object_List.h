#pragma once
#include "common.h"
#include "RGE_Object_List.h"

class TRIBE_Object_List : public RGE_Object_List {
public:
    // Virtuals (best-effort)
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // vt[0] (0x0)

};
static_assert(sizeof(TRIBE_Object_List) == 0xC, "Size mismatch");
