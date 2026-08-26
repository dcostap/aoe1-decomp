#ifndef TACT_REP_CONTEXT_H
#define TACT_REP_CONTEXT_H

// Canonical declarations for the tact_rep.cpp source module.
//
// The action hierarchy and the virtual methods below follow the reviewed
// tactical-action surfaces.  These declarations supply the inherited ABI for
// the tact_rep owners.  They do not create function bodies or source owners.

typedef unsigned char uchar;

class XYPoint;
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Action_Object_Data;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Base_Game;

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame;
    char gap_60[0x10];
    uchar flags;
    uchar gap_71;
    short id;
};

// The action-object master carries the proven id/group fields and the
// master work rate used by update().
class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    char gap_04[0x0C];
    short id;             // +10
    short copy_id;        // +12
    short object_group;   // +14
    char gap_16[0xCE];
    float work_rate;      // +E4
};

class RGE_Action_Object_Data {
public:
    char gap_00[0x14];
    short object_type;                                  // +14
    char gap_16[2];
    RGE_Sprite* sprite;   // +18
    char gap_1C[0xF8];
    float work_range;     // +114
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();                    // +00
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float); // +04
    virtual void recycle_out_of_game();              // +08
    virtual void draw(void*, short, short, void*);   // +0C
    virtual void shadow_draw(void*, short, short, uchar); // +10
    virtual void normal_draw(short, short, short);   // +14
    virtual void draw_front_frame(short, short, short); // +18
    virtual void draw_back_frame(short, short, short); // +1C
    virtual void draw_frame(short, short, short);    // +20
    virtual uchar update();                           // +24
    virtual void check_damage_sprites();              // +28
    virtual void rehook();                            // +2C
    virtual void save(int);                           // +30
    virtual float teleport(float, float, float);      // +34
    virtual void new_sprite(RGE_Sprite*);             // +38
    virtual void add_overlay_sprite(RGE_Sprite*, uchar); // +3C
    virtual void remove_overlay_sprite(RGE_Sprite*);  // +40
    virtual void change_ownership(RGE_Player*);       // +44
    virtual void modify(float, uchar);                // +48
    virtual void modify_delta(float, uchar);          // +4C
    virtual void modify_percent(float, uchar);        // +50
    virtual void transform(RGE_Master_Action_Object*); // +54
    virtual void copy_obj(RGE_Master_Action_Object*); // +58
    virtual void set_object_state(uchar);             // +5C
    virtual void remove_visible_resource();           // +60
    virtual void create_doppleganger_when_dying();    // +64
    virtual void destroy_obj();                       // +68
    virtual void die_die_die();                       // +6C
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*); // +70
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*); // +74
    virtual void rotate(long);                        // +78
    virtual uchar can_attack();                       // +7C
    virtual void set_attribute(short, float);         // +80
    virtual void set_attribute_amount(float, uchar, uchar); // +84
    virtual uchar heal(float);                        // +88
    virtual int heal(int, int);                       // +8C
    virtual int canRepair();                          // +90
    virtual void notify_of_relation(long, uchar);     // +94
    virtual void do_command(RGE_Static_Object*, float, float, float); // +98
    virtual void move_to(RGE_Static_Object*, float, float, float); // +9C
    virtual void work(RGE_Static_Object*, float, float, float); // +A0
    virtual void stop();                              // +A4
    virtual void set_attack(RGE_Static_Object*);      // +A8
    virtual void play_command_sound();                // +AC
    virtual void play_move_sound();                   // +B0
    virtual void new_angle(float);                    // +B4
    virtual RGE_Static_Object* spawn_death_obj();     // +B8
    virtual RGE_Master_Action_Object* get_command_master(RGE_Static_Object*, float, float, float); // +BC
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar); // +C0
    virtual void release_being_worked_on(RGE_Static_Object*); // +C4
    virtual uchar is_moving();                        // +C8
    virtual RGE_Static_Object* get_target_obj();      // +CC
    virtual void enter_obj(RGE_Static_Object*);        // +D0
    virtual void exit_obj();                           // +D4
    virtual int explore_terrain(RGE_Player*, uchar, int); // +D8
    virtual void unexplore_terrain(RGE_Player*, uchar, int); // +DC
    virtual void* get_los_table();                     // +E0
    virtual int inAttackRange(RGE_Static_Object*);     // +E4
    virtual uchar underAttack();                       // +E8
    virtual void setUnderAttack(uchar);                // +EC
    virtual float calc_attack_modifier(RGE_Static_Object*); // +F0
    virtual float getSpeed();                          // +F4
    virtual float getAngle();                          // +F8
    virtual float maximumSpeed();                      // +FC
    virtual float rateOfFire();                        // +100
    virtual float damageCapability(RGE_Static_Object*); // +104
    virtual float damageCapability();                  // +108
    virtual float weaponRange();                       // +10C
    virtual float minimumWeaponRange();                // +110
    virtual int passableTile(float, float, int);       // +114
    virtual uchar facetToNextWaypoint();               // +118
    virtual int currentTargetID();                     // +11C
    virtual float currentTargetX();                    // +120
    virtual float currentTargetY();                    // +124
    virtual float currentTargetZ();                    // +128
    virtual void setWaitingToMove(uchar);              // +12C
    virtual uchar waitingToMove();                     // +130
    virtual uchar actionState();                      // +134
    virtual uchar keepGatheringWhenObjectIsOut(int);   // +138
    virtual uchar produceWhenKilledBy(int);            // +13C
    virtual uchar useSameZoneDropsite();              // +140
    virtual void logDebug(const char*, ...);           // +144
    virtual void notify(int, int, int, long, long, long); // +148
    virtual int attack(float, float, float, int);      // +14C
    virtual int attack(int, int);                      // +150
    virtual int moveTo(float, float, float, float, int);  // +154
    virtual void moveTo_int_float_int();               // +158
    virtual void moveTo_int_int();                     // +15C
    virtual void moveAwayFrom();                       // +160
    virtual void hunt();                                // +164
    virtual void gather();                              // +168
    virtual void convert();                             // +16C
    virtual void repair();                              // +170
    virtual void build();                               // +174
    virtual void trade();                               // +178
    virtual void explore();                             // +17C
    virtual void enter();                               // +180
    virtual void unload();                              // +184
    virtual void transport();                          // +188
    virtual void stopAction();                         // +18C
    virtual void pause();                              // +190
    virtual void canPath();                            // +194
    virtual void canPath_extended();                   // +198
    virtual void canBidirectionPath();                 // +19C
    virtual void canPathWithObstructions();            // +1A0
    virtual void canPathWithAdditionalPassability();   // +1A4
    virtual void findFirstTerrainAlongExceptionPath(); // +1A8
    virtual void canLinePath();                        // +1AC
    virtual void canLinePath_extended();               // +1B0
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int); // +1B4
    virtual void userDefinedWaypoint();               // +1B8
    virtual void addUserDefinedWaypoint();             // +1BC
    virtual void removeAllUserDefinedWaypoints();      // +1C0
    virtual void removeUserDefinedWaypoint();          // +1C4
    virtual void numberUserDefinedWaypoints();         // +1C8
    virtual void findAvoidancePath();                  // +1CC
    virtual void get_action_checksum();                // +1D0
    virtual void get_waypoint_checksum();              // +1D4
    virtual void setup_world();                        // +1D8
    virtual void setup_static_object();                // +1DC
    virtual void create_object_list_tail();            // +1E0
    virtual void create_sprite_list_tail();            // +1E4

    long id;                                           // +04
    union {
        RGE_Master_Action_Object* master_obj;         // +08
        RGE_Action_Object_Data* object_data;          // +08
    };
    RGE_Player* owner;                                 // +0C
    char gap_10[0x28];                                 // to +38
    float world_x;                                     // +38
    float world_y;                                     // +3C
    float world_z;                                     // +40
    float attribute_amount_held;                      // +44
    uchar object_state;                                // +48
    char gap_49[0x13B];                                // to +184
    RGE_Action_List* actions;                          // +184
    uchar command_flag;                                // +188

    void removeAllFromPathingGroup();
    float distance_to_object(RGE_Static_Object*);
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Action_Object();
    virtual int setup_animated(void*, RGE_Player*, float, float, float); // +1E8
    virtual void stop_moving();                         // +1EC
    virtual uchar turn_towards(RGE_Static_Object*, float, float); // +1F0
    virtual int setup_moving(void*, RGE_Player*, float, float, float); // +1F4
    virtual void work2(RGE_Static_Object*, float, float, float, uchar); // +1F8
    virtual void set_task(short);                       // +1FC
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;                     // +84
    RGE_Static_Object* object(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);                             // +1C

    char gap_04[0x24];
    RGE_Object_List* objects;                            // +28
    char gap_2C[0x10];
    RGE_Game_World* world;                               // +3C
    char gap_40[0x0A];
    short id;                                            // +4A
};

class RGE_Task {
public:
    char gap_00[0x1C];
    float work_rate;                                     // +1C
    char gap_20[4];
    float range;                                         // +24
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;                             // +34
    RGE_Sprite* work_sprite;                             // +38
    RGE_Sprite* work_sprite2;                            // +3C
    RGE_Sprite* carry_sprite;                            // +40
    RGE_Sound* work_sound;                               // +44
    RGE_Sound* work_sound2;                              // +48
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();                              // +0C
    void delete_list();
    void add_action(RGE_Action*);
    RGE_Action* get_action();
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
    virtual void first_in_stack(uchar);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual uchar attack_response(RGE_Static_Object*);
    virtual uchar relation_response(long, uchar);
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;                                   // +04
    char gap_06[2];
    RGE_Action_Object* obj;                              // +08
    uchar state;                                         // +0C
    char gap_0D[3];
    RGE_Static_Object* target_obj;                       // +10
    RGE_Static_Object* target_obj2;                      // +14
    int targetID;                                        // +18
    int target2ID;                                       // +1C
    float target_x;                                      // +20
    float target_y;                                      // +24
    float target_z;                                      // +28
    float timer;                                         // +2C
    RGE_Task* task;                                      // +30
    RGE_Action_List* sub_actions;                       // +34
    RGE_Sprite* sprite;                                  // +38
    uchar subActionValue;                                // +3C
    char gap_3D[3];

    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, int);
    void setSubAction(uchar);
    float targetX();
    float targetY();
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class XYPoint {
public:
    int x;
    int y;
};

class RGE_Object_Node {
public:
    RGE_Action_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long); // +40
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    TRIBE_Action_Repair(int, RGE_Action_Object*, int);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Repair(RGE_Action_Object*, RGE_Task*, float, float, float);

    virtual int setup(int, RGE_Action_Object*);
    virtual void save(int);
    virtual void first_in_stack(uchar);

protected:
    virtual void set_state(uchar);

public:
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);

protected:
    void meet_target();

public:
    union {
        uchar save_target_command_flag;                  // +40
        uchar repair_field_40;                            // setup() view
    };
};

extern float save_game_version;
extern void rge_read(int, void*, int);
extern "C" void __cdecl rge_write(int, void*, int);
extern RGE_Base_Game* rge_base_game;
extern float DAT_0057526c;
extern double DAT_00575270;
extern float DAT_00575278;
extern float DAT_0086bc08;
extern float DAT_005750e0;
extern double DAT_005750e8;

#endif
