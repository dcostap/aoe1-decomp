// VA: 004E05C0 TribeInformationAIModule::undesirableLot
// taiinfmd.cpp:5898-5911
//
// Attempt log:
// v0: for loop with early return -> 176 bytes, 145-byte diff (82%)
// v1: do-while, explicit max local -> 176 bytes, similar diff
// v2: goto-based loop -> same as v1
// v3: for(;;) with if-break -> 176 bytes, 44-byte edit diff (25%) after splitting bounds
// v4: reordered i=0 before max=this->... -> fixed init order, 153 matching bytes
// v5: try continue -> same result
// v6-v7: coordOffset+x vs x+coordOffset for LEA operands -> no change
//
// Remaining diff (37 edit bytes, 21%):
// 1. Loop branch: VC5 generates jge+jmp instead of single jl at bottom
// 2. LEA operand order: [ecx+edi] vs [edi+ecx], [esi+edi] vs [edi+esi]
// 3. jle short vs jle near (consequence of #1 shifting offsets)
// 4. Loop-end return-0 epilogue merged with early-return (consequence of #1)
// All remaining diff is VC5 codegen register/encoding choices.
// Retry 2026-05-24 Boss pass: 14 probes. Revalidated baseline at exact-size 176B with 153 equal bytes, 37 edit bytes,
// first mismatch +27. Tried explicit goto labels for success/late zero, predeclared pLot to permit the goto, do-while/preincrement,
// if(max>0) wrapper, no-cast unsigned-char comparisons, reordered i/max declarations, and flags /Ob0 /Og /Ot /G5 /GB /Oa /O1.
// No source/flag variant beat the current family; /O1 shrank to 124B. Remaining diff is branch layout only (short jle + jge/jmp
// versus original near jle + bottom jl), epilogue placement/merge, and equivalent LEA base/index encodings; memory reads/writes,
// comparisons, loop bounds, and return values are unchanged. Candidate for accepted_drift if reviewer accepts localized layout/encoding drift.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct BuildingLot {
    int typeID;            // +0
    unsigned char status;  // +4
    unsigned char x;       // +5
    unsigned char y;       // +6
};

#endif
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap_1F4[0x1F4];
    int maxBuildingLots;    // +0x1F4
    BuildingLot* buildingLots; // +0x1F8

    int undesirableLot(int typeID, unsigned char xRange, unsigned char yRange, int coordOffset);
};
#endif

#endif
int TribeInformationAIModule::undesirableLot(int typeID, unsigned char xRange, unsigned char yRange, int coordOffset) {
    int i = 0;
    int max = this->maxBuildingLots;
    BuildingLot* pLot;

    if (max <= 0) {
        goto ret_zero_late;
    }

    pLot = this->buildingLots;

loop:
    if (pLot->typeID == typeID && pLot->status == 1) {
        int x = (int)pLot->x;
        int y = (int)pLot->y;
        int yMinusOff = y - coordOffset;
        int offPlusX = coordOffset + x;
        int xMinusOff = x - coordOffset;
        int offPlusY = coordOffset + y;

        if (xMinusOff <= (int)xRange && offPlusX >= (int)xRange &&
            yMinusOff <= (int)yRange && offPlusY >= (int)yRange) {
            goto ret_one;
        }
    }
    pLot++;
    i++;
    if (i < max) goto loop;
    return 0;

ret_one:
    return 1;
ret_zero_late:
    return 0;
}
