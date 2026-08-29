# Recovery journal: 004D21B0 `TRIBE_Action_Make_Tech`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_tek.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_tek.cpp`.
- Earlier recovery note: `recovery_notes/tact_tek_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:7a587a8c01909197b2b3 -->
### `d050eea3c` `src/tact_tek.cpp:20-30`

Mapping: `strong`. comment lies after mapped function TRIBE_Action_Make_Tech at old line 14.

```text
// 004D21B0  lines 29-34  matching
// 004D2250  lines 41-45  accepted_drift
// 004D2290  lines 49-64  scratch
// 004D2370  lines 68-73  matching
// 004D23B0  lines 76-98  matching
// 004D2440  lines 102-106 matching
// 004D2450  lines 109-134 scratch
// 004D2550  lines 138-147 matching
// 004D25E0  lines 151-164 accepted_drift

// VA 004D21B0; PDB tact_tek.cpp:29-34; matching.
```
<!-- end-recovered:7a587a8c01909197b2b3 -->

<!-- recovered:d0b3bda199b212289d53 -->
### `a5fb96a1e6de` `src/scratch/004D21B0_TRIBE_Action_Make_Tech.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech ctor
// VA: 004D21B0
// PDB: tact_tek.cpp:29-34
// EH-framed, needs /GX
// [non-comment lines omitted during migration]
// Forward declare vtable-needed classes with dummy virtuals for slots 0-23+1
```
<!-- end-recovered:d0b3bda199b212289d53 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
