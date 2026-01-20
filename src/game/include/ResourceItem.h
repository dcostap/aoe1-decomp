#pragma once
#include "common.h"

class ResourceItem {
public:
    // Virtuals (best-effort)
    virtual ~ResourceItem(); // vt[0] (0x0)

    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;
};
static_assert(sizeof(ResourceItem) == 0x70, "Size mismatch");
