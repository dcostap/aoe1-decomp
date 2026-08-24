#include "../../include/point_context.h"

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
