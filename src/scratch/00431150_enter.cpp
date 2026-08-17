// VA: 00431150, RGE_Combat_Object::enter, 255 bytes
// Source: com_obj.cpp lines 1097-1139
// FLAGS: /nologo /c /O2 /Oy /GX
//
// Source-gate reconstruction:
// - Use the reviewed RGE_Static_Object -> RGE_Animated_Object ->
//   RGE_Moving_Object -> RGE_Action_Object ownership chain.
// - Keep action target and type calls on their canonical RGE_Action methods.
// - Keep getTask and set_only_action on RGE_Action_Object.
// - ORIGINAL BUG: delete_list is called before set_only_action. The latter
//   deletes the list again before it adds the new action.
// - Structured returns preserve the call and fault order without EH-layout
//   labels from the decompiler.

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Task;
class RGE_Action;
class RGE_Sprite;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class Path;
struct XYPoint;
struct XYZPoint;
struct XYZBYTEPoint;
template<class T> class ManagedArray;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    uchar gap_04[0x84];
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

    RGE_Static_Object* object(int index);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    uchar gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Action_List {
public:
    uchar have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(uchar value);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual uchar attack_response(RGE_Static_Object* object);
    virtual uchar relation_response(long value, uchar relation);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* source, RGE_Task* destination);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(uchar value);

    short action_type;
    uchar gap_06[2];
    RGE_Action_Object* obj;
    uchar state;
    uchar gap_0D[3];
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
    uchar subActionValue;
    uchar gap_3D[3];
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
    RGE_Action_Enter(RGE_Action_Object* object, RGE_Task* task,
                     RGE_Static_Object* target);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
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
    virtual uchar facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(uchar);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual uchar keepGatheringWhenObjectIsOut(int);
    virtual uchar produceWhenKilledBy(int);
    virtual uchar useSameZoneDropsite();
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
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    uchar gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    uchar gap_44[0x44];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    uchar gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);

    uchar waiting;
    uchar gap_181[3];
    RGE_Action_List* actions;
    uchar command_flag;
    uchar gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    uchar gap_194[0x30];
    virtual int enter(int param_1, int param_2);
};

int RGE_Combat_Object::enter(int param_1, int param_2)
{
    RGE_Static_Object* obj = this->owner->world->object(param_1);

    if (obj == 0)
        return 0;

    if (param_2 == 0) {
        if (this->actions->have_action() == 1) {
            RGE_Action* action = this->actions->get_action();
            if (action->get_target_obj() == obj) {
                action = this->actions->get_action();
                if (action->type() == 3)
                    return 1;
            }
        }
    }

    RGE_Task* task = this->getTask(obj, obj->world_x, obj->world_y, obj->world_z);
    if (task == 0)
        return 0;

    RGE_Action_Enter* action = new RGE_Action_Enter(this, task, obj);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}
