// VA: 004FD4F0, TribeTacticalAIModule::numberExtraGroupedSoldiers, 473 bytes
// Source: taitacmd.cpp lines 10154-10201
// Attempt log:
// - v1: natural reconstruction from packet/decompiler, using TacticalAIGroup member calls and local dynamic int array.
// - v2: modeled group list sentinel at +0x9d4, next at +0x9d8, working array at +0xd48/+0xd4c/+0xd54.
// - v3: made list sentinel raw bytes instead of embedding TacticalAIGroup, fixing working-area offsets.
// - v4: reordered local declarations to probe VC5 stack-slot/register allocation.
// - v5: changed initial sentinel/null exits from early returns to one shared final return; worse, rolled back.
// - v6: set workingNumber from result local to encourage xor/store/store initialization.
// - v7: removed sentinel local; original recomputes lea [esi+9d4] at list checks.
// - v8: declared group before int locals to probe EBX vs EBP allocation.
// - v9: initialized result in declaration instead of separate assignment.
// BLOCKER: behavior/call set and size are close (473/473), but VC5 is in a different register/stack-slot basin from the prologue: original zeroes EAX then stores result at [esp+18] and workingNumber, keeps current group in EBX; rebuilt initializes result with a C7 store at [esp+10] and keeps current group in EBP. This cascades through rNum/tempCount/u slots and inner duplicate-array/copy loops.

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
    char groups_sentinel[4];       // +0x9d4
    TacticalAIGroup* groupNext;    // +0x9d8
    char gap_after_groups[0xd48 - 0x9dc];
    int* workingValue;             // +0xd48
    int workingNumber;             // +0xd4c
    char gap_d50[4];
    int workingMax;                // +0xd54

    int numberExtraGroupedSoldiers();
};

int TribeTacticalAIModule::numberExtraGroupedSoldiers()
{
    TacticalAIGroup* group;
    int result = 0;
    int rNum;
    int tempCount;
    int j;

    this->workingNumber = result;
    group = this->groupNext;
    if (group == (TacticalAIGroup*)this->groups_sentinel) {
        return result;
    }

    do {
        if (group == 0) {
            return result;
        }

        if ((group->type() == 100 || group->type() == 101 || group->type() == 102) &&
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
