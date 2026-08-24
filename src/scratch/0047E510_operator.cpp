#include "../../include/point_context.h"

XYZ& XYZ::operator=(const XYZ& other) {
    this->xValue = other.xValue;
    this->yValue = other.yValue;
    this->zValue = other.zValue;
    return *this;
}
