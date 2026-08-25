#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00501430 TribeTacticalAIModule::dealWithGAIAAttacker (424 B)
// PDB source: taitacmd.cpp:11854-11938
// __thiscall
//
// Attempt log:
// - Replaced the raw-offset scaffold with the period typed ownership model:
//   param_1 is the attacker, param_2 is the GAIA target, civilianExplorers is
//   the +0x104 ManagedArray, md is the +0xF0 decision module, and sn[0x64]
//   is the +0x324 response limit. The natural source uses civilian(), the
//   weaponRange()/canPath() pair, and taskAttacker(). Baseline: 435 bytes;
//   the do/while scan added a redundant first capacity test.
// - Hoisting target->id was codegen-neutral with the first scan shape.
// - Replaced the scan with the exact same-TU bounded for-loop idiom: 424
//   bytes, with only sn displaced by the incomplete class layout.
// - Restored the ten task-list array region before sn at +0x194; this fixed
//   sn[0x64] at +0x324 and reached MATCH. Direct target->id in the for loop
//   was tested and worsened codegen; the hoisted local is retained.

#ifndef TAITACMD_SHARED_CONTEXT
struct XYPoint {
    int x;
    int y;
};

struct XYZPoint {
    int x;
    int y;
    int z;
};

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
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
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArrayInt*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual unsigned char* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(unsigned char*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, void*);
    virtual int setup(void*, RGE_Player*, float, float, float);
    virtual void* create_object_list();
    virtual void* create_sprite_list();

    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Static_Object* object(int id);
};

struct Waypoint {
    int x;
    int y;
    int z;
    int unk;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    char gap_114[0x194 - 0x114];
    int sn[0xE2];

    int civilian(XYPoint&, int, int, int, int, int);
    int taskAttacker(int, float, float, int, int, Waypoint*, int, int, int);

    int dealWithGAIAAttacker(RGE_Static_Object* attacker,
                             RGE_Static_Object* target);
};

#endif
int TribeTacticalAIModule::dealWithGAIAAttacker(
    RGE_Static_Object* attacker, RGE_Static_Object* target)
{
    int count;
    int unitID;
    RGE_Static_Object* unitObject;
    XYPoint vPosition;
    XYZPoint point;

    if (attacker == 0 || target == 0)
        return 0;

    int targetID = target->id;
    int i;
    for (i = 0; i < this->civilianExplorers.numberValue; i++) {
        if (i >= this->civilianExplorers.maximumSizeValue)
            break;
        if (this->civilianExplorers.value[i] == targetID)
            return 0;
    }

    count = 0;
    vPosition.x = (int)target->world_x;
    vPosition.y = (int)target->world_y;
    unitID = this->civilian(vPosition, 1, 700, 0x2C9, 0x2C9, 1);
    while (unitID != -1 && count < this->sn[0x64] &&
           (unitObject = this->md->object(unitID)) != 0) {
        point.x = (int)attacker->world_x;
        point.y = (int)attacker->world_y;
        point.z = (int)attacker->world_z;
        if (unitObject->canPath(
                point, unitObject->weaponRange(), attacker->id,
                0, 1, -1, -1) == 0)
            break;

        this->taskAttacker(unitID, attacker->world_x, attacker->world_y,
                           attacker->id, (int)attacker->owner->id,
                           0, 0, -1, 0);
        count++;
        unitID = this->civilian(vPosition, 1, 700, 0x2C9, 0x2C9, 1);
    }

    return count > 0;
}
#else
int TribeTacticalAIModule::dealWithGAIAAttacker(
    RGE_Static_Object* attacker, RGE_Static_Object* target) {
    return 0;
}
#endif
