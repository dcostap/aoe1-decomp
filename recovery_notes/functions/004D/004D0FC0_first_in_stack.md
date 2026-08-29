# Recovery journal: 004D0FC0 `first_in_stack`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/tact_mob.cpp`.
- PDB source: `C:\msdev\work\age1_x1\tact_mob.cpp`.
- Earlier recovery note: `recovery_notes/tact_mob_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:2200e373ea2f24734293 -->
### `d050eea3c` `src/tact_mob.cpp:75-75`

Mapping: `strong`. next mapped function definition is first_in_stack at old line 82.

```text
// VA 004D0F70; PDB tact_mob.cpp:69-76; matching.
```
<!-- end-recovered:2200e373ea2f24734293 -->

<!-- recovered:82a4dd69a5a02636e760 -->
### `d050eea3c` `src/tact_mob.cpp:84-85`

Mapping: `strong`. comment lies after mapped function first_in_stack at old line 82.

```text
// VA 004D0FC0; PDB tact_mob.cpp:79-116; scratch.
// The natural body misses one virtual call and has broad call-surface drift.
```
<!-- end-recovered:82a4dd69a5a02636e760 -->

<!-- recovered:d434746734ec0f68a995 -->
### `912332e8f578` `src/accepted_drift/004D0FC0_first_in_stack.cpp:1-61`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004D0FC0, first_in_stack, 288 bytes
// Source: tact_mob.cpp lines 79-116
// ACCEPTED_DRIFT: VC5 register allocation differs (AX vs DX for obj_id temp,
// plus speculative early load of this->obj). All calling conventions, stack
// cleanup, structural flow, and behavior identical.
//
// Key challenge: this function uses mixed calling conventions in its vtable:
//   - vtable[57] (0xE4, logFn): __cdecl — 5 stack args, caller cleans with
//     add esp, 14h
//   - vtable[67] (0x10C, zeroFn): __thiscall — ECX=this, callee cleans
//   - vtable[23] (0x5C, stateFn): __thiscall — ECX=this, callee cleans
//   - vtable[82] (0x148, spawnFn): __thiscall — ECX=this, callee cleans
//
// Solution: __declspec(novtable) interface classes with matching virtual
// function slots (57 dummies + __cdecl logFn + 9 dummies + __thiscall zeroFn
// for player; 82 dummies + __thiscall spawnFn for obj; 23 dummies + __thiscall
// stateFn for this). The __declspec(novtable) prevents compiler from generating
// vtable init code, avoiding push ebp.
//
// Remaining drift:
// 1. obj_id register: original `mov dx, [esi+40h]` (DX), rebuilt `mov ax,
//    [esi+40h]` (AX) — pure register allocator choice.
// 2. Speculative load: original doesn't load this->obj until inside the
//    negative path. Rebuilt loads `this->obj` into ECX immediately after
//    loading obj_id (between mov and test). This adds a 3-byte instruction
//    that cascades alignment throughout the entire function.
// 3. Cascading register allocation: different register names throughout
//    (eax↔ecx↔edx, edi↔ebx, ebp↔edi, etc.) due to the different starting
//    register choice cascading through the compiler's register allocator.
//
// What matches: function size (288 bytes), prologue structure (push ebx, push
// esi, test al/al, push edi, mov esi/ecx), jump on zero at 0FD1, all calling
// conventions (__cdecl for logFn with add esp, 14h, __thiscall for others),
// all virtual calls at correct vtable offsets (0xE4, 0x10C, 0x5C, 0x148),
// pay_obj_cost call @ 00513C50, all string pushes with relocation masking,
// stack cleanup (ret 4). All control flow: negative path jumps over else to
// common tail, master_objects check splits free/occupied, pre_paid check
// controls pay_or_state vs pay_fail_path.
//
// Attempt log:
// - v1: __cdecl typedef for all vtable functions → push ebp from struct
//   declarations, 82.3% diff
// - v2: typedef approach with __cdecl for all → same push ebp issue
// - v3: __fastcall typedef for __thiscall entries → xor edx, edx at each call
// - v4: cleaned up __fastcall approach → xor edx edx persists (compiler
//   requirement for __fastcall via function pointer)
// - v5: real class hierarchy with virtual functions → push ebp from class
//   declarations (no novtable)
// - v6: hybrid __cdecl + __fastcall typedefs → xor edx edx at call sites
// - v7: member function call for pay_obj_cost + typedefs for vtable → 82.3%
// - v8: __declspec(novtable) interface classes → push ebp
// - v9: hybrid __cdecl + __fastcall, no local variables → xor edx, edx at
//   3 call sites, AX instead of DX for obj_id
// - v10: match PDB source structure precisely → 88.2% positional
// - v11: __declspec(novtable) interfaces with mixed __cdecl/__thiscall → 79.5%
//   positional, 36.1% edit diff. No push ebp. Direct this->obj->owner access.
//   BEST RESULT. Key differences: AX vs DX for obj_id, 3-byte early load.
// - v12: per-branch objp local → push ebp returned (compiler needs EBP for
//   the additional local)
// - Conclusion: v11 is optimal. Remaining register/scheduling diffs are
//   compiler-version-specific and unfixable from C++ source.
```
<!-- end-recovered:d434746734ec0f68a995 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
