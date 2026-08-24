#ifndef RPNL_TBX_CONTEXT_H
#define RPNL_TBX_CONTEXT_H

#include <string.h>

typedef unsigned char uchar;

class TDrawArea {
public:
    void Clear(struct RectStub*, int);
};

class TDigital;
class TPanel;
class TScreenPanel;
struct RectStub;
class RGE_View;
class RGE_Diamond_Map;
class RGE_Map;
class RGE_Player;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Active_Sprite_List;

struct RectStub {
    int a;
    int b;
    int c;
    int d;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw();
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect();
    virtual void draw_offset();
    virtual void draw_rect2();
    virtual void draw_offset2();
    virtual void paint();
    virtual void wnd_proc();
    virtual void handle_idle();
    virtual void handle_size();
    virtual void handle_paint();
    virtual void handle_key_down();
    virtual void handle_char();
    virtual void handle_command();
    virtual void handle_user_command();
    virtual void handle_timer_command();
    virtual void handle_scroll();
    virtual void handle_mouse_down();
    virtual void handle_mouse_move();
    virtual void handle_mouse_up();
    virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();
    virtual void mouse_left_down_action();
    virtual void mouse_left_hold_action();
    virtual void mouse_left_move_action();
    virtual void mouse_left_up_action();
    virtual void mouse_left_dbl_click_action();
    virtual void mouse_right_down_action();
    virtual void mouse_right_hold_action();
    virtual void mouse_right_move_action();
    virtual void mouse_right_up_action();
    virtual void mouse_right_dbl_click_action();
    virtual long key_down_action(long, short, int, int, int);
    virtual void char_action();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(RectStub*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(unsigned char&, char*, long&, long&, long&);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x1C];
    union {
        TDrawArea* render_area;
        TDrawArea* draw_area;
    };
    RectStub rect;
    char gap_34[0x38];
    int field_6C;
    int field_70;
    char gap_74[0x64];
    int error_code;
    char gap_DC[0x18];

    TPanel();
    char* panelName();
    char* get_string(int);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x2B8 - 0xF4];

    TButtonPanel();
    virtual ~TButtonPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, long,
               TDigital*, long, long);
    void set_text_info(char*, void*, long, long, long, long);
    void set_text(short, char*);
    void set_radio_info(TPanel*, int);
    void set_state_info(short);
    void set_radio_button();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background();
    virtual void set_ideal_size();
    virtual void create_button_number();
    virtual void create_button_text();
    virtual void create_check_box();
    virtual void create_radio_button();
    virtual void create_text_number();
    virtual void create_text_list();
    virtual void create_text();
    virtual void create_input();
    virtual void create_edit();
    virtual void create_drop_down();
    virtual int create_list(TPanel*, void**, long, long, long, long, long);
    virtual void create_scrollbar();
    virtual void create_auto_scrollbar();
    virtual void create_vert_slider();
    virtual void create_horz_slider();
    virtual void position_panel();

    char gap_F4[0x384];

    long get_popup_info_id();
    char* get_popup_info_file();
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_View : public TPanel {
public:
    int get_selection_area(long*, long*, long*, long*, int);
    void set_selection_area(int, int, int, int);
};

class RGE_Diamond_Map : public TPanel {
};

class RGE_Map {
public:
    void set_elev(short, short, short, short, uchar, short, uchar);
    void clean_elevation(long, long, long, long, uchar);
};

class RGE_Game_World {
public:
    char gap_00[0x1C];
    uchar temp_pause;
    char gap_1D[0xB];
    RGE_Map* map;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);

    char gap_14[0x1AC];
    int prog_mode;
    int game_mode;
    char gap_1B8[0x23C];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;

    int get_paused();
    RGE_Player* get_player();
    void delete_dialog(TPanel**);
};

class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj;
    void unselect_object();
};

class RGE_Sprite {
public:
    uchar get_lowest_draw_level();
};

class RGE_Active_Sprite_List {
public:
    uchar get_lowest_draw_level();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
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
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();

    char gap_04[0x0C];
    RGE_Sprite* sprite;
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list;
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
    virtual int setup(TPanel*, TPanel*, long, long, uchar, int);
    virtual int setup(TPanel*, TPanel*, long, long, char*, long, int);

    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;
};

class TListDialog : public TDialogPanel {
public:
    virtual ~TListDialog();
    virtual short get_list_id();
    virtual char* get_list_name();

    void* title;
    void* list;
    void* scroll_bar;
    void* ok_btn;
    void* cancel_btn;
    short list_id;
    char gap_4A6[2];
    char* list_name;
};

struct rdlg_list_info {
    char text[100];
    short id;
};

class RGE_Dialog_List : public TListDialog {
public:
    virtual ~RGE_Dialog_List();
    virtual short get_list_id();
    virtual int create_list();
    virtual short get_cur_id();

    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info* list_info;
    char** list_text;

    RGE_Dialog_List(char*);
    int setup(TScreenPanel*, char*, long, int, char*);
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    virtual ~RGE_Panel_Tool_Box();

    TScreenPanel* screen_panel;
    RGE_View* view;
    RGE_Diamond_Map* map;
    union {
        TButtonPanel* game_mode_button;
        TButtonPanel* field_100;
    };
    union {
        TButtonPanel* object_mode_button;
        TButtonPanel* field_104;
    };
    union {
        TButtonPanel* delete_mode_button;
        TButtonPanel* field_108;
    };
    union {
        TButtonPanel* move_mode_button;
        TButtonPanel* field_10C;
    };
    union {
        TButtonPanel* terrain_mode_button;
        TButtonPanel* field_110;
    };
    union {
        TButtonPanel* elevation_mode_button;
        TButtonPanel* field_114;
    };
    union {
        TButtonPanel* command_button;
        TButtonPanel* field_118;
    };
    TPanel* dialog;

    RGE_Panel_Tool_Box(TDrawArea*, TPanel*, long, long, long, long, void*, long,
                       long, TDigital*, TScreenPanel*, RGE_View*, RGE_Diamond_Map*);
    void game_mode_changed(int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long key_down_action(long, short, int, int, int);
    virtual void draw();
};

extern RGE_Base_Game* rge_base_game;

#endif
