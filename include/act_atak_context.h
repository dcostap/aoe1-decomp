#ifndef ACT_ATAK_CONTEXT_H
#define ACT_ATAK_CONTEXT_H

#include <math.h>

typedef unsigned char uchar;

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Active_Sprite_List;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class RGE_Damage_Sprite_Info;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Combat_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Task_List;
class RGE_Tile;
class RGE_Visible_Map;
class TDrawArea;
class UnitAIModule;
class LOSTBL;

void rge_read(int handle, void* buffer, int count);
void rge_write(int handle, void* buffer, int count);
extern float DAT_0056e0cc;

class Waypoint {
public:
    float x;
    float y;
    float z;
    uchar facetToNextWaypoint;
    uchar pad_0D[3];
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};

class XYPoint {
public:
    int x;
    int y;
};

class XYZBYTEPoint {
public:
    uchar x;
    uchar y;
    uchar z;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Sprite {
public:
    char gap_00[0x5E];
    short frame;                    // +0x5E
    char gap_60[0x10];
    uchar flags;                    // +0x70
    char gap_71;
    short id;                       // +0x72
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    uchar master_type;             // +0x04
    uchar pad_05[3];
    char* name;                     // +0x08
    short string_id;                // +0x0C
    short string_id2;               // +0x0E
    short id;                       // +0x10
    short copy_id;                  // +0x12
    short object_group;             // +0x14
    uchar pad_16[2];
    RGE_Sprite* sprite;             // +0x18
    RGE_Sprite* death_sprite;       // +0x1C
    RGE_Sprite* undead_sprite;      // +0x20
    uchar undead_flag;              // +0x24
    uchar pad_25;
    short hp;                       // +0x26
    float los;                      // +0x28
    uchar obj_max;                  // +0x2C
    uchar pad_2D[3];
    float radius_x;                 // +0x30
    float radius_y;                 // +0x34
    float radius_z;                 // +0x38
    RGE_Sound* selected_sound;      // +0x3C
    RGE_Sound* created_sound;       // +0x40
    RGE_Sound* death_sound;         // +0x44
    short death_spawn_obj_id;       // +0x48
    uchar sort_number;              // +0x4A
    uchar can_be_built_on;          // +0x4B
    short button_pict;              // +0x4C
    uchar hide_in_scenario_editor;  // +0x4E
    uchar pad_4F;
    short portrait_pict;            // +0x50
    uchar available;                // +0x52
    uchar pad_53;
    short tile_req1;                // +0x54
    short tile_req2;                // +0x56
    short center_tile_req1;         // +0x58
    short center_tile_req2;         // +0x5A
    float construction_radius_x;    // +0x5C
    float construction_radius_y;    // +0x60
    uchar elevation_flag;           // +0x64
    uchar fog_flag;                 // +0x65
    short terrain;                  // +0x66
    uchar movement_type;            // +0x68
    uchar pad_69;
    short attribute_type_held[3];   // +0x6A
    float attribute_amount_held[3]; // +0x70
    short attribute_max_amount;     // +0x7C
    uchar pad_7E[2];
    float attribute_rot;            // +0x80
    float multiple_attribute_mod;   // +0x84
    uchar attribute_flag[3];        // +0x88
    uchar area_effect_object_level; // +0x8B
    uchar combat_level;             // +0x8C
    uchar select_level;             // +0x8D
    uchar map_draw_level;           // +0x8E
    uchar unit_level;               // +0x8F
    uchar map_color;                // +0x90
    uchar attack_reaction;          // +0x91
    uchar convert_terrain_flag;     // +0x92
    uchar damage_sprite_num;        // +0x93
    RGE_Damage_Sprite_Info* damage_sprites; // +0x94
    long help_string_id;            // +0x98
    long help_page_id;              // +0x9C
    long hotkey_id;                 // +0xA0
    uchar recyclable;               // +0xA4
    uchar track_as_resource;        // +0xA5
    uchar create_doppleganger_on_death; // +0xA6
    uchar resource_group;           // +0xA7
    uchar draw_flag;                // +0xA8
    uchar draw_color;               // +0xA9
    uchar pad_AA[2];
    float outline_radius_x;         // +0xAC
    float outline_radius_y;         // +0xB0
    float outline_radius_z;         // +0xB4
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                    // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;        // +0xBC
    RGE_Sprite* run_sprite;         // +0xC0
    float turn_speed;               // +0xC4
    uchar size_class;               // +0xC8
    uchar pad_C9;
    short obj_trail_id;             // +0xCA
    uchar obj_trail_options;        // +0xCC
    uchar pad_CD[3];
    float obj_trail_spacing;        // +0xD0
    uchar move_algorithem;          // +0xD4
    uchar pad_D5[3];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;           // +0xD8
    short default_task;             // +0xDC
    uchar pad_DE[2];
    float search_radius;            // +0xE0
    float work_rate;                // +0xE4
    short drop_site;                // +0xE8
    short backup_drop_site;         // +0xEA
    uchar task_by_group;            // +0xEC
    uchar pad_ED[3];
    RGE_Sound* command_sound;       // +0xF0
    RGE_Sound* move_sound;          // +0xF4
    uchar run_pattern;              // +0xF8
    uchar pad_F9[3];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;       // +0xFC
    uchar base_armor;               // +0x100
    uchar pad_101;
    short armor_num;                // +0x102
    RGE_Armor_Weapon_Info* armor;   // +0x104
    short weapon_num;               // +0x108
    uchar pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;  // +0x10C
    short defense_terrain_bonus;    // +0x110
    uchar pad_112[2];
    float weapon_range;             // +0x114
    float area_effect_range;        // +0x118
    uchar area_effect_level;        // +0x11C
    uchar pad_11D[3];
    float speed_of_attack;          // +0x120
    short missile_id;               // +0x124
    short base_hit_chance;          // +0x126
    uchar break_off_combat;         // +0x128
    uchar pad_129;
    short fire_missile_at_frame;    // +0x12A
    float weapon_offset_x;          // +0x12C
    float weapon_offset_y;          // +0x130
    float weapon_offset_z;          // +0x134
    float minimum_weapon_range;     // +0x138
    short orig_armor;               // +0x13C
    short orig_weapon;              // +0x13E
    float orig_weapon_range;        // +0x140
    float orig_speed_of_attack;     // +0x144
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
    virtual uchar can_attack();                    // +0x7C
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
    virtual float maximumSpeed();                   // +0xFC
    virtual void vpad100();
    virtual void vpad104();
    virtual void vpad108();
    virtual void vpad10C();
    virtual void vpad110();
    virtual void vpad114();
    virtual void vpad118();
    virtual void vpad11C();
    virtual void vpad120();
    virtual void vpad124();
    virtual void vpad128();
    virtual void vpad12C();
    virtual void vpad130();
    virtual void vpad134();
    virtual void vpad138();
    virtual void vpad13C();
    virtual void vpad140();
    virtual void vpad144();
    virtual void notify(int, int, int, long, long, long); // +0x148
    virtual void vpad14C();
    virtual void vpad150();
    virtual void vpad154();
    virtual void vpad158();
    virtual void vpad15C();
    virtual void vpad160();
    virtual void vpad164();
    virtual void vpad168();
    virtual void vpad16C();
    virtual void vpad170();
    virtual void vpad174();
    virtual void vpad178();
    virtual void vpad17C();
    virtual void vpad180();
    virtual void vpad184();
    virtual void vpad188();
    virtual void vpad18C();
    virtual void vpad190();
    virtual void vpad194();
    virtual void vpad198();
    virtual void vpad19C();
    virtual void vpad1A0();
    virtual void vpad1A4();
    virtual void vpad1A8();
    virtual void vpad1AC();
    virtual void vpad1B0();
    virtual void vpad1B4();
    virtual void vpad1B8();
    virtual void vpad1BC();
    virtual void vpad1C0();
    virtual void vpad1C4();
    virtual void vpad1C8();
    virtual void vpad1CC();
    virtual void vpad1D0();
    virtual void vpad1D4();
    // VC5 reverses adjacent overload entries in the vtable.
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float); // +0x1DC
    virtual int setup(int, RGE_Game_World*);                         // +0x1D8
    virtual RGE_Object_List* create_object_list();                   // +0x1E0
    virtual RGE_Active_Sprite_List* create_sprite_list();            // +0x1E4

    long id;                        // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;              // +0x0C
    RGE_Sprite* sprite;             // +0x10
    RGE_Sprite* old_sprite;         // +0x14
    RGE_Active_Sprite_List* sprite_list; // +0x18
    RGE_Tile* tile;                 // +0x1C
    RGE_Static_Object* inside_obj;  // +0x20
    RGE_Object_List* objects;       // +0x24
    short screen_x_offset;          // +0x28
    short screen_y_offset;          // +0x2A
    short shadow_x_offset;          // +0x2C
    short shadow_y_offset;          // +0x2E
    float hp;                       // +0x30
    uchar curr_damage_percent;      // +0x34
    uchar facet;                    // +0x35
    uchar selected;                 // +0x36
    uchar selected_group;           // +0x37
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    float attribute_amount_held;    // +0x44
    uchar object_state;             // +0x48
    uchar sleep_flag;               // +0x49
    uchar dopple_flag;              // +0x4A
    uchar goto_sleep_flag;          // +0x4B
    short attribute_type_held;      // +0x4C
    uchar type;                     // +0x4E
    uchar worker_num;               // +0x4F
    RGE_Object_Node* player_object_node; // +0x50
    ManagedArray<int> pathingGroupMembers; // +0x54
    ManagedArray<int> groupMembers; // +0x64
    UnitAIModule* unitAIValue;      // +0x74
    int groupCommanderValue;        // +0x78
    int zoneMapIndex;               // +0x7C
    float groupRangeValue;          // +0x80
    uchar inObstructionMapValue;    // +0x84
    uchar lastInObstructionMapValue; // +0x85
    uchar underAttackValue;         // +0x86
    uchar pad_87;

    RGE_Sprite* get_sprite_pointer(short);
    float distance_to_object(RGE_Static_Object*);
    float distance_to_position(float, float, float);
    UnitAIModule* unitAI();
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float); // +0x1E8
    float speed;                    // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    virtual void stop_moving();                                      // +0x1EC
    virtual uchar turn_towards(RGE_Static_Object*, float, float);    // +0x1F0
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float); // +0x1F4
    float trail_remainder;          // +0x8C
    float velocity_x;               // +0x90
    float velocity_y;               // +0x94
    float velocity_z;               // +0x98
    float angle;                    // +0x9C
    float turn_towards_time;        // +0xA0
    Path pathValue;                 // +0xA4
    Path exceptionPathValue;        // +0xD8
    Waypoint startValue;            // +0x10C
    Waypoint goalValue;             // +0x11C
    float turnTimer;                // +0x12C
    float collisionAvoidanceDistance; // +0x130
    float actionRange;              // +0x134
    int targetIDValue;              // +0x138
    float targetRadiusX;            // +0x13C
    float targetRadiusY;            // +0x140
    int continueCounter;            // +0x144
    int rangeStatusValue;           // +0x148
    int currentTerrainException1;   // +0x14C
    int currentTerrainException2;   // +0x150
    uchar storePathInExceptionPath; // +0x154
    uchar waitingToMoveValue;       // +0x155
    uchar numberWaitDelays;         // +0x156
    uchar pad_157;
    XYPoint minInitialPointValue;    // +0x158
    XYPoint maxInitialPointValue;    // +0x160
    XYZBYTEPoint* userDefinedWaypoints; // +0x168
    int numberUserDefinedWaypointsValue; // +0x16C
    int maxUserDefinedWaypointsValue; // +0x170
    uchar finalUserDefinedWaypoint; // +0x174
    uchar pad_175[3];
    float closestDistanceToWaypoint; // +0x178
    uchar lastFacet;                // +0x17C
    uchar lastFacet2;               // +0x17D
    uchar pad_17E[2];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void work2(RGE_Static_Object*, float, float, float, uchar); // +0x1F8
    virtual void set_task(short);                                    // +0x1FC

    uchar waiting;                   // +0x180
    uchar pad_181[3];
    RGE_Action_List* actions;        // +0x184
    uchar command_flag;              // +0x188
    uchar pad_189[3];
    int lastActionValue;             // +0x18C
    int lastActionStateValue;        // +0x190
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual ~RGE_Combat_Object();
    virtual void vpad200();
    virtual void vpad204();
    virtual void vpad208();
    virtual void vpad20C();
    virtual void vpad210();
    virtual void vpad214();
    virtual void vpad218();
    virtual void vpad21C();
    // VC5 reverses these adjacent overloads in the vtable.
    virtual void attack(RGE_Static_Object*, RGE_Combat_Object*);     // +0x224
    virtual void attack(float, float, float, RGE_Combat_Object*);    // +0x220

    char gap_194[0x30];             // complete size 0x1C4
    void reset_attack_timer();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vpad04();
    virtual void vpad08();
    virtual void vpad0C();
    virtual void vpad10();
    virtual void vpad14();
    virtual void vpad18();
    virtual int isAlly(int);         // +0x1C

    char gap_04[0x34];
    RGE_Visible_Map* visible;        // +0x38
    RGE_Game_World* world;           // +0x3C
    char gap_40[0x08];
    uchar type;                      // +0x48
    uchar pad_49;
    short id;                        // +0x4A
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds; // +0x84

    RGE_Static_Object* object(int);
};

class RGE_Visible_Map {
public:
    uchar get_visible(int, int);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap_04[0x24];
    int currentOrderValue;           // +0x28
    int currentOrder();
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite*);
    virtual void update(float, float);
    virtual void draw(short, short, short, short, short, void*, void*);
    virtual void normal_draw(short, short, short, void*, void*);
    virtual void shadow_draw(short, short, short, void*, void*, uchar);
    virtual uchar is_animating(RGE_Sprite*);
    virtual void set_frame(RGE_Sprite*, short);
    virtual uchar frame_passed(RGE_Sprite*, short); // +0x20
    virtual uchar looped(RGE_Sprite*);              // +0x24
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;        // +0x34
    RGE_Sprite* work_sprite;        // +0x38
    RGE_Sprite* work_sprite2;       // +0x3C
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual uchar inside_obj_update();
    virtual uchar update();

    RGE_Action_Object* obj;         // +0x10
    void* list;                     // +0x14

    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    // VC5 reverses adjacent overload entries in the vtable.
    virtual int setup(int, RGE_Action_Object*);                      // +0x08
    virtual int setup(RGE_Action_Object*);                           // +0x04
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
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj() { return target_obj; }
    virtual RGE_Static_Object* get_target_obj2() { return target_obj2; }
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;              // +0x04
    uchar pad_06[2];
    RGE_Action_Object* obj;         // +0x08
    uchar state;                    // +0x0C
    uchar pad_0D[3];
    RGE_Static_Object* target_obj;  // +0x10
    RGE_Static_Object* target_obj2; // +0x14
    int targetID;                   // +0x18
    int target2ID;                  // +0x1C
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    RGE_Task* task;                 // +0x30
    RGE_Action_List* sub_actions;   // +0x34
    RGE_Sprite* sprite;             // +0x38
    uchar subActionValue;           // +0x3C
    uchar pad_3D[3];

    RGE_Action(RGE_Action_Object*, int);
    RGE_Action(int, RGE_Action_Object*, int);
    void setSubAction(uchar);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(int, RGE_Action_Object*);
    RGE_Action_Attack(RGE_Action_Object*, RGE_Static_Object*, RGE_Sprite*, RGE_Sprite*, RGE_Sprite*, float, float, short, short);
    RGE_Action_Attack(RGE_Action_Object*, float, float, float, RGE_Sprite*, RGE_Sprite*, RGE_Sprite*, float, float, short, short);
    virtual ~RGE_Action_Attack();
    virtual void save(int);
    virtual void first_in_stack(uchar);
    virtual uchar update();
    virtual int stop();
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void set_state(uchar);

    RGE_Sprite* move_sprite;        // +0x40
    RGE_Sprite* fight_sprite;       // +0x44
    RGE_Sprite* wait_sprite;        // +0x48
    float range;                    // +0x4C
    float min_range;                // +0x50
    short missile_id;               // +0x54
    short fire_missile_at_frame;    // +0x56
    uchar need_to_attack;           // +0x58
    uchar was_same_owner;           // +0x59
    uchar indirect_fire_flag;       // +0x5A
    uchar pad_5B;

    int ready_to_attack(int&);
    void do_attack();
};

#endif
