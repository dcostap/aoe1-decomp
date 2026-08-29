// ManagedArray<int>::resize(int new_size)
// Size: 95 bytes (0x5F), 40 asm lines

// Key insight: for loop + direct indexing prevents loop peeling,
// same pattern as ManagedArray<int>::remove (004F1390).

extern "C" {
    void* __cdecl operator_new(size_t size);
    void __cdecl operator_delete(void* block);
}

class ManagedArray_int {
public:
    int* value;             // +0
    int numberValue;        // +4
    int desiredNumberValue; // +8
    int maximumSizeValue;   // +0C

    int resize(int new_size);
};

int ManagedArray_int::resize(int new_size) {
    int* new_value = (int*)operator_new(new_size * 4);
    if (new_value == 0) return 0;

    int i = 0;
    for (; i < this->maximumSizeValue && i < new_size; i++) {
        new_value[i] = this->value[i];
    }

    operator_delete(this->value);
    this->value = new_value;
    this->maximumSizeValue = new_size;
    return 1;
}
