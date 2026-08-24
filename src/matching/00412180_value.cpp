// ResourceItem::value(int) const
// VA: 00412180 | airesitm.cpp:146-150

int ResourceItem::value(int index) const {
    if (index < 0 || index >= this->numberValue) {
        return -1;
    }
    return this->valueValue[index];
}
