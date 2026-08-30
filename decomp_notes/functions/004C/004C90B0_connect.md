# Function notes: 004C90B0 `connect`

Module notes: `decomp_notes/t_b_obj_module.md`.

## Recovered attempt history

<!-- recovered:d83eab1a06f731756d79 -->
### `target-session` `build/target_sessions/004C90B0_connect.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MISMATCH; diff=1; shape=98.63013698630137: Bind connect rotate calls to original RGE_Moving_Object virtual long target.
```
<!-- end-recovered:d83eab1a06f731756d79 -->

<!-- recovered:29c81e5c12a6803c5f54 -->
### `9f29dc381200` `src/matching/004C90B0_connect.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C90B0 TRIBE_Building_Object::connect
// PDB source: t_b_obj.cpp
// Baseline: natural building-neighbor reconnection flow, using the same
// binary-proven field and check surface as the exact connect2 sibling.
// Attempt log:
// - Full base surface with function-scope branch aliases kept live added 9
//   bytes and saved EBX; flattening the surface did not change that basin.
// - Scoping the branch-only aliases before the common connect2 tail restored
//   the stack reloads and matched all 200 bytes.
// - A combined if/else spelling was 4 bytes off from alias load order; the
//   nested branches and explicit shared continuation below are retained.
```
<!-- end-recovered:29c81e5c12a6803c5f54 -->
