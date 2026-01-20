#pragma once
#include "common.h"

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};
static_assert(sizeof(DrawAreaNode) == 0xC, "Size mismatch");
