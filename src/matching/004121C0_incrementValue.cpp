class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    void incrementValue(int index, int value);
};

void ResourceItem::incrementValue(int index, int value) {
    if (index >= 0 && index < numberValue) {
        valueValue[index] += value;
    }
}
