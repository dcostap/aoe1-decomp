// VA 005071F0 TribeSoldierUnitAIModule::processNotify
// taiuaimd.cpp:2380-2536
// Attempt log:
// 1: Natural reconstruction from packet/decompiler using nearby taiuaimd processNotify/list-growth patterns.
// 2: Modeled NotifyEvent type split for 0x20F evasive-move and 0x200 chase/retreat paths, with base processNotify fallback.
// 3: Added computerPlayer/world->object/type gates, group 0x23/0x24 checks, command/target checks, and issueOrder/moveTo virtual-call surfaces.
// 4: Added debug_rand jitter and FPU-ish random coordinate adjustment logic for both X/Y evasive targets.
// 5: Added rangeLeft/distance_to_object check, target vector accumulation, dynamic id-list growth/copy/delete pattern, and normalized retreat move.
// 6: Default /O2 /Oy compiles but is size-short: configured 1098 exceeds rebuilt .text 992. Broad source is behaviorally approximate but not enough codegen/detail.
// 7: Probed /Od: exact size 1098 but broad wrong basin from offset 0 (86.7942% positional); removed flag.
// 8: Probed /O2 /Oy /Ob0: still size-short 992; removed flag.
// 9: Probed /O2 /Oy /Og-: exact size 1098 but broad wrong basin from offset 0 (86.0656% positional); removed flag.
// 10: Probed /O2 /Oy /Op: closer size 1040 but still size-short; removed flag.
// 11: Probed /O1 /Oy: size-short 861; removed flag.
// 12: Rebuilt the canonical taiuaimd class surfaces: switched to the original 0x200/0x20F dispatch order, typed owner/master/world access, UnitAIModule::order/intelligentEvasiveMoveTo, weaponRange, and the inline ManagedArray indexer.
// 13: Common-fallback goto/positive-guard rewrites moved the fallback block early and degraded the otherwise aligned call/body basin; reverted.
// 14: Scoping jitter locals, splitting modulo into a temporary, adding stdio context, and reusing the jitter local for the range delta did not improve emitted code; reverted.
// 15: Explicit goto-to-base paths in the switch were codegen-identical; the compiler still relocated the fallback before the 0x200 body.
// 16: A positive compound 0x20F guard inside the switch was codegen-identical; Ghidra's guard shape did not change the VC5 basin.
// 17: Reusing param_1's dead stack home for the second jitter float worsened the diff and did not reduce the 0x0C frame; reverted.
// 18: Reusing evasiveMoveDistance for the 0x200 range delta kept size/diff but worsened shape and exact-block coverage; reverted.
// 19: Moving both guards into the decompiler's if/else-if form matched the earlier broad 1055-byte basin; reverted.
// 20: Modeling one explicit 0x200 case with a default 0x20F guard changed dispatch to cmp and worsened the diff to 944; reverted.
// 21: Replaced switch breaks with an if/else dispatch and one late base label; 1055-byte diff and 6/+6 call-site gaps; reverted.
// 22: Swapped the switch arm order; emitted code was identical to the clean 855-byte candidate; reverted.
// 23: Replaced rejected switch breaks with direct base returns; added ten processNotify calls and worsened the diff to 1225; reverted.
// 24: Explicit 0x200-to-0x20F labels kept the fallback late but changed the dispatch/body basin to 1062 bytes and 6/+6 call gaps; reverted.
// 40 meaningful probes: direct +0x60 pointer, +0x64 count, and +0x6C capacity fields with
// duplicated natural growth scans recover the shipped list-loop basin. The best
// result is 1078 bytes, 0x8 frame, 93.75% shape, and 639 strict-diff bytes.
// Parenthesized random-coordinate arithmetic and the inverted >10 branch recover
// both x87 jitter blocks. The remaining drift is the late shared base-fallback
// block: the rebuilt guards use short branches to an early call site.
// Compiler-neutral goto and local-order reductions were removed from the pinned source.
// GIVEUP: leave this direct-field candidate in scratch for the next worker.
// Accepted-drift review: the call-map gap is the same base processNotify call
// moved from the cold tail to the guard join. All integer and unordered x87
// guards reach the same fallback with the same arguments and ESP. The main
// path, 18 other calls, list growth, coordinate arithmetic, order issue, move,
// and return values match; the final 3/2 return blocks only invert branch form.

#include <math.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

extern "C" int debug_rand(char*, int);
#define taskedThisUpdate (*(int*)0x592A48)
extern const float DAT_005758bc;
extern const float DAT_005758c0;
extern const float DAT_005758dc;
extern const float DAT_005758e0;
extern const float DAT_005758e4;

struct NotifyEvent {
    int caller;
    char gap_04[4];
    int mType;
    char gap_0C[4];
    int p2;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                                  // +0x10
    char gap_12[2];
    short object_group;                        // +0x14
};

class RGE_Game_World;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;                     // +0x3C
    char gap_40[0x0A];
    short id;                                  // +0x4A

    int computerPlayer();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();

    long id;                                    // +0x04
    RGE_Master_Static_Object* master_obj;       // +0x08
    RGE_Player* owner;                          // +0x0C
    char gap_10[0x20];                          // +0x10 .. +0x2F
    float hitPoints;                            // +0x30
    char gap_34[4];                             // +0x34
    float world_x;                              // +0x38
    float world_y;                              // +0x3C
    float world_z;                              // +0x40
    float attribute_amount_held;                // +0x44
    unsigned char object_state;                 // +0x48
    char gap_49[7];                             // +0x49 .. +0x4F
    void* player_object_node;                   // +0x50
    char gap_54[0x20];                          // +0x54 .. +0x73

    float distance_to_object(RGE_Static_Object* object);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
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
    virtual int moveTo(int, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float, int);
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
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

    RGE_Static_Object* objectValue;             // +0x04
    char gap_08[0x20];                          // +0x08 .. +0x27
    int currentOrderValue;                      // +0x28
    int currentOrderPriorityValue;              // +0x2C
    int currentActionValue;                     // +0x30
    int currentTargetValue;                     // +0x34
    int currentTargetTypeValue;                 // +0x38
    float currentTargetXValue;                  // +0x3C
    float currentTargetYValue;                  // +0x40
    float currentTargetZValue;                  // +0x44
    float desiredTargetDistanceValue;           // +0x48
    int defendTargetValue;                      // +0x4C
    char gap_50[0x10];                          // +0x50 .. +0x5F
    // BINARY NOTE: the executable treats these as direct fields, not an aggregate.
    int* attackingUnitsValue;                    // +0x60
    int attackingUnitsCount;                     // +0x64
    char gap_68[4];                              // +0x68
    int attackingUnitsCapacity;                 // +0x6C
    char gap_70[0xC4];                          // +0x70 .. +0x133
};

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, ulong flags);
};

int TribeSoldierUnitAIModule::processNotify(NotifyEvent* param_1, ulong param_2)
{
    NotifyEvent* event = param_1;
    float evasiveMoveDistance;
    float fStack_8;
    RGE_Static_Object* target;
    float distanceLeft;
    float xDiff;
    float yDiff;
    float distance;
    int i;

    switch (event->mType) {
    case 0x20F: {
        if (this->objectValue->owner->computerPlayer() == 0)
            break;

        RGE_Static_Object* attacker =
            this->objectValue->owner->world->object(event->caller);
        if (attacker == 0)
            break;
        short group = attacker->master_obj->id;
        if (group != 0x23 && group != 0x24)
            break;
        if (this->currentActionValue == -1)
            break;

        if (this->currentOrderValue != -1) {
            this->order(
                this->objectValue->id, this->currentOrderValue,
                this->currentTargetValue, -1,
                this->currentTargetXValue, this->currentTargetYValue,
                this->currentTargetZValue, this->desiredTargetDistanceValue,
                0, 0, this->currentOrderPriorityValue);
        }

        evasiveMoveDistance =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x97c) % 8) +
            (this->objectValue->world_x - DAT_005758dc);
        if (evasiveMoveDistance == this->objectValue->world_x) {
            if (evasiveMoveDistance > DAT_005758e0)
                evasiveMoveDistance -= DAT_005758c0;
            else
                evasiveMoveDistance -= DAT_005758e4;
        }

        fStack_8 =
            (float)(debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x983) % 8) +
            (this->objectValue->world_y - DAT_005758dc);
        if (fStack_8 == this->objectValue->world_y) {
            if (fStack_8 > DAT_005758e0)
                fStack_8 -= DAT_005758c0;
            else
                fStack_8 -= DAT_005758e4;
        }

        if (this->intelligentEvasiveMoveTo(
                evasiveMoveDistance, fStack_8,
                this->objectValue->world_z, 1, 1) != 1)
            break;
        taskedThisUpdate = 1;
        return 3;
    }

    case 0x200: {
        if (this->objectValue->owner->computerPlayer() == 0)
            break;
        if (this->objectValue->weaponRange() < DAT_005758bc)
            break;
        if (this->objectValue->master_obj->object_group == 0x1A)
            break;
        if (this->currentActionValue != 600)
            goto return_two;

        target =
            this->objectValue->owner->world->object(this->currentTargetValue);
        if (target == 0)
            break;

        distanceLeft = this->objectValue->weaponRange() -
            this->objectValue->distance_to_object(target);
        if (distanceLeft < DAT_005758bc)
            break;

        xDiff = target->world_x - this->objectValue->world_x;
        yDiff = target->world_y - this->objectValue->world_y;

        this->order(
            this->objectValue->id, 700, this->currentTargetValue, -1,
            this->currentTargetXValue, this->currentTargetYValue,
            this->currentTargetZValue, this->desiredTargetDistanceValue,
            0, 1, this->currentOrderPriorityValue);

        if (this->attackingUnitsCount > 0) {
            i = 0;
            while (i < this->attackingUnitsCount) {
                if (i > this->attackingUnitsCapacity - 1) {
                    int newCount = i + 1;
                    int* newValues = new int[newCount];
                    if (newValues != 0) {
                        int j = 0;
                        if (this->attackingUnitsCapacity > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    newValues[j - 1] = this->attackingUnitsValue[j - 1];
                                } else {
                                    break;
                                }
                            } while (j < this->attackingUnitsCapacity);
                        }
                        delete[] this->attackingUnitsValue;
                        this->attackingUnitsValue = newValues;
                        this->attackingUnitsCapacity = newCount;
                    }
                }
                if (this->attackingUnitsValue[i] != this->currentTargetValue) {
                    if (i > this->attackingUnitsCapacity - 1) {
                        int newCount = i + 1;
                        int* newValues = new int[newCount];
                        if (newValues != 0) {
                            int j = 0;
                            if (this->attackingUnitsCapacity > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        newValues[j - 1] = this->attackingUnitsValue[j - 1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->attackingUnitsCapacity);
                            }
                            delete[] this->attackingUnitsValue;
                            this->attackingUnitsValue = newValues;
                            this->attackingUnitsCapacity = newCount;
                        }
                    }
                    RGE_Static_Object* object =
                        this->objectValue->owner->world->object(
                            this->attackingUnitsValue[i]);
                    if (object != 0) {
                        xDiff += object->world_x - this->objectValue->world_x;
                        yDiff += object->world_y - this->objectValue->world_y;
                    }
                }
                ++i;
            }
        }

        distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
        if (this->intelligentEvasiveMoveTo(
                            (float)(-((xDiff / distance) * distanceLeft)) +
                    this->objectValue->world_x,
                            (float)(-((yDiff / distance) * distanceLeft)) +
                this->objectValue->world_y,
                this->objectValue->world_z, 0, 1) != 1)
            goto return_two;
        return 3;
return_two:
        return 2;
    }

    default:
        break;
    }

    return UnitAIModule::processNotify(event, param_2);
}
