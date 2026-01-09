#pragma once
#include "common.h"

class TRIBE_Object_List {
public:
    char _pad_0x0[0xC];

    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // vt0[0]+0x0=0x511B00
};

static_assert(sizeof(TRIBE_Object_List) == 0xC, "TRIBE_Object_List Size Mismatch");

