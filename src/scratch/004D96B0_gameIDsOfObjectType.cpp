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
// left in scratch: current clean source is exact-size 691B but mismatch is broad allocation/copy-loop/register/control-flow drift, not accepted_drift-safe.

extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);

class RGE_Player {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual int relation(int);
    char gap_04[0x46]; short id;
};
class RGE_Static_Object { public: char gap_00[8]; void* master; RGE_Player* owner; };
class RGE_Master_Object { public: char gap_00[0x10]; short id; };
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class AIPlayer { public: char gap_00[0x1256C]; RGE_Player* player; };
class MainDecision { public: AIPlayer* aiPlayer; };
struct IntArray { int* value; int numberValue; int maximumSizeValue; };

class TribeInformationAIModule {
public:
    char gap_000[0x100];
    MainDecision* md;
    char gap_104[0x14];
    IntArray importantObjects;
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
            if (this->importantObjects.maximumSizeValue - 1 < i) {
                int* nv0 = (int*)operator new(i * 4 + 4);
                if (nv0 != 0) {
                    int k0 = 0;
                    if (this->importantObjects.maximumSizeValue > 0) {
                        do {
                            if (k0 >= i + 1) break;
                            nv0[k0] = this->importantObjects.value[k0];
                            k0++;
                        } while (k0 < this->importantObjects.maximumSizeValue);
                    }
                    operator delete(this->importantObjects.value);
                    this->importantObjects.value = nv0;
                    this->importantObjects.maximumSizeValue = i + 1;
                }
            }
            RGE_Game_World* world = *(RGE_Game_World**)((char*)this->md->aiPlayer->player + 0x3C);
            RGE_Static_Object* obj = world->object(this->importantObjects.value[i]);
            if (obj != 0) {
                if (playerFilter == -5) {
                    if (*(short*)((char*)this->md->aiPlayer->player + 2) == obj->owner->id) goto next;
                }
                if (playerFilter == -6) {
                    if (this->md->aiPlayer->player->relation(obj->owner->id) != 0) goto next;
                }
                if (playerFilter != -1 && obj->owner->id != playerFilter) goto next;
                if (objectType != -1 && objectType != ((RGE_Master_Object*)obj->master)->id) goto next;
                if (count == maxCount || *ids == 0) {
                    int* newIds = (int*)operator new(maxCount * 8);
                    int* newOwners = (int*)operator new(maxCount * 8);
                    if (*ids != 0 && maxCount > 0) {
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
                if (this->importantObjects.maximumSizeValue - 1 < i) {
                int* nv1 = (int*)operator new(i * 4 + 4);
                if (nv1 != 0) {
                    int k1 = 0;
                    if (this->importantObjects.maximumSizeValue > 0) {
                        do {
                            if (k1 >= i + 1) break;
                            nv1[k1] = this->importantObjects.value[k1];
                            k1++;
                        } while (k1 < this->importantObjects.maximumSizeValue);
                    }
                    operator delete(this->importantObjects.value);
                    this->importantObjects.value = nv1;
                    this->importantObjects.maximumSizeValue = i + 1;
                }
            }
                (*ids)[count] = this->importantObjects.value[i];
                count++;
                (*owners)[count - 1] = obj->owner->id;
            }
next:
            i++;
        } while (i < this->importantObjects.numberValue);
    }
    return count;
}
