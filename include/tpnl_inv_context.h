#ifndef AOE1_TPNL_INV_CONTEXT_H
#define AOE1_TPNL_INV_CONTEXT_H

// Authentic source module: C:\\msdev\\work\\age1_x1\\tpnl_inv.cpp.
// This header carries the reviewed game and inventory-panel surfaces for the
// PDB-ordered owner wrapper.  The normal module uses config/flags/default.rsp.

#if !defined(_WINDEF_) && !defined(_WINDOWS_)
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif

struct PanelNode;

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;

    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

typedef char tpnl_inv_tdrawarea_size_check[
    (sizeof(TDrawArea) == 0x3C) ? 1 : -1];

class TShape {
public:
    ~TShape();
};

class TPanel {
public:
    enum RedrawMode { NoRedraw = 0, Redraw = 1, RedrawFull = 2 };

    virtual ~TPanel();
    TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
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

    char* get_string(int string_id);
};

typedef char tpnl_inv_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

extern int TRIBE_Panel_Inven_vftable[];

extern "C" void __cdecl free(void*);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" long __cdecl __ftol(void);

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

    char gap_04[0x1E];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    void* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
    union {
        short attribute_num;
        short field_4C;
    };
    unsigned char gap_4E[2];
    union {
        float* attributes;
        float* float_values;
        float* field_50;
    };
};

class TRIBE_Player : public RGE_Player {
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
};

extern RGE_Base_Game* rge_base_game;

class TShape;

class TRIBE_Panel_Inven : public TPanel {
public:
    TShape* pics;                    // +0xF4
    TRIBE_Player* player;            // +0xF8
    short save_attr_num;             // +0xFC
    unsigned char gap_FE[2];
    short* save_attr;                // +0x100
    unsigned long idle_time;         // +0x104
    unsigned long idle_interval;     // +0x108
    void* font;                      // +0x10C
    unsigned long font_color;        // +0x110
    unsigned long back_color;        // +0x114

    TRIBE_Panel_Inven(TDrawArea*, TPanel*, void*, TRIBE_Player*);
    virtual ~TRIBE_Panel_Inven();
    virtual unsigned char get_help_info(char*& out_str, long& out_val,
                                        long x, long y);
    void set_text_color(unsigned long color1, unsigned long color2);
    virtual void draw();
    virtual long handle_idle();
    void save_info();
    void set_player(TRIBE_Player*);
};

typedef char tpnl_inv_panel_size_check[
    (sizeof(TRIBE_Panel_Inven) == 0x118) ? 1 : -1];

#endif
