# Recovery journal: 004C1100 `RGE_Static_Object`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d290a01a1ef3e67db8ea -->
### `d050eea3c` `src/stat_obj.cpp:1-2`

Mapping: `strong`. next mapped function definition is RGE_Static_Object at old line 40.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\stat_obj.cpp.
// Definitions follow the original source order.
```
<!-- end-recovered:d290a01a1ef3e67db8ea -->

<!-- recovered:fe1da09ccc8f653aad09 -->
### `9acc26143f36` `src/scratch/004C1100_RGE_Static_Object.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C1100 RGE_Static_Object ctor (179B)
// stat_obj.cpp lines 132-136
// Attempt log:
// try 1: inherited one-int ctor stub with /GX too small/wrong signature.
// try 2: natural virtual class and full six-arg constructor; emitted EH but .text was 176 bytes (3 bytes short).
// try 3: novtable plus manual vptr store removed the EH constructor basin, 144-byte wrong family.
// try 4: normal virtual plus volatile keep local did not change 176-byte size.
// try 5: normal virtual plus manual vptr store again collapsed to 144-byte wrong family.
// try 6: polymorphic base class to force EH/base context reached 179 bytes but broad drift: compiler emits base vptr zero/store early and reorders -1/state/zero stores.
// try 7: setup return type void vs int; no codegen/size change.
// try 8: moving -1 stores before zero stores; no size/codegen improvement.
// try 9: flag probes /Ob0, /Ob1, /O2 without /Oy kept 176-byte short object; /O1 wrong smaller family.
// GIVEUP: left in scratch. Behavior and class layout are understood, but the exact constructor lowering needs a hidden class/member lifetime surface. Best natural virtual version is only 3 bytes short; adding novtable/manual vptr loses EH, while adding a polymorphic base reaches size but causes broad vptr/store-order drift. Not proposing accepted_drift because current comparable variant has broad constructor store-order/vptr drift, and the best 176-byte variant cannot be positionally validated by the checker.
```
<!-- end-recovered:fe1da09ccc8f653aad09 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
