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
    int i = 0;

    if (count > 0) {
        do {
            if (i < 8) {
                this->valueValue[i] = values[i];
                this->sortedValue[i] = -1;
                this->sortedIndexValue[i] = -1;
                ++i;
            } else {
                goto done;
            }
        } while (i < this->numberValue);
    }

    if (i < 8) {
        int* dst = this->sortedValue + i;
        int remaining = 8 - i;
        do {
            dst[-8] = -1;
            *dst = -1;
            dst[8] = -1;
            ++dst;
            --remaining;
        } while (remaining != 0);
    }

done:
    ;
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
    const ResourceItem& lhs = left;
    int count = lhs.numberValue;
    if (count == right.numberValue) {
        for (int i = 0; i < count; ++i) {
            if (lhs.valueValue[i] != right.valueValue[i]) {
                goto not_equal;
            }
        }

        return 1;
    }

not_equal:
    return 0;
}

int operator!=(const ResourceItem& left, const ResourceItem& right) {
    const ResourceItem* lhs = &left;
    const ResourceItem* rhs = &right;
    int count = lhs->numberValue;
    if (count == rhs->numberValue) {
        for (int i = 0; i < count; ++i) {
            if (lhs->valueValue[i] != rhs->valueValue[i]) {
                goto not_equal;
            }
        }

        return 0;
    }

not_equal:
    return 1;
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
