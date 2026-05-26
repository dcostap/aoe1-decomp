// PointMaker::DrawPrimaryIntoProbabilityArray
// VA: 0044BAA0
// Retry 2026-05-26: shape locals to original stack/register loop.
// Revalidated best: 182B exact size, MISMATCH 6 positional / 6 edit, first mismatch +104.
// Tried 10 variants: baseline + dummy stack local, explicit original stack-temp topology, desty-first,
// reordered call/updates, while/continue, member-reread PrimaryRadius, casted call args, oldleft/oldbottom
// locals, volatile destx, and manual a/b/c/d call locals. Best source matches all setup/clipping/loop/tail
// and differs only in the inner AddingRect call setup register coloring: rebuilt uses ECX for left and EDX
// for bottom while original uses EDX for left and ECX for bottom; pushed argument values/order are equivalent.
// PROPOSED_ACCEPTED_DRIFT: localized benign register-choice drift in one call-setup hunk only.

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
    int i; int local_c; int local_8; int local_4;
    int px=Prime_x; int py=Prime_y; int rad=PrimaryRadius;
    int left=px-rad; int top=py-rad; int bottom=py+rad; int right=px+rad;
    if(left<0) left=0; if(top<0) top=0;
    int w=Width-1; if(right>w) right=w; int h=Height-1; if(bottom>h){ i=h; bottom=h; }
    ProbabilityAdd=1; local_c=0; if(rad>0){ do { int destx=left; local_4=top; left++; local_8=right; top++; int desty=bottom; right--; bottom--; i=bottom; AddingRect(destx, local_4, local_8, desty); ProbabilityAdd++; local_c++; } while(local_c<PrimaryRadius); }
}
