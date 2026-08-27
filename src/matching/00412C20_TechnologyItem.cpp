// EH-framed constructor with /GX

#include <string.h>

#include "../../include/aitchitm_context.h"

TechnologyItem::TechnologyItem(int id, char* name, ResourceItem cost)
    : next(0), prev(0), idValue(id) {
    this->resourceCostValue = new ResourceItem(cost);
    strcpy(this->nameValue, name);
}
