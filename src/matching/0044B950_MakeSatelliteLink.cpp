// PointMaker::MakeSatelliteLink
// VA: 0044B950 - from Ghidra decomp

// Attempt log:
// - Replaced explicit absolute-value sign tests with the natural signed
//   remainder predicate `r % 2`, restoring the original branchless parity
//   lowering and 336-byte size.
// - The vertical source intentionally rereads y, and preserves the original
//   lower-bound bug `dy = -dx`.
// - Upper-bound predicates use the binary-supported sum >= limit-3 spelling.
//   Candidate temporary/compound scheduling, declaration order, and canonical
//   PrimaryPt/PtToPt point-array layout probes were duplicates or regressed;
//   retained the clean typed source rather than allocator-only scaffolding.
// - Inline parity calls, several candidate_x declaration/update orders, and a
//   focused four-variant schedule lab all emitted the same 336-byte result.
//   The remaining first hunk is the target's mov/add candidate-x schedule
//   versus VC5's equivalent LEA; restored the clean direct bound expressions.
// - Fresh orch-fractal-fresh-03 probes confirmed direct x reloads, no cached
//   x, delayed dy accumulation, full PointMaker field declarations, and a
//   named direct-x candidate either regressed or duplicated the clean 149-byte
//   result. A 27-variant natural schedule lab likewise found no exact basin.
// - Moving the old_x snapshot after coordinate updates with direct x guards
//   changed the first candidate to mov/add and improved shape to 75.73% block
//   coverage, but left a 152-byte mismatch at the second horizontal guard;
//   reversing the commutative operands was a codegen duplicate. Restored the
//   cleaner old_x-before-update source; remaining drift is localized VC5
//   candidate/second-bound scheduling, not a proven ownership or ABI issue.
// - Fresh sa-7af9de30-r1-0044B950 pass: complete same-TU method declarations,
//   candidate_x copy/compound and expanded forms, old_x declaration placement,
//   and direct-x reread hybrids were duplicates or regressed (best retained
//   source remains 149 differing bytes).  A 7-variant candidate-sum lab also
//   collapsed to the same 149-byte emitted group; no exact natural basin found.
// - Fresh tu-fractal-44B950 pass: donor <stdlib.h>/<string.h> headers worsened
//   the residual to 153 bytes.  A candidate_x computed before dy += DirY was
//   a codegen duplicate; computing it without old_x regressed to 319 bytes.
//   Restored the clean typed source; the first candidate mov/add schedule
//   remains the only localized mismatch lead.
// - Removed the codegen-steering old_x snapshot.  Direct named x reads in the
//   second horizontal guard and final assignment are cleaner, but VC5 dropped
//   the saved EBP role and regressed the byte diff from 149 to 319.  The
//   x + dx spelling was a codegen duplicate; retained the cleaner source.
// - Fresh sa-32ff943f-r1 pass: restored the binary-supported old_x snapshot
//   and rechecked candidate_x split/direct forms, second-guard x rereads,
//   register/const qualifiers, top-scoped candidates, and point-store aliases.
//   They were duplicates or regressed; final validation remains 149 differing
//   bytes.  The remaining mismatch is the target mov/add candidate-x schedule
//   versus VC5's natural LEA lowering, with all calls, size, CFG, frame, and
//   saved-register sets aligned.
// - Fresh sa-ad558ed4-r1 pass: protected method access restores the original
//   IA EH symbol. Direct-x forms, old_y-only liveness, full 0x1058 class tail,
//   snapshot placement, and candidate copy/add forms were duplicates or
//   regressed. Retain the typed x/y reconstruction and 149-byte result.
// - Fresh delegated revisit: first-guard `nx = dx + old_x`, compound `nx`, and
//   condition-local candidate forms all emitted the same 336-byte/149-diff
//   basin. Restored the pinned clean source; no natural exact basin was found.
// - Fresh blocker-focused pass: direct final `x = x + dx`, x-before-y
//   publication, top-scoped old_x, donor stdlib/string context, and a nine-
//   variant final-update/publication lab were tested. The best natural source
//   has 336 bytes, 90.74% shape, 84.47% exact-block coverage, and 25 edit
//   bytes. It still differs at the first candidate-x hunk; no exact basin was
//   found. The final publication tail now has the target x reread, x-before-y
//   stores, and NumNodes reload between point stores. Register hints, const
//   snapshots, accumulator spellings, named indices, split stores, and
//   final_x aliases were duplicates or regressed. Keep this function in scratch.
// - Probe record: H1/H2/H3 direct-x forms reached 175 bytes; H4/H5 early or
//   mid-block result locals reached 157/178 bytes; H6/H7 header variants reached
//   153/175 bytes; H8/H9/H10 candidate, compound-x, and dy-accumulator forms
//   reached 175 bytes. H11/H12/H13/H14 top old_x, candidate, and register forms
//   reached 184 bytes with 29 edit bytes. H15/H16 const and final_x forms
//   reached 175 bytes. H17/H18/H19 top old_x plus context reached 184 bytes
//   with 25 edit bytes. H20 reversed y operands was a codegen duplicate.
// - Before the final repair, exact-finish probes restored the smallest
//   no-header source with a local old_x and direct x/y publication.
//   Block-scoped and register-qualified candidate locals, old_y,
//   declaration-order, operand-order, and post-update snapshot probes were
//   duplicates. Direct-x upper-bound and candidate forms regressed to the
//   319-byte basin.
// - Exact transition: direct x reads in both horizontal guards, with no old_x
//   snapshot, restored the target's mov/add candidate schedule. Walkback kept
//   exactness when the snapshot was used only by the first guard, but the
//   second-guard snapshot regressed. The direct form is the smaller source.
// - Exact-finish context walkback: <stdlib.h> is required in this translation
//   unit. <string.h> is not required. Removing both headers regressed the
//   prologue and body to 330 bytes.
// BINARY NOTE: The final tail rereads x, publishes x before y, and reloads
// NumNodes between point stores. The source keeps this order.
// Context pass: PDB source module is fractal.cpp, lines 355-373, with 11
// records. The address sequence is 0044B950-0044BA9F and follows MakeNewLink
// before DrawPrimaryIntoProbabilityArray. Exact anchors are the four direct
// debug_rand calls at 0044B960/0044B97C/0044B99E/0044B9BA, the 0044B9D2
// direction load, and the 0044BA88 tail store. The owning class is PointMaker.

extern int __cdecl debug_rand(char* param_1, int param_2);

#include <stdlib.h>

#ifndef FRACTAL_ARRAYS_CONTEXT_H
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

// Main-agent audit confirmed canonical point/link ownership and preserved the
// binary-observed dy=-dx bug.
class PointMaker {
public:
    PrimaryPt Prime;
    PtToPt Point[500];
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

protected:
    int MakeSatelliteLink();
};
#endif

int PointMaker::MakeSatelliteLink() {
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    dx = dx % SatelliteDistance + 1;
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    if (r % 2) dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    dy = dy % SatelliteDistance + 1;
    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    if (r % 2) dy = -dy;

    dx += DirX;
    dy += DirY;

    if (dx + x < 3) {
        dx = -dx;
        DirX = -DirX;
    }

    if (dx + x >= Width - 3) {
        dx = -dx;
        DirX = -DirX;
    }

    if (dy + y < 3) {
        dy = -dx;  // original bug: uses -dx not -dy
        DirY = -DirY;
    }

    if (dy + y >= Height - 3) {
        dy = -dy;
        DirY = -DirY;
    }

    x = x + dx;
    y = dy + y;
    Point[NumNodes].x = x;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}
