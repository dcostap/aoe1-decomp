// EH-framed copy constructor with /GX

#include <string.h>

#include "../../include/aitchitm_context.h"

TechnologyItem::TechnologyItem(const TechnologyItem& src)
    : next(0), prev(0), idValue(src.idValue) {
    this->resourceCostValue = new ResourceItem(src.resourceCostValue);
    strcpy(this->nameValue, src.nameValue);
}
