class ResourceItem {
public:
    char gap_0[0xC];
    int arr[24];
    int count;

    int value(int index);
};

int ResourceItem::value(int index) {
    if (index < 0 || index >= this->count) {
        return -1;
    }
    return this->arr[index];
}
