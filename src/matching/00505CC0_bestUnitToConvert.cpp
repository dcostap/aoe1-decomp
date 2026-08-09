// 00505CC0 TribePriestUnitAIModule::bestUnitToConvert
// taiuaimd.cpp:1517-1558, 263 bytes
//
// int __thiscall TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
// - ret 4 cleanup (1 stack param + this in ecx)
//
// Returns: best unit ID (int), or -1 if none found
// param_1: optional output for priority value (can be NULL)
//
// === Attempt log ===
// 1: C-style function pointer virtual calls; RGE_Player class with virtual
//    Compiled to 263 bytes, 79% positional diff (~208 bytes mismatched)
//    Virtual calls use __cdecl (ecx not set = wrong calling convention)
//    Stack frame: sub esp,10h + push ebx,ebp vs sub esp,0Ch + push ebp,edi
//    Same TU-context register cascade as other view/tai functions
// 2: No virtual functions in any class — .text section issue (263 > 256)
//    Function body 246 bytes (17 bytes short of original)
// 3: Restored exact same-TU UnitAIModule, RGE_Player, and object virtual
//    surfaces; typed search/isEnemy/canConvert calls reached 263 bytes and
//    94.51% shape, with the remaining differences localized to relocations and
//    initial local-home ordering.
// 4: Used the canonical game_globals.h declarations and the proven 8-byte
//    visible-unit record instead of a locally typed global; emitted code was
//    unchanged, but relocation identity became eligible for exact matching.
// 5: Declared targetValue before the loop index, matching the original
//    target-value store before the loop-count home. Exact 263-byte match.

#include <stdlib.h>
#include "../../include/game_globals.h"

typedef unsigned char uchar;

struct VISIBLE_UNIT_REC {
    int object_id;
    uchar distance;
    uchar player;
    uchar pos_x;
    uchar pos_y;
};

struct RGE_Master_Static_Object {
    char gap_00[0x26];
    short hp;                         // +0x26
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(int);
    virtual void do_resign();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual int aiStatus();
    virtual int isEnemy(int player_id); // slot 6, +0x18
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                            // +0x04
    RGE_Master_Static_Object* master; // +0x08
    RGE_Player* owner;                // +0x0C
    char gap_10[0x38];                // +0x10 .. +0x47
    uchar object_state;               // +0x48
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
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
    virtual int canAttackUnit(void*);
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
    virtual int canConvert(int);
    virtual int processOrder(void*, int);
    virtual int processNotify(void*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

    RGE_Static_Object* objectValue;     // +0x04
    char gap_08[0x12C];                 // sizeof(UnitAIModule) == 0x134

    RGE_Static_Object* lookupObject(int unit_id);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    int bestUnitToConvert(float* param_1);
};

int TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
{
    this->search();

    int best_id = -1;
    float targetValue = 0.0f;
    int i = 0;

    if ((int)DAT_0087d7d8 > 0) {
        do {
            if (this->objectValue->owner->isEnemy(
                    (int)((VISIBLE_UNIT_REC*)DAT_0087d7f0)[i].player) != 0) {
                RGE_Static_Object* found = this->lookupObject(
                    ((VISIBLE_UNIT_REC*)DAT_0087d7f0)[i].object_id);

                if (found != 0 && found->object_state < 3) {
                    if (this->canConvert(found->id) != 0) {
                        float priority =
                            (float)((VISIBLE_UNIT_REC*)DAT_0087d7f0)[i].distance;
                        if (priority < 1.0f)
                            priority = 1.0f;

                        short hp_short = found->master->hp;
                        float hp_float = (float)hp_short;
                        float score = hp_float / priority;

                        if (best_id == -1 || score > targetValue) {
                            best_id = found->id;
                            targetValue = score;
                            if (param_1 != 0)
                                *param_1 = priority;
                        }
                    }
                }
            }

            i++;
        } while (i < (int)DAT_0087d7d8);
    }

    return best_id;
}
