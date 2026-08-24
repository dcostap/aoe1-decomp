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
// - The period ManagedArray::add operation is the missing source boundary:
//   replacing the hand-expanded duplicate scan/append with the exact donor's
//   inline add body restored the target's callee-save allocation and matched
//   all 299 bytes.  This is a real utmarray.h API surface, not a codegen hack.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

#ifndef PATHSYS_TU_CONTEXT
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

    int add(T val) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == val)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int new_size = this->numberValue + 1;
            T* new_data = (T*)operator_new(new_size * sizeof(T));
            if (new_data != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_data[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

class PathingSystem {
public:
    virtual ~PathingSystem();
    char gap_04[0x11DCE0];
    ManagedArray<int> currentUnobstructibles;

    void copyUnobstructibles(ManagedArray<int>& out);
};
#endif

void PathingSystem::copyUnobstructibles(ManagedArray<int>& out)
{
    int i = this->currentUnobstructibles.numberValue;
    if (i >= 0) {
        do {
            out.add(this->currentUnobstructibles[i]);

            --i;
        } while (i >= 0);
    }
}
