// VA: 004FF4E0 TribeTacticalAIModule::numberUngroupedWarBoats
// Attempt log:
// baseline: raw-offset expandable-array reconstruction had the right call set and
// size, but broad structural/register drift started at the prologue.
// probe 2: replaced raw array plumbing with typed ManagedArray<int> boats and
// workingArea members. This matched the exact same-TU numberUngroupedSoldiers
// donor's ordinary indexer/add source shape and produced an exact 510-byte match.
// exact: canonical ownership is the boats and workingArea ManagedArray<int>
// members at +134 and +D48; no raw-offset plumbing or compiler steering remains.

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
    char gap_000[0x134];
    ManagedArray<int> boats;
    char gap_144[0xD48 - 0x144];
    ManagedArray<int> workingArea;

    TacticalAIGroup* groupUnitIsIn(int unit);
    int numberUngroupedWarBoats();
};

int TribeTacticalAIModule::numberUngroupedWarBoats()
{
    int rNum = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& boats = this->boats;

    workingArea.numberValue = 0;
    if (boats.numberValue > 0) {
        do {
            if (this->groupUnitIsIn(boats[i]) == 0) {
                workingArea.add(boats[i]);
                rNum++;
            }
            i++;
        } while (i < boats.numberValue);
    }
    return rNum;
}
