// VA: 00412CD0 TechnologyItem::TechnologyItem(const TechnologyItem&)
// aitchitm.cpp lines 46-49
// EH-framed copy constructor with /GX

// attempt 1: natural C++ copy constructor, strcpy for name, new ResourceItem(ptr)
// attempt 2: added full ResourceItem class layout for correct sizeof(0x70)

#include <string.h>

#include "../../include/aitchitm_context.h"

// 00412CD0 - 147 bytes
TechnologyItem::TechnologyItem(const TechnologyItem& src)
    : next(0), prev(0), idValue(src.idValue) {
    this->resourceCostValue = new ResourceItem(src.resourceCostValue);
    strcpy(this->nameValue, src.nameValue);
}
