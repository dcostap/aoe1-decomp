// VA: 004D96B0 TribeInformationAIModule::gameIDsOfObjectType
// Attempt log:
// try 1: direct behavioral reconstruction from decompiler/asm: scan importantObjects, filter by player/master, grow output arrays and important object vector as needed.
// try 2: helper-based ensureImportant compiled too small (624B vs 691B); inlined both growth sites like original.
// try 3: inlined importantObjects growth at top of each iteration, matching original operator new/delete copy loop family.
// try 4: inlined second importantObjects growth before writing accepted result.
// try 5: modeled output ids/owners allocation as two arrays sized maxCount*8, then doubled maxCount.
// try 6: modeled copy of old output arrays before freeing/replacing pointers.
// try 7: modeled special playerFilter -5 same-player exclusion.
// try 8: modeled special playerFilter -6 relation check via virtual call on current AI player.
// try 9: modeled ordinary player and object type filters using owner id and master id offsets.
// try 10: /GX probe no change; removed.
// try 11: /Od probe exact-size but wrong debug-basin codegen; removed.
// try 12: restored the same-TU RGE_Player virtual surface through vslot +0x14;
// relation is the +0x18 slot used by the original call.  The prior three-slot
// stub emitted an unrelated +0x0C virtual call and was not a valid ABI model.
// try 13: replaced the three-field array stub with the same-TU ManagedArray<int>
// surface.  This fixed maximumSizeValue at +0x124 and restored both inline
// growth blocks.  Direct md->aiPlayer->world ownership also removed an extra
// pointer hop.  The rebuilt body reached 319 differing bytes, then 24 bytes
// after removing the redundant positive-capacity copy guard.
// try 14: moved the loop-index initialization before the outer guard; exact
// size and all CFG/call counts now match.
// try 15: operand order, scoped aliases, combined relation predicate, and a
// final objectID local were neutral or worse.  The direct typed source is kept.
// left in scratch: 24 localized register/address bytes remain in the -5/-6
// player filters and final ID store.  Size, frame, calls, CFG, and 89.52% of
// blocks are exact; the remaining drift is not accepted_drift-safe.

// The information arrays use the inline ManagedArray<int> surface from the
// same translation unit.  Its desired-size member is real, even though this
// function does not read it; maximumSizeValue is therefore at +0x0C.
#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

class RGE_Game_World;

class RGE_Player {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08();
    virtual void vf0c(); virtual void vf10(); virtual void vf14();
    virtual int relation(int);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};
class RGE_Static_Object { public: char gap_00[8]; void* master; RGE_Player* owner; };
class RGE_Master_Object { public: char gap_00[0x10]; short id; };
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class TribeMainDecisionAIModule {
public:
    char gap_00[0x1256C];
    RGE_Player* aiPlayer;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)::operator new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                ::operator delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    TribeMainDecisionAIModule* md;
    char gap_104[0x14];
    ManagedArray<int> importantObjects;
    int gameIDsOfObjectType(int objectType, int** ids, int** owners, int playerFilter);
};

int TribeInformationAIModule::gameIDsOfObjectType(int objectType, int** ids, int** owners, int playerFilter)
{
    *ids = 0;
    int count = 0;
    *owners = 0;
    int maxCount = 10;
    int i = 0;
    if (this->importantObjects.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->aiPlayer->world->object(
                this->importantObjects[i]);
            if (obj != 0) {
                if (playerFilter == -5) {
                    if (this->md->aiPlayer->id == obj->owner->id) goto next;
                }
                if (playerFilter == -6) {
                    if (this->md->aiPlayer->relation(obj->owner->id) != 0) goto next;
                }
                if (playerFilter != -1 && obj->owner->id != playerFilter) goto next;
                if (objectType != -1 && objectType != ((RGE_Master_Object*)obj->master)->id) goto next;
                if (count == maxCount || *ids == 0) {
                    int* newIds = (int*)operator new(maxCount * 8);
                    int* newOwners = (int*)operator new(maxCount * 8);
                    if (*ids != 0) {
                        for (int j = 0; j < maxCount; j++) {
                            newIds[j] = (*ids)[j];
                            newOwners[j] = (*owners)[j];
                        }
                    }
                    maxCount *= 2;
                    if (*ids != 0) operator delete(*ids);
                    if (*owners != 0) operator delete(*owners);
                    *ids = newIds;
                    *owners = newOwners;
                }
                int objectID = this->importantObjects[i];
                (*ids)[count] = objectID;
                count++;
                (*owners)[count - 1] = obj->owner->id;
            }
next:
            i++;
        } while (i < this->importantObjects.numberValue);
    }
    return count;
}
