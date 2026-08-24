// ResourceItem::setValue(int, int)
// VA: 004121A0 | airesitm.cpp:155-159

void ResourceItem::setValue(int index, int value) {
    if (index >= 0 && index < numberValue) {
        valueValue[index] = value;
    }
}
