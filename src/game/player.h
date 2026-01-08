#pragma once
#include "../common.h"
#include "m_s_obj.h"
#include "obj_list.h"
#include "victory.h"
#include "visible.h"
#include "vis_unit.h"
#include "dpl_obj.h"
#include "mst_play.h"
#include "sprite.h"
#include "Sound.h"

class RGE_Tile_List       {
public:
    int list_size;                           // 0x0
    int num_active;                          // 0x4
    int new_count;                           // 0x8
    int collapse_list;                       // 0xC
    RGE_Tile_List_Node* list;                // 0x10

    RGE_Tile_List(int param_1);

    // --- Non-Virtual Members ---
    void add_node(int param_1, int param_2);
    void del_list();
    // --- Non-Virtual Destructor ---
    ~RGE_Tile_List() noexcept(false);
    void get_list_info(RGE_Tile_List_Node** param_1, int* param_2);
    int get_new_count();
};

static_assert(sizeof(RGE_Tile_List) == 0x14, "RGE_Tile_List Size Mismatch");
static_assert(offsetof(RGE_Tile_List, list) == 0x10, "RGE_Tile_List Offset Mismatch");

class RGE_Player : public RGE_Tile_List       {
public:
    int computerPlayerValue;                 // 0x4
    int pathingAttemptCapValue;              // 0x8
    int pathingDelayCapValue;                // 0xC
    int currentUpdatePathingAttemptsValue;   // 0x10
    long checksum;                           // 0x14
    long position_checksum;                  // 0x18
    long action_checksum;                    // 0x1C
    uchar checksum_created_this_update;      // 0x20
    short master_object_num;                 // 0x22
    RGE_Master_Static_Object** master_objects; // 0x24
    RGE_Object_List* objects;                // 0x28
    RGE_Object_List* sleeping_objects;       // 0x2C
    RGE_Object_List* doppleganger_objects;   // 0x30
    RGE_Victory_Conditions* victory_conditions; // 0x34
    RGE_Visible_Map* visible;                // 0x38
    RGE_Game_World* world;                   // 0x3C
    RGE_Doppleganger_Creator* doppleganger_creator; // 0x40
    char* name;                              // 0x44
    uchar type;                              // 0x48
    short id;                                // 0x4A
    short attribute_num;                     // 0x4C
    float* attributes;                       // 0x50
    uchar culture;                           // 0x54
    RGE_Tile_List tile_list;                 // 0x58
    RGE_Tile_List diam_tile_list;            // 0x6C
    uchar game_status;                       // 0x80
    uchar resigned;                          // 0x81
    uchar* relations;                        // 0x84
    int unitDiplomacy[9];                    // 0x88
    int mutualAlly[9];                       // 0xAC
    ulong mutualExploredMask;                // 0xD0
    ulong mutualVisibleMask;                 // 0xD4
    ulong nonMutualVisibleMask;              // 0xD8
    ulong RemoveVisibleBits[9];              // 0xDC
    int allied_LOS_Enable;                   // 0x100
    uchar allied_victory;                    // 0x104
    uchar master_player_id;                  // 0x105
    RGE_Color_Table* color_table;            // 0x108
    long tribe_effect;                       // 0x10C
    Visible_Resource_Manager* VR_List;       // 0x110
    float view_x;                            // 0x114
    float view_y;                            // 0x118
    short map_x;                             // 0x11C
    short map_y;                             // 0x11E
    short selected_start_col;                // 0x120
    short selected_start_row;                // 0x122
    short selected_end_col;                  // 0x124
    short selected_end_row;                  // 0x126
    short replacement_terrain;               // 0x128
    short replacement_overlay;               // 0x12A
    short replacement_overlay_shape;         // 0x12C
    RGE_Static_Object* selected_obj;         // 0x130
    RGE_Static_Object* sel_list[25];         // 0x134
    ulong sel_object_properties;             // 0x198
    short sel_count;                         // 0x19C
    uchar groups_used[127];                  // 0x19E

    RGE_Player(int param_1, RGE_Game_World* param_2, uchar param_3);
    RGE_Player(RGE_Game_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Player() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void set_game_status(uchar param_1); // Ghidra: set_game_status

    // [Slot 02] Offset 0x08 (Override)
    virtual void do_resign(int param_1); // Ghidra: do_resign

    // [Slot 03] Offset 0x0C (Override)
    virtual void changeToHumanPlayer(); // Ghidra: changeToHumanPlayer

    // [Slot 04] Offset 0x10 (Override)
    virtual void changeToComputerPlayer(); // Ghidra: changeToComputerPlayer

    // [Slot 05] Offset 0x14 (Override)
    virtual char* aiStatus(int param_1); // Ghidra: aiStatus

    // [Slot 06] Offset 0x18 (Override)
    virtual int isEnemy(int param_1); // Ghidra: isEnemy

    // [Slot 07] Offset 0x1C (Override)
    virtual int isAlly(int param_1); // Ghidra: isAlly

    // [Slot 08] Offset 0x20 (Override)
    virtual int isNeutral(int param_1); // Ghidra: isNeutral

    // [Slot 09] Offset 0x24 (Override)
    virtual int isAllNeutral(); // Ghidra: isAllNeutral

    // [Slot 10] Offset 0x28 (Override)
    virtual void setDiplomaticStance(int param_1, int param_2); // Ghidra: setDiplomaticStance

    // [Slot 11] Offset 0x2C (Override)
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5); // Ghidra: loadAIInformation

    // [Slot 12] Offset 0x30 (Override)
    virtual void sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12); // Ghidra: sendUnitAIOrder

    // [Slot 13] Offset 0x34 (Override)
    virtual void processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12); // Ghidra: processAIOrder

    // [Slot 14] Offset 0x38 (Override)
    virtual void kickAI(int param_1); // Ghidra: kickAI

    // [Slot 15] Offset 0x3C (Override)
    virtual int strategicNumber(int param_1); // Ghidra: strategicNumber

    // [Slot 16] Offset 0x40 (Override)
    virtual void sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4); // Ghidra: sendGameOrder

    // [Slot 17] Offset 0x44 (Override)
    virtual void sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3); // Ghidra: sendAddWaypointCommand

    // [Slot 18] Offset 0x48 (Override)
    virtual void processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3); // Ghidra: processAddWaypointCommand

    // [Slot 19] Offset 0x4C (Override)
    virtual void sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5); // Ghidra: sendPlayCommand

    // [Slot 20] Offset 0x50 (Override)
    virtual void sendPlayCommand(int param_1, int param_2, int param_3); // Ghidra: sendPlayCommand

    // [Slot 21] Offset 0x54 (Override)
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5); // Ghidra: sendAICommand

    // [Slot 22] Offset 0x58 (Override)
    virtual int objectCostByType(int param_1); // Ghidra: objectCostByType

    // [Slot 23] Offset 0x5C (Override)
    virtual void trackUnitGather(int param_1, int param_2, int param_3); // Ghidra: trackUnitGather

    // [Slot 24] Offset 0x60 (Override)
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6); // Ghidra: make_scenario_obj

    // [Slot 25] Offset 0x64 (Override)
    virtual void scenario_save(int param_1); // Ghidra: scenario_save

    // [Slot 26] Offset 0x68 (Override)
    virtual void scenario_load(int param_1, long* param_2, float param_3); // Ghidra: scenario_load

    // [Slot 27] Offset 0x6C (Override)
    virtual void scenario_postsave(int param_1); // Ghidra: scenario_postsave

    // [Slot 28] Offset 0x70 (Override)
    virtual void scenario_postload(int param_1, long* param_2, float param_3); // Ghidra: scenario_postload

    // [Slot 29] Offset 0x74 (Override)
    virtual void load(int param_1); // Ghidra: load

    // [Slot 30] Offset 0x78 (Override)
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3); // Ghidra: add_attribute_num

    // [Slot 31] Offset 0x7C (Override)
    virtual void update(); // Ghidra: update

    // [Slot 32] Offset 0x80 (Override)
    virtual void update_dopplegangers(); // Ghidra: update_dopplegangers

    // [Slot 33] Offset 0x84 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 34] Offset 0x88 (Override)
    virtual void save2(int param_1); // Ghidra: save2

    // [Slot 35] Offset 0x8C (Override)
    virtual void save_info(int param_1); // Ghidra: save_info

    // [Slot 36] Offset 0x90 (Override)
    virtual void random_start(); // Ghidra: random_start

    // [Slot 37] Offset 0x94 (Override)
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5); // Ghidra: make_new_object

    // [Slot 38] Offset 0x98 (Override)
    virtual void analyize_selected_objects(); // Ghidra: analyize_selected_objects

    // [Slot 39] Offset 0x9C (Override)
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3); // Ghidra: get_mouse_pointer_action_vars

    // [Slot 40] Offset 0xA0 (Override)
    virtual uchar command_make_move(RGE_Static_Object* param_1, float param_2, float param_3); // Ghidra: command_make_move

    // [Slot 41] Offset 0xA4 (Override)
    virtual uchar command_make_work(RGE_Static_Object* param_1, float param_2, float param_3); // Ghidra: command_make_work

    // [Slot 42] Offset 0xA8 (Override)
    virtual uchar command_make_do(RGE_Static_Object* param_1, float param_2, float param_3); // Ghidra: command_make_do

    // [Slot 43] Offset 0xAC (Override)
    virtual uchar command_stop(); // Ghidra: command_stop

    // [Slot 44] Offset 0xB0 (Override)
    virtual uchar command_place_object(short param_1, float param_2, float param_3, float param_4); // Ghidra: command_place_object

    // [Slot 45] Offset 0xB4 (Override)
    virtual uchar command_add_attribute(int param_1, float param_2); // Ghidra: command_add_attribute

    // [Slot 46] Offset 0xB8 (Override)
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3); // Ghidra: command_give_attribute

    // [Slot 47] Offset 0xBC (Override)
    virtual uchar command_formation(int param_1); // Ghidra: command_formation

    // [Slot 48] Offset 0xC0 (Override)
    virtual uchar command_stand_ground(); // Ghidra: command_stand_ground

    // [Slot 49] Offset 0xC4 (Override)
    virtual uchar command_create_group(int param_1, int* param_2, int param_3, float param_4); // Ghidra: command_create_group

    // [Slot 50] Offset 0xC8 (Override)
    virtual uchar command_add_to_group(int param_1, int param_2, float param_3); // Ghidra: command_add_to_group

    // [Slot 51] Offset 0xCC (Override)
    virtual uchar command_remove_from_group(int param_1, int param_2); // Ghidra: command_remove_from_group

    // [Slot 52] Offset 0xD0 (Override)
    virtual uchar command_destroy_group(int param_1); // Ghidra: command_destroy_group

    // [Slot 53] Offset 0xD4 (Override)
    virtual uchar command_resign(int param_1, int param_2); // Ghidra: command_resign

    // [Slot 54] Offset 0xD8 (Override)
    virtual uchar command_add_waypoint(float param_1, float param_2, float param_3); // Ghidra: command_add_waypoint

    // [Slot 55] Offset 0xDC (Override)
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3); // Ghidra: addObject

    // [Slot 56] Offset 0xE0 (Override)
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4); // Ghidra: removeObject

    // [Slot 57] Offset 0xE4 (Override)
    virtual void logMessage(char* param_1); // Ghidra: logMessage

    // [Slot 58] Offset 0xE8 (Override)
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // Ghidra: notify

    // [Slot 59] Offset 0xEC (Override)
    virtual void logStatus(_iobuf* param_1, int param_2); // Ghidra: logStatus

    // [Slot 60] Offset 0xF0 (Override)
    virtual void load_victory(int param_1, long* param_2, uchar param_3); // Ghidra: load_victory

    // [Slot 61] Offset 0xF4 (Override)
    virtual void new_victory(); // Ghidra: new_victory

    // [Slot 62] Offset 0xF8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 63] Offset 0xFC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 64] Offset 0x100 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 65] Offset 0x104 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 66] Offset 0x108 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 67] Offset 0x10C WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 68] Offset 0x110 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 69] Offset 0x114 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 70] Offset 0x118 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 71] Offset 0x11C WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 72] Offset 0x120 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 73] Offset 0x124 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 74] Offset 0x128 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 75] Offset 0x12C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 76] Offset 0x130 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 77] Offset 0x134 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 78] Offset 0x138 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 79] Offset 0x13C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 80] Offset 0x140 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 81] Offset 0x144 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 82] Offset 0x148 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 83] Offset 0x14C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 84] Offset 0x150 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 85] Offset 0x154 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 86] Offset 0x158 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 87] Offset 0x15C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 88] Offset 0x160 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 89] Offset 0x164 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 90] Offset 0x168 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 91] Offset 0x16C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 92] Offset 0x170 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 93] Offset 0x174 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 94] Offset 0x178 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 95] Offset 0x17C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 96] Offset 0x180 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 97] Offset 0x184 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 98] Offset 0x188 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 99] Offset 0x18C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 100] Offset 0x190 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 101] Offset 0x194 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 102] Offset 0x198 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 103] Offset 0x19C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 104] Offset 0x1A0 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 105] Offset 0x1A4 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 106] Offset 0x1A8 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 107] Offset 0x1AC WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 108] Offset 0x1B0 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 109] Offset 0x1B4 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 110] Offset 0x1B8 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 111] Offset 0x1BC WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 112] Offset 0x1C0 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 113] Offset 0x1C4 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 114] Offset 0x1C8 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 115] Offset 0x1CC WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 116] Offset 0x1D0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 117] Offset 0x1D4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 118] Offset 0x1D8 WARNING: Function body missing in analysis
    // virtual void set_state();

    // [Slot 119] Offset 0x1DC WARNING: Function body missing in analysis
    // virtual void hit_button();

    // [Slot 120] Offset 0x1E0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 121] Offset 0x1E4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 122] Offset 0x1E8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 123] Offset 0x1EC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 124] Offset 0x1F0 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 125] Offset 0x1F4 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 126] Offset 0x1F8 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 127] Offset 0x1FC WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 128] Offset 0x200 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 129] Offset 0x204 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 130] Offset 0x208 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 131] Offset 0x20C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 132] Offset 0x210 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 133] Offset 0x214 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 134] Offset 0x218 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 135] Offset 0x21C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 136] Offset 0x220 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 137] Offset 0x224 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 138] Offset 0x228 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 139] Offset 0x22C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 140] Offset 0x230 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 141] Offset 0x234 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 142] Offset 0x238 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 143] Offset 0x23C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 144] Offset 0x240 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 145] Offset 0x244 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 146] Offset 0x248 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 147] Offset 0x24C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 148] Offset 0x250 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 149] Offset 0x254 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 150] Offset 0x258 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 151] Offset 0x25C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 152] Offset 0x260 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 153] Offset 0x264 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 154] Offset 0x268 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 155] Offset 0x26C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 156] Offset 0x270 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 157] Offset 0x274 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 158] Offset 0x278 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 159] Offset 0x27C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 160] Offset 0x280 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 161] Offset 0x284 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 162] Offset 0x288 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 163] Offset 0x28C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 164] Offset 0x290 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 165] Offset 0x294 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 166] Offset 0x298 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 167] Offset 0x29C WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 168] Offset 0x2A0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 169] Offset 0x2A4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 170] Offset 0x2A8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 171] Offset 0x2AC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 172] Offset 0x2B0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 173] Offset 0x2B4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 174] Offset 0x2B8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 175] Offset 0x2BC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 176] Offset 0x2C0 WARNING: Function body missing in analysis
    // virtual void draw_background();

    // [Slot 177] Offset 0x2C4 WARNING: Function body missing in analysis
    // virtual void set_ideal_size();

    // [Slot 178] Offset 0x2C8 WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 179] Offset 0x2CC WARNING: Function body missing in analysis
    // virtual void create_button();

    // [Slot 180] Offset 0x2D0 WARNING: Function body missing in analysis
    // virtual void create_check_box();

    // [Slot 181] Offset 0x2D4 WARNING: Function body missing in analysis
    // virtual void create_radio_button();

    // [Slot 182] Offset 0x2D8 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 183] Offset 0x2DC WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 184] Offset 0x2E0 WARNING: Function body missing in analysis
    // virtual void create_text();

    // [Slot 185] Offset 0x2E4 WARNING: Function body missing in analysis
    // virtual void create_input();

    // [Slot 186] Offset 0x2E8 WARNING: Function body missing in analysis
    // virtual void create_edit();

    // [Slot 187] Offset 0x2EC WARNING: Function body missing in analysis
    // virtual void create_drop_down();

    // [Slot 188] Offset 0x2F0 WARNING: Function body missing in analysis
    // virtual void create_list();

    // [Slot 189] Offset 0x2F4 WARNING: Function body missing in analysis
    // virtual void create_scrollbar();

    // [Slot 190] Offset 0x2F8 WARNING: Function body missing in analysis
    // virtual void create_auto_scrollbar();

    // [Slot 191] Offset 0x2FC WARNING: Function body missing in analysis
    // virtual void create_vert_slider();

    // [Slot 192] Offset 0x300 WARNING: Function body missing in analysis
    // virtual void create_horz_slider();

    // [Slot 193] Offset 0x304 WARNING: Function body missing in analysis
    // virtual void position_panel();

    // [Slot 194] Offset 0x308 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 195] Offset 0x30C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 196] Offset 0x310 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 197] Offset 0x314 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 198] Offset 0x318 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 199] Offset 0x31C WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 200] Offset 0x320 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 201] Offset 0x324 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 202] Offset 0x328 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 203] Offset 0x32C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 204] Offset 0x330 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 205] Offset 0x334 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 206] Offset 0x338 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 207] Offset 0x33C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 208] Offset 0x340 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 209] Offset 0x344 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 210] Offset 0x348 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 211] Offset 0x34C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 212] Offset 0x350 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 213] Offset 0x354 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 214] Offset 0x358 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 215] Offset 0x35C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 216] Offset 0x360 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 217] Offset 0x364 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 218] Offset 0x368 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 219] Offset 0x36C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 220] Offset 0x370 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 221] Offset 0x374 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 222] Offset 0x378 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 223] Offset 0x37C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 224] Offset 0x380 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 225] Offset 0x384 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 226] Offset 0x388 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 227] Offset 0x38C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 228] Offset 0x390 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 229] Offset 0x394 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 230] Offset 0x398 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 231] Offset 0x39C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 232] Offset 0x3A0 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 233] Offset 0x3A4 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 234] Offset 0x3A8 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 235] Offset 0x3AC WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 236] Offset 0x3B0 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 237] Offset 0x3B4 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 238] Offset 0x3B8 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 239] Offset 0x3BC WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 240] Offset 0x3C0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 241] Offset 0x3C4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 242] Offset 0x3C8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 243] Offset 0x3CC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 244] Offset 0x3D0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 245] Offset 0x3D4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 246] Offset 0x3D8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 247] Offset 0x3DC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 248] Offset 0x3E0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 249] Offset 0x3E4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 250] Offset 0x3E8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 251] Offset 0x3EC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 252] Offset 0x3F0 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 253] Offset 0x3F4 WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 254] Offset 0x3F8 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 255] Offset 0x3FC WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 256] Offset 0x400 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 257] Offset 0x404 WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 258] Offset 0x408 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 259] Offset 0x40C WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 260] Offset 0x410 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 261] Offset 0x414 WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 262] Offset 0x418 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 263] Offset 0x41C WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 264] Offset 0x420 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 265] Offset 0x424 WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 266] Offset 0x428 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 267] Offset 0x42C WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 268] Offset 0x430 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 269] Offset 0x434 WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 270] Offset 0x438 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 271] Offset 0x43C WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 272] Offset 0x440 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 273] Offset 0x444 WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 274] Offset 0x448 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 275] Offset 0x44C WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 276] Offset 0x450 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 277] Offset 0x454 WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 278] Offset 0x458 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 279] Offset 0x45C WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 280] Offset 0x460 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 281] Offset 0x464 WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 282] Offset 0x468 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 283] Offset 0x46C WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 284] Offset 0x470 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 285] Offset 0x474 WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 286] Offset 0x478 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 287] Offset 0x47C WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 288] Offset 0x480 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 289] Offset 0x484 WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 290] Offset 0x488 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 291] Offset 0x48C WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 292] Offset 0x490 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 293] Offset 0x494 WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 294] Offset 0x498 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 295] Offset 0x49C WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 296] Offset 0x4A0 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 297] Offset 0x4A4 WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 298] Offset 0x4A8 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 299] Offset 0x4AC WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 300] Offset 0x4B0 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 301] Offset 0x4B4 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 302] Offset 0x4B8 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 303] Offset 0x4BC WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 304] Offset 0x4C0 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 305] Offset 0x4C4 WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 306] Offset 0x4C8 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 307] Offset 0x4CC WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 308] Offset 0x4D0 WARNING: Function body missing in analysis
    // virtual void set_state();

    // [Slot 309] Offset 0x4D4 WARNING: Function body missing in analysis
    // virtual void hit_button();

    // [Slot 310] Offset 0x4D8 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 311] Offset 0x4DC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 312] Offset 0x4E0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 313] Offset 0x4E4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 314] Offset 0x4E8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 315] Offset 0x4EC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 316] Offset 0x4F0 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 317] Offset 0x4F4 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 318] Offset 0x4F8 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 319] Offset 0x4FC WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 320] Offset 0x500 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 321] Offset 0x504 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 322] Offset 0x508 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 323] Offset 0x50C WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 324] Offset 0x510 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 325] Offset 0x514 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 326] Offset 0x518 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 327] Offset 0x51C WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 328] Offset 0x520 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 329] Offset 0x524 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 330] Offset 0x528 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 331] Offset 0x52C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 332] Offset 0x530 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 333] Offset 0x534 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 334] Offset 0x538 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 335] Offset 0x53C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 336] Offset 0x540 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 337] Offset 0x544 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 338] Offset 0x548 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 339] Offset 0x54C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 340] Offset 0x550 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 341] Offset 0x554 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 342] Offset 0x558 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 343] Offset 0x55C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 344] Offset 0x560 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 345] Offset 0x564 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 346] Offset 0x568 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 347] Offset 0x56C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 348] Offset 0x570 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 349] Offset 0x574 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 350] Offset 0x578 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 351] Offset 0x57C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 352] Offset 0x580 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 353] Offset 0x584 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 354] Offset 0x588 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 355] Offset 0x58C WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 356] Offset 0x590 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 357] Offset 0x594 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 358] Offset 0x598 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 359] Offset 0x59C WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 360] Offset 0x5A0 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 361] Offset 0x5A4 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 362] Offset 0x5A8 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 363] Offset 0x5AC WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 364] Offset 0x5B0 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 365] Offset 0x5B4 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 366] Offset 0x5B8 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 367] Offset 0x5BC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 368] Offset 0x5C0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 369] Offset 0x5C4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 370] Offset 0x5C8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 371] Offset 0x5CC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 372] Offset 0x5D0 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 373] Offset 0x5D4 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 374] Offset 0x5D8 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 375] Offset 0x5DC WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 376] Offset 0x5E0 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 377] Offset 0x5E4 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 378] Offset 0x5E8 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 379] Offset 0x5EC WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 380] Offset 0x5F0 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 381] Offset 0x5F4 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 382] Offset 0x5F8 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 383] Offset 0x5FC WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 384] Offset 0x600 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 385] Offset 0x604 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 386] Offset 0x608 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 387] Offset 0x60C WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 388] Offset 0x610 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 389] Offset 0x614 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 390] Offset 0x618 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 391] Offset 0x61C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 392] Offset 0x620 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 393] Offset 0x624 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 394] Offset 0x628 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 395] Offset 0x62C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 396] Offset 0x630 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 397] Offset 0x634 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 398] Offset 0x638 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 399] Offset 0x63C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 400] Offset 0x640 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 401] Offset 0x644 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 402] Offset 0x648 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 403] Offset 0x64C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 404] Offset 0x650 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 405] Offset 0x654 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 406] Offset 0x658 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 407] Offset 0x65C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 408] Offset 0x660 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 409] Offset 0x664 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 410] Offset 0x668 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 411] Offset 0x66C WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 412] Offset 0x670 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 413] Offset 0x674 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 414] Offset 0x678 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 415] Offset 0x67C WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 416] Offset 0x680 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 417] Offset 0x684 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 418] Offset 0x688 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 419] Offset 0x68C WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 420] Offset 0x690 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 421] Offset 0x694 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 422] Offset 0x698 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 423] Offset 0x69C WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 424] Offset 0x6A0 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 425] Offset 0x6A4 WARNING: Function body missing in analysis
    // virtual void set_bevel_info();

    // [Slot 426] Offset 0x6A8 WARNING: Function body missing in analysis
    // virtual void `vector_deleting_destructor'();

    // [Slot 427] Offset 0x6AC WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 428] Offset 0x6B0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 429] Offset 0x6B4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 430] Offset 0x6B8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 431] Offset 0x6BC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 432] Offset 0x6C0 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 433] Offset 0x6C4 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 434] Offset 0x6C8 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 435] Offset 0x6CC WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 436] Offset 0x6D0 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 437] Offset 0x6D4 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 438] Offset 0x6D8 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 439] Offset 0x6DC WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 440] Offset 0x6E0 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // [Slot 441] Offset 0x6E4 WARNING: Function body missing in analysis
    // virtual void draw_rect2();

    // [Slot 442] Offset 0x6E8 WARNING: Function body missing in analysis
    // virtual void draw_offset2();

    // [Slot 443] Offset 0x6EC WARNING: Function body missing in analysis
    // virtual void paint();

    // [Slot 444] Offset 0x6F0 WARNING: Function body missing in analysis
    // virtual void wnd_proc();

    // [Slot 445] Offset 0x6F4 WARNING: Function body missing in analysis
    // virtual void handle_idle();

    // [Slot 446] Offset 0x6F8 WARNING: Function body missing in analysis
    // virtual void handle_size();

    // [Slot 447] Offset 0x6FC WARNING: Function body missing in analysis
    // virtual void handle_paint();

    // [Slot 448] Offset 0x700 WARNING: Function body missing in analysis
    // virtual void handle_key_down();

    // [Slot 449] Offset 0x704 WARNING: Function body missing in analysis
    // virtual void handle_char();

    // [Slot 450] Offset 0x708 WARNING: Function body missing in analysis
    // virtual void handle_command();

    // [Slot 451] Offset 0x70C WARNING: Function body missing in analysis
    // virtual void handle_user_command();

    // [Slot 452] Offset 0x710 WARNING: Function body missing in analysis
    // virtual void handle_timer_command();

    // [Slot 453] Offset 0x714 WARNING: Function body missing in analysis
    // virtual void handle_scroll();

    // [Slot 454] Offset 0x718 WARNING: Function body missing in analysis
    // virtual void handle_mouse_down();

    // [Slot 455] Offset 0x71C WARNING: Function body missing in analysis
    // virtual void handle_mouse_move();

    // [Slot 456] Offset 0x720 WARNING: Function body missing in analysis
    // virtual void handle_mouse_up();

    // [Slot 457] Offset 0x724 WARNING: Function body missing in analysis
    // virtual void handle_mouse_dbl_click();

    // [Slot 458] Offset 0x728 WARNING: Function body missing in analysis
    // virtual void mouse_move_action();

    // [Slot 459] Offset 0x72C WARNING: Function body missing in analysis
    // virtual void mouse_left_down_action();

    // [Slot 460] Offset 0x730 WARNING: Function body missing in analysis
    // virtual void mouse_left_hold_action();

    // [Slot 461] Offset 0x734 WARNING: Function body missing in analysis
    // virtual void mouse_left_move_action();

    // [Slot 462] Offset 0x738 WARNING: Function body missing in analysis
    // virtual void mouse_left_up_action();

    // [Slot 463] Offset 0x73C WARNING: Function body missing in analysis
    // virtual void mouse_left_dbl_click_action();

    // [Slot 464] Offset 0x740 WARNING: Function body missing in analysis
    // virtual void mouse_right_down_action();

    // [Slot 465] Offset 0x744 WARNING: Function body missing in analysis
    // virtual void mouse_right_hold_action();

    // [Slot 466] Offset 0x748 WARNING: Function body missing in analysis
    // virtual void mouse_right_move_action();

    // [Slot 467] Offset 0x74C WARNING: Function body missing in analysis
    // virtual void mouse_right_up_action();

    // [Slot 468] Offset 0x750 WARNING: Function body missing in analysis
    // virtual void mouse_right_dbl_click_action();

    // [Slot 469] Offset 0x754 WARNING: Function body missing in analysis
    // virtual void key_down_action();

    // [Slot 470] Offset 0x758 WARNING: Function body missing in analysis
    // virtual void char_action();

    // [Slot 471] Offset 0x75C WARNING: Function body missing in analysis
    // virtual void action();

    // [Slot 472] Offset 0x760 WARNING: Function body missing in analysis
    // virtual void get_true_render_rect();

    // [Slot 473] Offset 0x764 WARNING: Function body missing in analysis
    // virtual void is_inside();

    // [Slot 474] Offset 0x768 WARNING: Function body missing in analysis
    // virtual void set_focus();

    // [Slot 475] Offset 0x76C WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 476] Offset 0x770 WARNING: Function body missing in analysis
    // virtual void set_tab_order();

    // [Slot 477] Offset 0x774 WARNING: Function body missing in analysis
    // virtual void get_help_info();

    // [Slot 478] Offset 0x778 WARNING: Function body missing in analysis
    // virtual void stop_sound_system();

    // [Slot 479] Offset 0x77C WARNING: Function body missing in analysis
    // virtual void restart_sound_system();

    // [Slot 480] Offset 0x780 WARNING: Function body missing in analysis
    // virtual void take_snapshot();

    // [Slot 481] Offset 0x784 WARNING: Function body missing in analysis
    // virtual void handle_reactivate();

    // [Slot 482] Offset 0x788 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 483] Offset 0x78C WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 484] Offset 0x790 WARNING: Function body missing in analysis
    // virtual void set_text();

    // [Slot 485] Offset 0x794 WARNING: Function body missing in analysis
    // virtual void set_bevel_info();

    // [Slot 486] Offset 0x798 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 487] Offset 0x79C WARNING: Function body missing in analysis
    // virtual void setup();

    // [Slot 488] Offset 0x7A0 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 489] Offset 0x7A4 WARNING: Function body missing in analysis
    // virtual void set_rect();

    // [Slot 490] Offset 0x7A8 WARNING: Function body missing in analysis
    // virtual void set_color();

    // [Slot 491] Offset 0x7AC WARNING: Function body missing in analysis
    // virtual void set_active();

    // [Slot 492] Offset 0x7B0 WARNING: Function body missing in analysis
    // virtual void set_positioning();

    // [Slot 493] Offset 0x7B4 WARNING: Function body missing in analysis
    // virtual void set_fixed_position();

    // [Slot 494] Offset 0x7B8 WARNING: Function body missing in analysis
    // virtual void set_redraw();

    // [Slot 495] Offset 0x7BC WARNING: Function body missing in analysis
    // virtual void set_overlapped_redraw();

    // [Slot 496] Offset 0x7C0 WARNING: Function body missing in analysis
    // virtual void draw_setup();

    // [Slot 497] Offset 0x7C4 WARNING: Function body missing in analysis
    // virtual void draw_finish();

    // [Slot 498] Offset 0x7C8 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 499] Offset 0x7CC WARNING: Function body missing in analysis
    // virtual void draw_rect();

    // [Slot 500] Offset 0x7D0 WARNING: Function body missing in analysis
    // virtual void draw_offset();

    // --- Non-Virtual Members ---
    uchar get_resigned();
    int computerPlayer();
    int pathingAttemptCap();
    void setPathingAttemptCap(int param_1);
    int pathingDelayCap();
    void setPathingDelayCap(int param_1);
    int currentUpdatePathingAttempts();
    int availablePathingAttempts(int param_1);
    void incrementPathingAttempts();
    void sendChatMessage(int param_1, int param_2, char* param_3);
    void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
    void load_info(int param_1);
    long get_checksum();
    uchar get_checksums(long* param_1, long* param_2, long* param_3);
    long create_checksum();
    void new_attribute_num(short param_1, float param_2);
    void make_available(short param_1, uchar param_2);
    void set_map_loc(short param_1, short param_2);
    void set_view_loc(float param_1, float param_2);
    void destroy_objects();
    void set_color_table(uchar param_1);
    void victory_if_game_on();
    void loss_if_game_on();
    void win_game_now();
    uchar check_victory_conditions();
    uchar check_ally_group(long* param_1);
    uchar check_victory();
    void modify_tobj(short param_1, short param_2, float param_3, uchar param_4);
    void modify_tobj_delta(short param_1, short param_2, float param_3, uchar param_4);
    void modify_tobj_percent(short param_1, short param_2, float param_3, uchar param_4);
    void copy_obj(short param_1, short param_2);
    void set_allied_victory(uchar param_1);
    uchar get_allied_victory();
    uchar relation(long param_1);
    void set_relation(long param_1, uchar param_2);
    void reset_selected();
    int select_object(RGE_Static_Object* param_1);
    int select_one_object(RGE_Static_Object* param_1, int param_2);
    void unselect_object();
    void unselect_one_object(RGE_Static_Object* param_1);
    void unselect_one_object(short param_1);
    int group_objects(int param_1);
    int select_group(int param_1);
    int own_selected();
    int is_category_selected(short param_1);
    int is_group_selected(short param_1);
    uchar unit_level_selected();
    uchar get_select_level();
    uchar get_selected_objects_to_command(RGE_Static_Object*** param_1, short* param_2, short param_3, short param_4, short param_5, short param_6);
    void update_selected();
    void select_area(short param_1, short param_2, short param_3, short param_4);
    void unselect_area();
    void ungroup_objects();
    void set_map_visible();
    void remake_visible_map();
};

static_assert(sizeof(RGE_Player) == 0x220, "RGE_Player Size Mismatch");
static_assert(offsetof(RGE_Player, groups_used) == 0x19E, "RGE_Player Offset Mismatch");

void RGE_Player::changeToHumanPlayer() {
    /* TODO: Stub */
//                              void __thiscall changeToHumanPlayer(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?changeToHumanPlayer@RGE_Player@@UAEXXZ                      XREF[1]:     00570edc(*)
//                               RGE_Player::changeToHumanPlayer
//                              player.h:173 (1)
//         0046ec80     RET
//         0046ec81     ??         90h
//         0046ec82     NOP
//         0046ec83     NOP
//         0046ec84     NOP
//         0046ec85     NOP
//         0046ec86     NOP
//         0046ec87     NOP
//         0046ec88     NOP
//         0046ec89     NOP
//         0046ec8a     NOP
//         0046ec8b     NOP
//         0046ec8c     NOP
//         0046ec8d     NOP
//         0046ec8e     NOP
//         0046ec8f     NOP
    return;
}

void RGE_Player::changeToComputerPlayer() {
    /* TODO: Stub */
//                              void __thiscall changeToComputerPlayer(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?changeToComputerPlayer@RGE_Player@@UAEXXZ                   XREF[1]:     00570ee0(*)
//                               RGE_Player::changeToComputerPlayer
//                              player.h:174 (1)
//         0046ec90     RET
//         0046ec91     ??         90h
//         0046ec92     NOP
//         0046ec93     NOP
//         0046ec94     NOP
//         0046ec95     NOP
//         0046ec96     NOP
//         0046ec97     NOP
//         0046ec98     NOP
//         0046ec99     NOP
//         0046ec9a     NOP
//         0046ec9b     NOP
//         0046ec9c     NOP
//         0046ec9d     NOP
//         0046ec9e     NOP
//         0046ec9f     NOP
    return;
}

void RGE_Player::kickAI(int param_1) {
    /* TODO: Stub */
//                              void __thiscall kickAI(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?kickAI@RGE_Player@@UAEXH@Z                                  XREF[1]:     00570f08(*)
//                               RGE_Player::kickAI
//                              player.h:186 (3)
//         0046eca0     RET        0x4
//         0046eca3     ??         90h
//         0046eca4     NOP
//         0046eca5     NOP
//         0046eca6     NOP
//         0046eca7     NOP
//         0046eca8     NOP
//         0046eca9     NOP
//         0046ecaa     NOP
//         0046ecab     NOP
//         0046ecac     NOP
//         0046ecad     NOP
//         0046ecae     NOP
//         0046ecaf     NOP
    return;
}

int RGE_Player::strategicNumber(int param_1) {
    /* TODO: Stub */
//                              int __thiscall strategicNumber(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?strategicNumber@RGE_Player@@UAEHH@Z                         XREF[1]:     00570f0c(*)
//                               RGE_Player::strategicNumber
//                              player.h:187 (6)
//         0046ecb0     OR         EAX,0xffffffff
//         0046ecb3     RET        0x4
//         0046ecb6     ??         90h
//         0046ecb7     NOP
//         0046ecb8     NOP
//         0046ecb9     NOP
//         0046ecba     NOP
//         0046ecbb     NOP
//         0046ecbc     NOP
//         0046ecbd     NOP
//         0046ecbe     NOP
//         0046ecbf     NOP
    return 0;
}

int RGE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall sendAICommand(RGE_Player * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?sendAICommand@RGE_Player@@UAEHHHHHH@Z                       XREF[1]:     00570f24(*)
//                               RGE_Player::sendAICommand
//                              player.h:193 (5)
//         0046ecc0     XOR        EAX,EAX
//         0046ecc2     RET        0x14
//         0046ecc5     ??         90h
//         0046ecc6     NOP
//         0046ecc7     NOP
//         0046ecc8     NOP
//         0046ecc9     NOP
//         0046ecca     NOP
//         0046eccb     NOP
//         0046eccc     NOP
//         0046eccd     NOP
//         0046ecce     NOP
//         0046eccf     NOP
    return 0;
}

int RGE_Player::objectCostByType(int param_1) {
    /* TODO: Stub */
//                              int __thiscall objectCostByType(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?objectCostByType@RGE_Player@@UAEHH@Z                        XREF[1]:     00570f28(*)
//                               RGE_Player::objectCostByType
//                              player.h:195 (6)
//         0046ecd0     OR         EAX,0xffffffff
//         0046ecd3     RET        0x4
//         0046ecd6     ??         90h
//         0046ecd7     NOP
//         0046ecd8     NOP
//         0046ecd9     NOP
//         0046ecda     NOP
//         0046ecdb     NOP
//         0046ecdc     NOP
//         0046ecdd     NOP
//         0046ecde     NOP
//         0046ecdf     NOP
    return 0;
}

void RGE_Player::trackUnitGather(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall trackUnitGather(RGE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?trackUnitGather@RGE_Player@@UAEXHHH@Z                       XREF[1]:     00570f2c(*)
//                               RGE_Player::trackUnitGather
//                              player.h:206 (3)
//         0046ed30     RET        0xc
//         0046ed33     ??         90h
//         0046ed34     NOP
//         0046ed35     NOP
//         0046ed36     NOP
//         0046ed37     NOP
//         0046ed38     NOP
//         0046ed39     NOP
//         0046ed3a     NOP
//         0046ed3b     NOP
//         0046ed3c     NOP
//         0046ed3d     NOP
//         0046ed3e     NOP
//         0046ed3f     NOP
    return;
}

void RGE_Player::logStatus(_iobuf* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall logStatus(RGE_Player * this, _iobuf * param_1, int p
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?logStatus@RGE_Player@@UAEXPAU_iobuf@@H@Z                    XREF[1]:     00570fbc(*)
//                               RGE_Player::logStatus
//                              player.h:300 (3)
//         0046ed40     RET        0x8
//         0046ed43     ??         90h
//         0046ed44     NOP
//         0046ed45     NOP
//         0046ed46     NOP
//         0046ed47     NOP
//         0046ed48     NOP
//         0046ed49     NOP
//         0046ed4a     NOP
//         0046ed4b     NOP
//         0046ed4c     NOP
//         0046ed4d     NOP
//         0046ed4e     NOP
//         0046ed4f     NOP
    return;
}

