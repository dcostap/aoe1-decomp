#ifndef SCR_GAME_CONTEXT_H
#define SCR_GAME_CONTEXT_H

// Canonical declarations for the scr_game.cpp recovery owner set.
// PDB source order and the shared TRIBE_Screen_Game offsets are the authority.
// The active owner set spans constructor, update, key, action, button, score,
// draw, and animation code. The full module still has owners that need this
// surface before they can join the one-TU wrapper.

#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

#ifndef _WINDEF_
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPOINT {
    long x;
    long y;
};
#endif

class TDrawArea;
class TShape;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class RGE_Static_Object;
class RGE_Object_Node;
class RGE_Object_List;
class RGE_Player;
class TRIBE_Player;
class RGE_Color_Table;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class TRIBE_Master_Building_Object;
class RGE_Scenario;
class RGE_Scenario_Header;
class RGE_Victory_Conditions;
class RGE_Player_Info;
class RGE_Sound;
class RGE_Map;
class RGE_Tile;
class TSound_Driver {
public:
    int stop_stream();
    int stream_file(char*, int, long);
};
class TCommunications_Handler;
class TDebuggingLog;
class TFont;
class TDigital;
class TPanel;
struct PanelNode;
class TEasy_Panel;
class TScreenPanel;
class RGE_View;
class RGE_Main_View;
class TRIBE_Main_View;
class RGE_Diamond_Map;
class TRIBE_Diamond_Map_View;
class TRIBE_Panel_Inven;
class TRIBE_Panel_Object;
class TRIBE_Panel_Button;
class TMessagePanel;
class TRIBE_Panel_Time;
class TRIBE_Panel_Pop;
class RGE_Panel_Tool_Box;
class RGE_Game_World;
class TRIBE_World;
class RGE_Base_Game;
class TRIBE_Game;
class TPanelSystem;
class TribeSaveGameScreen;
class TribeLoadSavedGameScreen;
struct Item_Avail;
class Trade_Avail;
class TRIBE_Player_Tech;
class TRIBE_Tech;
class XYZBYTEPoint;

extern "C" unsigned long __cdecl debug_timeGetTime(char*, int);
extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void __cdecl qsort(void*, unsigned int, unsigned int,
                               int (*)(const void*, const void*));
extern "C" long __cdecl __ftol(void);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct RGE_Prog_Info {
    char gap_00[0x888];
    unsigned long update_interval;
    char gap_88c[0x1c];
    int use_sound;
};

struct TPanelBaseFields {
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    union {
        TDrawArea* render_area;
        TDrawArea* draw_surface;
    };
    tagRECT clip_rect;
    int position_mode;
    union {
        int need_redraw;
        int mode;
        int panel_mode;
    };
    union {
        TPanel* curr_child;
        TPanel* panel_state;
    };
    union {
        TPanel* parent_panel;
        TPanel* panel_40;
    };
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    union {
        void* first_child_node;
        PanelNode* child_list;
    };
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    union {
        int active;
        int field_6C;
    };
    union {
        int visible;
        int field_70;
    };
    int tab_stop;
    union {
        int have_focus;
        void* input_window;
    };
    union {
        int overlapping_children;
        int field_7C;
    };
    int handle_mouse_input;
    union {
        int just_drawn;
        int redraw_needed;
    };
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

struct scr_tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawSystem {
public:
    void ModifyPalette(int, int, scr_tagPALETTEENTRY*);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* hwnd;
    void LockWindow(void*);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void FillRect(long, long, long, long, unsigned char);
    void SetClipRect(tagRECT*);
};

struct PanelNode {
    TPanel* panel;
    char gap_04[4];
    PanelNode* next;
};

class TPanel {
public:
    enum RedrawMode {
        RedrawNormal = 0
    };

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    void set_positioning(int, long, long, long, long, long, long, long, long);
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
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
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
    union {
        TDrawArea* render_area;
        TDrawArea* draw_surface;
    };
    tagRECT clip_rect;
    int position_mode;
    union {
        int need_redraw;
        int mode;
        int panel_mode;
    };
    union {
        TPanel* curr_child;
        TPanel* panel_state;
    };
    union {
        TPanel* parent_panel;
        TPanel* panel_40;
    };
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    union {
        void* first_child_node;
        PanelNode* child_list;
    };
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    union {
        int active;
        int field_6C;
    };
    union {
        int visible;
        int field_70;
    };
    int tab_stop;
    union {
        int have_focus;
        void* input_window;
    };
    union {
        int overlapping_children;
        int field_7C;
    };
    int handle_mouse_input;
    union {
        int just_drawn;
        int redraw_needed;
    };
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    union {
        int error_code;
        int field_D8;
    };
    int field_DC;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;


    char* panelName();
    void target_func(int);
    int pick_tile(long, long, short*, short*, RGE_Tile**);
    void update();
    void update(int);
    void show_message(int, char*, int, int, int, int, int);
    void set_text(char*);
    void set_text(int, char*, int);
    void set_text_color(int, int);
    void set_text_color(int, int, int);
    void set_player(RGE_Player*);
    char* get_string(int);
    int get_string(int, char*, int);
    char* get_string(int, int, int, int, int, int);
    void set_curr_child(TPanel*);
    void set_help_info(int, int);
    void set_z_order(unsigned char, int);
    int get_focus();
    void release_mouse();
    void set_object(RGE_Static_Object*);
    void remove_message();
    void set_visible(int);
};

class RGE_Command {
public:
    void command_group(int);
    void command_group_by_number(int);
    void command_select_group(int, int);
    void command_menu();
    void do_commands(int);
};

class TRIBE_Command {
public:
    void command_quick_build(int);
    void command_game_speed(float);
    void do_commands(int);
    void do_commands();
    void command_queue(RGE_Static_Object*, int, short);
};

struct Speed_Message {
    union {
        float new_speed;
        char msg[256];
    };
    char pad[4];
};

class TribeSendMessageDialog {
public:
    TribeSendMessageDialog(TPanel*, int);
    TribeSendMessageDialog(TPanel*);
};

class TribeSendQuickMessageDialog {
public:
    TribeSendQuickMessageDialog(TPanel*, int);
    TribeSendQuickMessageDialog(TPanel*);
};

class TribeDiplomacyDialog {
public:
    TribeDiplomacyDialog(TPanel*, int);
    TribeDiplomacyDialog(TPanel*);
};

class TribeMenuDialog {
public:
    TribeMenuDialog(TPanel*, int);
    TribeMenuDialog(TPanel*);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x354];
    TShape* button_pics;
    char gap_44C[0x2c];

    virtual ~TEasy_Panel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long,
                               long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long,
                               long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long,
                                 long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long,
                            long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long,
                            long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, int, long,
                             long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long,
                            long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long,
                            long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel*, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long,
                                   long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);

    void setup_popup_help();
    void popupYesNoDialog(char*, void*, int, int);
    void popupYesNoDialog(long, char*, int, int);
    void popupYesNoCancelDialog(char*, char*, int, int);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char*);
    virtual ~TScreenPanel();
    int setup(TDrawArea*, char*, long, int);
    long setup(TDrawArea*, TPanel*, int, int, int, int, int);
    int create_text(TPanel*, TTextPanel**, int, int, int, int, int, int,
                    int, int, int, int);
    int create_text(TPanel*, TTextPanel**, int, int, int, int, int, int,
                    int, int, int);
    int create_text(TPanel*, TTextPanel**, char*, int, int, int, int, int,
                    int, int, int, int);
    int create_text(TPanel*, TTextPanel**, char*, int, int, int, int, int,
                    int, int, int);
    virtual void set_focus(int);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char*, int);
    ~TShape();
    int is_loaded();
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
    unsigned char shape_draw(TDrawArea*, long, long, int, unsigned char,
                             unsigned char*);
};

class TFont {
};

class RGE_Font {
public:
    TFont* font;
    int font_wid;
    int font_hgt;
};

class TDigital {
public:
    TDigital(TSound_Driver*, char*, long);
    ~TDigital();
    int play();
    int load(char*, long);
    int is_playing();
    void stop();
};

class RGE_Sound {
public:
    char* get_file_name();
    void stop();
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x26c];
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    long setup(TDrawArea*, TPanel*, int, int, int, int, unsigned char, int,
               char*);
    void set_world(RGE_Game_World*);
    void set_player(RGE_Player*);
    void set_selection_area(long, long, long, long);
};

class RGE_Tile_Set {
public:
    unsigned char loaded;
    char gap_001[0x23];
    RGE_Sound* sound;
    char gap_028[0x1d];
    unsigned char drawn;
    char gap_046[0x152];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_004[0x88];
    RGE_Tile_Set terrain_types[32];
    char gap_338c[0x5a00];
    void* map_row_offset;
    short num_terrain;
};

class RGE_Main_View : public RGE_View {
public:
    char gap_380[0x20];
    RGE_Main_View();
    int message_active;
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual ~TRIBE_Main_View();
    long width();
    void update();
    void update(int);
};

class RGE_Diamond_Map : public TPanel {
public:
    char gap_DC[0x74];
    TRIBE_Main_View* main_view;
    char gap_154[0x20];
    long setup(TDrawArea*, TPanel*, int, int, int, int, unsigned char, int,
               void*);
    void set_world(RGE_Game_World*);
    void set_bitmap(char*, int);
    void set_player(RGE_Player*);
    int pick_tile(long, long, short*, short*);
    void update();
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    TRIBE_Diamond_Map_View();
};

class TRIBE_Panel_Inven : public TPanel {
public:
    char gap_DC[0x3c];
    TRIBE_Panel_Inven(TDrawArea*, TPanel*, TFont*, RGE_Player*);
};

class TRIBE_Panel_Object : public TPanel {
public:
    char gap_DC[0x138];
    TRIBE_Panel_Object(TDrawArea*, TPanel*, TFont*, int, int, TShape*,
                       TShape**, RGE_Player*);
    void set_object(RGE_Static_Object*);
    void set_player(RGE_Player*);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1cc];
    union {
        unsigned char draw_type_byte;
        unsigned char draw_type;
    };
    int enabled;
    char gap_2C1[0x113];
    long hotkey;
    long hotkey_shift;

    virtual ~TButtonPanel();
    void set_text_color(int, int, int);
    void set_text_color(int, unsigned long, unsigned long);
    void set_sound_number(int);
    void set_id(short, long, long);
    void setDrawType(int);
    long get_id();
    void set_text(int, char*);
    void set_text(int, char*, char*);
    void set_text(char*);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_picture(short, TShape*, short);
    int button_action(long, long);
    char* help_text;
};

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;
    int garrison_number;
    unsigned char tribe_button_type;
    char gap_2C1[3];
    TShape* border_pic;
    char gap_2C8[0x108];
    int in_use;
    int disabled;
    unsigned char* color_table;
    int border_frame;

    TRIBE_Panel_Button(TDrawArea*, TPanel*, TDigital*, TFont*, int, int,
                       TShape*);
    void set_text_msg(char*);
    void set_text(int, char*, char*);
    void set_display_garrison(int);
    void set_garrison_number(int);
    void set_active(int);
    void set_disabled(int);
    int get_id2();
    void reset();
    void set_text(int, char*, int);
};

class TMessagePanel : public TPanel {
public:
    enum MessageType {
        MessageNormal = 0
    };

    char gap_F4[0x28c];
    TMessagePanel(TFont*, int, int);
    long setup(TDrawArea*, TPanel*, int, int, int, int, int);
    void set_justification(int, int, int);
    void remove_message();
    void show_message2(int, char*, unsigned long, unsigned long, void*, long,
                       long, void*, int, void*, int);
    void show_message(int, char*);
    void show_message(int, char*, int, int, int, int, int);
    void show_message(MessageType, char*, int, int, int, int, int);
    void show_message(int, const char*);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x94];
    TTextPanel();
    long setup(TDrawArea*, TPanel*, int, int, int, int, TFont*, int, int,
               char*, int, unsigned char, int, unsigned char, int, char*);
    void set_alignment(int, int);
    void set_back_pic(char*);
    void set_fill_back(int, unsigned char);
    void set_style(int);
    void set_text_color(int, int);
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    void empty_list();
    int pause_flag;
    char* get_text();
};

class TScrollBarPanel : public TPanel {
public:
    void set_bevel_info(int, int, int, int, int, int, int);
};

class TRIBE_Panel_Time : public TPanel {
public:
    char gap_DC[0x78];
    TRIBE_Panel_Time(TDrawArea*, TPanel*);
    void startup();
    void set_clock_type(int, int);
    int get_clock_type();
};

class TRIBE_Panel_Pop : public TPanel {
public:
    char gap_DC[0x88];
    TRIBE_Panel_Pop(TDrawArea*, TPanel*);
    void startup();
};

class RGE_Panel_Tool_Box : public TEasy_Panel {
public:
    RGE_Panel_Tool_Box(TDrawArea*, TPanel*, int, int, int, int, TFont*, int,
                       int, TDigital*, TScreenPanel*, RGE_View*,
                       RGE_Diamond_Map*);
    void game_mode_changed(int, int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    void* objects;
    char gap_2C[0x08];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x18];
    float* attributes;
    unsigned char culture;
    char gap_55[0x2b];
    unsigned char game_status;
    unsigned char resigned;
    char gap_82[2];
    unsigned char* relations;
    char gap_88[0x7c];
    unsigned char allied_victory;
    unsigned char master_player_id;
    char gap_106[2];
    RGE_Color_Table* color_table;
    char gap_10c[0x24];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    char gap_134[0x68];
    short sel_count;
    long id;

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
    unsigned char unit_level_selected();
    int is_group_selected(short);
    unsigned char get_selected_objects_to_command();
    unsigned char check_obj_cost(short, short*, float, int);
    void group_objects(int);
    void unselect_object(RGE_Static_Object*);
    void unselect_object();
    void select_group(int);
    void select_object(RGE_Static_Object*);
    void set_view_loc(long, long);
    void set_map_loc(long, long);
    void ungroup_objects();
    RGE_Static_Object* find_obj(int);
    RGE_Static_Object* find_obj(int, int);
    RGE_Static_Object* find_obj();
    RGE_Static_Object* find_obj(int, RGE_Static_Object*);
    void unselect_area();
    unsigned char check_tech_cost(short*, short*);
    void command_building_make_obj(short);
    unsigned char relation(long);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*,
                               float, float);
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
    virtual RGE_Static_Object* make_new_object(long, float, float, float,
                                                 int);
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
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    void interface_item_avail(Item_Avail**, short*, short);
    void interface_tech_avail(Item_Avail**, short*, short);
};

class RGE_PlayerExt : public RGE_Player {
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1f;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    char gap_02e[2];
    RGE_Sound** sounds;
    short sprite_num;
    char gap_036[2];
    void* sprites;
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
    char gap_7E[0x86];

    virtual unsigned char update();
    void pause(unsigned char);
};

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;
    char gap_108[0x14];
    union {
        unsigned char score_displayed;
        unsigned char countdown_victory;
    };
    unsigned char controllingComputerPlayer;
    char gap_11E[2];
    int sent_zone_score;
    int victory_type;
    union {
        TRIBE_Command* command;
        TRIBE_Command* commands;
    };
    struct WorldInfo {
        int cheat_visibility_flag;
    };
    WorldInfo* info;
    int show_score;

    class FogState {
    public:
        int fog_of_war;
    };
    FogState* fog_state;

    void send_zone_score_info();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    void set_game_mode(int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    char* get_string(int, int, int, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);

    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x0c];
    int prog_active;
    char gap_1c[0x34];
    union {
        TDrawArea* draw_area;
        unsigned char outline_type;
    };
    char gap_54[0x0c];
    TSound_Driver* sound_system;
    char gap_64[0x14c];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    char gap_1c0[0x18];
    int input_enabled;
    char gap_1dc[0x220];
    RGE_Game_World* world;
    char gap_3fc[0x5d8];
    int display_selected_ids;
    char gap_9dc[0x24];
    int save_paused;
    char gap_a04[0x1c];
    void* map_save_area;
    int quick_build;

    int multiplayerGame();
    int allowCheatCodes();
    void enable_input();
    void set_font(int, int);
    void request_pause(int);
    void request_pause();
    void set_game_speed(float);
    void build_mode(int, int);
    int language(int);
    char* language(int, int, int, char*, int);
    int singlePlayerGame();
    int numberPlayers();
    int playerID(int);
    unsigned long get_last_single_time(int);
    int get_last_world_update_count();
    unsigned long get_last_time(int);
    void set_last_single_time(int, unsigned long);
    void add_to_timing(int, unsigned long);
    void increment_world_update_count();
    TRIBE_Player* get_player();
    RGE_Player* get_player(void***, short*, int, int, int, int);
    TRIBE_Player* get_player(int, short*);
    TRIBE_Player* get_player(int);
    RGE_Font* get_font(int);
    int get_paused();
    void set_windows_mouse(int);
    void set_map_visible(int);
    void set_map_fog(int);
    void set_paused(int, int);
    void close();
    void draw_window();
    void close_game_screens(int);
    void do_game_over();
    TDigital* get_sound(int);
    int gameDeveloperMode();
    unsigned char check_prog_argument(const char*);
    void dump_memory_usage(char*);
    void goto_notification_loc();
    void* prog_window;
    void get_mouse_pos(tagPOINT);
    void set_font(int);
    int master_obj_id;
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    int get_countdown_timer(int, int*);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x200];
    int show_object_id;
    unsigned long auto_exit_time;
    void restart_game();
    void goto_notification_loc();
    void show_status_message(char*, char*, long);
    void close_status_message();
    void quit_game();
};

class TPanelSystem {
public:
    TPanel* currentPanel();
    TPanel* mouseOwner();
    TPanel* panel(char*);
    TPanel* modalPanel();
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
};

class TCommunications_Speed {
public:
    char gap_00[0x1bc];
    union {
        unsigned long PlayerAvgFramesMsec[10];
        unsigned long player_avg_frames_msec[10];
    };
    unsigned long GetPlayerLatency(unsigned int);
};

class TCommunications_Handler {
public:
    char gap_00[0x14d4];
    TCommunications_Speed* Speed;
    int WhoAmI();
    int IsHost();
    int Kick(unsigned int);
    int TXDebugPing();
    int GetPlayerHumanity(unsigned int);
    char* GetPlayerName(unsigned int);
    void SendChatMsgAll(const char*);
    void SendIResignMsg();
    void GameOver();
};

class PLAYER_SCORE {
public:
    int comm_id;
    int player_id;
    int team_id;
    long player_score;
    long team_score;
};

struct Item_Avail {
public:
    char* name;
    union {
        short id;
        short master_object_id;
    };
    short pict;
    short inventory_item_1;
    short gap_0a;
    float inventory_cost_1;
    short inventory_item_2;
    short gap_12;
    float inventory_cost_2;
    short inventory_item_3;
    short gap_1a;
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};

typedef Item_Avail BuildingEntry;

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char gap_00[0x26];
    short id;
    unsigned char table[0x100];
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x18];
    long total_points;
    long get_victory_points();
};

class RGE_Object_List {
public:
    void* list;
    short number_of_objects;
    short gap_0a;
};

struct Production_Queue_Record {
    short master_id;
    short unit_count;
};

struct Tech_Tree {
    char* name;
    short gap_04[16];
    short icon;
    unsigned char gap_26[2];
    short build_obj_id;
    short string_id;
    short string_id2;
    unsigned char gap_2e[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

class TRIBE_Tech {
public:
    Tech_Tree* tech_tree;
};

class TRIBE_Player_Tech {
public:
    short get_tech_state(short);
    void tech_cost(short, short*, short*, short*, short*, short*, short*);
    long get_help_message(short);
    long get_help_page(short);
    short get_string_id(short);
    short get_string_id2(short);
    unsigned char get_button_location(short);
    long get_hotkey(short);
};

class TRIBE_Player : public RGE_Player {
public:
    TRIBE_Player_Tech* tech_tree;
    RGE_Static_Object* sel_list[25];
    unsigned char check_obj_cost(short, short*, float, int);
    int artifact_held_time;
    int ruin_held_time;
    void command_building_cancel();
    unsigned char check_tech_cost(short, short*, float, int);
    void command_building_make_tech(short);
    unsigned char check_tech_cost();
    void command_building_make_tech();
    void command_trade_attribute(long);
    void unselect_area();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    long world_x;
    long world_y;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x14];
    RGE_Object_List* objects;
    char gap_28[0x0f];
    unsigned char selected_group;
    char gap_38[0x10];
    unsigned char object_state;
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    unsigned char have_action();
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    char gap_88[0x140];
    Production_Queue_Record* production_queue;
    short production_queue_size;
    short production_queue_count;
    unsigned char production_queue_enabled;
    unsigned char production_queue_change_flag;
    unsigned char production_queue_auto_paused;
    unsigned char production_queue_need_attr;
    long build_pts;
    long unique_build_id;
    unsigned char culture;
    unsigned char built;
    char gap_1e6[0x0e];
    int work_status(short&, short&, short&, char*, short);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[4];
    char* name;
    short string_id;
    short string_id2;
    short id;
    char gap_12[0x7d];
    unsigned char unit_level;
    char gap_90[0x0c];
    long help_page_id;
    long hotkey_id;
    char gap_a4[0x14];
    unsigned char building_connect_flag;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x60];
    float area_effect_range;
    char gap_11c[8];
    short missile_id;
    char gap_126[0x22];
    unsigned char button_location;
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    short building_facet;
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x60];
    float area_effect_range;
    char gap_11c[8];
    short missile_id;
};

class TDebuggingLog {
public:
    static void Log(TDebuggingLog*, const char*, ...);
    void Log(const char*, ...);
};

class TChat {
public:
    char* GetChatMsg(int);
};

class TribeSaveGameScreen {
public:
    char gap_00[0x6a4];
    TribeSaveGameScreen(int, char*, int);
};

class TribeLoadSavedGameScreen {
public:
    char gap_00[0x494];
    TribeLoadSavedGameScreen();
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    TShape* game_screen_pic;
    TShape* button_border1_pic;
    TShape* button_other_pic;
    TShape* button_border2_pic;
    TShape* button_border3_pic;
    TShape* button_cmd_pic;
    TShape* button_tech_pic;
    TShape* button_unit_pic;
    TShape* button_bldg_pics[5];
    TShape* more_cancel_pic;
    short more_frame;
    short cancel_frame;
    short unselect_frame;
    char gap_4b6[2];
    TRIBE_Main_View* main_view;
    TPanel* map_view;
    TPanel* inven_panel;
    TRIBE_Panel_Object* object_panel;
    TRIBE_Panel_Button* button_panel[17];
    TPanel* text_line_panel;
    TTextPanel* quit_message_panel;
    TRIBE_Panel_Time* time_panel;
    TRIBE_Panel_Time* countdown_clock[10];
    TPanel* pop_panel;
    union {
        struct {
            TMessagePanel* message_panel;
            TMessagePanel* message_panel2;
            TMessagePanel* message_panel3;
            TMessagePanel* message_panel4;
            TMessagePanel* message_panel5;
            TMessagePanel* message_panel6;
        };
        struct {
            TMessagePanel* msg_panel_0;
            TMessagePanel* msg_panel_1;
            TMessagePanel* msg_panel_2;
            TMessagePanel* msg_panel_3;
            TMessagePanel* msg_panel_4;
            TMessagePanel* msg_panel_5;
        };
        struct {
            TMessagePanel* message_panel1;
            TMessagePanel* message_panel2_alt;
            TMessagePanel* message_panel3_alt;
            TMessagePanel* message_panel4_alt;
            TMessagePanel* message_panel5_alt;
            TMessagePanel* message_panel6_alt;
        };
        struct {
            TMessagePanel* ai_panel_1;
            TMessagePanel* ai_panel_2;
            TMessagePanel* ai_panel_3;
            TMessagePanel* ai_panel_4;
            TMessagePanel* ai_panel_5;
            TMessagePanel* ai_panel_6;
        };
        TMessagePanel* message_panels_at_544[6];
    };
    union {
        TPanel* chat_panel[8];
        TMessagePanel* message_panels[8];
    };
    RGE_Panel_Tool_Box* tool_box;
    TPanel* age_panel;
    TTextPanel* pause_text;
    TTextPanel* fps_panel;
    TMessagePanel* score_panel[8];
    TTextPanel* log_text;
    TScrollBarPanel* log_scrollbar;
    union {
        TRIBE_World* world;
        void* comm_handler;
    };
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;
    RGE_Static_Object* game_obj;
    short sel_count;
    char gap_5ce[2];
    Item_Avail* tech_list;
    Item_Avail* make_list;
    Item_Avail* bldg_list;
    Trade_Avail* trade_list;
    short item_cnt;
    short start_item;
    short last_item;
    char gap_5e6[0x92];
    unsigned long terrain_sound_interval;
    unsigned long last_terrain_sound_time;
    RGE_Sound* terrain_sound;
    int terrain_playing;
    unsigned long terrain_sound_start_time;
    char gap_68c[4];
    unsigned long anim_pal_interval;
    unsigned long last_anim_pal_time;
    short last_anim_pal_index;
    short last_anim_pal_index2;
    short last_anim_pal_index3;
    struct AnimPalEntry {
        unsigned char red;
        unsigned char green;
        unsigned char blue;
    };
    AnimPalEntry anim_pal_table[7];
    char gap_6b3[0x55];
    union {
        long mouse_last_x;
        long last_mouse_x;
    };
    union {
        long mouse_last_y;
        long last_mouse_y;
    };
    union {
        struct {
            int save_age;
            int save_culture;
            long save_screen_width;
            unsigned long game_over_time;
            int showing_game_over;
            union {
                int chat_line;
                int next_chat_panel;
                int message_index;
            };
            unsigned long view_interval;
            unsigned long last_view_time;
            union {
                int player_quit;
                int resign_flag;
            };
            char gap_734[0x70];
            int reset_after_update;
            unsigned long score_interval;
            unsigned long last_score_time;
            int watch_mode;
            int game_ended;
            union {
                TDigital* game_over_sound;
                TDigital* sound_system;
            };
        };
        struct {
            char gap_710[0x24];
            int key_buffer_length;
            char key_buffer[0x34];
            int select_building_key;
            int work_key;
            int move_key;
            int attack_key;
            int ungroup_key;
            char gap_780[4];
            int building_hotkeys[8];
        };
    };

    TRIBE_Screen_Game();
    virtual ~TRIBE_Screen_Game();
    void draw();

protected:
    void handle_anim_pal();
    void handle_terrain_sound();

public:
    long handle_size(long, long);
    void handle_game_update();
    long key_down_action(long, short, int, int, int);
    long action(TPanel*, long, unsigned long, unsigned long);
protected:
    void do_button_action(int, int, int);

public:
    void setup_buttons();
    void reset_score_display();
    void player_changed(int, int);
    void reset_clocks();
protected:
    void command_score(int);
    void command_group_by_number(int);
    void command_select_group(int, int);
    void command_formation(int);
    void command_tab_selected(int);
    void command_view_selected();
    void command_building(int);
    void command_select_building(int);
    void command_player(int);
    void command_add_attribute(int);
    void command_tool_box();
    void command_quick_build();
    void command_work();
    void command_move();
    void command_attack();
    void command_ungroup();
    void command_fps();
    void command_visibility();
    void command_fog_of_war();
    void command_comm_info();
    void command_ai_info();
    void command_quick_chat();
    void command_cancel_building();
    void command_cancel();
    void command_unselect();

protected:
    void object_changed();
    void age_changed();

protected:
    int any_selected_have_action();

public:
    void disable_unused_buttons();

protected:
    char* calc_text_msg(char*, Item_Avail*, long, long);
    short calc_button_loc(unsigned char);
    void set_button(TShape*, short, short, long, long, long, long, long,
                    unsigned char*, char*, char*, int);

public:
    virtual void set_redraw(TPanel::RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*,
                                       TPanel::RedrawMode);
    void set_map_buttons_redraw(TPanel::RedrawMode);
    long handle_paint();
    long handle_idle();
    long wnd_proc(void*, unsigned int, unsigned int, long);
    long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_user_command(unsigned int, long);
    void handle_pause();
    void handle_resume();
    void handleChatReceived(int);

protected:
    void handle_mouse_pointing_at();

public:
    void display_system_message(char*);
    long char_action(long, short);
    void show_timings(char*, char*);
    void show_comm(char*, char*, char*, char*, char*, char*);
    void show_ai(char*, char*, char*, char*, char*, char*);
    void show_message(TMessagePanel::MessageType, char*, unsigned char,
                      unsigned char);
    void reset_buttons();
    void game_mode_changed(int, int);
protected:
    void command_game_speed(int);

public:
    void set_info_file(char*);
    void set_info_file(char*, long);
    void set_popup_info_file(char*);
    void set_popup_info_file(char*, long);
    void set_button_pics();
    void set_button_pics(char*, long);
    void set_bevel_colors(int, int, int, int, int, int);
    int bevel_color1;
    int bevel_color2;
    int bevel_color3;
    int bevel_color4;
    int bevel_color5;
    int bevel_color6;

protected:
    void command_build();
    void command_chat();
    void command_repair();
    void command_heal();
    void command_convert();
    void command_diplomacy();
    void command_research(int);
    int popup_help_flag;
    void clear_popup_help();
    void command_save_game();
    void command_save_scenario();
    void command_stop();
    void command_trade();
    void command_trade_with(int);
    void command_train(int, short);
    void command_unload();
    void command_view_tribe();
    void command_outline();
    void command_pause();
    void command_more();
    void command_menu();
    void command_group();
    int field_5E4;
    int field_7B4;
    unsigned long last_pause_time;
    unsigned long last_game_speed_time;
    void command_attack_ground();
    void command_stand_ground();
    void command_trade_attribute(long);
    void command_quit();

protected:
    void stop_sound_system();
    virtual int restart_sound_system();

public:
    void add_log(char*);
    virtual void set_focus(int);
    int field_14;
    int field_18;
};

extern RGE_Base_Game* rge_base_game;
extern int disable_terrain_sounds;
extern int _bPlaying;
extern TPanelSystem panel_system;
extern TCommunications_Handler* comm;
extern TChat* chat;
extern TDebuggingLog* L;
extern int start_paused;
extern int allow_user_commands;
extern int do_fixed_update;
extern int displayPathingFlags;
extern int MapPathsDisplay;
extern int view_debug_spans;
extern int view_debug_redraw_all;
extern int view_debug_ObstructionMap;
extern int view_debug_Objects;
extern int show_timing_max;
extern int view_debug_palette;
extern int View_Grid_Mode;
extern int confirmed_close;
extern int multi_updates;
extern int out_of_sync2;
extern unsigned char die_die_die;
extern unsigned char do_color_log;
extern unsigned char production_queues_is_use;
extern int DAT_0086bac8;
extern char Save_Game_Screen[];
extern char s_Save_Game_Screen[];
extern char s_Game_Screen[];
extern char s_scr6[];
extern char s_scr_game_cpp[];
extern char s_C__msdev_work_age1_x1_scr_game_c[];
extern char s_Send_Quick_Message_Dialog[];
extern char s_Help_Dialog[];
extern char s_won_wav[];
extern char s_lost_wav[];
extern char s_btnunit_shp[];
extern char s_btntech_shp[];
extern char s_btncmd_shp[];
extern char s_btnbldg_d_shp[];
extern char s_bordline[];
extern char s_map_bmp[];
extern char s_[];
extern char s_PAUSE[];
extern const char s_Writing_out_memory_info[];
extern const char s_memory_filename[];
extern const char s_ALLOWCTRLU[];
extern const char s_force_ctrl_u[];

#define rge_base_game_absolute (rge_base_game_at_storage())
#define OFF32(o) (*(int*)((char*)this + (o)))
#define OFFU32(o) (*(unsigned long*)((char*)this + (o)))
#define OFF16(o) (*(short*)((char*)this + (o)))
#define OFF8(o) (*(unsigned char*)((char*)this + (o)))
#define MAIN_VIEW ((TRIBE_Main_View*)OFF32(0x4b8))
#define MAP_VIEW ((TRIBE_Diamond_Map_View*)OFF32(0x4bc))
#define comm (*(TCommunications_Handler**)0x0062c4c0)
#define out_of_sync2 (*(int*)0x0062c564)
#define multi_updates (*(int*)0x00586318)

#define set_command_button(screen, index, frame, type, string_id) \
    (screen)->set_button((screen)->button_cmd_pic, (index), (frame), \
                         (type), 0, (string_id), -1, 0, (unsigned char*)0, \
                         (char*)0, (char*)0, 0)

#endif
