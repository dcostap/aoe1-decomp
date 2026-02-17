#pragma once
#include "common.h"

class RGE_Object_List {
public:
    // Virtuals (best-effort)
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // vt[0] (0x0)
    void update();

    RGE_Object_Node* list;
    short number_of_objects;
};
static_assert(sizeof(RGE_Object_List) == 0xC, "Size mismatch");
