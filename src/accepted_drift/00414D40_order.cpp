// VA: 00414D40 UnitAIModule::order(int,int,int,int,float,float,float,float,int,int,int)
// aiuaimod.cpp
// Attempt log:
// - Baseline: typed direct-call reconstruction; exact size/call set, but VC5 saves
//   EDI at entry while the original delays it until the nonzero-p9 path.
// - Tried p2 directly, a block-local orderType, early-return versus explicit-else
//   layout, positive state guard, <3 versus <=2, corrected virtual return types,
//   and stdio context. These emitted the same best nonexact code (except <3,
//   which changed the compare immediate); no source-shape lead remains in this
//   isolated TU.
// - Follow-up session probes: a branch-local p2 copy, an address-taken p2 alias,
//   register/const p2 qualifiers, and /GX all emitted the same code. A natural
//   switch(p9) worsened size/call alignment and was rolled back. The remaining
//   structural gap is the original's delayed push edi after the p9 test versus
//   VC5's entry push edi; no ABI/layout or ordered-call discrepancy was found.
// - Fresh normal-414D40-r1 pass: baseline reconfirmed the 306-byte, 8-call
//   canonical source. Separate branch-local copies, a top-level guard-bound
//   copy, a single-iteration loop, a common done label, and positive-guard
//   if/else layout were all codegen duplicates. The delayed EDI save remains
//   the only actionable gap; the clean direct-parameter source is restored.
// - Added the full proven UnitAIModule virtual surface and typed 0x24-byte
//   OrderEvent; corrected the same-TU owner return surface. No bytes changed.
// - Expanded the local class to the proven UnitAIModule field layout. All
//   eight ordered calls and the 277-byte mismatch stayed unchanged.
// - Fresh shardE baseline reconfirmed the same 306-byte source and 8-call
//   surface. A volatile state byte, an inline identity helper around p2, and
//   a branch-local p10 copy all emitted the same code. A size-optimization
//   pragma changed the basin to 297 bytes and was rolled back.
// - Restored the canonical source. The remaining evidence-backed blocker is
//   VC5's entry push edi versus the oracle's branch-local push edi; ABI,
//   layout, ordered calls, and all later blocks remain aligned.
// - Best canonical source retained: positive state guard, direct p2 use, typed
//   object/member ownership, real virtual calls, and standard FILE/fprintf ABI.
// - Managed pass probes: split p2 into branch-local orderType copies, move the
//   nonzero-path copy after the p10 call, and add windows.h context. All were
//   codegen duplicates. Restored the canonical source; delayed EDI remains
//   unresolved and requires a compiler/TU-context lead, not a semantic change.
// - Revisit probes added stdlib.h, then string.h with stdio.h, and split the
//   late orderType declaration from its assignment. All stayed at 306 bytes,
//   eight ordered calls, and the same 277-byte mismatch. The natural typed
//   dispatch remains the clean source.
// - Final revisit validation: the restored source still has the exact 306-byte
//   boundary and eight ordered calls. The only structural gap is VC5's entry
//   push edi versus the original branch-local push edi; no policy-valid source
//   lead was found.
// ACCEPTED DRIFT: the original saves EDI only on the nonzero-p9 path. The
// rebuild saves it at entry. This shifts parameter displacements but each of
// the three addToOrderQueue calls receives the same typed arguments. The only
// other instruction difference replaces a dead p10 register load with a direct
// stack compare. All eight calls, predicates, queue effects, logging, virtual
// dispatches, return values, register restoration, and fault order match.
// Size and CFG match. Each path balances its own saved registers and arguments.
// This function has no SEH.
// A fresh early-invalid-state return probe reproduced the same allocation.
// Canonical-context pass: this owner now uses the shared aiuaimod.cpp surface.
// Its 306-byte boundary, eight calls, symbol, and 277-byte drift stay unchanged.
// Adding this owner changes updateGroup scheduling but not its recorded metrics.

#include <stdio.h>

#include "../../include/aiuaimod_context.h"

extern FILE* actionFile;
extern const char str_fmt_stopObject[];
extern const char str_aiuaimod_path[];

int UnitAIModule::order(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10, int p11)
{
    if (this->objectValue->object_state <= 2) {
        if (p9 == 0) {
            this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, p10, p11);
            return 1;
        }

        if (p10 == 1) {
            this->addToOrderQueue(this->objectValue->id,
                                  this->currentOrderValue,
                                  this->currentTargetValue,
                                  -1,
                                  this->currentTargetXValue,
                                  this->currentTargetYValue,
                                  this->currentTargetZValue,
                                  this->desiredTargetDistanceValue,
                                  1,
                                  this->currentOrderPriorityValue);
        }

        this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, 1, p11);

        if (p2 != 0x2D9) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0)
                    id = this->objectValue->id;
                else
                    id = -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x6F3);
            }
            this->stopObject(1);
        }

        this->purgeNotifyQueue(0);
        this->processOrder(this->orderQueueValue, 0);
    }
    return 1;
}
