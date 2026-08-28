#ifndef AOE1_SCR_SED_H
#define AOE1_SCR_SED_H

// PDB source module: C:\\msdev\\work\\age1_x1\\scr_sed.cpp.
// TRIBE_Screen_Sed and List_Info are the only declarations owned here.
// Shared panel and control types come from their canonical owners.
#include "Pnl_scr.h"
#include "Pnl_inp.h"
#include "pnl_edit.h"

class RGE_Static_Object;
class TShape;
class TTextPanel;
class TButtonPanel;
class TInputPanel;
class TDropDownPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TMessagePanel;
class TRIBE_Main_View;
class RGE_Diamond_Map_View;
class TRIBE_Scenario_Editor_Panel_Object;
class TRIBE_World;

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    TRIBE_Screen_Sed(char*, int);

    enum ScenarioMode {
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
        ScenarioModeSave = 11
    };
    enum SelectRegionMode {
        SelectOff = 0,
        SelectObject = 1,
        SelectDestinationObject = 2,
        SelectArea = 3
    };
    enum MapType {
        MapTypeNone = 0,
        MapTypeBlankValue = 1,
        MapTypeSeedValue = 2,
        MapTypeRandomValue = 3
    };
    enum VictoryType {
        VictoryTypeNone = 0,
        VictoryTypeStandardValue = 1,
        VictoryTypeConquestValue = 2,
        VictoryTypeScoreValue = 3,
        VictoryTypeTimeValue = 4,
        VictoryTypeCustomValue = 5
    };
    enum PaintType {
        PaintTypeNone = 0,
        PaintTypeTerrainValue = 1,
        PaintTypeElevationValue = 2,
        PaintTypeObjectValue = 3
    };
    enum BrushSize {
        BrushSizeNone = 0,
        BrushSizeVerySmall = 1,
        BrushSizeSmall = 2,
        BrushSizeMedium = 3,
        BrushSizeLarge = 4,
        BrushSizeVeryLarge = 5
    };
    enum MessageType {
        MessageTypeNone = 0,
        MessageTypeNormal = 1,
        MessageTypeWarning = 2,
        MessageTypeError = 3
    };

    class List_Info {
    public:
        char text[100];
        short id;
    };

    int is_multi_player;
    int set_player_first_flag;
    RGE_Static_Object* SelectedObject;
    RGE_Static_Object* DestinationObject;
    float px1;
    float py1;
    float px2;
    float py2;
    int CurrentVictory;
    int CurrentPlayer;
    int SelectRegionFlag;
    int scenario_mode;
    int map_type;
    int mp_victory_type;
    BrushSize brush_size;
    int paint_type;
    short player_num;
    MessageType message_type;
    unsigned char need_to_save_flag;
    unsigned char valid_save_spot_flag;
    TShape* background_pic;
    TRIBE_Main_View* main_view;
    RGE_Diamond_Map_View* map_view;
    TMessagePanel* message_panel;
    TPanel* bottom_panel;
    TButtonPanel* scenario_mode_button[10];
    TButtonPanel* menu_button;
    TButtonPanel* help_button;
    TButtonPanel* map_type_button[3];
    TTextPanel* map_type_text[3];
    TTextPanel* map_type_label;
    TTextPanel* default_terrain_label;
    TDropDownPanel* default_terrain_drop;
    TTextPanel* map_size_label;
    TDropDownPanel* map_size_drop;
    TTextPanel* map_style_label;
    TDropDownPanel* map_style_drop;
    TTextPanel* random_seed_label;
    TEditPanel* random_seed_input;
    TTextPanel* random_seed_used_label;
    TTextPanel* random_seed_used_text;
    TButtonPanel* generate_map_button;
    TTextPanel* map_generating_text;
    TTextPanel* brush_size_label;
    TButtonPanel* brush_size_button[5];
    TTextPanel* brush_size_button_label[5];
    TTextPanel* paint_type_label;
    TButtonPanel* paint_type_button[3];
    TTextPanel* paint_type_button_label[3];
    TTextPanel* paint_terrain_label;
    TListPanel* paint_terrain_list;
    TScrollBarPanel* paint_terrain_scrollbar;
    TListPanel* paint_elevation_list;
    TScrollBarPanel* paint_elevation_scrollbar;
    TTextPanel* player_label;
    TDropDownPanel* player_list;
    TDropDownPanel* player_number_list;
    TDropDownPanel* player_advance_civilization_drop;
    TButtonPanel* player_advance_civilization_button;
    TTextPanel* player_inven_label[5];
    TEditPanel* player_inven_input[5];
    TTextPanel* player_setting_label[2];
    TTextPanel* player_starting_age_label;
    TDropDownPanel* player_setting_drop[2];
    TDropDownPanel* BuildList;
    TDropDownPanel* CityLayout;
    TDropDownPanel* AiRules;
    TTextPanel* player_build_text;
    TTextPanel* player_city_text;
    TTextPanel* AiRules_text;
    TDropDownPanel* unit_player_list;
    TButtonPanel* unit_mode_select[4];
    TTextPanel* unit_mode_select_label[4];
    TListPanel* unit_list;
    TScrollBarPanel* unit_scrollbar;
    List_Info* unit_list_info;
    TShape* button_unit_pics;
    TShape* button_bldg_pics[5];
    TRIBE_Scenario_Editor_Panel_Object* object_panel;
    short unit_list_size;
    TButtonPanel* victory_cond_on[6];
    TButtonPanel* victory_and_or[2];
    TTextPanel* victory_condition_label;
    TTextPanel* victory_amount_label;
    TTextPanel* victory_long_label;
    TTextPanel* victory_text_and_or[2];
    TTextPanel* victory_label_conquest;
    TTextPanel* victory_label_explore;
    TTextPanel* victory_label_explore_percent;
    TTextPanel* victory_label_ruins;
    TTextPanel* victory_label_artifacts;
    TTextPanel* victory_label_discoveries;
    TTextPanel* victory_label_gold;
    TEditPanel* victory_condition_explore;
    TEditPanel* victory_condition_ruins;
    TEditPanel* victory_condition_artifacts;
    TEditPanel* victory_condition_discoveries;
    TEditPanel* victory_condition_gold;
    TTextPanel* victory_cond_type_label[5];
    TButtonPanel* victory_cond_type[5];
    TTextPanel* victory_score_label;
    TDropDownPanel* victory_score;
    TTextPanel* victory_time_label;
    TDropDownPanel* victory_time;
    TButtonPanel* victory_button[12];
    TDropDownPanel* victory_drop_down;
    TDropDownPanel* victory_object_list;
    TDropDownPanel* victory_player_list;
    TDropDownPanel* victory_enemy_player_list;
    TDropDownPanel* victory_attribute_list;
    TDropDownPanel* victory_ages_list;
    TDropDownPanel* victory_tech_list;
    TButtonPanel* victory_button_set_object;
    TButtonPanel* victory_button_set_destination;
    TButtonPanel* victory_button_go_to_dest;
    TTextPanel* victory_condition_text;
    TTextPanel* victory_condition_type;
    TTextPanel* victory_amount_text;
    TTextPanel* victory_which_enemy_text;
    TEditPanel* victory_amount_input;
    TScrollBarPanel* victory_object_scrollbar;
    TEditPanel* message_input;
    TButtonPanel* message_button[5];
    TTextPanel* message_button_label[5];
    long current_message;
    TTextPanel* cinematic_label[4];
    TDropDownPanel* cinematic_input[4];
    TTextPanel* options_label[1];
    TButtonPanel* options_button[1];
    TDropDownPanel* options_player_list;
    TTextPanel* options_disable_tech_text;
    TButtonPanel* options_disable_button[16];
    TTextPanel* options_disable_text[16];
    TTextPanel* Diplomacy_opponent_label[8];
    TTextPanel* Diplomacy_player_text[8];
    TDropDownPanel* Diplomacy_player_list;
    TTextPanel* Diplomacy_status_label[4];
    union {
        TButtonPanel* Diplomacy_friend_box[8][3];
        TButtonPanel* Diplomacy_friend_box_flat[24];
    };
    TButtonPanel* Diplomacy_AlliedVictory[8];
    TRIBE_World* world;
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    int changed_system_colors;
    unsigned long save_text_color;
    unsigned long save_window_color;

    virtual ~TRIBE_Screen_Sed();
    virtual void draw();
    virtual long handle_size(long, long);
    virtual long handle_idle();
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
protected:
    virtual void set_focus(int);
public:
    void get_string(long, char*, int);
protected:
    int create_button(TPanel*, TButtonPanel**, long, int);
    int create_button(TPanel*, TButtonPanel**, char*, char*, char*, char*);
    int create_text(TPanel*, TTextPanel**, long);
    int create_text(TPanel*, TTextPanel**, char*);
    int create_text(TPanel*, TTextPanel**, int, int, int, int, int, int, int, int, int);
    int create_drop_down(TPanel*, TDropDownPanel**);
    int create_input(TPanel*, TInputPanel**, char*, short,
                     TInputPanel::FormatType);
    int create_edit(TPanel*, TEditPanel**, char*, short,
                    TEditPanel::FormatType, int, int);
    int create_list(TPanel*, TListPanel**, TScrollBarPanel**);
    int create_radio_button(TPanel*, TButtonPanel**);
    int create_check_box(TPanel*, TButtonPanel**);
    int Set_player_advance_civilization_text(int);
    void SaveDisabledItemsInScenario();
    void LoadDisabledItemsFromScenario();
    void save_info_in_scenario();
    void save_multi_victory_cond_in_scenario();
protected:
    void save_victory_cond_in_scenario(int);
    void load_victory_cond_from_scenario(int);
    void load_multi_victory_cond_from_scenario();
    void save_diplomacy_in_scenario(int);
    void load_diplomacy_from_scenario(int);
    void activate_victory_proper_fields(int, int);
    void init_module_variables();
    void create_all_buttons_etc();
    int SetupListOfTerrain(TListPanel*);
    void position_panels();
    void activate_victory_panel(int);
    int MakeFileList(TDropDownPanel*, char*, char*, unsigned char, unsigned char);
    void SavePlayerActiveStatus();
protected:
    void set_player(short, unsigned char, unsigned char);
    void set_map_type(MapType, int);
    void set_mp_victory_type(VictoryType, int);
    void set_paint_type(PaintType, int);
    void set_unit_player(short);
public:
    void set_scenario_mode(ScenarioMode);
    void set_scenario_mode(int);
protected:
    void set_panel_info();
    void set_string(char*, long, int);
    void set_brush_size(BrushSize);
    void set_terrain(short);
    void set_elevation(short);
    void set_player_active(short, int);
    void set_unit(short);
    void set_message_type(MessageType, int);
public:
    void set_paint_object_mode();
    int command_new_map(char*, int, int, int, int, int);
    void command_cancel();
    int command_menu();
    void command_new();
    void command_open();
    void command_quit();
    void command_save(unsigned char, unsigned char);
    void command_save_as(unsigned char);
    void command_quick_save();
    void command_player(int);
    void command_outline();
    unsigned char need_to_save();
    char* scenario_get_default_name();
    char* scenario_save_defaulted();
    void setup_popup_help();
    char* get_string(int);
};

typedef char scr_sed_screen_size_check[
    (sizeof(TRIBE_Screen_Sed) == 0x948) ? 1 : -1];

#endif
