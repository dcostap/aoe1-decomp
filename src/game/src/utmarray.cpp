#include "../include/common.h"

#include <new>

// Fully verified. Source of truth: utmarray.cpp.decomp @ 0x00408D20
template <>
ManagedArray<int>::~ManagedArray() {
    if (this->value != nullptr) {
        ::operator delete(this->value);
        this->value = nullptr;
    }
    this->numberValue = 0;
    this->desiredNumberValue = 0;
    this->maximumSizeValue = 0;
}

// Fully verified. Source of truth: utmarray.cpp.decomp @ 0x004147A0
template <>
int ManagedArray<int>::resize(int param_1) {
    int* new_values = (int*)::operator new((size_t)param_1 * sizeof(int), std::nothrow);
    if (new_values == nullptr) {
        return 0;
    }

    int i = 0;
    if (this->maximumSizeValue > 0) {
        while (i < this->maximumSizeValue) {
            if (param_1 <= i) {
                break;
            }
            new_values[i] = this->value[i];
            i = i + 1;
        }
    }

    ::operator delete(this->value);
    this->value = new_values;
    this->maximumSizeValue = param_1;
    return 1;
}

// Fully verified. Source of truth: utmarray.cpp.decomp @ 0x004DE980
template <>
int ManagedArray<int>::contains(const int& param_1) {
    int i = 0;
    if (0 < this->numberValue) {
        while (i < this->maximumSizeValue) {
            if (this->value[i] == param_1) {
                return 1;
            }
            i = i + 1;
            if (this->numberValue <= i) {
                return 0;
            }
        }
    }
    return 0;
}

// Fully verified. Source of truth: utmarray.cpp.decomp @ 0x004DE9D0
template <>
int ManagedArray<int>::add(int param_1) {
    int i = 0;
    int count = this->numberValue;
    if (0 < count) {
        do {
            if (this->maximumSizeValue <= i) {
                break;
            }
            if (this->value[i] == param_1) {
                return 0;
            }
            i = i + 1;
        } while (i < count);
    }

    if (this->maximumSizeValue - 1 < count) {
        int new_size = count + 1;
        int* new_values = (int*)::operator new((size_t)new_size * sizeof(int), std::nothrow);
        if (new_values != nullptr) {
            i = 0;
            if (0 < this->maximumSizeValue) {
                while (i < this->maximumSizeValue) {
                    if (new_size <= i) {
                        break;
                    }
                    new_values[i] = this->value[i];
                    i = i + 1;
                }
            }
            ::operator delete(this->value);
            this->value = new_values;
            this->maximumSizeValue = new_size;
        }
    }

    this->value[this->numberValue] = param_1;
    this->numberValue = this->numberValue + 1;
    return 1;
}

// Fully verified. Source of truth: utmarray.cpp.decomp @ 0x004EA750
template <>
int& ManagedArray<int>::operator[](int param_1) {
    if (this->maximumSizeValue - 1 < param_1) {
        int new_size = param_1 + 1;
        int* new_values = (int*)::operator new((size_t)new_size * sizeof(int), std::nothrow);
        if (new_values != nullptr) {
            int i = 0;
            if (0 < this->maximumSizeValue) {
                while (i < this->maximumSizeValue) {
                    if (new_size <= i) {
                        break;
                    }
                    new_values[i] = this->value[i];
                    i = i + 1;
                }
            }
            ::operator delete(this->value);
            this->value = new_values;
            this->maximumSizeValue = new_size;
        }
    }
    return this->value[param_1];
}

// Fully verified. Source of truth: utmarray.cpp.decomp @ 0x004F1390
template <>
int ManagedArray<int>::remove(int param_1) {
    int size = this->maximumSizeValue;
    int index = 0;
    if (0 < size) {
        int* current = this->value;
        do {
            if (*current == param_1) {
                break;
            }
            index = index + 1;
            current = current + 1;
        } while (index < size);
    }

    if (size <= index) {
        return 0;
    }

    if (index < size - 1) {
        while (index < this->maximumSizeValue - 1) {
            int next_index = index + 1;
            this->value[index] = this->value[next_index];
            index = next_index;
        }
    }

    int new_count = this->numberValue - 1;
    this->numberValue = new_count;
    if (new_count < 0) {
        this->numberValue = 0;
    }
    return 1;
}
