// VA: 004171F0 UnitAIModule::runAwayFromAttackers (357B)
// aiuaimod.cpp:3634-3678
//
// Attempt log:
// - Replaced the placeholder with the binary-supported early guard, attacking-
//   units ManagedArray<int> scan, world-object lookup, accumulated coordinate
//   deltas, float range getter, normalized retreat point, and evasiveMoveTo call.
// - Baseline below follows the exact same-TU typed surfaces and utmarray.h
//   inline growth body; initial body was 2 bytes over size and spilled the
//   range factor after the x87 sum.
// - Initializing xDiff/yDiff before the loop index restored the oracle's
//   immediate zero stores. Binding `range * 4.0f` at the maximumSpeed call kept
//   the scaled getter live through sqrt and reproduced the complete FPU tail.
//   MATCH (357/357 bytes, 5/5 calls, default flags).

#include <math.h>
#include "../../include/game_globals.h"

#pragma intrinsic(sqrt)

void* operator_new(unsigned int size);
void operator_delete(void* block);

class RGE_Game_World;
class RGE_Player;
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
    RGE_Game_World* world; // +0x3C
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
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
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
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
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
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

    int id;                         // +0x04
    void* master_obj;               // +0x08
    RGE_Player* owner;              // +0x0C
    char gap_10[0x28];              // +0x10 to +0x37
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)operator_new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
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
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float x, float y, float z, int flag); // +0x9C
    virtual int runAwayFromAttackers(int param);

    RGE_Static_Object* objectValue; // +0x04
    char gap_08[0x30 - 0x08];
    int currentActionValue;         // +0x30
    char gap_34[0x60 - 0x34];
    ManagedArray<int> attackingUnitsValue; // +0x60
    char gap_70[0x134 - 0x70];
};

int UnitAIModule::runAwayFromAttackers(int param_1) {
    if (param_1 == 0 && this->currentActionValue != -1)
        return 0;

    int i;
    float xDiff;
    float yDiff;

    xDiff = 0.0f;
    yDiff = 0.0f;
    i = 0;

    if (this->attackingUnitsValue.numberValue > 0) {
        do {
            RGE_Static_Object* attacker =
                this->objectValue->owner->world->object(this->attackingUnitsValue[i]);
            if (attacker != 0) {
                xDiff += attacker->world_x - this->objectValue->world_x;
                yDiff += attacker->world_y - this->objectValue->world_y;
            }
            ++i;
        } while (i < this->attackingUnitsValue.numberValue);
    }

    float range = this->objectValue->maximumSpeed() * 4.0f;
    float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

    return this->evasiveMoveTo(
        (float)(-((xDiff / distance) * range)) + this->objectValue->world_x,
        (float)(-((yDiff / distance) * range)) + this->objectValue->world_y,
        this->objectValue->world_z,
        1);
}
