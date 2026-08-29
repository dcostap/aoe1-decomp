# Recovery journal: 00539C80 `get_border_edge_pictures`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/view.cpp`.
- PDB source: `C:\msdev\work\age1_x1\view.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:83b3cbb4dd0bfc5f5627 -->
### `target-session` `build/target_sessions/00539C80_get_border_edge_pictures.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: PDB-qualified RGE_View::get_border_edge_pictures is protected with int& outputs; preserved border shape guard, four ordered protected get_border_picture calls, narrow uchar fields, output initialization, and boundary.
probe 2 abi; result=MATCH; diff=0; shape=100.0: Module closure: protected ref-output get_border_edge_pictures declaration restores IAE symbol. [same emitted code as probe 1]
```
<!-- end-recovered:83b3cbb4dd0bfc5f5627 -->

<!-- recovered:c357a73bc090ffee89de -->
### `912332e8f578` `src/matching/00539C80_get_border_edge_pictures.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00539C80 RGE_View::get_border_edge_pictures
// PDB: view.cpp:5677-5703, ?get_border_edge_pictures@RGE_View@@IAEHEEEFFAAH000@Z.
// Body: 00539C80-00539D83. Padding: 00539D84-00539D8F. Next: 00539D90.
// 260 bytes, __thiscall, protected member with four int& outputs.
// BINARY NOTE: Output stores occur before the map shape read.
// BINARY NOTE: The four calls keep the protected get_border_picture ABI.
// int get_border_edge_pictures(uchar terrain_type, uchar row_idx, uchar edge_mask, short param_4, short param_5, int& out1, int& out2, int& out3, int& out4)
```
<!-- end-recovered:c357a73bc090ffee89de -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
