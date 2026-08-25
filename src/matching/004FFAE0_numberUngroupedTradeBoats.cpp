#ifndef TAITACMD_SHARED_CONTEXT
// Attempt log for 004FFAE0 TribeTacticalAIModule::numberUngroupedTradeBoats
// try 1: natural decompiler-shaped reconstruction with ManagedArray fields; exact size but 90.20% positional, compiler made 1-based loop and omitted EBP save.
// try 2: write closer to decompiler/original using local_4 index and allocation size local_4*4+4 directly; first mismatch moved to offset 16, exact size.
// try 3: reorder local declarations and store workingNumber from local_4 to probe stack slot/scheduling; no change.
// try 4: add middle dummy zero local to force local_4 to [esp+10]; dummy optimized away/no change.
// try 5: initialize rNum to zero before local_4 to occupy middle stack slot; no change.
// try 6: use <= skip form for first grow test to match cmp local_4,max; jle skip; small improvement.
// try 7: use <= skip form for second trade grow test too; no further change.
// try 8: adopt sibling numberUngroupedFishingBoats volatile i/copy-temp style; edit diff improved to 45.69%, first mismatch offset 17.
// try 9: /GX flag probe; unchanged, rolled back.
// try 10: /O1 flag probe; object too small (472B), rolled back.
// try 11: /Oy- flag probe; worse from offset 0, rolled back.
// try 12: replaced manual growth and raw pointer arithmetic with the period-plausible
//     ManagedArray operator[]/add surfaces from exact same-TU numberUngroupedSoldiers
//     and numberUngroupedFishingBoats donors; this is the natural typed reconstruction.

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
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int add(int valueToAdd) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
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

        this->value[this->numberValue] = valueToAdd;
        this->numberValue++;
        return 1;
    }
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    void* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    char gap_174[0xD48 - 0x174];
    ManagedArray<int> workingArea;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedTradeBoats();
};

#endif
int TribeTacticalAIModule::numberUngroupedTradeBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& tradeBoats = this->tradeBoats;

    workingArea.numberValue = 0;
    if (tradeBoats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(tradeBoats[i]) == 0) {
                workingArea.add(tradeBoats[i]);
                rNum++;
            }
            i++;
        } while (i < tradeBoats.numberValue);
    }
    return rNum;
}
#else
int TribeTacticalAIModule::numberUngroupedTradeBoats() {
    return 0;
}
#endif
