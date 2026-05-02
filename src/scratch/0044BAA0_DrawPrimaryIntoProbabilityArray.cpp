// PointMaker::DrawPrimaryIntoProbabilityArray
// VA: 0044BAA0

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
    void DrawPrimaryIntoProbabilityArray();
};

void PointMaker::DrawPrimaryIntoProbabilityArray() {
    int left = Prime_x - PrimaryRadius;
    int top = Prime_y - PrimaryRadius;
    int bottom = Prime_y + PrimaryRadius;
    int right = Prime_x + PrimaryRadius;
    
    if (left < 0) left = 0;
    if (top < 0) top = 0;
    
    int w1 = Width - 1;
    if (right > w1) right = w1;
    int h1 = Height - 1;
    if (bottom > h1) bottom = h1;
    
    ProbabilityAdd = 1;
    int rad = PrimaryRadius;
    int counter = 0;
    
    if (rad > 0) {
        do {
            AddingRect(left, top, right, bottom);
            ProbabilityAdd++;
            counter++;
            bottom--;
            top++;
            right--;
            left++;
        } while (counter < rad);
    }
}
