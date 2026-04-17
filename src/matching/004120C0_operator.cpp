class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem& operator+=(const ResourceItem& other);
};

ResourceItem& ResourceItem::operator+=(const ResourceItem& other) {
    if (numberValue == other.numberValue) {
        for (int i = 0; i < numberValue; ++i) {
            valueValue[i] += other.valueValue[i];
        }
    }
    return *this;
}
