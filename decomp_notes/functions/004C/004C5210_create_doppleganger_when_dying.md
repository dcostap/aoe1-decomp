# Function notes: 004C5210 `create_doppleganger_when_dying`

Module notes: `decomp_notes/stat_obj_module.md`.

## Recovered attempt history

<!-- recovered:98988f0aee23fd1f2f8d -->
### `056a20c24f68` `src/scratch/004C5210_create_doppleganger_when_dying.cpp:1-45`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C5210 RGE_Static_Object::create_doppleganger_when_dying
// PDB source: stat_obj.cpp:2663-2699
// Attempt log:
// 1 baseline: natural reconstruction (value local, mask first, != 0 guard). diff=141:
//   mask/explored got ebx/eax instead of eax/ebp (saved ebx instead of ebp), guard je not jbe.
// 2: guard spelled `> 0` (jbe) - no codegen change (VC5 canonicalizes unsigned >0 to !=0).
// 3: DECLARATION ORDER FIX: `explored` before `mask` flips VC5 into the original register
//   coloring (mask=eax+home, explored=ebp, saved ebp) - diff dropped 141 -> 4.
// 4: guard `> 0` now produces the original `jbe` (1 byte closer); diff=3.
// 5: call statement collapsed to one line - no change (still 3).
// 6: while-loop form - worse (27, assembly-farther 24); reverted to if+do-while.
// 7: for-loop increment-clause form - same 27; reverted.
// 8: variant lab (960 variants; axes guard/cond/access/call/bottom): G0000 = current
//   source is best at 3 bytes; no exact. Remaining 3-byte gap: the mask-home reload
//   `mov eax,[esp+10h]` after the virtual call sits in the CALL block in the original
//   (join at add edi,4) but in the LOOP-BOTTOM block in rebuilt (join at the reload),
//   shifting the three skip-branch displacements by 4 each.
// Left in scratch: canonical reconstruction matches size/calls/frame/registers/CFG 100%
//   shape; only the reload block-membership scheduling differs (3 bytes).
// 2026-08-09 session: nested explored/mask/index guards, an outer-loop player
//   declaration, an empty else, a post-call no-op mask reread, a repeated map
//   expression, and a full static-object virtual surface all emitted the same
//   3-byte mismatch; all were restored. A duplicated advance/continue form grew
//   17 bytes and was also restored.
// 2026-08-10 session (wave21-statobj-01): focused five-variant loop lab,
//   branch-local/duplicated updates, explicit loop-advance gotos, moved index
//   declaration, bottom `> 0`, and the ignored virtual-factory `void` return
//   all failed to move the 3-byte branch-displacement mismatch. The lab's only
//   size/frame/call-set eligible basin remained the canonical 223-byte source;
//   restore and retain it. No exact match found; next lead is a genuinely
//   different period source/control-flow context for placing the post-call mask
//   reload in the call block rather than the common loop-bottom block.
// 2026-08-11 session (sa-7f86d46a-r1-004C5210): a focused seven-form reload
//   lab (nested/conditional/continue/update spellings) found no exact output;
//   all size/frame/call-set eligible forms stayed at the same 3-byte drift.
//   Symbol-backed map declaration and full 0x88 static-object field surface
//   were tested and restored; split map-local initialization and a register
//   qualifier were codegen duplicates. A full-word explored-local/mask-copy
//   ownership form widened the mismatch and was restored. Retain the clean
//   223-byte typed reconstruction; the remaining blocker is VC5 placement of
//   the post-call mask reload in the call block versus the common loop bottom.
// 2026-08-12 session (orch-004C5210-L): exact source shape found by loading the
//   map word into the mask local, deriving explored from that local, then
//   masking the low word in place. This preserves the natural map-word split
//   and moves the VC5 reload into the call block; exact output is 223 bytes.
```
<!-- end-recovered:98988f0aee23fd1f2f8d -->
