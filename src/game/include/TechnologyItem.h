#pragma once
#include "common.h"

class TechnologyItem {
public:
    // Virtuals (best-effort)
    virtual ~TechnologyItem(); // vt[0] (0x0)

    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[64];
    ResourceItem* resourceCostValue;
};
static_assert(sizeof(TechnologyItem) == 0x54, "Size mismatch");
