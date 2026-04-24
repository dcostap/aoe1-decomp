// attempt 1: array class, .text 80 instead of 82
// attempt 2: const ref, still 80
// attempt 3: include stdlib, still 80
// attempt 4: /GX, still 80
// attempt 5: /G5, still 80
// attempt 6: raw pointer casts, 82 bytes but entirely different codegen
// left in scratch: same delta-based addressing issue as 00411FF0 (const copy ctor)
// original uses sub ecx,eax / mov ebx,[ecx+edx] pattern VC5 doesn't generate
// behavior fully correct: non-const ptr copy ctor, zeros next/prev, copies numberValue
// loop copies 3 values per iteration

class ResourceItem {
public:
    void* vftable;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int val_2c[15];
    int numberValue;
    int sortedIndexValue[16];

    ResourceItem(ResourceItem* src);
};

ResourceItem::ResourceItem(ResourceItem* src) {
    next = 0;
    prev = 0;
    numberValue = src->numberValue;
    if (numberValue > 0) {
        int i = 0;
        do {
            if (i >= 8) break;
            valueValue[i] = src->valueValue[i];
            val_2c[i] = src->val_2c[i];
            sortedIndexValue[i] = src->sortedIndexValue[i];
            i++;
        } while (i < numberValue);
    }
}
