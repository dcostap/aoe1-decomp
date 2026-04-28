// InfluenceMap::incrementValue
// VA: 0044E600
// infmap.cpp:240-257
// 123 bytes, ~11 byte diff (parked on VC5 register allocation quirk)
//
// Two stable codegen patterns regardless of source form:
// - Pattern A (112 bytes): only push esi, no byte masking (AND) — missing ~11 bytes
// - Pattern B (128 bytes): push esi+edi, with explicit AND masking — 5 bytes too big
//
// The original asm has 3 AND instructions (16 bytes total) for byte masking
// that come from partial register overwrite + full register read patterns.
// No C source variant found that generates these ANDs WITHOUT adding
// an extra callee-saved register (edi/ebx). VC5 register allocation quirk.
// Same behavior, same structure, same field layout.
// 4 relocations masked.
// 8+ source forms tried. Scoped variant_lab candidates documented below.

#include "../../include/game_globals.h"

struct InfluenceMap {
    char gap_00[4];
    int xSize;                // +0x04
    int ySize;                // +0x08
    int xReferencePoint;      // +0x0C
    int yReferencePoint;      // +0x10
    char gap_14[4];
    unsigned char** rowData;  // +0x18
    char gap_1C[8];
    unsigned char maxLimit;   // +0x24

    int incrementValue(int x, int y, unsigned char value);
};

int InfluenceMap::incrementValue(int x, int y, unsigned char value) {
    int rx = x - this->xReferencePoint;
    int ry = y - this->yReferencePoint;

    if (rx < 0 || ry < 0 || rx >= this->xSize || ry >= this->ySize)
        return 0;

    unsigned char* cell = this->rowData[ry] + rx;
    unsigned char cur = *cell;

    if (cur >= this->maxLimit)
        return 1;

    cur = cur + value;

    if (cur >= this->maxLimit) {
        *cell = this->maxLimit - 1;
        return 1;
    }

    *cell = cur;
    return 1;
}
