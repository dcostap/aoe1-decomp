# Recovery journal: 00428A70 `SetSelfPlayer`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_hand.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Com_hand.cpp`.
- Earlier recovery note: `recovery_notes/com_hand_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:536817ba158e57aa1bb8 -->
### `target-session` `build/target_sessions/00428A70_SetSelfPlayer.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Module closure probe: corrected original-FPO member access/return/parameter declaration; final grouped object emits the expected symbol. Body remains a grouped mismatch and is not changed beyond declaration repair.
```
<!-- end-recovered:536817ba158e57aa1bb8 -->

<!-- recovered:dbedbd3904b17b87dbb6 -->
### `a78d9e7434ee` `src/scratch/00428A70_SetSelfPlayer.cpp:1-40`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TCommunications_Handler::SetSelfPlayer (__thiscall)
// VA: 00428A70
// Com_hand.cpp:2303-2323
// 156 bytes
//
// Attempt log:
// 1: Clean while loop with extern globals — 29% positional diff, 21% edit diff.
//    Issues: selfDcoID hoisted before prologue; signed vs unsigned comparison (jle vs jbe)
// 2: goto-based with unsigned short — worse prologue
// 3: Direct address derefs via macro — worse code
// 4: *(type*)0xADDR access — 72% diff
// 5: for-loop structure — 88% edit diff
// 6: Unsigned comparisons — similar to attempt 1
// 7: volatile globals — 115% diff
// 8: inline helper functions — similar
// 9: volatile globals + casts — 115% diff
//
// Best result (attempt 1): 29.5% positional diff, 21.2% edit diff.
// 135 bytes equal, 46 bytes diff (12 relocations masked).
//
// Remaining diffs from best:
// 1. selfDcoID (extern int) hoisted before prologue — VC5 moves global loads
//    to function entry under /O2. Original loads at first-use point.
// 2. jle (signed, 7E) vs jbe (unsigned, 76) — different signedness convention
// 3. Branch offset values differ due to prologue layout differences
//
// Root cause: Single-function TU prevents exact register/scheduling match.
// extern int selfDcoID always hoisted before prologue; original delays
// loading until after the first bounds check.
//
// Left in scratch. Not proposing accepted_drift.
// Retry 2026-05-19 Boss pass: 10 additional variants (p declared after count check, unsigned/goto/for loop shapes, selfDcoID local vs reload vs volatile, value temp, L local, separate assignment style). None improved prior best; most worsened to 55-67% positional / 61-119% edit by perturbing prologue/loop. Restored prior exact-size scratch.
// Retry 2026-05-20 Boss pass:
// - Made loop index unsigned int: kept, fixes the loop-back branch to jbe and improves best to 45 positional bytes / 28.8462%, 32 edit bytes / 20.5128%.
// - volatile selfDcoID: delayed load but changed saved-register assignment and block order badly (46.1538% positional / 115.3846% edit); rolled back.
// - /Og-, /Oa-, /Ob0, /O1 flag probes: no improvement or wrong-size/worse output; no custom flag kept.
// - Guarded if/do-while and duplicated fail-log shapes delayed the initial selfDcoID load past the prologue, but VC5 unrolled/pipelined the loop and produced broad topology drift; rolled back.
// - Explicit local `me = selfDcoID` inside guard caused EBP save and broad loop drift; rolled back.
// - `extern const int selfDcoID` and removing <stdlib.h>: no meaningful scheduling change; const rolled back, include removal kept as neutral.
// GIVEUP: current best remains exact size but first mismatch at offset 0 from selfDcoID hoisted before prologue; remaining drift is non-local scheduling/topology, not accepted_drift.
```
<!-- end-recovered:dbedbd3904b17b87dbb6 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
