// VA: 0040CE90 MainDecisionAIModule::MainDecisionAIModule(int, RGE_Player*, int)
// PDB: aimdmod.cpp lines 43-52
// Size: 390 bytes
// FLAGS: /GX
//
// Status: exact candidate (390 bytes; 0.0000% positional diff)
//
// Canonical ownership: AIModule is the 0xF0 base; `objects` is the inline
// four-word ManagedArray_RGE_Player at +0xF4.  The input loop reuses the
// incoming player parameter as rge_read's destination, then keeps a separate
// saved value for the duplicate scan and append.
//
// Attempt log:
// - Baseline thin AIModule/flat object fields: 366 bytes, first mismatch at 56.
// - Mirrored the exact same-TU addObject growth/scan shape and reused param_1
//   as the outer counter: 390 bytes, edit/resync similarity improved sharply.
// - Read the second player directly into param_2: frame returned to 0x8 and
//   the complete post-read growth body aligned.
// - Applied the binary-proven delayed derived-vtable surface
//   (__declspec(novtable) plus the explicit vtable store); this localized the
//   remaining difference to the constructor prefix.
// - Expanded the local AIModule declaration to its donor-backed 0xF0 fields;
//   no emitted-code change.
// - Modeling `objects` as an inline ManagedArray with its natural zeroing
//   constructor and nontrivial destructor restored the missing VC5 EH state
//   transition and produced an exact match.
//
// The explicit derived-vtable write is retained only because the oracle proves
// its delayed position and the natural compiler-owned-vptr form did not match.

#include <new.h>
#include <stdlib.h>

extern "C" void __cdecl rge_read(int, void*, int);

class RGE_Player {};

struct ManagedArray_RGE_Player {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ManagedArray_RGE_Player()
        : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedArray_RGE_Player();
};

class AIModule {
public:
    char idValue[0x48];             // +0x04, AIModuleID storage
    int playerNumberValue;          // +0x4C
    char playerNameValue[0x40];    // +0x50
    int runningValue;               // +0x90
    int pausedValue;                // +0x94
    int logHistoryValue;            // +0x98
    int logCommonHistoryValue;      // +0x9C
    void* historyLogFile;            // +0xA0
    char historyLogFilename[0x40];  // +0xA4
    int intelligenceLevelValue;     // +0xE4
    int priorityValue;               // +0xE8
    int processFrameValue;           // +0xEC
    AIModule(char* name, int id, int player_number, void* owner);
    virtual ~AIModule();
};

class __declspec(novtable) MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;              // +0xF0
    ManagedArray_RGE_Player objects;  // +0xF4

    MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3);
    virtual ~MainDecisionAIModule();
};

MainDecisionAIModule::MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3)
    : AIModule("Main Decision AI", 1000, param_1, 0),
      player(param_2),
      objects()
{
    RGE_Player* saved_p;
    int count;

    *(void**)this = (void*)0x56E8D8;
    rge_read(param_3, &count, 4);

    param_1 = 0;
    if (count > 0) {
        do {
            rge_read(param_3, &param_2, 4);
            saved_p = param_2;

            int number = this->objects.numberValue;
            for (int j = 0; j < number; j++) {
                if (j >= this->objects.maximumSizeValue) break;
                if (this->objects.value[j] == (int)saved_p) goto next;
            }

            if (number > this->objects.maximumSizeValue - 1) {
                int new_size = number + 1;
                int* new_arr = (int*)operator new(new_size * 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < new_size) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = new_size;
                }
            }
            this->objects.value[this->objects.numberValue] = (int)saved_p;
            this->objects.numberValue++;
next:
            param_1++;
        } while (param_1 < count);
    }
}
