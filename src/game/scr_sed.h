#pragma once
#include "../common.h"
#include "diam_map.h"
#include "dlg_abt.h"
#include "dlg_conf.h"
#include "dlg_dip.h"
#include "dlg_help.h"
#include "dlg_list.h"
#include "dlg_menu.h"
#include "Dlg_msg.h"
#include "dlg_sedm.h"
#include "dlg_smsg.h"
#include "Mouseptr.h"
#include "Panel_ez.h"
#include "Panel.h"
#include "Pnl_btn.h"
#include "pnl_dlg.h"
#include "Pnl_drop.h"
#include "pnl_edit.h"
#include "Pnl_inp.h"
#include "Pnl_lst.h"
#include "Pnl_msg.h"
#include "Pnl_pic.h"
#include "Pnl_scbr.h"
#include "Pnl_scr.h"
#include "pnl_sld.h"
#include "Pnl_txt.h"
#include "rpnl_tbx.h"
#include "rpnl_tim.h"
#include "tpnl_btn.h"
#include "tpnl_inv.h"
#include "tpnl_obj.h"
#include "tpnl_pop.h"
#include "tpnl_tim.h"
#include "tpnl_tml.h"
#include "tpnl_txl.h"
#include "spnl_obj.h"

typedef enum BrushSize : unsigned int {
    BrushSizeNone = 0,
    BrushSizeVerySmall = 1,
    BrushSizeSmall = 2,
    BrushSizeMedium = 3,
    BrushSizeLarge = 4,
    BrushSizeXLarge = 5,
};

typedef struct List_Info {
    char text[100]; // 0x0
    short id; // 0x64
};

typedef enum MapType : unsigned int {
    MapTypeNone = 0,
    MapTypeBlank = 1,
    MapTypeRandom = 2,
    MapTypeSeed = 3,
};


typedef enum MessageType : unsigned int {
    MessageTypeNone = 0,
    MessageTypeDescription = 1,
    MessageTypeInstructions = 2,
    MessageTypeVictory = 3,
    MessageTypeFailure = 4,
};

typedef enum PaintType : unsigned int {
    PaintTypeNone = 0,
    PaintTypeTerrain = 1,
    PaintTypeElevation = 2,
    PaintTypeCliffs = 3,
};

typedef enum ScenarioMode : unsigned int {
    ScenarioModeNone = 0,
    ScenarioModeMap = 1,
    ScenarioModeTerrain = 2,
    ScenarioModePlayers = 3,
    ScenarioModeUnits = 4,
    ScenarioModeDiplomacy = 5,
    ScenarioModeVictory = 6,
    ScenarioModeVictoryMulti = 7,
    ScenarioModeOptions = 8,
    ScenarioModeMessages = 9,
    ScenarioModeCinematics = 10,
    ScenarioModeSave = 11,
};

typedef enum VictoryType : unsigned int {
    VictoryTypeNone = 0,
    VictoryTypeStandard = 1,
    VictoryTypeConquest = 2,
    VictoryTypeScore = 3,
    VictoryTypeTime = 4,
    VictoryTypeCustom = 5,
};

typedef enum SELECT_REGION_e : unsigned int {
    SELECT_OFF = 0,
    SELECT_OBJECT = 1,
    SELECT_DEST_OBJECT = 2,
    SELECT_AREA = 3,
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int is_multi_player;                     // 0x478
    int set_player_first_flag;               // 0x47C
    RGE_Static_Object* SelectedObject;       // 0x480
    RGE_Static_Object* DestinationObject;    // 0x484
    float px1;                               // 0x488
    float py1;                               // 0x48C
    float px2;                               // 0x490
    float py2;                               // 0x494
    int CurrentVictory;                      // 0x498
    int CurrentPlayer;                       // 0x49C
    SELECT_REGION_e SelectRegionFlag;        // 0x4A0
    ScenarioMode scenario_mode;              // 0x4A4
    MapType map_type;                        // 0x4A8
    VictoryType mp_victory_type;             // 0x4AC
    BrushSize brush_size;                    // 0x4B0
    PaintType paint_type;                    // 0x4B4
    short player_num;                        // 0x4B8
    MessageType message_type;                // 0x4BC
    uchar need_to_save_flag;                 // 0x4C0
    uchar valid_save_spot_flag;              // 0x4C1
    TShape* background_pic;                  // 0x4C4
    TRIBE_Main_View* main_view;              // 0x4C8
    RGE_Diamond_Map_View* map_view;          // 0x4CC
    TMessagePanel* message_panel;            // 0x4D0
    TPanel* bottom_panel;                    // 0x4D4
    TButtonPanel* scenario_mode_button[10];  // 0x4D8
    TButtonPanel* menu_button;               // 0x500
    TButtonPanel* help_button;               // 0x504
    TButtonPanel* map_type_button[3];        // 0x508
    TTextPanel* map_type_text[3];            // 0x514
    TTextPanel* map_type_label;              // 0x520
    TTextPanel* default_terrain_label;       // 0x524
    TDropDownPanel* default_terrain_drop;    // 0x528
    TTextPanel* map_size_label;              // 0x52C
    TDropDownPanel* map_size_drop;           // 0x530
    TTextPanel* map_style_label;             // 0x534
    TDropDownPanel* map_style_drop;          // 0x538
    TTextPanel* random_seed_label;           // 0x53C
    TEditPanel* random_seed_input;           // 0x540
    TTextPanel* random_seed_used_label;      // 0x544
    TTextPanel* random_seed_used_text;       // 0x548
    TButtonPanel* generate_map_button;       // 0x54C
    TTextPanel* map_generating_text;         // 0x550
    TTextPanel* brush_size_label;            // 0x554
    TButtonPanel* brush_size_button[5];      // 0x558
    TTextPanel* brush_size_button_label[5];  // 0x56C
    TTextPanel* paint_type_label;            // 0x580
    TButtonPanel* paint_type_button[3];      // 0x584
    TTextPanel* paint_type_button_label[3];  // 0x590
    TTextPanel* paint_terrain_label;         // 0x59C
    TListPanel* paint_terrain_list;          // 0x5A0
    TScrollBarPanel* paint_terrain_scrollbar; // 0x5A4
    TListPanel* paint_elevation_list;        // 0x5A8
    TScrollBarPanel* paint_elevation_scrollbar; // 0x5AC
    TTextPanel* player_label;                // 0x5B0
    TDropDownPanel* player_list;             // 0x5B4
    TDropDownPanel* player_number_list;      // 0x5B8
    TDropDownPanel* player_advance_civilization_drop; // 0x5BC
    TButtonPanel* player_advance_civilization_button; // 0x5C0
    TTextPanel* player_inven_label[5];       // 0x5C4
    TEditPanel* player_inven_input[5];       // 0x5D8
    TTextPanel* player_setting_label[2];     // 0x5EC
    TTextPanel* player_starting_age_label;   // 0x5F4
    TDropDownPanel* player_setting_drop[2];  // 0x5F8
    TDropDownPanel* BuildList;               // 0x600
    TDropDownPanel* CityLayout;              // 0x604
    TDropDownPanel* AiRules;                 // 0x608
    TTextPanel* player_build_text;           // 0x60C
    TTextPanel* player_city_text;            // 0x610
    TTextPanel* AiRules_text;                // 0x614
    TDropDownPanel* unit_player_list;        // 0x618
    TButtonPanel* unit_mode_select[4];       // 0x61C
    TTextPanel* unit_mode_select_label[4];   // 0x62C
    TListPanel* unit_list;                   // 0x63C
    TScrollBarPanel* unit_scrollbar;         // 0x640
    List_Info* unit_list_info;               // 0x644
    TShape* button_unit_pics;                // 0x648
    TShape* button_bldg_pics[5];             // 0x64C
    TRIBE_Scenario_Editor_Panel_Object* object_panel; // 0x660
    short unit_list_size;                    // 0x664
    TButtonPanel* victory_cond_on[6];        // 0x668
    TButtonPanel* victory_and_or[2];         // 0x680
    TTextPanel* victory_condition_label;     // 0x688
    TTextPanel* victory_amount_label;        // 0x68C
    TTextPanel* victory_long_label;          // 0x690
    TTextPanel* victory_text_and_or[2];      // 0x694
    TTextPanel* victory_label_conquest;      // 0x69C
    TTextPanel* victory_label_explore;       // 0x6A0
    TTextPanel* victory_label_explore_percent; // 0x6A4
    TTextPanel* victory_label_ruins;         // 0x6A8
    TTextPanel* victory_label_artifacts;     // 0x6AC
    TTextPanel* victory_label_discoveries;   // 0x6B0
    TTextPanel* victory_label_gold;          // 0x6B4
    TEditPanel* victory_condition_explore;   // 0x6B8
    TEditPanel* victory_condition_ruins;     // 0x6BC
    TEditPanel* victory_condition_artifacts; // 0x6C0
    TEditPanel* victory_condition_discoveries; // 0x6C4
    TEditPanel* victory_condition_gold;      // 0x6C8
    TTextPanel* victory_cond_type_label[5];  // 0x6CC
    TButtonPanel* victory_cond_type[5];      // 0x6E0
    TTextPanel* victory_score_label;         // 0x6F4
    TDropDownPanel* victory_score;           // 0x6F8
    TTextPanel* victory_time_label;          // 0x6FC
    TDropDownPanel* victory_time;            // 0x700
    TButtonPanel* victory_button[12];        // 0x704
    TDropDownPanel* victory_drop_down;       // 0x734
    TDropDownPanel* victory_object_list;     // 0x738
    TDropDownPanel* victory_player_list;     // 0x73C
    TDropDownPanel* victory_enemy_player_list; // 0x740
    TDropDownPanel* victory_attribute_list;  // 0x744
    TDropDownPanel* victory_ages_list;       // 0x748
    TDropDownPanel* victory_tech_list;       // 0x74C
    TButtonPanel* victory_button_set_object; // 0x750
    TButtonPanel* victory_button_set_destination; // 0x754
    TButtonPanel* victory_button_go_to_dest; // 0x758
    TTextPanel* victory_condition_text;      // 0x75C
    TTextPanel* victory_condition_type;      // 0x760
    TTextPanel* victory_amount_text;         // 0x764
    TTextPanel* victory_which_enemy_text;    // 0x768
    TEditPanel* victory_amount_input;        // 0x76C
    TScrollBarPanel* victory_object_scrollbar; // 0x770
    TEditPanel* message_input;               // 0x774
    TButtonPanel* message_button[5];         // 0x778
    TTextPanel* message_button_label[5];     // 0x78C
    long current_message;                    // 0x7A0
    TTextPanel* cinematic_label[4];          // 0x7A4
    TDropDownPanel* cinematic_input[4];      // 0x7B4
    TTextPanel* options_label[1];            // 0x7C4
    TButtonPanel* options_button[1];         // 0x7C8
    TDropDownPanel* options_player_list;     // 0x7CC
    TTextPanel* options_disable_tech_text;   // 0x7D0
    TButtonPanel* options_disable_button[16]; // 0x7D4
    TTextPanel* options_disable_text[16];    // 0x814
    TTextPanel* Diplomacy_opponent_label[8]; // 0x854
    TTextPanel* Diplomacy_player_text[8];    // 0x874
    TDropDownPanel* Diplomacy_player_list;   // 0x894
    TTextPanel* Diplomacy_status_label[4];   // 0x898
    TButtonPanel** Diplomacy_friend_box[8];  // 0x8A8
    TButtonPanel* Diplomacy_AlliedVictory[8]; // 0x908
    TRIBE_World* world;                      // 0x928
    ulong update_interval;                   // 0x92C
    ulong last_update_time;                  // 0x930
    ulong map_redraw_interval;               // 0x934
    ulong last_map_redraw_time;              // 0x938
    int changed_system_colors;               // 0x93C
    ulong save_text_color;                   // 0x940
    ulong save_window_color;                 // 0x944

    TRIBE_Screen_Sed(char* param_1, int param_2);
    virtual void set_panel_info();
    virtual void set_string(char* param_1, long param_2, int param_3);
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, int param_4);
    virtual int create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, char* param_5, char* param_6);
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, long param_3);
    virtual int create_text(TPanel* param_1, TTextPanel** param_2, char* param_3);
    virtual int create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5);
    virtual int create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, int param_6, int param_7);
    virtual int create_drop_down(TPanel* param_1, TDropDownPanel** param_2);
    virtual int SetupListOfTerrain(TListPanel* param_1);
    virtual int create_list(TPanel* param_1, TListPanel** param_2, TScrollBarPanel** param_3);
    virtual ~TRIBE_Screen_Sed();
    virtual void set_scenario_mode(ScenarioMode param_1);
    virtual void set_paint_object_mode();
    virtual void set_map_type(MapType param_1, int param_2);
    virtual void set_mp_victory_type(VictoryType param_1, int param_2);
    virtual void set_brush_size(BrushSize param_1);
    virtual void set_paint_type(PaintType param_1, int param_2);
    virtual void set_terrain(short param_1);
    virtual void set_elevation(short param_1);
    virtual void set_player(short param_1, uchar param_2, uchar param_3);
    virtual void set_player_active(short param_1, int param_2);
    virtual void set_unit_player(short param_1);
    virtual void set_unit(short param_1);
    virtual void set_message_type(MessageType param_1, int param_2);
    virtual long handle_size(long param_1, long param_2);
    virtual long handle_idle();
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual void draw();
    virtual void command_cancel();
    virtual int command_menu();
    virtual void command_new();
    virtual int command_new_map(char* param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
    virtual void command_open();
    virtual void command_outline();
    virtual void command_player(int param_1);
    virtual void command_quit();
    virtual void command_save(uchar param_1, uchar param_2);
    virtual void command_save_as(uchar param_1);
    virtual char* scenario_get_default_name();
    virtual void command_quick_save();
    virtual char* scenario_save_defaulted();
    virtual uchar need_to_save();
    virtual void set_focus(int param_1);
    virtual void SaveDisabledItemsInScenario();
    virtual void LoadDisabledItemsFromScenario();
    virtual void save_info_in_scenario();
    virtual void save_multi_victory_cond_in_scenario();
    virtual void save_victory_cond_in_scenario(int param_1);
    virtual void load_victory_cond_from_scenario(int param_1);
    virtual void load_multi_victory_cond_from_scenario();
    virtual void save_diplomacy_in_scenario(int param_1);
    virtual void load_diplomacy_from_scenario(int param_1);
    virtual void activate_victory_proper_fields(int param_1, int param_2);
    virtual void init_module_variables();
    virtual void create_all_buttons_etc();
    virtual void position_panels();
    virtual void activate_victory_panel(int param_1);
    virtual int MakeFileList(TDropDownPanel* param_1, char* param_2, char* param_3, uchar param_4, uchar param_5);
    virtual int Set_player_advance_civilization_text(int param_1);
    virtual void SavePlayerActiveStatus();
    virtual int create_check_box(TPanel* param_1, TButtonPanel** param_2);
    virtual int create_radio_button(TPanel* param_1, TButtonPanel** param_2);
};

static_assert(sizeof(TRIBE_Screen_Sed) == 0x948, "TRIBE_Screen_Sed Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Sed, save_window_color) == 0x944, "TRIBE_Screen_Sed Offset Mismatch");

