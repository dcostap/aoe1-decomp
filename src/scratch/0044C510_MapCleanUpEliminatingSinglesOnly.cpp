// PointMaker::MapCleanUpEliminatingSinglesOnly
// VA: 0044C510 - best version (10.4% diff)
// 2026-05-19 retry:
// try 1: revalidated inherited best: exact size, 15 positional bytes / 10.4167%, only pointer-computation register/order hunk differs.
// try 2: introduced explicit offset local and PlacementArray+iVar7+offset; no codegen change.
// try 3: split offset *= width and pcVar3 += terms; no codegen change.
// try 4: delayed cVar6 declaration/assignment and register-qualified pcVar3/cVar6; no codegen change.
// try 5: changed cVar6 to char; worsened broad register allocation, rolled back.
// GIVEUP: remaining drift is localized to inner pointer computation: original uses EAX=row (EBX*width), loads PlacementArray in ESI, adds EDI then ESI, then reuses ESI as count; rebuilt loads PlacementArray into EBP early and zeros ESI before imul. Behavior/size otherwise match; not proposing accepted_drift without approval because it is a nontrivial address-generation/register-topology hunk.

class PointMaker {
public:
    char gap_00[0xFD4];
    int Width;
    int Height;
    char gap_FDC[0x4C];
    char* PlacementArray;
    void MapCleanUpEliminatingSinglesOnly();
};

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
