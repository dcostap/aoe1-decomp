#ifndef AOE1_AIRESITM_H
#define AOE1_AIRESITM_H

class ResourceItem {
public:
    virtual ~ResourceItem();

    ResourceItem();
    ResourceItem(int count);
    ResourceItem(int count, int* values);
    ResourceItem(const ResourceItem& source);
    ResourceItem(ResourceItem* source);

    ResourceItem& operator+=(const ResourceItem& source);
    int value(int index) const;
    void setValue(int index, int value);
    void incrementValue(int index, int value);
    void setAllValues(int value);
    int number() const;
    int largestValueIndex(int index);

    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

protected:
    int sortLarge();
};

typedef char airesitm_resource_item_size[
    (sizeof(ResourceItem) == 0x70) ? 1 : -1];
typedef char airesitm_resource_item_pointer_width[
    (sizeof(void*) == 4) ? 1 : -1];

int operator==(const ResourceItem& left, const ResourceItem& right);
int operator!=(const ResourceItem& left, const ResourceItem& right);

#endif
