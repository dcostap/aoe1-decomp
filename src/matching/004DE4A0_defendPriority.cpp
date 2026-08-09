// 004DE4A0 defendPriority
// TribeInformationAIModule::defendPriority(int param_1, int param_2)
// Source: taiinfmd.cpp lines 4579-4607
// Size: 204 bytes
//
// Status: PARKED - VC5 dispatch structure / encoding drift
//
// Attempt log:
// Probe 1: switch(case) + tactical local — CSE hoisted md load to top,
//   shared call tail. 65.7% positional diff.
// Probe 2: inline cast expression in each case — same CSE.
// Probe 3: static helper fn — actually made external call (worse).
// Probe 4: proper member access md->tacticalAI.strategicNumber() — same CSE.
// Probe 5: if/else if chain — SELF-CONTAINED HANDLERS! Each handler has:
//   mov ecx, [ecx+100h]; push val; add ecx, 0x1146C; call; ret 8
//   (matching original handler pattern exactly)
//   Remaining: if/else dispatch vs switch/jump-table, add vs sub encoding,
//   test/jne vs direct je for equality checks.
//
// Key findings:
// - `switch` causes CSE (shared tail), `if/else` keeps handlers independent
// - md at +0x100, tacticalAI at +0x1146C in TribeMainDecisionAIModule
// - strategicNumber is non-virtual, direct call
// - param_1 cases: 0x2D→0x46, 0x6D→0x38, 0x9E/0xA3→0x36, 0x9F→0x37
// - param_2: 7→0x34, 8→0x33, 0x20→0x32, else -1
//
// Remaining drift (VC5 TU-context):
// - if/else dispatch (cmp/jne chain) vs switch jump table (sub+byte+table)
// - add eax,-7 / test/jne vs sub eax,7 / je encoding
// - case handler order differs from original
//
// Session sa-ff64edc9-r1 (10 meaningful probes):
// - natural switch emitted the required table but VC5 merged all tactical calls
//   into one tail (204 bytes, 1/7 calls; 172 positional diff).
// - volatile pointee/pointer qualifiers and explicit goto handler labels were
//   unchanged; /pragma optimize("g", off) was 428 bytes and /pragma optimize
//   ("t", off) was 99 bytes, so both were rejected.
// - a 256-case expression variant lab found no exact variant; pointer spelling
//   changed only table/tail details and never restored independent calls.
// - the typed nested md->tacticalAI surface was also codegen-identical to the
//   raw-offset switch; an explicit volatile md-field lvalue was unchanged.
// Best paused source below keeps the binary-proven primary switch and named
// nested ownership, rather than retaining codegen-only volatility/labels.
// No custom flags, no inline asm.
//
// Session orch-luna-4de4a0-w2 (10 meaningful probes, fresh pass):
// - distinct inherited receiver types, per-arm result locals, complete ABI-proven
//   class hierarchy, explicit switch default ownership, distinct owner-view types,
//   qualified virtual/direct calls, and binary-observed case order all emitted the
//   same one-call basin (or only neutral table bytes).
// - two 128/2187-case variant families mixed direct/raw, volatile-receiver, and
//   result-local spellings; all size-preserving groups still merged the seven
//   handlers to one direct strategicNumber call.
// - a compile-time pointer-to-member call also stayed in the same 204-byte basin.
// Final evidence: structural blocker is unchanged: rebuilt/original direct calls
//   1/7, positional diff 172/204 (84.3137%), first mismatch +0x0B. Retain the
//   natural primary switch and named md/tacticalAI ownership for the next pass.
// Main-agent exact follow-up:
// - Restoring the second sparse dispatch as a natural `switch (param_2)` rather
//   than its equivalent hand-written subtract chain changed VC5's whole-function
//   tail-merging decision and recovered all seven independent call handlers.
// - Ordering the first switch's source cases by the binary handler layout
//   (0x6D, 0x2D, 0x9F, 0x9E/0xA3) fixed the remaining four literal bytes.
// Exact: 204/204 bytes, seven ordered calls, and full byte equality.

struct AIModule {
    virtual void dummy();
};

struct InformationAIModule : public AIModule {
    char pad_EC[0xEC]; // 0xF0 - 4 (vptr)
};

class TribeTacticalAIModule {
public:
    int strategicNumber(int val);
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1146C];
    TribeTacticalAIModule tacticalAI;
};

struct TribeInformationAIModule : public InformationAIModule {
    char farmsPad[0x10]; // ManagedArray<int> farmsTaskedThisUpdate at +0xF0
    TribeMainDecisionAIModule* md; // +0x100

    int defendPriority(int param_1, int param_2);
};

int TribeInformationAIModule::defendPriority(int param_1, int param_2)
{
    switch (param_1) {
    case 0x6D:
        return md->tacticalAI.strategicNumber(0x38);
    case 0x2D:
        return md->tacticalAI.strategicNumber(0x46);
    case 0x9F:
        return md->tacticalAI.strategicNumber(0x37);
    case 0x9E:
    case 0xA3:
        return md->tacticalAI.strategicNumber(0x36);
    }

    switch (param_2) {
    case 7:
        return md->tacticalAI.strategicNumber(0x34);
    case 8:
        return md->tacticalAI.strategicNumber(0x33);
    case 0x20:
        return md->tacticalAI.strategicNumber(0x32);
    default:
        return -1;
    }
}
