#include "../include/game_globals.h"
#include "../include/point.h"
#include <math.h>

XYZ::XYZ() {
    this->xValue = 0;
    this->yValue = 0;
    this->zValue = 0;
}

XYZ::XYZ(int x, int y, int z) {
    xValue = x;
    yValue = y;
    zValue = z;
}

int __cdecl operator==(const XYZ& a, const XYZ& b) {
    if (a.xValue == b.xValue) {
        if (a.yValue == b.yValue) {
            if (a.zValue == b.zValue) {
                return 1;
            }
        }
    }
    return 0;
}

int __cdecl operator!=(const XYZ& a, const XYZ& b) {
    if (a.xValue == b.xValue) {
        if (a.yValue == b.yValue) {
            if (a.zValue == b.zValue) {
                return 0;
            }
        }
    }
    return 1;
}

XYZ& XYZ::operator=(const XYZ& other) {
    this->xValue = other.xValue;
    this->yValue = other.yValue;
    this->zValue = other.zValue;
    return *this;
}

XYZ XYZ::operator+(const XYZ& other) const {
    XYZ tmp(xValue + other.xValue, yValue + other.yValue, zValue + other.zValue);
    return tmp;
}

XYZ XYZ::operator-(XYZ const& param_1) const {
    XYZ newP(this->xValue - param_1.xValue, this->yValue - param_1.yValue, this->zValue - param_1.zValue);
    return newP;
}

void XYZ::rotateXYByFacet(const XYZ& facet, XYZ& output, unsigned char facet_idx)
{
    output.xValue = this->xValue;
    output.yValue = this->yValue;
    output.zValue = this->zValue;

    if (facet_idx)
    {
        int dx = this->xValue - facet.xValue;
        int dy = this->yValue - facet.yValue;
        float angle = (float)(facet_idx & 0xFF) * 0.7853981852531433f;
        float s = sin(angle);
        float c = cos(angle);
        output.xValue = (int)(c * dx - s * dy);
        // Keep this product separate to preserve the shipped FPU order.
        float y1 = c * dy;
        output.yValue = (int)(y1 + s * dx);
    }
}
