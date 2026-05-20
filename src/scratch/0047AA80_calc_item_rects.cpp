// 0047AA80 TScrollBarPanel::calc_item_rects
// Size: 146 bytes
// Retry 2026-05-19/20 assigned pass:
// - Revalidated inherited near-source: build emits only 144B for configured 146B, so check_function stops before producing rebuilt disassembly.
// - Removed register `r` and block-scoped the up-rect temp: still 144B.
// - Reordered `r++` to match original later `inc esi` placement after down-rect load: still 144B.
// - /Ob0 flag probe and dummy local/increment probe did not change emitted size; flag/probe removed.
// - Direct expression form (no r/dl locals) still emitted 144B and optimized to no saved ESI.
// - register r no change; volatile r overgrew to 176B and badly changed scheduling.
// - switch form and inverted if/else branch form both stayed 144B, no exact.
// - /O1 shrank to 141B; /O2 without /Oy and /Ob0 stayed 144B; flags removed.
// Retry 2026-05-20 assigned pass:
// - Revalidated current source: configured 146B exceeds rebuilt 144B; compiler uses push ecx stack temp, not original push/pop ESI.
// - Tried plain block-scoped x/w/r/dl locals with r++ before and after x--; still 144B.
// - Tried all locals top-declared x/w/r/dl; still 144B.
// - Tried source ordered to mirror original exactly (load tab, width, up edge, stores, then down edge); still 144B.
// - Tried switch(orientation) with case 1/default; still 144B.
// - Flag probes /Og-, /Oi, /Gr, /Gf, and /O2 without /Oy: only /Og- reached 146B but was a totally wrong 95.9% positional family; others stayed 144B. Flags removed.
// - Tried register combinations for r/dl/x/w; still 144B.
// - Tried volatile orientation to force a 146B body; produced broad wrong 108-byte positional diff and not the original ESI save.
// - Tried self alias to alter this lifetime; still 144B.
// GIVEUP: behavior and offsets are understood and source is close, but blocker is a 2-byte size/scheduling difference. Current object disassembly shows compiler emits no saved ESI (or stack-temp family) and appends/truncates at 144B, while original uses push/pop ESI and 146B. No accepted_drift proposed due size/register topology mismatch.

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

void TScrollBarPanel::calc_item_rects() {
    int x, w, dl;

    if (this->orientation == 1) {
        x = this->tab_x;
        w = this->field_18;
        register int r = this->up_rect_right;
        this->tab_rect_left = x;
        w = w + x - 5;
        x--;
        this->tab_rect_right = w;
        this->top_rect_right = x;
        dl = this->down_rect_left;
        r++;
        w++;
        dl--;
        this->top_rect_left = r;
        this->bottom_rect_left = w;
        this->bottom_rect_right = dl;
    } else {
        x = this->tab_y;
        w = this->field_14;
        register int r = this->up_rect_bottom;
        this->tab_rect_top = x;
        w = w + x - 5;
        x--;
        this->tab_rect_bottom = w;
        this->top_rect_bottom = x;
        dl = this->down_rect_top;
        r++;
        w++;
        dl--;
        this->top_rect_top = r;
        this->bottom_rect_top = w;
        this->bottom_rect_bottom = dl;
    }
}
