#include "../../include/aibitm_context.h"

int __cdecl operator!=(const BaseItem& lhs, const BaseItem& rhs) {
    return !operator==(lhs, rhs);
}
