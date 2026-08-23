// PointMaker::MapCleanUpEliminatingSinglesOnly
// VA: 0044C510 - ACCEPTED_DRIFT (10.4167% positional / localized address-generation register scheduling)
// ACCEPTED_DRIFT 2026-05-20 Boss: exact size; only differing hunk computes the same PlacementArray + row*Width + col address with EBP/early zeroed ESI instead of original ESI-then-reused-as-count schedule. Neighbor comparisons, loop bounds, store, and epilogues are byte-identical; behavior-equivalent localized VC5 register/scheduling drift.
// 2026-05-19 retry:
// try 1: revalidated inherited best: exact size, 15 positional bytes / 10.4167%, only pointer-computation register/order hunk differs.
// try 2: introduced explicit offset local and PlacementArray+iVar7+offset; no codegen change.
// try 3: split offset *= width and pcVar3 += terms; no codegen change.
// try 4: delayed cVar6 declaration/assignment and register-qualified pcVar3/cVar6; no codegen change.
// try 5: changed cVar6 to char; worsened broad register allocation, rolled back.
// try 6: explicit row/base/pcVar3 pointer steps; no codegen change.
// try 7: non-register cVar6; no codegen change.
// try 8: declare row before width; no codegen change.
// try 9: /Ob0 flag probe; no codegen change, removed flag.
// try 10: /G5 flag probe; no codegen change, removed flag.
// try 11: alternate address expression iVar7 + (row + PlacementArray); no codegen change.
// try 12: volatile PlacementArray forced different address basin and worsened to 88 positional bytes; rolled back.
// try 13: boolean initializer for cVar6 used setg/register reshuffle and worsened to 98 positional bytes; rolled back.
// GIVEUP: remaining drift is localized to inner pointer computation: original uses EAX=row (EBX*width), loads PlacementArray in ESI, adds EDI then ESI, then reuses ESI as count; rebuilt loads PlacementArray into EBP early and zeros ESI before imul. Behavior/size otherwise match; not proposing accepted_drift without approval because it is a nontrivial address-generation/register-topology hunk.
// Retry 2026-05-20 assigned pass: 18 more probes. Tried prod/base/row pointer variants, casted integer address order, separate pcVar3 assignment, register base/prod/pc, placement local before/after width, dependency zero initializers for cVar6, volatile cVar6, and flags /Oa /Og /Ot /G6 /GB /Gr. All non-volatile source variants stayed at the same exact-size 15-byte localized pointer-computation hunk; volatile and /Oa worsened broadly; /G6 moved first mismatch earlier. GIVEUP/propose accepted_drift: current diff is localized, behavior-equivalent address-generation/register scheduling only (EBP-vs-ESI base and early `xor esi,esi`), with the neighbor tests, loop bounds, stores, and epilogues byte-identical.

#ifndef FRACTAL_ARRAYS_CONTEXT_H
class PointMaker {
public:
    char gap_00[0xFD4];
    int Width;
    int Height;
    char gap_FDC[0x4C];
    char* PlacementArray;
    void MapCleanUpEliminatingSinglesOnly();
};
#endif

void PointMaker::MapCleanUpEliminatingSinglesOnly() {
    int iVar4 = Height - 1;
    int iVar5 = 1;
    int iVar2 = Width - 1;
    if (1 < iVar4) {
        do {
            int iVar7 = 1;
            if (1 < iVar2) {
                do {
                    int iVar1 = Width;
                    char* pcVar3 = PlacementArray + iVar5 * iVar1 + iVar7;
                    register int cVar6;
                    cVar6 = 0;
                    if (pcVar3[-iVar1] > 0) cVar6 = 1;
                    if (pcVar3[-1] > 0) cVar6++;
                    if (pcVar3[1] > 0) cVar6++;
                    if (pcVar3[iVar1] > 0) cVar6++;
                    if (*pcVar3 != 0 && cVar6 == 0) {
                        *pcVar3 = 0;
                    }
                    iVar7++;
                } while (iVar7 < iVar2);
            }
            iVar5++;
        } while (iVar5 < iVar4);
    }
}
