// 00505FD0 TribePriestUnitAIModule::processIdle
// Source: taiuaimd.cpp lines 1692-1756
// Attempt log:
// 1: initial natural source with virtual slots 0x40/0x70/0x9C/0xE0, base processIdle member, debug_rand, and intrinsic sqrt: wrong frame (sub 10), object field offset +0x10 from explicit vtable+virtual double count, early null return inline.
// 2: remove explicit object vtable field and wrap body in positive computerPlayer guard: shortened to 352 without local output.
// 3: restore 4-byte local output buffer: still 352.
// 4: return to early-return structure with corrected object offsets: exact object offsets but still sub esp,10; early fail inline.
// 5: move chooseSomething output local into narrow scope: fixed sub esp,0C and output address; 33.9% edit diff. Remaining branch layout differs (early fail inline vs shared tail) and later FPU/call scheduling shifted.
// 6: positive computerPlayer/target guards shortened to 352.
// 7: explicit goto shared ret5 with top declarations shortened to 336, wrong family.
// 8: corrected the object slot +0x10C surface (the period method is weaponRange);
//    returned to best attempt-5 source family.
// 9: status local with `if (status != 6) { body } return 6` to try inline ret6 layout.
// 10: restored full same-TU UnitAIModule/RGE_Static_Object virtual surfaces,
//     typed globals, positive guards, and the donor-backed weaponRange gate;
//     335 differing bytes, with calls and frame aligned.
// 11: put the success/failure flow back into the original positive outer guard;
//     153 differing bytes and exact central block islands.
// 12: reversed the commutative distance-square terms; FPU stack schedule moved
//     toward the original, 62 differing bytes.
// 13: mirrored exact idle donors' xDiff-then-yDiff declaration/order; 54 bytes
//     remained, localized to movement lowering and the success tail.
// 14: explicit float casts around the negated movement products plus a direct
//     return 6 after evasiveMoveTo reproduce the complete 360-byte function.

#include <math.h>
#include "../../include/game_globals.h"

#pragma intrinsic(sqrt)

extern int __cdecl debug_rand(const char* file, int line);

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;             // +0x3C
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

    char gap_04[0x08];                    // +0x04 .. +0x0B
    RGE_Player* owner;                    // +0x0C
    char gap_10[0x28];
    float world_x;                        // +0x38
    float world_y;                        // +0x3C
    float world_z;                        // +0x40
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

    RGE_Static_Object* objectValue;       // +0x04
    char gap_08[0x12C];                   // sizeof(UnitAIModule) == 0x134
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    int processIdle(int param_1);
};
#endif

int TribePriestUnitAIModule::processIdle(int param_1)
{
    if (this->objectValue->owner->computerPlayer()) {
        if (UnitAIModule::processIdle(1) == 6) {
            return 6;
        }

    int range = (int)DAT_0087d7d8;
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0x6AC) % (range + 2);
    if (range > 0 && r > range) {
        float local_4;
        int action = this->bestUnitToHeal(1, &local_4);
        if (action != -1) {
            this->healObject(action, 0);
            return 6;
        }
    }

    int targetId = this->closestObject(-1, 2, -1, -1, 0);
    if (targetId == -1) {
        return 5;
    }

    RGE_Static_Object* target = this->objectValue->owner->world->object(targetId);
    if (target == 0) {
        return 5;
    }

    float xDiff = target->world_x - this->objectValue->world_x;
    float yDiff = target->world_y - this->objectValue->world_y;
    float dist = (float)sqrt(xDiff * xDiff + yDiff * yDiff);
    float distanceDiff = this->objectValue->weaponRange() - dist;

    if (distanceDiff <= DAT_005758c4) {
        return 5;
    }

    float nx = (float)(-((xDiff / dist) * distanceDiff)) +
               this->objectValue->world_x;
    float ny = (float)(-((yDiff / dist) * distanceDiff)) +
               this->objectValue->world_y;
    this->evasiveMoveTo(nx, ny, this->objectValue->world_z, 1);
    return 6;
    }

    return 5;
}
