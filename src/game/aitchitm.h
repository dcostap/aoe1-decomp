#pragma once
#include "../common.h"

class TechnologyItem {
public:
    TechnologyItem* next;                    // 0x4
    TechnologyItem* prev;                    // 0x8
    int idValue;                             // 0xC
    char nameValue[64];                      // 0x10
    ResourceItem* resourceCostValue;         // 0x50

    TechnologyItem();
    TechnologyItem(int param_1, char* param_2, ResourceItem param_3);
    TechnologyItem(TechnologyItem* param_1);
    virtual ~TechnologyItem();
    virtual int id();
    virtual char* name();
    virtual ResourceItem* resourceCost();
};

static_assert(sizeof(TechnologyItem) == 0x54, "TechnologyItem Size Mismatch");
static_assert(offsetof(TechnologyItem, resourceCostValue) == 0x50, "TechnologyItem Offset Mismatch");

