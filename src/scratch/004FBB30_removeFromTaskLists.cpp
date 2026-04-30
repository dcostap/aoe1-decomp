// 004FBB30 TribeTacticalAIModule::removeFromTaskLists
// PDB: taitacmd.cpp:9318-9332, 215 bytes
// __thiscall, void, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1: 73% - extra bounds check, wrong register allocation
// probe 2: 68% - do-while, correct register allocation (EDX=count, ECX=values)
//   remaining: loop back-edge is jge (forward exit) instead of jl (back to compare)
//   this creates a redundant `cmp [ecx],ebx; jne inc` pair
// probe 3-5: for/goto/while variants, no improvement
// probe 6: moved load outside - exceeded section size
// probe 7: goto label approach - register allocation changed (edi for param)
//
// left in scratch: remaining drift is VC5 loop-back polarity decision.
// `do { if (*v==key) break; i++; v++; } while(i<count)` generates `jge exit`
// instead of `jl top` — the loop-back targets the increment step instead of
// the compare. This creates a redundant cmp/jne pair at the bottom of the loop.
// Semantically equivalent, but VC5 makes different scheduling decision.
// Possible TU context fix: maybe move to proper TU grouping.

#include <stdlib.h>

class UnitAIModule;
class UnitData;
class RGE_Static_Object;

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
    void* md;                                  // +0xF0: MainDecisionAIModule*
    char gap_F4[0x10];                         // +0xF4-0x103
    int* civilianExplorers_value;              // +0x104
    int civilianExplorers_numberValue;          // +0x108
    int civilianExplorers_pad;                  // +0x10C
    int civilianExplorers_maximumSizeValue;     // +0x110

    void removeGatherer(int key);
    UnitData* gatherer(int key);
    void removeFromTaskLists(int key);
};

void TribeTacticalAIModule::removeFromTaskLists(int key) {
    int i = 0;
    int count = this->civilianExplorers_maximumSizeValue;

    if (count > 0) {
        int* values = this->civilianExplorers_value;
        do {
            if (*values == key) break;
            i++;
            values++;
        } while (i < count);
    }

    if (i < count) {
        count--;
        if (i < count) {
            do {
                int* values = this->civilianExplorers_value;
                i++;
                values[i - 1] = values[i];
            } while (i < this->civilianExplorers_maximumSizeValue - 1);
        }

        this->civilianExplorers_numberValue--;
        if (this->civilianExplorers_numberValue < 0) {
            this->civilianExplorers_numberValue = 0;
        }
    }

    this->removeGatherer(key);

    RGE_Static_Object* obj = ((MainDecisionAIModule*)this->md)->object(key);
    if (obj != NULL) {
        if (obj->unitAI() != NULL) {
            if (obj->unitAI()->currentAction() == 0x261) goto check;
            if (obj->unitAI()->currentAction() != 0x265) goto end;
check:
            UnitData* g = this->gatherer(key);
            if (g != NULL) {
                int index = *(int*)((char*)g + 4);
                int* dist = (int*)((char*)this + 0xD68);
                dist[index]--;
            }
        }
    }

end:
    return;
}
