# Recovery journal: 004E4B80 `TribeMainDecisionAIModule`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/taimdmd.cpp`.
- PDB source: `C:\msdev\work\age1_x1\taimdmd.cpp`.
- Earlier recovery note: `recovery_notes/taimdmd_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:e2b0d1df58a52ea4d54d -->
### `d050eea3c` `src/taimdmd.cpp:29-30`

Mapping: `strong`. next mapped function definition is TribeMainDecisionAIModule at old line 106.

```text
// PDB lines 89-151; VA 004E4800.
// BINARY NOTE: The shipped constructor stores the derived vptr at +0x155,
```
<!-- end-recovered:e2b0d1df58a52ea4d54d -->

<!-- recovered:245ef70fd794aafe2cbf -->
### `d050eea3c` `src/taimdmd.cpp:108-109`

Mapping: `strong`. comment lies after mapped function TribeMainDecisionAIModule at old line 106.

```text
// PDB lines 175-231; VA 004E4B80.
// BINARY NOTE: The shipped load constructor stores its derived vptr at +0x114,
```
<!-- end-recovered:245ef70fd794aafe2cbf -->

<!-- recovered:22b7dc95ac0b88389145 -->
### `4bd44d0bfdf7` `src/scratch/004E4B80_TribeMainDecisionAIModule.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004E4B80 TribeMainDecisionAIModule::TribeMainDecisionAIModule
// taimdmd.cpp
// FLAGS: /GX
// Attempt log:
// initial natural constructor reconstruction using known subobject offsets and /GX EH context.
// 2: renamed all nine setup calls to the binary-proven setMainDecisionAI
//    member surface; standalone relocations changed from 9 failures to none.
// 3: added the exact-class virtual destructor declaration and tested novtable.
//    The novtable form lost six bytes and was restored.
// BINARY NOTE: the shipped constructor stores its derived vptr at +0x114,
//    after field initialization.  VC5 emits that store at +0xEA here.
// Final clean checkpoint: 15-byte mismatch remains after the recorded source
// shape probes. The natural source and exact call sequence are retained.
```
<!-- end-recovered:22b7dc95ac0b88389145 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
