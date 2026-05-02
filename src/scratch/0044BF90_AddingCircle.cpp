// PointMaker::AddingCircle
// VA: 0044BF90 - Full implementation from Ghidra decomp

int __cdecl debug_rand(char* param_1, int param_2);

class TRIGONOMETRY {
public:
    float sin360(int angle);
    float cos360(int angle);
};

extern TRIGONOMETRY trig;

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
    char _pad_end[3];

    void AddingCircle(int param_1, int param_2, int param_3);
};

void PointMaker::AddingCircle(int param_1, int param_2, int param_3) {
    if (param_3 == 0) param_3 = 1;
    
    float lasty = 0.0f;
    float W = 0.0f;
    int angle = 0;
    int step = 360 / (param_3 * 3);
    
    do {
        float sin_val = trig.sin360(angle);
        float fVar9 = sin_val * (float)param_3;
        float cos_val = trig.cos360(angle);
        float fVar10 = cos_val * (float)param_3;
        
        if (fVar9 != lasty || fVar10 != W) {
            int loc = (int)fVar9;
            if (loc > 0 && loc < SizeArrays - 1) {
                char* p = ProbArray + loc;
                char cur = *p;
                char add = (char)ProbabilityAdd;
                if (cur == 0) {
                    *p = add;
                    ProbabilityTiles++;
                } else if (ProbabilityAdd + (int)cur < 0xFF) {
                    *p = add + cur;
                } else {
                    *p = (char)-1;
                }
            }
            
            W = fVar10;
            int r = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x1F1);
            lasty = fVar9;
            
            if (r & 1) {
                trig.sin360(angle);
                debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 499);
                trig.cos360(angle);
                debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 500);
                
                loc = (int)sin_val;
                int addp1 = ProbabilityAdd + 1;
                if (loc > 0 && loc < SizeArrays - 1) {
                    char* p = ProbArray + loc;
                    char cur = *p;
                    char add = (char)addp1;
                    if (cur == 0) {
                        *p = add;
                        ProbabilityTiles++;
                    } else if (addp1 + (int)cur < 0xFF) {
                        *p = add + cur;
                    } else {
                        *p = (char)-1;
                    }
                }
            }
        }
        angle += step;
    } while (angle < 360);
}
