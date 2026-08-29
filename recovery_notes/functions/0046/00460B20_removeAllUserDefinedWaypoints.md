# Recovery journal: 00460B20 `removeAllUserDefinedWaypoints`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/move_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\move_obj.cpp`.
- Earlier recovery note: `recovery_notes/move_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:5e01d83d0f4882d57cbe -->
### `d050eea3c` `src/move_obj.cpp:2564-2565`

Mapping: `strong`. next mapped function definition is removeAllUserDefinedWaypoints at old line 2626.

```text
//    one top guard; exact 425-byte match (all four calls and all CFG blocks).
// Source audit: the +1C0 virtual call is the donor-backed
```
<!-- end-recovered:5e01d83d0f4882d57cbe -->

<!-- recovered:869d84089644e975e896 -->
### `6a2aef2e2` `src/move_obj.cpp:2326-2332`

Mapping: `strong`. next mapped function definition is removeAllUserDefinedWaypoints at old line 2391.

```text
// 1: the old stub only modeled the final-waypoint guard.  The binary instead
//    appends three-byte XYZBYTEPoint records and grows a 5/2x byte buffer.
//    exact call set and 425-byte neighborhood but had reversed capacity
//    operand order and a redundant nested copy-loop guard.
// 3: wrote the capacity test as max > count and flattened the copy loop to
// removeAllUserDefinedWaypoints slot; the surrounding ABI declarations retain
// the proven inherited slot order without manual vtable stores.
```
<!-- end-recovered:869d84089644e975e896 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
