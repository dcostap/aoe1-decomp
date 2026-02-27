#pragma once
#include "common.h"
#include "ResourceItem.h"

class TechnologyItem {
public:
    TechnologyItem();
    TechnologyItem(int param_1, char* param_2, ResourceItem param_3);
    TechnologyItem(const TechnologyItem& param_1);

    // Virtuals (best-effort)
    virtual ~TechnologyItem(); // vt[0] (0x0)

    int id() const;
    char* name();
    ResourceItem* resourceCost();

    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;
    char nameValue[64];
    ResourceItem* resourceCostValue;
};

int operator==(const TechnologyItem& param_1, const TechnologyItem& param_2);
int operator!=(const TechnologyItem& param_1, const TechnologyItem& param_2);
int operator<(const TechnologyItem& param_1, const TechnologyItem& param_2);
int operator>(const TechnologyItem& param_1, const TechnologyItem& param_2);

static_assert(sizeof(TechnologyItem) == 0x54, "Size mismatch");
