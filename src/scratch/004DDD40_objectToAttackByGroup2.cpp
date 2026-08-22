// VA 004DDD40 TribeInformationAIModule::objectToAttackByGroup2
// PDB source: taiinfmd.cpp:4253-4435
// Attempt log:
// 1: The prior scaffold had mismatched helper calls and broad code drift.
// 2: Rebuilt the typed ObjectMemory, object, visible-map, and unit-AI surfaces.
// 3: Exact donors prove both scoring helpers take (ids, count, object).
// 4: The +0xC4 unit-AI call takes the candidate ObjectMemory id, not its pointer.
// 5: The natural typed indexed array model is retained for important memories.
// 6: Direct coordinate conversions recover the repeated __ftol and visibility
//    sequence without volatile state or address macros.
// 7: The score comparison is `score > bestScore`; this emits the original
//    `test ah,41h` x87 predicate.
// 8: The score terms are evaluated as 0xb8*targetTime, 0x4d/distance, and
//    0x50*kills. The order follows the original strategic-number call sites.
// 9: Reused dx/dy across both coordinate blocks. The compiler output is
//    unchanged, which supports the ordinary shared-local model.
// 10: Best prior check was 1200 bytes, 332 instructions, and 597 differing
//     bytes. Calls aligned 31/31 and the frame was 0x40, but the result was not exact.
// 11: Restored canonical md->tacticalAI ownership and typed indexed memory
//     access. Emitted code stayed unchanged.
// 12: A typed per-iteration memory pointer was natural but lost 65 code bytes.
//     Restored the indexed form.
// 13: The original inner count scan tests count before loading ids or storing
//     remaining. Declaring both inside `if (count > 0)` recovers the test/store
//     block and improves the retained result to 579 differing bytes.
// 14: Tested the oracle random-branch polarity, early float kills conversion,
//     one score expression, and function-scope float locals. They were worse or
//     codegen duplicates and were restored.
// 15: Best current check is 1200 bytes, 332 instructions, and 579 differing
//     bytes. Calls align 31/31, frame is 0x40, and exact-block coverage is 28.53%.
// Remaining drift is mainly VC5 register and local-home allocation around the
// initial zero, coordinate scratch, and score locals.
// Main-agent audit: replaced the generated VPAD padding with the named
// UnitAIModule ABI surface through the binary-proven +0xC4 can_attack_mem
// override. No codegen-only volatility or inline assembly is retained.
// Structural probe: the original nonzero wonderToAttack branch returns its
// result; the zero return belongs only to the later null-commander paths.
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
    virtual int can_attack_mem(int objectId);
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
    char gap_0F4[0x10];
    RGE_Static_Object* object(int id);
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int number);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1146C - 0x104];
    TribeTacticalAIModule tacticalAI; // +0x1146C
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    TribeMainDecisionAIModule* md; // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory; // +0x110
    ObjectMemory* importantObjectMemory; // +0x114

    ObjectMemory* wonderToAttack(int type);
    float damageInflictedPerSecond(int* ids, int count, RGE_Static_Object* object);
    float timeToBeKilled(int* ids, int count, RGE_Static_Object* object);

    ObjectMemory* objectToAttackByGroup2(int group, int* ids, int count);
};

ObjectMemory* TribeInformationAIModule::objectToAttackByGroup2(int group, int* ids, int count)
{
    ObjectMemory* bestObject;
    ObjectMemory* wonder = this->wonderToAttack(-1);
    if (wonder != 0) {
        return wonder;
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

                bestObject = 0;
                float bestScore = -1.0f;
                float bestAttackValue = 0.0f;
                int timeTK = 0;

                if (this->maxImportantObjectMemory > 0) {
                    do {
                        if (this->importantObjectMemory[timeTK].owner == group) {
                            RGE_Static_Object* object =
                                this->md->object(this->importantObjectMemory[timeTK].id);
                            if (object != 0) {
                                int dx;
                                int dy;
                                if (object->object_state <= 2 && object->hp != DAT_00575580) {
                                    dx = (int)this->importantObjectMemory[timeTK].x - (int)object->world_x;
                                    if (dx < 0) {
                                        dx = -dx;
                                    }
                                    dy = (int)this->importantObjectMemory[timeTK].y - (int)object->world_y;
                                    if (dy < 0) {
                                        dy = -dy;
                                    }

                                    if ((dx <= 5 && dy <= 5) ||
                                        this->md->player->visible->get_visible(
                                            (int)object->world_x, (int)object->world_y) == 0x0f) {
                                        // BINARY NOTE: slot +0xC4 receives ObjectMemory::id.
                                        if (commanderIsPriest == 0 ||
                                            commanderObj->unitAI()->can_attack_mem(this->importantObjectMemory[timeTK].id) != 0) {
                                            float damage;
                                            float hpOverDamage;
                                            float time;
                                            float targetTime;
                                            float targetDistance;
                                            damage = this->damageInflictedPerSecond(ids, count, object);
                                            hpOverDamage = object->hp / damage;
                                            time = this->timeToBeKilled(ids, count, object);
                                            if (damage != DAT_00575580 && time != DAT_00575580) {
                                                targetTime = time / hpOverDamage;
                                                int targetX = (int)commanderObj->world_x;
                                                int targetY = (int)commanderObj->world_y;
                                                dx = (int)this->importantObjectMemory[timeTK].x - targetX;
                                                dy = (int)this->importantObjectMemory[timeTK].y - targetY;
                                                targetDistance = (float)sqrt((float)(dx * dx + dy * dy));
                                                if (targetDistance < DAT_00575564) {
                                                    targetDistance = 1.0f;
                                                }

                                                int randomNumber = this->md->tacticalAI.strategicNumber(0x53);
                                                if (randomNumber < 1) {
                                                    bestAttackValue = 0.0f;
                                                } else {
                                                    int randomRange = this->md->tacticalAI.strategicNumber(0x53);
                                                    bestAttackValue = (float)(debug_rand((char*)0x5878dc, 0x110b) % randomRange);
                                                }

                                                int killCount =
                                                    this->importantObjectMemory[timeTK].kills;
                                                float attackAttemptFactor =
                                                    (float)this->md->tacticalAI.strategicNumber(0x59) *
                                                    (float)this->importantObjectMemory[timeTK].attackAttempts;
                                                float targetRandomization = 0.0f;
                                                int lookupX = (int)object->world_x;
                                                int lookupY = (int)object->world_y;
                                                if (commanderZone == commanderObj->lookupZone(lookupX, lookupY)) {
                                                    targetRandomization = (float)this->md->tacticalAI.strategicNumber(0x7a);
                                                }

                                                float zoneFactor = 0.0f;
                                                int strategicB9 = this->md->tacticalAI.strategicNumber(0xb9);
                                                if (strategicB9 > 0) {
                                                    int currentTargetCount = 0;
                                                    if (count > 0) {
                                                        int* currentID = ids;
                                                        int remaining = count;
                                                        do {
                                                            RGE_Static_Object* currentObject = this->md->object(*currentID);
                                                            if (currentObject != 0 && currentObject->unitAI() != 0 &&
                                                                currentObject->unitAI()->currentTarget() ==
                                                                    this->importantObjectMemory[timeTK].id) {
                                                                ++currentTargetCount;
                                                            }
                                                            ++currentID;
                                                            --remaining;
                                                        } while (remaining != 0);
                                                    }
                                                    zoneFactor = (float)this->md->tacticalAI.strategicNumber(0xb9) * (float)currentTargetCount;
                                                }

                                                // BINARY NOTE: VC5 evaluates these weights in this order.
                                                float score =
                                                    (float)this->md->tacticalAI.strategicNumber(0xb8) *
                                                    targetTime;
                                                score +=
                                                    (float)this->md->tacticalAI.strategicNumber(0x4d) /
                                                    targetDistance;
                                                score +=
                                                    (float)this->md->tacticalAI.strategicNumber(0x50) *
                                                    (float)killCount;
                                                score += zoneFactor;
                                                score += targetRandomization;
                                                score += attackAttemptFactor;
                                                score += bestAttackValue;
                                                if (bestObject == 0 || score > bestScore) {
                                                    bestObject = &this->importantObjectMemory[timeTK];
                                                    bestScore = score;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        ++timeTK;
                    } while (timeTK < this->maxImportantObjectMemory);
                }
                return bestObject;
            }
        }
    }
    return 0;
}
