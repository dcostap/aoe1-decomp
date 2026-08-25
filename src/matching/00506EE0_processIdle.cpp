// VA: 00506EE0 TribeFishingShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:2281-2306, 250 bytes
// __thiscall: ecx=this, one stack parameter, ret 4
//
// Attempt log:
// The parked predecessor used raw function-pointer calls and got cdecl/fastcall
// stack plumbing instead of the observed virtual thiscall calls.  This candidate
// restores the natural UnitAIModule and RGE_Static_Object virtual surfaces, named
// coordinate locals, and the direct period-style movement expression.
// Baseline: 250 bytes, 53 differing bytes; all five calls, frame, and prefix
// structure aligned.
// Named x/y offset temporaries were codegen-neutral; explicit assignments added
// stack homes and eight bytes, so they were rolled back.
// Separate speed/factor locals moved the x87 schedule and widened the function;
// the scaled return local is retained.
// Binary-required arithmetic spelling: `0.0f - offset` preserves the original
// fchs/fadd tail, while unary minus or direct subtraction lowers to fsubr.  The
// simple zero-minus form is retained because it is the only exact natural form
// found and matches the observed arithmetic topology.
// Main-agent audit restored canonical destructor slots across the player,
// object, world, and AI virtual surfaces; emitted code remains exact.

#include <math.h>

extern float DAT_005758d8; // 7.0f

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
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

    char gap_04[0x08];
    RGE_Player* owner; // +0x0C
    char gap_10[0x28];
    float world_x;      // +0x38
    float world_y;      // +0x3C
    int facing;         // +0x40
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual int notifyCommander(int, int, int, long, long, long);
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
    virtual int processNotify(void*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

    RGE_Static_Object* objectValue; // +0x04
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    int processIdle(int param_1);
    virtual int moveTo(float, float, int, int);
};
#endif

int TribeFishingShipUnitAIModule::processIdle(int param_1)
{
    if (objectValue->owner->computerPlayer()) {
        int targetID = closestObject(-1, -1, -1, -1, 0);

        if (targetID != -1) {
            RGE_Static_Object* target = objectValue->owner->world->object(targetID);

            if (target != 0) {
                float speed = objectValue->maximumSpeed() * DAT_005758d8;
                float xDiff = target->world_x - objectValue->world_x;
                float yDiff = target->world_y - objectValue->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                moveTo((0.0f - ((xDiff / distance) * speed)) + objectValue->world_x,
                       (0.0f - ((yDiff / distance) * speed)) + objectValue->world_y,
#ifdef TAIUAIMD_COMPLETE_TU
                       objectValue->facet, 1);
#else
                       objectValue->facing, 1);
#endif
                return 6;
            }
        }
    }

    return 5;
}
