#pragma once
#include "common.h"

class ResourceItem {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
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
    ~ResourceItem();
    ResourceItem* operator+=(ResourceItem* param_1);
    int value(int param_1);
    void setValue(int param_1, int param_2);
    void incrementValue(int param_1, int param_2);
    void setAllValues(int param_1);
    int number();
    int largestValueIndex(int param_1);
    int sortLarge();
};

static_assert(sizeof(ResourceItem) == 0x70, "ResourceItem Size Mismatch");

