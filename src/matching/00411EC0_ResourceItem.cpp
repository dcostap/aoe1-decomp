// ResourceItem::ResourceItem()
// VA: 00411EC0 | airesitm.cpp:26-32

ResourceItem::ResourceItem() {
    this->next = 0;
    this->prev = 0;
    this->numberValue = 0;
    for (int i = 0; i < 8; i++) {
        this->valueValue[i] = -1;
        this->sortedValue[i] = -1;
        this->sortedIndexValue[i] = -1;
    }
}
