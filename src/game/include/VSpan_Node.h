#pragma once
#include "common.h"

struct VSpan_Node {
    VSpan_Node* Next;
    VSpan_Node* Prev;
    int StartPx;
    int EndPx;
};
static_assert(sizeof(VSpan_Node) == 0x10, "Size mismatch");
