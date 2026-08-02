// 004F7D90 TribeTacticalAIModule::idleSoldier()
// Source: taitacmd.cpp lines 7061-7070
// Size: 231 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Attempt log:
// Probe 1 (prior session): clean for loop, hand-expanded grow — 83.1% positional, 231 bytes
// Probes 2-3 (prior session): do-while with i=0 early, newSize var — prologue + expansion check matched
//   but stuck at 224/231 bytes with copy-loop register allocation + loop branch encoding drift.
//
// New approach (this session): the grow/copy/delete path is the inline
// ManagedArray<int>::operator[] (utmarray.h lines 63-67) exactly as matched at
// 004EA750. idleSoldier's line map puts the grow AND the world->object() call on
// one source line (7063), which is the signature of an inlined operator[] call:
//     obj = md->player->world->object(soldiers[i]);
// The standalone exact match 004EA750 emits the identical copy loop (inc eax +
// [base+eax*4-4] post-increment form), so inlining operator[] should reproduce
// the canonical grow basin instead of the hand-expanded 224/231 variant.
//
// Key findings (struct layout correct):
// - Prologue: push ebx; push ebp; push esi; mov esi,ecx; xor ebx,ebx; push edi
// - +0x114: soldiers ManagedArray (value=+0x114, numberValue=+0x118, maximumSizeValue=+0x120)
// - +0x0F0: md (TribeMainDecisionAIModule*) -> +0xF0: player -> +0x3C: world
// - operator_new at 0054B6F0h, operator_delete at 0054B660h
// - unitAI at 004C7420h (called twice: null-check then currentAction), currentAction at 00413960h,
//   world->object at 00545D30h
// - return obj->id ([edi+4]) on currentAction == -1

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct RGE_Static_Object;
struct UnitAIModule;
struct RGE_Game_World;
struct RGE_Player;

struct RGE_Player {
    char pad_00[0x3C];
    RGE_Game_World* world;            // +0x3C
};

struct RGE_Game_World {
    RGE_Static_Object* object(int objectID);
};

struct RGE_Static_Object {
    void* vtable;                     // +0x00
    int id;                           // +0x04
    UnitAIModule* unitAI();
};

struct UnitAIModule {
    int currentAction();
};

struct MainDecisionAIModule {
    char pad_F0[0xF0];
    RGE_Player* player;               // +0xF0
};

struct TribeMainDecisionAIModule : MainDecisionAIModule {};

struct ManagedArray_int {
    int* value;                       // +0x00
    int numberValue;                  // +0x04
    int desiredNumberValue;           // +0x08
    int maximumSizeValue;             // +0x0C

    int& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            int* new_data = (int*)operator_new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

struct TribeTacticalAIModule {
    char pad_00[0x0F0];
    TribeMainDecisionAIModule* md;    // +0xF0
    ManagedArray_int civilians;       // +0xF4
    ManagedArray_int civilianExplorers; // +0x104
    ManagedArray_int soldiers;        // +0x114

    int idleSoldier();
};

int TribeTacticalAIModule::idleSoldier()
{
    for (int i = 0; i < soldiers.numberValue; i++) {
        RGE_Static_Object* obj = md->player->world->object(soldiers[i]);
        if (obj != 0 && obj->unitAI() != 0) {
            if (obj->unitAI()->currentAction() == -1)
                return obj->id;
        }
    }
    return -1;
}
