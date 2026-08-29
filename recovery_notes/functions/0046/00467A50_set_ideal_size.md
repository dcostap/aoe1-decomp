# Recovery journal: 00467A50 `set_ideal_size`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/Panel_ez.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Panel_ez.cpp`.
- Earlier recovery note: `recovery_notes/Panel_ez_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:53e6ab50c4b74a669776 -->
### `target-session` `build/target_sessions/00467A50_set_ideal_size.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Replace the synthetic TRIBE_Screen_Sed_Open owner with PDB-proven protected virtual TEasy_Panel::set_ideal_size(long,long).
probe 2 context; result=MATCH; diff=0; shape=100.0: Walkback: restore the original wrapper include order. The anchor includes the shared header itself, so wrapper relocation is incidental. [same emitted code as probe 1]
```
<!-- end-recovered:53e6ab50c4b74a669776 -->

<!-- recovered:4b6daaeb63f7fdb3106e -->
### `82c8c744e6de` `src/matching/00467A50_set_ideal_size.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00467A50, TEasy_Panel::set_ideal_size, Panel_ez.cpp lines 559-562.
// Exact finish: the PDB-proven protected virtual long/long owner replaces a
// synthetic same-layout class. The shared class header belongs before the
// ordered Panel_ez.cpp method bodies; a repeated local include was incidental.
```
<!-- end-recovered:4b6daaeb63f7fdb3106e -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
