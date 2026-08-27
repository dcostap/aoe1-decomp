// Canonical period surface for the Pnl_drop.cpp translation unit.
// Ownership and offsets follow the reviewed panel type evidence.

#ifndef AOE1_PNL_DROP_H
#define AOE1_PNL_DROP_H

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
struct PanelNode;
class TShape;
class TDigital;
class TTextPanel;
class TButtonPanel;
class TListPanel;
class TScrollBarPanel;
class TDropDownPanel;
class TPanel;

struct TDrawArea {
    void* DrawSystem;
    void* Wnd;
    char gap_08[0x10];
    long Width;
    long Height;
};

enum PositionMode {
    PositionFixed = 0,
    PositionCentered = 2,
    PositionLeft = 3,
    PositionTop = 4,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10
};

class TPanelSystem {
public:
    TPanel* mouseOwner();
    TPanel* keyboardOwner();
    TPanel* modalPanel();
    int GetInputEnabled();
    void setModalPanel(TPanel*);
    int restorePreviousModalPanel();
};

class TPanel {
public:
    // BINARY NOTE: Pnl_drop constructors call the real TPanel base constructor.
    TPanel();
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
    long z_order;
    long display_changed_count;
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

    void delete_panel(TPanel**);
    void set_curr_child(TPanel*);
    void set_z_order(int, int);
    void redraw(int);
    void refresh_values(int, int);
    long width() const;
    long xPosition() const;
    long yPosition() const;
    long height() const;
};

extern TPanelSystem panel_system;

class TButtonPanel : public TPanel {
public:
    enum DrawType { DrawBevelPicture = 6 };
    enum NotifyType { NotifyAction = 1 };
    long id[9];
    long id2[9];
    int buttonTypeValue;
    int drawTypeValue;
    int notifyTypeValue;
    TDigital* sound;
    TShape* pic[9];
    short pic_index[9];
    unsigned char _pad_0[2];
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
    unsigned char _pad_1[2];
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
    unsigned char _pad_2[2];
    long key_down;
    int disabled;
    int sound_number;

    virtual ~TButtonPanel();
    TButtonPanel();
    void set_picture(short, TShape*, short);
    void set_bevel_info(int, int, int, int, int, int, int);
    long setup(TDrawArea*, TPanel*, long, long, long, long, DrawType, TDigital*, NotifyType, long);
};

class TTextPanel : public TPanel {
public:
    class TextNode;
    TextNode* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    int vert_align;
    int horz_align;
    int word_wrap;
    int text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    unsigned char _pad_0[2];
    long text_wid;
    long text_hgt;
    TShape* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    unsigned char _pad_1[3];
    int outline;
    unsigned char outline_color;
    unsigned char _pad_2[3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char _pad_3[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;

    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    // BINARY NOTE: exact TTextPanel donors place these overloads at +E0/+E4/+E8.
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, int,
               unsigned char, int, unsigned char, short, char*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long, char*, int,
               unsigned char, int, unsigned char, short, char**, short);
    void set_alignment(int, int);
    void set_scrollbar(TScrollBarPanel*, int);
    void setCurrentLineNumber(int);
    void set_line_by_id(int);
    long set_line(long);
    long get_line();
    long get_line(long);
    long get_line(char*);
    char* get_text(int);
    char* get_text(long);
    int numberLines();
    int numberDrawLines();
    int append_line(char*, long);
    int append_line(long, long);
    int insert_line(long, char*, long);
    int insert_line(long, long, long);
    void empty_list();
    void set_outline(int, unsigned char);
    void set_text_color(unsigned long, unsigned long);
    int currentLineNumber();
    char* currentLine();
    void refresh_values(int, int);
    long get_id();
    long get_id(long);
    char* get_text();
    int delete_line(long);
};

class TListPanel : public TTextPanel {
public:
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual int is_inside(long, long);
    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
    TListPanel();
    void set_auto_track(int);
    long handle_mouse_down(long, long);
};

class TScrollBarPanel : public TPanel {
public:
    enum Orientation { Vertical = 0, Horizontal = 1 };
    TPanel* list_panel;
    long list_len;
    long one_step;
    long page_step;
    long list_num;
    TShape* button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;
    long arrowSize;
    long tabSize;
    long tab_y;
    long tab_min_y;
    long tab_max_y;
    long tab_mouse_y;
    long tab_x;
    long tab_min_x;
    long tab_max_x;
    long tab_mouse_x;
    unsigned char item_down;
    unsigned char _pad_0[3];
    int item_is_down;
    long item_x;
    long item_y;
    unsigned char item_mode;
    unsigned char _pad_1[3];
    unsigned long item_last_time;
    unsigned long item_hold_interval;
    unsigned long item_down_interval;
    tagRECT up_rect;
    tagRECT down_rect;
    tagRECT tab_rect;
    tagRECT top_rect;
    tagRECT bottom_rect;
    int orientation;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char _pad_end[2];
    virtual int is_inside(long, long);
    TScrollBarPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, char*, char*, char*, char*, long, long,
               TPanel*, long, Orientation);
    void set_buttons(TShape*, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    long handle_mouse_down(long, long);
};

class TParentPanel : public TPanel {
public:
    long notify_action(TPanel*, long, unsigned long, unsigned long);
};

class TDropDownPanel : public TPanel {
public:
    enum DrawStyle {
        DrawStyleDefault = 0,
        DrawStyleLeftButton = 1
    };

    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    TScrollBarPanel* scbar_panel;
    int mode;
    short val_num;
    unsigned char val_num_padding[2];
    long val_wid;
    long val_hgt;
    long btn_wid;
    long btn_hgt;
    long list_wid;
    long list_hgt;
    long scbar_wid;
    long scbar_arrow_hgt;
    long scbar_tab_hgt;
    unsigned char list_is_above;
    unsigned char list_is_above_padding[3];
    long font_hgt;
    int outline_color;
    int draw_style;
    int draw_val_rect;

    enum DropdownMode { ModeNone = 0, ModeValue = 1, ModeList = 2 };

    TDropDownPanel();
    virtual ~TDropDownPanel();
    virtual void draw();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_key_down(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_rect(long, long, long, long);
    virtual long handle_mouse_move(long, long, int, int);
    long setup(TDrawArea*, TPanel*, void*, long, long, int, unsigned char, int, unsigned char,
               long, long, long, long, short, short, long, long, char*, long, long, char**, short,
               long, char*, char*, char*, char*, long, long);
    void set_val_text_color(unsigned long, unsigned long);
    void set_draw_style(DrawStyle);
    void set_draw_val_rect(int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_mode(DropdownMode);
    int numberLines();
    int currentLineNumber();
    void setCurrentLineNumber(int);
    void setCurrentLineId(int);
    char* currentLine();
    void set_tab_order(TPanel*, TPanel*);
    void set_sorted(int);
    int get_sorted();
    void set_line(long);
    int append_line(char*, long);
    int append_line(long, long);
    int insert_line(long, char*, long);
    int insert_line(long, long, long);
    int delete_line(long);
    long get_line();
    long get_line(long);
    long get_line(char*);
    char* get_text();
    char* get_text(long);
    long get_id();
    long get_id(long);
    void empty_list();
    void target_func(int);
};

class TDropDownButtonPanel : public TButtonPanel {
public:
    TDropDownPanel* drop_down_panel;
    TDropDownButtonPanel(TDropDownPanel*);
    virtual long handle_mouse_move(long, long, int, int);
};

extern char s_[];

#endif
