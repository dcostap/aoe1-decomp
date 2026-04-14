class ResourceItem {
public:
    char gap_0[0xC];
    int* arr_C;
    char gap_10[0x5C];
    int count_6C;

    int value(int index);
};

int ResourceItem::value(int index) {
    if (index < 0 || index >= this->count_6C) {
        return -1;
    }
    return this->arr_C[index];
}
