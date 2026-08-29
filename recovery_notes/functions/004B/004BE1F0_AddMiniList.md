# Recovery journal: 004BE1F0 `AddMiniList`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/spanlist.cpp`.
- PDB source: `C:\msdev\work\age1_x1\spanlist.cpp`.
- Earlier recovery note: `recovery_notes/spanlist_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:40d5c64bd0f7280019bc -->
### `target-session` `build/target_sessions/004BE1F0_AddMiniList.json:1-7`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 behavior; result=MATCH; diff=0; shape=100.0: Mirror exact SubtractMiniList source shape with canonical Y_delta/X_start/X_end ownership, copied offsets, and natural AddSpan call order.
probe 3 liveness; result=MATCH; diff=0; shape=100.0: Walkback: remove copied x/y offset locals and use incoming parameters directly. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=51; shape=85.29411764705883: Walkback: remove the carried y_delta local and reread the canonical byte field.
probe 6 abi; result=MATCH; diff=0; shape=100.0: Walkback: remove explicit this qualifier from the AddSpan member call. [same emitted code as probe 3]
probe 7 behavior; result=MATCH; diff=0; shape=100.0: Walkback: remove explicit int casts from unsigned-byte span endpoints. [same emitted code as probe 6]
probe 8 liveness; result=MATCH; diff=0; shape=100.0: Reduced exact source: remove copied offset locals after proving direct parameter use is codegen-identical. [same emitted code as probe 7]
probe 9 liveness; result=MATCH; diff=0; shape=100.0: Walkback from reduced exact source: split y_delta declaration from its field initialization. [same emitted code as probe 8]
```
<!-- end-recovered:40d5c64bd0f7280019bc -->

<!-- recovered:d3f6488bc8471e3d806a -->
### `037950f4de84` `src/scratch/004BE1F0_AddMiniList.cpp:1-2`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// first pass: walk 3-byte span records, stop on 0xFF in the first byte, and feed each span into AddSpan
// tried direct AddSpan calls, swapped offset parameter names, and an unsigned-int first-byte compare; the remaining mismatch stayed in the early prolog / branch-displacement basin
```
<!-- end-recovered:d3f6488bc8471e3d806a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
