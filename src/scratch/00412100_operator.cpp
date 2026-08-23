class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;
};

int operator==(const ResourceItem& lhs, const ResourceItem& rhs) {
    if (lhs.numberValue == rhs.numberValue) {
        for (int i = 0; i < lhs.numberValue; ++i) {
            if (lhs.valueValue[i] != rhs.valueValue[i]) {
                goto not_equal;
            }
        }

        return 1;
    }

not_equal:
    return 0;
}
