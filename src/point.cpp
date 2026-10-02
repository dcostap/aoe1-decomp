#include "../include/game_globals.h"
#include "../include/point.h"
#include <math.h>

XYZ::XYZ() {
    this->xValue = 0;
    this->yValue = 0;
    this->zValue = 0;
}

XYZ::XYZ(int a, int b, int c) {
    xValue = a;
    yValue = b;
    zValue = c;
}

int __cdecl operator==(const XYZ& one, const XYZ& two) {
    if (one.xValue == two.xValue) {
        if (one.yValue == two.yValue) {
            if (one.zValue == two.zValue) {
                return 1;
            }
        }
    }
    return 0;
}

int __cdecl operator!=(const XYZ& one, const XYZ& two) {
    if (one.xValue == two.xValue) {
        if (one.yValue == two.yValue) {
            if (one.zValue == two.zValue) {
                return 0;
            }
        }
    }
    return 1;
}

XYZ& XYZ::operator=(const XYZ& p) {
    this->xValue = p.xValue;
    this->yValue = p.yValue;
    this->zValue = p.zValue;
    return *this;
}

XYZ XYZ::operator+(const XYZ& p) const {
    XYZ newP(xValue + p.xValue, yValue + p.yValue, zValue + p.zValue);
    return newP;
}

XYZ XYZ::operator-(XYZ const& p) const {
    XYZ newP(this->xValue - p.xValue, this->yValue - p.yValue, this->zValue - p.zValue);
    return newP;
}

void XYZ::rotateXYByFacet(const XYZ& refPoint, XYZ& rPoint, unsigned char facet) {
    rPoint.xValue = this->xValue;
    rPoint.yValue = this->yValue;
    rPoint.zValue = this->zValue;

    if (facet) {
        int xDiff = this->xValue - refPoint.xValue;
        int yDiff = this->yValue - refPoint.yValue;
        float rotAmount = (float)(facet & 0xFF) * 0.7853982f;
        float s = sin(rotAmount);
        float c = cos(rotAmount);
        rPoint.xValue = (int)(c * xDiff - s * yDiff);
        float y1 = c * yDiff;
        rPoint.yValue = (int)(y1 + s * xDiff);
    }
}
