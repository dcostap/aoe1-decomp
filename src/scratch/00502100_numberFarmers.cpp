// 00502100 TribeTacticalAIModule::numberFarmers()
// Source: taitacmd.cpp lines 12516-12535
// Size: 249 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift
//
// Attempt log:
// Probe 1: initial — 83.9% positional, used ebp as result
// Probe 2: removed extra master_obj null check — 79.5% positional, 38.6% edit diff
//
// Key findings (struct layout correct):
// - civilians ManagedArray at +0xF4 (value, numberValue=+0xF8, maxSize=+0x100)
// - md at +0xF0: MainDecisionAIModule* for object lookup
// - Same copy-on-grow pattern as idleSoldier
// - master_obj->id at [obj+8]->[+10h] == 0x103 (farmer type)
// - currentAction checks for 0x261 or 0x262 (farming actions)
// - Result stored in [esp+8] in original, returned in eax
//
// Remaining drift:
// - Prologue: push ecx+esp+8 vs push ebp (result in register vs memory)
// - Array expansion check: cmp+jl vs mov+dec+cmp+jle
// - Copy loop: register allocation (ecx vs edx) same as idleSoldier

extern "C" void* _new(unsigned int);
extern "C" void _delete(void*);

struct RGE_Static_Object;
struct UnitAIModule;
struct MainDecisionAIModule;

struct RGE_Static_Object {
    void* vtable;
    int id;
    void* master_obj;          // +0x8
    UnitAIModule* unitAI();
};

struct UnitAIModule {
    int currentAction();
};

struct MainDecisionAIModule {
    RGE_Static_Object* object(int unitID);
};

struct ManagedArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct TribeTacticalAIModule {
    char pad_00[0x0F0];
    MainDecisionAIModule* md;  // +0xF0
    ManagedArray civilians;    // +0xF4 (value, numberValue=+0xF8, maxSize=+0x100)

    int numberFarmers();
};

int TribeTacticalAIModule::numberFarmers()
{
    int result = 0;
    int i = 0;

    if (civilians.numberValue <= 0)
        return result;

    do {
        if (i >= civilians.maximumSizeValue) {
            int* newArr = (int*)_new((i + 1) * 4);
            if (newArr != 0) {
                int j;
                for (j = 0; j < civilians.maximumSizeValue && j < i + 1; j++)
                    newArr[j] = civilians.value[j];
                _delete(civilians.value);
                civilians.value = newArr;
                civilians.maximumSizeValue = i + 1;
            }
        }

        int unitID = civilians.value[i];
        RGE_Static_Object* obj = md->object(unitID);
        if (obj != 0 && obj->unitAI() != 0) {
            // Check master_obj->id == 0x103 (no null check on master_obj)
            if (*(unsigned short*)((char*)obj->master_obj + 0x10) == 0x103) {
                if (obj->unitAI()->currentAction() == 0x261 ||
                    obj->unitAI()->currentAction() == 0x262) {
                    result++;
                }
            }
        }
        i++;
    } while (i < civilians.numberValue);

    return result;
}
