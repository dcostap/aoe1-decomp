// Pnl_lst.cpp:26-41, 102 bytes
// attempt 1: 88.2%, EH code at start (push ecx + lea/call)
// attempt 2: 89.2%, non-virtual base still has EH code
// attempt 3: 82.4%, plain fn call has push esi + add esp,4
// attempt 4: __thiscall extern error C4234
// attempt 5: __fastcall on ctor compile error
// attempt 6: 56.9%, fn ptr still has push/add esp
// attempt 7: 96 bytes, no base call, no vptr
// attempt 8: 62.7%, vptr=0 at offset 10 shifts all later instructions
// attempt 9: 62.7%, same as 8
// attempt 10: 63.7%, explicit vptr assignment no help
// attempt 11: 62.7%, /GX same asm, 5 relocations masked (better)
// attempt 12: 96 bytes, no base call
// attempt 13: 62.7%, /GX same result
// attempt 14: 62.7%, no /GX same result
// attempt 15: 78.4%, /O1 worse
// BEST: 62.7% (attempts 8-11,13-14), /GX flags help with relocations
// BLOCKER: VC5 inserts vptr=0 safety init at offset 10 (after xor eax,eax).
//   Original has mov ecx,1 at that position instead. The 6-byte vptr=0 shifts
//   all subsequent instructions, causing field order and register differences.
//   Also: VC5 uses mov eax,1 (not ecx) for one-fields; field_190=0x32
//   appears after all ones (not between ones as in original).
// FLAGS: /GX
class TTTextPanel {
public:
    virtual ~TTTextPanel();
    TTTextPanel();
};

class TListPanel : public TTTextPanel {
public:
    char gap_04[0x80 - 0x04];
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

    TListPanel();
};

TListPanel::TListPanel() : TTTextPanel() {
    this->field_C0 = 0;
    this->field_18C = 0;
    this->field_194 = 0;
    this->field_198 = 0;
    this->field_188 = 0;
    this->field_19C = 1;
    this->field_170 = 1;
    this->field_190 = 0x32;
    this->field_80 = 1;
    this->field_184 = 1;
    this->field_180 = 1;
    this->field_EE = 4;
}
