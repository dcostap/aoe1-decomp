#ifndef AOE1_COMMAND_TU_CONTEXT_H
#define AOE1_COMMAND_TU_CONTEXT_H

// Period-shaped declarations for the complete Command.cpp owner sequence.
// The owner files keep their standalone declarations for focused checks.  The
// full wrapper defines COMMAND_TU_CONTEXT before including them so that every
// body sees one compiler-facing class and object surface.

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
    float attr_amount;
};
struct RGE_Command_Add_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char attr_id;
    unsigned char gap_03;
    int attr_amount;
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
class UnitAIModule {
public:
    void setCurrentOrder(int);
    void setCurrentAction(int);
    void setCurrentTarget(int, int, float, float, float);
};

class PlayerLike {
public:
    void ai_order(unsigned int, int, int, int, unsigned int, int, int, int,
                  int, unsigned int, unsigned int, unsigned int);
};

class MasterObject {
public:
    char gap_00[8];
    const char* name;
};
struct RGE_Command_AI_Order {
    unsigned char command;
    unsigned char gap_00;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char gap_03;
    int recipient;
    short orderType;
    union {
        unsigned char flags;
        unsigned char orderPriority;
    };
    unsigned char gap_0B;
    int target;
    unsigned char targetOwner;
    unsigned char gap_11[3];
    union { int targetX; float target_x; };
    union { int targetY; float target_y; };
    union { int targetZ; float target_z; };
    int inFront;
    int range;
    unsigned char immediate;
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
    virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual void create(class RGE_Player*, float, float, float);
    char gap_1C[0x14];
    short object_group;
    short gap_32;
    float radius_x;
    float radius_y;
    char* name;
};

class RGE_Player {
public:
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8();
    virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8();
    virtual void vDC(); virtual void vE0();
    virtual void notify(int, int, int, long, long, long);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, unsigned int, unsigned int, unsigned int);
    virtual void resign(int);
    virtual void send_waypoint(int, unsigned char*, int);

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
    virtual void move_to(RGE_Static_Object*, float, float, float); virtual void work();
    virtual void stop();
    virtual void work(RGE_Static_Object*, float, float, float);
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
    virtual void pause_callback();

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
    void Log(const char*, ...);
};

class RGE_Base_Game {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void notification(int, long, long, long, long);
    char gap_44[0xA15 - 0x44];
    unsigned char resigned[16];
    int multiplayerGame();
    int playerID(int);
};

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute*);
    virtual ~RGE_Command();
    virtual void do_command(void*);
    void command_give_attribute(int, int, int, float);

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
    void reset_communications(int);
    RGE_Static_Object* get_obj(int);
    RGE_Static_Object* get_obj(RGE_Obj_Info);
    void do_commands();
    void do_command_order(void*);
    void do_command_stop(void*);
    void do_command_work(void*);
    void do_command_move(void*);
    void do_command_create(void*);
    void do_command_add_attribute(void*);
    void do_command_formation(void*);
    void do_command_create_group(void*);
    void do_command_destroy_group(void*);
    void do_command_ai_order(void*);
    void do_command_resign(void*);
    void do_command_add_waypoint(void*);
    void do_command_group_waypoint(void*);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint*);
    void do_command_add_to_group(void*);
    void do_command_remove_from_group(void*);
    void do_command_group_ai_order(void*);
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
    void submit(unsigned char*, long);

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
    void command_create_group(int, int, int*, int, int);
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
extern void Log(TDebuggingLog*, const char*, int, int, int);
extern void Log(void*, const char*, int);
extern void Log(void*, const char*, int, const char*);
extern "C" void __cdecl TDebuggingLog_Log(void*, const char*, int, const char*);
extern void __cdecl operator_delete(void*);
extern void* RGE_Command_vftable;

// Existing focused context files use this guard to omit their local class
// declarations when they are part of the complete module sequence.
#ifndef COMMAND_CONTEXT_H
#define COMMAND_CONTEXT_H
#endif

#endif
