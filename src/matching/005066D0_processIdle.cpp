// 005066D0 TribeTradeShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:1981-2027, 250 bytes
//
// Canonical reconstruction: an AI trade ship looks for its destination,
// obtains the ship speed, and moves back toward the ship by seven speed
// units.  The object/player/world fields and the virtual calls are modeled at
// their proven offsets; the math is kept in the natural source form suggested
// by the original x87 stack topology.
//
// Attempt log:
// - Typed virtual surfaces and nested success guards matched the frame, calls,
//   and all non-math control-flow structure.
// - Binding the seven-times-speed scale to the getter result reproduced the
//   original early FMUL and exact-size FPU schedule.
// - The explicit float cast around each negated movement product is deliberate:
//   without it VC5 folds the operation into FPU FSUBR; with it the original
//   FCHS/FADD pair and branch displacements are reproduced. MATCH.
// Main-agent audit restored canonical destructor slots on the world/player,
// object, and AI surfaces; emitted code remains exact.

#include <math.h>

#ifndef TAIUAIMD_COMPLETE_TU
class NotifyEvent;
class RGE_Master_Static_Object;
class RGE_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;                 // +0x3C

    int computerPlayer();
};

class RGE_Static_Object {
public:
    char gap_04[0x08];                     // +0x04 .. +0x0B
    RGE_Player* owner;                     // +0x0C
    char gap_10[0x28];                     // +0x10 .. +0x37
    float world_x;                         // +0x38
    float world_y;                         // +0x3C
    int field_40;                          // +0x40

    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual unsigned char update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual float teleport(float, float, float);
    virtual void new_sprite(); virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*); virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char); virtual void modify_percent(float, unsigned char);
    virtual void transform(); virtual void copy_obj(); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die();
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
};

class TribeTradeShipUnitAIModule {
public:
    RGE_Static_Object* obj;                // +0x04 (vptr at +0x00)

    virtual ~TribeTradeShipUnitAIModule();
    virtual void save(int); virtual void load(int); virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(NotifyEvent*);
    virtual void search(); virtual int importantWhenDead(int);
    virtual int retryableOrder(int); virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*); virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*); // +0x40
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*); virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int); virtual int stopObject(int);
    virtual int attackObject(int, int); virtual int attackRoundupObject(int);
    virtual int huntObject(int, int); virtual int gatherObject(int, int);
    virtual int convertObject(int, int); virtual int healObject(int, int);
    virtual int repairObject(int, int); virtual int buildObject(int, int);
    virtual int tradeWithObject(int, int); virtual int explore(int, int, int);
    virtual int enterObject(int, int); virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int); virtual int moveTo(int, int);
    virtual int moveTo(float, float, int, int);     // +0x9C

    int processIdle(int param_1);
};
#endif

int TribeTradeShipUnitAIModule::processIdle(int param_1)
{
    if (this->obj->owner->computerPlayer()) {
        int targetId = this->closestObject(-1, -1, -1, -1, 0);
        if (targetId != -1) {
            RGE_Static_Object* target = this->obj->owner->world->object(targetId);
            if (target != 0) {
                float speed = this->obj->maximumSpeed() * 7.0f;
                float xDiff = target->world_x - this->obj->world_x;
                float yDiff = target->world_y - this->obj->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                this->moveTo(
                    (float)(-(xDiff / distance * speed)) + this->obj->world_x,
                    (float)(-(yDiff / distance * speed)) + this->obj->world_y,
#ifdef TAIUAIMD_COMPLETE_TU
                    this->obj->world_z, 1);
#else
                    this->obj->field_40, 1);
#endif
                return 6;
            }
        }
    }

    return 5;
}
