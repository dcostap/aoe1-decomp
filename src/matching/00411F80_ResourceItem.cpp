// VA: 00411F80 | ResourceItem::ResourceItem(int count, int* source) | airesitm.cpp:59-70 | 105 bytes
// Exact match under default flags.
//
// Attempt log:
// - Previous best had exact prologue/init and tail but a 5-byte edit diff in the first
//   fill loop: VC5 moved the `i >= 8` check to the loop bottom, emitted the sorted store
//   before the value store, and delayed `inc esi` until after stores.
// - Tried top-check `return`/`goto done`, while/for forms, indexed array stores, split
//   value/sorted/sortedIndex pointers, and source-order store variants. Most either kept
//   the bottom-check family or regressed to different register allocation.
// - Breakthrough: keeping the top `if (i < 8) { ... } else goto done;` shape and writing
//   all three first-loop stores through volatile int lvalues forced VC5 to preserve the
//   source store order and keep `inc esi` before the stores. This matched exactly.

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
            if (i < 8) {
                int v = *source;
                ++i;
                *(volatile int*)(dst - 8) = v;
                *(volatile int*)dst = -1;
                *(volatile int*)(dst + 8) = -1;
                ++source;
                ++dst;
            } else {
                goto done;
            }
        } while (i < this->numberValue);
    }

    if (i < 8) {
        int* dst = this->sortedValue + i;
        int remaining = 8 - i;
        do {
            dst[-8] = -1;
            *dst = -1;
            dst[8] = -1;
            ++dst;
            --remaining;
        } while (remaining != 0);
    }

done:
    ;
}
