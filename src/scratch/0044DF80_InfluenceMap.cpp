// InfluenceMap::InfluenceMap (constructor)
// VA: 0044DF80, infmap.cpp:26-36
// Status: PARKED in scratch - VC5 register/scheduling drift
//
// Attempt log:
// v0: virtual class, C++ constructor → EBP frame, vtable auto-write position mismatch
// v1: struct + __fastcall with dummy, manual vfptr → EBP kept for ySize param
// v2: field accesses for ySize/xSize → compiler still keeps params in regs
// v3: memset intrinsic → call not inline, size too small (144 bytes)
// v4: __thiscall member + memset pragma → compile error (undeclared)
// v5: string.h include → guarded fill loops, still EBP
// v6: C++ constructor (virtual) → auto-generated fill code, EBP
// v7: volatile params store+compute order → first 5 bytes match!
// v8: volatile params, single p var → 5-byte prologue match, still EBP
// v9: explicit v<<24 fill → correct 4-byte fill pattern, still EBP + guarded fill
//
// Remaining drift summary:
// 1. PROLOGUE: compiler saves EBP (extra callee-saved register). Original saves
//    ebx/esi/edi (3 regs) but mine saves ebx/ebp/esi/edi (4 regs). Root cause:
//    compiler keeps total >> 2 in EBP across the fill, while original reuses
//    volatile registers (ecx, edx) for total bookkeeping. Using volatile params
//    fixed the first 5 bytes to match exactly.
// 2. FILL: compiler adds zero-check guards before rep stosd/stosb (je short skip).
//    Original has unconditional rep stosd/stosb. This is VC5's loop idiom
//    recognition differing from the original build context.
// 3. FILL: byte fill uses dec/jne loop instead of rep stosb. Same root cause.
// 4. ROW LOOP: register allocation differs (original uses edi for both value
//    pointer and row pointer; mine uses separate registers).
// 5. All differences are stable VC5 codegen-family drift; behavior is equivalent.

void* __cdecl operator_new(size_t size);

struct InfluenceMap {
    int vfptr;          // 0x00
    int xSize;          // 0x04
    int ySize;          // 0x08
    int xRef;           // 0x0C
    int yRef;           // 0x10
    unsigned char* value;   // 0x14
    unsigned char** row;    // 0x18

    void Init(volatile int xSize, volatile int ySize, volatile int fillValue);
};

void InfluenceMap::Init(volatile int xSize, volatile int ySize, volatile int fillValue) {
    int total;
    unsigned char* p;
    int cnt;

    this->ySize = ySize;
    total = ySize * xSize;
    this->xSize = xSize;
    this->xRef = 0;
    this->yRef = 0;
    this->vfptr = 0x00570444;
    this->value = (unsigned char*)operator_new(total);
    p = this->value;

    {
        unsigned int v = (unsigned char)fillValue;
        v = v | (v << 8) | (v << 16) | (v << 24);
        unsigned int* q = (unsigned int*)p;
        for (cnt = total >> 2; cnt; cnt--) *q++ = v;
        unsigned char* r = (unsigned char*)q;
        for (cnt = total & 3; cnt; cnt--) *r++ = (unsigned char)fillValue;
    }

    this->row = (unsigned char**)operator_new(this->ySize * 4);
    if (this->row) {
        int offset = 0;
        for (int i = 0; i < this->ySize; i++) {
            this->row[i] = this->value + offset;
            offset += this->xSize;
        }
    }
}
