#include "../../include/aiblditm_context.h"

int __cdecl operator==(const BuildItem& left, const BuildItem& right) {
    return left.typeIDValue == right.typeIDValue;
}
