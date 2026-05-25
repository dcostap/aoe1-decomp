// VA: 00475E50 TEditPanel::set_bevel_info
// PDB: pnl_edit.cpp lines 474-509 (168 bytes)
// Default flags, no inline asm/hacks.
// Previous scratch state: switch/jump-table, vtable slots, field offsets, and behavior all correct;
// remaining drift was register allocation/scheduling for byte parameter stores and set_rect arg loads.
// Current retry:
// 1: Revalidated baseline: exact size 168, 15.4762% positional / 28.5714% edit, first mismatch +1.
// 2: Added bc2 temp before first store to try to force original early `mov dl,[esp+0Ch]`; no change.
// 3: Added type temp and switched on it; no change.
// 4: Replaced rect locals with direct `set_rect(this->left,...)`; no change.
// 5: Reordered first stores (color2 before color1): slight edit improvement (27.3810%) but wrong
//    source/store order family and still broad register drift; rolled back.
// 6: Changed color formals to unsigned char; no improvement.
// 7: unsigned-char form plus color2-first: same slight edit-only improvement, not kept.
// 8: volatile c2 temp: worsened badly (88.6905% positional), rolled back.
// 9: Tail rect locals declared in lft/tp/rgt/btm order: no change from baseline.
// 10: tmp2/tmp1 byte temps: no change.
// 11-12: flag probes /Oa and /Og: no change, flags removed.
// Drift proposal: reasonable accepted_drift candidate if reviewed. Rebuilt is same size and has
// exact switch cases, stores to the same fields with the same values, same vtable calls/stack cleanup,
// and same jump-table control flow. Remaining byte diffs are register-coloring/instruction-encoding:
// early byte parameters AL/CL/DL are permuted vs original DL/CL/DL, and set_rect argument loads use
// EDX/EAX/ECX instead of EAX/ECX/EDX. No predicates, call slots, field offsets, or stack effects differ.

class TPanel {
public:
    virtual ~TPanel();
    virtual void v1();
    virtual void v2();
    virtual void set_rect(int left, int top, int right, int bottom);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set_redraw(int redraw);
    char gap_04[8];
    int left;
    int top;
    int right;
    int bottom;
};
class TEditPanel : public TPanel {
public:
    char gap_1C[0x134];
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_15A[2];
    int bevel_size;
    void set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6);
};
void TEditPanel::set_bevel_info(int type, int c1, int c2, int c3, int c4, int c5, int c6) {
    this->bevel_color1 = (unsigned char)c1;
    this->bevel_color2 = (unsigned char)c2;
    this->bevel_type = type;
    this->bevel_color3 = (unsigned char)c3;
    this->bevel_color4 = (unsigned char)c4;
    this->bevel_color5 = (unsigned char)c5;
    this->bevel_color6 = (unsigned char)c6;
    switch (type) {
    case 1:
    case 2:
    case 5:
        this->bevel_size = 1;
        break;
    case 3:
    case 6:
        this->bevel_size = 2;
        break;
    case 4:
    case 7:
        this->bevel_size = 3;
        break;
    default:
        this->bevel_size = 0;
        break;
    }
    int btm = this->bottom;
    int rgt = this->right;
    int tp = this->top;
    int lft = this->left;
    this->set_rect(lft, tp, rgt, btm);
    this->set_redraw(1);
}
