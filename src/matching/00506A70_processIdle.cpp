// 00506A70 TribeTransportShipUnitAIModule::processIdle (taiuaimd.cpp:2122-2147)
// int __thiscall processIdle(int param_1)
//
// MATCHED - natural typed thiscall virtual surfaces reproduce both dispatch calls.
// The final explicit float cast preserves the original VC5 fchs/fadd movement lowering.
//
// Attempts:
// 1. __fastcall vtable shims and early returns produced an extra edx setup and wrong tails.
// 2. Typed virtual slots at +40/+9C and +FC removed the ABI drift and fixed the structure.
// 3. Materializing getSpeed()*7 before dx/dy fixed the original FPU evaluation order.
// 4-7. Equivalent movement spellings either emitted fsubr or spilled intermediates.
// 8. A focused variant lab found `(float)(-((delta / distance) * speed)) + position` exact.
// Main-agent audit restored canonical polymorphic ownership and destructor
// slots throughout the world/object/AI surface; emitted code remains exact.

#include <math.h>

#ifndef TAIUAIMD_COMPLETE_TU
class NotifyEvent;
class RGE_Master_Static_Object;
class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char _gap_04[0x38];
    RGE_Game_World* world;
    int computerPlayer();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    class RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
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
    virtual float rateOfFire();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char _gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class TribeTransportShipUnitAIModule {
public:
    virtual ~TribeTransportShipUnitAIModule();
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
    virtual int closestObject(int, int, int, int, int*);
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
    virtual int evasiveMoveTo(float, float, float, int);

    RGE_Static_Object* sub;
    virtual int moveTo(float, float, int, int);

    int processIdle(int param_1);
};
#endif

int TribeTransportShipUnitAIModule::processIdle(int param_1)
{
    if (this->sub->owner->computerPlayer()) {
        int targetId = closestObject(-1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->sub->owner->world->object(targetId);

            if (target != 0) {
                float speed = this->sub->maximumSpeed() * 7.0f;

                float dx = target->world_x - this->sub->world_x;
                float dy = target->world_y - this->sub->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);

                float move_x = (float)(-((dx / dist) * speed)) + this->sub->world_x;
                float move_y = (float)(-((dy / dist) * speed)) + this->sub->world_y;

                moveTo(move_x, move_y, this->sub->world_z, 1);

                return 6;
            }
        }
    }

    return 5;
}
