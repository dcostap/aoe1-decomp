// 0047C3B0 TTextPanel::set_rect (Pnl_txt.cpp:185-231)
//
// Binary-supported layout: TPanel is 0xF4 bytes; the text-panel additions
// place the scrollbar state at +0x130/+0x134 and the second-column/clip
// state at +0x160/+0x17C.  The compiler also keeps a tagRECT-sized local in
// this routine while rebuilding clip_rgn2.
//
// Attempt log:
// - Baseline structural stub was replaced with the natural TPanel/TTextPanel
//   reconstruction; the first clean source had the wrong parent-branch shape,
//   an indirect scrollbar call, no frame, and a 259-byte strict diff.
// - Reversed the parent test so the non-null x/y calculation is inline,
//   selected the observed set_fixed_position virtual slot (+0x1C), and copied
//   clip_rect2 before clamping its right edge.  This restored exact size/frame,
//   all eight ordered calls, and 87.1% exact blocks (19-byte strict diff).
// - Compound x updates, a block-local scrollbar pointer, six focused call-shape
//   variants, the proven nonempty scrollbar layout, the full text-panel field
//   surface, int/register temporary variants, and declaration-order changes
//   were all emitted-code duplicates.  The living source keeps the canonical
//   typed layout and natural direct call rather than those diagnostics.
// - Paused with the remaining drift localized to the scrollbar call setup at
//   +0x7B..+0x9A: original loads scbar_panel before scbar_width and computes
//   the first argument in EDI/EBP; VC5's natural basin reverses those loads and
//   uses EDX.  No call, CFG, frame, boundary, or later clip-region bytes differ.
// - This assignment rechecked a named scrollbar pointer, then a pointer-plus-
//   width source-order pair; both were codegen duplicates. Restored the direct
//   typed call because the remaining issue is only VC5 load scheduling.
// - An int spelling for the proven 4-byte scbar_width field was a codegen
//   duplicate; restored the period-plausible long geometry type.
// - A reference receiver for the proven non-null scrollbar and a narrow int
//   fixed-position width parameter were both duplicates; restored the exact
//   typed donor ABI and direct member call.
// - Restored the period Windows SDK context with <windows.h> for tagRECT,
//   DeleteObject, and CreateRectRgn instead of local import/type stubs.  The
//   natural source then emits the original scrollbar receiver-before-width
//   schedule and matches all 277 bytes under the default flags.

#include <windows.h>

#ifndef PNL_TXT_TU_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long width, long height);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(int mode, long x, long y, long width,
                                 long height, long p6, long p7, long p8,
                                 TPanel* p9, TPanel* p10, TPanel* p11,
                                 TPanel* p12);
    virtual void set_fixed_position(long left, long top, long width,
                                    long height);

    char gap_04[0x08];
    long pnl_x;                         // +0x0C
    long pnl_y;                         // +0x10
    long pnl_wid;                       // +0x14
    long pnl_hgt;                       // +0x18
    char gap_1C[0x04];
    void* render_area;                  // +0x20
    tagRECT clip_rect;                  // +0x24
    char gap_34[0x0C];
    TPanel* parent_panel;               // +0x40
    char gap_44[0x2C];
    int visible;                        // +0x70
    char gap_74[0x14];
    void* clip_rgn;                     // +0x88
    tagRECT render_rect;                // +0x8C
    char gap_9C[0x54];
    char gap_F0[0x04];

    long xPosition();
    long yPosition();
};

class TScrollBarPanel : public TPanel {
public:
    TPanel* list_panel;                 // +0xF4
    char gap_F8[0xCC];
};

class TTextPanel : public TPanel {
public:
    void* list;                         // +0xF4
    short num_lines;                    // +0xF8
    short draw_lines;                   // +0xFA
    short top_line;                     // +0xFC
    short bot_line;                     // +0xFE
    short cur_line;                     // +0x100
    short cur_col;                      // +0x102
    void* font;                         // +0x104
    long font_wid;                      // +0x108
    long font_hgt;                      // +0x10C
    long vert_align;                    // +0x110
    long horz_align;                    // +0x114
    int word_wrap;                      // +0x118
    long text_style;                    // +0x11C
    unsigned long text_color1;           // +0x120
    unsigned long text_color2;           // +0x124
    unsigned long highlightTextColor1;   // +0x128
    unsigned long highlightTextColor2;   // +0x12C
    TScrollBarPanel* scbar_panel;       // +0x130
    int auto_scbar;                     // +0x134
    short fixed_len;                    // +0x138
    char gap_13A[0x02];
    long text_wid;                      // +0x13C
    long text_hgt;                      // +0x140
    void* back_pic;                     // +0x144
    short back_pic_wid;                 // +0x148
    short back_pic_hgt;                 // +0x14A
    int fill_back;                      // +0x14C
    unsigned char back_color;            // +0x150
    char gap_151[0x03];
    int outline;                        // +0x154
    unsigned char outline_color;         // +0x158
    char gap_159[0x03];
    int sorted;                         // +0x15C
    long second_column_pos;             // +0x160
    long full_width;                    // +0x164
    long scbar_width;                   // +0x168
    int scbar_active;                   // +0x16C
    int bevel_type;                     // +0x170
    unsigned char bevel_color1;          // +0x174
    unsigned char bevel_color2;          // +0x175
    unsigned char bevel_color3;          // +0x176
    unsigned char bevel_color4;          // +0x177
    unsigned char bevel_color5;          // +0x178
    unsigned char bevel_color6;          // +0x179
    char gap_17A[0x02];
    void* clip_rgn2;                    // +0x17C

    virtual void set_rect(long left, long top, long width, long height);
    void calc_draw_info(int redraw);
};
#endif

void TTextPanel::set_rect(long left, long top, long width, long height) {
    int x;
    int y;
    tagRECT clip_rect2;

    TPanel::set_rect(left, top, width, height);
    this->full_width = this->pnl_wid;

    if (this->auto_scbar != 0 && this->scbar_panel != 0) {
        this->scbar_panel->set_active(0);
        this->scbar_active = 0;

        if (this->parent_panel != 0) {
            x = this->pnl_x - this->parent_panel->xPosition();
            y = this->pnl_y - this->parent_panel->yPosition();
        } else {
            x = this->pnl_x;
            y = this->pnl_y;
        }

        this->scbar_panel->set_fixed_position(
            x + this->full_width - this->scbar_width,
            y,
            this->scbar_width,
            this->pnl_hgt);
    }

    this->calc_draw_info(1);

    if (this->second_column_pos != 0) {
        if (this->clip_rgn2 != 0) {
            DeleteObject(this->clip_rgn2);
            this->clip_rgn2 = 0;
        }

        if (this->visible != 0) {
            clip_rect2 = this->clip_rect;
            clip_rect2.right = this->render_rect.left +
                               this->second_column_pos - 10;
            if (clip_rect2.right > this->clip_rect.right) {
                clip_rect2.right = this->clip_rect.right;
            }
            this->clip_rgn2 = CreateRectRgn(
                clip_rect2.left,
                clip_rect2.top,
                clip_rect2.right,
                clip_rect2.bottom);
        }
    }
}
