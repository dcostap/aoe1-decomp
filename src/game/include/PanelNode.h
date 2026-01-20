#pragma once
#include "common.h"

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};
static_assert(sizeof(PanelNode) == 0xC, "Size mismatch");
