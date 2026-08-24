// ResourceItem::setAllValues(int)
// VA: 004121E0 | airesitm.cpp:173-176

void ResourceItem::setAllValues(int value) {
    for (int i = 0; i < 8; ++i) {
        valueValue[i] = value;
    }
}
