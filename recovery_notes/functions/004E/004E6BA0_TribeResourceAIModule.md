# Recovery journal: 004E6BA0 `TribeResourceAIModule`

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


<!-- recovered:ec9fc4ae75f3c794cae5 -->
### `d050eea3c` `src/tairesmd.cpp:25-26`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// 004E6BA0 TribeResourceAIModule::TribeResourceAIModule(int, int)
// PDB: tairesmd.cpp lines 38-40. Status: matching.
```
<!-- end-recovered:ec9fc4ae75f3c794cae5 -->

<!-- recovered:ef05a93ce991b5d14d37 -->
### `6a2aef2e2` `src/tairesmd.cpp:11-12`

Mapping: `strong`. next mapped function definition is TribeResourceAIModule at old line 19.

```text
// Both members are initialized in the initializer list. VC5 then
// emits the derived vtable store after the member stores, matching the binary.
```
<!-- end-recovered:ef05a93ce991b5d14d37 -->

<!-- recovered:9ef94a9ab6ceb1efa240 -->
### `44679cc1b979` `src/matching/004E6BA0_TribeResourceAIModule.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004E6BA0 TribeResourceAIModule::TribeResourceAIModule
// Source: tairesmd.cpp lines 38-40
// Size: 117 bytes, EH-framed
//
// Attempt log:
// Probe 1: fixed AIModule base size (gap_04[0xEC] for sizeof 0xF0), /GX
// Probe 2: init-list for md=0 to change store order vs vtable
```
<!-- end-recovered:9ef94a9ab6ceb1efa240 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
