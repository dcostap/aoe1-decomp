#include <string.h>

#include "../include/aitchitm.h"

TechnologyItem::TechnologyItem()
    : next(0), prev(0), idValue(0), resourceCostValue(0) {
    strcpy(this->nameValue, s_592A40);
}

TechnologyItem::TechnologyItem(int id, char* name, ResourceItem cost)
    : next(0), prev(0), idValue(id) {
    this->resourceCostValue = new ResourceItem(cost);
    strcpy(this->nameValue, name);
}

TechnologyItem::TechnologyItem(const TechnologyItem& src)
    : next(0), prev(0), idValue(src.idValue) {
    this->resourceCostValue = new ResourceItem(src.resourceCostValue);
    strcpy(this->nameValue, src.nameValue);
}

TechnologyItem::~TechnologyItem() {
    if (this->resourceCostValue != 0) {
        delete this->resourceCostValue;
    }
}

int __cdecl operator==(TechnologyItem const& lhs, TechnologyItem const& rhs) {
    return lhs.idValue == rhs.idValue;
}

int __cdecl operator!=(TechnologyItem const& lhs, TechnologyItem const& rhs) {
    return lhs.idValue != rhs.idValue;
}

int __cdecl operator<(TechnologyItem const& lhs, TechnologyItem const& rhs) {
    return lhs.idValue < rhs.idValue;
}

int __cdecl operator>(TechnologyItem const& lhs, TechnologyItem const& rhs) {
    return lhs.idValue > rhs.idValue;
}

int TechnologyItem::id() const { return this->idValue; }

char* TechnologyItem::name() { return this->nameValue; }

ResourceItem* TechnologyItem::resourceCost() { return this->resourceCostValue; }
