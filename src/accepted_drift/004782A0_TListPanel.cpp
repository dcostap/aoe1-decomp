// VA: 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
// Attempt log:
// inherited tries 1-10: baseline/natural/manual stores, virtual/nonvirtual, /GX,/Od; best exact size but vptr hoisted before zero stores and ones used EAX.
// try 11: volatile int/byte store pointers preserved source order and delayed vptr; improved to exact size with only ECX-vs-EAX one-register family remaining (31.37% positional, 14.71% edit).
// try 12: separate zero and one locals with volatile stores; no allocation change.
// try 13: register-qualified one local; no allocation change.
// try 14: pointer-typed constant onep; no allocation change.
// try 15: volatile one stack local forced stack frame/loads and worsened broad diff; rolled back.
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent constant-register drift.
// Best source matches constructor call, size, field offsets, store order, vptr timing,
// and final values. Remaining differences are VC5 choosing EAX for constant 1 after
// zero stores instead of original preloading ECX=1 before zero stores; the five one-
// stores write the same value to the same addresses with no calls/predicates affected.

class TTextPanel {
public:
    void* vptr;
    TTextPanel();
    char gap_04[0x7C];
    int field_80;
    char gap_84[0x3C];
    int field_C0;
    char gap_C4[0x2A];
    unsigned char field_EE;
    char gap_EF[0x81];
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
};

class TListPanel : public TTextPanel {
public:
    int auto_track;
    int mouse_scroll_last_time;
    int mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
    TListPanel();
};

TListPanel::TListPanel() : TTextPanel() {
    volatile int* p = (volatile int*)this;
    volatile unsigned char* b = (volatile unsigned char*)this;
    int zero = 0;
    int one = 1;
    p[0x0C0/4] = zero;
    p[0x18C/4] = zero;
    p[0x194/4] = zero;
    p[0x198/4] = zero;
    p[0x188/4] = zero;
    p[0x19C/4] = one;
    p[0] = 0x00571578;
    b[0x0EE] = 4;
    p[0x170/4] = one;
    p[0x190/4] = 0x32;
    p[0x080/4] = one;
    p[0x184/4] = one;
    p[0x180/4] = one;
}
