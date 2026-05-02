// PointMaker::AddingRect
// VA: 0044BD80 - Proper asm-based implementation

int __cdecl debug_rand(char* param_1, int param_2);

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

void PointMaker::AddingRect(int x, int y, int w, int h) {
    int width = Width;
    int idx = y * width + x;
    int delta_y = w - x;
    int delta_x = h - y;
    int row_count = delta_x - 1;
    int idx2 = row_count * width + idx;
    
    if (delta_y < 0 || delta_x < 0) return;
    
    // First loop: iterate delta_y+1 times
    int cur_idx = idx;
    int count = delta_y + 1;
    while (count != 0) {
        int probAdd = ProbabilityAdd;
        
        if (cur_idx >= 1 && cur_idx < SizeArrays - 1) {
            char* p = ProbArray + cur_idx;
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
        
        if (idx2 >= 1 && idx2 < SizeArrays - 1) {
            char* p = ProbArray + idx2;
            if (*p == 0) {
                *p = (char)probAdd;
                ProbabilityTiles++;
            } else if (probAdd + (int)*p < 0xFF) {
                *p = (char)(probAdd + (int)*p);
            } else {
                *p = (char)-1;
            }
        }
        
        cur_idx++;
        idx2++;
        count--;
    }
    
    // Second loop: iterate row_count times, shift by Width each iteration
    int base_idx = idx;
    count = row_count;
    while (count != 0) {
        base_idx += width;
        int probAdd = ProbabilityAdd;
        
        if (base_idx >= 1 && base_idx < SizeArrays - 1) {
            char* p = ProbArray + base_idx;
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
        int idx4 = base_idx + delta_y;
        
        if (idx4 >= 1 && idx4 < SizeArrays - 1) {
            char* p = ProbArray + idx4;
            if (*p == 0) {
                *p = (char)probAdd;
                ProbabilityTiles++;
            } else if (probAdd + (int)*p < 0xFF) {
                *p = (char)(probAdd + (int)*p);
            } else {
                *p = (char)-1;
            }
        }
        
        count--;
        if (count == 0) break;
    }
}
