// VA: 004FF6E0, TribeTacticalAIModule::numberExtraGroupedWarBoats, 509 bytes
// Attempt log:
// - try 1: natural decompiler-shaped C++ with minimal local class surface; exact size but 80.55% diff, group allocated EBP and init/store order wrong.
// - try 2: declared group as register to probe EBX allocation; no change.
// - try 3: seeded a zero local for count/working_number to encourage xor eax before push edi; no change.
// - try 4: compared against 004FD4F0 sibling scratch; same family/register-basin blocker noted there.
// - try 5: switched to sibling surface: vtable,next layout, raw sentinel bytes, explicit groupNext/workingValue names; edit diff improved to 57.76%, same first mismatch.
// - try 6: split result initialization from declaration; no change.
// - try 7: declare group after int locals to probe EBX/EBP allocation; no change.
// - try 8: /GX flag probe; no change, rolled back.
// - try 9: /O1 flag probe; object too small (492B), rolled back.
// - try 10: reviewed while/do loop; kept while(1)+break because it matches sibling and bottom desiredNumberUnits check family best.
// BLOCKER: exact 509B size, but not accepted-drift-safe. First mismatch remains at offset 8: original emits xor eax; push edi; stores result and workingNumber from eax, and keeps group in EBX. Rebuilt emits push edi then C7 result store and keeps group in EBP. Broad register/stack-slot basin diff remains.

typedef unsigned char uchar;
void* operator new(unsigned int size);
void operator delete(void* ptr);

class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int type();
    int numberUnits();
    int unit(int index);
    int desiredNumberUnits();
    int commander();
    int action();
};

class TribeTacticalAIModule {
public:
    char gap_000[0x9d4];
    char groups_sentinel[4];
    TacticalAIGroup* groupNext;
    char gap_after_groups[0xd48 - 0x9dc];
    int* workingValue;
    int workingNumber;
    char gap_d50[4];
    int workingMax;

    int numberExtraGroupedWarBoats();
};

int TribeTacticalAIModule::numberExtraGroupedWarBoats()
{
    int result;
    int rNum;
    int tempCount;
    int j;
    TacticalAIGroup* group;

    result = 0;
    this->workingNumber = result;
    group = this->groupNext;
    if (group == (TacticalAIGroup*)this->groups_sentinel) {
        return result;
    }

    do {
        if (group == 0) {
            return result;
        }
        if ((group->type() == 103 || group->type() == 104 || group->type() == 105 ||
             group->type() == 106 || group->type() == 107 || group->type() == 108) &&
            (group->action() == 1 || group->action() == 0)) {
            if (group->desiredNumberUnits() < group->numberUnits()) {
                rNum = group->numberUnits();
                tempCount = 0;
                if (group->desiredNumberUnits() < rNum) {
                    while (1) {
                        if (tempCount >= group->numberUnits()) break;
                        if (group->unit(tempCount) != group->commander()) {
                            rNum--;
                            int u = group->unit(tempCount);
                            j = 0;
                            if (this->workingNumber > 0) {
                                do {
                                    if (j >= this->workingMax) break;
                                    if (this->workingValue[j] == u) goto counted;
                                    j++;
                                } while (j < this->workingNumber);
                            }
                            if (this->workingNumber > this->workingMax - 1) {
                                int newMax = this->workingNumber + 1;
                                int* newValue = (int*)operator new(newMax * 4);
                                if (newValue != 0) {
                                    j = 0;
                                    if (this->workingMax > 0) {
                                        do {
                                            if (j >= newMax) break;
                                            j++;
                                            newValue[j - 1] = this->workingValue[j - 1];
                                        } while (j < this->workingMax);
                                    }
                                    operator delete(this->workingValue);
                                    this->workingValue = newValue;
                                    this->workingMax = newMax;
                                }
                            }
                            this->workingValue[this->workingNumber] = u;
                            this->workingNumber++;
counted:
                            result++;
                        }
                        tempCount++;
                        if (group->desiredNumberUnits() >= rNum) break;
                    }
                }
            }
        }
        group = group->next;
    } while (group != (TacticalAIGroup*)this->groups_sentinel);

    return result;
}
