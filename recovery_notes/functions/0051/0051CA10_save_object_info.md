# Recovery journal: 0051CA10 `save_object_info`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tpnl_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tpnl_obj.cpp`.
- Earlier recovery note: `recovery_notes/tpnl_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:27e69fff81d91c6c0963 -->
### `target-session` `build/target_sessions/0051CA10_save_object_info.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Candidate TU validation with save_object_info protected produced the expected symbol and MATCH 620/620.
```
<!-- end-recovered:27e69fff81d91c6c0963 -->

<!-- recovered:acd770a86577eae96d0a -->
### `0f9e0a1ccc96` `src/matching/0051CA10_save_object_info.cpp:1-17`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0051CA10 TRIBE_Panel_Object::save_object_info (620B)
// PDB: tpnl_obj.cpp:1139-1228
//
// Attempt log:
// - canonical baseline: reconstructed the mode score loop, the action/combat
//   snapshot, and the building/population snapshot using the proven period
//   object layouts and virtual getter surface.
// - corrected the inherited static-object virtual count; combat getter calls
//   then landed at the proven 22C/230/234/238 slots.
// - restored the polymorphic master-object and player layouts (los +28,
//   attributes +50) and the unsigned 46h type threshold from the oracle.
// - a local action amount preserves the binary-proven fld-before-game-object
//   reload order in the final farm total; the source remains typed and has no
//   raw offset or register-forcing plumbing.
// - exact: 620/620 bytes, 15/15 ordered calls, frame 0xC, 171 instructions.
// - ABI repair: protected access produces the PDB-qualified decorated owner
//   in the grouped translation unit.
```
<!-- end-recovered:acd770a86577eae96d0a -->

<!-- recovered:f84cec7440db31dc8f0a -->
### `0f9e0a1ccc96` `src/matching/0051CA10_save_object_info.cpp:85-86`

Mapping: `exact`. historical standalone source path names this target VA.

```text
    // The inherited object surface occupies slots 0..121.  The named fields
    // below retain the binary-proven RGE_Static_Object offsets.
```
<!-- end-recovered:f84cec7440db31dc8f0a -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
