#include "../include/XYZ.h"

#include <cmath>

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E480
XYZ::XYZ() {
    this->xValue = 0;
    this->yValue = 0;
    this->zValue = 0;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E490
XYZ::XYZ(int param_1, int param_2, int param_3) {
    this->xValue = param_1;
    this->yValue = param_2;
    this->zValue = param_3;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E4B0
int operator==(const XYZ& param_1, const XYZ& param_2) {
    if (param_1.xValue == param_2.xValue && param_1.yValue == param_2.yValue && param_1.zValue == param_2.zValue) {
        return 1;
    }
    return 0;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E4E0
int operator!=(const XYZ& param_1, const XYZ& param_2) {
    if (param_1.xValue == param_2.xValue && param_1.yValue == param_2.yValue && param_1.zValue == param_2.zValue) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E510
XYZ& XYZ::operator=(const XYZ& param_1) {
    this->xValue = param_1.xValue;
    this->yValue = param_1.yValue;
    this->zValue = param_1.zValue;
    return *this;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E530
XYZ XYZ::operator+(const XYZ& param_1) const {
    XYZ newP(this->xValue + param_1.xValue, this->yValue + param_1.yValue, this->zValue + param_1.zValue);
    return newP;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E580
XYZ XYZ::operator-(const XYZ& param_1) const {
    XYZ newP(this->xValue - param_1.xValue, this->yValue - param_1.yValue, this->zValue - param_1.zValue);
    return newP;
}

// Fully verified. Source of truth: point.cpp.decomp @ 0x0047E5D0
void XYZ::rotateXYByFacet(const XYZ& param_1, XYZ& param_2, uchar param_3) {
    param_2.xValue = this->xValue;
    param_2.yValue = this->yValue;
    param_2.zValue = this->zValue;
    if (param_3 != 0) {
        const int delta_x = this->xValue - param_1.xValue;
        const int delta_y = this->yValue - param_1.yValue;
        const double angle = (double)(param_3 & 0xFF) * 0.7853982;
        const double sin_a = std::sin(angle);
        const double cos_a = std::cos(angle);
        param_2.xValue = (int)std::lround(cos_a * (double)delta_x - sin_a * (double)delta_y);
        param_2.yValue = (int)std::lround(sin_a * (double)delta_x + cos_a * (double)delta_y);
    }
}
