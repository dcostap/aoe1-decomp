// VA: 00507640 TribeSoldierUnitAIModule::processIdle
// PDB: taiuaimd.cpp:2541-2629, 564 bytes
//
// Attempt log:
// Prior parked work reconstructed the broad behavior but used an incorrect
// object/master surface and omitted the maximum-speed result in the final
// movement calculation.  The current candidate restores the period
// UnitAIModule/RGE object surfaces and the duplicated strategic-number gate
// visible in the executable.  Keep later source-shape probes below this note.
//
// Prior evidence retained from the parked attempt:
// - the target is normal corpus work and uses the default VC5 /O2 /Oy flags;
// - all 16 calls, shared return-5 tail, and the +0xFC/+0x9C virtual slots are
//   binary-proven;
// - the final movement uses object maximumSpeed() multiplied by [5758B0h]
//   (3.0f), then normalized x/y deltas and evasiveMoveTo(..., world_z, 1).
// Baseline result: exact 564-byte match with the default /O2 /Oy response.
// Source audit: named master/player/object ownership and ordinary virtual
// declarations are retained; no inline asm, volatility, or codegen-only pad
// function is used.
//
// Exact-finish notes:
// - The first exact check matched 564 bytes and all 16 ordered calls.
// - The real object, player, master, and UnitAIModule surfaces are required.
// - Collapsing the duplicated strategic-number gate removed 3 calls and 56
//   bytes. It also changed the first direct call, so the shipped gate stays.
// - Removing the explicit sqrt float cast kept the exact result. The reduced
//   source keeps that simpler form.
// - Keep SPEED_3. The binary loads the soldier speed constant at 5758B0h.

#include <math.h>

extern const float SPEED_3; // 3.0f at [5758B0h]

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;                         // +0x10
};

class RGE_Game_World;
class RGE_Static_Object;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);

    char gap_04[0x38];                // +0x04 .. +0x3B
    RGE_Game_World* world;            // +0x3C
    char gap_40[0x0A];
    short id;                         // +0x4A

    int computerPlayer();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
    int difficultyLevel();
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
    virtual float maximumSpeed(); // slot 0x3F, +0xFC

    char gap_04[4];                    // +0x04 .. +0x07
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                 // +0x0C
    char gap_10[0x28];                 // +0x10 .. +0x37
    float world_x;                     // +0x38
    float world_y;                     // +0x3C
    float world_z;                     // +0x40

    int inGroup();
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
    int scenarioGame();
    int singlePlayerGame();
};

extern RGE_Base_Game* rge_base_game;

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

    RGE_Static_Object* objectValue;     // +0x04
    char gap_08[0x20];                  // +0x08 .. +0x27
    int currentActionValue;             // +0x28
};

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    int processIdle(int param_1);
};
#endif

int TribeSoldierUnitAIModule::processIdle(int param_1)
{
    if (param_1 == 1 && this->processRetryableOrder() == 8) {
        return 6;
    }

    if (this->objectValue->owner->id != 0 &&
        (this->objectValue->owner->computerPlayer() != 0 ||
         this->objectValue->master_obj->id != 0x12B)) {
        if (this->currentActionValue != 0x2D5 ||
            (this->objectValue->master_obj->id != 0x23 &&
             this->objectValue->master_obj->id != 0x24 &&
             this->objectValue->master_obj->id != 0xFA)) {
            int targetID = this->bestUnitToAttack(1, 0, 0);
            if (targetID != -1 && this->attackObject(targetID, 1) == 1) {
                return 6;
            }

            if (this->objectValue->owner->computerPlayer() != 0 &&
#ifdef TAIUAIMD_COMPLETE_TU
                taiuaimd_object_in_group(this->objectValue) != 1) {
                taiuaimd_world_difficulty(this->objectValue->owner->world);
#else
                this->objectValue->inGroup() != 1) {
                this->objectValue->owner->world->difficultyLevel();
#endif

                if ((rge_base_game->scenarioGame() == 1 &&
                     rge_base_game->singlePlayerGame() == 1 &&
#ifdef TAIUAIMD_COMPLETE_TU
                     taiuaimd_player_strategic_number(this->objectValue->owner, 0x8F) == 0) ||
#else
                     this->objectValue->owner->strategicNumber(0x8F) == 0) ||
#endif
                    (rge_base_game->singlePlayerGame() == 1 &&
#ifdef TAIUAIMD_COMPLETE_TU
                     taiuaimd_player_strategic_number(this->objectValue->owner, 0x8F) == 0)) {
#else
                     this->objectValue->owner->strategicNumber(0x8F) == 0)) {
#endif
                    return 5;
                }

                if (this->currentActionValue != 0x2BD &&
                    this->currentActionValue != 0x2D5) {
                    int targetID2 = this->closestObject(-1, -1, -1, -1, 0);
                    if (targetID2 != -1) {
                        RGE_Static_Object* target =
                            this->objectValue->owner->world->object(targetID2);
                        if (target != 0) {
                            float speed =
                                this->objectValue->maximumSpeed() * SPEED_3;
                            float xDiff = target->world_x - this->objectValue->world_x;
                            float yDiff = target->world_y - this->objectValue->world_y;
                            float distance =
                                sqrt(xDiff * xDiff + yDiff * yDiff);
                            float x =
                                (float)(-((xDiff / distance) * speed)) +
                                this->objectValue->world_x;
                            float y =
                                (float)(-((yDiff / distance) * speed)) +
                                this->objectValue->world_y;
                            this->evasiveMoveTo(
                                x, y, this->objectValue->world_z, 1);
                            return 6;
                        }
                    }
                }
            }
        }
    }

    return 5;
}
