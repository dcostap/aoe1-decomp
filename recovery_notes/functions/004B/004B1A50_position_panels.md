# Recovery journal: 004B1A50 `position_panels`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/scr_sed2.cpp`.
- PDB source: `C:\msdev\work\age1_x1\scr_sed2.cpp`.
- Earlier recovery note: `recovery_notes/scr_sed2_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:3adfd4067bafba3e5a5f -->
### `d050eea3c` `src/scr_sed2.cpp:1281-1282`

Mapping: `exact`. removed comment declares this PDB source owner VA.

```text
// VA: 004B1A50 TRIBE_Screen_Sed::position_panels.
// BINARY NOTE: The panel cursor loops follow the adjacent array layout shown
```
<!-- end-recovered:3adfd4067bafba3e5a5f -->

<!-- recovered:c9e746e4ddc7711c16e3 -->
### `b6e159352e2d` `src/scratch/004B1A50_position_panels.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004B1A50 TRIBE_Screen_Sed::position_panels (3969 B)
// PDB source: scr_sed2.cpp:1900-2175
// Attempt log:
// - Replaced the panel-name placeholder with the binary-supported panel layout.
// - Baseline uses the recovered set_position/set_fixed_position virtual surfaces,
//   natural panel arrays, and the two layout loops shown by the source-line bands.
// - Restored omitted object, unit-list, victory, and current-message fields from
//   the proven offsets; signed /4 and %4 reproduces the victory grid arithmetic.
// - Best check is 3969/3969 bytes with 157/157 calls and 100% shape.  The only
//   drift is nine option-loop register-color bytes; the natural TTextPanel cursor
//   is retained after equivalent register probes produced no exact match.
// - Tested a TPanel base cursor for the adjacent option fields; emitted bytes
//   were unchanged, so the canonical TTextPanel cursor was restored.
```
<!-- end-recovered:c9e746e4ddc7711c16e3 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
