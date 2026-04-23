#include <string.h>

class ResourceItem;

class TechnologyItem {
public:
    void* vftable;
    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[0x40];
    ResourceItem* resourceCostValue;

    TechnologyItem();
};

extern char s_592A40[];

TechnologyItem::TechnologyItem() {
    this->next = 0;
    this->prev = 0;
    this->idValue = 0;
    this->resourceCostValue = 0;
    this->vftable = (void*)0x0056EA94;
    strcpy(this->nameValue, s_592A40);
}
