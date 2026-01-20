#pragma once
#include "common.h"

struct RGE_Check_Node {
    RGE_Static_Object* node;
    float dx;
    float dy;
    uchar flag;
    RGE_Check_Node* next;
};
static_assert(sizeof(RGE_Check_Node) == 0x14, "Size mismatch");
