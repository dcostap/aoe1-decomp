# Recovery journal: 004E6CA0 `resourcesAvailable`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tairesmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tairesmd.cpp`.
- Earlier recovery note: `recovery_notes/tairesmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3788212928a70b2eda9f -->
### `d050eea3c` `src/tairesmd.cpp:72-75`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004E6CA0 TribeResourceAIModule::resourcesAvailable
// PDB: tairesmd.cpp lines 82-110. Status: scratch.
// BINARY NOTE: Canonical Main Decision and Player composition emits a 56-byte
// mismatch. The direct targets and boundary match, but no current drift claim
```
<!-- end-recovered:3788212928a70b2eda9f -->

<!-- recovered:0f6f45d836e7ea8ccc35 -->
### `a9a8fe10cd56` `src/scratch/004E6CA0_resourcesAvailable.cpp:1-18`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E6CA0 TribeResourceAIModule::resourcesAvailable
// Source: tairesmd.cpp lines 82-110
// Size: 147 bytes, no EH
//
// Attempt log:
// Probe 1: standalone class + for-loop with count local -> 144 bytes, wrong offset, ebp for this
// Probe 2: direct-pointer chain + for-loop -> extra number() at loop entry (85% diff)
// Probe 3: infinite loop with bottom break + inline chain -> completely different (122% diff)
// Probe 4: do-while + limits temp -> 60% diff, ebp for this, test ah,1 vs test ah,41h
// Probe 5: for(;;) with top i>=number() break -> wrong structure
// Retry 2026-05-19/20 assigned pass:
// - Restored full local model after comment-only scratch and validated natural do/while implementation: 147/147, MISMATCH, 33.3333% positional / 28.5714% edit, first mismatch +9.
// - Source now gets the original `test ah,41h` FPU compare but still chooses EBP=this and EBX=available; original wants EBX=this and EBP=available.
// - Tried explicit `n` local and bottom `n=item->number()` spelling: no codegen change.
// - Tried `self=this` local to encourage EBX for module: no codegen change.
// - Tried reversed FPU predicate `(float)needed > available[i]`: no codegen change.
// - /G5 and /Ob0 flag probes: no change; flags removed.
// GIVEUP: behavior/calls/offsets/FPU predicate are understood, but remaining mismatch is broad register allocation and loop layout (including duplicated rebuilt loop body vs original single loop body). No accepted_drift: not localized.
```
<!-- end-recovered:0f6f45d836e7ea8ccc35 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
