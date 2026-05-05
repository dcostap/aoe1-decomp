// VA: 0047A910 TScrollBarPanel::set_rect(long, long, long, long)
// PDB source: Pnl_scbr.cpp lines 139-193 (368 bytes, 95 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params, ret 10h. void return.
//
// Calls TPanel::set_rect then updates scrollbar rects based on orientation.

struct TPanel {
    void set_rect(long param_1, long param_2, long param_3, long param_4);
};

struct TScrollBarPanel {
    char gap_00[0x0C];
    int margin;                // +0x0C (panel edge offset)
    int track_size;            // +0x10 (track dimension in scroll direction)
    int perp_size;             // +0x14 (track dimension perpendicular to scroll)
    int button_size;           // +0x18 (arrow/button dimension)
    char gap_1C[0x124 - 0x1C];
    int tab_y;                 // +0x124
    int tab_min_y;             // +0x128
    int tab_max_y;             // +0x12C
    char gap_130[0x134 - 0x130];
    int tab_x;                 // +0x134
    int tab_min_x;             // +0x138
    int tab_max_x;             // +0x13C
    char gap_140[0x164 - 0x140];
    // RECT structs (left, top, right, bottom)
    int up_rect_left;          // +0x164
    int up_rect_top;           // +0x168
    int up_rect_right;         // +0x16C
    int up_rect_bottom;        // +0x170
    int down_rect_left;        // +0x174
    int down_rect_top;         // +0x178
    int down_rect_right;       // +0x17C
    int down_rect_bottom;      // +0x180
    int tab_rect_left;         // +0x184
    int tab_rect_top;          // +0x188
    int tab_rect_right;        // +0x18C
    int tab_rect_bottom;       // +0x190
    int top_rect_left;         // +0x194
    int top_rect_top;          // +0x198
    int top_rect_right;        // +0x19C
    int top_rect_bottom;       // +0x1A0
    int bottom_rect_left;      // +0x1A4
    int bottom_rect_top;       // +0x1A8
    int bottom_rect_right;     // +0x1AC
    int bottom_rect_bottom;    // +0x1B0
    int orientation;           // +0x1B4 (1 = horizontal)

    void set_rect(long param_1, long param_2, long param_3, long param_4);
};

void calc_item_rects(TScrollBarPanel*);

void TScrollBarPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    ((TPanel*)this)->set_rect(param_1, param_2, param_3, param_4);

    if (this->orientation == 1) {
        // Horizontal scrollbar layout
        int v10 = this->track_size;
        int v18 = this->button_size;
        int v14 = this->perp_size;
        int v0C = this->margin;

        int t1 = v10 + 2;
        int t2 = v18 + v10 - 5;
        int t3 = v14 + v0C;
        t3 = t3 - v18;
        int t4 = v0C + 2;

        this->up_rect_top = t1;
        this->down_rect_top = t1;
        this->tab_rect_top = t1;
        this->top_rect_top = t1;
        this->bottom_rect_top = t1;

        this->up_rect_left = t4;

        int t5 = t3 + 2;
        this->down_rect_left = t5;

        int t6 = t4 + v18 - 5;
        this->up_rect_bottom = t2;
        this->up_rect_right = t6;

        int t7 = t5 + v18 - 5;
        this->down_rect_bottom = t2;
        this->down_rect_right = t7;

        int t8 = t6 + 1;
        this->tab_min_x = t8;
        this->tab_x = t8;

        int t9 = t5 - v18 + 4;
        this->tab_max_x = t9;

        this->tab_rect_bottom = t2;
        this->top_rect_bottom = t2;
        this->bottom_rect_bottom = t2;
        this->down_rect_bottom = t2;
        this->down_rect_right = t7;
    } else {
        // Vertical scrollbar layout
        int track = this->track_size;
        int btn = this->button_size;
        int perp = this->perp_size;
        int margin = this->margin;

        int total = btn + track;
        int top = track + 2;
        int scroll_range = total - perp;
        int left = margin + 2;

        this->up_rect_top = top;

        int down_top = scroll_range + 2;
        this->down_rect_top = down_top;

        int right = perp + top - 5;
        this->up_rect_left = left;
        this->tab_rect_left = left;
        this->top_rect_left = left;
        this->bottom_rect_left = left;
        this->down_rect_left = left;

        int down_right = perp + left - 5;
        this->up_rect_right = down_right;
        this->up_rect_bottom = right;

        int down_bottom = down_top + perp - 5;
        this->down_rect_right = down_right;
        this->down_rect_bottom = down_bottom;
        this->tab_rect_right = down_right;
        this->top_rect_right = down_right;
        this->bottom_rect_right = down_right;

        int tab_max = scroll_range - perp + 6;
        this->tab_max_y = tab_max;

        int tab_min = right + 1;
        this->tab_min_y = tab_min;
        this->tab_y = tab_min;
    }

    calc_item_rects(this);
}
