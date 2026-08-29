# Recovery journal: 004A94A0 `~TRIBE_Screen_Sed`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:d96fdd5829ba3d3f40ca -->
### `748d8fedf57a` `src/matching/004A94A0_TRIBE_Screen_Sed.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004A94A0 TRIBE_Screen_Sed::~TRIBE_Screen_Sed
// PDB: scr_sed.cpp:890-1144
// virtual __thiscall ~TRIBE_Screen_Sed()
// Attempt log:
// 1: broad reconstruction from packet/decompiler + scr_sed field layout; /GX EH destructor.
// Main-agent plausibility audit: replaced explicit destructor/operator_delete
// plumbing with ordinary `delete p`; emitted bytes remained exactly identical.
```
<!-- end-recovered:d96fdd5829ba3d3f40ca -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
