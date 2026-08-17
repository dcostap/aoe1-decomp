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
// - The binary's duplicated edge gate is best expressed as the natural
//   arithmetic predicate `w - x >= 0`; moving the first cursor assignment
//   before that gate restores the complete first setup block.
// - The second and third edge updates use indexed ProbArray reads beside
//   their store pointers, matching the close fractal.cpp donor forms.
//   This reaches a 506-byte body, 94.19%-shape, and 31-edit-byte basin.
// - Direct `w >= x`, h/y parameter-home mutations, and a one-shot row-width
//   local were regressive or codegen duplicates and were not retained.
// - A typed `rowCount = iVar3` second-edge loop-counter copy was also a
//   codegen duplicate (506 bytes, diff 222); the clean source was restored.
// - A 16-variant lab of row-advance and vertical-loop spellings produced
//   only the existing 506-byte group or a 510-byte regressive group.
//   Remaining drift is the second-edge-row setup and later schedule; no
//   calls or ABI uncertainties remain.
// - Restored the reviewed PrimaryPt/PtToPt and mask-pointer PointMaker
//   ownership. It preserves all observed field offsets and emits the same
//   506-byte reconstruction.

#include <stdlib.h>
#include <string.h>

class PrimaryPt {
public:
    int x;
    int y;
};

class PtToPt {
public:
    int x;
    int y;
};

class PointMaker {
public:
    PrimaryPt Prime;
    PtToPt Point[500];
    char* Mask_2x2;
    char* Mask_3x3;
    char* Mask_4x4;
    char* Mask_5x5;
    int x;
    int y;
    int NumSplitsPerBranch;
    int NumberOfSatellites;
    int ChanceOfNextNode;
    int MaxNumberOfBranches;
    int MaxBranchFlag;
    int Width;
    int Height;
    int MinimumNumTiles;
    int NumNodes;
    int NumTilesActuallyChosen;
    int CurrentPoint;
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
            iVar2 = iVar5;
            if (w - x >= 0) {
            w = iVar6 + 1;
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
                    char value = ProbArray[iVar8];
                    if (value == 0) {
                        *p = (char)probAdd;
                        ProbabilityTiles++;
                    } else if (probAdd + (int)value < 0xFF) {
                        *p = (char)(probAdd + (int)value);
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
                    char value = ProbArray[iVar5];
                    if (value == 0) {
                        *p = (char)probAdd;
                        ProbabilityTiles++;
                    } else if (probAdd + (int)value < 0xFF) {
                        *p = (char)(probAdd + (int)value);
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
