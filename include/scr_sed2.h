#ifndef AOE1_SCR_SED2_H
#define AOE1_SCR_SED2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new.h>

#include "rge_base_game_global.h"

extern char s_space[];
extern char s_percent_d[];
extern char s_btnbldg_d_shp[];
extern char s_btnunit_shp[];
extern char s_0[];
extern char s_angle_d_star[];
extern char s_percent_d_star[];
extern char s_angle_d[];
extern char s_300[];
extern char s_400[];
extern char s_500[];
extern char s_600[];
extern char s_700[];
extern char s_900[];
extern char s_1200[];
extern char s_1500[];
extern char s_1800[];
extern char s_2100[];
extern char s_2400[];
extern char s_2700[];
extern char s_3000[];
extern char s_800[];
extern char s_empty[];

extern "C" int __cdecl atoi(const char*);
extern "C" char* __cdecl itoa(int, char*, int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" long __cdecl _findfirst(const char*, void*);
extern "C" int __cdecl _findnext(long, void*);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class Shape_Header;
class Shape_File_Header;
class Shape_Offsets;
class SLhape_File_Header;
class Shape_Info;
class TShape;
class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class TRIBE_Player;
class TRIBE_World;
class T_Scenario;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    char gap_24[0x54];
    int have_focus;
    char gap_7C[0x5C];
    int error_code;
    char gap_DC[0x8];
    long help_string_id;
    long help_page_id;
    char gap_EC[0x8];

    void set_help_info(long, long);
    void set_z_order(unsigned char, int);
    void set_curr_child(TPanel*);
    int width();
    int height();
};

class TButtonPanel : public TPanel {
public:
    virtual void set_state(int);
    int get_state();
    void set_radio_info(TButtonPanel**, short);
    void set_radio_button();
    void set_bevel_info(int, int, int, int, int, int, int);
};

class TTextPanel : public TPanel {
public:
    char* currentLine();
    char* get_string();
    void set_text(char*);
    int numberLines();
    int numberDrawLines();
};

class TEditPanel : public TTextPanel {};
class TListPanel : public TTextPanel {};
class TScrollBarPanel : public TPanel {};

class TDropDownPanel : public TPanel {
public:
    void empty_list();
    int append_line(long, long);
    int append_line(char*, long);
    void setCurrentLineNumber(int);
    void setCurrentLineId(int);
    void set_line(long);
    long get_line();
    long get_line(long);
    long get_id();
};

class TShape {
public:
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;
    TShape(char*, long);
    ~TShape();
    int is_loaded();
};

class TRIBE_Panel_Object : public TPanel {
public:
    char gap_F4[0x120];
    virtual ~TRIBE_Panel_Object();
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea*, TPanel*, void*, long, long,
                                       TShape*, TShape**, TRIBE_Player*);
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class TMessagePanel : public TPanel {
public:
    char gap_F4[0x28C];
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x26C];
    void get_selection_area(long*, long*, long*, int*, int);
    void set_selection_area(long, long, long, long);
};

class RGE_Main_View : public RGE_View {};
class TRIBE_Main_View : public RGE_Main_View {};
class RGE_Diamond_Map : public TPanel {};
class RGE_Diamond_Map_View : public RGE_Diamond_Map {};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    RGE_Font* get_font(int);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x228];
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_326[2];
    char gap_328[0x150];

    virtual ~TEasy_Panel();
    int create_check_box(TPanel*, TButtonPanel**, int, int, int, int, int, int);
    int create_radio_button(TPanel*, TButtonPanel**, int, int, int, int, int, int);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class T_Scenario {
public:
    virtual void v0();
    virtual void v1();
    virtual void reset();

    void SetDisabledTechnology(int, int, int);
    int GetDisabledTechnology(int, int);
    void SetMPVictory(int);
    int GetMPVictory();
    void SetVictoryScore(int);
    int GetVictoryScore();
    void SetVictoryTime(int);
    int GetVictoryTime();
    void Set_victory_all_flag(int);
    int Get_victory_all_flag();
    void Set_Multi_Conquest(int);
    int Get_Multi_Conquest();
    void Set_Multi_Exploration(int);
    int Get_Multi_Exploration();
    void Set_Multi_Ruins(int);
    int Get_Multi_Ruins();
    void Set_Multi_Artifacts(int);
    int Get_Multi_Artifacts();
    void Set_Multi_Discoveries(int);
    int Get_Multi_Discoveries();
    void Set_Multi_Gold(int);
    int Get_Multi_Gold();
    void ClearSPVictoryCondition(int);
    void SetSPRectangle(int, float, float, float, float);
    void GetSPRectangle(int, float*, float*, float*, float*);
    void SetSPObjectType(int, int);
    int GetSPObjectType(int);
    void SetSPPlayerID(int, int);
    int GetSPPlayerID(int);
    void SetSPAllFlag(int, int);
    int GetSPAllFlag(int);
    void SetSPAttribType(int, int);
    int GetSPAttribType(int);
    void SetSPVictoryType(int, int);
    int GetSPVictoryType(int);
    void SetSPObject(int, RGE_Static_Object*);
    RGE_Static_Object* GetSPObject(int);
    void SetSPDestObjectID(int, RGE_Static_Object*);
    RGE_Static_Object* GetSPDestObjectID(int);
    void SetSPAmount(int, int);
    int GetSPAmount(int);
    void SetSPWhich(int);
    void Save_victory_conditions_into_players(int);
    void Set_player_attitude(int, int, int);
    int Get_player_attitude(int, int);
    void SetPlayerAlliedVictory(int, int);
    int GetPlayerAlliedVictory(int);
    void Set_player_Active(int, int);
};

class TRIBE_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[0x1E];
    T_Scenario* scenario;
};

struct FindDataLocal {
    unsigned int attrib;
    long time_create;
    long time_access;
    long time_write;
    unsigned long size;
    char name[260];
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
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
    int brush_size;
    int paint_type;
    short player_num;
    unsigned char pad_4BA[2];
    int message_type;
    unsigned char need_to_save_flag;
    unsigned char valid_save_spot_flag;
    unsigned char pad_4C2[2];
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
    unsigned char pad_666[2];
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
    TButtonPanel* Diplomacy_friend_box[8][3];
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
protected:
    int create_button(TPanel*, TButtonPanel**, long, int);
    int create_button(TPanel*, TButtonPanel**, char*, char*, char*, char*);
    int create_text(TPanel*, TTextPanel**, long);
    int create_text(TPanel*, TTextPanel**, char*);
    int create_text(TPanel*, TTextPanel**, int, int, int, int, int, int, int, int, int);
    int create_drop_down(TPanel*, TDropDownPanel**);
    int create_edit(TPanel*, TEditPanel**, char*, short, int, int, int);
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
public:
    void position_panels();
protected:
    void activate_victory_panel(int);
    int MakeFileList(TDropDownPanel*, char*, char*, unsigned char, unsigned char);
    void SavePlayerActiveStatus();
    void set_player(short, unsigned char, unsigned char);
};

const int FormatText = 0;
const int FormatUnsignedInt = 3;
const int FormatMultiLine = 7;

#endif
