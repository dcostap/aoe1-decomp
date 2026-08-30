# Recovery journal: 004C58C0 `more_room`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/stat_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\stat_obj.cpp`.
- Earlier recovery note: `recovery_notes/stat_obj_module.md`.

## Translation-unit context

The PDB module is `stat_obj.cpp`. The owner is `RGE_Static_Object`.
The source order is `004C5880 get_frame`, `004C58C0 more_room`, then
`004C58E0 enter_obj`. The original body is 19 bytes at `004C58C0-004C58D2`.
It has no frame, calls, relocations, or branches. It reads `this->objects` at
`+0x24`, then `this->master_obj` at `+0x08`. It compares the signed short
object count at list `+0x08` with the zero-extended byte `obj_max` at master
`+0x2C`.

## Current mismatch

The fresh natural baseline used the direct comparison expression. It emitted
23 bytes, with 8 instructions and a 4-byte boundary escape. VC5 loaded
`master_obj` first, kept the object-list pointer in `EAX`, and returned through
`CL` with an extra `xor` and `mov`.

The current natural source uses an explicit `if` with `return 1` and a final
`return 0`. It emits 19 bytes, 6 instructions, no frame, no calls, and the
correct closed boundary. It keeps the original `cmp`, `setl al`, and `ret`.
The remaining 9 positional differences are the order of the first three
loads. Rebuilt code is:

```text
mov eax,[ecx+8]
movzx dx,byte [eax+2Ch]
mov eax,[ecx+24h]
cmp [eax+8],dx
setl al
ret
```

The original loads `objects` first, then `master_obj`, then `obj_max`.
The checker classifies the remaining difference as instruction scheduling.
There are no relocation, owner, call, frame, or boundary errors.

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

### Wave 21 probes

- Separate object-list and master locals did not change the baseline 23-byte
  output.
- Comma sequencing, pointer references, declaration order, explicit short
  locals, cast variants, and a conditional result all did not change load
  order. Reversed comparison changed only predicate polarity.
- An explicit `if` with constant returns reduced the body to 19 bytes and
  produced `setl al` instead of `setl cl` plus `mov al,cl`.
- A volatile pointer forced the desired load order but added a stack save and
  reload. It is not a natural source form and was rejected.
- The explicit `if` form is retained because it is natural, behavior equal,
  and closes the original boundary. The direct expression is not retained.

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

The remaining blocker is the VC5 load order for two independent member
expressions. Test only a new, evidence-backed source dependency. Do not keep
volatile locals, raw field views, or compiler steering. If no natural dependency
changes the order, review the 9-byte scheduling difference as a narrow drift
proposal.

Final focused check: `check_function.py --va 004C58C0 --detail full --rebuild
--checkpoint wave21-final` reported `MISMATCH`, 19 versus 19 bytes, 9 differing
bytes, correct owner, frame, calls, and boundary. The grouped validation is in
`build/audits/workers/wave21-stat-obj/grouped`.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
