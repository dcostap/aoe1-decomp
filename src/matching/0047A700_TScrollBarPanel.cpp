// VA: 0047A700 TScrollBarPanel::TScrollBarPanel
// Source: Pnl_scbr.cpp lines 66-76
// Attempt log:
// 1: natural constructor without virtual base surface built only 336 bytes/no EH.
// 2: make TPanel/TScrollBarPanel virtual-destructor classes to trigger original constructor EH frame.
// Prior body-assignment form emitted the derived vptr at entry. The executable
// stores it after the field stores. The initializer-list form below preserves
// that order without manual vptr code.
// Probe 3: moved all proven derived scalar stores to the constructor initializer
// list. VC5 then delayed the derived vptr store and matched all 380 bytes in the
// authentic Pnl_scbr.cpp wrapper without manual vptr code.
// Exact-finish walkbacks: removing bevel_color6(0) changed 134 bytes; removing
// item_hold_interval(100) changed 190 bytes. Restored both initializers.

#ifndef PNL_SCBR_CANONICAL_TU
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* rect, int left, int top, int right, int bottom);

class TPanel {
public:
    virtual ~TPanel();
    TPanel();
    char gap_04[0x0C - 0x04];
    long field_0C;
    long field_10;
    long field_14;
    long field_18;
    char gap_1C[0x20 - 0x1C];
    void* draw_area;
    tagRECT rect_24;
    char gap_34[0x40 - 0x34];
    void* panel;
    char gap_44[0x0C0 - 0x44];
    int field_C0;
    char gap_C4[0x0EE - 0x0C4];
    unsigned char field_EE;
    char gap_EF[0x0F4 - 0x0EF];
};

class TScrollBarPanel : public TPanel {
public:
    void* list_panel;          // +F4
    long list_len;             // +F8
    long one_step;             // +FC
    long page_step;            // +100
    long list_num;             // +104
    void* button_pics;         // +108
    long back_frame;           // +10C
    long up_frame;             // +110
    long down_frame;           // +114
    long tab_frame;            // +118
    long arrowSize;            // +11C
    long tabSize;              // +120
    long tab_y;                // +124
    long tab_min_y;            // +128
    long tab_max_y;            // +12C
    long tab_mouse_y;          // +130
    long tab_x;                // +134
    long tab_min_x;            // +138
    long tab_max_x;            // +13C
    long tab_mouse_x;          // +140
    unsigned char item_down;   // +144
    char gap_145[3];
    long item_is_down;         // +148
    long item_x;               // +14C
    long item_y;               // +150
    unsigned char item_mode;   // +154
    char gap_155[3];
    long item_last_time;       // +158
    long item_hold_interval;   // +15C
    long item_down_interval;   // +160
    tagRECT up_rect;           // +164
    tagRECT down_rect;         // +174
    tagRECT tab_rect;          // +184
    tagRECT top_rect;          // +194
    tagRECT bottom_rect;       // +1A4
    long orientationValue;     // +1B4
    long bevel_type;           // +1B8
    unsigned char bevel_color1; // +1BC
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;

    virtual ~TScrollBarPanel();
    TScrollBarPanel();
};
#endif

TScrollBarPanel::TScrollBarPanel()
    : TPanel(),
      list_panel(0),
      list_len(0),
      one_step(0),
      page_step(0),
      list_num(0),
      button_pics(0),
      back_frame(0),
      up_frame(0),
      down_frame(0),
      tab_frame(0),
      arrowSize(0),
      tabSize(0),
      tab_y(0),
      tab_min_y(0),
      tab_max_y(0),
      tab_mouse_y(0),
      tab_x(0),
      tab_min_x(0),
      tab_max_x(0),
      tab_mouse_x(0),
      item_down(0),
      item_is_down(0),
      item_x(0),
      item_y(0),
      item_mode(0),
      item_last_time(0),
      item_hold_interval(100),
      item_down_interval(250),
      orientationValue(0),
      bevel_type(1),
      bevel_color1(0),
      bevel_color2(0),
      bevel_color3(0),
      bevel_color4(0),
      bevel_color5(0),
      bevel_color6(0)
{
    this->field_EE = 5;
    this->field_C0 = 0;
    SetRect(&this->up_rect, 0, 0, 0, 0);
    SetRect(&this->down_rect, 0, 0, 0, 0);
    SetRect(&this->tab_rect, 0, 0, 0, 0);
    SetRect(&this->top_rect, 0, 0, 0, 0);
    SetRect(&this->bottom_rect, 0, 0, 0, 0);
}
