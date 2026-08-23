#ifndef AOE1_TPNL_TML_CONTEXT_H
#define AOE1_TPNL_TML_CONTEXT_H

struct Special_Events;
struct PanelNode;
struct RGE_Color_Table;
class TShape;
class TTextPanel;
class TDrawArea;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
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

    long width();
    long height();
    TDrawArea* renderArea();
    void delete_panel(TPanel** panel);
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
    char _gap_00[0xAC];
    Special_Events* next;
};

class TShape {
public:
    char _gap_00;
    ~TShape();
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};

class RGE_Base_Game {
public:
    RGE_Font* get_font(int id);
};

extern RGE_Base_Game* rge_base_game;

class Time_Line_Panel : public TEasy_Panel {
public:
    enum Style {
        ChiseledStyle = 2
    };

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
    Time_Line_Panel();
    long create_timeline(TPanel* parent, Time_Line_Panel** out, long x1, long y1, long x2, long y2, long axis_font_id, long body_font_id, long xden, long yden);
    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height,
               void* axis_font, long axis_w, long axis_h, void* body_font, long body_w, long body_h,
               char* bg, char* se, int fill_back, unsigned char back_color, int outline, unsigned char outline_color);
    void init_timeline();
};

#endif
