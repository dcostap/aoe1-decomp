# Wave 02 cleanup report: `ttsk_lst.cpp`

## Delivery

- Module: `src/ttsk_lst.cpp`
- PDB source: `C:\\msdev\\work\\age1_x1\\ttsk_lst.cpp`
- Worker slot: 36
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Earlier source commit: `4e0192183b6768b3bd1b842952cf6eab9ed8a043`
- Final source commit: `95b7fa83e8e8b61f6fce66288eafc470a27b530d`
- Changed files:
  - `src/ttsk_lst.cpp`
  - `workflow/decomp_notes/source_cleanup/wave02/ttsk_lst.md`
- Header owner: owner 04 owns `include/ttsk_lst.h`. This worker did not edit it.

The source commits change local names and apply 1TBS brace placement. The final
source commit also formats `get_target_task` as a compact two-line signature.
It changes presentation only. It does not change types, scopes, expressions,
comparisons, statements, calls, or literals. The report commit follows the
source commits. The final delivery hash is in the worker response because a
report cannot contain its own commit hash.

## Root correction

The final source commit changes the definition to this two-line form:

```cpp
RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* obj, RGE_Static_Object* target_obj,
                                           float target_x, float target_y, float target_z) {
```

The continuation starts under the first parameter column. No source token
changed outside this signature's whitespace.

## Assigned functions and PDB inspection

Evidence came from the following files. The listed hashes identify the evidence
files used for this report.

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  - SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C3F0_get_target_task.txt`
  - SHA256: `d19c2343d98947ac8551410b81e2994b3f8057c0450c46afea06b95fd6719d6d`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/0052C8D0_is_attack_task.txt`
  - SHA256: `b1f520e1883e0c33e6d323538e4969ce8831a822c9cafdab39f39144d695d130`

### `0052C3F0` `TRIBE_Task_List::get_target_task`

- PDB scoped record: `__thiscall`, `this` in `ECX`, and five stack parameters.
- PDB parameters and types:
  - `obj`: `RGE_Action_Object*`, stack `+0x4`.
  - `target_obj`: `RGE_Static_Object*`, stack `+0x8`.
  - `target_x`: `float`, stack `+0xC`.
  - `target_y`: `float`, stack `+0x10`.
  - `target_z`: `float`, stack `+0x14`.
- All five PDB names already matched the source. The source keeps them.
- The packet body is `0052C3F0-0052C8A0`, with 1,201 bytes and source lines
  41-294. The scoped PDB size field reports 1,241 bytes. The reason for this
  size difference remains unresolved.
- The packet lists one saved decompiler stack temporary, `local_4`. It has no
  PDB scoped local name. The source keeps the direct `this` list access model.
- The source preserves seven ordered `RGE_Player::isAlly` calls and one direct
  `RGE_Task_List::get_target_task` call.
- No PDB local symbols exist for the source locals. Reused optimized stack
  mappings remain uncertain and were not forced.

### `0052C8D0` `TRIBE_Task_List::is_attack_task`

- PDB scoped record: `__thiscall`, `this` in `ECX`, and one stack parameter.
- PDB parameter and type: `task`, `RGE_Task*`, stack `+0x4`.
- The PDB name already matched the source. The source keeps it.
- The packet body is `0052C8D0-0052C8EB`, with 28 bytes and source lines
  299-304.
- No PDB local symbols exist for this function.

## Name recovery and cleanup names

### Recovered original names

The scoped PDB recovers these names. They are not invented by this cleanup:

- `obj`
- `target_obj`
- `target_x`
- `target_y`
- `target_z`
- `task`

The PDB does not recover local names for either function. No local name is
claimed as an original spelling.

### New cleanup names

The source uses these new snake_case names. Their meanings follow direct field
reads and comparisons in the function packet:

- `target_id` replaces `object_id`. It stores a candidate target master ID.
- `alternate_target_id` replaces `object_id2`. It stores the second candidate
  target master ID.
- `source_group` replaces the first `object_group`. It comes from
  `obj->master_obj->object_group`.
- `target_group` replaces each target-side `object_group`. It comes from the
  target master object and compares with task object groups or exclusions.
- `index` replaces each loop-local `i`. It indexes the task list.

The existing names `attribute_type`, `task`, and `master_obj` are descriptive.
The PDB has no local records that can prove different original spellings, so the
cleanup does not claim them as recovered names.

## Constants and code evidence

No shared constant or enum has a proved equal role and value for the numeric
state, group, object, or action values in this module. The source keeps every
literal and its type. It does not add local constants.

The function packet proves these uses:

- `0052C40F-0052C41D` compares the held amount with the original float global
  at `DAT_0057733C`. The global inventory records `0.0f`. The source's existing
  `0.0f` spelling was not changed in this cleanup.
- `0052C435-0052C49B` selects target master IDs from source object group and
  held attribute type.
- `0052C4D2-0052C502` scans tasks for matching attribute type and action values
  `5`, `0x6E`, or `0x6F`.
- `0052C549-0052C55B` scans for action `0x65`.
- `0052C5C6-0052C5D9` scans for action `3`.
- `0052C658-0052C67D` scans repair action `0x6A` with wildcard object groups
  `-1` and `0`.
- `0052C72A-0052C742` scans repair action `0x6A` for the target group.
- `0052C7BA-0052C7CC` scans conversion action `0x68`.
- `0052C85B-0052C869` scans healing action `0x69`.
- `0052C894` is the direct base fallback call.

The original behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

The source changes only identifier spellings and brace placement. It does not
change the narrow `short` locals, explicit casts, comparisons, loop order,
return paths, or call order.

## Resource evidence

This module has no resource lookup call and no resource ID expression. It does
not call a string-table API. Therefore, no per-ID row exists:

- ID: none.
- Text: not applicable.
- Missing or empty slot: not applicable.
- Language: not applicable.
- Resource module and lookup path: not applicable.
- Call-site purpose: not applicable.
- Proposed cleanup name: not applicable.

The resource files were not used for this module. Their current hashes are
recorded only to prevent a false resource claim:

- `runtime/language.dll`: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `runtime/languagex.dll`: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `orig/.../XPack/languagex.dll`:
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

## Comments and formatting

No source comment was added. The existing ownership comment remains accurate.
The function and `else` braces now follow 1TBS. The edits do not move a
statement or change a preprocessor boundary.

## Code-generation risks

- Local identifier changes should not change release code, ABI, layout, or
  symbol identity. No compiler check was allowed in this wave.
- Brace placement can change debug line records. It does not change executable
  statements, but final validation must check the rebuilt output.
- `0052C3F0` remains a known non-exact source reconstruction. Earlier evidence
  reports a 1,201-byte rebuild with 481 differing bytes and eight aligned calls.
  This cleanup does not claim a new match or accepted drift.
- `0052C8D0` was an exact neighbor before this cleanup. The source keeps its
  control flow and call target unchanged.
- The scoped PDB size and packet body-size difference remains unresolved.

## Shared-file requests and unresolved questions

- No header change is requested.
- Owner 04 retains `include/ttsk_lst.h`.
- Root retains shared headers, including `include/game_globals.h` and
  `include/resource_ids.h`.
- No resource-ID declaration is requested.
- The original local spellings are unresolved because the PDB has no local
  records. Future source recovery may revise `target_id`,
  `alternate_target_id`, `source_group`, `target_group`, or `index` only with
  new source evidence.
- The PDB boundary-size discrepancy for `0052C3F0` needs owner-level review.
- The remaining positional differences in `0052C3F0` need separate codegen work.

## Validation status

Compilation, matching, audits, and tests were not run. No build, compiler,
matching, audit, test, or game command was run for this cleanup.
