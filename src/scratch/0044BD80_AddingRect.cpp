// PointMaker::AddingRect
// VA: 0044BD80
//
// Attempt log:
// - The initial width/parallel-cursor reconstruction emitted a frame and a
//   507-byte body; it was replaced with the parameter-home loop shape.
// - Direct Width expressions plus the redundant nested edge guard removed the
//   frame and recovered the two edge-loop CFG and saturation blocks.
// - >= 1 bounds and int ProbabilityAdd temporaries reproduce the original
//   compare and dword signed-saturation topology.
// - The donor-era <stdlib.h>/<string.h> context is retained: it moved the
//   source into the 494-byte, 89.53%-shape / 62-edit-byte basin.
// - Ten probes exhausted this assignment. Remaining drift begins at the
//   initial row-count register copy and includes the later parameter-home /
//   register schedule; no calls or ABI uncertainties remain.

#include <stdlib.h>
#include <string.h>

class PointMaker {
public:
    int Prime_x;
    int Prime_y;
    int Point[1000];
    char gap_FA8[0x10];
    int x;
    int y;
    char gap_FC0[0x14];
    int Width;
    int Height;
    char gap_FDC[0x04];
    int NumNodes;
    char gap_FE4[0x08];
    int ProbabilityTiles;
    int TargetProbabilityCount;
    int ProbabilityAdd;
    int BranchRadius;
    int SatelliteRadius;
    int PrimaryRadius;
    int SizeArrays;
    int SatelliteDistance;
    int BranchDistance;
    int DirX;
    int DirY;
    int MaxNumberOfBranchLevels;
    int CurrentNumberOfBranchLevels;
    char* ExternalArray;
    char* ProbArray;
    char* PlacementArray;

    void AddingRect(int x, int y, int w, int h);
};

// The executable reuses the incoming argument homes as the two edge cursors
// and their countdowns.  Keep the source in the ordinary parameter-mutating
// form suggested by the PDB/decompiler rather than introducing a frame-sized
// collection of parallel cursor locals.
void PointMaker::AddingRect(int x, int y, int w, int h) {
    int iVar2;
    int iVar3;
    int iVar5;
    int iVar6;
    int iVar8;
    iVar5 = Width * y + x;
    iVar6 = w - x;
    iVar3 = h - y - 1;
    iVar8 = iVar3 * Width + iVar5;

    if (iVar6 >= 0) {
        if (h - y >= 0) {
            if (iVar6 >= 0) {
            w = iVar6 + 1;
            iVar2 = iVar5;
            do {
                int probAdd = ProbabilityAdd;
                if (iVar2 >= 1 && iVar2 < SizeArrays - 1) {
                    char* p = ProbArray + iVar2;
                    if (*p == 0) {
                        *p = (char)probAdd;
                        ProbabilityTiles++;
                    } else if (probAdd + (int)*p < 0xFF) {
                        *p = (char)(probAdd + (int)*p);
                    } else {
                        *p = (char)-1;
                    }
                }
                probAdd = ProbabilityAdd;
                if (iVar8 >= 1 && iVar8 < SizeArrays - 1) {
                    char* p = ProbArray + iVar8;
                    if (*p == 0) {
                        *p = (char)probAdd;
                        ProbabilityTiles++;
                    } else if (probAdd + (int)*p < 0xFF) {
                        *p = (char)(probAdd + (int)*p);
                    } else {
                        *p = (char)-1;
                    }
                }
                iVar8++;
                iVar2++;
                w--;
            } while (w != 0);
            }

            iVar5 += Width;
            if (iVar3 >= 0) {
                for (; iVar3 != 0; iVar3--) {
                int probAdd = ProbabilityAdd;
                if (iVar5 >= 1 && iVar5 < SizeArrays - 1) {
                    char* p = ProbArray + iVar5;
                    if (*p == 0) {
                        *p = (char)probAdd;
                        ProbabilityTiles++;
                    } else if (probAdd + (int)*p < 0xFF) {
                        *p = (char)(probAdd + (int)*p);
                    } else {
                        *p = (char)-1;
                    }
                }
                iVar8 = iVar6 + iVar5;
                probAdd = ProbabilityAdd;
                if (iVar8 >= 1 && iVar8 < SizeArrays - 1) {
                    char* p = ProbArray + iVar8;
                    if (*p == 0) {
                        *p = (char)probAdd;
                        ProbabilityTiles++;
                    } else if (probAdd + (int)*p < 0xFF) {
                        *p = (char)(probAdd + (int)*p);
                    } else {
                        *p = (char)-1;
                    }
                }
                iVar5 += Width;
                }
            }
        }
    }
}
