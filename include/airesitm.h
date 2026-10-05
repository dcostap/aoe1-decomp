#ifndef AOE1_AIRESITM_H
#define AOE1_AIRESITM_H

class ResourceItem {
  public:
    virtual ~ResourceItem();

    ResourceItem();
    ResourceItem(int n);
    ResourceItem(int n, int* v);
    ResourceItem(const ResourceItem& ri);
    ResourceItem(ResourceItem* ri);

    ResourceItem& operator+=(const ResourceItem& ri);
    int value(int n) const;
    void setValue(int n, int v);
    void incrementValue(int n, int v);
    void setAllValues(int v);
    int number() const;
    int largestValueIndex(int num);

    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

  protected:
    int sortLarge();
};

typedef char airesitm_resource_item_size[(sizeof(ResourceItem) == 0x70) ? 1 : -1];
typedef char airesitm_resource_item_pointer_width[(sizeof(void*) == 4) ? 1 : -1];

int operator==(const ResourceItem& one, const ResourceItem& two);
int operator!=(const ResourceItem& one, const ResourceItem& two);

#endif
