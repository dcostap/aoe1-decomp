// EXACT OWNER: 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
//
// Translation-unit context: Pnl_lst.cpp. The wrapper supplies the canonical
// TPanel/TTextPanel/TListPanel surface. This local declaration is only the
// standalone checker fallback; the wrapper guard prevents duplicate classes.
//
// Exact-finish log:
// - The old accepted-drift source used volatile offset stores and an explicit
//   vptr write. It matched size and order but kept EAX for the one stores,
//   while the executable preloads ECX with 1 at +000A.
// - A natural polymorphic surface with ordinary member stores moved the vptr
//   to the entry and did not match. The exact source form initializes only
//   drawHighlightBar in the member-initializer list. VC5 then keeps the vptr
//   store after the first member group and preloads the one value in ECX.
// - Walkback: removing the explicit TTextPanel initializer stayed exact.
//   Removing explicit this qualifiers stayed exact. Moving drawHighlightBar
//   back to the body restored the prior nonexact vptr/register basin.
//
// BINARY NOTE: The constructor stores the inherited +0xC0, +0x80, +0x170,
// +0x180, and +0x184 fields as shown by the PDB line bands and assembly.
// Keep these assignments. They are not a second list or selection surface.

#ifndef AOE1_PNL_LST_CONTEXT_H
class TTextPanel {
public:
    virtual ~TTextPanel();
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
    int border_size;
    int spacer_size;
};

class TListPanel : public TTextPanel {
public:
    virtual ~TListPanel();
    int auto_track;
    int mouse_scroll_last_time;
    int mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
    TListPanel();
};
#endif

TListPanel::TListPanel() : drawHighlightBar(1) {
    field_C0 = 0;
    mouse_scroll_last_time = 0;
    mouse_scroll_up = 0;
    mouse_scroll_down = 0;
    auto_track = 0;
    field_EE = 4;
    field_170 = 1;
    mouse_scroll_interval = 0x32;
    field_80 = 1;
    spacer_size = 1;
    border_size = 1;
}
