#pragma once
#include "../common.h"

class ResourceItem {
public:
    ResourceItem* next;                      // 0x4
    ResourceItem* prev;                      // 0x8
    int valueValue[8];                       // 0xC
    int sortedValue[8];                      // 0x2C
    int sortedIndexValue[8];                 // 0x4C
    int numberValue;                         // 0x6C

    ResourceItem();
    ResourceItem(int param_1);
    ResourceItem(int param_1, int* param_2);
    ResourceItem(ResourceItem* param_1);
    ResourceItem(ResourceItem* param_1);
    virtual ~ResourceItem();
    virtual ResourceItem* operator+=(ResourceItem* param_1);
    virtual int value(int param_1);
    virtual void setValue(int param_1, int param_2);
    virtual void incrementValue(int param_1, int param_2);
    virtual void setAllValues(int param_1);
    virtual int number();
    virtual int largestValueIndex(int param_1);
    virtual int sortLarge();
};

static_assert(sizeof(ResourceItem) == 0x70, "ResourceItem Size Mismatch");
static_assert(offsetof(ResourceItem, numberValue) == 0x6C, "ResourceItem Offset Mismatch");

