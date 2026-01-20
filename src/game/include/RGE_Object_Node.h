#pragma once
#include "common.h"

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    uchar centered;
};
static_assert(sizeof(RGE_Object_Node) == 0x10, "Size mismatch");
