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
// - Unqualified inherited draw_setup/draw_finish calls were an emitted-code
//   duplicate; restored explicit member spelling.
// - A natural for-header declaration for the top-line loop was also an emitted
//   duplicate; restored the clean while form.
// - Fresh replacement baseline: full calls/CFG/frame/size aligned; the
//   remaining 18 bytes are the EBX/EDI callee-save color swap at the vtable/DC
//   boundary and its mirrored loop/cleanup uses.
// - Period Windows/CRT headers with HDC/HGDIOBJ/HRGN, and the canonical full
//   TPanel/PanelNode/TTextPanel ownership surface, emitted the same 18-byte
//   group.  Four natural local-order variants and a 12-case receiver/local
//   variant lab likewise collapsed to that group.
// - Narrow register-qualified DC/font locals and a TPanel reference receiver
//   were emitted-code duplicates.  Removed those compiler-steering probes;
//   retained the readable typed TU/layout reconstruction in scratch.
// - Fresh worker pass: generic-versus-destructor TPanel vtable surface,
//   implicit highlight predicates, canonical unused TPanel link types,
//   explicit prechecked do/while scan, memory.h context, register-qualified
//   line, full TDrawArea layout, late TPanel receiver alias, and packet ABI
//   void* draw_line all emitted the same 18-byte EBX/EDI coloring group.
//   A seven-header context lab likewise had one 270-byte group; restored the
//   clean typed source after each diagnostic probe.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char s_pnl_txt__draw[];

struct PanelNode;

class TDrawArea {
public:
    HDC GetDc(char* unused);
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

    TPanel* previous_panel;              // +0x04
    TPanel* previous_modal_panel;        // +0x08
    long pnl_x;                           // +0x0C
    long pnl_y;                           // +0x10
    long pnl_wid;                         // +0x14
    long pnl_hgt;                         // +0x18
    char* panel_name;                     // +0x1C
    TDrawArea* render_area;               // +0x20
    long clip_left;                       // +0x24
    long clip_top;                        // +0x28
    long clip_right;                      // +0x2C
    long clip_bottom;                     // +0x30
    int position_mode;                    // +0x34
    int need_redraw;                      // +0x38
    int field_3C;                         // +0x3C
    TPanel* parent_panel;                 // +0x40
    TPanel* left_panel;                   // +0x44
    TPanel* top_panel;                    // +0x48
    TPanel* right_panel;                  // +0x4C
    TPanel* bottom_panel;                 // +0x50
    PanelNode* node;                      // +0x54
    PanelNode* first_child_node;          // +0x58
    PanelNode* last_child_node;           // +0x5C
    TPanel* curr_child;                   // +0x60
    int field_64;                         // +0x64
    int mouse_captured;                   // +0x68
    int active;                           // +0x6C
    int visible;                          // +0x70
    int tab_stop;                         // +0x74
    int have_focus;                       // +0x78
    int field_7C;                         // +0x7C
    int field_80;                         // +0x80
    int just_drawn;                       // +0x84
    void* clip_rgn;                       // +0x88
    char gap_8C[0x68];
};

class TTextPanel : public TPanel {
public:
    virtual void draw();
    void* list;                            // +0xF4
    short num_lines;                       // +0xF8
    short draw_lines;                      // +0xFA
    short top_line;                       // +0xFC
    short bot_line;                       // +0xFE
    short cur_line;                        // +0x100
    short cur_col;                         // +0x102
    void* font;                            // +0x104
    long font_wid;                         // +0x108
    long font_hgt;                         // +0x10C
    int vert_align;                        // +0x110
    int horz_align;                        // +0x114
    int word_wrap;                         // +0x118
    int text_style;                        // +0x11C
    unsigned long text_color1;            // +0x120
    unsigned long text_color2;            // +0x124
    unsigned long highlight_text_color1;  // +0x128
    unsigned long highlight_text_color2;  // +0x12C
    void* scbar_panel;                     // +0x130
    int auto_scbar;                        // +0x134
    short fixed_len;                       // +0x138
    short gap_13A;                          // +0x13A
    long text_wid;                         // +0x13C
    long text_hgt;                         // +0x140
    void* back_pic;                        // +0x144
    short back_pic_wid;                    // +0x148
    short back_pic_hgt;                    // +0x14A
    int fill_back;                         // +0x14C
    unsigned char back_color;              // +0x150
    char gap_151[0x03];                    // +0x151
    int outline;                            // +0x154
    unsigned char outline_color;           // +0x158
    char gap_159[0x03];                    // +0x159
    int sorted;                             // +0x15C
    long second_column_pos;                // +0x160
    long full_width;                       // +0x164
    long scbar_width;                      // +0x168
    int scbar_active;                      // +0x16C
    int bevel_type;                        // +0x170
    unsigned char bevel_color1;            // +0x174
    unsigned char bevel_color2;            // +0x175
    unsigned char bevel_color3;            // +0x176
    unsigned char bevel_color4;            // +0x177
    unsigned char bevel_color5;            // +0x178
    unsigned char bevel_color6;            // +0x179
    char gap_17A[0x02];                    // +0x17A
    void* clip_rgn2;                       // +0x17C
    int border_size;                        // +0x180
    int spacer_size;                        // +0x184

    void draw_background();
    void draw_line(HDC dc, short line_index, short line,
                   unsigned long color1, unsigned long color2);
    void draw_border();
};

void TTextPanel::draw()
{
    short line;
    short line_index = 0;
    HDC dc;
    void* old_font;

    this->need_redraw = 0;
    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        return;
    }

    this->draw_background();
    this->draw_setup(0);

    dc = this->render_area->GetDc(s_pnl_txt__draw);
    if (dc != 0) {
        SelectClipRgn(dc, this->clip_rgn);
        old_font = SelectObject(dc, this->font);
        SetBkMode(dc, 1);

        line = this->top_line;
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
