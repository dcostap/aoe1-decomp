#ifndef ACT_ENTR_CONTEXT_H
#define ACT_ENTR_CONTEXT_H

#include "xy_point.h"

class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Action;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class XYZBYTEPoint;
class Path;
class RGE_Object_List;
class RGE_Active_Sprite_List;

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;

    RGE_Static_Object* object(int param_1);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char param_1);
    virtual void do_resign(int param_1);
    virtual void changeToHumanPlayer(void);
    virtual void changeToComputerPlayer(void);
    virtual char* aiStatus(int param_1);
    virtual int isEnemy(int param_1);
    virtual int isAlly(int param_1);

    int computerPlayer(void);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game(void);
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update(void);
    virtual void check_damage_sprites(void);
    virtual void rehook(void);
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite* param_1);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(void);
    virtual void create_doppleganger_when_dying(void);
    virtual void destroy_obj(void);
    virtual void die_die_die(void);
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack(void);
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair(void);
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop(void);
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound(void);
    virtual void play_move_sound(void);
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj(void);
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving(void);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual void enter_obj(RGE_Static_Object* param_1);
    virtual void exit_obj(void);
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table(void);
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(void);
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed(void);
    virtual float getAngle(void);
    virtual float maximumSpeed(void);
    virtual float rateOfFire(void);
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability(void);
    virtual float weaponRange(void);
    virtual float minimumWeaponRange(void);
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint(void);
    virtual int currentTargetID(void);
    virtual float currentTargetX(void);
    virtual float currentTargetY(void);
    virtual float currentTargetZ(void);
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove(void);
    virtual unsigned char actionState(void);
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite(void);
    virtual void logDebug(const char*, ...);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    // VC5 reverses this adjacent overload group in the vtable.
    virtual int attack(int, int);
    virtual int attack(float, float, float, int);
    // VC5 reverses this adjacent overload group in the vtable.
    virtual int moveTo(int, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
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
    virtual int stopAction(void);
    virtual int pause(void);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(XYPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6);

    int id;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[0x03];

    float distance_to_object(RGE_Static_Object* param_1);
    unsigned char is_dying(void);
    unsigned char more_room(void);
};

/*
 * BINARY NOTE: act_entr.cpp proves action-object calls at +38, +D0, +134,
 * +148, +154, and +1B4.  The inherited static-object surface owns these
 * slots.  The action-object tail retains the observed +184 action-list field.
 */
class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_4C[0x138];
    RGE_Action_List* actions;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action* param_1);
    RGE_Action* get_action(void);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook(void);
    virtual void save(int param_1);
    virtual short type(void);
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char attack_response(RGE_Static_Object* param_1);
    virtual unsigned char relation_response(long param_1, unsigned char param_2);
    virtual void copy_obj(void* param_1);
    virtual void copy_obj_sprites(void* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual RGE_Static_Object* get_target_obj2(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    unsigned short action_type;
    unsigned short gap_06;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x03];
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
    char gap_3D[0x03];

    RGE_Action(RGE_Action_Object* param_1, int param_2);
    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    float targetX(void);
    float targetY(void);
    void setSubAction(unsigned char param_1);
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6);

    float range;
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Enter(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    virtual void first_in_stack(unsigned char param_1);
protected:
    virtual void set_state(unsigned char param_1);
public:
    virtual unsigned char update(void);
};

extern float DAT_0056e1a0;
extern float DAT_0056e1a4;
extern float DAT_0056e1a8;

#endif
