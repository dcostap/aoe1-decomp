#pragma once
#include "common.h"

class RGE_Active_Sprite;

struct RGE_Active_Sprite_Node {
    RGE_Active_Sprite* node;
    uchar order;
    uchar count;
    RGE_Active_Sprite_Node* next;
};
static_assert(sizeof(RGE_Active_Sprite_Node) == 0xC, "Size mismatch");
