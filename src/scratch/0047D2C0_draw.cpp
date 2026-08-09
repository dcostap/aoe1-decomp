// VA: 0047D2C0 TTextPanel::draw
// PDB source: Pnl_txt.cpp:961-1000
//
// Canonical panel ownership follows the exact Pnl_btn/Pnl_txt siblings:
//   TPanel +0x20 render_area, +0x38 need_redraw, +0x68 mouse_captured,
//   +0x6C active, +0x70 visible, +0x74 tab_stop, +0x78 have_focus,
//   +0x88 clip_rgn; TTextPanel +0xFC/+0xFE top/bottom line,
//   +0x104 font, +0x120/+0x124 normal colors, +0x128/+0x12C highlight.
//
// Attempt log:
// - baseline: restored the natural draw-background/setup, DC/font selection,
//   line loop, cleanup, border, and draw-finish sequence from the packet.
// - corrected TPanel's +0x84/+0x88 layout; rebuilt size/frame/calls and reached
//   18 positional bytes of drift with the complete CFG aligned.
// - top-declared locals, for-loop spelling, int counter, register qualifiers,
//   a common color-temporary form, and a base-pointer call context were either
//   codegen duplicates or materially worse; restored the clean while form.
// - remaining drift is localized to VC5 callee-save coloring: original keeps
//   the saved vtable/top-line in EBX and DC in EDI, while this clean source
//   keeps the same values in EDI and EBX respectively. Calls/layout/fields are
//   aligned; no canonical source lead remains within this assignment.
// - Main-agent audit restored TPanel's canonical destructor slot; the validated
//   18-byte register-coloring gap is unchanged.
// - This assignment rechecked C-style top declaration of dc/old_font/line;
//   it was an emitted-code duplicate. The clean direct-member source remains
//   the plausible candidate.

extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
}

extern char s_pnl_txt__draw[];

class TDrawArea {
public:
    void* GetDc(char* unused);
    void ReleaseDc(char* unused);
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)

class TPanel {
public:
    virtual ~TPanel();
    VPAD4(v1)
    VPAD2(v5)
    VPAD1(v7)
    VPAD2(v8)
    virtual void draw_setup(int clear);   // +0x28
    virtual void draw_finish();           // +0x2C
    virtual void draw();                  // +0x30

    char gap_04[0x08];
    long pnl_x;                           // +0x0C
    long pnl_y;                           // +0x10
    long pnl_wid;                         // +0x14
    long pnl_hgt;                         // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;               // +0x20
    char gap_24[0x14];
    int need_redraw;                      // +0x38
    char gap_3C[0x2C];
    int mouse_captured;                   // +0x68
    int active;                           // +0x6C
    int visible;                          // +0x70
    int tab_stop;                         // +0x74
    int have_focus;                       // +0x78
    char gap_7C[0x08];
    int just_drawn;                       // +0x84
    void* clip_rgn;                       // +0x88
    char gap_8C[0x68];
};

class TTextPanel : public TPanel {
public:
    virtual void draw();
    char gap_F4[0x08];                    // list/line-count fields
    short top_line;                       // +0xFC
    short bot_line;                       // +0xFE
    char gap_100[0x04];
    void* font;                            // +0x104
    char gap_108[0x18];
    unsigned long text_color1;            // +0x120
    unsigned long text_color2;            // +0x124
    unsigned long highlight_text_color1;  // +0x128
    unsigned long highlight_text_color2;  // +0x12C

    void draw_background();
    void draw_line(void* dc, short line_index, short line,
                   unsigned long color1, unsigned long color2);
    void draw_border();
};

void TTextPanel::draw()
{
    short line_index = 0;

    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    void* dc = this->render_area->GetDc(s_pnl_txt__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        void* old_font = SelectObject(dc, this->font);
        SetBkMode(dc, 1);

        short line = this->top_line;
        while (line <= this->bot_line) {
            if ((this->tab_stop != 0 && this->have_focus != 0) ||
                this->mouse_captured != 0) {
                this->draw_line(dc, line_index, line,
                                this->highlight_text_color1,
                                this->highlight_text_color2);
            } else {
                this->draw_line(dc, line_index, line,
                                this->text_color1, this->text_color2);
            }
            ++line;
            ++line_index;
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc(s_pnl_txt__draw);
    }

    this->draw_border();
    this->draw_finish();
}
