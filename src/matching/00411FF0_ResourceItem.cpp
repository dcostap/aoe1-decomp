// ResourceItem::ResourceItem(const ResourceItem&)
// VA: 00411FF0 | airesitm.cpp:78-84
//
// BINARY NOTE: the copied value lane uses the source/destination address
// difference.  The two sorted lanes use the source sorted-index array.

ResourceItem::ResourceItem(const ResourceItem& src) {
    int i;
    i = 0;
    this->next = 0;
    this->prev = 0;
    this->numberValue = src.numberValue;
    if (this->numberValue > 0) {
        while (1) {
            if (i >= 8) {
                break;
            }
            this->valueValue[i] = src.valueValue[i];
            this->sortedValue[i] = src.sortedValue[i];
            this->sortedIndexValue[i] = src.sortedIndexValue[i];
            i = i + 1;
            if (i >= this->numberValue) {
                break;
            }
        }
    }
}
