// PointMaker::DrawMask
// VA: 0044AFE0 - Draws mask patterns onto probability array
//
// Attempt log:
// - Corrected the PointMaker ownership surface: Width/Height (+0xFD4/+0xFD8),
//   ProbabilityTiles (+0xFEC), SizeArrays (+0x1004), and ProbArray (+0x1024).
// - Direct parameter/member guards recover exact size and improve the early
//   guard CFG; the natural typed mask_ptr/mask_width/mask_height reconstruction
//   is retained after parameter-home and allocator variants were rejected.
// - Remaining gap is the VC5 frame/register basin and loop parameter-home
//   reuse (original 0x10 frame, rebuilt 0xC); no opaque pointer/int alias is
//   retained as living source.

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
    char gap_FDC[0x10];
    int ProbabilityTiles;
    int TargetProbabilityCount;
    int ProbabilityAdd;
    int BranchRadius;
    int SatelliteRadius;
    int PrimaryRadius;
    int SizeArrays;
    char gap_1008[0x1C];
    char* ProbArray;

    void DrawMask(int param_1, int param_2, int param_3);
};

void PointMaker::DrawMask(int param_1, int param_2, int param_3) {
    if (param_1 > Width) return;
    if (param_2 > Height) return;
    if (param_3 + 2 + param_1 < 0) return;
    if (param_3 + 2 + param_2 < 0) return;
    
    int mask_step = param_3 + 2;
    int mask_row = param_2;
    int mask_col = param_1;
    
    if (param_3 == 2) {
        if (param_1 + 4 <= Width && param_1 < 0) param_1 = 0;
        mask_col = param_1;
        if (param_2 + 4 <= Height && param_2 < 0) mask_row = 0;
    } else if (param_3 == 3) {
        if (param_1 + 5 <= Width && param_1 < 0) param_1 = 0;
        mask_row = param_2 + (Height < 5 ? 1 : 0);
        mask_col = param_1;
    }
    
    char* mask_ptr;
    int mask_width;
    int mask_height;
    
    if (param_3 == 4) {
        mask_ptr = Mask_4x4;
        mask_width = mask_col + 6;
        if (Width < mask_width) {
            mask_width = Width - mask_col;
        } else if (mask_col < 0) {
            mask_ptr = mask_ptr - mask_col;
            mask_col = 0;
        } else {
            mask_width = 6;
        }
        mask_height = mask_row + 6;
        if (Height < mask_height) {
            mask_height = Height - mask_row;
        } else if (mask_row < 0) {
            mask_ptr = mask_ptr - mask_row * Width;
            mask_row = 0;
        } else {
            mask_height = 6;
        }
    } else {
        mask_ptr = Mask_5x5;
        mask_width = mask_col + 7;
        if (Width < mask_width) {
            mask_width = Width - mask_col;
        } else if (mask_col < 0) {
            mask_ptr = mask_ptr - mask_col;
            mask_col = 0;
        } else {
            mask_width = 7;
        }
        mask_height = mask_row + 7;
        if (Height < mask_height) {
            mask_height = Height - mask_row;
        } else if (mask_row < 0) {
            mask_ptr = mask_ptr - mask_row * Width;
            mask_row = 0;
        } else {
            mask_height = 7;
        }
    }
    
    int write_index = mask_row * Width + mask_col;
    int row_step = mask_step;
    char* mask_cursor = mask_ptr;
    
    while (mask_height != 0) {
        if (mask_width > 0) {
            int pos = write_index;
            int remaining = mask_width;
            do {
                char mask_val = *(char*)((int)mask_cursor + (pos - write_index));
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
        mask_cursor = mask_cursor + row_step;
        write_index = write_index + Width;
        mask_height--;
    }
}
