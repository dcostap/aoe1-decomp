# Recovery journal: 005414A0 `data_load_effects`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/world.cpp`.
- PDB source: `C:\msdev\work\age1_x1\World.cpp`.
- Earlier recovery note: `recovery_notes/world_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:418c9a7557d05147fd96 -->
### `e5b22f4df482` `src/scratch/005414A0_data_load_effects.cpp:1-30`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 005414A0 RGE_Game_World::data_load_effects
// FLAGS: /GX required for original SEH/new/ctor cleanup basin
//
// BLOCKER: natural /GX new-expression emits the original EH prologue, allocation
// size, null test, EH state store, filename push, constructor call, and null xor.
// Remaining mismatch is tail scheduling: VC5 either sinks the member store into
// the non-null path and places the null cleanup tail after the ret, or (with a
// volatile local read) keeps the original common branch/join but spills/reloads
// EAX through [esp+18h] before storing to [esi+4Ch]. Original has the ideal common
// tail: restore FS source into ECX, direct `mov [esi+4Ch], eax`, FS restore, epilogue.
//
// Attempt log:
// 1. Prior placement-new/volatile source failed extraction (only 64B .text) and/or sunk store.
// 2. Natural direct member new: first 50B exact, then store sinks into non-null path; null path after ret (23.86% pos, 17.05% edit).
// 3. Explicit operator new + placement constructor: no EH new-expression, .text only 64B.
// 4. Natural new into local before member assignment: same sunk-store basin.
// 5. Explicit if/else assignment: forced source join but added unwanted `test eax,eax; jne` after ctor/null join.
// 6. Volatile read of local for final assignment: first 72B exact, common tail retained, but spills EAX to [esp+18h], reloads EDX, and stores EDX.
// 7. Redundant ternary assignment: optimized back to sunk-store basin.
// 8. Explicit goto label before assignment: optimized back to sunk-store basin.
// 9. Register local plus volatile read: same stack spill/reload as volatile read.
// 10. Store through pointer-to-member slot local: optimized back to sunk-store basin.
// 11. Volatile local assigned from natural new: optimized back to sunk-store basin.
// 12. variant_lab over member volatility, direct/local/ternary/ifelse/volatile/goto shapes, and vc5-risky flags: no exact; best default families are sunk-store or volatile-spill; /Oa slightly changes spill ordering but still not exact.
// 13. LemonLily pass: tried direct member assignment, plain local, assignment-expression, empty if(e), goto/common-label, if/else self-assign, slot pointer/ref, volatile member declaration, raw +0x4C store, comma expression, volatile filename/this, int/long volatile reads, and address-escape forms. They collapse to either sunk-store/null-tail or common-tail-with-stack-spill; none produced original direct `mov [esi+4Ch],eax` common tail.
// 14. Additional temporary flag probes on the int-volatile-read family (/Oa, /Ow, /Og, /Oi, /Ox /Oa, no /Oy, /Ob0, /Gs) did not match; /Oa-/Ow reduce edit diff slightly but still keep extra stack traffic. Original /GX flag file kept unchanged.
// 15. This pass retried direct member assignment (sunk-store/null-tail, 23.86%),
//     plain local assignment (same), and explicit null self-assignment (adds
//     unwanted test/jne at join, 18.18%). Reverted to plain local assignment. Still
//     no accepted_drift suggestion: tail control-flow/stack-spill variants are broad.
```
<!-- end-recovered:418c9a7557d05147fd96 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
