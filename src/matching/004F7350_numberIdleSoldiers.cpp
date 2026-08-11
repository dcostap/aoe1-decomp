// 004F7350 TribeTacticalAIModule::numberIdleSoldiers
// Source: taitacmd.cpp lines 6891-6904
// Counts soldiers whose UnitAIModule is idle and records them in workingArea.
//
// Attempt log:
// Probe 1 (baseline): rough raw-offset reconstruction rebuilt 573 bytes with
//   9 calls; helper shims lost the two unitAI calls and all three original
//   decorated member-call identities. Canonical fields were nevertheless the
//   soldiers and workingArea ManagedArray<int> members.
// Probe 2: restored the period ManagedArray operator[]/add bodies, typed
//   RGE_Game_World::object, RGE_Static_Object::unitAI, and UnitAIModule calls,
//   with md->aiPlayer->world ownership. Checking the natural source next.
// Probe 3: added ordinary references to the two array members, mirroring the
//   exact same-TU numberUngroupedSoldiers source so the reset precedes the
//   soldiers count load and indexed member expressions retain their address
//   term order.
// Probe 4: rewrote the inline indexer return as pointer addition; this is a
//   natural equivalent source spelling to test the two remaining SIB bytes.
// Probe 5: reversed the pointer-addition operands in the indexer return;
//   retained only as a focused address-term experiment.
// Probe 6: materialized the array pointer before the indexer return to test
//   whether a natural local pointer changes VC5's base/index encoding.
// Probe 7: restored the compact non-polymorphic local type context used by
//   the exact same-TU ManagedArray donor; the proven field offsets remain
//   unchanged while testing whether class vptr context affects SIB encoding.
// Probe 8: focused six-way indexer-return lab; every natural pointer/member
//   spelling stayed in the same two-byte SIB basin.
// Probe 9: focused ensure-then-direct-value lab; the explicit inline growth
//   spelling also stayed in the same two-byte SIB basin.
// Probe 10: restored the canonical indexer return and added the donor-TU
//   <stdlib.h> context as the final translation-unit hypothesis.

#include <stdlib.h>

extern "C" {
    void* operator_new(unsigned int size);
    void operator_delete(void* ptr);
}

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0;
                     i < this->maximumSizeValue && i < new_size;
                     i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int add(T valueToAdd) {
        int i;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                break;
            if (this->value[i] == valueToAdd)
                return 0;
        }

        if (this->numberValue > this->maximumSizeValue - 1) {
            int new_size = this->numberValue + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                int j;
                for (j = 0; j < this->maximumSizeValue; j++) {
                    if (j >= new_size)
                        break;
                    new_value[j] = this->value[j];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }

        this->value[this->numberValue] = valueToAdd;
        this->numberValue++;
        return 1;
    }
};

class RGE_Game_World;
class RGE_Static_Object;
class UnitAIModule;

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class TRIBE_Player : public RGE_Player {
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int objectID);
};

class RGE_Static_Object {
public:
    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    int currentAction();
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
    ManagedArray<int> objects;
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    TRIBE_Player* aiPlayer;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    char gap_124[0xD48 - 0x124];
    ManagedArray<int> workingArea;

    int numberIdleSoldiers();
};

int TribeTacticalAIModule::numberIdleSoldiers()
{
    int count = 0;
    int i = 0;
    ManagedArray<int>& workingArea = this->workingArea;
    ManagedArray<int>& soldiers = this->soldiers;

    workingArea.numberValue = 0;
    if (soldiers.numberValue > 0) {
        do {
            RGE_Static_Object* obj =
                this->md->aiPlayer->world->object(soldiers[i]);
            if ((obj != 0) && (obj->unitAI() != 0)) {
                if (obj->unitAI()->currentAction() == -1) {
                    workingArea.add(soldiers[i]);
                    count++;
                }
            }
            i++;
        } while (i < soldiers.numberValue);
    }
    return count;
}
