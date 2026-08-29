# Recovery journal: 00532610 `handle_bring_object`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/victory.cpp`.
- PDB source: `C:\msdev\work\age1_x1\victory.cpp`.
- Earlier recovery note: `recovery_notes/victory_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:c7d404a0dfd54199f29e -->
### `target-session` `build/target_sessions/00532610_handle_bring_object.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Protected access and struct-tag declaration pass; verify standalone bytes and original symbol.
```
<!-- end-recovered:c7d404a0dfd54199f29e -->

<!-- recovered:5789978fefd86d01b357 -->
### `caa20929b406` `src/matching/00532610_handle_bring_object.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Victory_Conditions::handle_bring_object
// VA: 00532610
// victory.cpp
// 8.48% positional diff - register swap EDX<->ECX for this_obj/target_obj
```
<!-- end-recovered:5789978fefd86d01b357 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
