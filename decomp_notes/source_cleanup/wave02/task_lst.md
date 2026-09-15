# `task_lst.cpp` source-cleanup report

## Scope and commits

- Module: `src/task_lst.cpp`
- Branch: `cleanup/staging-20260915-33`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `11b723ce64894ffcbcfc43905ed9ea3a6640d51d`
- Changed files: `src/task_lst.cpp` and this report.
- Assigned header: `include/task_lst.h` (read only; not changed).
- Registry: `config/functions/src/task_lst.cpp.json`; build flags `gx`.
- PDB source: `C:\msdev\work\age1_x1\task_lst.cpp`.

Evidence came from the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json` and
all eleven packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/`:

- `00508E00_RGE_Task_List.txt`
- `00508E20_RGE_Task_List.txt`
- `00508E30_copy.txt`
- `00508EC0_load.txt`
- `00508F60_load.txt`
- `00509010_save.txt`
- `00509050_delete_list.txt`
- `005090B0_create_task.txt`
- `00509120_get_target_task.txt`
- `005092D0_is_attack_task.txt`
- `005092F0_check_task.txt`

The original executable used as the behavior oracle is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

## Cleanup performed

The source restores PDB parameter names and applies 1TBS function braces.
The changes keep types, declarations, scopes, storage, statements, calls,
literals, casts, evaluation order, and source order unchanged.

- `RGE_Task_List::copy`: `src` became the recovered PDB name `other_list`.
- Binary `RGE_Task_List::load`: `handle` became the recovered PDB name
  `infile`.
- Text `RGE_Task_List::load`: `file` became the recovered PDB name `infile`.
- `RGE_Task_List::save`: `fd` became the recovered PDB name `outfile`.
- `RGE_Task_List::create_task`: `object_id` became the recovered PDB name
  `index`.
- `RGE_Task_List::get_target_task`: restored `obj`, `target_obj`, `target_x`,
  `target_y`, and `target_z` from PDB records.
- `RGE_Task_List::check_task`: restored `obj` and `target_obj` from PDB
  records. The `task` parameter already matched the PDB.

No new local or parameter name was invented. Existing source-level names
`self`, `i`, `task`, `terrain_type`, `tile_x`, `tile_y`, and `map` remain in
place because the PDB has no matching lexical local records for them.

Recovered names are listed above. Invented names: none.

## PDB inspection coverage

Every registry function was inspected. Every procedure has a PDB register
record named `this` in `ecx`. PDB `function_statics` is empty for every
assigned procedure.

| VA | Registry status | PDB parameters and locals | Result |
| --- | --- | --- | --- |
| `00508E00` | `matching` | `this` only; no stack or local records | No name change. |
| `00508E20` | `matching` | `this` only; no stack or local records | No name change. |
| `00508E30` | `matching` | `other_list` at `+0x4`, `RGE_Task_List*`; no locals | Restored `other_list`. |
| `00508EC0` | `matching` | `infile` at `+0x4`, `int`; `sprites` at `+0x8`, `RGE_Sprite**`; `sounds` at `+0xc`, `RGE_Sound**`; `task_type` at `-0x4`, `short` | Restored `infile`; kept the PDB names `sprites`, `sounds`, and `task_type`. |
| `00508F60` | `matching` | `infile` at `+0x4`, `_iobuf*`; `sprites` at `+0x8`, `RGE_Sprite**`; `sounds` at `+0xc`, `RGE_Sound**`; `task_type` at `-0x4`, `short` | Restored `infile`; kept the PDB names `sprites`, `sounds`, and `task_type`. |
| `00509010` | `matching` | `outfile` at `+0x4`, `int`; no locals | Restored `outfile`. |
| `00509050` | `matching` | `this` only; no stack or local records | Kept source locals `i` and `task`; no forced mapping. |
| `005090B0` | `matching` | `task_type` at `+0x4`, `short`; `index` at `+0x8`, `short`; no locals | Restored `index`; kept `task_type`. |
| `00509120` | `matching` | `obj` at `+0x4`, `RGE_Action_Object*`; `target_obj` at `+0x8`, `RGE_Static_Object*`; `target_x` at `+0xc`, `float`; `target_y` at `+0x10`, `float`; `target_z` at `+0x14`, `float`; no locals | Restored all five parameters. Source locals have no PDB records. |
| `005092D0` | `matching` | `task` at `+0x4`, `RGE_Task*`; no locals | No name change. |
| `005092F0` | `matching` | `task` at `+0x4`, `RGE_Task*`; `obj` at `+0x8`, `RGE_Action_Object*`; `target_obj` at `+0xc`, `RGE_Static_Object*`; no locals | Restored `obj` and `target_obj`; kept `task`. |

The PDB and packet evidence does not map the source `self` aliases in the two
load functions. It also does not map loop counters, the delete-loop pointer,
the create-task pointer, or the terrain locals. Those mappings remain
unresolved. No reused stack slot was forced onto a source declaration.

## Constants, resources, and comments

The source adds no named constant or enum. Existing values remain unchanged,
including task type `1`, attack action type `7`, owner types `1` through `5`,
and the state and combat comparisons.

The two added comments describe existing global values and conditions:

- `src/game_globals.cpp:593` defines `DAT_00576540` as `-1.0f`. The
  `00509120` packet shows that either matching coordinate skips the terrain
  lookup. The source comment records this sentinel use.
- `src/game_globals.cpp:594` defines `DAT_00576544` as `0.0f`. The `005092F0`
  packet shows that a task with `holding_attr == 1` rejects a non-positive
  `attribute_amount_held`. The source comment records this constraint.

This module has no resource ID or resource lookup. No per-ID text, missing
block, empty slot, language, lookup path, purpose, or proposed cleanup name
applies. No resource macro or header definition was added. For provenance,
the hashed resource inputs are:

- `runtime/language.dll`: SHA-256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- `runtime/languagex.dll`: SHA-256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
- Pinned original
  `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`:
  SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

The resource files were not extracted because this source has no resource
call site.

## Header and shared-file requests

The owner of `include/task_lst.h` may add the recovered names to its otherwise
unnamed declarations. The request is name-only and does not change an ABI,
type, virtual slot, or layout:

```cpp
void copy(RGE_Task_List* other_list);
void load(int infile, RGE_Sprite**, RGE_Sound**);
void load(FILE* infile, RGE_Sprite**, RGE_Sound**);
void save(int outfile);
virtual RGE_Task* create_task(short task_type, short index);
virtual RGE_Task* get_target_task(RGE_Action_Object* obj, RGE_Static_Object* target_obj,
                                  float target_x, float target_y, float target_z);
virtual int is_attack_task(RGE_Task* task);
virtual int check_task(RGE_Task* task, RGE_Action_Object* obj, RGE_Static_Object* target_obj);
```

The declarations can remain unnamed. No root-owned shared-header or resource
ID request is open.

## Code-generation risks and validation limits

- Parameter renames affect debug names only. They keep each PDB type and stack
  position.
- Brace placement and two sparse comments can change PDB line records. They do
  not add or remove executable statements or scopes.
- The source retains the `self` aliases, explicit casts, narrow `short` values,
  loop forms, `goto`, virtual calls, direct calls, and numeric literals.
- No public symbol, class, member, layout, relocation, call target, or resource
  lookup changed by source inspection.
- The baseline already marks all eleven registry functions `matching`; this
  cleanup does not claim a new match or byte equality.

I reviewed the complete base-to-head diff and ran `git diff --check`.
Compilation, matching, audits, builds, and tests were not run. No compiler,
game, or runtime command was run. Final validation remains deferred to the
root stage.
