// PointMaker::AddingCircle
// VA: 0044BF90 - Full implementation from Ghidra decomp
//
// Attempt log:
// - Baseline decompiler-shaped source emitted 438 bytes with a 0x14 frame and
//   had the circle arithmetic/call order only loosely aligned.
// - Reconstructed the binary-supported source shape: a cached float Width,
//   direct sin/cos radius products, signed rand % 2, abs(rand) offsets, and
//   the two observed probability-array updates. This reached the original
//   540-byte effective size, 9/9 ordered calls, and 76.85% resync similarity.
// - Bound checks use the observed `>= 1` spelling; declaring the byte add
//   before the array pointer recovered the original load order in both arms.
// - The remaining mismatch is a stable VC5 local topology basin: the rebuilt
//   frame is 0x18 versus the original 0x1C, the loop increment remains in EBX
//   rather than the original stack home, and the first index keeps curx with
//   `fld st0` instead of the oracle's width-load/fmul-st1 form.
// - Declaration-order, split-initializer, local-topology variant-lab, and
//   const loop-step probes were nonproductive or codegen duplicates. Kept the
//   natural typed reconstruction rather than retaining register-steering
//   scaffolding.
// - Tested an unscaled cosine with radius multiplication at each observed use.
//   It widened the positional diff and repeated one source-level calculation.
//   Restored the natural scaled cosine value retained across compare/index/W use.
// - Tested loading a full-width ProbabilityAdd local after the first __ftol
//   and before the bounds check, then keeping it through the first cell update.
//   It moved the load as intended but changed pointer/byte register topology,
//   shrank the code to 525 bytes, and worsened the positional diff to 447.
//   Restored the clean scaled-cosine source.

#include <stdlib.h>

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

    int angle_step = 360 / (param_3 * 3);
    float width = (float)Width;
    float step;
    float curx;
    float x;
    float W = 0.0f;
    float lasty = 0.0f;
    int angle = 0;

    do {
        float lastx = trig.sin360(angle) * (float)param_3;
        curx = trig.cos360(angle) * (float)param_3;

        if (lastx != lasty || curx != W) {
            int loc = (int)(curx * width + lastx);
            if (loc >= 1 && loc < SizeArrays - 1) {
                char add = (char)ProbabilityAdd;
                char* p = ProbArray + loc;
                char cur = *p;
                if (cur == 0) {
                    *p = add;
                    ProbabilityTiles++;
                } else if (ProbabilityAdd + (int)cur < 0xFF) {
                    *p = add + cur;
                } else {
                    *p = (char)-1;
                }
            }

            W = curx;
            int random = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x1F1);
            lasty = lastx;
            if (random % 2) {
                x = trig.sin360(angle) * (float)param_3;
                step = abs(debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 499)) + x - 1.0f;
                float y = trig.cos360(angle) * (float)param_3;
                int random_2 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 500) % 2;
                loc = (int)(width * ((float)random_2 + y - 1.0f) + step);
                int addp1 = ProbabilityAdd + 1;
                if (loc >= 1 && loc < SizeArrays - 1) {
                    char add = (char)addp1;
                    char* p = ProbArray + loc;
                    char cur = *p;
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
        angle += angle_step;
    } while (angle < 360);
}
