#include <string.h>

#include "../include/aitchitm.h"

TechnologyItem::TechnologyItem()
    : next(0), prev(0), idValue(0), resourceCostValue(0) {
    strcpy(this->nameValue, s_592A40);
}

TechnologyItem::TechnologyItem(int i, char* n, ResourceItem r)
    : next(0), prev(0), idValue(i) {
    this->resourceCostValue = new ResourceItem(r);
    strcpy(this->nameValue, n);
}

TechnologyItem::TechnologyItem(const TechnologyItem& ti)
    : next(0), prev(0), idValue(ti.idValue) {
    this->resourceCostValue = new ResourceItem(ti.resourceCostValue);
    strcpy(this->nameValue, ti.nameValue);
}

TechnologyItem::~TechnologyItem() {
    if (this->resourceCostValue != 0) {
        delete this->resourceCostValue;
    }
}

int __cdecl operator==(TechnologyItem const& one, TechnologyItem const& two) {
    return one.idValue == two.idValue;
}

int __cdecl operator!=(TechnologyItem const& one, TechnologyItem const& two) {
    return one.idValue != two.idValue;
}

int __cdecl operator<(TechnologyItem const& one, TechnologyItem const& two) {
    return one.idValue < two.idValue;
}

int __cdecl operator>(TechnologyItem const& one, TechnologyItem const& two) {
    return one.idValue > two.idValue;
}

int TechnologyItem::id() const { return this->idValue; }

char* TechnologyItem::name() { return this->nameValue; }

ResourceItem* TechnologyItem::resourceCost() { return this->resourceCostValue; }
