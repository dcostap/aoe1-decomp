// attempt log:
// first pass: natural constructor shape with vptr init, next/prev zero, count save, and the two fill phases
// second pass: switch to the decompiler-shaped do/while form because the first loop basin was slightly too small
// third pass: use sortedValue as the moving pointer base so the three writes land on the observed +/-0x20, 0, +0x20 addresses
// fourth pass: switching back to a top-tested loop changed the register basin too far and blew the diff up
// paused here: the remaining mismatch is still in the first-loop codegen basin / register order around the pointer walk

class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem(int count);
};

ResourceItem::ResourceItem(int count) {
    int i;
    int* p;

    i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = count;
    this->vtable_ptr = (void*)0x56E9D0;

    if (count > 0) {
        p = this->sortedValue;
        do {
            if (i >= 8) {
                return;
            }
            p[-8] = 0;
            p[0] = -1;
            p[8] = -1;
            i = i + 1;
            p = p + 1;
        } while (i < this->numberValue);
    }

    if (i < 8) {
        p = this->sortedValue + i;
        count = 8 - i;
        do {
            p[-8] = -1;
            p[0] = -1;
            p[8] = -1;
            p = p + 1;
            count = count - 1;
        } while (count != 0);
    }
}
