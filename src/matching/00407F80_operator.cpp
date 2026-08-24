#include "../../include/aibitm_context.h"

int __cdecl operator==(const BaseItem& lhs, const BaseItem& rhs) {
    if (lhs.gameIDValue == rhs.gameIDValue) {
        if (lhs.xValue == rhs.xValue) {
            if (lhs.yValue == rhs.yValue) {
                return 1;
            }
        }
    }
    return 0;
}
