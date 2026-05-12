// VA: 0040CE90 MainDecisionAIModule::MainDecisionAIModule(int, RGE_Player*, int)
// PDB: aimdmod.cpp lines 43-52
// Size: 390 bytes
// FLAGS: /GX
//
// Status: STUCK — instruction scheduling + register allocation diff
//
// First 56 bytes match (EH prologue + base ctor call). Then VC5 reorders
// field stores, rge_read argument setup, SEH code writes, and vtable store
// differently than the original. The same instructions exist in both, but in
// different order (scheduling) and with different register allocation (ebp vs
// edi as zero reg in various versions). No source surface controls VC5's
// instruction scheduler or register allocator.
//
// Best result: 56 bytes exact, first mismatch at offset 56. Edit diff 44%.
//
// Attempt log:
// - Fixed AIModule base size to 0xF0 (gap_04[0xEC]) for correct field offsets
// - Added <new.h>/<stdlib.h> includes to trigger EH prologue generation
// - Removed excess locals; simplified loop structure to match original style
// - Field offsets now correct (+0xF0 player, +0xF4 value, etc.)
// - Prologue register allocation matches (esi/edi save, edi as zero)
// - Remaining issue: instruction scheduling (field stores vs rge_read prep order)
//   and missing SEH code write (mov byte [esp+24h], 1)
//
// No accepted_drift: 74% positional diff, broad scheduling and register differences.

#include <new.h>
#include <stdlib.h>

extern "C" void __cdecl rge_read(int, void*, int);

class RGE_Player {};

class AIModule {
public:
    char gap_04[0xEC]; // vptr + 0xEC = 0xF0 total base size
    AIModule(char* name, int id, int player_number, void* owner);
    virtual ~AIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;              // +0xF0
    int* objects_value;              // +0xF4
    int objects_numberValue;         // +0xF8
    int objects_desiredNumberValue;  // +0xFC
    int objects_maximumSizeValue;    // +0x100

    MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3);
    virtual ~MainDecisionAIModule();
};

MainDecisionAIModule::MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3)
    : AIModule("Main Decision AI", 1000, param_1, 0)
{
    RGE_Player* p;
    int count;
    int i;

    this->player = param_2;
    this->objects_value = 0;
    this->objects_numberValue = 0;
    this->objects_desiredNumberValue = 0;
    this->objects_maximumSizeValue = 0;

    rge_read(param_3, &count, 4);

    i = 0;
    if (count > 0) {
        do {
            rge_read(param_3, &p, 4);
            int nv = this->objects_numberValue;
            int mv = this->objects_maximumSizeValue;
            int j;
            for (j = 0; j < nv; j++) {
                if (j >= mv) break;
                if ((RGE_Player*)this->objects_value[j] == p) goto next;
            }
            if (nv > mv - 1) {
                int new_sz = nv + 1;
                int* new_arr = (int*)operator new(new_sz * 4);
                if (new_arr != 0) {
                    int k;
                    for (k = 0; k < mv; k++) {
                        if (k >= new_sz) break;
                        new_arr[k] = this->objects_value[k];
                    }
                    operator delete(this->objects_value);
                    this->objects_value = new_arr;
                    this->objects_maximumSizeValue = new_sz;
                }
            }
            this->objects_value[this->objects_numberValue] = (int)p;
            this->objects_numberValue++;
next:
            i++;
        } while (i < count);
    }
}
