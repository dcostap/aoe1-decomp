// PointMaker::DrawMask
// VA: 0044AFE0 - draws one distance mask into the probability array.
//
// Attempt log:
// - The binary and exact fractal.cpp donors prove PointMaker ownership for the
//   four mask pointers at +0xFA8..+0xFB4, Width/Height at +0xFD4/+0xFD8,
//   ProbabilityTiles at +0xFEC, SizeArrays at +0x1004, and ProbArray at
//   +0x1024.
// - The prior source used independent mask-row, mask-column, width, height,
//   and cursor locals. The target instead reuses the incoming parameter homes:
//   param_1 becomes the mask pointer, param_2 becomes the clipped width, and
//   param_3 becomes the inner countdown. This source follows that proven
//   ownership and the decompiler's natural loop shape.
// - The target performs a first outer-count test, then runs a post-tested inner
//   loop and a bottom-tested outer loop. The source keeps those distinct.
// - This is an unresolved structural probe. Exact validation is recorded in
//   the target session notebook.
// - BINARY NOTE: The mask sample is sign-extended before the first bounds
//   test. An int sample preserves this operation and the best current diff.
// - BINARY NOTE: A guarded post-tested outer loop preserves the target's first
//   row-count test and bottom countdown. The current fresh diff is 474 bytes.
// - Header and reviewed full-context probes changed the basin without an exact
//   result. The source keeps the smallest local class surface and no alias
//   used only to steer code generation.

#ifndef FRACTAL_ARRAYS_CONTEXT_H
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
    char* WritableExternalArray;
    int DoNotDrawOnFlag;
    int DrawOnOnlyFlag;
    int DrawOnlyInExternalArrayFlag;
    int DrawToOneArrayFlag;
    int BorderDepthPercentage;
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;
    char SpecialLandType;
    char pad_end[3];

protected:
    void DrawMask(int param_1, int param_2, int param_3);
};
#endif

void PointMaker::DrawMask(int param_1, int param_2, int param_3) {
    int iVar1;
    int cVar3;
    char cVar4;
    char* pcVar2;
    int len;
    int iVar6;
    int iVar7 = param_1;
    int iVar8;
    int iVar9;

    if (iVar7 > Width) return;
    if (param_2 > Height) return;
    if (param_3 + 2 + iVar7 < 0) return;
    if (param_3 + 2 + param_2 < 0) return;

    iVar9 = Width;
        iVar1 = param_3 + 2;
        iVar6 = param_2;
        if (param_3 == 2) {
            if (iVar7 + 4 <= iVar9 && iVar7 < 0) {
                iVar7 = 0;
            }
            if (param_2 + 4 <= Height && param_2 < 0) {
                iVar6 = 0;
            }
        }
        if (param_3 == 3) {
            if (iVar7 + 5 <= iVar9 && iVar7 < 0) {
                iVar7 = 0;
            }
            iVar6 = param_2;
            iVar6 += (unsigned)(Height < 5);
        }

        if (param_3 == 4) {
            param_1 = (int)Mask_4x4;
            param_2 = iVar7 + 6;
            if (iVar9 < param_2) {
                param_2 = iVar9 - iVar7;
            } else if (iVar7 < 0) {
                param_1 = param_1 - iVar7;
                iVar7 = 0;
            } else {
                param_2 = 6;
            }
            iVar8 = iVar6 + 6;
            if (Height < iVar8) {
                iVar8 = Height - iVar6;
            } else if (iVar6 < 0) {
                param_1 = param_1 - iVar6 * iVar9;
                iVar6 = 0;
            } else {
                iVar8 = 6;
            }
        } else {
            param_1 = (int)Mask_5x5;
            param_2 = iVar7 + 7;
            if (iVar9 < param_2) {
                param_2 = iVar9 - iVar7;
            } else if (iVar7 < 0) {
                param_1 = param_1 - iVar7;
                iVar7 = 0;
            } else {
                param_2 = 7;
            }
            iVar8 = iVar6 + 7;
            if (Height < iVar8) {
                iVar8 = Height - iVar6;
            } else if (iVar6 < 0) {
                param_1 = param_1 - iVar6 * iVar9;
                iVar6 = 0;
            } else {
                iVar8 = 7;
            }
        }

        iVar7 = iVar6 * iVar9 + iVar7;
        int row_count = iVar8;
        if (row_count != 0) {
            do {
            if (0 < param_2) {
                iVar9 = iVar7;
                param_3 = param_2;
                len = param_1 - iVar7;
                do {
                    cVar3 = *(char*)(len + iVar9);
                    if (0 < iVar9 && iVar9 < SizeArrays + -1) {
                        cVar4 = ProbArray[iVar9];
                        pcVar2 = ProbArray + iVar9;
                        if (cVar4 == 0) {
                            *pcVar2 = cVar3;
                            ProbabilityTiles = ProbabilityTiles + 1;
                        } else if ((int)cVar3 + (int)cVar4 < 0xFF) {
                            *pcVar2 = cVar3 + cVar4;
                        } else {
                            *pcVar2 = -1;
                        }
                    }
                    iVar9 = iVar9 + 1;
                    param_3 = param_3 + -1;
                } while (param_3 != 0);
            }
            param_1 = param_1 + iVar1;
            iVar7 = iVar7 + Width;
                row_count--;
            } while (row_count != 0);
        }
}
