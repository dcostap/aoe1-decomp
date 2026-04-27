// 004EA750 ManagedArray<int>::operator[]
// Source: utmarray.h lines 63-67
// public: int & __thiscall ManagedArray<int>::operator[](int)
//
// Attempt log:
// Probe 1: natural resizing operator[], default flags

#include "..\..\include\game_globals.h"

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

// ManagedArray<int> layout:
// +0x00: value (int*)
// +0x04: numberValue (int)
// +0x08: desiredNumberValue (int)
// +0x0C: maximumSizeValue (int)
class ManagedArray_int {
public:
    int* value;              // +0x00 (4)
    int numberValue;         // +0x04 (4)
    int desiredNumberValue;  // +0x08 (4)
    int maximumSizeValue;    // +0x0C (4)

    int& operator[](int index);
};

int& ManagedArray_int::operator[](int index)
{
    if (index > this->maximumSizeValue - 1) {
        int new_size = index + 1;
        int* new_data = (int*)operator_new(new_size * 4);
        if (new_data != 0) {
            for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                new_data[i] = this->value[i];
            }
            operator_delete(this->value);
            this->value = new_data;
            this->maximumSizeValue = new_size;
        }
    }
    return this->value[index];
}
