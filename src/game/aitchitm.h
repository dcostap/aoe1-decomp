#pragma once
#include "common.h"

class TechnologyItem {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    TechnologyItem* next;                    // 0x4
    TechnologyItem* prev;                    // 0x8
    int idValue;                             // 0xC
    char nameValue[64];                      // 0x10
    ResourceItem* resourceCostValue;         // 0x50

    TechnologyItem();
    TechnologyItem(int param_1, char* param_2, ResourceItem param_3);
    TechnologyItem(TechnologyItem* param_1);
    ~TechnologyItem();
    int id();
    char* name();
    ResourceItem* resourceCost();
};

static_assert(sizeof(TechnologyItem) == 0x54, "TechnologyItem Size Mismatch");

