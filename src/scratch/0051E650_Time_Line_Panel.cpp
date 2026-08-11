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

class TShape;
class TTextPanel;
struct Special_Events;

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    unsigned char gap_04[0x7C];
    int field_80;
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    TEasy_Panel();
    unsigned char gap_84[0x3F4];
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
    field_80 = 0;
    timeline_flag = 1;
    drop_flag = 0;
    pop_reading_rate = 0x0C;
    legend_entry_text[0] = 0;
    legend_entry_text[1] = 0;
    legend_entry_text[2] = 0;
}
