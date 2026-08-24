#include "../../include/aiconitm_context.h"

int __cdecl operator!=(const ConstructionItem& left,
                       const ConstructionItem& right) {
    if (left.xValue == right.xValue && left.yValue == right.yValue) {
        return 0;
    }
    return 1;
}
