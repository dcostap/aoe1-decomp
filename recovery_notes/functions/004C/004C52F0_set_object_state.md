# Recovery journal: 004C52F0 `set_object_state`

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


<!-- recovered:189f166b11846b7030a2 -->
### `a31dfd78d9df` `src/scratch/004C52F0_set_object_state.cpp:1-13`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C52F0 RGE_Static_Object::set_object_state
// Attempt log:
// try 1: behavioral reconstruction from asm/Ghidra: state transition hooks, garrison/commander propagation, sleep flag update.
// try 2: fixed virtual surfaces for no-arg release and three-arg return/release calls so source compiles.
// try 3: modeled old<3/new>=3 owner-attribute removal and resource release for player mode 2.
// try 4: modeled old<=3/new>=7 recycle-in hook.
// try 5: modeled carried-resource transition from state 2 to >=3 with return/release resource calls and master float gate.
// try 6: modeled state 7 entry return-resource call.
// try 7: modeled state byte store before commander propagation.
// try 8: modeled commander/list dynamic-array growth, object lookup, low-state/unitAI filters, and commander reassignment.
// try 9: /Od probe exact-size but wrong debug-basin codegen; removed.
// try 10: /GX probe no useful change; removed.
// left in scratch: current clean source is 704B vs original 787B with broad dynamic-array/vtable/control-flow drift, not accepted_drift-safe.
```
<!-- end-recovered:189f166b11846b7030a2 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
