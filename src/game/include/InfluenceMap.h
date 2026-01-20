#pragma once
#include "common.h"

class InfluenceMap {
public:
    // Virtuals (best-effort)
    virtual ~InfluenceMap(); // vt[0] (0x0)

    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    uchar* valueValue;
    uchar** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    uchar unchangeableLimitValue;
};
static_assert(sizeof(InfluenceMap) == 0x28, "Size mismatch");
