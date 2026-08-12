// VA: 004F7E80 TribeTacticalAIModule::idleCivilian
// PDB source: taitacmd.cpp lines 7075-7160
// Attempt log:
// - Fresh reconstruction follows the exact same-TU idleCivilian overload and
//   idleSoldier donors.  It uses named civilians, civilianExplorers, and
//   unitsTaskedThisUpdate ManagedArray members at their proven offsets.
// - The first pass uses explicit resize-before-value accesses.  The second
//   pass uses the period direct operator[] form only in the mode branch, which
//   accounts for the observed inline grow/copy block.
// - Structural reconstruction now matches the original frame, size within
//   12 bytes, and all 23 ordered calls.  Remaining drift is return-block
//   placement and register-sized branch displacements in the final tail.
// - Probes for an explicit second-pass guard, found labels, and for-loop form
//   did not improve emitted code.  The natural direct-return form is retained.

#include <stdlib.h>

void* operator_new(unsigned int size);
void operator_delete(void* ptr);

class UnitAIModule {
public:
    int currentAction();
    int currentOrder();
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;
    UnitAIModule* unitAI();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int objectID);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int contains(const int& value) const {
        int i;
        int current;
        for (i = 0; i < this->numberValue; i++) {
            if (i >= this->maximumSizeValue)
                return 0;
            current = this->value[i];
            if (current == value)
                return 1;
        }
        return 0;
    }

    int resize(int newSize);

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
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    char gap_114[0xD58 - 0x114];
    ManagedArray<int> unitsTaskedThisUpdate;

    int isGatherer(int objectID);
    int idleCivilian(int mode);
};

int TribeTacticalAIModule::idleCivilian(int mode)
{
    RGE_Static_Object* firstObject;
    RGE_Static_Object* secondObject;
    int i = 0;
    ManagedArray<int>& tasked = this->unitsTaskedThisUpdate;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (tasked.contains(civilians->value[i]) != 0)
                goto first_next;

            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            firstObject =
                this->md->player->world->object(civilians->value[i]);
            if ((firstObject != 0) && (firstObject->unitAI() != 0)) {
                if (i > civilians->maximumSizeValue - 1)
                    civilians->resize(i + 1);
                if (this->isGatherer(civilians->value[i]) == 0) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    if (this->civilianExplorers.contains(civilians->value[i]) != 0)
                        goto first_next;
                    if (firstObject->unitAI()->currentAction() == -1 &&
                        firstObject->unitAI()->currentOrder() == -1)
                        return firstObject->id;
                }
            }
first_next:
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue <= 0)
        return -1;

    {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            if (tasked.contains(civilians->value[i]) != 0)
                goto second_next;

            if (i > civilians->maximumSizeValue - 1)
                civilians->resize(i + 1);
            secondObject =
                this->md->player->world->object(civilians->value[i]);
            if ((secondObject != 0) && (secondObject->unitAI() != 0)) {
                if (mode != 0) {
                    if (mode != 3) {
                        if (i > civilians->maximumSizeValue - 1)
                            civilians->resize(i + 1);
                        if (this->isGatherer(civilians->value[i]) != 0)
                            goto second_next;
                    }
                }
                if ((mode != 0) && (mode != 1)) {
                    if (this->civilianExplorers.contains((*civilians)[i]) != 0)
                        goto second_next;
                }
                if (secondObject->unitAI()->currentAction() == -1 &&
                    secondObject->unitAI()->currentOrder() == -1)
                    return secondObject->id;
            }
second_next:
            i++;
        } while (i < this->civilians.numberValue);
    }
    return -1;
}
