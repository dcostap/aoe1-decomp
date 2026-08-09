// VA: 0046DCB0 copyUnobstructibles (299B)
// pathsys.cpp
//
// Attempt log:
// - Baseline: named currentUnobstructibles plus the period utmarray.h inline
//   indexer and a natural duplicate scan; 314 rebuilt bytes, 291 positional
//   differences.
// - The binary-proven combined number/max bounded scan reduced the candidate
//   to 304 bytes and 278 positional differences, with all four allocation
//   calls aligned.  This is the retained natural reconstruction.
// - For/while/do-while outer-loop spellings, declaration scope/order, a
//   narrow register declaration, self/current aliases, and the exact
//   operator_new/operator_delete ABI surface were tested; they emitted the
//   same 304-byte code.  The remaining gap is structural register/block
//   layout (target saves EBX/EDI; candidate saves EBX/EBP) rather than calls
//   or ownership.
// - Left in scratch: current source is typed and period-plausible, but exact
//   matching is paused after the 10-hypothesis session budget.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_data = (T*)operator_new(new_size * sizeof(T));
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
};

class PathingSystem {
public:
    char gap_000[0x11DCE4];
    ManagedArray<int> currentUnobstructibles;

    void copyUnobstructibles(ManagedArray<int>& out);
};

void PathingSystem::copyUnobstructibles(ManagedArray<int>& out)
{
    int value;
    int j;
    int i = this->currentUnobstructibles.numberValue;
    if (i >= 0) {
        do {
            value = this->currentUnobstructibles[i];
            j = 0;

            while (j < out.numberValue && j < out.maximumSizeValue) {
                if (out.value[j] == value)
                    goto next_value;
                ++j;
            }

            out[out.numberValue] = value;
            ++out.numberValue;

        next_value:
            --i;
        } while (i >= 0);
    }
}
