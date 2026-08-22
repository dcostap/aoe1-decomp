// PointMaker::DrawCurrentBranchIntoProbArray
// VA: 0044BB60 - natural typed reconstruction

// Attempt log:
// - Replaced the rotated-loop dummy self-reload/raw cursor scaffold with a
//   natural typed PointMaker/Point-array reconstruction and a direct
//   AddingRect member call.
// - A guarded `for` loop with direct BranchRadius bounds (rather than keeping
//   radius live as a local loop bound) recovered the original 357-byte size,
//   0x8 frame, one call, and 0x8 stack-local topology.  The natural do/while
//   form peeled an extra AddingRect call and was discarded.
// - Remaining drift is broad register/source scheduling from the initial
//   point/radius locals and saturation tail; parameter capture and raw/typed
//   array/register probes did not move it.  Retained readable typed source,
//   not fake volatility, raw offsets, or register-only scaffolding.
// - Register-qualified parameter, entry index/Point-element pointer captures,
//   and direct ProbabilityAdd tail casts were either duplicates or regressed;
//   restored the clean typed baseline.  Current blocker remains the broad
//   pre-save index/register basin (target loads [esp+0C] before callee saves).
// - Follow-up worker probes: direct input initializers moved the first paired
//   hunk four bytes deeper (diff 327) but emitted radius/y/x rather than the
//   oracle's x/radius/y load order; the declaration-order variants did not
//   retain that improvement.  An int Point[1000] donor representation and a
//   full same-TU PointMaker declaration surface were codegen duplicates.
// - A saved-radius/count loop reproduced the prior 373-byte, 0xC-frame basin.
//   A six-case variant lab confirmed initialized-radius/y/x as the closest
//   size/frame candidate, but no exact or source-quality winner emerged.
//   Restored the clean typed source; unresolved drift starts at the pre-save
//   parameter-index load and includes the broad register/liveness basin.
// - Separate named point-x/point-y locals moved the first mismatch from +3 to
//   +4 and improved the positional diff from 331 to 325 bytes.  This retained
//   the natural PointMaker/Point ownership and produced the pre-save index
//   load, but VC5 still chose different x/y register roles than the oracle.
// - Explicit bound copies, initialized derived bounds, const coordinates,
//   donor header context, coordinate declaration-order, and delayed y
//   assignment were duplicate or regressed.  Restored the best separate-
//   coordinate source; the remaining blocker is the first setup block's
//   register coloring and liveness.
// - Fresh tu-fractal-44BB60 pass: donor <stdlib.h>/<string.h> headers were a
//   codegen duplicate.  The exact PointMaker/Point layout and typed coordinate
//   source remain stable; the target still differs at the pre-save x/radius/y
//   register coloring and later tail schedule.
// - Grouping the point_x, BranchRadius, and point_y initial declarations was a
//   clean typed probe, but worsened the diff from 325 to 331 bytes and moved
//   the first mismatch to +3.  Restored the separate declarations.
// - The original parameter is recorded as `which` in CodeView; renaming the
//   source parameter was codegen-neutral.  Spelling the probability lower
//   bound as `>= 1` recovered the target cmp-1 form and improved the diff from
//   325 to 299 bytes without changing size, frame, calls, or CFG.
// - A nine-case early-input/tail variant lab found no exact result.  Named
//   coordinate reuse, point-element pointers, and post-index add locals were
//   regressive or changed the frame.  The natural typed source is restored;
//   remaining drift starts at the pre-save parameter/index register basin.
// - Revisited the setup basin with natural statement order.  Assigning the
//   radius before loading point_y, then assigning min_x before max_x, matches
//   the target setup, clipping, and draw-loop register ownership through the
//   shared loop exit.  This reduces drift from 299 to 111 bytes and raises
//   exact-block coverage from 69.92% to 85.37%, but leaves a two-byte size
//   excess and the probability-index/tail block nonexact.  Retain this typed
//   source as the strongest natural reconstruction; no opaque allocator aids.
// - Fresh tail probes moved the typed add initialization before the probability
//   guard.  A full-width prob_add local reached 61 differing bytes, exact size,
//   and 89.43% exact-block coverage, but its load/register order remained
//   nonexact.  Direct indexed stores were codegen-neutral.  Restored this
//   pinned natural source; no metric-only tail variant is retained.
// - Follow-up worker probes: a natural satellite-style common tail reached
//   diff 62 with exact size but lost tail blocks.  A repeated direct member
//   read, function-scope prob_add, and explicit validated-index pointer were
//   codegen duplicates.  Staged point-x/ProbabilityAdd/index declarations
//   regressed to diff 118.  Restored the donor-style full-width prob_add and
//   byte add locals before the bounds with the original early returns; this
//   reaches diff 61, exact size, 97.58% shape, and 89.43% exact blocks.
// ACCEPTED DRIFT AUDIT:
// - The only live instruction-shape difference starts after the draw loop.
// - Both versions read which, Width, Point[which].y, Point[which].x,
//   ProbabilityAdd, SizeArrays, ProbArray, and the probability byte in the
//   same order.
// - VC5 moves the private wrapping index addition across the ProbabilityAdd
//   load. The addition cannot fault and has no external effect.
// - Both versions use the same index bounds, byte saturation predicate,
//   probability write, ProbabilityTiles update, and return paths.
// - Register allocation and branch distances account for the remaining
//   bytes. No call, writable address, publication, or fault order differs.

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

// Main-agent audit confirmed canonical probability/branch ownership and retained
// the natural typed draw loop.
class PointMaker {
public:
    PrimaryPt Prime;                     // +0x00
    PtToPt Point[500];                   // +0x08
    char* Mask_2x2;                      // +0xFA8
    char* Mask_3x3;                      // +0xFAC
    char* Mask_4x4;                      // +0xFB0
    char* Mask_5x5;                      // +0xFB4
    int x;                               // +0xFB8
    int y;                               // +0xFBC
    int NumSplitsPerBranch;              // +0xFC0
    int NumberOfSatellites;              // +0xFC4
    int ChanceOfNextNode;                // +0xFC8
    int MaxNumberOfBranches;             // +0xFCC
    int MaxBranchFlag;                   // +0xFD0
    int Width;                           // +0xFD4
    int Height;                          // +0xFD8
    int MinimumNumTiles;                 // +0xFDC
    int NumNodes;                        // +0xFE0
    int NumTilesActuallyChosen;          // +0xFE4
    int CurrentPoint;                    // +0xFE8
    int ProbabilityTiles;                // +0xFEC
    int TargetProbabilityCount;          // +0xFF0
    int ProbabilityAdd;                  // +0xFF4
    int BranchRadius;                    // +0xFF8
    int SatelliteRadius;                 // +0xFFC
    int PrimaryRadius;                   // +0x1000
    int SizeArrays;                      // +0x1004
    int SatelliteDistance;               // +0x1008
    int BranchDistance;                  // +0x100C
    int DirX;                            // +0x1010
    int DirY;                            // +0x1014
    int MaxNumberOfBranchLevels;         // +0x1018
    int CurrentNumberOfBranchLevels;     // +0x101C
    char* ExternalArray;                 // +0x1020
    char* ProbArray;                     // +0x1024
    char* PlacementArray;                // +0x1028
    char* WritableExternalArray;         // +0x102C
    int DoNotDrawOnFlag;                 // +0x1030
    int DrawOnOnlyFlag;                  // +0x1034
    int DrawOnlyInExternalArrayFlag;     // +0x1038
    int DrawToOneArrayFlag;              // +0x103C
    int BorderDepthPercentage;           // +0x1040
    int LeftLimit;                       // +0x1044
    int RightLimit;                      // +0x1048
    int TopLimit;                        // +0x104C
    int BottomLimit;                     // +0x1050
    char SpecialLandType;                // +0x1054
    char pad_end[3];                     // +0x1055

    void AddingRect(int param1, int param2, int param3, int param4);
    void DrawCurrentBranchIntoProbArray(int which);
};

void PointMaker::DrawCurrentBranchIntoProbArray(int which) {
    int point_x = Point[which].x;
    int radius;
    int point_y;
    int max_x;
    int min_x;
    int min_y;
    int max_y;
    int ring;

    radius = BranchRadius;
    point_y = Point[which].y;
    min_x = point_x - radius;
    max_x = radius + point_x;
    min_y = point_y - radius;
    max_y = point_y + radius;

    if (max_x >= 0 && max_y >= 0 && min_x < Width && min_y < Height) {
        if (min_x < 0) min_x = 0;
        if (min_y < 0) min_y = 0;
        if (max_x >= Width) max_x = Width - 1;
        if (max_y >= Height) max_y = Height - 1;

        ProbabilityAdd = 1;
        ring = 0;
        if (BranchRadius > 0) {
            for (; ring < BranchRadius; ++ring) {
                AddingRect(min_x, min_y, max_x, max_y);
                ++min_x;
                if (min_x >= Width || ++min_y >= Height || --max_x < 0 || --max_y < 0) {
                    break;
                }
                ++ProbabilityAdd;
            }
        }

        int prob_idx = Width * Point[which].y + Point[which].x;
        int prob_add = ProbabilityAdd;
        char add = (char)prob_add;
        if (prob_idx >= 1 && prob_idx < SizeArrays - 1) {
            char* p = ProbArray + prob_idx;
            char old = *p;
            if (old == 0) {
                *p = add;
                ProbabilityTiles++;
                return;
            }
            if (prob_add + (int)old < 0xFF) {
                *p = add + old;
                return;
            }
            *p = (char)-1;
        }
    }
}
