// Shared declarations for the sparse canonical stat_obj.cpp translation unit.
#ifndef STAT_OBJ_CONTEXT_H
#define STAT_OBJ_CONTEXT_H

#include <math.h>
#include <stdlib.h>

typedef unsigned char uchar;

extern float DAT_00574720;
extern double DAT_00574718;
extern float DAT_00574748;
extern float DAT_0057474c;
extern float DAT_00574774;

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Tile;
class RGE_Object_List;
struct RGE_Object_Node;
class RGE_Check_List;
class RGE_Check_Node;
class RGE_Action_Object;
class RGE_Active_Sprite_Node;
class RGE_Color_Table;
class UnitAIModule;
class TPanel;
typedef TPanel RGE_Panel;

extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void*, void*);
__declspec(dllimport) void* __stdcall GetStockObject(int);
__declspec(dllimport) void* __stdcall SelectObject(void*, void*);
__declspec(dllimport) int __stdcall MoveToEx(void*, int, int, void*);
__declspec(dllimport) int __stdcall LineTo(void*, int, int);
}

extern int startLoggingAI;

class TDrawArea {
public:
    void* DrawSystem;                   // +0x00
    void* Wnd;                          // +0x04
    unsigned char* Bits;                // +0x08
    unsigned char gap_0c[0x2C];         // +0x0C
    void* DrawDc;                       // +0x38
    void* DrawSurface;                  // +0x3C

    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void* GetDc(char*);
    void ReleaseDc(char*);
    void FillRect(long, long, long, long, unsigned char);
};

class TPanel {
public:
    virtual ~TPanel();
    unsigned char gap_04[0x84];
    void* clip_rgn;                     // +0x88
};

struct ScreenPoint {
    short y;
    short x;
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
    virtual TPanel* get_view_panel();

    unsigned char gap_04[0x4C];
    unsigned char outline_type;         // +0x50
    unsigned char gap_51[0x15F];
    int prog_mode;                      // +0x1B0
    int game_mode;                      // +0x1B4
};

class VDraw {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void front(void*, short, short);
};

extern RGE_Base_Game* rge_base_game;
extern long SDI_Object_ID;
extern int SDI_Draw_Line;
extern int SDI_Capture_Info;

struct RGE_Armor_Weapon_Info {
    unsigned char gap_00[2];
    short value;
};

class RGE_Sprite {
public:
    unsigned char gap_00[0x60];
    short facet_num;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[2];
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[1];
    short hp;
    float los;                         // +0x28
    unsigned char gap_2c[4];
    float radius_x;                     // +0x30
    float radius_y;                     // +0x34
    float radius_z;                     // +0x38
    void* selected_sound;               // +0x3C
    void* created_sound;                // +0x40
    void* death_sound;                  // +0x44
    short death_spawn_obj_id;           // +0x48
    unsigned char sort_number;          // +0x4A
    unsigned char can_be_built_on;      // +0x4B
    short button_pict;                  // +0x4C
    unsigned char hide_in_scenario_editor; // +0x4E
    unsigned char gap_4f;               // +0x4F
    short portrait_pict;                // +0x50
    unsigned char available;            // +0x52
    unsigned char gap_53;               // +0x53
    short tile_req1;                    // +0x54
    short tile_req2;                    // +0x56
    short center_tile_req1;             // +0x58
    short center_tile_req2;             // +0x5A
    float construction_radius_x;       // +0x5C
    float construction_radius_y;       // +0x60
    unsigned char elevation_flag;       // +0x64
    unsigned char fog_flag;             // +0x65
    short terrain;                      // +0x66
    unsigned char movement_type;        // +0x68
    unsigned char gap_69;               // +0x69
    short attribute_type_held[3];       // +0x6A
    float attribute_amount_held[3];     // +0x70
    short attribute_max_amount;         // +0x7C
    unsigned char gap_7e[2];            // +0x7E
    float attribute_rot;                // +0x80
    float multiple_attribute_mod;       // +0x84
    unsigned char attribute_flag[3];    // +0x88
    unsigned char gap_8b[0x19];         // +0x8B
    unsigned char recyclable;            // +0xA4
    unsigned char gap_a5[3];             // +0xA5
    unsigned char draw_flag;             // +0xA8
    unsigned char gap_a9[3];             // +0xA9
    float outline_radius_x;              // +0xAC
    float outline_radius_y;              // +0xB0
    float outline_radius_z;              // +0xB4
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;                          // +0x04
    long map_width;                     // +0x08
    long map_height;                    // +0x0C
    unsigned char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;          // +0x8D8C
    void get_point(short*, short*, float, float, float, short, short);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned char gap_04[0x24];
    RGE_Map* map;                       // +0x28
    unsigned char gap_2c[0x50];
    short curr_player;                  // +0x7C
    int get_next_reusable_object_id();
    int get_next_object_id();
};

class RGE_Player {
public:
#define STAT_OBJ_PLAYER_PAD(n) virtual void player_pad_##n();
    STAT_OBJ_PLAYER_PAD(0)  STAT_OBJ_PLAYER_PAD(1)  STAT_OBJ_PLAYER_PAD(2)
    STAT_OBJ_PLAYER_PAD(3)  STAT_OBJ_PLAYER_PAD(4)  STAT_OBJ_PLAYER_PAD(5)
    STAT_OBJ_PLAYER_PAD(6)  STAT_OBJ_PLAYER_PAD(7)  STAT_OBJ_PLAYER_PAD(8)
    STAT_OBJ_PLAYER_PAD(9)  STAT_OBJ_PLAYER_PAD(10) STAT_OBJ_PLAYER_PAD(11)
    STAT_OBJ_PLAYER_PAD(12) STAT_OBJ_PLAYER_PAD(13) STAT_OBJ_PLAYER_PAD(14)
    STAT_OBJ_PLAYER_PAD(15) STAT_OBJ_PLAYER_PAD(16) STAT_OBJ_PLAYER_PAD(17)
    STAT_OBJ_PLAYER_PAD(18) STAT_OBJ_PLAYER_PAD(19) STAT_OBJ_PLAYER_PAD(20)
    STAT_OBJ_PLAYER_PAD(21) STAT_OBJ_PLAYER_PAD(22) STAT_OBJ_PLAYER_PAD(23)
    STAT_OBJ_PLAYER_PAD(24) STAT_OBJ_PLAYER_PAD(25) STAT_OBJ_PLAYER_PAD(26)
    STAT_OBJ_PLAYER_PAD(27) STAT_OBJ_PLAYER_PAD(28) STAT_OBJ_PLAYER_PAD(29)
    virtual void vf78(short, int, int);
    virtual void change_attribute(short, float, int);
    STAT_OBJ_PLAYER_PAD(32)
    STAT_OBJ_PLAYER_PAD(33) STAT_OBJ_PLAYER_PAD(34) STAT_OBJ_PLAYER_PAD(35)
    STAT_OBJ_PLAYER_PAD(36) STAT_OBJ_PLAYER_PAD(37) STAT_OBJ_PLAYER_PAD(38)
    STAT_OBJ_PLAYER_PAD(39) STAT_OBJ_PLAYER_PAD(40) STAT_OBJ_PLAYER_PAD(41)
    STAT_OBJ_PLAYER_PAD(42) STAT_OBJ_PLAYER_PAD(43) STAT_OBJ_PLAYER_PAD(44)
    STAT_OBJ_PLAYER_PAD(45) STAT_OBJ_PLAYER_PAD(46) STAT_OBJ_PLAYER_PAD(47)
    STAT_OBJ_PLAYER_PAD(48) STAT_OBJ_PLAYER_PAD(49) STAT_OBJ_PLAYER_PAD(50)
    STAT_OBJ_PLAYER_PAD(51) STAT_OBJ_PLAYER_PAD(52) STAT_OBJ_PLAYER_PAD(53)
    STAT_OBJ_PLAYER_PAD(54)
#undef STAT_OBJ_PLAYER_PAD
    unsigned char gap_04[0x38];
    RGE_Game_World* world;              // +0x3C
    unsigned char gap_40[0xC8];
    RGE_Color_Table* color_table;       // +0x108
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
};

class RGE_Active_Sprite_List {
public:
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;
    RGE_Active_Sprite_List(RGE_Static_Object*);
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite*);
    virtual void update(float, float);
    virtual void draw(short, short, short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void normal_draw(short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void shadow_draw(short, short, short, RGE_Color_Table*, TDrawArea*, unsigned char);
    virtual unsigned char is_animating(RGE_Sprite*);
    virtual void set_frame(RGE_Sprite*, short);
    virtual unsigned char frame_passed(RGE_Sprite*, short);
    virtual unsigned char looped(RGE_Sprite*);
    virtual short get_facetindex(RGE_Sprite*, short);
    virtual unsigned char load_node(int, unsigned char, RGE_Sprite**);
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char gap_0D[3];
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_List();
    RGE_Object_Node* list;              // +0x04 or +0x10 in a tile
    short number_of_objects;
    unsigned char gap_0A[2];
    operator RGE_Object_Node*() { return this->list; }
};

class RGE_Tile {
public:
    unsigned char gap_00[0x0C];
    RGE_Object_List objects;            // list at +0x10
};

struct RGE_Check_Node {
    RGE_Static_Object* node;
    float dx;
    float dy;
    unsigned char flag;
    unsigned char gap_0D[3];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;
    RGE_Check_List();
    ~RGE_Check_List();
    void add_node(RGE_Static_Object*, float, float, unsigned char);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    void draw_frame_3d_cube_front(TDrawArea*, short, short);
    void draw_frame_3d_square_front(TDrawArea*, short, short);
    void draw_frame_3d_cube_back(void*, short, short);
    void draw_frame_3d_cube_back(TDrawArea*, short, short);
    void draw_frame_3d_square_back(void*, short, short);
    void draw_frame_3d_square_back(TDrawArea*, short, short);
    void capture_frame_3d_cube(TDrawArea*, short, short);
    void capture_frame_3d_square(TDrawArea*, short, short);
    void capture_square_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(int);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned int);
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
    void give_attribute_to_owner();
    void take_attribute_from_owner();
    void get_starting_attribute();
protected:
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
public:
    void change_unique_id();
    int inRange(RGE_Static_Object*, float);
    float distance_to_object(RGE_Static_Object*);
    RGE_Check_List* make_object_bounds_list(float);
    int objectCollisionList(float);
    RGE_Static_Object* check_object_bounds();

    long id;                            // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                  // +0x0C
    RGE_Sprite* sprite;                 // +0x10
    RGE_Sprite* old_sprite;             // +0x14
    RGE_Active_Sprite_List* sprite_list; // +0x18
    RGE_Tile* tile;                     // +0x1C
    RGE_Static_Object* inside_obj;      // +0x20
    RGE_Object_List* objects;           // +0x24
    short screen_x_offset;              // +0x28
    short screen_y_offset;              // +0x2A
    short shadow_x_offset;              // +0x2C
    short shadow_y_offset;              // +0x2E
    float hp;                           // +0x30
    unsigned char curr_damage_percent;  // +0x34
    unsigned char facet;                // +0x35
    unsigned char selected;             // +0x36
    unsigned char selected_group;       // +0x37
    float world_x;                      // +0x38
    float world_y;                      // +0x3C
    float world_z;                      // +0x40
    float attribute_amount_held;        // +0x44
    unsigned char object_state;         // +0x48
    unsigned char sleep_flag;           // +0x49
    unsigned char dopple_flag;          // +0x4A
    unsigned char goto_sleep_flag;      // +0x4B
    short attribute_type_held;          // +0x4C
    unsigned char type;                 // +0x4E
    unsigned char worker_num;           // +0x4F
    RGE_Object_Node* player_object_node; // +0x50
    unsigned char gap_54[0x20];         // +0x54
    UnitAIModule* unitAIValue;          // +0x74
    int groupCommanderValue;            // +0x78
    int zoneMapIndex;                   // +0x7C
    float groupRangeValue;              // +0x80
    unsigned char inObstructionMapValue; // +0x84
    unsigned char lastInObstructionMapValue; // +0x85
    unsigned char underAttackValue;     // +0x86
    unsigned char gap_87;               // +0x87

    void set_sleep_flag(unsigned char);
    void capture_frame(TDrawArea*, short, short);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    float speed;
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
};

#endif
