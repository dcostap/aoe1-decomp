// ResourceItem::largestValueIndex(int)
// VA: 00412210 | airesitm.cpp:188-195

int ResourceItem::largestValueIndex(int index) {
    if (numberValue < index) {
        return -1;
    }
    if (sortLarge() == 1) {
        return sortedIndexValue[index - 1];
    }
    return -1;
}
