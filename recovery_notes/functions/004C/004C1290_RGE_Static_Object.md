# Recovery journal: 004C1290 `~RGE_Static_Object`

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


<!-- recovered:73a4e5f2129ce11317c4 -->
### `3719bc4b64cd` `src/scratch/004C1290_RGE_Static_Object.cpp:1-29`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004C1290 RGE_Static_Object::~RGE_Static_Object
// PDB: stat_obj.cpp:192-327, 388 bytes
// __thiscall, void
// FLAGS: default + /GX (EH)
//
// Attempt log:
// v0: compile errors (duplicate vtable ptr, wrong calling convention)
// v1: virtual dtor + /GX — no EH frame generated (368 < 388, body starts with push ebx)
// v2: __try/__finally — generates DIFFERENT EH pattern (EBP-frame-based, 76.8% diff)
// v3: fixed layout (no double vtable), member function calls — body identical except EH
// v4-v10: tested various /GX permutations — EH frame only generated in full-TU context
//
// ACCEPTED_DRIFT: EH frame not generated for root-class destructors in single-function
// compilation. Original has VC5 destructor EH frame (push -1; push handler; mov fs[0];esp;
// push ecx; state tracking stores). Our single-function /GX compile skips this because
// RGE_Static_Object has no base class with virtual destructor.
//
// Differences summary:
// 1. Missing: push -1; push handler; mov eax,fs[0]; push eax; mov fs[0],esp; push ecx (EH setup, 19 bytes)
// 2. Missing: mov [esp+0Ch], esi (this save for EH restore)
// 3. Missing: mov [esp+18h], 1 (EH state = 1 at start)
// 4. Missing: mov [esp+18h], bl (EH state = 0 before groupMembers free)
// 5. Missing: mov [esp+18h], -1 (EH state = -1 before pathingGroupMembers free)
// 6. Missing: mov ecx,[esp+10h]; mov fs[0],ecx (EH restore at end, 7 bytes)
// 7. Missing: add esp, 10h (EH stack cleanup, 3 bytes)
//
// All field accesses, branch targets, linked-list walk, virtual calls, and operator_delete
// calls are byte-identical between original and rebuilt body. This is pure structural EH
// frame overhead that's not replicable outside the full TU.
```
<!-- end-recovered:73a4e5f2129ce11317c4 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
