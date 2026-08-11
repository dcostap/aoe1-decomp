// VA: 0047A910 TScrollBarPanel::set_rect(long, long, long, long)
// PDB source: Pnl_scbr.cpp lines 139-193 (368 bytes, 95 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params, ret 10h. void return.
//
// Calls TPanel::set_rect then updates scrollbar rects based on orientation.
#include <new.h>

// Attempt log:
// 1: baseline natural field reconstruction; exact size/calls but calc_item_rects was a free cdecl helper,
//    missing EBP and emitted explicit this push/add-esp around both calls.
// 2: made calc_item_rects a member; call ABI became thiscall, but source still had the wrong register/liveness basin.
// 3: restored the proven TPanel base size/vptr; emitted code was unchanged.
// 4: replaced offset aliases with canonical tagRECT members; diff improved to 282 bytes and size/calls stayed exact.
// 5: compound-update liveness variant moved farther (328 bytes); rolled back to the clean tagRECT candidate.
// Paused: ordered calls/CFG and exact field offsets are established, but the remaining gap is early register/block
// topology (not a behavior or call-set uncertainty). Next lead is a natural Pnl_scbr donor/source-order comparison,
// especially the branch-local declaration order that makes EBP live from the prologue in both orientation arms.
// Fresh bounded pass (sa3cf31e29_r1, probes 034-043):
// - Shared function-scope geometry results and source-order/store-order variants moved the emitted basin to
//   275-276 strict bytes; the best natural form is exact size with 3/3 ordered calls and 68.42% shape similarity.
// - A shared range accumulator recovered the original-size basin without stack spill; initializing it was a
//   codegen duplicate.  Reordered rectangle stores improved edit/resync diagnostics but not positional bytes.
// - The proven virtual base/override surface with a qualified TPanel::set_rect call preserved the direct call;
//   an unqualified virtual call was rejected because it emitted an indirect target.  <new.h> TU context was a
//   donor-supported duplicate and is retained as period-plausible context.
// - Full Windows header context, direct-width spelling, declaration reordering, and virtual-only surfaces were
//   nonproductive or worse.  Final blocker remains the original early EBP save/register topology; no behavior,
//   layout, boundary, or call-set uncertainty remains.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TPanel {
    virtual ~TPanel();
    char gap_04[0x0C - 0x04];
    int margin;                // +0x0C (panel edge offset)
    int track_size;            // +0x10 (track dimension in scroll direction)
    int perp_size;             // +0x14 (track dimension perpendicular to scroll)
    int button_size;           // +0x18 (arrow/button dimension)
    char gap_1C[0xF4 - 0x1C];
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
};

struct TScrollBarPanel : public TPanel {
    char gap_F4[0x124 - 0xF4];
    int tab_y;                 // +0x124
    int tab_min_y;             // +0x128
    int tab_max_y;             // +0x12C
    char gap_130[0x134 - 0x130];
    int tab_x;                 // +0x134
    int tab_min_x;             // +0x138
    int tab_max_x;             // +0x13C
    char gap_140[0x164 - 0x140];
    tagRECT up_rect;            // +0x164
    tagRECT down_rect;          // +0x174
    tagRECT tab_rect;           // +0x184
    tagRECT top_rect;           // +0x194
    tagRECT bottom_rect;        // +0x1A4
    int orientation;           // +0x1B4 (1 = horizontal)

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    void calc_item_rects();
};

void TScrollBarPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    int range;

    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->orientation == 1) {
        // Horizontal scrollbar layout
        int track = this->track_size;
        int button = this->button_size;
        int top = track + 2;
        int bottom = button + track - 5;
        int margin = this->margin;

        range = this->perp_size;
        range += margin;
        range -= button;
        int up_left = margin + 2;
        int down_left = range + 2;
        int down_right = down_left + button - 5;
        int tab_min = down_right + 1;

        this->up_rect.top = top;
        this->down_rect.top = top;
        this->tab_rect.top = top;
        this->top_rect.top = top;
        this->bottom_rect.top = top;
        this->up_rect.left = up_left;
        this->down_rect.left = down_left;
        this->up_rect.bottom = bottom;
        this->up_rect.right = up_left + button - 5;
        this->down_rect.bottom = bottom;
        this->down_rect.right = down_right;
        this->tab_min_x = tab_min;
        this->tab_x = tab_min;
        this->tab_max_x = down_left - button + 4;
        this->tab_rect.bottom = bottom;
        this->top_rect.bottom = bottom;
        this->bottom_rect.bottom = bottom;
    } else {
        // Vertical scrollbar layout
        int track = this->track_size;
        int button = this->button_size;
        int perp = this->perp_size;
        int margin = this->margin;

        range = button + track;
        range -= perp;
        int top = track + 2;
        int left = margin + 2;

        this->up_rect.top = top;

        int down_top = range + 2;
        this->down_rect.top = down_top;

        int right = perp + top - 5;
        this->up_rect.left = left;
        this->tab_rect.left = left;
        this->top_rect.left = left;
        this->bottom_rect.left = left;
        this->down_rect.left = left;

        int down_right = perp + left - 5;
        this->up_rect.right = down_right;
        this->up_rect.bottom = right;

        int down_bottom = down_top + perp - 5;
        this->down_rect.right = down_right;
        this->down_rect.bottom = down_bottom;
        this->tab_rect.right = down_right;
        this->top_rect.right = down_right;
        this->bottom_rect.right = down_right;

        int tab_max = range - perp + 6;
        this->tab_max_y = tab_max;

        int tab_min = right + 1;
        this->tab_min_y = tab_min;
        this->tab_y = tab_min;
    }

    this->calc_item_rects();
}
