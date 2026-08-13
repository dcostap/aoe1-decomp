// 0047CE70 TTextPanel::calc_draw_info
// Pnl_txt.cpp:769-833
//
// Canonical ownership:
//   - TPanel owns the rectangle, render area, visibility, and base set_rect.
//   - TTextPanel owns the line counters, font/spacing metrics, text dimensions,
//     and scrollbar layout state.
//   - TScrollBarPanel owns set_list_len and the virtual active-state slot.
//
// Attempt log:
// - Replaced the former count-only scaffold with the natural period panel
//   layout calculation: line height, clamped top/bottom/current lines, and
//   optional automatic scrollbar activation/deactivation.
// - Declared the old-style short line locals and used member-left bound
//   predicates; this reduced the reconstruction from 38 to 14 differing bytes
//   while preserving exact size, CFG, ordered calls, and all earlier blocks.
// - Corrected TPanel ownership to active +0x6C / visible +0x70 and retained
//   the real virtual set_active slot and explicit TPanel::set_rect call.
//   Scoped/final width temps, base receiver casts, and the TTextPanel virtual
//   set_rect context were codegen duplicates.  Final residual is only the
//   deactivation virtual-vtable scratch register plus the common text_wid
//   load register at +0x19A..+0x1F0; source remains canonical and typed.
// - Fresh Pnl_txt donor pass: the exact base virtual surface, scrollbar size
//   surface, explicit scrollbar active override, full TTextPanel field order,
//   and long text_wid type were all emitted-code duplicates; restored the
//   pinned narrow source surface.
// - Explicit terminal return, branch-local scrollbar receiver, and volatile
//   text_wid tests were duplicates. A six-case focused store/receiver lab also
//   stayed in the same 14-byte group. The Windows SDK context worsened drift
//   to 15 bytes at the line-clamp block and was restored.
// - Fresh mapped-assembly donors confirmed natural virtual-call examples that
//   use EDX for the vtable and EAX for a following result load.  No same-class
//   source lead explains this final register color, so the typed source stays.
// - Passed the stored zero scrollbar state as the second-branch set_active
//   argument; emitted code was unchanged, so restored the literal zero.
// - A natural long final_width local scoped to the common tail was a codegen
//   duplicate; restored the direct width assignment. The paired register
//   colors remain unchanged.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(class TDrawArea* draw, TPanel* parent,
                       long x, long y, long width, long height,
                       unsigned char flags);
    virtual void set_rect_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long width, long height);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);       // +0x14

    char gap_04[0x08];
    long x;                                    // +0x0C
    long y;                                    // +0x10
    long width;                                // +0x14
    long height;                               // +0x18
    char gap_1C[0x04];
    class TDrawArea* render_area;              // +0x20
    int clip_left;                             // +0x24
    int clip_top;                              // +0x28
    int clip_right;                            // +0x2C
    int clip_bottom;                           // +0x30
    char gap_34[0x0C];
    TPanel* parent_panel;                      // +0x40
    char gap_44[0x28];
    int active;                                // +0x6C
    int visible;                               // +0x70
    char gap_74[0x14];
    void* clip_rgn;                            // +0x88
    int render_left;                           // +0x8C
    int render_top;                            // +0x90
    int render_right;                          // +0x94
    int render_bottom;                         // +0x98
    char gap_9C[0x55];
    char clip_to_parent;                       // +0xF1
};

class TScrollBarPanel : public TPanel {
public:
    void set_list_len(int length, int top_line);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x04];
    short num_lines;                           // +0xF8
    short draw_lines;                           // +0xFA
    short top_line;                             // +0xFC
    short bot_line;                             // +0xFE
    short cur_line;                             // +0x100
    short cur_col;                              // +0x102
    char gap_104[0x08];
    int font_hgt;                               // +0x10C
    char gap_110[0x20];
    TScrollBarPanel* scbar_panel;              // +0x130
    int auto_scbar;                             // +0x134
    char gap_138[0x04];
    int text_wid;                               // +0x13C
    int text_hgt;                               // +0x140
    char gap_144[0x20];
    int full_width;                             // +0x164
    int scbar_width;                            // +0x168
    int scbar_active;                           // +0x16C
    int bevel_type;                             // +0x170
    unsigned char bevel_color1;                 // +0x174
    unsigned char bevel_color2;                 // +0x175
    unsigned char bevel_color3;                 // +0x176
    unsigned char bevel_color4;                 // +0x177
    unsigned char bevel_color5;                 // +0x178
    unsigned char bevel_color6;                 // +0x179
    char gap_17A[0x06];
    int border_size;                            // +0x180
    int spacer_size;                            // +0x184

    virtual void set_rect(long left, long top, long width, long height);
    void calc_draw_info(int recalc_scrollbar);
};

void TTextPanel::calc_draw_info(int recalc_scrollbar)
{
    short bottom_line;
    short number_lines;
    short visible_lines;
    int font_height;
    int available_height;
    int line_height;

    font_height = this->font_hgt;
    line_height = font_height + 2;
    this->text_hgt = line_height;

    if (font_height == 0) {
        this->draw_lines = 1;
    } else {
        if (this->spacer_size == 0) {
            available_height = this->height - this->border_size * 2;
        } else {
            available_height = this->height - this->border_size * 2;
            line_height += this->spacer_size * 2 - 1;
        }
        this->draw_lines = (short)(available_height / line_height);
    }

    if (this->draw_lines < 1) {
        this->draw_lines = 1;
    }

    number_lines = this->num_lines;
    if (this->top_line >= number_lines) {
        this->top_line = number_lines - 1;
    }

    visible_lines = this->draw_lines;
    if ((int)number_lines - (int)this->top_line < (int)visible_lines) {
        this->top_line = number_lines - visible_lines;
    }

    if (this->top_line < 0) {
        this->top_line = 0;
    }

    bottom_line = this->top_line - 1 + visible_lines;
    this->bot_line = bottom_line;
    if (bottom_line < 0) {
        this->bot_line = 0;
    }
    if (this->bot_line >= number_lines) {
        this->bot_line = number_lines - 1;
    }

    if (this->cur_line < 0) {
        this->cur_line = 0;
    }
    if (this->cur_line >= number_lines) {
        this->cur_line = number_lines - 1;
    }

    if (this->scbar_panel != 0) {
        if (recalc_scrollbar != 0) {
            this->scbar_panel->set_list_len(
                (int)number_lines - (int)visible_lines + 1,
                (int)this->top_line);
        }

        if (this->auto_scbar != 0) {
            if (this->num_lines > this->draw_lines) {
                if (this->scbar_active == 0) {
                    TPanel::set_rect(this->x, this->y,
                                     this->full_width - this->scbar_width,
                                     this->height);
                    this->scbar_active = 1;
                    if (this->active != 0) {
                        this->scbar_panel->set_active(1);
                        this->text_wid = this->width;
                        return;
                    }
                }
            } else if (this->scbar_active != 0) {
                TPanel::set_rect(this->x, this->y,
                                 this->full_width, this->height);
                this->scbar_active = 0;
                if (this->active != 0) {
                    this->scbar_panel->set_active(0);
                }
            }
        }
    }

    this->text_wid = this->width;
}
