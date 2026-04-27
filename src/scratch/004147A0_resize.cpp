// attempt 1: direct operator_new / operator_delete path with a natural bounded copy loop
// attempt 2: tried tighter loop-condition spellings; the compiler keeps drifting the copy loop into a different compare basin
// leaving this in scratch paused because the remaining diff is localized loop codegen, not the allocation/delete semantics

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* block);

class ManagedArray_int {
public:
    int* value;
    char gap_4[8];
    int maximumSizeValue;

    int resize(int new_size);
};

int ManagedArray_int::resize(int new_size) {
    int* new_value = (int*)operator_new((unsigned int)new_size * 4);
    if (new_value == 0) {
        return 0;
    }

    int i = 0;
    if (0 < this->maximumSizeValue) {
        while (i < new_size && i < this->maximumSizeValue) {
            int next_i = i + 1;
            new_value[i] = this->value[i];
            i = next_i;
        }
    }

    operator_delete(this->value);
    this->value = new_value;
    this->maximumSizeValue = new_size;
    return 1;
}
