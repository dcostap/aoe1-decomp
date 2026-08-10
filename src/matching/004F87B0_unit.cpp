// 004F87B0 TribeTacticalCommand::unit
// taitacmd.cpp: 7336-7374
// Attempt log:
// - Prior worker used helper-factored growth/filter code and stopped at 704B;
//   the packet proves five inline ManagedArray growth blocks plus one real
//   resize call, so this candidate restores those source-level surfaces.
// - Baseline candidate: civilians, soldiers, and boats are the named
//   ManagedArray<int> members at +0xF4, +0x114, and +0x134.  The null-object
//   UnitAI filter is intentionally retained because the executable calls
//   unitAI with a null receiver before checking the three wildcard filters.
// - Probe 1 baseline: 1127B, 35/35 ordered calls, 92.60% shape; helper
//   factoring was gone but the second/third success paths still had duplicate
//   explicit growth checks.
// - Probe 2: returned `soldiers[i]`/`boats[i]` directly through the inline
//   operator[] and reached exact size (1071B), leaving a localized boat-loop
//   topology hunk.  Probe 3 changed that scan to the natural top-tested while
//   form and reduced the remaining drift to 33 bytes.
// - Probes 4-5: a function-wide civilians pointer/reference alias perturbed
//   the prologue and broad register basin; rolled back.  Probe 6 used a
//   branch-local typed result-array pointer, assigned only on civilian success,
//   preserving the original EDI receiver into the late shared return.
// - Exact candidate: 1071B, 35/35 ordered calls, 100% shape, 0-byte strict
//   diff.  The null-receiver call and branch-local result pointer are retained
//   because both are directly supported by the original instruction flow.
// Source audit: the null-receiver UnitAI call is the executable's observed
// short-circuit order, including its apparent original bug; the surrounding
// player/AI/object surfaces now use the proven polymorphic boundaries and
// named member offsets without raw address plumbing.

#include <stdlib.h>

typedef unsigned long ulong;

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* block);

struct RGE_Static_Object;
struct UnitAIModule;

struct RGE_Game_World {
    RGE_Static_Object* object(int id);
};

struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    RGE_Player* aiPlayer;
    char gap_12570[0x58];
};

struct UnitAIModule {
    virtual ~UnitAIModule();
    int currentAction();
    int currentTarget();
    int currentTargetType();
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    UnitAIModule* unitAI();
};

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

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

    int resize(int new_size);
};

struct TribeTacticalCommand {
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;

    int unit(int player, int currentAction, int currentTargetType);
};

int TribeTacticalCommand::unit(int player, int currentAction, int currentTargetType)
{
    int i = 0;
    ManagedArrayInt* resultArray;

    while (i < this->civilians.numberValue) {
        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->civilians[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (player != -1) {
                if (object->unitAI()->currentAction() != player)
                    goto next_civilian;
            }
            if (currentAction != -1) {
                if (object->unitAI()->currentTarget() != currentAction)
                    goto next_civilian;
            }
            if (currentTargetType == -1) {
                resultArray = &this->civilians;
                goto found_civilian;
            }
            if (object->unitAI()->currentTargetType() == currentTargetType) {
                resultArray = &this->civilians;
                goto found_civilian;
            }
        }
next_civilian:
        ++i;
    }

    i = 0;
    while (i < this->soldiers.numberValue) {
        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->soldiers[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (player != -1) {
                if (object->unitAI()->currentAction() != player)
                    goto next_soldier;
            }
            if (currentAction != -1) {
                if (object->unitAI()->currentTarget() != currentAction)
                    goto next_soldier;
            }
            if (currentTargetType != -1) {
                if (object->unitAI()->currentTargetType() != currentTargetType)
                    goto next_soldier;
            }
            return this->soldiers[i];
        }
next_soldier:
        ++i;
    }

    i = 0;
    while (i < this->boats.numberValue) {
        RGE_Static_Object* object = this->md->aiPlayer->world->object(this->boats[i]);
        if (object == 0 && object->unitAI() == 0) {
            if (player != -1) {
                if (object->unitAI()->currentAction() != player)
                    goto next_boat;
            }
            if (currentAction != -1) {
                if (object->unitAI()->currentTarget() != currentAction)
                    goto next_boat;
            }
            if (currentTargetType != -1) {
                if (object->unitAI()->currentTargetType() != currentTargetType)
                    goto next_boat;
            }
            return this->boats[i];
        }
next_boat:
        ++i;
    }
    return -1;

found_civilian:
    if (i > resultArray->maximumSizeValue - 1)
        resultArray->resize(i + 1);
    return resultArray->value[i];

}
