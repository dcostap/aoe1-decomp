// 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
//
// Attempt log / blocker:
// - Natural inherited constructor calls TTextPanel::TTextPanel(), then VC5 emits the
//   TListPanel vptr store immediately after `xor eax,eax` and uses EAX for the later
//   constant-1 stores. Original needs `xor eax,eax; mov ecx,1`, five zero stores,
//   `field_19C=ecx`, then the TListPanel vptr store mid-body, followed by byte/one
//   stores in source order.
// - Prior work tried virtual/no-virtual combinations, derived/base/both
//   __declspec(novtable), manual vptr assignment, flat non-inherited TListPanel with
//   explicit base ctor call, volatile field stores, local `one = 1`, alternate vptr
//   source positions, /O1, and /Od+/GX. Best flat/manual basin removed C++ automatic
//   vptr scheduling but still hoisted the manual vptr store and used EAX for one.
// - 2026-05-10: verified target only. Re-tested natural inherited shape, then tried
//   flat raw-store variants with locals/const/register one, member-pointer local,
//   volatile vptr/byte/after-stores, all-base/all-derived novtable/manual-vptr mixes,
//   and flags /vd0 /vd1 /GR- /GX /Od /O2(no /Oy) /Ox /G5. No exact basin found.
//   Volatile-after flat variant reduced edit diff to 23 bytes but reordered real
//   stores (vptr early, field_19C late), so it is not a good accepted_drift candidate.
// - 2026-05-10 StarryZephyr pass: retried flat/manual base-ctor call with explicit vptr store after field_19C,
//   volatile vptr store plus register `one`, and a derived-member initializer-list hypothesis. Manual/volatile
//   flat forms still hoisted the vptr store immediately after `xor eax,eax` and used EAX for later one-stores;
//   initializer-list form either failed for base members or followed declaration/memory order, not source order.
//   Restored natural inherited source as the cleaner model.
// Left in scratch: natural source below is the cleaner typed model. Remaining mismatch
// is constructor vptr/constant scheduling and broad later store order, not localized
// enough for accepted_drift.

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
