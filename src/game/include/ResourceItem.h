#pragma once
#include "common.h"

class ResourceItem {
public:
    ResourceItem();
    ResourceItem(int param_1);
    ResourceItem(int param_1, int* param_2);
    ResourceItem(const ResourceItem& param_1);
    ResourceItem(ResourceItem* param_1);

    // Virtuals (best-effort)
    virtual ~ResourceItem(); // vt[0] (0x0)

    ResourceItem& operator+=(const ResourceItem& param_1);
    int value(int param_1) const;
    void setValue(int param_1, int param_2);
    void incrementValue(int param_1, int param_2);
    void setAllValues(int param_1);
    int number() const;
    int largestValueIndex(int param_1);

protected:
    int sortLarge();

public:
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;
};

int operator==(const ResourceItem& param_1, const ResourceItem& param_2);
int operator!=(const ResourceItem& param_1, const ResourceItem& param_2);

static_assert(sizeof(ResourceItem) == 0x70, "Size mismatch");
