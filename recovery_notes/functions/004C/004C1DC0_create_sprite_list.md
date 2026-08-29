# Recovery journal: 004C1DC0 `create_sprite_list`

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


<!-- recovered:0bc84609715563882e5a -->
### `9f29dc381200` `src/matching/004C1DC0_create_sprite_list.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt log:
// first pass: straight new-expression wrapper with the live EH/new prolog in mind
// second pass: add a per-function /GX rsp because this helper lives in the EH/new constructor family
// rsp used: config/flags/004C1DC0_create_sprite_list.rsp = /nologo /c /O2 /Oy /GX
// target shape: return new RGE_Active_Sprite_List(this);
```
<!-- end-recovered:0bc84609715563882e5a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
