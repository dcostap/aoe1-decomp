// VA: 00412CD0 TechnologyItem::TechnologyItem(const TechnologyItem&)
// aitchitm.cpp lines 46-49
// EH-framed copy constructor with /GX

// attempt 1: natural C++ copy constructor, strcpy for name, new ResourceItem(ptr)
// attempt 2: added full ResourceItem class layout for correct sizeof(0x70)

#include <string.h>

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem();
    ResourceItem(const ResourceItem& src);
    ResourceItem(ResourceItem* src);

    ResourceItem* next;
    ResourceItem* prev;
    int field_0C[8];
    int sortedValue[8];
    int field_4C[8];
    int field_6C;
};

class TechnologyItem {
public:
    void* vftable;
    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[0x40];
    ResourceItem* resourceCostValue;

    TechnologyItem(const TechnologyItem& src);
};

// 00412CD0 - 147 bytes
TechnologyItem::TechnologyItem(const TechnologyItem& src) {
    this->next = 0;
    this->prev = 0;
    this->idValue = src.idValue;
    this->vftable = (void*)0x0056EA94;
    this->resourceCostValue = new ResourceItem(src.resourceCostValue);
    strcpy(this->nameValue, src.nameValue);
}
