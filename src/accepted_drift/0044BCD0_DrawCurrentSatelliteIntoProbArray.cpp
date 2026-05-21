// PointMaker::DrawCurrentSatelliteIntoProbArray
// VA: 0044BCD0 - v3: goto-based branch structure matching original asm
// Attempt log:
// inherited baseline: exact first 90 bytes; remaining tail differs because VC5 uses ECX as ProbArray pointer and EAX/AL for byte math, while original keeps pointer in EAX and uses CL plus ESI/EDI for signed old+ProbabilityAdd saturation.
// try 1: p = iVar4 + ProbArray with explicit c local; kept size but used ECX pointer/AL byte and shorter saturation tail, 36 diff bytes.
// try 2: char ProbabilityAdd local; worsened earlier register/branch layout.
// try 3: no probAdd local; worsened to broad 70-byte diff.
// try 4: separate old/total locals; same ECX/EAX tail family.
// try 5: goto/return tails for nonzero/saturate; worsened branch layout.
// try 6: mutating iVar4 by adding ProbArray then casting to char*; still ECX pointer family.
// try 7: volatile p forced stack/local traffic and worsened to 74 diff bytes.
// try 8: register char* p, split assignment p after declaration, int pointer temp, register int pointer temp; no improvement.
// try 9: compound assignment *p += ProbabilityAdd; compile/codegen family not useful.
// try 10: char old local and signed char old variants; still shorter AL/ECX saturation family.
// try 11: predeclared old/total locals and volatile total; no improvement.
// ACCEPTED_DRIFT 2026-05-21 (Boss approved): behavior-equivalent localized register/allocation-tail drift after byte 0x5A. Rebuilt keeps the target byte pointer in ECX and accumulates in AL/EAX; original keeps pointer in EAX, old byte in CL, and uses ESI/EDI for signed saturation. Branch targets move by 2-5 bytes and rebuilt fills the now-unreachable end with NOPs, but calls, bounds checks, memory effects, and saturation semantics match.

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

    void AddingCircle(int param_1, int param_2, int param_3);
    void DrawCurrentSatelliteIntoProbArray(int param_1);
};

void PointMaker::DrawCurrentSatelliteIntoProbArray(int param_1) {
    int iVar4 = SatelliteRadius;
    ProbabilityAdd = 2;
    while (iVar4 >= 0) {
        AddingCircle(Point[param_1 * 2], Point[param_1 * 2 + 1], iVar4);
        ProbabilityAdd++;
        iVar4--;
    }
    
    iVar4 = Point[param_1 * 2 + 1] * Width + Point[param_1 * 2];
    int probAdd = ProbabilityAdd;
    if (iVar4 >= 1 && iVar4 < SizeArrays - 1) {
        char* p = ProbArray + iVar4;
        if (*p == 0) {
            *p = (char)probAdd;
            ProbabilityTiles++;
        } else {
            int total = probAdd + (int)*p;
            if (total < 0xFF) {
                *p = (char)total;
            } else {
                *p = (char)-1;
            }
        }
    }
}
