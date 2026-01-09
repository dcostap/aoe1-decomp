#pragma once
#include "common.h"

class ManagedArray<int> {
public:
    int* value;                              // 0x0
    int numberValue;                         // 0x4
    int desiredNumberValue;                  // 0x8
    int maximumSizeValue;                    // 0xC

    ~ManagedArray<int>();
    int resize(int param_1);
    int contains(int* param_1);
    int add(int param_1);
    int* operator[](int param_1);
    int remove(int param_1);
};

static_assert(sizeof(ManagedArray<int>) == 0x10, "ManagedArray<int> Size Mismatch");

