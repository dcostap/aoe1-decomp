#ifndef AOE1_TPNL_TML_H
#define AOE1_TPNL_TML_H

// Declarations recovered for the original tpnl_tml.cpp translation unit.

typedef unsigned char uchar;
typedef void* HDC;
typedef void* HGDIOBJ;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct PanelNode;
struct RGE_Color_Table;
class TShape;
class TTextPanel;

struct TDrawSystem {
    void* instance;
    void* window;
    void* Pal;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    void* DrawDc;
    unsigned char* Bits;

    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void Clear(tagRECT*, unsigned int);
    void FillRect(long, long, long, long, unsigned char);
    void DrawRect(long, long, long, long, unsigned char);
    void DrawBevel(long, long, long, long, unsigned char, unsigned char);
    void DrawBevel2(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char);
    void DrawBevel3(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
    void DrawVertLine(long, long, long, unsigned char);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class TPanel {
public:
    virtual ~TPanel();
    TPanel();

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

    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);

    long width();
    long height();
    long xPosition();
    long yPosition();
    TDrawArea* renderArea();
    void delete_panel(TPanel**);
    int setup(TDrawArea*, TPanel*, long, long, long, long, int);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    TEasy_Panel();

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
    unsigned char gap_326[2];
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
    unsigned char gap_456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char gap_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;
};

struct Special_Events {
    long time_slice;
    long X_line_pos;
    long Y_line_pos;
    long intermediate_y_line_segment;
    uchar player_id;
    uchar player_color;
    uchar event;
    uchar gap_13;
    long pop_total;
    long integer_value_1;
    long integer_value_2;
    long start_x;
    long start_y;
    long start_txt_x1;
    long start_txt_y1;
    long start_txt_x2;
    long start_txt_y2;
    int text_length1;
    char text1[50];
    uchar gap_6E[2];
    int text_length2;
    char text2[50];
    uchar gap_A6[2];
    int icon_flag;
    Special_Events* next;
};

class TShape {
public:
    unsigned char* shape;
    int load_type;
    int load_size;
    void* shape_header;
    char gap_10[4];
    void* offsets;
    unsigned char* FShape;
    void* shape_info;

    TShape(char*, int);
    TShape(char*, long);
    ~TShape();
    int is_loaded();
    long shape_count();
    unsigned char shape_bounds(long, short&, short&);
    unsigned char shape_minmax(long*, long*, long*, long*, long);
    unsigned char shape_minmax(long*, long*, long*, long*, int);
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};

class TRIBE_History_Info {
public:
    long get_history_entry_num();
    unsigned char get_history_entry(unsigned char, long);
    unsigned char get_history_event(long, unsigned char&);
};

struct RGE_Player_Details {
    char gap_000[0x26];
    short civilization;
};

struct RGE_Player {
    char gap_000[0x44];
    char* name;
    char gap_048[0xBD];
    unsigned char civilization;
    char gap_106[2];
    RGE_Player_Details* details;
    char gap_10C[0x730];
    TRIBE_History_Info* history_info;
};
typedef RGE_Player TRIBE_Player;

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void*);
    char gap_04[0x38];
    short player_num;
    short pad_3E;
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    char gap_004[0x3F0];
    RGE_Game_World* world;
    RGE_Font* get_font(int);
};

extern RGE_Base_Game* rge_base_game;
extern char s_tpnl_tml_draw_axis[];

class Time_Line_Panel : public TEasy_Panel {
public:
    enum Style { ChiseledStyle = 2 };

    void* axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    void* body_font;
    long body_font_wid;
    long body_font_hgt;
    Style text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    long text_wid;
    long text_hgt;
    TShape* background_pic;
    short background_pic_wid;
    short background_pic_hgt;
    int fill_back;
    unsigned char back_color;
    unsigned char gap_4B9[3];
    int outline;
    unsigned char outline_color;
    unsigned char gap_4C1[3];
    int sorted;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char gap_4D2[2];
    TShape* special_events_pic;
    short special_events_pic_wid;
    short special_events_pic_hgt;
    long X_start_line_pos;
    long Y_start_line_pos;
    long X_line_pos;
    long Y_line_pos;
    long X_line_max_width;
    long Y_line_max_length;
    long X_axis_length;
    long Y_axis_length;
    float bar_thickness;
    long pop_reading_rate;
    float time_slice_drop_rate;
    int total_slices_to_drop;
    unsigned char drop_flag;
    unsigned char gap_50D[3];
    long num_entries_page;
    long num_history_entries;
    Special_Events* time_slice_events;
    unsigned char timeline_flag;
    unsigned char gap_51D[3];
    TTextPanel* legend_entry_text[3];

    virtual ~Time_Line_Panel();
    virtual void draw();
    virtual void redraw(int);
    Time_Line_Panel();
    long create_timeline(TPanel*, Time_Line_Panel**, long, long, long, long,
                         long, long, long, long);
    int set_background(char*, long);
    int set_special_events(char*, long);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               void*, long, long, char*, char*, int, unsigned char, int,
               unsigned char);
    void init_timeline();
    void set_axis_font(void*, long, long);
    void set_body_font(void*, long, long);
    void set_bevel_info(int, int, int, int, int, int, int);
    int set_background(char*);
    int set_special_events(char*);
    void set_back_color(int, unsigned char);
    void draw_border();
    void add_pop_total_special_event(long, long, long, int);
    void record_special_event(unsigned char, TRIBE_History_Info*, unsigned char,
                              long, long, long, long);
    int calculate_icon_location(Special_Events*, short, uchar);
    void draw_axis();
    void draw_special_events();
    void draw_background();
    void draw_civilization_names();
    void draw_timeline();
    void draw_icon(Special_Events*, short, uchar);
    void draw_legend();
    int xPosition();
    int yPosition();
    int width();
    int height();
    int get_string(int, char*, int);
};

// API declarations used by this period source module.
extern "C" {
__declspec(dllimport) unsigned int __stdcall GetNearestPaletteIndex(void*, unsigned int);
__declspec(dllimport) unsigned int __stdcall SetTextColor(void*, unsigned int);
__declspec(dllimport) int __stdcall SetBkMode(void*, int);
__declspec(dllimport) void* __stdcall SelectObject(void*, void*);
__declspec(dllimport) int __stdcall TextOutA(void*, int, int, const char*, int);
}

#endif
