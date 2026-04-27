// attempt 1: count+source-pointer constructor with the observed 8-entry fill and tail fill loops
// attempt 2: remove the early return and keep the original break/fallthrough shape; the first basin was too branchy around the loop exit
// attempt 3 rolled back: the explicit loop-condition probe added an extra compare basin, so keep the do/while form and just tighten the write order
// attempt 4: move the loop increment back in front of the stores; that matches the observed post-inc basin and may flip the store order into the original sequence
class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem(int count, int* source);
};

ResourceItem::ResourceItem(int count, int* source) {
    int i;
    int* dst;

    i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = count;
    this->vtable_ptr = (void*)0x56E9D0;
    if (count > 0) {
        dst = this->sortedValue;
        do {
            if (i >= 8) {
                break;
            }
            ++i;
            dst[-8] = *source;
            *dst = -1;
            dst[8] = -1;
            ++source;
            ++dst;
        } while (i < this->numberValue);
    }
    if (i < 8) {
        dst = this->sortedValue + i;
        count = 8 - i;
        do {
            dst[-8] = -1;
            *dst = -1;
            dst[8] = -1;
            ++dst;
            --count;
        } while (count != 0);
    }
}
