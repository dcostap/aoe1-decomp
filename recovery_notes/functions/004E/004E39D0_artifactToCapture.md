# Recovery journal: 004E39D0 `artifactToCapture`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taiinfmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taiinfmd.cpp`.
- Earlier recovery note: `recovery_notes/taiinfmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3ff5e8cfb414a5714ee7 -->
### `target-session` `build/target_sessions/004E39D0_artifactToCapture.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MATCH; diff=0; shape=100.0: Baseline for PDB-qualified TribeInformationAIModule::artifactToCapture in taiinfmd.cpp lines 7925-7976; source claims natural VC5 exact scan with named distance local.
probe 2 liveness; result=MISMATCH; diff=82; shape=99.21259842519684: Exact-finish walkback: remove named converted town-center distance local while preserving distance call, x87 conversion, and multiplication.
```
<!-- end-recovered:3ff5e8cfb414a5714ee7 -->

<!-- recovered:e313e2b4e2d42584d389 -->
### `3ad784e0af52` `src/scratch/004E39D0_artifactToCapture.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E39D0 TribeInformationAIModule::artifactToCapture
// Source: taiinfmd.cpp lines 7925-7976
// attempt 1: natural source from packet/decompiler with local layout; wrong register coloring (EBP=this) and frame 0x1C.
// attempt 2: model md->field_F0 owner/check object separately from visible_map at +0x38; frame size fixed to 0x18 but rebuilt still 400B vs original 428B.
// attempt 3: introduced self local to encourage ESI=this; VC5 chose EBP=this and ESI=offset, still short.
// attempt 4: register offset before self; added stack spill and worsened prologue.
// attempt 5: removed self and kept register offset; this colored as EBP and offset as ESI, still not original.
// attempt 6: array indexing importantObjectMemory[i+1] instead of byte offset; worsened to EBX=this and extra saved regs.
// attempt 7: register self plus explicit offset; no change, still EBP=this/ESI=offset.
// attempt 8: volatile vMap local to preserve unused zero local; no codegen/size change.
// attempt 9: volatile parameter to force redundant player reload/compare; no codegen/size change.
// attempt 10: diagnostic /Od compile produced 428B but broad mismatch from offset 0; reverted flags.
// Left in scratch: behavior modeled, but optimized VC5 register coloring/loop topology remains wrong (original ESI=this, EBP=byte offset; rebuilt tends EBP=this or EBX=this and emits a 400B function). Not accepted_drift.
```
<!-- end-recovered:e313e2b4e2d42584d389 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
