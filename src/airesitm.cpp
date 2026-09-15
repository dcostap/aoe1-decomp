#include "../include/airesitm.h"

ResourceItem::ResourceItem()
    : next(0), prev(0), numberValue(0) {
    for (int i = 0; i < 8; ++i) {
        valueValue[i] = -1;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }
}

ResourceItem::ResourceItem(int n)
    : next(0), prev(0), numberValue(n) {
    int i = 0;

    while (i < numberValue) {
        if (i >= 8) {
            return;
        }
        valueValue[i] = 0;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
        i = i + 1;
    }

    for (; i < 8; ++i) {
        valueValue[i] = -1;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }
}

ResourceItem::ResourceItem(int n, int* v)
    : next(0), prev(0), numberValue(n) {
    int i = 0;

    while (i < numberValue) {
        if (i >= 8) {
            return;
        }
        valueValue[i] = v[i];
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
        i = i + 1;
    }

    for (; i < 8; ++i) {
        valueValue[i] = -1;
        sortedValue[i] = -1;
        sortedIndexValue[i] = -1;
    }
}

ResourceItem::ResourceItem(const ResourceItem& ri)
    : next(0), prev(0), numberValue(ri.numberValue) {
    for (int i = 0; i < numberValue && i < 8; ++i) {
        valueValue[i] = ri.valueValue[i];
        sortedValue[i] = ri.sortedValue[i];
        sortedIndexValue[i] = ri.sortedIndexValue[i];
    }
}

ResourceItem::ResourceItem(ResourceItem* ri)
    : next(0), prev(0), numberValue(ri->numberValue) {
    for (int i = 0; i < numberValue && i < 8; ++i) {
        valueValue[i] = ri->valueValue[i];
        sortedValue[i] = ri->sortedValue[i];
        sortedIndexValue[i] = ri->sortedIndexValue[i];
    }
}

ResourceItem::~ResourceItem() {}

ResourceItem& ResourceItem::operator+=(const ResourceItem& ri) {
    if (numberValue == ri.numberValue) {
        for (int i = 0; i < numberValue; ++i) {
            valueValue[i] += ri.valueValue[i];
        }
    }
    return *this;
}

int operator==(const ResourceItem& one, const ResourceItem& two) {
    const ResourceItem& lhs = one;
    int count = lhs.numberValue;
    if (count == two.numberValue) {
        for (int i = 0; i < count; ++i) {
            if (lhs.valueValue[i] != two.valueValue[i]) {
                goto not_equal;
            }
        }

        return 1;
    }

not_equal:
    return 0;
}

int operator!=(const ResourceItem& one, const ResourceItem& two) {
    if (one.numberValue == two.numberValue) {
        for (int i = 0; i < one.numberValue; ++i) {
            if (one.valueValue[i] != two.valueValue[i]) {
                goto not_equal;
            }
        }

        return 0;
    }

not_equal:
    return 1;
}

int ResourceItem::value(int n) const {
    if (n < 0 || n >= numberValue) {
        return -1;
    }
    return valueValue[n];
}

void ResourceItem::setValue(int n, int v) {
    if (n >= 0 && n < numberValue) {
        valueValue[n] = v;
    }
}

void ResourceItem::incrementValue(int n, int v) {
    if (n >= 0 && n < numberValue) {
        valueValue[n] += v;
    }
}

void ResourceItem::setAllValues(int v) {
    for (int i = 0; i < 8; ++i) {
        valueValue[i] = v;
    }
}

int ResourceItem::number() const {
    return numberValue;
}

int ResourceItem::largestValueIndex(int num) {
    if (numberValue < num) {
        return -1;
    }
    if (sortLarge() == 1) {
        return sortedIndexValue[num - 1];
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
