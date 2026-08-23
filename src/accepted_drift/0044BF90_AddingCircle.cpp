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
// - Tested a named float radius local for the circle loop and all four trig
//   products. VC5 emitted the same 540-byte code and retained the 0x18 frame;
//   restored the clean direct parameter conversion.
// - Revisit: the donor-supported <string.h> context restores the 0x1C frame,
//   165 instructions, and the loop-step stack home. It also exposes several
//   exact block islands.
// - Hoisting a full-width probability-add local before the first bounds check
//   restores the original EDX/EBP saturation tail. The best result is 245
//   differing bytes with all nine ordered calls and the original size/frame.
// - Typed pointer spellings and local declaration variants do not change the
//   remaining pointer-register difference. Keep canonical ProbArray ownership.
// - Behavior correction: the line-499 random value uses signed `% 2` in the
//   binary. The prior `abs(random)` reconstruction could select distant cells.
// - Accepted-drift review after that correction: size, frame, CFG, nine calls,
//   both x87 index expressions, signed remainders, bounds, array fault
//   addresses, byte saturation, ProbabilityTiles updates, angle progress, and
//   return match. The first index keeps the same extended curx value through
//   multiplication and __ftol. Residual drift swaps private float homes and
//   the register that owns each probability-cell address.
// - Exact-finish pass: declare the two zeroed FPU history values separately,
//   publish lasty before the random call, and use a reference for each byte
//   cell. This reduces the clean nonvolatile source to 5 bytes.
// BINARY NOTE: CodeView lists int step and float curx, W, lasty, lastx,
// and x. It lists no width or offset local. VC5 overlaps their homes with
// compiler temporaries after optimization.
// - Walkback: removing volatile returns the clean 5-byte drift at +008E.
//   Const, direct-member, address-taken, and staged-width forms did not fix it.
// - PDB finish audit rejects volatile width: the type record for W is
//   nonvolatile, and no source width local exists. Keep the natural source.
// - Direct Width expressions are PDB-plausible but lose the 0x1C frame and
//   widen the diff to 478 bytes. The cached nonvolatile form is the cleanest
//   supported source, with only the x87 operand order unresolved.
// - Final natural-source pass restored PDB function scope for curx, the int
//   step name and type, and the line-489 for-loop. These changes preserve the
//   clean five-byte result. Reusing x for the line-499 offset causes 13 bytes
//   of drift, so keep a separate optimized offset expression home.
// - Scalar, const, register, array, reference, declaration-order, implicit-
//   conversion, and compound-update forms all keep the five-byte x87 hunk.
//   Direct Width reloads remove the invariant home and change 478 bytes.
// - Authentic 41-owner fractal.cpp builds preserve this natural 540-byte
//   result and the same +008E hunk. Reversing the first commutative product
//   is a codegen duplicate. Volatile width fixes the hunk in that context.
// BLOCKER: The only exact source found requires volatile width. CodeView has
// no volatile float local, so policy rejects that otherwise exact form.

#include <stdlib.h>
#include <string.h>

int __cdecl debug_rand(char* param_1, int param_2);

class TRIGONOMETRY {
public:
    float sin360(int angle);
    float cos360(int angle);
};

extern TRIGONOMETRY trig;

#ifndef FRACTAL_ARRAYS_CONTEXT_H
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

protected:
    void AddingCircle(int param_1, int param_2, int param_3);
};
#endif

void PointMaker::AddingCircle(int param_1, int param_2, int param_3) {
    if (param_3 == 0) param_3 = 1;

    int step = 360 / (param_3 * 3);
    float width = (float)Width;
    float offset;
    float x;
    float curx;
    float W;
    float lasty;
    lasty = 0.0f;
    W = 0.0f;
    float lastx;
    for (int angle = 0; angle < 360; angle += step) {
        lastx = trig.sin360(angle) * (float)param_3;
        curx = trig.cos360(angle) * (float)param_3;

        if (lastx != lasty || curx != W) {
            int loc = (int)(width * curx + lastx);
            int prob_add = ProbabilityAdd;
            char add = (char)prob_add;
            if (loc >= 1 && loc < SizeArrays - 1) {
                char& cur = ProbArray[loc];
                if (cur == 0) {
                    ProbArray[loc] = add;
                    ProbabilityTiles++;
                } else if (prob_add + (int)cur < 0xFF) {
                    ProbArray[loc] = add + cur;
                } else {
                    ProbArray[loc] = (char)-1;
                }
            }

            lasty = lastx;
            W = curx;
            int random = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x1F1);
            if (random % 2) {
                x = trig.sin360(angle) * (float)param_3;
                offset = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 499) % 2 + x - 1.0f;
                float y = trig.cos360(angle) * (float)param_3;
                int random_2 = debug_rand((char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 500) % 2;
                loc = (int)(width * ((float)random_2 + y - 1.0f) + offset);
                int addp1 = ProbabilityAdd + 1;
                if (loc >= 1 && loc < SizeArrays - 1) {
                char add = (char)addp1;
                char& cur = ProbArray[loc];
                if (cur == 0) {
                    ProbArray[loc] = add;
                    ProbabilityTiles++;
                } else if (addp1 + (int)cur < 0xFF) {
                    ProbArray[loc] = add + cur;
                    } else {
                        ProbArray[loc] = (char)-1;
                    }
                }
            }
        }
    }
}
