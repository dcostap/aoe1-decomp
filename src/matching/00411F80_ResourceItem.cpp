// ResourceItem::ResourceItem(int, int*)
// VA: 00411F80 | airesitm.cpp:59-70
//
// BINARY NOTE: the first fill loop keeps its capacity guard before the three
// stores.  The second loop fills the remaining lanes with -1.

ResourceItem::ResourceItem(int count, int* source) {
    int i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = count;

    if (count > 0) {
        int* dst = this->sortedValue;
        do {
            if (i < 8) {
                int v = *source;
                ++i;
                dst[-8] = v;
                dst[0] = -1;
                dst[8] = -1;
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
