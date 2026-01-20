#pragma once
#include "common.h"

struct RGE_Action_Node {
    RGE_Action* action;
    RGE_Action_Node* next;
};
static_assert(sizeof(RGE_Action_Node) == 0x8, "Size mismatch");
