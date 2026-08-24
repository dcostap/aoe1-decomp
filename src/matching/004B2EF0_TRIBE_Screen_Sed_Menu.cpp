// TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu constructor
// VA: 004B2EF0
// PDB: scr_sedm.cpp:41-86
// FLAGS: /GX (EH-framed constructor)
//
// Attempt log:
// - The first natural source had the correct 504-byte boundary and 14 calls,
//   but it differed in the constructor initialization schedule.
// - Pointer aliases, a title member initializer, and success-only null stores
//   did not match. They changed size or block layout.
// - A loop over all four real button slots produced the original VC5 store
//   schedule. The loop is period-plausible and preserves typed ownership.
// - The inherited setup-error field is typed at +0xD8. Its tail padding keeps
//   TPanel at 0xF4 and preserves all derived field offsets.
// - The close button uses the reviewed long-ID create_button overload. The
//   other buttons use the text overload. Both overloads emit the same calls.
// - TPanel's inherited virtual slots identify the close-button calls as
//   set_active and set_positioning. TButtonPanel adds no virtual slots here.
// - Exact result: 504 bytes, 158 instructions, 14/14 ordered calls, and
//   22/22 compatible relocations masked. Strict diff is 0 bytes.

#ifndef SCR_SEDM_TU
#include "..\..\include\game_globals.h"
#include <string.h>

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class PanelNode;
class TDigital;
class TShape;
class RGE_Color_Table;

// --- Canonical panel hierarchy declarations ---

class TPanel {
public:
    TPanel(char* name = 0);
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
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
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);
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

    void delete_panel(TPanel** panel);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char pad_456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char pad_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;
    void set_ideal_size(long w, long h);
    int create_text(TPanel* parent, TTextPanel** out, long langId, long x, long y, long w, long h,
                    long a8, long a9, long a10, long a11);
    int create_button(TPanel* parent, TButtonPanel** out, char* name, char* label,
                      long x, long y, long w, long h,
                      long a9, long a10, long a11);
    int create_button(TPanel* parent, TButtonPanel** out, long name, long label,
                      long x, long y, long w, long h,
                      long a9, long a10, long a11);
};

class TTextPanel : public TPanel {
public:
};

class TButtonPanel : public TPanel {
public:
    long id[9];
    long id2[9];
    int buttonTypeValue;
    int drawTypeValue;
    int notifyTypeValue;
    TDigital* sound;
    TShape* pic[9];
    short pic_index[9];
    unsigned char pad_182[2];
    int auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;
    int draw_reverse;
    char* text1[9];
    char* text2[9];
    long text_x;
    long text_y;
    void* font;
    long font_wid;
    long font_hgt;
    short num_states;
    short cur_state;
    int is_down;
    TButtonPanel** radio_buttons;
    short num_radio_buttons;
    unsigned char pad_202[2];
    unsigned long button_down_time;
    unsigned long text_color1[9];
    unsigned long text_color2[9];
    unsigned long highlight_text_color1[9];
    unsigned long highlight_text_color2[9];
    long hotkey;
    int hotkey_shift;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_2AA[2];
    long key_down;
    int disabled;
    int sound_number;

    void set_text(short param1, long langId);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    long setup(TDrawArea*, char*, long, int);
    ~TScreenPanel();
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
};

extern RGE_Base_Game* rge_base_game;
extern char s_Scenario_Editor_Menu[];
extern char s_scr4[];
extern char s_empty[];

class TRIBE_Screen_Sed_Menu : public TScreenPanel {
public:
    TTextPanel* title;
    TButtonPanel* button[4];
    TButtonPanel* close_button;

    virtual long handle_idle();
    virtual long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);

    TRIBE_Screen_Sed_Menu();
    virtual ~TRIBE_Screen_Sed_Menu();
};
#endif

TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu()
    : TScreenPanel(s_Scenario_Editor_Menu)
{
    title = 0;
    for (int j = 0; j < 4; j++)
        button[j] = 0;
    close_button = 0;

    if (!setup(rge_base_game->draw_area, s_scr4, 0xC386, 1)) {
        error_code = 1;
        return;
    }

    set_ideal_size(0x280, 0x1E0);

    if (!create_text(this, &title, 0x242D, 0x14, 0x14, 0x258, 0x1E, 1, 1, 0, 0))
        return;

    for (int i = 0; i < 4; i++) {
        if (!create_button(this, &button[i], s_empty, (char*)0,
                           0xAA, 0xAA + i * 0x32, 0x12C, 0x28, 0, 0, 0))
            return;
    }

    if (!create_button(this, &close_button, 0x3EA, 0,
                       0, 0, 0, 0, -1, -1, 0))
        return;

    close_button->set_active(1);
    close_button->set_positioning(9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, 0, 0, 0, 0);

    button[0]->set_text(0, 0x242E);
    button[1]->set_text(0, 0x242F);
    button[2]->set_text(0, 0x2431);
    button[3]->set_text(0, 0x2430);

    TButtonPanel* cancel = button[3];
    cancel->hotkey = 0x1B;
    cancel->hotkey_shift = 0;

    set_tab_order((TPanel**)button, 4);
    set_curr_child(button[0]);
}
