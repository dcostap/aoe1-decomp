class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    int largestValueIndex(int index);
    int sortLarge();
};

int ResourceItem::largestValueIndex(int index) {
    if (numberValue < index) {
        return -1;
    }
    if (sortLarge() == 1) {
        return sortedIndexValue[index - 1];
    }
    return -1;
}
