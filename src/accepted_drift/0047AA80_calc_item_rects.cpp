// 0047AA80 TScrollBarPanel::calc_item_rects
// Size: 146 bytes
// ACCEPTED_DRIFT proposal (2026-05-21): exact size and behavior-equivalent.
// Diff is localized to two repeated scheduling hunks, one in each orientation arm.
// Original schedules `inc r; dec x; store tab_end; store top_end; load down; inc tab_end; dec down`.
// Rebuilt schedules `dec x; store top_end; load down; store tab_end; inc r; inc tab_end; dec down`.
// The moved operations are independent within the arm: r increment feeds only the later top-left/top-top store,
// tab_end store and top_end store write distinct fields, and the down_rect load overwrites EAX only after the
// decremented x has already been stored. Branch layout, sizes, field offsets, and final stores match.
// This is not a predicate/call/stack cleanup/memory-effect change, just VC5 instruction scheduling drift.
//
// Prior scratch attempts (summarized): inherited close source emitted 144B without saved ESI; many source/flag
// variants (/Ob0, /O1, /O2 no /Oy, /Og-, /Oi, /Gr, /Gf; block-scoped/top-declared locals, switch, register locals,
// self alias, volatile orientation) either stayed 144B or entered wrong broad basins. A volatile read of the
// down_rect field forces the original 146B saved-ESI size while leaving only the localized scheduling drift above.

#ifndef PNL_SCBR_CANONICAL_TU
class TScrollBarPanel {
public:
    char gap_00[0x14];
    int field_14;              // +0x14 (vertical scrollbar height)
    int field_18;              // +0x18 (horizontal scrollbar width)
    char gap_1C[0x108];        // +0x1C to +0x123
    int tab_y;                 // +0x124
    char gap_128[0x0C];        // +0x128 to +0x133
    int tab_x;                 // +0x134
    char gap_138[0x34];        // +0x138 to +0x16B
    int up_rect_right;         // +0x16C (H)
    int up_rect_bottom;        // +0x170 (V)
    int down_rect_left;        // +0x174 (H)
    int down_rect_top;         // +0x178 (V)
    char gap_17C[8];           // +0x17C to +0x183
    int tab_rect_left;         // +0x184 (H)
    int tab_rect_top;          // +0x188 (V)
    int tab_rect_right;        // +0x18C (H)
    int tab_rect_bottom;       // +0x190 (V)
    int top_rect_left;         // +0x194 (H)
    int top_rect_top;          // +0x198 (V)
    int top_rect_right;        // +0x19C (H)
    int top_rect_bottom;       // +0x1A0 (V)
    int bottom_rect_left;      // +0x1A4 (H)
    int bottom_rect_top;       // +0x1A8 (V)
    int bottom_rect_right;     // +0x1AC (H)
    int bottom_rect_bottom;    // +0x1B0 (V)
    int orientation;           // +0x1B4

    void calc_item_rects();
};
#endif

void TScrollBarPanel::calc_item_rects()
{
#ifdef PNL_SCBR_CANONICAL_TU
    int x, w, r, dl;

    if (this->orientationValue == 1) {
        x = this->tab_x;
        w = this->field_18;
        r = this->up_rect.right;
        this->tab_rect.left = x;
        w = w + x - 5;
        x--;
        this->tab_rect.right = w;
        this->top_rect.right = x;
        dl = *(volatile int*)&this->down_rect.left;
        r++;
        w++;
        dl--;
        this->top_rect.left = r;
        this->bottom_rect.left = w;
        this->bottom_rect.right = dl;
    } else {
        x = this->tab_y;
        w = this->field_14;
        r = this->up_rect.bottom;
        this->tab_rect.top = x;
        w = w + x - 5;
        x--;
        this->tab_rect.bottom = w;
        this->top_rect.bottom = x;
        dl = *(volatile int*)&this->down_rect.top;
        r++;
        w++;
        dl--;
        this->top_rect.top = r;
        this->bottom_rect.top = w;
        this->bottom_rect.bottom = dl;
    }
#else
    int x, w, r, dl;

    if (this->orientation == 1) {
        x = this->tab_x;
        w = this->field_18;
        r = this->up_rect_right;
        this->tab_rect_left = x;
        w = w + x - 5;
        x--;
        this->tab_rect_right = w;
        this->top_rect_right = x;
        dl = *(volatile int*)&this->down_rect_left;
        r++;
        w++;
        dl--;
        this->top_rect_left = r;
        this->bottom_rect_left = w;
        this->bottom_rect_right = dl;
    } else {
        x = this->tab_y;
        w = this->field_14;
        r = this->up_rect_bottom;
        this->tab_rect_top = x;
        w = w + x - 5;
        x--;
        this->tab_rect_bottom = w;
        this->top_rect_bottom = x;
        dl = *(volatile int*)&this->down_rect_top;
        r++;
        w++;
        dl--;
        this->top_rect_top = r;
        this->bottom_rect_top = w;
        this->bottom_rect_bottom = dl;
    }
#endif
}
