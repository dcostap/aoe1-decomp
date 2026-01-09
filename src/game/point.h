#pragma once
#include "common.h"

class XYZ {
public:
    int xValue;                              // 0x0
    int yValue;                              // 0x4
    int zValue;                              // 0x8

    XYZ();
    XYZ(int param_1, int param_2, int param_3);
    XYZ* operator=(XYZ* param_1);
    XYZ* operator+(XYZ* param_1);
    XYZ* operator-(XYZ* param_1);
    void rotateXYByFacet(XYZ* param_1, XYZ* param_2, uchar param_3);
};

static_assert(sizeof(XYZ) == 0xC, "XYZ Size Mismatch");

