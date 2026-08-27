#ifndef AOE1_PNL_INP_H
#define AOE1_PNL_INP_H

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long ulong;

typedef void* HWND;
typedef void* HANDLE;
typedef void* HDC;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;

struct PanelNode;
struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next_node;
};

class TDrawArea {
public:
    void* inst;
    void* Wnd;
    char gap_08[0x100 - 0x08];

    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
    uchar* Lock(const char* name, int flag);
    void Unlock(const char* name);
    void DrawVertLine(int x, int y, int h, uchar color);
};

class TDigital {
public:
    int play();
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                  long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void set_text(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
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
    ulong mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char*);

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
    ulong text_color1;
    ulong text_color2;
    ulong highlightTextColor1;
    ulong highlightTextColor2;
    void* scbar_panel;
    int auto_scbar;
    short fixed_len;
    uchar pad_13A[2];
    long text_wid;
    long text_hgt;
    void* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    uchar back_color;
    uchar pad_151[3];
    int outline;
    uchar outline_color;
    uchar pad_159[3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    uchar pad_17A[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;

    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, uchar, int, uchar, short, char*);
    void set_alignment(int, int);
    void set_word_wrap(int);
    void draw();
    void calc_line_pos(void*, short, short, tagRECT*, int*);
    char* get_text();
    char* get_text(int);
    void scroll(uchar, uchar, int);
    char* currentLine();
};

class TInputPanel : public TTextPanel {
public:
    enum FormatType {
        FormatSingleLine = 0,
        FormatNumber = 1,
        FormatInteger = 2,
        FormatUnsignedInt = 3,
        FormatFile = 4,
        FormatFileNoExt = 5,
        FormatPath = 6,
        FormatMultiLine = 7,
        FormatPercent = 8
    };

    TInputPanel();
    virtual ~TInputPanel();

    uchar caret_color;
    uchar pad_189[3];
    ulong caret_interval;
    ulong caret_last_time;
    int draw_caret;
    TDigital* overLengthSound;
    FormatType format_type;
    char* input_buffer;
    char* input_buffer1;
    char* input_buffer2;
    short input_len;
    short max_len;
    int insert_mode;
    short input_pos;
    uchar pad_1B6[2];

    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, uchar, int, uchar, uchar, short, TDigital*, char*,
               FormatType);
    virtual void set_focus(int);
    void set_format(FormatType);
    virtual long handle_idle();
    virtual long char_action(long, short);
    virtual long key_down_action(long, short, int, int, int);
    virtual void draw();
    virtual void set_text(char*);
    virtual void set_text(char**, short);
    char* get_input_buffer();

protected:
    int append_character(long);
    int insert_character(long);
    int delete_character();
    int backspace_character();
    int paste();
    void reformat();
    void calc_input_pos();
    void calc_cur_line_col();

public:
    int is_blank();
    char* get_trimmed_str(char*, int);
};

#endif
