class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    void setAllValues(int value);
};

void ResourceItem::setAllValues(int value) {
    for (int i = 0; i < 8; ++i) {
        valueValue[i] = value;
    }
}
