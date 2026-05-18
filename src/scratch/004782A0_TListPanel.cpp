// VA: 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
// Top-20 scratch retry attempt log:
// try 1: baseline explicit pointer arithmetic source: exact size 102B but broad store-order/vptr drift.
// try 2: corrected TTextPanel/TListPanel layout using generated reference: derived fields auto_track +0x188, mouse_scroll_last_time +0x18C, interval +0x190, up/down +0x194/+0x198, drawHighlightBar +0x19C.
// try 3: added virtual TListPanel destructor to coax natural vptr store; no improvement, compiler still stores vptr at start and uses EAX for ones.
// try 4: removed virtuals and used manual vptr store; offsets shifted by -4, exposing need for explicit vptr field in non-virtual stub.
// try 5: added explicit vptr field to non-virtual TTextPanel stub; offsets correct and size exact, but compiler hoists vptr store before zero stores and uses EAX=1 instead of ECX=1.
// try 6: used volatile vptr store to force ordering; no codegen change.
// try 7: rewrote body as raw pointer stores in original source order with local one=1; no codegen change, vptr still hoisted and one still EAX.
// try 8: /GX probe; no code/size change, removed flag.
// try 9: /Od probe; broad EBP-frame mismatch, removed flag.
// try 10: final validation default: exact size 102B but 69 positional diff bytes / 67.65%; mismatch is broad constructor store ordering/register choice, not accepted_drift candidate.
// GIVEUP: although final field values match, original delays vptr store until after early zero/one stores and carries one in ECX; rebuilt hoists vptr store and writes one fields with EAX in a different order. Constructor write ordering/vptr timing drift is too broad for accepted_drift.

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
    int one = 1;
    *(int*)((char*)this + 0x0C0) = 0;
    *(int*)((char*)this + 0x18C) = 0;
    *(int*)((char*)this + 0x194) = 0;
    *(int*)((char*)this + 0x198) = 0;
    *(int*)((char*)this + 0x188) = 0;
    *(int*)((char*)this + 0x19C) = one;
    *(int*)((char*)this + 0) = 0x00571578;
    *(unsigned char*)((char*)this + 0x0EE) = 4;
    *(int*)((char*)this + 0x170) = one;
    *(int*)((char*)this + 0x190) = 0x32;
    *(int*)((char*)this + 0x080) = one;
    *(int*)((char*)this + 0x184) = one;
    *(int*)((char*)this + 0x180) = one;
}
