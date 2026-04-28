// 0051E9E0 Time_Line_Panel::setup (tpnl_tml.cpp:202-227)
// Attempt 3: fix TPanel.layout - render_area at +0x20

__declspec(dllimport) int __stdcall GetNearestPaletteIndex(void*, unsigned int);

class TDrawArea {
public:
    void* unk0;              // +0x00
    void* unk4;              // +0x04
    unsigned char* Bits;     // +0x08
};

class TPanel {
public:
    virtual ~TPanel() {}     // forces vtable ptr at +0x00
    char gap_04[0x1C];       // +0x04 to +0x1F
    TDrawArea* render_area;  // +0x20
    char gap_24[0xD0];       // +0x24 to +0xF3

    int setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, int value);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel() {}  // virtual dtor for vtable
    char gap_F4[0x384];      // +0xF4 to +0x477
};

class Time_Line_Panel : public TEasy_Panel {
public:
    virtual ~Time_Line_Panel() {}  // virtual dtor for vtable
    char gap_478[0x3C];      // +0x478 to +0x4B3
    int fill_back;            // +0x4B4
    unsigned char back_color; // +0x4B8
    char pad_4B9[3];          // +0x4B9 to +0x4BB
    int outline;              // +0x4BC
    unsigned char outline_color; // +0x4C0
    char pad_4C1[7];          // +0x4C1 to +0x4C7
    int bevel_type;           // +0x4C8

    long setup(
        TDrawArea*, TPanel*, long, long, long, long,
        void*, long, long, void*, long, long,
        char*, char*, int, unsigned char, int, unsigned char);

    void set_axis_font(void* font, long w, long h);
    void set_body_font(void* font, long w, long h);
    int set_background(char* bg);
    int set_special_events(char* se);
    void set_back_color(int a, unsigned char b);
};

long Time_Line_Panel::setup(
    TDrawArea* param_1,
    TPanel* param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    void* param_7,
    long param_8,
    long param_9,
    void* param_10,
    long param_11,
    long param_12,
    char* param_13,
    char* param_14,
    int param_15,
    unsigned char param_16,
    int param_17,
    unsigned char param_18
)
{
    this->TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);

    this->fill_back = param_15;
    this->back_color = param_16;
    this->outline = param_17;
    this->outline_color = param_18;

    if (param_17) {
        this->bevel_type = 1;
    }

    this->set_axis_font(param_7, param_8, param_9);
    this->set_body_font(param_10, param_11, param_12);
    this->set_background(param_13);
    this->set_special_events(param_14);

    unsigned char pal_idx = (unsigned char)GetNearestPaletteIndex(
        *(void**)((*(char**)this->render_area) + 8), 0);
    this->set_back_color(1, pal_idx);

    return 1;
}
