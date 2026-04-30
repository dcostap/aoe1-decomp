// 004F7D90 TribeTacticalAIModule::idleSoldier()
// Source: taitacmd.cpp lines 7061-7070
// Size: 231 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift (224/231 bytes, ~78% match)
//
// Attempt log:
// Probe 1: clean for loop — 83.1% positional, 231 bytes
// Probes 2-3: do-while with i=0 early, newSize var — prologue + expansion check now match
//
// Key findings (struct layout correct):
// - Prologue: push ebx; push ebp; push esi; mov esi,ecx; xor ebx,ebx; push edi
// - +0x114: soldiers ManagedArray (value, numberValue=+0x118, maximumSizeValue=+0x120)
// - +0x0F0: md (TribeMainDecisionAIModule*) → +0xF0: player → +0x3C: world
// - operator_new at 0054B6F0h, operator_delete at 0054B660h
// - unitAI at 004C7420h, currentAction at 00413960h, world->object at 004545D30h
//
// Remaining drift:
// - 224 bytes vs original 231 (7 bytes short)
// - Copy loop register allocation (ecx vs edx for temp)
// - Object lookup register allocation (eax/ecx/edx choices)
// - Loop: jge+jmp vs jl encoding

extern "C" void* _new(unsigned int);
extern "C" void _delete(void*);

struct RGE_Static_Object;
struct UnitAIModule;
struct RGE_Game_World;
struct RGE_Player;

struct RGE_Player {
    char pad_00[0x3C];
    RGE_Game_World* world;
};

struct RGE_Game_World {
    RGE_Static_Object* object(int objectID);
};

struct RGE_Static_Object {
    void* vtable;
    int id;
    UnitAIModule* unitAI();
};

struct UnitAIModule {
    int currentAction();
};

struct MainDecisionAIModule {
    char pad_F0[0xF0];
    RGE_Player* player;
};

struct TribeMainDecisionAIModule : MainDecisionAIModule {};

struct ManagedArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct TribeTacticalAIModule {
    char pad_00[0x0F0];
    TribeMainDecisionAIModule* md;
    ManagedArray civilians;
    ManagedArray civilianExplorers;
    ManagedArray soldiers;

    int idleSoldier();
};

int TribeTacticalAIModule::idleSoldier()
{
    int i;
    int* newArr;
    int newSize;
    int j;

    i = 0;

    if (soldiers.numberValue <= 0)
        return -1;

    do {
        if (i > soldiers.maximumSizeValue - 1) {
            newSize = i + 1;
            newArr = (int*)_new(newSize * 4);
            if (newArr != 0) {
                for (j = 0; j < soldiers.maximumSizeValue && j < newSize; j++)
                    newArr[j] = soldiers.value[j];
                _delete(soldiers.value);
                soldiers.value = newArr;
                soldiers.maximumSizeValue = newSize;
            }
        }

        int unitID = soldiers.value[i];
        RGE_Static_Object* obj = md->player->world->object(unitID);
        if (obj != 0) {
            if (obj->unitAI() != 0) {
                if (obj->unitAI()->currentAction() == -1)
                    return obj->id;
            }
        }
        i++;
    } while (i < soldiers.numberValue);

    return -1;
}
