// VA: 004FF6E0, TribeTacticalAIModule::numberExtraGroupedWarBoats, 509 bytes
// Attempt log:
// - Prior scratch work used raw working-area fields and reached 509 bytes, but
//   it used a compiler-shaped register basin and did not model array ownership.
// - Baseline in this session rebuilt at 541 bytes. It had the right 19 calls,
//   but the working-area scan and list CFG had extra structural blocks.
//
// This source models the proven group sentinel and workingArea as their
// period-plausible typed owners. The inline array method is the same ownership
// surface used by exact same-TU ManagedArray donors.
//
// Probe notes:
// - ManagedArray::add plus the explicit while loop aligned all 19 calls and
//   reduced the function to the exact 509-byte boundary.
// - Left-side comparison spellings aligned the remaining branch opcodes.
// - A local workingArea reference aligned the prologue order and all body
//   bytes except stack-home displacements.
// - A natural do-while spelling for the inner predicate added one
//   numberUnits call and 11 bytes; restored the while/break reconstruction.
// - A direct typed count predicate reversed the initial numberUnits/
//   desiredNumberUnits call order and increased the diff to 19 bytes; restored
//   the explicit count temporary.
// - Remaining drift is 10 stack-home bytes: VC5 assigns result/rNum/tempCount
//   to [esp+10]/[esp+18]/[esp+14], while the oracle uses [esp+18]/[esp+14]/
//   [esp+10]. No behavior or call-set drift remains.

void* operator new(unsigned int size);
void operator delete(void* ptr);

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int add(T val)
    {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == val)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int newSize = this->numberValue + 1;
            T* newValue = (T*)operator new(newSize * sizeof(T));
            if (newValue != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= newSize)
                        break;
                    newValue[j] = this->value[j];
                }
                operator delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }

        this->value[this->numberValue] = val;
        this->numberValue++;
        return 1;
    }
};

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    char gap_after_subType[0x330 - 0x1c];

    int type();
    int action();
    int numberUnits();
    int desiredNumberUnits();
    int unit(int index);
    int commander();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9d4];
    TacticalAIGroup groups;
    char gap_after_groups[0xd48 - (0x9d4 + 0x330)];
    ManagedArray<int> workingArea;

    int numberExtraGroupedWarBoats();
};

int TribeTacticalAIModule::numberExtraGroupedWarBoats()
{
    ManagedArray<int>& workingArea = this->workingArea;
    int tempCount;
    int rNum;
    int result = 0;
    int numberUnitsValue;
    TacticalAIGroup* group;

    workingArea.numberValue = result;
    group = this->groups.next;
    while (group != &this->groups) {
        if (group == 0)
            return result;

            if ((group->type() == 103 || group->type() == 104 ||
                 group->type() == 105 || group->type() == 106 ||
                 group->type() == 107 || group->type() == 108) &&
                (group->action() == 1 || group->action() == 0)) {
                numberUnitsValue = group->numberUnits();
                if (numberUnitsValue > group->desiredNumberUnits()) {
                    rNum = group->numberUnits();
                    tempCount = 0;
                    if (rNum > group->desiredNumberUnits()) {
                        while (1) {
                            if (tempCount >= group->numberUnits())
                                break;
                            if (group->unit(tempCount) != group->commander()) {
                                rNum--;
                                workingArea.add(group->unit(tempCount));
                                result++;
                            }
                            tempCount++;
                            if (rNum <= group->desiredNumberUnits())
                                break;
                        }
                    }
                }
            }
        group = group->next;
    }
    return result;
}
