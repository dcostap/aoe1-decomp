// VA: 0047A910 TScrollBarPanel::set_rect(long, long, long, long)
// PDB source: Pnl_scbr.cpp lines 139-193 (368 bytes, 95 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params, ret 10h. void return.
//
// Calls TPanel::set_rect then updates scrollbar rects based on orientation.
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
// New worker: function-scope/shared-range and in-place arithmetic variants improved emitted shape only to a duplicate
// 275-byte basin; virtual-member declaration with an explicit qualified base call preserved the direct ABI but made no
// body change. Restored the clean canonical tagRECT source; EBP still is not saved in the prologue.
// Fresh bounded pass (orch-pnlscbr-fresh-03):
// - Full Pnl_scbr/TPanel/TShape/windows.h context improved shape but added 5-8 bytes and was rolled back.
// - Direct inherited geometry expressions likewise added bytes; the full-class context was not retained.
// - Binary/Ghidra store ownership corrected horizontal tab_min_x to up_rect.right + 1 (not down_rect.right + 1).
// - Six shared temporaries improved the byte diff to 276 but introduced a stack home; four shared temporaries were
//   equivalent. Long-width and virtual-member ABI declarations were codegen duplicates.
// - A single shared range temporary was a duplicate/farther result. Final source keeps the natural typed geometry
//   reconstruction and the corrected tab minimum; remaining gap is prologue EBP/register topology.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TPanel {
    virtual ~TPanel();
    char gap_04[0x0C - 0x04];
    long pnl_x;                // +0x0C
    long pnl_y;                // +0x10
    long pnl_wid;              // +0x14
    long pnl_hgt;              // +0x18
    char gap_1C[0xF4 - 0x1C];
    void set_rect(long param_1, long param_2, long param_3, long param_4);
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
    int orientationValue;      // +0x1B4 (1 = horizontal)
    int bevel_type;             // +0x1B8
    unsigned char bevel_color1; // +0x1BC
    unsigned char bevel_color2; // +0x1BD
    unsigned char bevel_color3; // +0x1BE
    unsigned char bevel_color4; // +0x1BF
    unsigned char bevel_color5; // +0x1C0
    unsigned char bevel_color6; // +0x1C1
    unsigned char gap_1C2[2];   // +0x1C2

    void set_rect(long param_1, long param_2, long param_3, long param_4);
    void calc_item_rects();
};

void TScrollBarPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TPanel::set_rect(param_1, param_2, param_3, param_4);

    if (this->orientationValue == 1) {
        // Horizontal scrollbar layout
        int track = this->pnl_y;
        int button = this->pnl_hgt;
        int perp = this->pnl_wid;
        int margin = this->pnl_x;
        int top = track + 2;
        int bottom = button + track - 5;
        int up_left = margin + 2;
        int down_left = perp + margin - button + 2;
        int up_right = up_left + button - 5;
        int down_right = down_left + button - 5;
        int tab_min = up_right + 1;

        this->up_rect.top = top;
        this->down_rect.top = top;
        this->tab_rect.top = top;
        this->top_rect.top = top;
        this->bottom_rect.top = top;
        this->up_rect.left = up_left;
        this->down_rect.left = down_left;
        this->up_rect.bottom = bottom;
        this->up_rect.right = up_right;
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
        int track = this->pnl_y;
        int btn = this->pnl_hgt;
        int perp = this->pnl_wid;
        int margin = this->pnl_x;

        int top = track + 2;
        int scroll_range = btn + track - perp;
        int left = margin + 2;

        this->up_rect.top = top;

        int down_top = scroll_range + 2;
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

        int tab_max = scroll_range - perp + 6;
        this->tab_max_y = tab_max;

        int tab_min = right + 1;
        this->tab_min_y = tab_min;
        this->tab_y = tab_min;
    }

    this->calc_item_rects();
}
