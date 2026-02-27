#include "../include/TechnologyItem.h"

#include <new>
#include <string.h>

namespace {
const char kEmptyName[] = "";
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412BB0
TechnologyItem::TechnologyItem() {
    this->next = nullptr;
    this->prev = nullptr;
    this->idValue = 0;
    this->resourceCostValue = nullptr;
    strcpy(this->nameValue, kEmptyName);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412C20
TechnologyItem::TechnologyItem(int param_1, char* param_2, ResourceItem param_3) {
    this->next = nullptr;
    this->prev = nullptr;
    this->idValue = param_1;

    ResourceItem* pRVar2 = static_cast<ResourceItem*>(::operator new(sizeof(ResourceItem), std::nothrow));
    if (pRVar2 == nullptr) {
        pRVar2 = nullptr;
    } else {
        pRVar2 = new (pRVar2) ResourceItem(&param_3);
    }
    this->resourceCostValue = pRVar2;
    strcpy(this->nameValue, param_2);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412CD0
TechnologyItem::TechnologyItem(const TechnologyItem& param_1) {
    this->next = nullptr;
    this->prev = nullptr;
    this->idValue = param_1.idValue;

    ResourceItem* pRVar3 = static_cast<ResourceItem*>(::operator new(sizeof(ResourceItem), std::nothrow));
    if (pRVar3 == nullptr) {
        pRVar3 = nullptr;
    } else {
        pRVar3 = new (pRVar3) ResourceItem(param_1.resourceCostValue);
    }
    this->resourceCostValue = pRVar3;
    strcpy(this->nameValue, param_1.nameValue);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412D70
TechnologyItem::~TechnologyItem() {
    if (this->resourceCostValue != nullptr) {
        delete this->resourceCostValue;
    }
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412D90
int operator==(const TechnologyItem& param_1, const TechnologyItem& param_2) {
    return (uint)(param_1.idValue == param_2.idValue);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412DB0
int operator!=(const TechnologyItem& param_1, const TechnologyItem& param_2) {
    return (uint)(param_1.idValue != param_2.idValue);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412DD0
int operator<(const TechnologyItem& param_1, const TechnologyItem& param_2) {
    return (uint)(param_1.idValue < param_2.idValue);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412DF0
int operator>(const TechnologyItem& param_1, const TechnologyItem& param_2) {
    return (uint)(param_2.idValue < param_1.idValue);
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412E10
int TechnologyItem::id() const {
    return this->idValue;
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412E20
char* TechnologyItem::name() {
    return this->nameValue;
}

// Fully verified. Source of truth: aitchitm.cpp.decomp @ 0x00412E30
ResourceItem* TechnologyItem::resourceCost() {
    return this->resourceCostValue;
}
