// TInputPanel::TInputPanel
// VA: 00476C10, Pnl_inp.cpp:36-41
// Status: MATCHED 2026-05-26
//
// Attempt log:
// v0: Plain constructor with gaps -> 144 bytes, no SEH, no base ctor call.
// v1: Added TTextPanel() declaration to init list -> still 144, VC5 skips EH frame.
// v2: Added TTextPanel ctor definition + /GX flags -> 160 bytes, wrong COMDAT/order.
// v3: Added real field back_color to TTextPanel -> same 160 bytes.
// earlier parked: same constructor SEH challenge as 00506240/005067D0; needed base ctor
// and lightweight VC5 /GX constructor frame without defining helper COMDATs in this TU.
// Retry 2026-05-26 Boss pass: tried visible virtual base/derived destructors with raw
// offset stores (exact-size but 87 positional / 26 edit), derived-only virtual (broad
// byte-0 mismatch), initializer-list scalar form (short), novtable virtual surface
// (also matched), empty dtor definition (short/COMDAT), and manual base ctor in body
// (short/wrong). Winning minimal source declares non-virtual base/derived destructors
// (declarations only) plus real base constructor in initializer list and raw observed
// field stores. The destructor declarations are enough under /GX to trigger the original
// lightweight constructor EH frame/base cleanup context without emitting extra COMDATs.

extern "C" __declspec(dllimport) unsigned long __stdcall GetCaretBlinkTime();

struct TTextPanel {
    char gap[0x188];
    TTextPanel();
    ~TTextPanel();
};

struct TInputPanel : TTextPanel {
    char rest[0x30];
    TInputPanel();
    ~TInputPanel();
};

TInputPanel::TInputPanel() : TTextPanel()
{
    *(unsigned char*)((char*)this + 0x188) = 0;
    *(int*)((char*)this + 0x18C) = GetCaretBlinkTime();
    *(int*)((char*)this + 0x190) = 0;
    *(int*)((char*)this + 0x194) = 1;
    *(int*)((char*)this + 0x1B0) = 1;
    *(int*)((char*)this + 0x80) = 1;
    *(int*)((char*)this + 0x170) = 1;
    *(int*)((char*)this + 0x198) = 0;
    *(int*)((char*)this + 0x1A0) = 0;
    *(int*)((char*)this + 0x1A4) = 0;
    *(int*)((char*)this + 0x1A8) = 0;
    *(short*)((char*)this + 0x1AC) = 0;
    *(short*)((char*)this + 0x1AE) = 0;
    *(short*)((char*)this + 0x1B4) = 0;
    *(int*)this = 0x571488;
    *(char*)((char*)this + 0xEE) = 7;
    *(int*)((char*)this + 0x114) = 5;
}
