#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FD2F0 TribeTacticalAIModule::numberUngroupedSoldiers
// Attempt log:
// try 1: factored ensure helpers compiled out-of-line, text too small.
// try 2: inlined repeated growth logic but compiler chose ebp for newMax and very different loop topology.
// try 3: closer decompiler-style locals/local_4/i/rNum and direct indexed access.
// try 4: volatile i forced 0x0c stack frame but shifted rNum/local_4 slots to +0x10/+0x0c instead of original +0x08/+0x10.
// try 5: reordered locals; no stack-slot improvement.
// try 6: compare spelling local_4 > max-1 restored first jle polarity but loop copy body still uses ecx index/shift instead of original eax increment + [base+eax*4-4].
// try 7: first natural inline version had correct function size but no EBP loop index and broad register/topology drift.
// probe 8: restored the period utmarray.h operator[] and add inline method surfaces;
// the source now models two ManagedArray<int> members and lets VC5 lower each
// repeated soldiers[i] access and workingArea.add() naturally.
// probe 9: cached soldier count after the working-number reset; VC5 introduced
// a 0x10 frame and broad drift, so it was rolled back.
// probe 10: pointer-plus-index return spelling in operator[] was a codegen duplicate.
// probe 11: naming the repeated soldier value before add() was also a duplicate.
// probe 12: a natural workingArea reference alias restored the oracle's
// reset-before-soldier-count load order, leaving one SIB base/index byte.
// probe 13: a natural soldiers reference alias selected the oracle's final SIB
// encoding and produced an exact 510-byte match.
// exact: both aliases are ordinary member references; no compiler-steering or
// raw-offset source remains beyond the proven class gaps and array layout.

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

#ifndef TAITACMD_SHARED_CONTEXT
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
    char gap_000[0x114];
    ManagedArray<int> soldiers;
    char gap_124[0xD48 - 0x124];
    ManagedArray<int> workingArea;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedSoldiers();
};

#endif
int TribeTacticalAIModule::numberUngroupedSoldiers()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& soldiers = this->soldiers;

    workingArea.numberValue = 0;
    if (soldiers.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(soldiers[i]) == 0) {
                workingArea.add(soldiers[i]);
                rNum++;
            }
            i++;
        } while (i < soldiers.numberValue);
    }
    return rNum;
}
#else
int TribeTacticalAIModule::numberUngroupedSoldiers() {
    return 0;
}
#endif
