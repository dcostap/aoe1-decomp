#ifndef AOE1_ACT_TRAN_CONTEXT_H
#define AOE1_ACT_TRAN_CONTEXT_H

// Canonical declaration surface for act_tran.cpp.
//
// PDB evidence binds all listed owners to C:\\msdev\\work\\age1_x1\\act_tran.cpp.
// Their source-line order is also their declaration order in this wrapper:
// constructors, first_in_stack, set_state, update, stop, move_to, work,
// next_to_drop_off_terrain, and targetZone.  The 00406D90 vector-deleting
// destructor is compiler generated from this one RGE_Action_Transport type.
//
// The owner files include this context for isolated checks.  The wrapper also
// uses this canonical surface so one translation unit has one owner for each
// class and vtable.

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Color_Table;
class TDrawArea;
struct RGE_Armor_Weapon_Info;
struct LOSTBL;
struct XYZBYTEPoint;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(int value, RGE_Action_Object* object);
    virtual int setup(RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int value);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long value, unsigned char relation);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* task, RGE_Task* other_task);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);

    union {
        short action_type;
        short field_04;
    };
    char gap_06[2];
    union {
        RGE_Action_Object* obj;
        RGE_Static_Object* object;
    };
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    union {
        float target_x;
        float field_20;
    };
    union {
        float target_y;
        float field_24;
    };
    union {
        float target_z;
        float field_28;
    };
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    RGE_Action(int id, RGE_Action_Object* object, int flag);
    RGE_Action(RGE_Action_Object* object, int flag);
    void setSubAction(unsigned char value);
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    void* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    long map_width;
    long map_height;

    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x14];
    RGE_Sprite* sprite;
    char gap_1C[0x14];
    float radius_x;
    float radius_y;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int stance);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  unsigned char, float);
    virtual void scenario_save(int file);
    virtual void scenario_load(int file, long* data, float version);
    virtual void scenario_postsave(int file);
    virtual void scenario_postload(int file, long* data, float version);
    virtual void load(int file);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file);
    virtual void save2(int file);
    virtual void save_info(int file);
    virtual void random_start();
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual void* addObject(void*, int, int);
    virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int param_1, int param_2, int param_3,
                        long param_4, long param_5, long param_6);
    virtual void logStatus(void*, int);
    virtual void load_victory(int file, long* data, unsigned char flag);
    virtual void new_victory();

    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update(void);
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite* sprite);
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
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
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
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*,
                                                          float, float, float);
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
    virtual void notify(int param_1, int param_2, int param_3,
                        int param_4, int param_5, int param_6);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x14];
    RGE_Object_List* objects;
    char gap_28[0x10];
    float world_x;
    float world_y;
    float world_z;

    unsigned char lookupZone(int x, int y);
    float distance_to_position(float x, float y, float z);
    int withinRangeOfZone(unsigned char zone, float range);
    unsigned char drop_held_objects(int mode);
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char gap_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char gap_10[0x24];
    RGE_Sprite* move_sprite;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*,
                                            float, float, float);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action* action);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* object, float x, float y, float z,
                       float range, RGE_Sprite* sprite);
    float move_range;
};

class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(int id, RGE_Action_Object* object);
    RGE_Action_Transport(RGE_Action_Object* object, RGE_Task* task,
                         float x, float y, float z);

    virtual void first_in_stack(unsigned char value);
    virtual unsigned char update(void);
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual int stop(void);
    virtual int next_to_drop_off_terrain(void);

protected:
    virtual void set_state(unsigned char state);

public:
    int targetZone(void);
};

#endif
