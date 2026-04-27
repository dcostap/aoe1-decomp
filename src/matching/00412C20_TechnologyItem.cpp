// VA: 00412C20 TechnologyItem::TechnologyItem(int, char*, ResourceItem)
// aitchitm.cpp lines 35-38
// EH-framed constructor with /GX

// attempt 1: natural C++ with by-value ResourceItem param, strcpy, new ResourceItem(cost)
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

    TechnologyItem(int id, char* name, ResourceItem cost);
};

// 00412C20 - 168 bytes
TechnologyItem::TechnologyItem(int id, char* name, ResourceItem cost) {
    this->next = 0;
    this->prev = 0;
    this->idValue = id;
    this->vftable = (void*)0x0056EA94;
    this->resourceCostValue = new ResourceItem(cost);
    strcpy(this->nameValue, name);
}
