// Authentic airesitm.cpp translation-unit context.
//
// The PDB source module is C:\\msdev\\work\\age1_x1\\airesitm.cpp.  Its
// ResourceItem owners appear in constructor, destructor, operator, accessor,
// and sorting order in src/airesitm_tu.cpp.  The executable proves a 0x70-byte
// polymorphic object with three eight-element integer arrays.

#ifndef AOE1_AIRESITM_CONTEXT_H
#define AOE1_AIRESITM_CONTEXT_H

class ResourceItem {
public:
    virtual ~ResourceItem();

    ResourceItem* next;          // +0x04
    ResourceItem* prev;          // +0x08
    int valueValue[8];           // +0x0C
    int sortedValue[8];          // +0x2C
    int sortedIndexValue[8];     // +0x4C
    int numberValue;             // +0x6C

    ResourceItem();
    ResourceItem(int count);
    ResourceItem(int count, int* source);
    ResourceItem(const ResourceItem& source);
    ResourceItem(ResourceItem* source);

    ResourceItem& operator+=(const ResourceItem& source);
    int value(int index) const;
    void setValue(int index, int value);
    void incrementValue(int index, int value);
    void setAllValues(int value);
    int number() const;
    int largestValueIndex(int index);

protected:
    int sortLarge();
};

typedef char airesitm_resource_item_size[
    (sizeof(ResourceItem) == 0x70) ? 1 : -1];
typedef char airesitm_resource_item_pointer_width[
    (sizeof(void*) == 4) ? 1 : -1];

#endif
