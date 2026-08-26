// VA: 00412C20 TechnologyItem::TechnologyItem(int, char*, ResourceItem)
// aitchitm.cpp lines 35-38
// EH-framed constructor with /GX

// attempt 1: natural C++ with by-value ResourceItem param, strcpy, new ResourceItem(cost)
// attempt 2: added full ResourceItem class layout for correct sizeof(0x70)

#include <string.h>

#include "../../include/aitchitm_context.h"

// 00412C20 - 168 bytes
TechnologyItem::TechnologyItem(int id, char* name, ResourceItem cost)
    : next(0), prev(0), idValue(id) {
    this->resourceCostValue = new ResourceItem(cost);
    strcpy(this->nameValue, name);
}
