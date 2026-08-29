# Recovery journal: 004E4800 `TribeMainDecisionAIModule`

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


<!-- recovered:1d95b9608da9258e864f -->
### `d050eea3c` `src/taimdmd.cpp:1-2`

Mapping: `strong`. next mapped function definition is TribeMainDecisionAIModule at old line 27.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\taimdmd.cpp.
// Definitions follow the original PDB source order.
```
<!-- end-recovered:1d95b9608da9258e864f -->

<!-- recovered:877657aedf77272b5df9 -->
### `4bd44d0bfdf7` `src/scratch/004E4800_TribeMainDecisionAIModule.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E4800 TribeMainDecisionAIModule::TribeMainDecisionAIModule
// Attempt log:
// 1: natural constructor with member subobject ctors and initialization from packet.
// 2: replaced the AIModule-only base call with the binary-proven
//    MainDecisionAIModule constructor; all 46 direct targets now align.
// 3: added the canonical AIModule gap, MainDecision fields, and virtual
//    declarations.  Output stayed at 50 differing bytes.
// 4: novtable probes on the derived, MainDecision, and AIModule classes were
//    restored.  They removed or moved the vptr code and worsened the result.
// BINARY NOTE: the shipped constructor stores the derived vptr at +0x155,
//    after field initialization.  VC5 emits that store at +0xF7 here.
// Final clean checkpoint: 50-byte mismatch remains after the recorded source
// shape probes. The natural source and exact call sequence are retained.
```
<!-- end-recovered:877657aedf77272b5df9 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
