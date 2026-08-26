// ResourceItem::ResourceItem(ResourceItem*)
// VA: 00412050 | airesitm.cpp:92-98
// BINARY NOTE: The relative source-value load has one remaining SIB operand
// order difference in the authentic TU: VC5 emits [edx+ecx], while the shipped
// body uses [ecx+edx]. Natural pointer forms tested in this TU changed more.

ResourceItem::ResourceItem(ResourceItem* src)
    : next(0), prev(0), numberValue(src->numberValue) {
    int i;
    int* dst;
    int* idx;

    i = 0;
    if (this->numberValue > 0) {
        idx = src->sortedIndexValue;
        dst = this->valueValue;
        src = (ResourceItem*)((char*)src - (char*)this);
        while (1) {
            if (i >= 8) {
                break;
            }
            dst[0] = *(int*)((char*)src + (int)dst);
            i = i + 1;
            dst[8] = idx[-8];
            dst[16] = idx[0];
            dst = dst + 1;
            idx = idx + 1;
            if (i >= this->numberValue) {
                break;
            }
        }
    }
}
