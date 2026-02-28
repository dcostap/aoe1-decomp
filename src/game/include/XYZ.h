#pragma once
#include "common.h"

struct XYZ {
    int xValue;
    int yValue;
    int zValue;

    XYZ();
    XYZ(int param_1, int param_2, int param_3);
    XYZ& operator=(const XYZ& param_1);
    XYZ operator+(const XYZ& param_1) const;
    XYZ operator-(const XYZ& param_1) const;
    void rotateXYByFacet(const XYZ& param_1, XYZ& param_2, uchar param_3);
};
int operator==(const XYZ& param_1, const XYZ& param_2);
int operator!=(const XYZ& param_1, const XYZ& param_2);
static_assert(sizeof(XYZ) == 0xC, "Size mismatch");
