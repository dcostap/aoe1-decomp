// VA: 00411F80 | ResourceItem::ResourceItem(int count, int* source) | airesitm.cpp:59-70 | 105 bytes
//
// Best result: 27 positional / 15 edit diff (78/105 bytes identical).
// First mismatch at offset 40. Prologue + init (40 bytes) matches exactly.
// Remaining: instruction scheduling differences (store order, i++ position,
// i>=8 check at loop bottom instead of top). All behavior, reg alloc,
// memory effects match. Equivalent VC5 scheduling drift.

class ResourceItem {
public:
    void* vtable_ptr;            // +0x00
    ResourceItem* next;          // +0x04
    ResourceItem* prev;          // +0x08
    int valueValue[8];           // +0x0C
    int sortedValue[8];          // +0x2C
    int sortedIndexValue[8];     // +0x4C
    int numberValue;             // +0x6C

    ResourceItem(int count, int* source);
};

ResourceItem::ResourceItem(int count, int* source) {
    int i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = count;
    this->vtable_ptr = (void*)0x56E9D0;

    if (count > 0) {
        int* dst = this->sortedValue;
        do {
            if (i >= 8) {
                break;
            }
            dst[-8] = *source;
            *dst = -1;
            dst[8] = -1;
            i++;
            source++;
            dst++;
        } while (i < this->numberValue);
    }

    if (i < 8) {
        int* dst = this->sortedValue + i;
        int remaining = 8 - i;
        do {
            dst[-8] = -1;
            *dst = -1;
            dst[8] = -1;
            dst++;
            remaining--;
        } while (remaining != 0);
    }
}
