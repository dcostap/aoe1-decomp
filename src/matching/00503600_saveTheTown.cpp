#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00503600 TribeTacticalAIModule::saveTheTown
// PDB source: taitacmd.cpp:13342-13444
// __thiscall
// Attempt log:
// - Replaced the parked raw-pointer scaffold with the typed same-TU ownership
//   model: md, aiPlayer, soldiers, playersToAttack, target objects, and groups.
// - The baseline follows the binary call bands: group rescue, soldier scan,
//   then civilian reinforcement. It keeps the two inline ManagedArray growth
//   sites because the executable contains all three growth blocks.
// - Shared the binary LAB_00503954 soldier attack path with a count-only label;
//   this restored all 52 ordered calls, the 0x24 frame, and a +11-byte size gap.
// - Restored the five missing ManagedArray records before sn; this aligned
//   sn[0x14] at +0x1E4 and playersToAttack at +0xD28/+0xD34.
// - Modeled vslot 0x10C as the same-TU weaponRange() call and vslot 0x198
//   as the full canPath(XYZPoint, float, int, float*, int, int, int) ABI.
//   The natural trailing id, 0, 1, -1, -1 arguments preserve the original
//   stack homes and remove the 14-byte command/canPath drift.
// - Reversed entryCount/count declarations to match the original loop stores.
// - A natural conjunction (`count < soldiers.numberValue && entryCount < 6`)
//   restores the binary split loop guard and reduces the gap to 14 bytes.
// - The proven 0x10 base gap places aiPlayer at +0x1256C. Reversed the owner
//   comparison operands and shared the binary entryCount label at +0x3A76.
// - Shared point declaration, aggregate initialization, object-local reuse,
//   and named command-result probes were duplicate or worse; they were rolled back.
// - Final validation: MATCH, 1450/1450 bytes, 52/52 calls, 0x24 frame.

typedef unsigned long ulong;

extern "C" ulong debug_timeGetTime(char* file, int line);
extern int __ftol();
extern void* operator_new(unsigned int size);
extern void operator_delete(void* block);

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

struct Waypoint {
    float x;
    float y;
    float z;
    int facetToNextWaypoint;
};

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int newSize = index + 1;
            int* newValue = (int*)operator_new(newSize * 4);
            if (newValue != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue && i < newSize; i++)
                    newValue[i] = this->value[i];
                operator_delete(this->value);
                this->value = newValue;
                this->maximumSizeValue = newSize;
            }
        }
        return this->value[index];
    }
};

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Player;
class TribeTacticalAIModule;
class TribeMainDecisionAIModule;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class UnitAIModule {
public:
    int currentAction();
    int currentTarget();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game(); virtual void draw();
    virtual void shadow_draw(); virtual void normal_draw(); virtual void draw_front_frame();
    virtual void draw_back_frame(); virtual void draw_frame(); virtual void update();
    virtual void check_damage_sprites(); virtual void rehook(); virtual void save(int);
    virtual float teleport(float, float, float); virtual void new_sprite(); virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite(); virtual void change_ownership(); virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char); virtual void modify_percent(float, unsigned char);
    virtual void transform(); virtual void copy_obj(); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die(); virtual void damage(); virtual float calculateDamage();
    virtual void rotate(long); virtual unsigned char can_attack(); virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char); virtual int heal(int, int);
    virtual unsigned char heal(float); virtual int canRepair(); virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(); virtual void move_to(); virtual void work(); virtual void stop();
    virtual void set_attack(); virtual void play_command_sound(); virtual void play_move_sound();
    virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj(); virtual void* get_command_master();
    virtual void set_being_worked_on(); virtual void release_being_worked_on(); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(); virtual void exit_obj();
    virtual int explore_terrain(); virtual void unexplore_terrain(); virtual void* get_los_table();
    virtual int inAttackRange(); virtual unsigned char underAttack(); virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(); virtual float getSpeed(); virtual float getAngle();
    virtual float maximumSpeed(); virtual float rateOfFire(); virtual float damageCapability();
    virtual float damageCapability(int); virtual float weaponRange(); virtual float minimumWeaponRange();
    virtual int currentTargetID(); virtual float currentTargetX(); virtual float currentTargetY();
    virtual float currentTargetZ(); virtual void setWaitingToMove(unsigned char); virtual unsigned char waitingToMove();
    virtual unsigned char actionState(); virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int); virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...); virtual void notify(int, int, int, long, long, long);
    virtual int currentPath(int, float, int, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* object);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
    char gap_F4[0x10];

    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    RGE_Player* aiPlayer;
};

class TacticalAIGroup {
public:
    virtual ~TacticalAIGroup();
    char gap_04[0x160];
    TacticalAIGroup* next;
    TacticalAIGroup* previous;
    int commanderValue;

    int commander();
    void setTarget(int id);
    void setTargetType(int type);
    void setTargetLocation(float x, float y, float z);
    void setAction(int action);
    void task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int);
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;
    ManagedArrayInt civilians;
    ManagedArrayInt civilianExplorers;
    ManagedArrayInt soldiers;
    ManagedArrayInt ungroupedSoldiers;
    ManagedArrayInt boats;
    ManagedArrayInt warBoats;
    ManagedArrayInt fishingBoats;
    ManagedArrayInt tradeBoats;
    ManagedArrayInt transportBoats;
    ManagedArrayInt artifacts;
    int sn[0xE2];
    char gap_51C[0xD28 - 0x51C];
    ManagedArrayInt playersToAttack;

    TacticalAIGroup* readyAndIdleGroup(int type, int maxDistance,
                                        XYPoint& point);
    int civilian(XYPoint&, int, int, int, int, int);
    int taskAttacker(int, float, float, int, int, Waypoint*, int, int, int);

    void saveTheTown(int objectID);
};
#endif

void TribeTacticalAIModule::saveTheTown(int objectID)
{
    ulong entryTime = debug_timeGetTime((char*)0x5880C0, 0x3420);
    RGE_Static_Object* targetObject;
    XYPoint objectPosition;
    int entryCount;
    int count;
    XYZPoint point;
    targetObject = this->md->object(objectID);

    if (targetObject != 0) {
        objectPosition.x = (int)targetObject->world_x;
        objectPosition.y = (int)targetObject->world_y;

        TacticalAIGroup* group = this->readyAndIdleGroup(
            100, this->sn[0x14], objectPosition);
        if (group == 0)
            group = this->readyAndIdleGroup(
                0x67, this->sn[0x14], objectPosition);

        if (group != 0) {
            int commanderID = group->commander();
            RGE_Static_Object* commanderObject =
                this->md->player->world->object(commanderID);
            if (commanderObject != 0) {
                point.x = (int)targetObject->world_x;
                point.y = (int)targetObject->world_y;
                point.z = (int)targetObject->world_z;
                if (commanderObject->canPath(
                        point, commanderObject->weaponRange(), objectID, 0, 1,
                        -1, -1) == 1) {
                    group->setTarget(objectID);
                    group->setTargetType(
                        (int)targetObject->master_obj->id);
                    group->setTargetLocation(
                        targetObject->world_x, targetObject->world_y,
                        targetObject->world_z);
                    group->setAction(2);
                    group->task(this, this->md, 2, 1, 0);
                    return;
                }
            }
        }

        entryCount = 0;
        count = 0;
        if (this->soldiers.numberValue > 0) {
            while (count < this->soldiers.numberValue && entryCount < 6) {
                if (count > 1 &&
                    debug_timeGetTime((char*)0x5880C0, 0x3447) -
                            entryTime > 10)
                    return;

                RGE_Static_Object* object = this->md->aiPlayer->world->object(
                    this->soldiers[count]);
                if (object != 0 && object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == 600) {
                        if (object->unitAI()->currentTarget() == -1)
                            goto trySoldier;
                        if (object->unitAI()->currentTarget() ==
                            targetObject->id)
                            goto countEntry;

                        RGE_Static_Object* currentTarget =
                            this->md->player->world->object(
                                object->unitAI()->currentTarget());
                        if (currentTarget != 0 &&
                            currentTarget->owner->id ==
                                this->playersToAttack[0])
                            goto countSoldier;
                    } else {
                        goto trySoldier;
                    }

trySoldier:
                    {
                        if (object->distance_to_object(targetObject) <
                            25.0f) {
                        point.x = (int)targetObject->world_x;
                        point.y = (int)targetObject->world_y;
                        point.z = (int)targetObject->world_z;
                        if (object->canPath(
                                point, object->weaponRange(), targetObject->id,
                                0, 1, -1, -1) != 0) {
                            if (this->taskAttacker(
                                    this->soldiers[count],
                                    targetObject->world_x,
                                    targetObject->world_y, targetObject->id,
                                    (int)targetObject->owner->id, 0, 0, -1,
                                    0) == 1) {
countEntry:
                                entryCount++;
                            }
                        }
                    }
                    }
                }

countSoldier:
                count++;
            }
        }

        int unitID = this->civilian(
            objectPosition, 1, 700, -1000, -1000, 1);
        while (unitID != -1 && entryCount < 6) {
            RGE_Static_Object* object = this->md->object(unitID);
            if (object == 0)
                return;

            point.x = (int)targetObject->world_x;
            point.y = (int)targetObject->world_y;
            point.z = (int)targetObject->world_z;
            if (object->canPath(
                    point, object->weaponRange(), objectID, 0, 1, -1, -1) == 0)
                return;

            this->taskAttacker(unitID, targetObject->world_x,
                               targetObject->world_y, objectID,
                               (int)targetObject->owner->id, 0, 0, -1, 0);
            entryCount++;
            unitID = this->civilian(
                objectPosition, 1, 700, 0x2C9, 0x2C9, 1);
        }
    }
}
#else
void TribeTacticalAIModule::saveTheTown(int) {}
#endif
