#pragma once
#include "../types.h"
#include "RGE_Tile_List.h"
#include "RGE_Object_List.h"

// Forward declarations
class RGE_Game_World;
class RGE_Map;
struct RGE_Master_Static_Object;
struct RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
struct RGE_Color_Table;
class Visible_Resource_Manager;
struct RGE_Static_Object;
struct RGE_Object_Node;
struct XYZBYTEPoint;
struct RGE_Player_Info;
struct _iobuf;

class RGE_Player {
public:
    // ========================================================================
    // Virtual Table (Indices 0-61 per layout.json)
    // ========================================================================
    virtual ~RGE_Player();                                      // 0
    virtual void set_game_status(uchar status);                 // 1
    virtual void do_resign(int param_1);                        // 2
    virtual void changeToHumanPlayer();                        // 3
    virtual void changeToComputerPlayer();                     // 4
    virtual char *aiStatus(int param_1);                        // 5
    virtual int isEnemy(int player_id);                         // 6
    virtual int isAlly(int player_id);                          // 7
    virtual int isNeutral(int player_id);                       // 8
    virtual int isAllNeutral();                                 // 9
    virtual void setDiplomaticStance(int player_id, int stance); // 10
    virtual void loadAIInformation(char *a, char *b, char *c, int d, int e); // 11
    virtual void sendUnitAIOrder(int a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l); // 12
    virtual void processAIOrder(int a, int b, int c, int d, int e, float f, float g, float h, float i, int j, int k, int l); // 13
    virtual void kickAI(int param_1);                           // 14
    virtual int strategicNumber(int param_1);                  // 15
    virtual void sendGameOrder(RGE_Static_Object *obj1, RGE_Static_Object *obj2, float x, float y); // 16
    virtual void sendAddWaypointCommand(int a, XYZBYTEPoint *b, int c); // 17
    virtual void processAddWaypointCommand(int a, XYZBYTEPoint *b, int c); // 18
    virtual void sendPlayCommand(int a, int *b, int c, int d, int e); // 19
    virtual void sendPlayCommand(int a, int b, int c);          // 20
    virtual int sendAICommand(int a, int b, int c, int d, int e); // 21
    virtual int objectCostByType(int param_1);                 // 22
    virtual void trackUnitGather(int a, int b, int c);          // 23
    virtual RGE_Static_Object *make_scenario_obj(float a, float b, float c, short d, uchar e, float f); // 24
    virtual void scenario_save(int file_ptr);                   // 25
    virtual void scenario_load(int a, long *b, float c);       // 26
    virtual void scenario_postsave(int file_ptr);               // 27
    virtual void scenario_postload(int a, long *b, float c);   // 28
    virtual void load(int file_ptr);                            // 29
    virtual void add_attribute_num(short id, float amount, uchar type); // 30
    virtual void update();                                      // 31
    virtual void update_dopplegangers();                        // 32
    virtual void save(int file_ptr);                            // 33
    virtual void save2(int file_ptr);                           // 34
    virtual void save_info(int file_ptr);                      // 35
    virtual void random_start();                                // 36
    virtual RGE_Static_Object *make_new_object(long a, float b, float c, float d, int e); // 37
    virtual void analyize_selected_objects();                  // 38
    virtual int get_mouse_pointer_action_vars(int a, int *b, int *c); // 39
    virtual uchar command_make_move(RGE_Static_Object *obj, float x, float y); // 40
    virtual uchar command_make_work(RGE_Static_Object *obj, float x, float y); // 41
    virtual uchar command_make_do(RGE_Static_Object *obj, float x, float y); // 42
    virtual uchar command_stop();                               // 43
    virtual uchar command_place_object(short a, float b, float c, float d); // 44
    virtual uchar command_add_attribute(int id, float amount); // 45
    virtual uchar command_give_attribute(int player_id, int attr_id, float amount); // 46
    virtual uchar command_formation(int param_1);               // 47
    virtual uchar command_stand_ground();                       // 48
    virtual uchar command_create_group(int a, int *b, int c, float d); // 49
    virtual uchar command_add_to_group(int a, int b, float c); // 50
    virtual uchar command_remove_from_group(int a, int b);     // 51
    virtual uchar command_destroy_group(int param_1);           // 52
    virtual uchar command_resign(int a, int b);                 // 53
    virtual uchar command_add_waypoint(float a, float b, float c); // 54
    virtual RGE_Object_Node *addObject(RGE_Static_Object *obj, int a, int b); // 55
    virtual void removeObject(RGE_Static_Object *obj, int a, int b, RGE_Object_Node *c); // 56
    virtual void logMessage(char *format, ...);                 // 57
    virtual void notify(int a, int b, int c, long d, long e, long f); // 58
    virtual void logStatus(_iobuf *file, int a);               // 59
    virtual void load_victory(int a, long *b, uchar c);        // 60
    virtual void new_victory();                                 // 61

    // ========================================================================
    // Members (Offsets MUST match layout.json exactly)
    // ========================================================================
    /* 0x0004 */ int computerPlayerValue;
    /* 0x0008 */ int pathingAttemptCapValue;
    /* 0x000C */ int pathingDelayCapValue;
    /* 0x0010 */ int currentUpdatePathingAttemptsValue;
    /* 0x0014 */ long checksum;
    /* 0x0018 */ long position_checksum;
    /* 0x001C */ long action_checksum;
    /* 0x0020 */ uchar checksum_created_this_update;
    // PADDING 1 byte
    /* 0x0022 */ short master_object_num;
    /* 0x0024 */ RGE_Master_Static_Object **master_objects;
    /* 0x0028 */ RGE_Object_List *objects;
    /* 0x002C */ RGE_Object_List *sleeping_objects;
    /* 0x0030 */ RGE_Object_List *doppleganger_objects;
    /* 0x0034 */ RGE_Victory_Conditions *victory_conditions;
    /* 0x0038 */ RGE_Visible_Map *visible;
    /* 0x003C */ RGE_Game_World *world;
    /* 0x0040 */ RGE_Doppleganger_Creator *doppleganger_creator;
    /* 0x0044 */ char *name;
    /* 0x0048 */ uchar type;
    // PADDING 1 byte
    /* 0x004A */ short id;
    /* 0x004C */ short attribute_num;
    // PADDING 2 bytes? layout.json says attributes is at 80.
    // 0x4E -> 0x50.
    /* 0x0050 */ float *attributes;
    /* 0x0054 */ uchar culture;
    // PADDING 3 bytes? layout.json says tile_list is at 88. 0x54 + 1 + 3 = 0x58 (88)
    /* 0x0058 (88) */ RGE_Tile_List tile_list; // size 20
    /* 0x006C (108) */ RGE_Tile_List diam_tile_list; // size 20
    /* 0x0080 (128) */ uchar game_status;
    /* 0x0081 (129) */ uchar resigned;
    // PADDING 2 bytes? layout.json says relations is at 132 (0x84).
    /* 0x0084 (132) */ uchar *relations;
    /* 0x0088 (136) */ int unitDiplomacy[9];
    /* 0x00AC (172) */ int mutualAlly[9];
    /* 0x00D0 (208) */ ulong mutualExploredMask;
    /* 0x00D4 (212) */ ulong mutualVisibleMask;
    /* 0x00D8 (216) */ ulong nonMutualVisibleMask;
    /* 0x00DC (220) */ ulong RemoveVisibleBits[9];
    /* 0x0100 (256) */ int allied_LOS_Enable;
    /* 0x0104 (260) */ uchar allied_victory;
    /* 0x0105 (261) */ uchar master_player_id;
    // PADDING 2 bytes
    /* 0x0108 (264) */ RGE_Color_Table *color_table;
    /* 0x010C (268) */ long tribe_effect;
    /* 0x0110 (272) */ Visible_Resource_Manager *VR_List;
    /* 0x0114 (276) */ float view_x;
    /* 0x0118 (280) */ float view_y;
    /* 0x011C (284) */ short map_x;
    /* 0x011E (286) */ short map_y;
    /* 0x0120 (288) */ short selected_start_col;
    /* 0x0122 (290) */ short selected_start_row;
    /* 0x0124 (292) */ short selected_end_col;
    /* 0x0126 (294) */ short selected_end_row;
    /* 0x0128 (296) */ short replacement_terrain;
    /* 0x012A (298) */ short replacement_overlay;
    /* 0x012C (300) */ short replacement_overlay_shape;
    // PADDING 2 bytes
    /* 0x0130 (304) */ RGE_Static_Object *selected_obj;
    /* 0x0134 (308) */ RGE_Static_Object *sel_list[25];
    /* 0x0198 (408) */ ulong sel_object_properties;
    /* 0x019C (412) */ short sel_count;
    /* 0x019E (414) */ uchar groups_used[127];
    // TOTAL SIZE: 544?
    // 0x19E + 127 = 0x21D (541).
    // Plus padding to 4 bytes: 544.
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Player) == 544, "RGE_Player size mismatch");
static_assert(offsetof(RGE_Player, tile_list) == 88, "tile_list offset");
static_assert(offsetof(RGE_Player, unitDiplomacy) == 136, "unitDiplomacy offset");
static_assert(offsetof(RGE_Player, groups_used) == 414, "groups_used offset");
