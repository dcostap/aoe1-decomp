// VA: 004FF8E0 TribeTacticalAIModule::numberUngroupedFishingBoats
// Attempt log:
// 1: adapted known numberUngroupedSoldiers source to fishingBoats offsets: correct size 510 but broad 90.4% positional diff; compiler omitted push ebp and used ebp as newMax.
// 2: switched to decompiler-shaped local_4/i/local_c source based on numberUngroupedArtifacts scratch to force stack locals: 510 B, first mismatch at stack slot init, 79.6% diff.
// 3: removed volatile from i; worse first mismatch at frame immediate/slot allocation, rolled back.
// 4: tested local declaration reordering with volatile i; no slot/order change.
// 5: changed growth predicates to `local_4 > max-1` / `iVar2 > max-1` to match original cmp polarity; fixed first growth compare polarity but broad copy-loop/register drift remains.
// 6: tried local order local_c/i/local_4 and local_c/local_4/i with volatile offset temp; stack slot order unchanged.
// 7: tried /GX; unchanged.
// 8: tried /O2 without /Oy; unchanged.
// 9: tried /Od narrow flag; unchanged under this build harness/output family.
// 10: restored the best raw-offset reconstruction before this fresh typed pass; it rebuilt 566 bytes with structural drift from stack-slot ordering and copy-loop shape.
// 11: replaced manual array growth with the period-plausible inline ManagedArray
//     operator[]/add surfaces used by the exact same-TU numberUngroupedSoldiers
//     donor. The class declaration now names fishingBoats and workingArea at
//     the proven offsets; check this typed group-count reconstruction.
// 12: typed group-count reconstruction is an exact 510-byte match. The source
//     keeps canonical named ManagedArray ownership and ordinary references;
//     no raw-offset or compiler-steering form remains.

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

    int add(T valueToAdd) {
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
    char gap_164[0xD48 - 0x164];
    ManagedArray<int> workingArea;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedFishingBoats();
};

int TribeTacticalAIModule::numberUngroupedFishingBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& fishingBoats = this->fishingBoats;

    workingArea.numberValue = 0;
    if (fishingBoats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(fishingBoats[i]) == 0) {
                workingArea.add(fishingBoats[i]);
                rNum++;
            }
            i++;
        } while (i < fishingBoats.numberValue);
    }
    return rNum;
}
