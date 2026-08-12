// 0051E650 Time_Line_Panel::Time_Line_Panel (tpnl_tml.cpp:98-109)
//
// Attempt log:
// baseline: offset-backed TPanel constructor; exact size/instruction count but
//   wrong base-call symbol and several delayed constant stores.
// probe 2: period TEasy_Panel hierarchy and virtual class surface fixed the
//   direct call target, but VC5 placed the derived vtable immediately after the
//   base call and moved the constant stores.
// probes 3/7/10: the natural member-initializer-list form is the best basin
//   (276 bytes, 1 aligned TEasy_Panel call, 125 strict-diff bytes); it still
//   emits highlightTextColor1 before text_style and delays the vtable/back
//   color/timeline tail relative to the oracle.
// probes 4/5/6: body-only, reduced virtual surface, and complete PDB layout
//   variants did not improve the emitted code.
// probe 9: a focused constructor-form lab found no exact variant; the
//   remaining blocker is VC5 store/vtable scheduling, not size or call shape.
// current session: body-assignment, full TPanel/TEasy_Panel vtable, member-width,
// declaration-order, implicit-base, and narrowed initializer/body variants were
// compiled and restored; none beat the 276-byte/125-diff initializer-list basin.
//   The body forms moved the compiler vtable store to entry (200-209 diff), while
//   the full virtual surface and ground-truth widths emitted unchanged bytes.
// paused: ordered base call and all 47 instructions/size match, but the first
// mismatch remains +000C (highlightTextColor1 before text_style) with delayed
// vtable/back-color/tail stores; next lead is original TU/header scheduling.
// layout hypothesis: use the canonical 0xF4 TPanel and 0x478 TEasy_Panel
// ownership from the type dumps and the exact 0051E9E0 setup donor.
// layout probe: the full canonical declarations and handle_mouse_input name
// emitted the same 276-byte/125-diff constructor; retain them as source truth.

class TShape;
class TTextPanel;
struct Special_Events;
struct PanelNode;
struct RGE_Color_Table;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

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
    int text_color1;
    int text_color2;
    int highlightTextColor1;
    int highlightTextColor2;
    int text_wid;
    int text_hgt;
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
    int pop_reading_rate;
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
};

Time_Line_Panel::Time_Line_Panel()
    : TEasy_Panel(),
      axis_font(0),
      axis_font_wid(0),
      axis_font_hgt(0),
      body_font(0),
      body_font_wid(0),
      body_font_hgt(0),
      text_style(ChiseledStyle),
      text_color1(0xFFFFFF),
      text_color2(0),
      highlightTextColor1(0xFFFF),
      highlightTextColor2(0),
      text_wid(0),
      text_hgt(0),
      background_pic(0),
      background_pic_wid(0),
      background_pic_hgt(0),
      fill_back(0),
      back_color(0xFF),
      outline(0),
      outline_color(0),
      bevel_type(0),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0),
      special_events_pic(0),
      special_events_pic_wid(0),
      special_events_pic_hgt(0),
      total_slices_to_drop(0),
      time_slice_events(0)
{
    handle_mouse_input = 0;
    timeline_flag = 1;
    drop_flag = 0;
    pop_reading_rate = 0x0C;
    legend_entry_text[0] = 0;
    legend_entry_text[1] = 0;
    legend_entry_text[2] = 0;
}
