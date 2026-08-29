# Recovery journal: 004CA300 `setup`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_c_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_c_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_c_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:4da5c3b19ad626686094 -->
### `d050eea3c` `src/t_c_obj.cpp:66-66`

Mapping: `strong`. next mapped function definition is setup at old line 83.

```text
        // ORIGINAL BUG: The executable reads master->id before this test.
```
<!-- end-recovered:4da5c3b19ad626686094 -->

<!-- recovered:b823c699214e1107a222 -->
### `0923cad7edb1` `src/matching/004CA300_setup.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004CA300 TRIBE_Combat_Object::setup
// PDB source: t_c_obj.cpp:111-146
//
// Binary-supported ownership: RGE_Static_Object supplies master_obj (+0x08),
// owner (+0x0c), attribute_amount_held (+0x44), attribute_type_held (+0x4c),
// and type (+0x4e).  RGE_Combat_Object supplies capture_flag (+0x1c0), while
// TRIBE_Combat_Object adds own_master (+0x1c4).  The declaration-only virtual
// padding preserves the observed TRIBE initUnitAI/setup slots (+0x250/+0x254).
```
<!-- end-recovered:b823c699214e1107a222 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
