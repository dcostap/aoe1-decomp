// PointMaker::DrawMask
// VA: 0044AFE0 - Draws mask patterns onto probability array

class PointMaker {
public:
    char gap_000[0xFA8];
    char* Mask_2x2;
    char* Mask_3x3;
    char* Mask_4x4;
    char* Mask_5x5;
    char gap_FB8[0x1C];
    int Width;
    int Height;
    char gap_FDC[0x28];
    int SizeArrays;
    char gap_1008[0x1C];
    char* ProbArray;
    char gap_1028[0x1C];
    int ProbabilityAdd;
    char gap_1000[0x10];
    int ProbabilityTiles;

    void DrawMask(int param_1, int param_2, int param_3);
};

void PointMaker::DrawMask(int param_1, int param_2, int param_3) {
    int iVar9 = Width;
    int iVar5 = Height;
    
    if (param_1 > iVar9) return;
    if (param_2 > iVar5) return;
    if (param_3 + 2 + param_1 < 0) return;
    if (param_3 + 2 + param_2 < 0) return;
    
    int iVar1 = param_3 + 2;
    int iVar6 = param_2;
    int iVar7 = param_1;
    
    if (param_3 == 2) {
        if (param_1 + 4 <= iVar9 && param_1 < 0) param_1 = 0;
        iVar7 = param_1;
        if (param_2 + 4 <= iVar5 && param_2 < 0) iVar6 = 0;
    } else if (param_3 == 3) {
        if (param_1 + 5 <= iVar9 && param_1 < 0) param_1 = 0;
        iVar6 = param_2 + (iVar5 < 5 ? 1 : 0);
        iVar7 = param_1;
    }
    
    char* mask_ptr;
    int mask_width;
    int mask_height;
    
    if (param_3 == 4) {
        mask_ptr = Mask_4x4;
        mask_width = iVar7 + 6;
        if (iVar9 < mask_width) {
            mask_width = iVar9 - iVar7;
        } else if (iVar7 < 0) {
            mask_ptr = mask_ptr - iVar7;
            iVar7 = 0;
        } else {
            mask_width = 6;
        }
        mask_height = iVar6 + 6;
        if (iVar5 < mask_height) {
            mask_height = iVar5 - iVar6;
        } else if (iVar6 < 0) {
            mask_ptr = mask_ptr - iVar6 * iVar9;
            iVar6 = 0;
        } else {
            mask_height = 6;
        }
    } else {
        mask_ptr = Mask_5x5;
        mask_width = iVar7 + 7;
        if (iVar9 < mask_width) {
            mask_width = iVar9 - iVar7;
        } else if (iVar7 < 0) {
            mask_ptr = mask_ptr - iVar7;
            iVar7 = 0;
        } else {
            mask_width = 7;
        }
        mask_height = iVar6 + 7;
        if (iVar5 < mask_height) {
            mask_height = iVar5 - iVar6;
        } else if (iVar6 < 0) {
            mask_ptr = mask_ptr - iVar6 * iVar9;
            iVar6 = 0;
        } else {
            mask_height = 7;
        }
    }
    
    int iVar7_row = iVar6 * Width + iVar7;
    int local_iVar1 = iVar1;
    char* local_mask = mask_ptr;
    
    while (mask_height != 0) {
        if (mask_width > 0) {
            int pos = iVar7_row;
            int remaining = mask_width;
            do {
                char mask_val = *(char*)((int)local_mask + (pos - iVar7_row));
                if (pos > 0 && pos < SizeArrays - 1) {
                    char prob_val = ProbArray[pos];
                    if (prob_val == 0) {
                        ProbArray[pos] = mask_val;
                        ProbabilityTiles++;
                    } else if ((int)mask_val + (int)prob_val < 0xFF) {
                        ProbArray[pos] = mask_val + prob_val;
                    } else {
                        ProbArray[pos] = (char)-1;
                    }
                }
                pos++;
                remaining--;
            } while (remaining != 0);
        }
        local_mask = local_mask + local_iVar1;
        iVar7_row = iVar7_row + Width;
        mask_height--;
    }
}
