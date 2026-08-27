#include "../../include/aitchitm_context.h"

int __cdecl operator>(TechnologyItem const& lhs, TechnologyItem const& rhs) {
    return lhs.idValue > rhs.idValue;
}
