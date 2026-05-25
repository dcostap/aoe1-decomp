// VA: 004755C0 TEditPanel ctor (170B)
// pnl_edit.cpp lines 50-75
// Retry 2026-05-21 Boss pass: made ctor out-of-class so it emits, corrected layout for
// fields +0x80/+0x14C, added missing vtable and one-valued fields, tried direct/volatile/raw
// vtable stores, pointer-derived vtable store to prevent hoisting, local/register/derived `one`
// forms, assignment-chain vs separate one stores, inheritance/virtual vptr surface, and /G5 /Og
// flags. Best exact-size form is very close (7.6471% edit) but still misses original early
// `mov ecx,1` before zero stores; VC5 keeps scheduling the vtable store before zero stores or
// materializes one in EAX after them. Not accepted_drift: broad positional shift from instruction
// scheduling/order, although behavior is equivalent.
// Retry 2026-05-24 assigned pass: 14 further probes. Tried zero/one declaration order, volatile/register/const one, one-derived zero expressions, early field_80 store with and without dead overwrite, chained/literal/comma one stores, moving vptr last, and flags /Ob0 /Og /Oa /G5 /O1. All competitive variants either kept the same 13-byte edit diff or worsened. PROPOSED_ACCEPTED_DRIFT: exact size, same base ctor call, same field offsets/values, same vptr store and return; remaining drift is just scheduling/register choice for materializing constant 1 (`mov ecx,1` before zero stores in original vs `mov eax,1` after zero stores in rebuilt) and the three following one-stores use ECX vs EAX.

class TPanel { public: TPanel(); };

class TEditPanel {
public:
    void* vtable;
    char gap04[0x80 - 4];
    int field_80;
    char gap84[0xF4 - 0x84];
    int field_F4;
    short field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    char gap128[(0x14C - 0x128)];
    int field_14C;
    int field_150;
    char field_154, field_155, field_156, field_157, field_158, field_159;
    char gap15A[(0x15C - 0x15A)];
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    
    TEditPanel();
};

TEditPanel::TEditPanel() {
    ((TPanel*)this)->TPanel::TPanel();
    int one = 1;
    int zero = one ^ 1;
    field_F4 = zero;
    field_FC = zero;
    field_F8 = zero;
    field_108 = zero;
    field_110 = 0;
    field_114 = 0;
    field_118 = 0;
    field_11C = 0;
    field_120 = 0;
    field_124 = 0;
    field_14C = 0;
    field_154 = 0;
    field_155 = 0;
    field_156 = 0;
    field_157 = 0;
    field_158 = 0;
    field_159 = 0;
    field_15C = 0;
    field_160 = 0;
    field_164 = 0;
    field_168 = 0;
    *((int*)&field_F4 - 0xF4/4) = 0x5713A8;
    field_80 = one;
    field_104 = one;
    field_150 = one;
}
