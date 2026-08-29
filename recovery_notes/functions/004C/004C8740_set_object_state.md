# Recovery journal: 004C8740 `set_object_state`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:bfaf2f9b8132dcb4bc61 -->
### `a31dfd78d9df` `src/scratch/004C8740_set_object_state.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// Attempt log for 004C8740 TRIBE_Building_Object::set_object_state
// try 1: natural reconstruction from packet/decompiler; compile required cast simplification, too small 336B.
// try 2: /Oy- probe; too small 352B.
// try 3: /O1 probe; too small 321B.
// try 4: reviewed state==2 entry/random/debug sequence; behavioral outline present.
// try 5: reviewed virtual call offsets; source uses casts and is not exact member-call surface.
// try 6: reviewed terrain rectangle FPU/ftol sequence; mostly omitted, major size gap.
// try 7: reviewed tech/sound cleanup state==3; omitted/placeholder.
// try 8: reviewed final base set_object_state order; approximate.
// try 9: attempted local type surface only; still behavioral scaffold.
// try 10: left in scratch; not exact-size.
// BLOCKER: rebuilt .text 336B vs original 791B; source is only partial scaffold missing terrain/tech/sound/helper call bodies and exact virtual/member-call surfaces. Not accepted_drift-safe.
```
<!-- end-recovered:bfaf2f9b8132dcb4bc61 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
