// Shared declarations for the sparse canonical stat_obj.cpp translation unit.
#ifndef STAT_OBJ_CONTEXT_H
#define STAT_OBJ_CONTEXT_H

#include <math.h>
#include <stdlib.h>

#include "infmap.h"

typedef unsigned char uchar;

#ifndef ZERO_F
#define ZERO_F 0.0f
#define ONE_F 1.0f
#define TILE_EPSILON 0.001f
#define SCREEN_BIAS 0.0f
#endif

extern float DAT_00574720;
extern float DAT_00574724;
extern float DAT_00574728;
extern double DAT_00574718;
extern float DAT_00574748;
extern float DAT_0057474c;
extern float DAT_00574774;

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Sprite;
class RGE_Visible_Map;
struct LOSTBL;
class RGE_Zone_Map {
public:
    unsigned char get_zone_info(int, int);
    int withinRange(unsigned char, int, int, float);
    int findClosestPointInTerrainType(XYPoint, XYPoint*);
    int findClosestPointInTerrainType(XYPoint, XYPoint*, int, int, int);
};
class RGE_Zone_Map_List {
public:
    RGE_Zone_Map* get_zone_map_by_terrain(void*, int, int*);
    RGE_Zone_Map* get_zone_map_by_index(int);
    RGE_Zone_Map* get_zone_map(long);
    RGE_Zone_Map* get_zone_map(int, int, int*);
    RGE_Zone_Map* get_zone_map(void*, int, int*);
};
class RGE_Tile;
class RGE_Object_List;
struct RGE_Object_Node;
class RGE_Check_List;
class RGE_Check_Node;
class RGE_Action_Object;
class RGE_Active_Sprite_Node;
class RGE_Color_Table;
class UnitAIModule;
class RGE_Victory_Conditions;
class RGE_Sound;
class Visible_Resource_Manager;
class RGE_Doppleganger_Creator;
class PathingSystem;
class TPanel;
struct XYZBYTEPoint;
struct _iobuf;
typedef TPanel RGE_Panel;

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    ManagedArrayInt() : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedArrayInt();
    int& operator[](int index) { return this->value[index]; }
    operator int*() const { return this->value; }
    ManagedArrayInt& operator=(int* pointer) { this->value = pointer; return *this; }
};
typedef ManagedArrayInt ManagedArray_int;

struct Inner_004C4C40 {
    void target(RGE_Sprite*);
};

class RGE_Victory_Conditions {
public:
    void update_for_object(void*);
};

class RGE_Sound {
public:
    void play(int);
};

class Visible_Resource_Manager {
public:
    int Remove_Resource(int, int);
};

class RGE_Doppleganger_Creator {
public:
    int remove_doppleganger_check(RGE_Static_Object*);
    int add_doppleganger_check(RGE_Static_Object*);
    int add_doppleganger_check(RGE_Static_Object*, void*);
};

class UnitAIModule {
public:
    void setPlayStatus(int);
    int playStatus;
};

class PathingSystem {
public:
    void incrementObstruction(int, int);
    void decrementObstruction(int, int);
};
extern PathingSystem pathSystem;
extern PathingSystem aiPathSystem;

extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void*, void*);
__declspec(dllimport) void* __stdcall GetStockObject(int);
__declspec(dllimport) void* __stdcall SelectObject(void*, void*);
}

extern int startLoggingAI;
extern int debug_random_on;
extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl debug_srand(char*, int, int);
extern void __cdecl operator_delete(void*);
struct DamageSpriteInfo {
    unsigned char damage_percent;
    unsigned char flag;
    unsigned char gap_02[2];
    RGE_Sprite* sprite;
};

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
    void DrawRect(long, long, long, long, unsigned char);
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

class Shape_Info {
public:
    unsigned char gap_00[0x10];
    int width;
    int height;
    int hotspot_x;
    int hotspot_y;
};

class TShape {
public:
    unsigned char gap_00[0x18];
    Shape_Info* FShape;
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
    int display_selected_ids;
    TShape* get_shape(int);
};

class VDraw {
public:
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void front(void*, short, short);
};

extern RGE_Base_Game* rge_base_game;
extern long SDI_Object_ID;
class DClipInfo_List {
public:
    void AddGDINode(int, int, short, short, short, short, short, short,
                    short, short, int, int, int);
    void AddDrawNode(void*, Shape_Info*, int, int, int, int,
                     unsigned char*, int, int, int);
};
extern DClipInfo_List* SDI_List;
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
    int id;
    int nFacets;
    unsigned char hit_test(short, short, long, long);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, RGE_Game_World*, unsigned char);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int,
                      unsigned char);
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[1];
    short hp;
    float los;                         // +0x28
    unsigned char gap_2c[4];
    float radius_x;                     // +0x30
    float radius_y;                     // +0x34
    float radius_z;                     // +0x38
    RGE_Sound* selected_sound;          // +0x3C
    RGE_Sound* created_sound;           // +0x40
    RGE_Sound* death_sound;             // +0x44
    short death_spawn_obj_id;           // +0x48
    short obj_max;
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
    unsigned char draw_color;
    float decay;
    int damage_sprite_num;
    DamageSpriteInfo* damage_sprites;
    float size_x;
    float size_y;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Static_Object {
public:
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float,
                                             RGE_Static_Object*);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;                          // +0x04
    long map_width;                     // +0x08
    long map_height;                    // +0x0C
    float screen_x_scale;
    float screen_y_scale;
    unsigned char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;          // +0x8D8C
    RGE_Zone_Map_List* map_zones;
    void get_point(short*, short*, float, float, float, short, short);
    void request_redraw(int, int, int, int);
    void request_redraw(int, int, int, int, int);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned char gap_04[0x24];
    RGE_Map* map;                       // +0x28
    long world_time;
    unsigned char gap_2c[0x50];
    short curr_player;                  // +0x7C
    short player_num;
    short terrain_num;
    short terrain_size;
    RGE_Sprite** sprites;
    short sprite_num;
    RGE_Player** players;
    float** terrains;
    float attr_rate;
    void add_object(RGE_Static_Object*);
    RGE_Static_Object* object(int);
    unsigned char recycle_object_out_of_game(unsigned char, RGE_Static_Object*);
    int get_next_reusable_object_id();
    int get_next_object_id();
};

class RGE_Visible_Map {
public:
    LOSTBL* get_los_table(int, int);
    int explore_terrain(int, int, int, int, int, int);
    int explore_terrain_sq(int, int, int, int, int, int);
    int unexplore_terrain(int, int, int, int, int, int);
    int unexplore_terrain_sq(int, int, int, int, int, int);
    LOSTBL* get_los_table();
};

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
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
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  unsigned char, float);
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
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
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
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(struct _iobuf*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    unsigned char gap_04[0x38];
    RGE_Game_World* world;              // +0x3C
    unsigned char gap_40[0xC8];
    RGE_Color_Table* color_table;       // +0x108
    RGE_Victory_Conditions* victory_conditions;
    short id;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    void unselect_one_object(void*);
    int computerPlayer();
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Doppleganger_Creator* doppleganger_creator;
    Visible_Resource_Manager* VR_List;
    RGE_Visible_Map* visible;
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
    void load(int, RGE_Sprite**);
    void add_sprite(RGE_Sprite*, int, int, int);
    void remove_sprite(RGE_Sprite*);
    void delete_list();
    void save(int);
    unsigned char get_frame(short*, short*, short*, short*, RGE_Sprite*, long);
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Static_Object* object;
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
    RGE_Object_Node* head;
    RGE_Object_Node* first;
    short number_of_objects;
    short obj_max;
    unsigned char gap_0A[2];
    operator RGE_Object_Node*() { return this->list; }
    void remove_node(void*, RGE_Object_Node*);
    RGE_Object_Node* add_node(RGE_Static_Object*);
    RGE_Static_Object* find_by_id(int);
};

class RGE_Tile {
public:
    unsigned char gap_00[0x0C];
    short tile_type;
    short tile_level;
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
    RGE_Static_Object(RGE_Master_Static_Object*, RGE_Player*, float, float, float, int);
    RGE_Static_Object(int, RGE_Game_World*, int);
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
    void draw_frame_3d_cube_back_case(TDrawArea*, short, short);
    void draw_frame_3d_square_back(void*, short, short);
    void draw_frame_3d_square_back(TDrawArea*, short, short);
    void capture_frame_3d_cube(TDrawArea*, short, short);
    void capture_frame_3d_square(TDrawArea*, short, short);
    void capture_square_frame(TDrawArea*, short, short);
    int get_frame(short&, short&, short&, short&);
    int get_frame(short*, short*, short*, short*);
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
    unsigned char is_dying();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack() const;
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
    virtual void __cdecl logDebug(char*, ...);
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
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int,
                                        void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int,
                                                 int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath(void*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();
    void release_from_holder();
    unsigned char more_room();
    float distance_to_position(float, float, float);
    unsigned char hit_test(short, short, short, short, short);
    unsigned char box_hit_test(short, short, short, short, short, short);
    void set_location(float, float, float);
    int isGroupCommander();
    int inGroup();
    int unitIsInGroup(int);
    int createGroup(int*, int, int, float);
    int commanderCreateGroup(int*, int, int, float);
    int addToGroup(int, float);
    int commanderAddToGroup(int, float);
    int removeFromGroup(int);
    int commanderRemoveFromGroup(int);
    int destroyGroup();
    int commanderDestroyGroup();
    void addToPathingGroup(int);
    void removeAllFromPathingGroup();
    void remove_shadows();
    int boundToFacet(float, float, int);
    int numberFacets();
    unsigned char lookupZone(XYPoint);
    unsigned char lookupZone(int, int);
    unsigned char currentZone();
    int withinRangeOfZoneAtPoint(unsigned char, float, XYPoint&);
    int withinRangeOfZone(unsigned char, float);
    int findClosestPointInTerrainType(XYPoint, XYPoint&, int, int, int);
    void changeInfluenceMap(InfluenceMap*, int, int, int);
    int removeFromObstructionMap(int);
    int addToObstructionMap(int);
    float get_terrain_speed(unsigned char);
    void notify(RGE_Player*);
    void notify(long, long, int, int, int, int);
    void setDamage(float);
    void setHealth(float);
    void setDamage(RGE_Player*, int, int);
    void setHealth(RGE_Player*, int, int);
    UnitAIModule* unitAI();
    void tileOp0(void*, int, int);
    void tileOp1(void*, int, int);
    void setSprite(void*);
    void update(int);
    RGE_Sprite* get_sprite_pointer(short);
    void give_attribute_to_owner();
    void take_attribute_from_owner();
    void get_starting_attribute();
public:
    void change_unique_id();
    int inRange(RGE_Static_Object*, float);
    float distance_to_object(RGE_Static_Object*);
    RGE_Check_List* make_object_bounds_list(float);
    RGE_Check_List* objectCollisionList(float);
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
    ManagedArrayInt pathingGroupMembers; // +0x54
    ManagedArrayInt groupMembers;        // +0x64
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
    RGE_Static_Object* get_object_pointer(long);
    unsigned char drop_held_objects(int);
    unsigned char find_drop_location(int, float&, float&, RGE_Master_Static_Object*,
                                     RGE_Static_Object*, float, float, float, float);
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
