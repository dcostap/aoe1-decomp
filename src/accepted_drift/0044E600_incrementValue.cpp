// VA: 0044E600 InfluenceMap::incrementValue
// PDB: infmap.cpp lines 240-257 (123 bytes, 45 asm lines)
// Default flags. No inline asm/hacks.
// Prior scratch history summary:
// - Many baseline variants were tried before this pass: parameter mutation, x/y temp order,
//   named rowData/limit/row/cell/cur locals, direct row[rx] stores, nested positive bounds,
//   int/uchar/schar/uint value signatures, register/volatile params, /Ob0 and other flag probes.
// - Best prior family matched first 22 bytes but kept broad register drift in the cell/sum hunk.
// Current Boss retry:
// 1: Revalidated prior best with `cur < limit` body: 63.4146% positional / 30.8943% edit,
//    first mismatch +22. It got exact coordinate setup but used `add edx,eax` cell pointer,
//    stack-spilled/alternate cur handling, and shifted tails.
// 2: Introduced `row = rows[ry]` and `cell = row + rx`; worsened badly with extra EBX save,
//    first mismatch +7.
// 3: Removed `cur` local and reloaded through row/cell expressions; improved to 60.1626%
//    positional / 30.8943% edit but still used EDX as cell.
// 4-5: Split sum into two statements and reversed add operands; no codegen change.
// 6-7: Changed value signature to int/uint; no codegen change for the best basin.
// 8: Rewrote as explicit early `if (*cell >= maxLimit) return 1;`; improved edit diff to
//    14.6341% and exactly recovered the original `cmp al,cl; jb body; mov eax,1; pop; ret`
//    block layout. Remaining hunk still uses `add edx,eax; mov al,[edx]` instead of original
//    `lea esi,[edx+eax]; mov al,[edx+eax]`, and uses EAX/ESI for sum/limit instead of
//    original EDX/EAX with ESI as cell.
// 9: Named `cur` under early-return shape; worsened (26.0163% edit). `int cur` worsened to
//    86.1789% positional.
// 10: `cell = row; cell += rx`/row local attempt again forced EBX and worsened.
// 11: Tried /O1 as a narrow flag probe; object .text too small (86B), flag removed.
// 12-14: `register` on cell/sum and reversed final add operands; no codegen change.
// Proposed accepted_drift candidate: current source is behavior-equivalent and the remaining
// diff is a localized VC5 register/addressing-choice drift in the cell/saturating-add block
// (EDX cell pointer via `add` vs original ESI cell via `lea`; EAX/ESI sum/limit vs original
// EDX/EAX; shifted branch displacements/tails follow from the two-byte body-size difference).
// No calls, stack cleanup, memory offsets, predicates, or stores differ semantically.

#ifndef INFMAP_SHARED_CONTEXT
struct InfluenceMap {
    int vtable;                  // +0x00
    int xSizeValue;              // +0x04
    int ySizeValue;              // +0x08
    int xReferencePointValue;    // +0x0C
    int yReferencePointValue;    // +0x10
    unsigned char* valueValue;   // +0x14
    unsigned char** rowValue;    // +0x18
    int coverageCount;           // +0x1C
    int connectionCount;         // +0x20
    unsigned char unchangeableLimitValue; // +0x24

    int incrementValue(int x, int y, unsigned char value);
};
#endif

int InfluenceMap::incrementValue(int x, int y, unsigned char value) {
    int rx = x - this->xReferencePointValue;
    int ry = y - this->yReferencePointValue;

    if (rx < 0 || ry < 0 || rx >= this->xSizeValue || ry >= this->ySizeValue)
        return 0;

    unsigned char** rows = this->rowValue;
    unsigned char* cell = &rows[ry][rx];

    if (*cell >= this->unchangeableLimitValue)
        return 1;

    int sum = (int)(unsigned char)*cell + (int)(unsigned char)value;
    if (sum >= (int)(unsigned char)this->unchangeableLimitValue) {
        *cell = (unsigned char)((int)(unsigned char)this->unchangeableLimitValue - 1);
        return 1;
    }
    *cell = (unsigned char)sum;
    return 1;
}
