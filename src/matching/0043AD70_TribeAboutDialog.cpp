// VA: 0043AD70 TribeAboutDialog::TribeAboutDialog
// dlg_abt.cpp lines 46-148

// Exact-finish retrospective:
// - The clean prior source was 710 bytes different and 1390 bytes long.
// - Decisive change: inline the xPosition/width result into create_text.
//   This recovered the original 1388-byte layout and all body bytes.
// - Decisive change: use RECT.right for the PID placement coordinate. The original
//   load is [esp+2C], which is the right field in the proven RECT stack view.
// - Required and inseparable: the inline x expression and RECT.right field use.
// - Incidental: duplicate standard headers, the named y and x temporaries,
//   and long pnl_x all reverted without benefit. The final source uses one
//   standard-header pair and direct expressions.
// - Walkback: restoring the x temporary caused 710 differing bytes. Restoring
//   long pnl_x did not change the exact result, so the canonical long field remains.
// - BINARY NOTE: VC5 emits the original code with the direct typed panel ABI.
//   The checker reports MATCH, 0.0000%, 1388/1388 bytes, and 36/36 calls.
// - Policy cleanup: replaced all generic TPanel slots with the named slots 0-55
//   from the same-TU dlg_dip donor. Named TPanel fields now cover +0x04..+0xF3.
// - Policy cleanup: adopted the same-TU TEasy_Panel and TDialogPanel fields,
//   factory ownership, setup overloads, and canonical tagRECT type.
// - Cleanup probes: the first field mapping used pnl_y and differed by 3 bytes.
//   Mapping the proven +0x0C access to pnl_x restored exactness. All later
//   canonical-surface and named-field changes stayed byte-identical.

#include <string.h>
#include <stdio.h>

class TPanel;
class TScreenPanel;
class TTextPanel;
class TButtonPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;

class TDrawArea {
public:
    char gap_000[4];
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct PanelNode;
typedef int PositionMode;
typedef int RedrawMode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
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
    TDrawArea* render_area;
    tagRECT clip_rect;
    PositionMode position_mode;
    RedrawMode need_redraw;
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

    TDrawArea* renderArea();
    int get_string(int id, char* buf, int max_len);
    char* get_string(int id);
    long xPosition();
    long width();
    void delete_panel(TPanel** panel_ptr);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, int, long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TTextPanel*, long, long, long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long, long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    void* background_pic;
    void* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char gradient_color_0;
    unsigned char gradient_color_1;
    unsigned char gradient_color_2;
    unsigned char gradient_color_3;
    unsigned char gradient_color_4;
    unsigned char gradient_color_5;
    char _gap_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    void* button_pics;
    void* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    char _gap_456[2];
    int enable_ime;
    unsigned char help_mode;
    char _gap_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    void* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    long get_popup_info_id();
    char* get_popup_info_file();
    long action(TPanel*, long, unsigned long, unsigned long);
};

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;
    TDialogPanel(char* name);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, unsigned char, int);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char _gap_F4[0x94];
    int get_text_rect(void* rect);
};

class TPicturePanel : public TPanel {
public:
    char gap_F4[0x28];
    virtual ~TPicturePanel();
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long y, long p4, long p5, long p6, char* name, long p8, int p9, int p10);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TRegistry {
public:
    char* RegGetAscii(int param_1, char* key);
};

extern TRegistry* Regs;

class TribeAboutDialog : public TDialogPanel {
public:
    TTextPanel* title_text;
    TTextPanel* version_text;
    TTextPanel* ms_copy_text1;
    TTextPanel* ms_copy_text2;
    TTextPanel* ens_copy_text;
    TTextPanel* genie_copy_text;
    TTextPanel* pid_label_text;
    TTextPanel* pid_text;
    TTextPanel* warning_text;
    TTextPanel* background;
    TButtonPanel* credits_button;
    TButtonPanel* close_button;
    TPicturePanel* circle_p_pic;

    TribeAboutDialog(TScreenPanel* param_1);
    virtual ~TribeAboutDialog();
protected:
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
public:
    void draw();
};

TribeAboutDialog::TribeAboutDialog(TScreenPanel* param_1) : TDialogPanel("About Dialog") {
    // Stack buffers
    char temp_str[512];
    char str[4096];
    tagRECT rect;

    int modal = 1;
    title_text = 0;
    version_text = 0;
    ms_copy_text1 = 0;
    ms_copy_text2 = 0;
    ens_copy_text = 0;
    genie_copy_text = 0;
    pid_label_text = 0;
    pid_text = 0;
    warning_text = 0;
    credits_button = 0;
    close_button = 0;
    circle_p_pic = 0;
    background = 0;

    if (!TDialogPanel::setup(param_1->renderArea(), param_1, 0x208, 0x19c,
                             param_1->get_popup_info_file(),
                             param_1->get_popup_info_id(), modal))
        return;

    TEasy_Panel::create_text(this, &background, "", 10, 10, 500, 0x15e, 4, 0, 0, 0);

    background->set_bevel_info(3, gradient_color_0, gradient_color_1,
                                gradient_color_2, gradient_color_3,
                                gradient_color_4, gradient_color_5);

    TEasy_Panel::create_text(this, &title_text, 0x2419, 0x14, 0x14, 0x1e0, 0x14, 4, 0, 0, 0);
    TEasy_Panel::create_text(this, &version_text, 0x241a, 0x14, 0x28, 0x1e0, 0x14, 0xb, 0, 0, 0);

    TPanel::get_string(0x2424, temp_str, 0x200);
    if (temp_str[0] == '\0') {
        TEasy_Panel::create_text(this, &ms_copy_text1, 0x241b, 0x14, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);

        if (ms_copy_text1) {
            if (ms_copy_text1->get_text_rect(&rect)) {
                circle_p_pic = new TPicturePanel();
                if (circle_p_pic) {
                    circle_p_pic->setup(render_area, this, (rect.right - pnl_x) + 3,
                                        0x42, 0xf, 0xe, "circlep", 0xc4e0, 0, 1);
                    // BINARY NOTE: Keep this result expression inline for VC5's original call order.
                    TEasy_Panel::create_text(this, &ms_copy_text2, 0x241c,
                                             circle_p_pic->xPosition() - pnl_x + circle_p_pic->width(),
                                             0x41, 0x1e0, 0x14, 10, 0, 0, 0);
                }
            }
        }
    } else {
        strcpy(temp_str, TPanel::get_string(0x241b));
        strcat(temp_str, TPanel::get_string(0x2424));
        strcat(temp_str, " ");
        strcat(temp_str, TPanel::get_string(0x241c));
        TEasy_Panel::create_text(this, &ms_copy_text1, temp_str, 0x14, 0x41, 0x1e0, 0x14, 10, 0, 0, 0);
    }

    TEasy_Panel::create_text(this, &ens_copy_text, 0x241d, 0x14, 0x55, 0x1e0, 0x14, 10, 0, 0, 0);
    TEasy_Panel::create_text(this, &genie_copy_text, 0x2423, 0x14, 0x69, 0x1e0, 0x28, 10, 0, 0, 1);
    TEasy_Panel::create_text(this, &pid_label_text, 0x241e, 0x14, 0x96, 0x5f, 0x14, 10, 0, 0, 0);

    if (pid_label_text) {
        if (pid_label_text->get_text_rect(&rect)) {
            char* pid_str = Regs->RegGetAscii(0, "PID");
            if (!pid_str) pid_str = "00000-000-0000000-00000";
            sprintf(str, "%s", pid_str);
            // BINARY NOTE: The shipped code uses RECT.right for this placement coordinate.
            // LIKELY INTENT: Place the product ID text to the right of its label.
            TEasy_Panel::create_text(this, &pid_text, str,
                                     (rect.right - pnl_x) + 4,
                                     0x96, 200, 0x14, 0xb, 0, 0, 0);
        }
    }

    TPanel::get_string(0x241f, str, 0x1000);
    TEasy_Panel::create_text(this, &warning_text, str, 0x14, 0xaf, 0x1e0, 0xdc, 10, 0, 0, 1);

    TEasy_Panel::create_button(this, &credits_button, 0x2420, 0, 0x46, 0x172, 0xaa, 0x1e, 0, 0, 0);
    TEasy_Panel::create_button(this, &close_button, 0x2421, 0, 0x118, 0x172, 0xaa, 0x1e, 0, 0, 0);

    TButtonPanel* cb = close_button;
    cb->hotkey = 0x1b;
    cb->hotkey_shift = 0;

    TPanel* tabs[2];
    tabs[0] = credits_button;
    tabs[1] = close_button;
    TPanel::set_tab_order(tabs, 2);
    TPanel::set_curr_child(credits_button);
}
