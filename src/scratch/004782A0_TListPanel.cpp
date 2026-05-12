// 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
//
// Status: STUCK — constructor vtable scheduling + register allocation mismatch.
//
// Blocker: VC5's constructor optimizer makes different global choices for
// register allocation (1 reg vs 2 regs) and vtable store placement (early vs
// mid-body) that are not controllable through source form or standard flags.
// - Original: xor eax/mov ecx (2 registers); zero stores use eax, one stores use
//   ecx; vtable stored mid-body after field_19C=1 before field_EE=4.
// - Rebuilt: xor eax only (1 register); eax used for zeros then reassigned to 1
//   for ones; vtable zeroed at very beginning (or omitted).
// This is a deep optimizer-internal heuristic, not a surface-shape issue.
// 63 positional diff bytes (61.76%) — too large for accepted_drift.
//
// Attempt log:
// - Pre-existing passes (GraniteCub, SpruceGlow, StarryZephyr): 50+ variants over
//   virtual/no-virtual, novtable/manual-vptr, flat/inherited, volatile stores,
//   local consts, /O1/Od/Ox/G5 flags. Best: 61.76% positional, 55.88% edit.
// - 2026-05-12 (this pass): Variants 1-7:
//   V1: Proper class hierarchy with virtual functions (62.75%)
//   V2: Flat class with manual vtable via global (81.37%)
//   V3: Flat class with virtual functions, TTextPanel ctor thunk (81.37%)
//   V4: Natural inherited, store order matched to original asm (61.76%)
//   V5: TListPanel with virtual overrides (~dtor, handle_idle) (61.76%)
//   V6: __declspec(novtable) + manual vtable mid-body (75.49%)
//   V7: Local `int one = 1` to try forcing 2-reg allocation (61.76%)
//   None improved beyond the natural baseline.
//
// No accepted_drift: 61.76% positional diff is structural, not localized.
// No inline asm/hacks. Left in scratch.

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
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
};

class TListPanel : public TTextPanel {
public:
    TListPanel();
};

TListPanel::TListPanel() : TTextPanel() {
    this->field_C0 = 0;
    this->field_18C = 0;
    this->field_194 = 0;
    this->field_198 = 0;
    this->field_188 = 0;
    this->field_19C = 1;
    this->field_EE = 4;
    this->field_170 = 1;
    this->field_190 = 0x32;
    this->field_80 = 1;
    this->field_184 = 1;
    this->field_180 = 1;
}
