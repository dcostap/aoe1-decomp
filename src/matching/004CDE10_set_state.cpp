// 004CDE10 TRIBE_Action_Convert::set_state
// Requested 004E2270 was absent from live status.
// Query fallback: 004CDE10 was the smallest unleased normal target with no
// current check (`--max-lifetime-probes 0`).
//
// Attempt log:
// - Replaced the prior raw vtable and cursor scaffold with typed action,
//   object, task, player, and static-object surfaces.
// - Natural reconstruction baseline: /GX, ordinary switch, and Move_To
//   constructors.  The original has EH registration around both allocations.
// - Baseline: 618 rebuilt bytes, 80.00% exact-block coverage; the remaining
//   structural gaps are the remapped dispatch table and case-6 sprite call.
// - Shared local sprite plus a common label duplicated the call and grew the
//   body to 622 bytes; restored the natural direct-call source.
// - Grouped and split no-op arms, and a zero-based dispatch expression, all
//   emitted the same 618-byte code; retained the period-plausible switch.
// - Restored the pinned clean source for closure; the remaining extra
//   virtual +0x38 call is the unresolved shared sprite-tail gap.
// - Grouped the master-sprite states into one typed post-switch call; VC5
//   emitted the same 618-byte code and kept the extra virtual +0x38 call.
// - Reordered the switch arms to the Ghidra listing order with a typed sprite
//   result; code grew to 622 bytes and call alignment worsened, so restored.
// - Tried a typed state enum with a sprite local declared after state storage;
//   VC5 kept the extra virtual +0x38 call, grew to 622 bytes, and worsened the
//   first dispatch hunk. Restored the clean direct-call source.
// - Tried a typed shared sprite tail in the existing switch order; both a
//   post-switch call and an explicit shared label stayed at 622 bytes with
//   three virtual +0x38 calls. Restored the clean source; the tail merge is
//   not obtained by this source shape.
// - Reordered the switch to route state 3, state 6, and states 1/2/13/14
//   through one typed post-switch sprite call. This follows the original
//   line-302 shared tail and its two total vslot+38 calls. Result: 541 bytes,
//   16/16 calls, 95.16% shape; retained as the best clean reconstruction.
// - Tried direct typed new_sprite calls with state 3 fallthrough and binary
//   no-op states 8/9/10/12. VC5 did not merge the calls: 618 bytes, 17 calls,
//   and a worse dispatch. Restored the clean shared-tail source.
// - Replaced the shared sprite local with a typed master-sprite label and a
//   direct state-6 move-sprite call. VC5 tail-merged the virtual call to the
//   original block. Final rebuild: 541/541 bytes, 16/16 calls, 0.0000% diff.
// - Canonical ABI audit: replaced all generic vfXX declarations with named
//   repository class-dump methods. Restored world_x/world_y/world_z,
//   RGE_Task::work_val2, and RGE_Player::make_new_object. Full rebuild remains
//   an exact, policy-valid 541-byte match.

#ifndef TACT_CNV_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;
class RGE_Task;
class RGE_Action;
class RGE_Action_List;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Active_Sprite_List;
class TDrawArea;
class LOSTBL;
class XYZBYTEPoint;
class RGE_Game_World;
class RGE_Master_Player;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;

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
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x14];
    RGE_Sprite* sprite;
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
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

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action_List {
public:
    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Task {
public:
    char gap_00[0x20];
    float work_val2;
    char gap_24[0x10];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    char gap_3C[8];
    RGE_Sound* work_sound;
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void setSubAction(unsigned char);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    float range;
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    virtual void set_state(unsigned char);
    unsigned char was_same_owner;
    char gap_41[3];
    float requiredRange;
};

#endif

void TRIBE_Action_Convert::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;
    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25C, 0, 0);
        goto master_sprite;

    case 11: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            this->requiredRange,
            this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->requiredRange,
            this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 5:
        return;

    case 6:
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0)
            this->task->work_sound->play(1);
        if (this->target_obj != 0 && this->target_obj->owner->id > 0) {
            this->target_obj->owner->make_new_object(0x70, this->obj->world_x, this->obj->world_y, this->obj->world_z, 0);
        }
        this->timer = this->task->work_val2;
        return;

    case 8:
    case 9:
    case 10:
    case 12:
    case 1:
    case 2:
    case 13:
    case 14:
    master_sprite:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }

}
