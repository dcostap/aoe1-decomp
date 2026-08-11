// VA: 00415B50 UnitAIModule::closestAttacker (328B)
// aiuaimod.cpp:2579-2600
//
// Attempt log:
// - Replaced the former placeholder with the binary-supported attacking-units
//   ManagedArray<int> surface, owner/world object lookup, distance comparison,
//   selected-ID tracking, and optional float output.
// - Baseline: period utmarray.h inline operator[] growth body and a positive-
//   count do/while scan; exact call set, but the distance local was optimized
//   into the x87 stack and the frame was four bytes short.
// - Promoted distance to a function-scope local and reversed selected-ID versus
//   threshold assignment order. This restored the separate FPU spill, frame,
//   CFG, call-site relocations, and all late blocks.
// - A volatile-distance diagnostic confirmed the spill cause but was removed.
//   Declaration/init permutations and a focused six-case init-order lab did not
//   produce the oracle's store order.
// - Reordered the local declarations to selected ID, threshold, loop index,
//   distance, matching the same-TU weakestEnemy donor's declaration style. This
//   preserved the natural source and emitted the oracle's sentinel-before-zero
//   stores exactly: MATCH (328/328 bytes, 6/6 calls, default flags).

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl operator_delete(void* block);
}

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int index);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    int id;                         // +0x04
    void* master_obj;               // +0x08
    RGE_Player* owner;              // +0x0C

    float distance_to_object(RGE_Static_Object* other);
};

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
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
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

class UnitAIModule {
public:
    virtual ~UnitAIModule();

    RGE_Static_Object* objectValue; // +0x04
    char gap_08[0x60 - 0x08];
    ManagedArray<int> attackingUnitsValue; // +0x60
    char gap_70[0x134 - 0x70];

    virtual int closestAttacker(float* attackDistance);
};

int UnitAIModule::closestAttacker(float* attackDistance) {
    int attackObject;
    float largestThreat;
    int i;
    float distance;

    attackObject = -1;
    largestThreat = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (object != 0) {
                distance = this->objectValue->distance_to_object(object);
                if (attackObject == -1 || distance < largestThreat) {
                    attackObject = this->attackingUnitsValue[i];
                    largestThreat = distance;
                }
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    if (attackDistance != 0)
        *attackDistance = largestThreat;
    return attackObject;
}
