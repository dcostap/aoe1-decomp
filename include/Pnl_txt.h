// Module-local declarations for the authentic Pnl_txt.cpp source module.
// PDB source: C:\msdev\work\age1_x1\Pnl_txt.cpp.

#ifndef AOE1_PNL_TXT_H
#define AOE1_PNL_TXT_H

#include <windows.h>

struct PanelNode;
class TDrawArea;
class TShape;
class TTextPanel;

struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next_node;
};

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int mode);
    void Unlock(char* name);
    void FillRect(long left, long top, long right, long bottom,
                  unsigned char color);
    void DrawRect(long x1, long y1, long x2, long y2,
                  unsigned char color);
    void DrawBevel(long x1, long y1, long x2, long y2,
                   unsigned char color1, unsigned char color2);
    void DrawBevel2(long x1, long y1, long x2, long y2,
                    unsigned char color1, unsigned char color2,
                    unsigned char color3, unsigned char color4);
    void DrawBevel3(long x1, long y1, long x2, long y2,
                    unsigned char color1, unsigned char color2,
                    unsigned char color3, unsigned char color4,
                    unsigned char color5, unsigned char color6);
};

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
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
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    long xPosition();
    long yPosition();
    int get_string(long, char*, long);
    int capture_mouse();
    void release_mouse();

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
};

typedef char pnl_txt_panel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel;
    char gap_F8[0xCC];
    long width();
    void set_list_len(int length, int top_line);
};

class TShape {
public:
    unsigned char* shape;
    int load_type;
    int load_size;
    void* shape_header;
    void* head;
    void* offsets;
    void* FShape;
    void* shape_info;
    TShape(char* name, int param_2);
    ~TShape();
    unsigned char shape_minmax(long*, long*, long*, long*, long);
    unsigned char shape_draw(TDrawArea*, long, long, long,
                             unsigned char, unsigned char*);
};

class TTextPanel : public TPanel {
public:
    enum CharType {
        SingleByteChar = 0,
        SingleByteKanaChar = 1,
        DoubleByteChar = 2
    };

    enum Alignment {
        AlignCenter = 0,
        AlignLeft = 1,
        AlignRight = 2,
        AlignTop = 3,
        AlignBottom = 4,
        AlignHorizontalScroll = 5,
        AlignWordwrap = 6
    };

    enum Style {
        NormalStyle = 0,
        BeveledStyle = 1,
        ChiseledStyle = 2
    };

    TTextPanel();
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);

    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, char*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, long);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, char**, short);
    void set_font(void*, long, long);
    void set_alignment(Alignment, Alignment);
    void set_word_wrap(int);
    void set_style(Style);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_fill_back(int, unsigned char);
    void set_back_pic(char*);
    void set_outline(int, unsigned char);
    void set_spacer_size(int);
    void set_scrollbar(TScrollBarPanel*, int);
    CharType char_type(unsigned char*);
    int word_wrap_append(char*);
    void calc_draw_info(int);
    void scroll(unsigned char, short, int);
    void draw_background();
    void draw_border();
    void draw_line(void*, short, short, unsigned long, unsigned long);
    void calc_line_pos(void*, short, short, tagRECT*, long*);
    void free_text();
    int append_line(const char*, long);
    int append_line(char*, long);
    int append_line(char*, char*, long);
    int append_line(long, long);
    int append_line(long, long, long);
    int insert_line(long, char*, long);
    int insert_line(long, char*, char*, long);
    int insert_line(long, long, long);
    int insert_line(long, long, long, long);
    int change_line(long, char*, char*, long);
    int change_line(long, long, long, long);
    int delete_line(long);
    long get_line();
    long get_line(long);
    long get_line(char*);
    char* get_text();
    char* get_text(long);
    char* get_text2();
    char* get_text2(long);
    long get_id();
    long get_id(long);
    void set_second_column_pos(long);
    void empty_list();
    void set_line(long);
    void set_line_by_id(long);
    char* currentLine();
    int numberLines() const;
    int numberDrawLines() const;
    int currentLineNumber() const;
    void setCurrentLineNumber(int);
    int get_text_rect(RECT*);

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
    long vert_align;
    long horz_align;
    int word_wrap;
    long text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlight_text_color1;
    unsigned long highlight_text_color2;
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    unsigned char gap_13A[2];
    long text_wid;
    long text_hgt;
    TShape* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    unsigned char gap_151[3];
    int outline;
    unsigned char outline_color;
    unsigned char gap_159[3];
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
    unsigned char gap_17A[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;
};

#endif
