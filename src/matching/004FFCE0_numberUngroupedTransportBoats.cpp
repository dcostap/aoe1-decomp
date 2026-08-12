// VA: 004FFCE0 TribeTacticalAIModule::numberUngroupedTransportBoats
// Attempt log:
// try 1: cloned decompiler-style dynamic-array logic from analogous soldiers function, changing source array offsets to transportBoats (+0x174/+0x178/+0x180).
// try 2: used volatile i to force 0x0c frame; it preserves frame size but shifts rNum/local_4 stack slots versus original.
// try 3: reordered local declarations; no improvement in stack slot allocation.
// try 4: compare spelling `local_4 > maximum-1` restored early jle polarity but copy-loop topology remains wrong.
// try 5: factored helper style was considered from analogous function; compiles too small/out-of-line and loses original inlined growth shape.
// try 6: fully natural indexed source uses no EBP loop index and broad register drift.
// try 7: decompiler-style locals get EBP loop index and exact size but VC5 emits ecx index/shift copy loops instead of original eax increment + [base+eax*4-4].
// try 8: non-volatile i kept exact size but did not improve topology (79.2% positional, 105.5% edit).
// try 9: original less-than compare spelling regressed slightly (79.6% positional, 109.8% edit).
// try 10: rNum-first local declaration did not move stack slots or copy-loop family.
// try 11: while(1)+break outer loop was neutral versus do/while for the major mismatch.
// try 12: replaced raw offset plumbing with the sibling's typed ManagedArray<int> surface and ordinary aliases; pending checker result.
// exact: sibling-shaped typed ManagedArray<int> reconstruction matches all 510 bytes with default flags.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

class TacticalAIGroup;

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
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
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
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_value[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

class TribeTacticalAIModule {
public:
    char gap_000[0x174];
    ManagedArray<int> transportBoats;
    char gap_184[0xD48 - 0x184];
    ManagedArray<int> workingArea;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedTransportBoats();
};

int TribeTacticalAIModule::numberUngroupedTransportBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& transportBoats = this->transportBoats;

    workingArea.numberValue = 0;
    if (transportBoats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(transportBoats[i]) == 0) {
                workingArea.add(transportBoats[i]);
                rNum++;
            }
            i++;
        } while (i < transportBoats.numberValue);
    }
    return rNum;
}
