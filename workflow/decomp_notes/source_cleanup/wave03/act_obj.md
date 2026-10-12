# `src/act_obj.cpp` cleanup report

## Delivery

- Module: `src/act_obj.cpp`.
- Report: `workflow/decomp_notes/source_cleanup/wave03/act_obj.md`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final commit: see the full Git hash in the delivery record.
- Changed files: the assigned source and this assigned report only.
- No header was changed.

## PDB coverage

I inspected every source owner in the module with the original procedure-scoped
PDB record at:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The source map at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
assigns these 35 normal owners to `C:\msdev\work\age1_x1\act_obj.cpp`:

`00405C60`, `00405F90`, `00406010`, `00406080`, `004060A0`, `004060D0`,
`00406120`, `004061A0`, `00406200`, `00406220`, `00406270`, `00406290`,
`004062B0`, `004062C0`, `00406300`, `00406430`, `00406470`, `00406830`,
`00406840`, `00406850`, `00406860`, `00406940`, `00406990`, `004069E0`,
`00406A00`, `00406A30`, `00406A50`, `00406A70`, `00406B90`, `00406BC0`,
`00406BF0`, `00406C10`, `00406C30`, `00406D00`, and `00406D30`.

Each normal record has `this` in `ecx` with type `RGE_Action_Object*`.
The `actionState` record has the proven const type. No normal record has an
additional register symbol. The adjacent compiler-generated scalar deleting
destructor at `00405F70` has `this` in `ecx` and `__flags` at `+0x4`; it has
no source body and was not changed.

The stack names from the PDB are:

- `00405C60`: `tobj`, `obj_owner`, `x`, `y`, `z`, `do_setup`.
- `00405F90`: `infile`, `gworld`, `do_setup`.
- `004060A0`: `tobj`, `obj_owner`, `x`, `y`, `z`.
- `004060D0`: `tobj`, `obj_owner`, `x`, `y`, `z`.
- `00406120`: `infile`, `gworld`.
- `00406220`: `outfile`.
- `00406270`: `obj`.
- `004062B0`: `player_id`, `relation`.
- `004062C0`, `00406300`, and `00406430`: `obj`, `x`, `y`, `z`.
- `00406470`: `obj`, `x`, `y`, `z`, `work_flag`; local `actionType`, `i`, and
  `skip`.
- `00406830`: `obj`.
- `00406860`: `obj`, `x`, `y`, `z`; local `i`.
- `00406940`: `task_id`.
- `00406990`: `t`.
- `004069E0`, `00406A00`, and `00406A30`: `action`.
- `00406B90`: `new_owner`.
- `00406BC0`: `source`.
- `00406C30`: `target`, `targetX`, `targetY`, `targetZ`; local `i`.

The other normal records have no stack symbols. This includes the destructor,
list creation, rehook, destroy, sound, stop, update, action query, target
query, state query, and checksum functions.

## Name recovery

I restored the PDB spellings in the source. This includes terse and mixed-style
names. The changes are:

- `00405C60`: `master` to `tobj`, `player` to `obj_owner`, and `flag` to
  `do_setup`.
- `00405F90`: `id` to `infile`, `world` to `gworld`, and `flag` to `do_setup`.
- `004060A0` and `004060D0`: `master_obj` to `tobj` and `player` to
  `obj_owner`.
- `00406120`: `handle` to `infile` and `world` to `gworld`.
- `00406220`: `handle` to `outfile`.
- `00406270`: `master` to `obj`.
- `004062B0`: `p0` to `player_id` and `p1` to `relation`.
- `004062C0`, `00406300`, and `00406430`: `target` to `obj`.
- `00406470`: `target` to `obj`, `flag` to `work_flag`, and `action_id` to
  the original mixed-style local `actionType`.
- `00406830`: `p0` to `obj`.
- `00406860`: `target` to `obj`. Its former local `obj` is now the cleanup
  name `master_obj`, because the PDB proves `obj` as the parameter.
- `00406990`: `task_id` to the original terse parameter `t`.
- `00406B90`: `player` to `new_owner`.
- `00406BC0`: `master_obj` to `source`.
- `00406C30`: `x`, `y`, and `z` to the original mixed-style names `targetX`,
  `targetY`, and `targetZ`.

The PDB does not map several optimized locals. I kept their existing useful
names and did not force a declaration mapping. These names are cleanup names,
not recovered originals: `action_list`, `master_obj` in `get_command_master`,
and the existing `task`, `action`, `current_task`, `other`, `order`,
`current_action`, `result`, `state`, `action_result`, `target_obj`, and
`checksum` locals.

The PDB records reused stack homes. In `move_to`, PDB local `action` shares
`+0x8` with parameter `x`. In `work2`, `actionType` and `i` both use `+0x8`.
In `get_command_master`, local `i` shares `+0x8` with parameter `x`. I kept
the source declarations, types, scopes, and order unchanged in these cases.
No uncertain mapping was forced.

## Formatting and evidence

I removed generated source-line marker comments. I moved function braces to the
module's 1TBS style. I made no new comment because the source has no comment
that adds a useful proven constraint.

I read the assigned header at
`C:/Projects/my_decomps/aoe1_attempt3/include/act_obj.h` and the related
`unit_ai_module.h` declaration. Original control-flow evidence remains in:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/act_obj.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/act_obj.cpp.decomp`

No constant or resource ID was investigated or changed. No resource lookup
exists in this module. There is no shared declaration request and no unresolved
header request.

The cleanup changes do not change types, casts, storage, declaration order,
call targets, expression order, literals, fields, layout, ABI, or public symbol
identity. They change names, comments, whitespace, and brace placement only.
The existing source behavior and known defects remain unchanged.

## Review and validation

I reviewed the complete Git diff and ran `git diff --check`. I did not run a
compiler, build, matching check, audit, test, or game. Compilation, matching,
audits, and tests were not run.
