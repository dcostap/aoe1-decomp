// PointMaker::CreateShape (0044B470)
//
// The PointMaker layout below follows the proven fractal.cpp class layout.  The
// called methods are declarations only: they are separately owned functions in
// the original translation unit, so defining local forwarding wrappers would
// create the wrong call relocations and extra COMDATs.
//
// Attempt log:
// - Removed local forwarding wrappers and kept separately-owned method declarations;
//   this fixed call relocation identity and reduced the initial 113-byte mismatch.
// - A post-incremented attempt guard (`iVar2++ < 1500`) reproduced the rotated
//   VC5 loop topology, bringing the function to 196 bytes and a 15-byte mismatch.
// - Canonical PrimaryPt/PtToPt and the full proven PointMaker surface, local-value
//   and register-qualified parameter probes, and a focused setup variant lab did
//   not change the emitted best code.
// - Final validated state remains scratch: all calls, loop blocks, frame, size,
//   and 189/196 bytes match. Remaining drift is localized to +0x1A..+0x2B:
//   rebuilt loads param_2 into EAX and sets ECX=this before the first stores,
//   while the original loads param_2 into ECX and param_1 into EAX first.
//
// orch-w18 pass (2026-08-07):
// - Reconfirmed the residual hunk: orig +0x1A..+0x2B is
//     mov ecx,[esp+18h]; mov eax,[esp+14h]; mov [esi+0FBCh],ecx; mov [esi+4],ecx;
//     mov ecx,esi; ... (param_2 in ECX, param_1 in EAX, both loaded at the top,
//     this-setup after the ECX stores)
//   while rebuilt emits
//     mov eax,[esp+18h]; mov ecx,esi; mov [esi+0FBCh],eax; mov [esi+4],eax;
//     mov eax,[esp+14h]; ... (param_2 in EAX, this-setup hoisted, param_1 deferred).
//   Every other block (prologue, loop, epilogue) is byte-exact.
// - Variant-lab #12: permuted the 6 store statements (y/Py/P/N/x/Px in 10 orders),
//   chained/comma/local/register spellings. VC5 fully reorders the independent
//   stores (direct_yfirst == direct_zerosfirst emit identical code), and ALL
//   variants stay in the same 15-byte EAX basin or regress. Source order is not
//   a free axis here.
// - Variant-lab #13: flag sweep (vc5-small + vc5-risky presets: /GX, /Oi, /Og,
//   /Ot, /Ob0, /Ow, /Oa, /Og-, /O1, /Ox) - every flag either stays in the same
//   15-byte basin or breaks the prologue (/O1, /Og-).
// - Variant-lab #15: debug-context preset (/Zd, /Zi, /Z7) - no change.
// - Micro-repro (build/temp/micro_create2.cpp) faithfully reproduces the rebuilt
//   basin; explored ~20 more source shapes there: param stores via locals
//   declared top/mid/late (with/without register), interleaved pair stores
//   (y,x,Py,Px), chained pair assignments (Prime_y = y = param_2), single-store
//   variants, member-load sources, volatile param reads, int-returning DrawPrimary,
//   and loop locals declared at function top. The ONLY shapes that put a
//   stack-param value into ECX (interleaved/single-store) also reverse the
//   store order (x before y), which mismatches the binary store order; every
//   shape that keeps the binary store order (y,Py,zeros,x,Px) gives param_2 in
//   EAX. The loop body (member loads) and sibling 00433D40/00478F40 show the
//   same compiler assigning the FIRST-STORE value to ECX, so the rebuilt's EAX
//   choice is a block-scheduling artifact, not a stable rule.
// - Include/TU context probes (0047E530-style): game_globals.h, game_types.h,
//   CRT headers (<stdlib.h>, <string.h>, <memory.h>) on the real scratch and the
//   micro repro - no change. /G4/G5/G6 CPU flags - no change.
// - Conclusion: the residual 15 bytes are a locked VC5 load-scheduling/
//   register-allocation basin for this block shape. Best next lead: reproduce
//   the original's PDB line map, which attributes BOTH param loads to line 248
//   (the y store line) while the x store is on line 250 - suggesting the source
//   declared a line-248 local (e.g. `int xv = param_1;`) whose value feeds the
//   line-250 x stores; VC5 still sinks that load to EAX in every tested spelling,
//   so the hoist difference likely needs TU-level allocator state (closest
//   analog: /GX EH-framed ctor 00478F40 loads stack params into ECX, but this
//   function has no EH frame).

// sa-b1e7d941 fresh same-TU pass (2026-08-09): reused the ground-truth
// PointMaker/PrimaryPt/PtToPt layout and exact fractal.cpp donor context.  The
// prior probes already cover direct/chained stores, declaration/liveness,
// helper-context, flags, and loop-shape axes; no new natural source axis was
// supported by the binary.  Retained the clean 15-byte mismatch and recorded
// final validation rather than replacing typed source with allocator scaffolding.

// orch-luna-44b470-w2 fresh pass (2026-08-09):
// - Claimed the paused target, reran the dossier/donor/ABI evidence, and
//   revalidated the canonical clean source before experiments.
// - An inline same-TU SetPoint helper (x/y body) moved both parameter loads
//   into the original ECX/EAX roles and improved the diagnostic diff to 5
//   bytes, but placed the x store before the zero stores; it is not retained
//   as living source because the helper is not a proven original call shape.
// - Moving/reordering that helper, reversing its member order, direct x-first
//   assignments, and a bundled helper-store diagnostic all regressed. Restored
//   the pinned natural source; final validation remains 15 bytes.

// orch-fractal-01 pass (2026-08-10):
// - Adding the original same-TU CreateShape() overload and SetPoint declaration
//   did not move the 15-byte setup hunk.
// - Prime.y/Prime.x-from-member, const-qualified parameters, an optimized local
//   PrimaryPt coordinate aggregate, and explicit this-qualified stores all
//   emitted the same 196-byte/15-byte basin.
// - Focused variant lab #39 covered pointer/reference aliases, self aliases,
//   chained stores, aggregate/array coordinates, and scoped setup; 18/18
//   invariant-eligible variants remained in the 15-byte basin.
// - Full preceding same-TU CreateShape() context lab #40 selected the 334-byte
//   no-arg overload during extraction and supplied no usable target lead.
// - Restored the pinned natural source. Remaining drift is still only the
//   parameter-load/ECX scheduling hunk at +0x1A..+0x2B; no canonical source axis
//   found in this pass changes it.

// orch-fractal-fresh-04 final lane (2026-08-10):
// - Independently reran the dossier, same-TU donor ranking, ABI query, and
//   clean baseline. Prior exact5 inline-SetPoint evidence was inspected rather
//   than repeated as a winning source; it preloads ECX/EAX but stores x before
//   the binary's zero stores.
// - Fresh y-only/helper, early-x-cache, reversed parameter-local, x-only
//   helper, y-helper-returning-x, and repeated-SetPoint diagnostics all stayed
//   in the clean 15-byte basin. A six-variant helper lab likewise found no
//   exact source shape; all size/frame/call gates remained valid.
// - Restored the canonical natural source. Cumulative evidence leaves a real
//   compiler allocator/scheduling blocker at +0x1A..+0x2B: param_2 must occupy
//   ECX and param_1 EAX before the y/Prime.y stores, while the natural source
//   hoists this into ECX and defers param_1. No behavior/layout/call mismatch
//   remains.

// wave20-fractal-01 pass (2026-08-10):
// - Inline reset/coordinate helpers, a first-pair this alias, an inline
//   reference-output assignment, and a two-helper point/reset sequence all
//   preserved the 196-byte/15-byte natural basin or worsened it; none is kept.
// - Focused parameter-pointer/reference and identity/arithmetic variant labs
//   (32 invariant-eligible variants total) found no ECX-scheduling lead. The
//   only closer family remains the prior inline SetPoint diagnostic, whose x
//   store is before the binary zero stores; the clean typed source is restored.

// ACCEPTED_DRIFT REVIEW (main-drift-0044B470): Direct comparison with the
// original shows identical size, frame, saved-register set, eight ordered call
// targets, branch/return structure, field stores, loop bounds, and return
// value. The only non-zero drift is the localized +0x1A..+0x2B setup hunk:
// VC5 assigns the two incoming coordinate values to EAX/ECX in the opposite
// allocation and hoists the `this` setup differently before the same stores.
// No predicate, call, stack cleanup, memory target, or stored value changes.
// The closer inline-helper experiment remains diagnostic only; this natural
// typed PointMaker source is the promoted candidate.

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

// Main-agent audit confirmed canonical point-array ownership and retained the
// natural shape construction flow.
class PointMaker {
public:
    PrimaryPt Prime;                     // +0x0000
    PtToPt Point[500];                   // +0x0008
    char* Mask_2x2;                      // +0x0FA8
    char* Mask_3x3;                      // +0x0FAC
    char* Mask_4x4;                      // +0x0FB0
    char* Mask_5x5;                      // +0x0FB4
    int x;                               // +0x0FB8
    int y;                               // +0x0FBC
    int NumSplitsPerBranch;              // +0x0FC0
    int NumberOfSatellites;              // +0x0FC4
    int ChanceOfNextNode;                // +0x0FC8
    int MaxNumberOfBranches;             // +0x0FCC
    int MaxBranchFlag;                   // +0x0FD0
    int Width;                            // +0x0FD4
    int Height;                           // +0x0FD8
    int MinimumNumTiles;                 // +0x0FDC
    int NumNodes;                        // +0x0FE0
    int NumTilesActuallyChosen;          // +0x0FE4
    int CurrentPoint;                    // +0x0FE8
    int ProbabilityTiles;                // +0x0FEC
    int TargetProbabilityCount;          // +0x0FF0
    int ProbabilityAdd;                  // +0x0FF4
    int BranchRadius;                    // +0x0FF8
    int SatelliteRadius;                 // +0x0FFC
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

    void ClearArrays();
    void PrepareLimits();
    void ErrorCheckingAndCorrection();
    void CreateMapBasedOnProbabilityArray();
    void MapCleanUpEliminatingSinglesOnly();
    void DrawPrimaryIntoProbabilityArray();
    int MakeFirstLink();
    void Branch(int param_1);
    int CreateShape(int param_1, int param_2);
};

int PointMaker::CreateShape(int param_1, int param_2) {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();
    y = param_2;
    Prime.y = param_2;
    ProbabilityTiles = 0;
    NumNodes = 0;
    x = param_1;
    Prime.x = param_1;
    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();

    int minimum_tiles = MinimumNumTiles;
    int chosen_tiles = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int attempts = 0;
    while (chosen_tiles < minimum_tiles && attempts++ < 1500) {
        chosen_tiles = Prime.y;
        x = Prime.x;
        y = chosen_tiles;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        chosen_tiles = MakeFirstLink();
        Branch(chosen_tiles);
        chosen_tiles = ProbabilityTiles;
    }
    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}
