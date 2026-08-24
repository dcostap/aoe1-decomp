#include "../../include/point_context.h"

XYZ XYZ::operator-(XYZ const& param_1) const {
    XYZ newP(this->xValue - param_1.xValue, this->yValue - param_1.yValue, this->zValue - param_1.zValue);
    return newP;
}
