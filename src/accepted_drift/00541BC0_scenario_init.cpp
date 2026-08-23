// 00541BC0 RGE_Game_World::scenario_init
// EH-framed allocate and construct RGE_Scenario (0x1990 bytes), store at +0x5C.
// FLAGS: config/flags/00541BC0_scenario_init.rsp uses /GX for original SEH/new-expression basin.
//
// === ACCEPTED_DRIFT ===
// Same VC5 /GX new-expression + EH lowering artifact as accepted_drift siblings
// 00541C90/0052E5F0/0052E530. First 70 bytes are exact (through prologue,
// operator new, null test, SEH try-level set, ctor call, jmp, xor eax). At the
// common-store join, VC5 inserts a dead `test eax,eax; jne +0` (4 bytes) that
// isn't in the original binary. This zero-displacement branch is behavior-neutral
// and only shifts the EH epilogue into padding.
//
// Best result: 17.5824% positional / 12.0879% edit diff, first mismatch offset 70.
// Same family as 0052E5F0/00541C20/00541C90/0052E530.
//
// Attempt log:
// 1. Prior /GX direct new with sizeof(RGE_Scenario)=0x1990 gives exact EH prologue/allocation/ctor family, but store sinks into non-null path; 23.08% pos / 16.48% edit.
// 2. Volatile read of local: first 75B exact/common join retained, but spills EAX through [esp+18h] and stores EDX.
// 3. Explicit if/else assignment: forced source join but adds unwanted post-join `test eax,eax; jne`.
// 4. variant_lab over direct/local/ternary/ifelse/volatile/slot shapes, member volatility, and vc5-risky flags: no exact. Best edit family was /GX /Oa + volatile read (edit 14) but still stack-spills EAX.
// 5. Slot local/pointer-to-member shape and ternary collapse back to the sunk-store basin.
// 6. 2026-05-10 pass on this VA only: retried 20+ variants: direct/local new, if-null/if-not/goto common-store, assignment-in-condition, zero-init, volatile local, parameter reuse, bool temp, switch, empty-if, ternary, do/for single-pass, if/else member stores, and volatile-read. Also probed flags /O1, /Og, /Ob0, /Ox, /Gf, /Gy, /Oa, /Ot with /GX. No exact.
// 7. 2026-05-12: Confirmed identical artifact to 00541C90 (accepted_drift). First 70 bytes exact, then test/jne +0 at join. Same causal root: VC5 new-expression + EH lowering dead-code elimination failure. Recommended for accepted_drift per Boss's 00541C90 ruling.
// 8. Full canonical World.cpp context emits the same reviewed drift bytes.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::scenario_init(RGE_Game_World* param_1) {
    RGE_Scenario* s = new RGE_Scenario(param_1);
    if (s == 0) {
        s = 0;
    }
    this->scenario = s;
}
