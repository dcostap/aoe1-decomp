#include "../include/airesitm.h"

ResourceItem::ResourceItem()
    : next(0), prev(0), numberValue(0) {
    for (int i = 0; i < 8; ++i) {
        valueValue[i] = -1;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }
}

ResourceItem::ResourceItem(int count)
    : next(0), prev(0), numberValue(count) {
    int i;

    for (i = 0; i < count && i < 8; ++i) {
        valueValue[i] = 0;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }

    for (; i < 8; ++i) {
        valueValue[i] = -1;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }
}

ResourceItem::ResourceItem(int count, int* values)
    : next(0), prev(0), numberValue(count) {
    int i;

    for (i = 0; i < count && i < 8; ++i) {
        valueValue[i] = values[i];
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }

    for (; i < 8; ++i) {
        valueValue[i] = -1;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }
}

ResourceItem::ResourceItem(const ResourceItem& source)
    : next(0), prev(0), numberValue(source.numberValue) {
    for (int i = 0; i < numberValue && i < 8; ++i) {
        valueValue[i] = source.valueValue[i];
        sortedValue[i] = source.sortedValue[i];
        sortedIndexValue[i] = source.sortedIndexValue[i];
    }
}

ResourceItem::ResourceItem(ResourceItem* source)
    : next(0), prev(0), numberValue(source->numberValue) {
    for (int i = 0; i < numberValue && i < 8; ++i) {
        valueValue[i] = source->valueValue[i];
        sortedValue[i] = source->sortedValue[i];
        sortedIndexValue[i] = source->sortedIndexValue[i];
    }
}

ResourceItem::~ResourceItem() {}

ResourceItem& ResourceItem::operator+=(const ResourceItem& source) {
    if (numberValue == source.numberValue) {
        for (int i = 0; i < numberValue; ++i) {
            valueValue[i] += source.valueValue[i];
        }
    }
    return *this;
}

int operator==(const ResourceItem& left, const ResourceItem& right) {
    if (left.numberValue != right.numberValue) {
        return 0;
    }

    for (int i = 0; i < left.numberValue; ++i) {
        if (left.valueValue[i] != right.valueValue[i]) {
            return 0;
        }
    }

    return 1;
}

int operator!=(const ResourceItem& left, const ResourceItem& right) {
    if (left.numberValue != right.numberValue) {
        return 1;
    }

    for (int i = 0; i < left.numberValue; ++i) {
        if (left.valueValue[i] != right.valueValue[i]) {
            return 1;
        }
    }

    return 0;
}

int ResourceItem::value(int index) const {
    if (index < 0 || index >= numberValue) {
        return -1;
    }
    return valueValue[index];
}

void ResourceItem::setValue(int index, int value) {
    if (index >= 0 && index < numberValue) {
        valueValue[index] = value;
    }
}

void ResourceItem::incrementValue(int index, int value) {
    if (index >= 0 && index < numberValue) {
        valueValue[index] += value;
    }
}

void ResourceItem::setAllValues(int value) {
    for (int i = 0; i < 8; ++i) {
        valueValue[i] = value;
    }
}

int ResourceItem::number() const {
    return numberValue;
}

int ResourceItem::largestValueIndex(int index) {
    if (numberValue < index) {
        return -1;
    }
    if (sortLarge() == 1) {
        return sortedIndexValue[index - 1];
    }
    return -1;
}

int ResourceItem::sortLarge() {
    int i;

    for (i = 0; i < numberValue; ++i) {
        sortedValue[i] = valueValue[i];
        sortedIndexValue[i] = i;
    }

    for (i = 0; i < numberValue; ++i) {
        int maxIndex = i;

        for (int j = i + 1; j < numberValue; ++j) {
            if (sortedValue[j] > sortedValue[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            int value = sortedValue[i];
            sortedValue[i] = sortedValue[maxIndex];
            sortedValue[maxIndex] = value;

            value = sortedIndexValue[i];
            sortedIndexValue[i] = sortedIndexValue[maxIndex];
            sortedIndexValue[maxIndex] = value;
        }
    }

    return 1;
}
