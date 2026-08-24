#include "../../include/aiconitm_context.h"

int __cdecl operator<(const ConstructionItem& left,
                      const ConstructionItem& right) {
    return left.typeIDValue < right.typeIDValue;
}
