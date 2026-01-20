#pragma once
#include "common.h"

class BaseItem {
public:
    // Virtuals (best-effort)
    virtual ~BaseItem(); // vt[0] (0x0)

    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char nameValue[64];
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;
};
static_assert(sizeof(BaseItem) == 0x6C, "Size mismatch");
