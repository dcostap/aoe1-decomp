#ifndef AOE1_COMMAND_H
#define AOE1_COMMAND_H

// Declarations used by the original Command.cpp translation unit.

template<class T> class ManagedArray {
public:
    T* data;
    int count;
    int capacity;
    int grow_by;
};

struct RGE_Obj_Info {
    int id;
};

struct RGE_Command_Order {
    unsigned char command;
    unsigned char gap_01[3];
    union {
        RGE_Obj_Info target;
        int target_id;
    };
    unsigned char unit_num;
    unsigned char gap_09[3];
    union { float location_x; float pos_x; };
    union { float location_y; float pos_y; };
    union {
        RGE_Obj_Info units[1];
        RGE_Obj_Info ids[1];
    };
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

struct WayPacket {
    unsigned char cmd;
    unsigned char player;
    char pad2[2];
    int rec;
    unsigned char one;
    unsigned char p3;
    unsigned char p4;
    unsigned char p5;
    char rest[12];
};

struct RGE_Command_Stop {
    unsigned char command;
    unsigned char unit_num;
    unsigned char gap_02[2];
    union {
        int items[1];
        int object_ids[1];
    };
};

struct RGE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float amount;
};
struct RGE_Command_Add_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char attr_id;
    unsigned char gap_03;
    union {
        int attr_amount;
        float amount;
    };
};
struct RGE_Command_Create {
    unsigned char command;
    unsigned char gap_01;
    short obj_catagory;
    unsigned char player_id;
    unsigned char gap_05[3];
    float location_x;
    float location_y;
    float location_z;
};

struct RGE_Command_Add_Waypoint {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int recipient;
    unsigned char numberWaypoints;
    XYZBYTEPoint waypoint[5];
};

struct RGE_Command_Work {
    unsigned char command;
    unsigned char gap_01[3];
    int target;
    unsigned char recipient_count;
    unsigned char gap_09[3];
    float target_x;
    float target_y;
};

class RGE_Game_World;
class RGE_Static_Object;
class UnitAIModule {
public:
    void setCurrentOrder(int);
    void setCurrentAction(int);
    void setCurrentTarget(int, int, float, float, float);
};

struct RGE_Command_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char gap_03;
    int recipient;
    short orderType;
    unsigned char orderPriority;
    unsigned char gap_0B;
    int target;
    unsigned char targetOwner;
    unsigned char gap_11[3];
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
    unsigned char gap_26[2];
};

struct RGE_Command_Group_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char recipient_count;
    short orderType;
    unsigned char orderPriority;
    unsigned char gap_07;
    int target;
    unsigned char targetOwner;
    unsigned char gap_0D[3];
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
    unsigned char gap_22[2];
};

struct RGE_Command_Resign {
    unsigned char command;
    unsigned char player_id;
    unsigned char comm_player_id;
    unsigned char dropped;
};

struct RGE_Command_Create_Group {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    unsigned char numberUnitsToGroup;
};

struct RGE_Command_Add_To_Group {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    int groupRange;
    int newUnit;
};

struct RGE_Command_Remove_From_Group {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
    int unit;
};

struct RGE_Command_Destroy_Group {
    unsigned char command;
    unsigned char player_id;
    unsigned char gap_02[2];
    int groupCommander;
};

struct RGE_Command_Formation {
    unsigned char command;
    unsigned char gap_01[3];
    int unitNum;
    int formationID;
    RGE_Obj_Info units[1];
};

struct RGE_Command_Group_Waypoint;
struct RGE_Command_Group_Waypoint {
    unsigned char command;
    unsigned char unit_num;
    unsigned char x;
    unsigned char y;
};

struct RGE_Command_Pause {
    char gap_00;
    unsigned char unit_num;
    int object_ids[1];
};

struct RGE_Command_Add_Attribute;
struct RGE_Command_Create;
struct RGE_Command_Create_Group;
struct RGE_Command_Pause;
struct RGE_Command_Add_Waypoint;
struct RGE_Command_Work;

class RGE_Map {
public:
    char gap_00[8];
    union {
        int map_width;
        int width;
    };
    union {
        int map_height;
        int height;
    };
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(class RGE_Player*, float, float, float);
    unsigned char master_type;
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    short gap_16;
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2D[3];
    float radius_x;
    float radius_y;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status();
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void aiStatus();
    virtual void isEnemy();
    virtual void isAlly();
    virtual void isNeutral();
    virtual void isAllNeutral();
    virtual void setDiplomaticStance();
    virtual void loadAIInformation();
    virtual void sendUnitAIOrder();
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, unsigned int, unsigned int, unsigned int);
    virtual void kickAI();
    virtual void strategicNumber();
    virtual void sendGameOrder();
    virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand();
    virtual void sendPlayCommand2();
    virtual void sendAICommand();
    virtual void objectCostByType();
    virtual void trackUnitGather();
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  unsigned char, float);
    virtual void scenario_save();
    virtual void scenario_load();
    virtual void scenario_postsave();
    virtual void scenario_postload();
    virtual void load();
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save();
    virtual void save2();
    virtual void save_info();
    virtual void random_start();
    virtual void make_new_object();
    virtual void analyize_selected_objects();
    virtual void get_mouse_pointer_action_vars();
    virtual void command_make_move();
    virtual void command_make_work();
    virtual void command_make_do();
    virtual void command_stop();
    virtual void command_place_object();
    virtual void command_add_attribute();
    virtual void command_give_attribute();
    virtual void command_formation();
    virtual void command_stand_ground();
    virtual void command_create_group();
    virtual void command_add_to_group();
    virtual void command_remove_from_group();
    virtual void command_destroy_group();
    virtual void command_resign();
    virtual void command_add_waypoint();
    virtual void addObject();
    virtual void removeObject();
    virtual void logMessage();
    virtual void notify(int, int, int, long, long, long);

    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    unsigned short id;
    char gap_4C[4];
    float* attributes;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game(); virtual void draw(); virtual void shadow_draw();
    virtual void normal_draw(); virtual void draw_front_frame(); virtual void draw_back_frame();
    virtual void draw_frame(); virtual unsigned char update(); virtual void check_damage_sprites();
    virtual void rehook(); virtual void save(int); virtual float teleport(float, float, float);
    virtual void new_sprite(void*); virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*); virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char); virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char); virtual void transform(void*);
    virtual void copy_obj(void*); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die(); virtual void damage();
    virtual float calculateDamage(); virtual void rotate(long); virtual unsigned char can_attack();
    virtual void set_attribute(short, float); virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*); virtual void play_command_sound();
    virtual void play_move_sound(); virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(); virtual void set_being_worked_on();
    virtual void release_being_worked_on(RGE_Static_Object*); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj(); virtual int explore_terrain(); virtual void unexplore_terrain();
    virtual void* get_los_table(); virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(); virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*); virtual float getSpeed();
    virtual float getAngle(); virtual float maximumSpeed(); virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*); virtual float damageCapability();
    virtual float weaponRange(); virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int); virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID(); virtual float currentTargetX(); virtual float currentTargetY();
    virtual float currentTargetZ(); virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
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
    virtual int stopAction();
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int pause();

    long id;
    union {
        RGE_Master_Static_Object* master_obj;
        RGE_Master_Static_Object* master;
        char* field_08;
    };
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    char gap_1C[0x1C];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char pad_end;

    void removeAllFromPathingGroup();
    void addToPathingGroup(int);
    UnitAIModule* unitAI();
    int commanderAddToGroup(int, int);
    int commanderRemoveFromGroup(int);
    int commanderCreateGroup(int*, int, int, float);
    int commanderDestroyGroup(int);
    int commanderDestroyGroup();
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x10];
    int player_num;
    RGE_Player** players;
    char gap_44[0x34];
    RGE_Player* curr_player;
    int world_time;

    RGE_Static_Object* object(int);
};

class TCommunications_Handler {
public:
    void* get_command();
    void* new_command(int);
    void* new_command(int, int);
    void new_command(void*, long);
};

class TDebuggingLog {
public:
    void __cdecl Log(char*, ...);
};

class RGE_Base_Game {
public:
    virtual void set_prog_mode(); virtual void get_view_panel();
    virtual void get_map_panel(); virtual void processCheatCode();
    virtual void handle_message(); virtual void action_update();
    virtual void action_mouse_move(); virtual void action_key_down();
    virtual void action_user_command(); virtual void action_command();
    virtual void action_music_done(); virtual void action_activate();
    virtual void action_deactivate(); virtual void action_init_menu();
    virtual void action_exit_menu(); virtual void action_size();
    virtual void notification(int, long, long, long, long);
    char gap_44[0xA15 - 0x44];
    unsigned char resigned[16];
    int multiplayerGame();
    int playerID(int);
};

class RGE_Command {
// PDB access and declaration order select the shipped decorated symbols and vtable slots.
protected:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute*);

public:
    virtual ~RGE_Command();
    virtual void do_command(void*);
    virtual void command_give_attribute(int, int, int, float);

    union {
        RGE_Game_World* world;
        void* field_04;
    };
    union {
        unsigned char* last_order;
        void* field_08;
    };
    long last_order_size;
    long last_order_time;
    union {
        TCommunications_Handler* com_hand;
        int field_14;
    };

    RGE_Command(RGE_Game_World*, TCommunications_Handler*);
    void reset_communications(TCommunications_Handler*);

    void do_commands();

protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint*);
    void do_command_add_attribute(RGE_Command_Add_Attribute*);
    void do_command_formation(RGE_Command_Formation*);
    void do_command_ai_order(RGE_Command_AI_Order*);
    void do_command_group_ai_order(RGE_Command_Group_AI_Order*);
    void do_command_create(RGE_Command_Create*);
    void do_command_create_group(RGE_Command_Create_Group*);
    void do_command_pause(RGE_Command_Pause*);
    void do_command_add_waypoint(RGE_Command_Add_Waypoint*);
    void do_command_work(RGE_Command_Order*);
    void do_command_move(RGE_Command_Order*);
    void do_command_order(RGE_Command_Order*);
    void do_command_stop(RGE_Command_Stop*);
    void do_command_resign(RGE_Command_Resign*);
    void do_command_destroy_group(RGE_Command_Destroy_Group*);
    void do_command_remove_from_group(RGE_Command_Remove_From_Group*);
    void do_command_add_to_group(RGE_Command_Add_To_Group*);
    unsigned char duplicate_check_command_order(RGE_Command_Order*);
    unsigned char duplicate_check_command_stop(RGE_Command_Stop*);
    unsigned char close_check_for_duplicate_orders(unsigned char*);
    unsigned char check_for_duplicate_orders(unsigned char*, long);
    void submit(void*, long);

public:
    void command_order(RGE_Static_Object**, short, RGE_Static_Object*, float, float);
    void command_stop(RGE_Static_Object**, short);
    void command_stop(int, int*, int);
    void command_pause(int, int*, int);
    void command_work(RGE_Static_Object**, short, RGE_Static_Object*, float, float);
    void command_work(int, int*, int, int, int, float, float);
    void command_move(RGE_Static_Object**, short, RGE_Static_Object*, float, float);
    void command_move(int, int*, int, int, int, float, float);
    void command_create(short, short, float, float, float);
    void command_add_attribute(int, int, float);
    void command_formation(RGE_Static_Object**, int, int);
    void command_create_group(int, int, int*, int, float);
    void command_add_to_group(int, int, int, float);
    void command_add_to_group(int, int, int, int);
    void command_remove_from_group(int, int, int);
    void command_destroy_group(int, int);
    void command_ai_order(int, int, int, int, int, int, float, float, float, float,
                          unsigned char, unsigned char, unsigned char);
    void command_group_ai_order(int, int, RGE_Static_Object**, short, int, int, int,
                                float, float, float, float, unsigned char, unsigned char, unsigned char);
    void command_resign(int, int, int);
    void command_add_waypoint(int, int, unsigned char, unsigned char, unsigned char);
    void command_add_waypoint(int, int, XYZBYTEPoint*, int);
    void command_group_waypoint(RGE_Static_Object**, short, unsigned char, unsigned char);
};

extern RGE_Base_Game* rge_base_game;
extern TDebuggingLog* L;
extern double DAT_0056f4d8;
extern double DAT_0056f4e0;
extern double DAT_0056f4e8;
extern void __cdecl operator delete(void*);
extern "C" void __cdecl free(void*);
extern unsigned long debug_timeGetTime(const char*, int);

#endif
