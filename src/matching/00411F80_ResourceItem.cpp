// ResourceItem::ResourceItem(int, int*)
// VA: 00411F80 | airesitm.cpp:59-70
//
// BINARY NOTE: the first fill loop keeps its capacity guard before the three
// stores and shares the final exit with the tail fill path.  The second loop
// fills the remaining lanes with -1.
// BINARY NOTE: In the authentic TU, VC5 emits the two independent induction
// updates in reverse order at +0x3B and +0x3E. Natural update forms tested in
// this TU changed other body bytes, so this source remains the clean baseline.

ResourceItem::ResourceItem(int count, int* source)
    : next(0), prev(0), numberValue(count) {
    int i = 0;

    if (count > 0) {
        do {
            if (i < 8) {
                this->valueValue[i] = *source;
                this->sortedValue[i] = -1;
                this->sortedIndexValue[i] = -1;
                ++i;
                ++source;
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
