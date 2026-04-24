// attempt 1: array-based class, .text 80 instead of 82
// attempt 2: simpler class, .text 64 (too small)
// attempt 3: two-region model, still 80
// attempt 4: explicit pointer math, 82 bytes but completely different codegen
// left in scratch: original uses delta-based addressing (sub ecx,eax; mov ebx,[ecx+edx])
// that VC5 doesn't generate from any natural source shape tried
// behavior fully correct: copy constructor, zeros next/prev, copies numberValue
// loop copies 3 values per iteration (valueValue[i], val_2c[i], sortedIndexValue[i])
// remaining gap: codegen basin not found, prologue and loop structure differ

class ResourceItem {
public:
    void* vftable;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int val_2c[15];
    int numberValue;
    int sortedIndexValue[16];

    ResourceItem(const ResourceItem& src);
};

ResourceItem::ResourceItem(const ResourceItem& src) {
    next = 0;
    prev = 0;
    numberValue = src.numberValue;
    if (numberValue > 0) {
        int i = 0;
        do {
            if (i >= 8) break;
            valueValue[i] = src.valueValue[i];
            val_2c[i] = src.val_2c[i];
            sortedIndexValue[i] = src.sortedIndexValue[i];
            i++;
        } while (i < numberValue);
    }
}
