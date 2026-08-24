// ResourceItem::operator+=(const ResourceItem&)
// VA: 004120C0 | airesitm.cpp:109-115

ResourceItem& ResourceItem::operator+=(const ResourceItem& other) {
    if (numberValue == other.numberValue) {
        for (int i = 0; i < numberValue; ++i) {
            valueValue[i] += other.valueValue[i];
        }
    }
    return *this;
}
