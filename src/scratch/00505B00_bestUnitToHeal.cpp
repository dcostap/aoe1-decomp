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
// 19-28: Scalar-global overlays, parallel pointers, a typed aggregate, category
//     loop forms, direct table expressions, and wider object-pointer scope did
//     not recover the oracle's hidden table-base slot or register colors. The
//     scalar overlay shortened the body; the other forms were codegen duplicates
//     or farther from the oracle. Restored the natural typed table source.
// 29: A reviewed-header byte-offset cursor moved the positional diff to 345,
//     but kept the 0x18 frame and violated the no-byte-cursor source policy;
//     restored the pinned source.
// 30: A cached typed record pointer shortened the body to 390 bytes and moved
//     the frame to 0x14; restored the pinned source.
// 31-39: Re-tested scalar globals, typed and raw offset cursors, declaration
//     order, do/while and for-header forms, and function-scope pointer aliases.
//     They stayed in the same 345-349-byte basin or shortened the body.
// 40: Replayed the prior 344-byte checkpoint. It had a 0x14 frame and only
//     126 instructions, so its smaller diff was not a natural improvement.
// 42-50: Hoisted list/object pointers and tested register hints and an offset
//     address alias. They emitted the clean 347-byte basin or a duplicate.
// 52: Volatile offset storage recovered the 0x1c frame but added six bytes and
//     32 changed spans. Restored the natural typed source.
// 54: Final unchanged validation confirms the pinned 445-byte source and 347
//     differing bytes.
// 55-57: Reviewed scalar DAT globals and casted bucket indexing improved the
//     diagnostic diff to 344 bytes, but shortened the natural body to 429 bytes
//     and lost block shape; restored.
// 58-62: Full tactical member declarations and canonical object vtable names
//     were codegen duplicates after the proven canSee +0x194 slot was restored.
// 63-67: Typed table-slot, count-slot, char-offset, and declaration-order
//     probes stayed in a 345-byte diff basin with the wrong saved-register
//     ownership; restored.
// 68-70: A live list-slot induction pointer recovered the 0x1c frame and more
//     aligned blocks, but added pre-loop global arithmetic and worsened the
//     positional diff to 358 bytes; restored.
// 71-72: A contiguous count/list table overlay shortened the body to 421 bytes
//     and changed global ownership; restored.
// 73: Fresh unchanged validation confirms the pinned natural typed source.
// 74-75: Replaced the outer for/break form with the PDB-supported positive
//     guard, nested do loop, early found-ID return, and final -1 return.
//     This improved the result to 346 differing bytes and 442 bytes, but the
//     offset still stayed in a saved register and the frame stayed 0x18.
// 76-77: Added the binary-proven scalar table bases and byte-offset cursor.
//     Function-scope slot pointers and direct count rereads were codegen
//     duplicates; they did not recover the slot home or saved-register colors.
// 78-80: An index-derived slot pointer recovered the 0x1c frame and 91.85%
//     shape, but worsened the positional diff to 354 bytes. Reference, raw
//     pointer, declaration-order, and reviewed-header variants stayed there.
// 81: Restored the pinned natural typed source and ran unchanged validation.
//     Exactness remains blocked by the slot-pointer and object register basin.
// BLOCKER: the natural typed source now matches the prologue, calls, CFG, size, and
// most inner blocks, but VC5 keeps the table offset in EDI and object in ESI.
// The oracle keeps the table slot in ESI, object in EDI, and one extra frame slot.
// Current best: 445/445 bytes, 347 differing bytes (77.9775%), first mismatch +2.

#include <stdlib.h>

#ifdef TAIUAIMD_COMPLETE_TU
#define DAT_0087d7cc taiuaimd_heal_counts
#define DAT_0087d7e4 taiuaimd_heal_records
#endif

#ifndef TAIUAIMD_COMPLETE_TU
struct RGE_Master_Static_Object {
    char gap_00[0x14];
    short object_group;
    char gap_16[0x10];
    short hp;
};

class RGE_Player {
public:
    virtual void set_game_status();
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
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual unsigned char update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual float teleport(float, float, float);
    virtual void new_sprite(); virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*); virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char); virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*); virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char); virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying(); virtual void destroy_obj(); virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long); virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float); virtual void stop();
    virtual void set_attack(RGE_Static_Object*); virtual void play_command_sound();
    virtual void play_move_sound(); virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving(); virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*); virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table(); virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(); virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed(); virtual float getAngle(); virtual float maximumSpeed();
    virtual float rateOfFire(); virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability(); virtual float weaponRange(); virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int); virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID(); virtual float currentTargetX(); virtual float currentTargetY();
    virtual float currentTargetZ(); virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove(); virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int); virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...); virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int); virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int); virtual int moveTo(int, float, int);
    virtual int moveTo(int, int); virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int); virtual int gather(int, int); virtual int convert(int, int);
    virtual int repair(int, int); virtual int build(int, int); virtual int trade(int, int);
    virtual int explore(int, int, int); virtual int enter(int, int);
    virtual int unload(int, float, float, float); virtual int transport(float, float, float, int);
    virtual int stopAction(); virtual int pause();
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
#endif

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
#ifdef TAIUAIMD_COMPLETE_TU
                                            if (taiuaimd_object_can_see(this->objectValue,
#else
                                            if (this->objectValue->canSeeObject(
#endif
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

#ifdef TAIUAIMD_COMPLETE_TU
#undef DAT_0087d7cc
#undef DAT_0087d7e4
#endif
