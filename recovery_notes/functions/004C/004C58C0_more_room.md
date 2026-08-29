# Recovery journal: 004C58C0 `more_room`

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


<!-- recovered:b675e432e19d0eddc9f2 -->
### `0c00f3d2dd72` `src/scratch/004C58C0_more_room.cpp:1-14`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C58C0 more_room (19B, stat_obj.cpp)
// Returns 1 if objects->number_of_objects < master_obj->obj_max
//
// Original asm:
//   mov eax,[ecx+24h]           ; objects
//   mov ecx,[ecx+8]             ; master_obj (reuses ecx register)
//   movzx dx,byte [ecx+2Ch]     ; obj_max
//   cmp [eax+8],dx              ; compare objects->count with obj_max
//   setl al                     ; result
//   ret
//
// Left in scratch: VC5 evaluates master_obj before objects (wrong register reuse),
// adds xor ecx,ecx (dead register), and truncates setl al + ret.
// All source variants produce same code.
```
<!-- end-recovered:b675e432e19d0eddc9f2 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
