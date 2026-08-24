// VA: 00419650 UnitAIModule::processMisc (1383 bytes)
// PDB owner/access: protected virtual UnitAIModule::processMisc
// (?processMisc@UnitAIModule@@MAEHXZ), aiuaimod.cpp:5287-5689.
// Body boundary: 00419650-00419BB7 (ret at 00419BB6); next sibling starts at
// 00419BC0. The 00419BB7-00419BBF gap is padding.
// Typed reconstruction of the order-specific miscellaneous update pass.
//
// Exact-finish notes:
// - DECISIVE: use target-first movement, the defend target field, and a direct
//   desired-distance push. These choices restore the original block order.
// - REQUIRED: literal -1.0f preserves the original VC5 fld/fsub sequence.
//   The equivalent named global emits fsubr and is not byte exact.
// - INCIDENTAL: split threshold declaration, inline accessors, extra aliases,
//   and a move-distance local were tested and removed or walked back.
// - INSEPARABLE: the 0x2BD branch shape and defendTargetValue source are kept
//   together; each controls the nearby canPath call and block layout.
// - ABI: the PDB-qualified protected access is required; public access emits
//   the wrong decorated owner even though the function bytes stay unchanged.
// BINARY NOTE: the 0x2BD canPath guard reads [this+0x4C], not [this+0x34].
// BINARY NOTE: the targetless +0x90 call receives desired distance as an int
//   push, not through an x87 store.
// LIKELY INTENT: retain the shipped target and action fallbacks without adding
//   defensive checks that are absent from the executable.
// Reusable lesson candidate: a pooled float literal can select a different VC5
//   x87 operand order than an equivalent absolute global expression.

#include "../../include/game_globals.h"

// BINARY NOTE: shared headers do not provide the called RGE_* vtable surfaces.
// Keep these local ABI surfaces. Their fields and called slots are proven here.
#ifndef AOE1_AIUAIMOD_COMPLETE_TU
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;                                  // +0x10
    char gap_12[2];
    short object_group;                        // +0x14
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;                                  // +0x4A

    int computerPlayer();
};

class UnitAIModule;
class RGE_Static_Object;
struct XYZPoint {
    int x;
    int y;
    int z;
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
    virtual int canPath(struct XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(struct XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(void*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, void*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* create_object_list();
    virtual void* create_sprite_list();

    long id;                                      // +0x04
    RGE_Master_Static_Object* master_obj;         // +0x08
    RGE_Player* owner;                            // +0x0C
    char gap_10[0x20];                            // +0x10
    float hitPoints;                              // +0x30
    char gap_34[4];                               // +0x34
    float world_x;                                // +0x38
    float world_y;                                // +0x3C
    float world_z;                                // +0x40
    float attribute_amount_held;                  // +0x44
    unsigned char object_state;                   // +0x48
    char gap_49[7];                               // +0x49
    void* player_object_node;                     // +0x50
    char gap_54[0x20];                            // +0x54 to +0x73
    UnitAIModule* unitAIValue;                    // +0x74

    UnitAIModule* unitAI();
    float distance_to_object(RGE_Static_Object* object);
    float distance_to_position(float x, float y, float z);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner() const;
    virtual int order(int, int, int, int, float, float, float, float,
                      int, int, int);
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
    virtual int processNotify(void*, unsigned long);
    virtual void processGroupNotify(void*);
    virtual int processIdle(int);

protected:
    virtual int processMisc();
    virtual int processRetryableOrder();
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);

public:

    RGE_Static_Object* objectValue;                // +0x04
    char gap_08[0x20];                            // +0x08 to +0x27
    int currentOrderValue;                        // +0x28
    int currentOrderPriorityValue;                // +0x2C
    int currentActionValue;                       // +0x30
    int currentTargetValue;                       // +0x34
    int currentTargetTypeValue;                   // +0x38
    float currentTargetXValue;                    // +0x3C
    float currentTargetYValue;                    // +0x40
    float currentTargetZValue;                    // +0x44
    float desiredTargetDistanceValue;             // +0x48
    int defendTargetValue;                         // +0x4C
    char gap_50[0xE4];                            // +0x50 to +0x133

    RGE_Static_Object* lookupObject(int id);
    void removeCurrentTarget();
};
#endif

extern int taskedThisUpdate;                     // 00592A48
extern FILE* actionFile;                         // 0062C4CC
extern const char str_fmt_stopObject[];         // 0057F964
extern const char str_aiuaimod_path[];          // 0057F980

int UnitAIModule::processMisc()
{
    int invalidValue = -1;
    int order;

    if (this->currentOrderValue != invalidValue) {
        order = this->currentOrderValue;
    } else {
        if (this->currentActionValue != invalidValue) {
            order = this->currentActionValue;
            order += 100;
        } else {
            order = invalidValue;
        }
    }

    switch (order) {
    case 700: {
        if (taskedThisUpdate != 1 &&
            this->objectValue->owner->computerPlayer() != 0 &&
            this->objectValue->can_attack() != 0) {
            RGE_Static_Object* oldTarget =
                this->lookupObject(this->currentTargetValue);
            if (oldTarget == 0 || oldTarget->master_obj->id != 0x114) {
                int candidateID = this->bestUnitToAttack(0, 0, 0);
                RGE_Static_Object* candidate = this->lookupObject(candidateID);
                if (candidateID != invalidValue && candidate != 0 &&
                    candidateID != this->currentTargetValue) {
                    short group = candidate->master_obj->object_group;
                    if (group == 3 || group == 0x1B) {
                        if (candidate->master_obj->id == 0x114) {
                            this->order(
                                this->objectValue->id, 700, candidateID,
                                candidate->owner->id,
                                candidate->world_x, candidate->world_y,
                                candidate->world_z,
                                this->objectValue->weaponRange(),
                                1, 0, this->currentOrderPriorityValue);
                        }
                    } else if (oldTarget == 0 ||
                               oldTarget->master_obj->object_group == 3 ||
                               oldTarget->master_obj->object_group == 0x1B) {
                        this->order(
                            this->objectValue->id, 700, candidateID,
                            candidate->owner->id,
                            candidate->world_x, candidate->world_y,
                            candidate->world_z,
                            this->objectValue->weaponRange(),
                            1, 0, this->currentOrderPriorityValue);
                        return 9;
                    }
                }
            }
        }
        break;
    }

    case 0x2BD: {
        RGE_Static_Object* target = 0;

        if (this->defendTargetValue != invalidValue) {
            target = this->lookupObject(this->defendTargetValue);
            if (target == 0) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID,
                            str_aiuaimod_path, 0x15C0);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }

            if (this->currentTargetXValue == -1.0f) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
            }

            if (target->object_state > 2 && target->owner->id != 0) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID,
                            str_aiuaimod_path, 0x15D9);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }
        }

        if (this->currentActionValue != 600 &&
            (this->currentActionValue != 0x262 ||
             this->objectValue->currentTargetID() != this->defendTargetValue)) {
            float distance;
            if (this->defendTargetValue != invalidValue) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
                this->currentTargetZValue = target->world_z;
                distance = this->objectValue->distance_to_object(target);
            } else {
                distance = this->objectValue->distance_to_position(
                    this->currentTargetXValue,
                    this->currentTargetYValue,
                    this->objectValue->world_z);
            }

            if (distance > this->desiredTargetDistanceValue - (-1.0f)) {
                if (this->defendTargetValue != invalidValue) {
                    if (this->objectValue->canPath(
                            this->defendTargetValue,
                            this->desiredTargetDistanceValue,
                            0, 0, invalidValue, invalidValue) == 1) {
                        this->moveTo(
                            this->defendTargetValue,
                            this->desiredTargetDistanceValue, 1);
                        return 10;
                    }
                } else {
                    int x = (int)this->currentTargetXValue;
                    int y = (int)this->currentTargetYValue;
                    XYZPoint point = { x, y, invalidValue };
                    if (this->objectValue->canPath(
                            point, this->desiredTargetDistanceValue,
                            invalidValue, 0, 0,
                            invalidValue, invalidValue) == 1) {
                        this->moveTo(
                            this->currentTargetXValue,
                            this->currentTargetYValue,
                            this->currentTargetZValue,
                            this->desiredTargetDistanceValue, 1);
                        return 10;
                    }
                }
                return 10;
            }

            if (target != 0 && target->unitAI() != 0) {
                UnitAIModule* targetAI = target->unitAI();
                int attacker = targetAI->closestAttacker(0);
                if (attacker != invalidValue) {
                    this->attackObject(attacker, 1);
                    return 10;
                }
                if (this->processIdle(0) == 6) {
                    return 10;
                }
            }
        }
        break;
    }

    case 0x2C8: {
        RGE_Static_Object* target = 0;
        if (this->currentTargetValue != invalidValue) {
            target = this->lookupObject(this->currentTargetValue);
            if (target == 0 || target->object_state > 2) {
                this->defendTargetValue = invalidValue;
                this->removeCurrentTarget();
                if (actionFile != 0) {
                    long objectID;
                    if (this->objectValue != 0) {
                        objectID = this->objectValue->id;
                    } else {
                        objectID = invalidValue;
                    }
                    fprintf(actionFile, str_fmt_stopObject, objectID,
                            str_aiuaimod_path, 0x1582);
                }
                this->stopObject(1);
                this->currentOrderValue = invalidValue;
                return 9;
            }
        }

        float xDiff;
        float yDiff;
        if (target != 0) {
            xDiff = target->world_x - this->currentTargetXValue;
        } else {
            xDiff = -10.0f;
        }
        if (target != 0) {
            yDiff = target->world_y - this->currentTargetYValue;
        } else {
            yDiff = -10.0f;
        }

        if (xDiff < DAT_0056ec00 || xDiff > DAT_0056ec08 ||
            yDiff < DAT_0056ec00 || yDiff > DAT_0056ec08) {
            float distance;
            if (this->currentTargetValue != invalidValue) {
                this->currentTargetXValue = target->world_x;
                this->currentTargetYValue = target->world_y;
                this->currentTargetZValue = target->world_z;
                distance = this->objectValue->distance_to_object(target);
            } else {
                distance = this->objectValue->distance_to_position(
                    this->currentTargetXValue,
                    this->currentTargetYValue,
                    this->objectValue->world_z);
            }

            if (distance > this->desiredTargetDistanceValue) {
                if (this->currentTargetValue != invalidValue) {
                    this->moveTo(this->currentTargetValue,
                                 this->desiredTargetDistanceValue, 1);
                    return 10;
                } else {
                    this->moveTo(
                        this->currentTargetXValue,
                        this->currentTargetYValue,
                        this->currentTargetZValue,
                        this->desiredTargetDistanceValue, 1);
                    return 10;
                }
            }
        }
        break;
    }

    default:
        break;
    }

    return 9;
}
