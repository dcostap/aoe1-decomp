class ResourceItem {
public:
    void* vtable_ptr;
    ResourceItem* next;
    ResourceItem* prev;
    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem(ResourceItem* src);
};

ResourceItem::ResourceItem(ResourceItem* src) {
    int i;
    int* dst;
    int* idx;

    i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = src->numberValue;
    this->vtable_ptr = (void*)0x56E9D0;
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
