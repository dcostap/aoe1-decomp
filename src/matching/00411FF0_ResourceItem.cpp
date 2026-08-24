// ResourceItem::ResourceItem(const ResourceItem&)
// VA: 00411FF0 | airesitm.cpp:78-84
//
// BINARY NOTE: the three link/count fields use the constructor initializer
// list; this preserves the shipped grouped-TU instruction order.
//
// BINARY NOTE: the copied value lane uses the source/destination address
// difference.  The two sorted lanes use the source sorted-index array.

ResourceItem::ResourceItem(const ResourceItem& src)
    : next(0), prev(0), numberValue(src.numberValue) {
    int i;
    i = 0;
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
