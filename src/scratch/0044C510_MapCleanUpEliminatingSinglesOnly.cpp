// PointMaker::MapCleanUpEliminatingSinglesOnly
// VA: 0044C510 - best version (10.4% diff)

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
                    int cVar6 = 0;
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
