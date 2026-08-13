// 00505B00 TribePriestUnitAIModule::bestUnitToHeal
// Attempt log:
// 1: Natural nested loops over four ally buckets: compiles 432 vs 445, wrong prologue/self in EBX and wrong canSee vtable surface.
// 2: Switch canSee to +0x194 virtual and bucket offset loop: exact size but 91% diff; self in ESI, 0x28 frame, bad global/list shape.
// 3: Use pointer-to-current bucket globals: frame 0x20 but self still ESI and broad diff.
// 4: Volatile self alias worsened prologue by homing this at [esp]; rolled back.
// 5: /Od and /O2-without-/Oy flag probes did not improve; removed custom flags.
// 6: Rewriting priority gates as <5/<3 worsened to 91.01% diff.
// 7: Naming fpriority before need calculation did not move first mismatch or improve diff.
// 8: Breaking outer loop then returning at function tail worsened to 89.89% diff.
// 9: Reconstructed the single final return with an inner do/while and outer break,
//    removing cached master/priority/offset locals; 445-byte output, 375 differing bytes.
// 10: Restored donor TU context/full UnitAIModule ABI and typed object/owner/record
//     ownership; output was codegen-duplicate (375 differing bytes).
// 11: Caching the current record-list pointer reached an exact 0x1c frame but
//     shortened the body and changed reload behavior; rolled back.
// 12: Reloading the record-list value per iteration also shortened the body;
//     rolled back because the oracle rereads the bucket slot.
// 13: Typed HealUnitRecord indexing and char* bucket offset were source-cleanup
//     probes; both emitted the same 375-byte-diff basin as probe 9.
// 14: Typed five-entry count/list tables gave the same 445-byte basin with a
//     small edit-distance gain; retained as canonical ownership.
// 15: Removed the unit_id temporary and reread the typed record ID at lookup and
//     canSee calls, matching the oracle reload order. Diff fell to 347 bytes and
//     shape rose to 85.19%; this is the current clean reconstruction.
// 16: Hoisting the record-slot pointer emitted identical code; rolled back.
// 17: Typed views over scalar global declarations shortened the body; rolled back.
// 18: Parallel count/list slot pointers kept the same register topology; rolled back.
// BLOCKER: the natural typed source now matches the prologue, calls, CFG, size, and
// most inner blocks, but VC5 keeps the table offset in EDI and object in ESI.
// The oracle keeps the table slot in ESI, object in EDI, and one extra frame slot.
// Current best: 445/445 bytes, 347 differing bytes (77.9775%), first mismatch +2.

#include <stdlib.h>

struct RGE_Master_Static_Object {
    char gap_00[0x14];
    short object_group;
    char gap_16[0x10];
    short hp;
};

class RGE_Player {
public:
    virtual void p00();
    char gap_04[0x4A - 0x04];
    short id;
};

struct HealUnitRecord {
    int object_id;
    unsigned char priority;
    unsigned char gap_05[3];
};

extern int DAT_0087d7cc[5];
extern HealUnitRecord* DAT_0087d7e4[5];

struct RGE_Static_Object {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual int canSeeObject(int id, float radius, int, int, int, int);
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x30 - 0x10];
    float hp;
    char gap_34[0x48 - 0x34];
    unsigned char object_state;
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

    RGE_Static_Object* objectValue;
    char gap_08[0x12C];
    RGE_Static_Object* lookupObject(int unit_id);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
protected:
    virtual int bestUnitToHeal(int param_1, float* param_2);
};

int TribePriestUnitAIModule::bestUnitToHeal(int param_1, float* param_2)
{
    this->search();

    int allyToHealID = -1;
    float allyNeed = 0.0f;
    int maxLimit = 2;
    int a;
    int i;
    if (this->objectValue->owner->id == 0) {
        maxLimit = 4;
    }

    a = 1;
    for (; a <= maxLimit; ++a) {
        i = 0;
        if (DAT_0087d7cc[a - 1] > 0) {
            HealUnitRecord** listPtr = &DAT_0087d7e4[a - 1];
            do {
                if ((*listPtr)[i].object_id != this->objectValue->id) {
                    RGE_Static_Object* unit =
                        this->lookupObject((*listPtr)[i].object_id);
                    if (unit != 0) {
                        if (unit->master_obj->object_group != 3) {
                            if ((float)(int)unit->master_obj->hp > unit->hp) {
                                if (unit->object_state < 3) {
                                    if (param_1 != 0 ||
                                        (*listPtr)[i].priority <= 4) {
                                        if (this->objectValue->owner->id != 0 ||
                                            (*listPtr)[i].priority <= 2) {
                                            if (this->objectValue->canSeeObject(
                                                    (*listPtr)[i].object_id,
                                                    1.0f, 0, 0, -1, -1)) {
                                                float need = (float)(int)unit->master_obj->hp -
                                                    unit->hp / (float)(int)(*listPtr)[i].priority;
                                                if (allyToHealID == -1 || need < allyNeed) {
                                                    allyNeed = need;
                                                    allyToHealID = unit->id;
                                                    if (param_2 != 0) {
                                                        *param_2 = (float)(int)(*listPtr)[i].priority;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                ++i;
            } while (i < DAT_0087d7cc[a - 1]);
        }
        if (allyToHealID != -1) {
            break;
        }
    }

    return allyToHealID;
}
