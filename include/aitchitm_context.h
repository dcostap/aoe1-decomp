#ifndef AOE1_AITCHITM_CONTEXT_H
#define AOE1_AITCHITM_CONTEXT_H

// Authentic declaration surface for the PDB source module aitchitm.cpp.
//
// The source order is the four TechnologyItem constructors/destructor, four
// free comparison operators, and three accessors.  ResourceItem is declared
// with the observed 0x70 by-value layout.  The shipped TechnologyItem
// destructor deletes its polymorphic ResourceItem member.

extern char s_592A40[];

class ResourceItem {
public:
    virtual ~ResourceItem();

    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem(const ResourceItem&);
    ResourceItem(ResourceItem*);
};

typedef char aitchitm_resource_item_size[(sizeof(ResourceItem) == 0x70) ? 1 : -1];

class TechnologyItem {
public:
    virtual ~TechnologyItem();

    TechnologyItem();
    TechnologyItem(int, char*, ResourceItem);
    TechnologyItem(const TechnologyItem&);

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

#endif
