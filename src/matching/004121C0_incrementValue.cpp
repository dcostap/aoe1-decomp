// ResourceItem::incrementValue(int, int)
// VA: 004121C0 | airesitm.cpp:164-168

void ResourceItem::incrementValue(int index, int value) {
    if (index >= 0 && index < numberValue) {
        valueValue[index] += value;
    }
}
