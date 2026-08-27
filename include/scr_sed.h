#ifndef SCR_SED_H
#define SCR_SED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new.h>

#include "rge_base_game_global.h"

typedef unsigned char uchar;

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
extern char s_592A40[];
extern char s_OKDialog[];
extern char s_QuitSaveDialog[];
extern char s_OpenSaveDialog[];
extern char s_NewSaveDialog[];
extern char s_Save_Game_Screen[];
extern char s_Scenario_Menu_Dialog[];
extern char s_Scenario_Editor_Screen[];
extern char s_Scenario_Editor_Open[];
extern char s_C__msdev_work_age1_x1_scr_sed_cp[];
extern char DAT_0086bad8[];

extern "C" int __cdecl atoi(const char*);
extern "C" char* __cdecl itoa(int, char*, int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" long __cdecl _findfirst(const char*, void*);
extern "C" int __cdecl _findnext(long, void*);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
extern "C" void __cdecl qsort(void*, unsigned int, unsigned int,
                                int (__cdecl*)(const void*, const void*));
extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long, unsigned long, const char*, int, const char*, int);
extern "C" void __cdecl debug_rand(char*, int);
extern int (__stdcall* const InvalidateRect)(void*, void*, int);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void DrawBevel3(int, int, int, int, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
};
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
class TInputPanel;
class TDropDownPanel;
class TEditPanel;
class TListPanel;
class TScrollBarPanel;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Prog_Info;
class TRegistry;
class TRIBE_Tech;
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
    tagRECT clip_rect;
    char gap_34[0x3C - 0x34];
    TPanel* curr_child;
    char gap_40[0x6C - 0x40];
    int field_6C;
    char gap_70[0x78 - 0x70];
    int have_focus;
    char gap_7C[0x8C - 0x7C];
    tagRECT stored_rect;
    char gap_9C[0xD8 - 0x9C];
    union {
        int error_code;
        int setup_error;
    };
    char gap_DC[0x8];
    long help_string_id;
    long help_page_id;
    char gap_EC[0x8];

    void set_help_info(long, long);
    void set_z_order(unsigned char, int);
    void set_curr_child(TPanel*);
    void redraw(int);
    char* panelName();
    int width();
    int height();
    int get_string(int, char*, int);
    template<class T> void delete_panel(T**);
};

class TButtonPanel : public TPanel {
public:
    virtual void set_state(int);
    int get_state();
    void set_radio_info(TButtonPanel**, short);
    void set_radio_button();
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text(short, char*);
};

class TTextPanel : public TPanel {
public:
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char* currentLine();
    char* get_string();
    int currentLineNumber();
    int numberLines();
    int numberDrawLines();
    void empty_list();
    int append_line(long, int);
    int append_line(char*, long);
};

class TEditPanel : public TPanel {
public:
    enum FormatType {
        FormatText = 0,
        FormatUnsignedInt = 3,
        FormatMultiLine = 7
    };
    char* currentLine();
    char* get_input_buffer();
    void set_text(char*);
};
class TInputPanel : public TPanel {
public:
    enum FormatType {
        FormatText = 0,
        FormatUnsignedInt = 3,
        FormatMultiLine = 7
    };
};
class TListPanel : public TTextPanel {
public:
    void empty_list();
    void scroll_cur_line(unsigned char, short, int);
};
class TScrollBarPanel : public TPanel {};

class TDropDownPanel : public TPanel {
public:
    char* currentLine();
    char* currentLine(int);
    int currentLineNumber();
    void empty_list();
    int append_line(long, long);
    int append_line(char*, long);
    void setCurrentLineNumber(int);
    void setCurrentLineId(int);
    void set_sorted(int);
    void set_line(long);
    long get_line();
    long get_line(long);
    long get_line(char*);
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
    virtual void slot0(int);
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea*, TPanel*, void*, long, long,
                                       TShape*, TShape**, TRIBE_Player*);
    void set_master_info(RGE_Master_Static_Object*, TRIBE_Player*);
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
    TMessagePanel(void*, long, long);
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x26C];
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char,
               int, char*);
    void get_selection_area(long*, long*, long*, long*, int);
    void set_selection_area(long, long, long, long);
    void set_world(RGE_Game_World*);
    void set_player(RGE_Player*);
};

class RGE_Diamond_Map_View;
class RGE_Main_View : public RGE_View {
public:
    RGE_Diamond_Map_View* map_view;
    RGE_Main_View();
    virtual ~RGE_Main_View();
};
class TRIBE_Main_View : public RGE_Main_View {};
class RGE_Diamond_Map : public TPanel {
public:
    char gap_F4[0x150 - 0xF4];
    RGE_View* main_view;
    void set_world(RGE_Game_World*);
    void set_player(RGE_Player*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char,
               int, TDrawArea*);
    int set_bitmap(char*, long);
};
class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    RGE_Diamond_Map_View();
    virtual ~RGE_Diamond_Map_View();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_game_mode(int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string_extended(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    char* get_string(long);
    char gap_04[0x0C - 0x04];
    RGE_Prog_Info* prog_info;
    void* prog_window;
    char gap_14[0x2C - 0x14];
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    char gap_3C[0x4C - 0x3C];
    TDrawArea* draw_area;
    unsigned char outline_type;
    char gap_51[0x60 - 0x51];
    void* sound_system;
    char gap_64[0x1AC - 0x64];
    TRegistry* registry;
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1BC[0x3F4 - 0x1BC];
    TRIBE_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    char gap_408[0xA20 - 0x408];
    TDrawArea* map_save_area;
    RGE_Font* get_font(int);
    RGE_Player* get_player();
    int gameDeveloperMode();
    void draw_window();
    void redraw(int);
    void redraw(long, long);
    void close();
    void set_windows_mouse(int);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void show_status_message(int, char*, long);
    int load_game_data();
    void close_status_message();
    int start_menu();
    void start_scenario_editor(char*, int);
    void close();
};

class TRegistry {
public:
    int RegGetInt(int, char*);
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
    virtual void draw();
    void setup_shadow_area(int);
    int create_button(TPanel*, TButtonPanel**, char*, long, long, long);
    int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long,
                      long, long, long, long);
    int create_text(TPanel*, TTextPanel**, long, int, int, int, int, int, int,
                    int, int);
    int create_text(TPanel*, TTextPanel**, char*, int, int, int, int, int, int,
                    int, int);
    int create_input(TPanel*, TInputPanel**, char*, short, int, int, int, int,
                     int, int);
    int create_edit(TPanel*, TEditPanel**, char*, short, int, int, int, int,
                    int, int, int, int);
    int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    void popupOKDialog(long, char*, int, int);
    void popupYesNoCancelDialog(long, char*, int, int);
    int create_check_box(TPanel*, TButtonPanel**, int, int, int, int, int, int);
    int create_radio_button(TPanel*, TButtonPanel**, int, int, int, int, int, int);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char*);
    virtual ~TScreenPanel();
    virtual void set_focus(int);
    long setup(TDrawArea*, char*, long, int);
};

class RGE_Scenario {
public:
    virtual void v0();
    virtual void v1();
    virtual void rehook();
    virtual void save(int);

    int active_player_count();
    int any_player_count();
    int Get_player_Active(int);
    char* Get_scenario_name();
    void Set_scenario_name(char*);
    char* Get_message(long);
    void Set_message(char*, long);
    char* Get_Cine_PreGame();
    char* Get_Cine_Victory();
    char* Get_Cine_Loss();
    char* Get_Mission_Bmp();
    void Set_Cine_PreGame(char*);
    void Set_Cine_Victory(char*);
    void Set_Cine_Loss(char*);
    void Set_Mission_Bmp(char*);
    void SetPlayerName(long, char*);
    void Set_player_Type(long, int);
    void Set_player_Civ(long, int);
    void Set_player_AI(long, char*);
    void Set_BuildList(long, char*);
    void Set_CityPlan(long, char*);
    char* GetPlayerName(long);
    int Get_player_Type(long);
    int Get_player_Civ(long);
    char* Get_player_AI(long, long);
    char* Get_BuildList(long, long);
    char* Get_CityPlan(long, long);
};

class T_Scenario : public RGE_Scenario {
public:

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
    void SetPlayerAge(int, int);
    int GetPlayerAge(int);
    void SetScenarioOption(int, int);
    int GetScenarioOption(int);
    void Set_player_Food(long, int);
    void Set_player_Wood(long, int);
    void Set_player_Stone(long, int);
    void Set_player_Gold(long, int);
    int Get_player_Food(long);
    int Get_player_Wood(long);
    int Get_player_Stone(long);
    int Get_player_Gold(long);
};

class RGE_Tile_List {
public:
    char values[0x14];
    void del_list();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    union {
        unsigned char master_type;
        unsigned char obj_type;
    };
    char gap_05[3];
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
    unsigned char gap_25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char disabled; // BINARY NOTE: +0x4E in scr_sed.cpp.
    unsigned char hide_in_scenario_editor;
    char gap_4F[0x16C - 0x4F];
    union {
        unsigned char scenario_editor_flag;
        unsigned char flag;
    };
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x22 - 0x04];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x4A - 0x28];
    short id;
    char gap_4C[0x58 - 0x4C];
    RGE_Tile_List tile_list;
    char gap_6C[0x114 - 0x6C];
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    char gap_120[0x130 - 0x120];
    RGE_Static_Object* selected_obj;
    void select_one_object(RGE_Static_Object*, int);
    void unselect_object();
    void unselect_area();
    void reset_selected();
    void set_map_loc(short, short);
    void set_view_loc(float, float);
    void set_map_visible();
};

class RGE_Map {
public:
    void clear_map(RGE_Player*, void*, unsigned char, long, long);
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
};

struct Tech_Entry {
    char gap_00[0x2A];
    short string_id;
    char gap_2C[0x3C - 0x2C];
};

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;
    char gap_06[2];
};

class RGE_Prog_Info {
public:
    char gap_00[0x102B];
    char ai_dir[0x105];
    char avi_dir[0x105];
};

struct RGE_Player_Info;

class RGE_Game_World {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24();
    virtual void new_random_map(float, float, float, long);
    virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44(); virtual void v48();
    virtual void v4C(); virtual void v50(); virtual void v54(); virtual void v58();
    virtual void v5C(); virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6C(); virtual void v70(); virtual void v74(); virtual void v78();
    virtual void v7C(); virtual void v80(); virtual void v84(); virtual void v88();
    virtual void v8C(); virtual void v90(); virtual void v94(); virtual void v98();
    virtual void v9C(); virtual void vA0(); virtual void vA4(); virtual void vA8();
    virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void del_game_info();
    virtual void vBC(); virtual void vC0(); virtual void vC4(); virtual void vC8();
    virtual void vCC(); virtual void vD0();
    virtual unsigned char new_scenario(RGE_Player_Info*, int);
    virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual unsigned char save(char*);

    char gap_04[0x28 - 0x04];
    RGE_Map* map;
    char gap_2C[0x3C - 0x2C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    short player_count;
    char gap_46[0x5C - 0x46];
    T_Scenario* scenario;
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_60[0x104 - 0x60];
    TRIBE_Tech* tech;
};

struct RGE_Info_Line {
    short clump_num;
    char rest[0x12];
};

struct RGE_Map_Gen_Info {
    RGE_Info_Line land;
    char rest[0x520 - 0x14];
};

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    char gap_25B;
    short color[9];
    char gap_26E[2];
    long player_id_hash[9];
    short player_num;
    char gap_296[2];
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
    char gap_2A9[3];
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
    // The original helper ABI names these nested enum types.
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
    unsigned char pad_4BA[2];
    MessageType message_type;
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
    // These five helpers have protected original-FPO decorated symbols.
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

class TRIBE_Dialog_Sed_Menu {
public:
    virtual void activate(int);
    char gap_004[0x0D8 - 0x004];
    void* field_D8;
    char gap_0DC[0x4B4 - 0x0DC];
    TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed*);
};

class PanelNode;
class TPanelSystem {
public:
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    int numberActivePanelsValue;
    TPanel* prevCurrentChildValue;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];
    unsigned long Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
    TPanel* modalPanel();
};
extern TPanelSystem panel_system;

class TribeSaveGameScreen : public TScreenPanel {
public:
    enum Mode { SaveGame = 0, SaveScenario = 1, SaveScenarioEdit = 2 };
    virtual ~TribeSaveGameScreen();
    char gap_478[0x6A4 - 0x478];
    TribeSaveGameScreen(Mode, char*, int);
};

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    char gap_478[0x490 - 0x478];
    TRIBE_Screen_Sed_Open();
};

class Sound_Driver {
public:
    char gap_00[1];
    unsigned char mute;
};

class RGE_Sprite {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Active_Sprite_List {
public:
    unsigned char get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual void set_selected(int);
    char gap_04[0x0C];
    RGE_Sprite* sprite;
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list;
};

extern int View_Grid_Mode;
extern unsigned long debug_timeGetTime(const char*, int);

int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void*, const void*);

const int FormatText = 0;
const int FormatUnsignedInt = 3;
const int FormatMultiLine = 7;
const int SELECT_OBJECT = 1;
const int SELECT_DEST_OBJECT = 2;
const int SELECT_AREA = 3;
const int SELECT_OFF = 0;
const int MapTypeBlank = 1;
const int MapTypeSeed = 2;
const int BrushSizeVerySmall = 1;
const int PaintTypeTerrain = 1;
const int VictoryTypeStandard = 1;

#endif
