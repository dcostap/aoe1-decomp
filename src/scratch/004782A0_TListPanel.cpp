// 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
// ========== BLOCKER: vptr=0 safety init ==========
// Our VC5 inserts `mov dword [esi], 0` (6-byte vptr-zero safety) where the
// 1998 build has `mov ecx, 1` (5 bytes). This 1-byte shift cascades through
// the entire function: different register allocation (eax vs ecx for const 1),
// different field grouping, different vtable-set position.
//
// Attempts:
// 1. Both virtual dtors (/O2): 62.7% - vptr=0 at orig mov ecx,1 position
// 2. No virtual dtors: 96 bytes, no vtable assignment at all
// 3. TListPanel virtual only: layout wrong (base at offset 4)
// 4. /O1 both virtual: 63.7% - vptr=0 at end, push/pop for const 1
// 5. Field reordering match: no effect - vptr=0 always inserted
//
// No C++ source or compiler flag fix found. VC5-version difference.
// The 1998 build also sets vtable mid-body (after some field stores), while
// our VC5 sets it immediately after base ctor. Two independent version diffs.

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
