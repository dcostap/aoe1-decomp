// VA: 004736F0 TButtonPanel::key_down_action (359 B)
// PDB source: Pnl_btn.cpp
//
// Attempt log:
// - Baseline reconstruction uses the period panel/button ownership: TPanel's
//   tab-order fields, TButtonPanel's key/button state, TDigital sound
//   playback, and the panel action virtual at +0xB4.  The four-key dispatch is
//   expressed as an ordinary switch with one shared tab-child tail.
// - Main-agent audit confirmed canonical panel/button/sound ownership and
//   natural shared-tail switch flow; exact bytes were revalidated.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

#ifndef PNL_BTN_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

class TDrawArea;
class TButtonPanel;

#ifndef PNL_BTN_SHARED_CONTEXT
class TDigital {
public:
    int is_playing(void);
    void stop(void);
    int play(void);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    VPAD4(1)
    VPAD2(5)
    VPAD1(7)
    virtual void set_redraw(int mode);
    VPAD32(9)
    VPAD4(41)
    virtual long action(TButtonPanel* panel, long code, long id, long id2);

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
    void* node;
    void* first_child_node;
    void* last_child_node;
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

    void set_curr_child(TPanel* child);
    long handle_key_down(long key, short ch, int a3, int a4, int a5);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel : public TPanel {
public:
    long id[9];
    long id2[9];
    int buttonTypeValue;
    int drawTypeValue;
    int notifyTypeValue;
    TDigital* sound;
    void* pic[9];
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

    long key_down_action(long key, short ch, int a3, int a4, int a5);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::key_down_action(long key, short ch, int a3, int a4, int a5) {
    TPanel* child;

    if (key_down != 0) {
        return 0;
    }

    switch (key) {
    case 0x28:
        if (a3 == 0 && a4 == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_next_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case 0x26:
        if (a3 == 0 && a4 == 0 && tab_stop != 0 && parent_panel != 0) {
            child = tab_prev_panel;
            if (child != 0) {
                parent_panel->set_curr_child(child);
            }
        }
        return 1;

    case 0x0D:
    case 0x20:
        if (disabled != 0 || a3 != 0 || a4 != 0) {
            break;
        }
        if (sound != 0) {
            if (sound->is_playing() != 0) {
                sound->stop();
            }
            sound->play();
        }
        key_down = key;
        is_down = 1;
        button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x44B);
        set_redraw(1);
        if (parent_panel != 0) {
            parent_panel->action(this, 2, id[cur_state], id2[cur_state]);
        }
        return 1;

    default:
        break;
    }
    return 0;
}
