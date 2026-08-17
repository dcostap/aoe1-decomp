// VA 004D9240 TribeInformationAIModule::gameIDOfResourceObject
// taiinfmd.cpp:1188-1484
// Attempt log:
// 1: Natural reconstruction from packet/decompiler, modeling ResourceMemory scan and scoring/filter logic.
// 2: Added output resource id initialization to -1 and mainDecision object(gathererId) lookup/null return.
// 3: Added currentZone and __ftol-style gatherer X/Y capture plus isBoat(gatherer) classification.
// 4: Added resource-list scan over arrays at +0x4D0/+0x4E0 and ResourceMemory stride 0x14 with dead/delay handling.
// 5: Added caller-supplied exclusion-list scan and missing-object dead marking/dropsite-update detection.
// 6: Added boat-vs-land class filters for classes 5/0x1F/0x21.
// 7: Added score calculation from squared tile distance, memory base field, age/amount divisors, numberGatherersWithTarget pressure, and best-score replacement.
// 8: Added special filters for animals/farms/buildings: towncenter/enemy attack checks, same-civ/state checks, important-id scan, per-resource gatherer thresholds, strategic-number/resource-count test.
// 9: Added gatherer lookupZone equality gate and final best-object result update: increment memory byte +6, write resource id, return memory id.
// 10: Fixed VC5 goto-crosses-initialization errors by hoisting loop locals.
// 11: Default /O2 /Oy exact-size build compares but is broad: 954 bytes / 84.4248% positional, first mismatch offset 9. Main early issue is register allocation/prologue: original keeps this in ESI and object in EDI; rebuilt keeps this in EBP and object in ESI, cascading through the function.
// 12: Probed /O2 /Oy /Ob0: identical broad mismatch; removed flag.
// 13: Probed /Od: exact size but wrong basin from offset 0 (91.5044% positional); removed flag.
// 14: Probed /O2 /Oy /Og-: exact size but wrong basin from offset 0 (91.5044% positional); removed flag.
// 15: Replaced the out-of-line tactical() wrapper with direct +0x1146C typed calls and bound the threshold to DAT_00575568; this removes six extra wrapper call sites and restores the original global identity, while retaining the clean reconstruction.
// 16: Restored canonical RGE_Static_Object/RGE_Master_Static_Object offsets and ResourceMemory/ManagedArray ownership names (vptr, id, gatherValue, farmsTaskedThisUpdate); this is a source/layout reconstruction probe, not a raw-offset workaround.
// 17: Changed the gatherer gate to a positive outer guard with the shared -1 epilogue, matching the original far JE topology instead of an early negative return.
// 18: Corrected two binary-proven farm/strategic rejection edges to the shared next-resource path (004D9642/004D9646); removed the decompiler-only skip_restore label.
// GIVEUP: left in scratch. Behavior is broad but source/register topology is far from original; no accepted_drift because mismatch is broad and begins in prologue/register allocation.
// Main-agent audit: a donor-backed virtual-destructor replacement for the
// proven vptr fields was tested and rolled back because it changed the early
// VC5 prologue/register basin. The typed vptr fields remain explicit binary
// layout evidence in this unresolved scratch reconstruction.
// 19: Same-TU taiinf donors and ABI evidence show md->object returns a typed
// RGE_Static_Object*. Corrected that ownership surface and removed two casts;
// this is a direct typed-call probe, not a register-coloring adjustment.
// 20-29: Tested standard headers, full AIModule inheritance, polymorphic owner
// surfaces, top-level local declarations, cursor forms, and for/do loop forms.
// The best clean basin is 1075/1130 bytes, 88.29% shape, 51.51% exact blocks,
// with all 16 calls aligned. The first mismatch remains the prologue at +9.
// BINARY NOTE: master object_group is at +0x14; the +0x12 pad is required.
// BINARY NOTE: town-center gather attempts use signed division by 150.
// BINARY NOTE: the amount bonus uses a strict greater-than threshold.
// UNRESOLVED: original keeps this in ESI, the candidate object in EDI, and
// score in EBP; this source keeps this in EBP and the candidate in ESI.

#include <math.h>
#include <stdlib.h>
#include <string.h>

extern double __cdecl floor(double);
extern float DAT_00575568;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap04[0x0C];
    short id;         // +10
    short gap12;      // +12
    short object_group; // +14
};
struct Player {
    virtual ~Player();
    char gap04[0x46];
    short civ_id;     // +4A
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;           // +4
    RGE_Master_Static_Object* master_obj; // +8
    Player* player;   // +C
    char gap10[0x38-0x10];
    float x;          // +38
    float y;          // +3C
    float z;          // +40
    float amount;     // +44
    unsigned char state; // +48
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
};
struct ResourceMemory {
    int id;          // +00
    unsigned char x; // +04
    unsigned char y; // +05
    unsigned char gatherAttempts; // +06
    char gap07;
    int gatherValue;  // +08
    unsigned char valid; // +0C
    unsigned char gone;  // +0D
    unsigned char dropDistance; // +0E
    unsigned char resourceType; // +0F
    int dropsiteID; // +10
};
template <class T>
struct ManagedArray {
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) { return this->value[index]; }
};
typedef ManagedArray<int> ManagedArray_int;
struct MainDecisionAIModule {
    virtual ~MainDecisionAIModule();
    char gap0[0xEC];
    Player* player; // +F0
    ManagedArray_int objects; // +F4
    RGE_Static_Object* object(int id);
};
struct TribeTacticalAIModule {
    int numberGatherersWithTarget(int id);
    int strategicNumber(int id);
    int actualGathererCountByRealResourceID(int id);
};
struct TribeMainDecisionAIModule : MainDecisionAIModule {
    char gap104[0x1146C-0x104];
    TribeTacticalAIModule tacticalAI; // +1146C
};

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    virtual ~AIModule();
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class TribeInformationAIModule : public InformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    ManagedArray_int farmsTaskedThisUpdate; // +F0
    TribeMainDecisionAIModule* md; // +100
    char gap104[0x4D0-0x104];
    ResourceMemory* resources[4]; // +4D0
    int numResources[4]; // +4E0
    char gap4F0[0x550-0x4F0];
    int dropsiteIds[4]; // +550

    int gameIDOfResourceObject(int resType, int gathererId, float& outX, float& outY, int& outResourceId, int* exclude, int excludeCount);
    int isBoat(RGE_Static_Object*);
    int withinXTilesOfEnemyTowncenter(RGE_Static_Object*, int);
    int withinXTilesOfAttackOnPlayer(RGE_Static_Object*, int, int);
    void updateResourceDropsites(int);
};

int TribeInformationAIModule::gameIDOfResourceObject(int resType, int gathererId, float& outX, float& outY, int& outResourceId, int* exclude, int excludeCount)
{
    unsigned char zone;
    int gx;
    int gy;
    int boat;
    ResourceMemory* bestObject;
    ResourceMemory* bestValue;
    int fishingBoat;
    int needUpdateDropsite;
    int i;
    int excluded;
    int j;
    RGE_Static_Object* obj;
    int dx;
    int dy;
    int score;
    short cls3;
    short cls;
    short cls2;
    int k;
    RGE_Static_Object* gatherer;

    outResourceId = -1;
    gatherer = this->md->object(gathererId);
    if (gatherer) {

    zone = gatherer->currentZone();
    gx = (int)gatherer->x;
    gy = (int)gatherer->y;
    boat = this->isBoat(gatherer);

    bestObject = 0;
    bestValue = 0;
    fishingBoat = -1;
    needUpdateDropsite = 0;

    i = 0;
    if (this->numResources[resType] > 0) {
        do {
            bestObject = (ResourceMemory*)((char*)this->resources[resType] + (int)bestObject);
            if (bestObject->gone == 1) goto next;
            if (bestObject->valid != 0) {
                if (bestObject->gone != 0) goto next;
                --bestObject->valid;
                goto next;
            }
            excluded = 0;
            for (j = 0; j < excludeCount; ++j) {
                if (exclude[j] == bestObject->id) { excluded = 1; break; }
            }
            if (excluded == 1) goto next;
            obj = this->md->object(bestObject->id);
            if (!obj) {
                bestObject->gone = 1;
                if (this->dropsiteIds[resType] == bestObject->id) needUpdateDropsite = 1;
                goto next;
            }
            if (boat == 1) {
                cls = obj->master_obj->object_group;
                if (cls != 5 && cls != 0x1f && cls != 0x21) goto next;
            }
            if (boat == 0) {
                cls2 = obj->master_obj->object_group;
                if (cls2 == 5 || cls2 == 0x1f || cls2 == 0x21) goto next;
            }
            dx = gx - bestObject->x;
            dy = gy - bestObject->y;
            score = dx * dx + dy * dy + bestObject->gatherValue * 10;
            if (obj->master_obj->id == 0x3b) {
                if (bestObject->dropDistance > 0x14) goto next;
                score += ((int)bestObject->gatherAttempts) / 150;
                if (this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 2) score += 200;
            } else {
                score += ((int)bestObject->gatherAttempts) / 50;
            }
            if (bestValue && score >= fishingBoat) goto next;
            cls3 = obj->master_obj->object_group;
            if ((cls3 == 9 || cls3 == 10) && obj->state > 2 && obj->amount > DAT_00575568) score += 25;
            if (this->withinXTilesOfEnemyTowncenter(obj, 25) == 1) goto next;
            if (this->withinXTilesOfAttackOnPlayer(obj, 15, this->md->player->civ_id) == 1) score += 500;
            if (obj->master_obj->id == 0x32) {
                if (obj->player->civ_id != this->md->player->civ_id) goto next;
                if (obj->state != 2) goto next;
                if (this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 0) goto next;
                k = 0;
                while (k < this->farmsTaskedThisUpdate.numberValue) {
                    if (k >= this->farmsTaskedThisUpdate.maximumSizeValue) break;
                    if (this->farmsTaskedThisUpdate[k] == obj->id) goto next;
                    ++k;
                }
            }
            if (resType == 1 && this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 0) goto next;
            if ((resType == 3 || resType == 2) && this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 3) goto next;
            if (obj->master_obj->id == 0x30 && obj->state == 2) {
                int want = this->md->tacticalAI.strategicNumber(0xcc);
                if (this->md->tacticalAI.actualGathererCountByRealResourceID(0) < want) goto next;
            }
            if (gatherer->lookupZone(bestObject->x, bestObject->y) != zone) goto next;
            if (bestValue && score >= fishingBoat) goto next;
            bestValue = bestObject;
            fishingBoat = score;
            outX = obj->x;
            outY = obj->y;
next:
            ++i;
            bestObject = (ResourceMemory*)((char*)bestObject + 20);
        } while (i < this->numResources[resType]);
    }

        if (needUpdateDropsite == 1) this->updateResourceDropsites(resType);
        if (bestValue) {
            bestValue->gatherAttempts++;
            outResourceId = bestValue->dropsiteID;
            return bestValue->id;
        }
    }
    return -1;
}
