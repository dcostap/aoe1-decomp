// Authentic Pnl_txt.cpp translation-unit wrapper.
//
// The owner files remain standalone recovery units.  This wrapper supplies one
// module-local panel surface, then includes every PDB owner in source order.
// The source guard is enabled only here; focused owner checks keep their local
// declarations when this file is not included.
//
// BINARY NOTE: TPanel owns 56 virtual slots.  The text panel appends the three
// set_text overloads and set_bevel_info.  VC5 reverses adjacent overloads in
// each vtable group, so their source declarations stay in reverse order.
// BINARY NOTE: the +0x40 callback and bevel views use the named TPanel action,
// draw_rect, and draw_rect2 slots.  They are not separate helper vtables.

#include <windows.h>

struct PanelNode;
class TDrawArea;
class TShape;
class TTextPanel;

struct TextNode {
    char* text;
    char* text2;
    long id;
    union { TextNode* next; TextNode* next_node; };
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
    union { long pnl_x; long x; };
    union { long pnl_y; long y; };
    union { long pnl_wid; long width; };
    union { long pnl_hgt; long height; };
    char* panel_name;
    TDrawArea* render_area;
    union { tagRECT clip_rect; tagRECT rect; };
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    union { TPanel* parent_panel; TPanel* bevel; TPanel* handler; };
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
    union { int active; int field_6C; };
    int visible;
    int tab_stop;
    union { int have_focus; int field_78; };
    union { int overlapping_children; int field_7C; };
    union { int handle_mouse_input; int field_80; int panel_state_80; };
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
    union { long mouse_move_tolerance; long field_C0; };
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
    union { unsigned char mouse_action; unsigned char field_EC; };
    unsigned char mouse_down_button;
    union { unsigned char panel_type; unsigned char field_EE; unsigned char panel_flag_EE; };
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
    void scroll_set(int);
    CharType char_type(unsigned char*);
    int word_wrap_append(char*);
    void calc_draw_info(int);
    void scroll(int, short, int);
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
    char* get_text();
    char* get_text(long);
    char* get_text2();
    char* get_text2(long);
    long get_id();
    long get_id(long);
    void empty_list();
    void set_line(long);
    void set_line_by_id(long);
    char* currentLine();
    int numberLines();
    int numberDrawLines();
    int currentLineNumber();
    void setCurrentLineNumber(int);
    void target_func(int);
    int get_text_rect(RECT*);

    TextNode* list;
    union { short num_lines; short max_scroll; };
    union { short draw_lines; short page_scroll; };
    union { short top_line; short cur_scroll; };
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    union { long vert_align; int field_110; };
    union { long horz_align; int field_114; };
    union { int word_wrap; int field_118; };
    union { long text_style; int field_11C; };
    union { unsigned long text_color1; int field_120; };
    union { unsigned long text_color2; int field_124; };
    union {
        unsigned long highlight_text_color1;
        unsigned long highlightTextColor1;
        int field_128;
    };
    union {
        unsigned long highlight_text_color2;
        unsigned long highlightTextColor2;
        int field_12C;
    };
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    unsigned char gap_13A[2];
    long text_wid;
    long text_hgt;
    TShape* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    union { int fill_back; int field_14C; char* fill_back_ptr; };
    union { unsigned char back_color; unsigned char field_150; };
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

#define PNL_TXT_TU_CONTEXT 1
#define AOE1_PNL_TXT_CONTEXT_H 1

#include "matching/0047BF40_TTextPanel.cpp"
#include "matching/0047C0B0_TTextPanel.cpp"
#include "matching/0047C120_setup.cpp"
#include "matching/0047C1E0_setup.cpp"
#include "matching/0047C2F0_setup.cpp"
#include "matching/0047C3B0_set_rect.cpp"
#include "matching/0047C4D0_set_scrollbar.cpp"
#include "matching/0047C520_char_type.cpp"
#include "matching/0047C560_set_text.cpp"
#include "scratch/0047C640_word_wrap_append.cpp"
#include "matching/0047CA70_set_text.cpp"
#include "matching/0047CAB0_set_text.cpp"
#include "matching/0047CB10_set_font.cpp"
#include "matching/0047CB50_set_alignment.cpp"
#include "matching/0047CB70_set_word_wrap.cpp"
#include "matching/0047CB90_set_style.cpp"
#include "matching/0047CBB0_set_text_color.cpp"
#include "matching/0047CBD0_set_highlight_text_color.cpp"
#include "matching/0047CBF0_set_fill_back.cpp"
#include "matching/0047CC10_set_back_pic.cpp"
#include "matching/0047CCF0_set_outline.cpp"
#include "matching/0047CD40_set_bevel_info.cpp"
#include "matching/0047CE00_set_spacer_size.cpp"
#include "matching/0047CE20_set_active.cpp"
#include "accepted_drift/0047CE70_calc_draw_info.cpp"
#include "scratch/0047D060_scroll.cpp"
#include "matching/0047D120_key_down_action.cpp"
#include "matching/0047D200_action.cpp"
#include "verified_logic/0047D2C0_draw.cpp"
#include "matching/0047D3D0_draw_background.cpp"
#include "matching/0047D570_draw_border.cpp"
#include "accepted_drift/0047D760_draw_line.cpp"
#include "accepted_drift/0047D9E0_calc_line_pos.cpp"
#include "matching/0047DC10_mouse_left_down_action.cpp"
#include "scratch/0047DC30_numberLines.cpp"
#include "scratch/0047DC40_numberDrawLines.cpp"
#include "scratch/0047DC50_currentLineNumber.cpp"
#include "matching/0047DC60_setCurrentLineNumber.cpp"
#include "matching/0047DC70_currentLine.cpp"
#include "matching/0047DC80_set_line.cpp"
#include "matching/0047DCA0_set_line_by_id.cpp"
#include "matching/0047DCD0_append_line.cpp"
#include "matching/0047DCF0_append_line.cpp"
#include "matching/0047DD10_append_line.cpp"
#include "matching/0047DD30_append_line.cpp"
#include "matching/0047DD50_insert_line.cpp"
#include "accepted_drift/0047DD70_insert_line.cpp"
#include "matching/0047DF90_insert_line.cpp"
#include "matching/0047DFE0_insert_line.cpp"
#include "matching/0047E050_change_line.cpp"
#include "matching/0047E0B0_change_line.cpp"
#include "matching/0047E110_delete_line.cpp"
#include "matching/0047E1E0_get_line.cpp"
#include "scratch/0047E200_get_line.cpp"
#include "scratch/0047E230_get_line.cpp"
#include "matching/0047E290_get_text.cpp"
#include "accepted_drift/0047E2A0_get_text.cpp"
#include "matching/0047E2E0_get_text2.cpp"
#include "matching/0047E2F0_get_text2.cpp"
#include "matching/0047E330_get_id.cpp"
#include "scratch/0047E340_get_id.cpp"
#include "matching/0047E370_empty_list.cpp"
#include "scratch/0047E380_free_text.cpp"
#include "scratch/0047E3F0_set_second_column_pos.cpp"
#include "matching/0047E410_get_text_rect.cpp"

#undef AOE1_PNL_TXT_CONTEXT_H
#undef PNL_TXT_TU_CONTEXT
