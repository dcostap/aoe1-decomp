# Recovery journal: 00539B90 `get_border_picture`

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


<!-- recovered:343fefe47766fe6fecc8 -->
### `target-session` `build/target_sessions/00539B90_get_border_picture.json:1-2`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: PDB-qualified protected owner is exact: rebuilt symbol is ?get_border_picture@RGE_View@@IAEFEEEFF@Z, body 00539B90-00539C7E, one-byte padding at 00539C7F before 00539C80.
probe 3 abi; result=MATCH; diff=0; shape=100.0: Module closure: protected get_border_picture declaration restores IAE symbol. [same emitted code as probe 2]
```
<!-- end-recovered:343fefe47766fe6fecc8 -->

<!-- recovered:ee42c9e6043ac532a1e4 -->
### `912332e8f578` `src/matching/00539B90_get_border_picture.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 00539B90 RGE_View::get_border_picture
// PDB: view.cpp:5617-5671, ?get_border_picture@RGE_View@@IAEFEEEFF@Z.
// Body: 00539B90-00539C7E. Padding: 00539C7F. Next: 00539C80.
// BINARY NOTE: The protected access is part of the PDB-qualified member ABI.
// Exact-finish note: public access kept bytes exact but emitted the QAE symbol;
// the protected declaration is retained for the original IAE symbol.
// 239 bytes, __thiscall
// short get_border_picture(uchar terrain_type, uchar row_idx, uchar col_idx, short param_4, short param_5)
```
<!-- end-recovered:ee42c9e6043ac532a1e4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
