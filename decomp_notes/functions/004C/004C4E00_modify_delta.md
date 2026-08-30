# Function notes: 004C4E00 `modify_delta`

Module notes: `decomp_notes/stat_obj_module.md`.

## Recovered attempt history

<!-- recovered:5c9eab4b3d2537a094a5 -->
### `target-session` `build/target_sessions/004C4E00_modify_delta.json:1-1`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 abi; result=MATCH; diff=0; shape=100.0: Changed modify_delta parameter from unsigned int to unsigned char and restored virtual member declaration. Dumpbin expects UAEXME; standalone exact check matches 139 bytes and symbol.
```
<!-- end-recovered:5c9eab4b3d2537a094a5 -->

<!-- recovered:d8f687eca84aa254fec7 -->
### `912332e8f578` `src/matching/004C4E00_modify_delta.cpp:1-5`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C4E00 RGE_Static_Object::modify_delta
// PDB source: stat_obj.cpp lines 2471-2486
// Attempt log:
// rewrite 2026-05-19: replaced wrong integer stub with packet-observed float/virtual-call behavior.
// retry: using unsigned int type plus switch(op) was the key for VC5 to emit the original `sub eax,0; je case0; dec eax; jne default` dispatch. Reusing the delta parameter stack slot via `*(int*)&delta` matched the FILD/FSTP stack-slot sequence. check_function: MATCH / 0.0000%.
```
<!-- end-recovered:d8f687eca84aa254fec7 -->
