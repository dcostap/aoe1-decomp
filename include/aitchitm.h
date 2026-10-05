#ifndef AOE1_AITCHITM_H
#define AOE1_AITCHITM_H

#include "airesitm.h"

extern char s_empty_string[];

class TechnologyItem {
  public:
    virtual ~TechnologyItem();

    TechnologyItem();
    TechnologyItem(int i, char* n, ResourceItem r);
    TechnologyItem(const TechnologyItem& ti);

    int id() const;
    char* name();
    ResourceItem* resourceCost();

    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[0x40];
    ResourceItem* resourceCostValue;
};

typedef char aitchitm_technology_item_size[(sizeof(TechnologyItem) == 0x54) ? 1 : -1];

int __cdecl operator==(const TechnologyItem& one, const TechnologyItem& two);
int __cdecl operator!=(const TechnologyItem& one, const TechnologyItem& two);
int __cdecl operator<(const TechnologyItem& one, const TechnologyItem& two);
int __cdecl operator>(const TechnologyItem& one, const TechnologyItem& two);

#endif
