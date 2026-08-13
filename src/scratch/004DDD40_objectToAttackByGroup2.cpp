// VA 004DDD40 TribeInformationAIModule::objectToAttackByGroup2
// PDB source: taiinfmd.cpp:4253-4435
// Attempt log:
// 1: Baseline decompiler-shaped helper/field scaffold was 1056 bytes with mismatched helper calls and broad drift.
// 2: Reconstructed the canonical ObjectMemory/RGE object/visible-map/unit-AI surfaces, corrected the parameter order, and restored the period scoring expression and call sequence.
// 3: Replaced fake liveness/zone/attack-factor helpers with direct unitAI/currentZone/visible-map/currentTarget/can-attack surfaces and the four observed coordinate conversions.
// 4: Used narrow volatile coordinate rereads only for the binary-proven post-call __ftol pair; this preserves the two repeated conversions without volatile object state.
// 5: Restored the observed <=2/>0 candidate gate, <=5 proximity algebra, priest result local, and candidate-coordinate lookupZone conversion.
// 6: Removed the volatile post-distance temporaries but retained named lookup coordinates; the intervening calls already force the binary-proven commander reread.
// 7: Bound zero/one comparisons to the shared DAT_00575580/DAT_00575564 constants, matching the original data references rather than literal constants.
// 8: Matched binary promotion/reload surfaces: owner compares as promoted int, hp uses != zero, and kills/attack-attempt weighting are captured before later lookup calls.
// 9: Declared the loop byte offset at function scope but initialized it at loop entry, matching the original low stack offset and delayed initialization.
// Main-agent audit: replaced the generated VPAD padding with the named
// UnitAIModule ABI surface through the binary-proven +0xC4 can_attack_mem
// override. No codegen-only volatility or inline assembly is retained.
// Continuation probe: moved hp-over-damage before timeToBeKilled to match the
// original FPU statement order; structure improved, bytes worsened.

#include "../../include/game_globals.h"
#include <math.h>

extern int debug_rand(char* file, int line);
void* operator new(unsigned int size);
void operator delete(void* ptr);

class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Visible_Map;
class RGE_Player;
class UnitAIModule;
class MainDecisionAIModule;
class TribeTacticalAIModule;

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char _pad_0[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char _pad_1[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char _pad_0[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x34];
    RGE_Visible_Map* visible; // +0x38
    void* world;              // +0x3C
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int);
    virtual int attackObject(int, int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int, int);
    virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int);
    virtual int repairObject(int, int);
    virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int);
    virtual int explore(int, int, int);
    virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int);
    virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int can_attack_mem(ObjectMemory* memory);
    int currentTarget();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id; // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner; // +0x0C
    char gap_10[0x20];
    float hp; // +0x30
    char gap_34[4];
    float world_x; // +0x38
    float world_y; // +0x3C
    float world_z; // +0x40
    float attribute_amount_held; // +0x44
    unsigned char object_state; // +0x48
    char gap_49[0x2B];
    UnitAIModule* unitAIValue; // +0x74

    UnitAIModule* unitAI();
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player; // +0xF0
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int number);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md; // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory; // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    ObjectMemory* wonderToAttack(int type);
    float damageInflictedPerSecond(int group, int* ids, RGE_Static_Object* object);
    float timeToBeKilled(int group, int* ids, RGE_Static_Object* object);

    ObjectMemory* objectToAttackByGroup2(int group, int* ids, int count);
};

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(int group, int* ids, int count)
{
    int byteOffset;
    ObjectMemory* wonder = this->wonderToAttack(-1);
    if (wonder != 0) {
        return 0;
    }

    if (count != 0) {
        RGE_Static_Object* commanderObj = this->md->object(*ids);
        if (commanderObj != 0) {
            if (commanderObj->unitAI() != 0) {
                unsigned char commanderZone = commanderObj->currentZone();
                int commanderIsPriest = 0;
                if (commanderObj->master_obj->object_group == 0x12) {
                    commanderIsPriest = 1;
                }

                float bestAttackValue = 0.0f;
                float bestScore = -1.0f;
                float timeTK = 0.0f;
                int i = 0;
                ObjectMemory* bestObject = 0;

                if (this->maxImportantObjectMemory > 0) {
                    byteOffset = 0;
                    do {
                        ObjectMemory* memory = (ObjectMemory*)((char*)this->importantObjectMemory + byteOffset);
                        if (memory->owner == group) {
                            RGE_Static_Object* object = this->md->object(memory->id);
                            if (object != 0) {
                                if (object->object_state <= 2 && object->hp != DAT_00575580) {
                                    int x = (int)object->world_x;
                                    int y = (int)object->world_y;
                                    int dx = (int)memory->x - x;
                                    if (dx < 0) {
                                        dx = -dx;
                                    }
                                    int dy = (int)memory->y - y;
                                    if (dy < 0) {
                                        dy = -dy;
                                    }

                                    if ((dx <= 5 && dy <= 5) ||
                                        this->md->player->visible->get_visible(x, y) == 0x0f) {
                                        if (commanderIsPriest == 0 ||
                                            commanderObj->unitAI()->can_attack_mem(memory) != 0) {
                                            float damage = this->damageInflictedPerSecond(group, ids, object);
                                            float hpOverDamage = object->hp / damage;
                                            float time = this->timeToBeKilled(group, ids, object);
                                            if (damage != DAT_00575580 && time != DAT_00575580) {
                                                float targetTime = time / hpOverDamage;
                                                int targetX = (int)commanderObj->world_x;
                                                int targetY = (int)commanderObj->world_y;
                                                int distanceX = (int)memory->x - targetX;
                                                int distanceY = (int)memory->y - targetY;
                                                float targetDistance = (float)sqrt((float)(distanceX * distanceX + distanceY * distanceY));
                                                if (targetDistance < DAT_00575564) {
                                                    targetDistance = 1.0f;
                                                }

                                                int randomNumber = ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0x53);
                                                if (randomNumber < 1) {
                                                    bestAttackValue = 0.0f;
                                                } else {
                                                    int randomRange = ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0x53);
                                                    bestAttackValue = (float)(debug_rand((char*)0x5878dc, 0x110b) % randomRange);
                                                }

                                                int killCount = memory->kills;
                                                float attackAttemptFactor =
                                                    (float)((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0x59) *
                                                    (float)memory->attackAttempts;
                                                float targetRandomization = 0.0f;
                                                int lookupX = (int)object->world_x;
                                                int lookupY = (int)object->world_y;
                                                if (commanderZone == commanderObj->lookupZone(lookupX, lookupY)) {
                                                    targetRandomization = (float)((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0x7a);
                                                }

                                                float zoneFactor = 0.0f;
                                                int strategicB9 = ((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0xb9);
                                                if (strategicB9 > 0) {
                                                    int currentTargetCount = 0;
                                                    int remaining = count;
                                                    int* currentID = ids;
                                                    if (remaining > 0) {
                                                        do {
                                                            RGE_Static_Object* currentObject = this->md->object(*currentID);
                                                            if (currentObject != 0 && currentObject->unitAI() != 0 &&
                                                                currentObject->unitAI()->currentTarget() == memory->id) {
                                                                ++currentTargetCount;
                                                            }
                                                            ++currentID;
                                                            --remaining;
                                                        } while (remaining != 0);
                                                    }
                                                    zoneFactor = (float)((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0xb9) * (float)currentTargetCount;
                                                }

                                                float score = (float)((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0xb8) * (float)killCount;
                                                score += (float)((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0x4d) / targetDistance;
                                                score += (float)((TribeTacticalAIModule*)((char*)this->md + 0x1146C))->strategicNumber(0x50) * targetTime;
                                                score += zoneFactor;
                                                score += targetRandomization;
                                                score += attackAttemptFactor;
                                                score += bestAttackValue;
                                                if (bestObject == 0 || bestScore < score) {
                                                    bestObject = memory;
                                                    bestScore = score;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        ++i;
                        byteOffset += 0x24;
                    } while (i < this->maxImportantObjectMemory);
                }
                return bestObject;
            }
        }
    }
    return 0;
}
