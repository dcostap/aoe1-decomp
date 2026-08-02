// 004FBB30 TribeTacticalAIModule::removeFromTaskLists
// PDB: taitacmd.cpp:9318-9332, 215 bytes
// __thiscall, void, ret 4
// FLAGS: default
//
// Attempt log:
// inherited attempts: decompiler-shaped pointer scans produced a redundant
//   bottom cmp/jne; several do/while, goto, and local-load variants stalled.
// probe 1 baseline: retained the best inherited natural candidate for fresh
//   validation; 175 positional diff bytes, exact calls/size/frame.
// probe 2: replaced the pointer do/while with a bounded indexed for scan,
//   following the exact ManagedArray<int>::remove donor; diff fell to 22 bytes.
// probe 3: modeled actualGathererDistribution[4] at +0xD68; emitted code
//   unchanged (negative layout evidence).
// probe 4: stored `value - 1` from an explicit load; emitted code unchanged.
// probe 5: named the proven distribution-element pointer and used explicit
//   load/store; restored the original mov/load, lea, dec, store tail: MATCH.
// probe 6: normalized civilianExplorers as ManagedArray<int> and UnitData as
//   named fields (including data1); emitted code remained exact.
// Exact source is a natural bounded ManagedArray scan/compact operation,
// typed helper calls, and an explicit element pointer for the observed
// load/lea/decrement/store sequence.

#include <stdlib.h>

class UnitAIModule;
class RGE_Static_Object;

struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    unsigned long lastTaskTime;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* member_F0;

    RGE_Static_Object* object(int key);
};

class RGE_Static_Object {
public:
    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    int currentAction();
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;                  // +0xF0
    char gap_F4[0x10];                         // +0xF4-0x103
    ManagedArray_int civilianExplorers;          // +0x104
    char gap_114[0xC54];                         // +0x114-0xD67
    int actualGathererDistribution[4];           // +0xD68

    void removeGatherer(int key);
    UnitData* gatherer(int key);
    void removeFromTaskLists(int key);
};

void TribeTacticalAIModule::removeFromTaskLists(int key) {
    int i = 0;
    int count = this->civilianExplorers.maximumSizeValue;

    for (; i < count; ++i) {
        if (this->civilianExplorers.value[i] == key) break;
    }

    if (i < count) {
        count--;
        if (i < count) {
            do {
                int* values = this->civilianExplorers.value;
                i++;
                values[i - 1] = values[i];
            } while (i < this->civilianExplorers.maximumSizeValue - 1);
        }

        this->civilianExplorers.numberValue--;
        if (this->civilianExplorers.numberValue < 0) {
            this->civilianExplorers.numberValue = 0;
        }
    }

    this->removeGatherer(key);

    RGE_Static_Object* obj = this->md->object(key);
    if (obj != NULL) {
        if (obj->unitAI() != NULL) {
            if (obj->unitAI()->currentAction() == 0x261) goto check;
            if (obj->unitAI()->currentAction() != 0x265) goto end;
check:
            UnitData* g = this->gatherer(key);
            if (g != NULL) {
                int index = g->data1;
                int* p = &this->actualGathererDistribution[index];
                int value = *p;
                *p = value - 1;
            }
        }
    }

end:
    return;
}
