# Source cleanup report: `task.cpp`

## Delivery

- Module: `src/task.cpp`
- Worker slot: `32`
- Branch: `cleanup/staging-20260915-32`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `5484289e95f4d09b077ff0f86ac4405fafef2ab5`
- Final delivery files: `src/task.cpp` and this report.
- The final delivery commit adds this report after the source commit. The full
  delivery hash is returned with the worker result.

The source registry assigns six functions to this module. All six registry
entries claim `matching`. The source changes recover PDB names and move
function braces to 1TBS form. No expression, control flow, call, type,
storage, declaration order, serialized field order, or data value changed.

## Evidence and hashes

The source registry is `config/functions/src/task.cpp.json`. Its PDB source
path is `C:\\msdev\\work\\age1_x1\\task.cpp`.

PDB evidence came from:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
  - SHA256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`
- `inventory/functions/0050/00508670_RGE_Task.txt`
  - SHA256: `86ea40d668ffeb4fa00b0566da6142fe134f711aaf446691a9dafcdc0dea6939`
- `inventory/functions/0050/005086F0_RGE_Task.txt`
  - SHA256: `db4db7401cc90eacb334be09b277ffa4f9de50d0fe0aecc9500e341f19f7cbb7`
- `inventory/functions/0050/00508700_copy.txt`
  - SHA256: `a9c3879cfad58e923236218dfeb4ae62cbb02b4e809b1a784c31c7230b69e499`
- `inventory/functions/0050/005087C0_load.txt`
  - SHA256: `82f375eb03475de060567ea7ba02ed7837c2d41dee4e69949a65619a3f66964d`
- `inventory/functions/0050/00508A20_load.txt`
  - SHA256: `1936c62af957b4e90da4276d65dc0a9365ea661f704be556a4265986e48ed5a5`
- `inventory/functions/0050/00508BB0_save.txt`
  - SHA256: `ba094a2d022b7625c60385d9a740fa3b146e23790dc8004cac29830ceb5eb58b`

The packets contain the original assembly, function boundaries, PDB line
records, and Ghidra listings. The original executable remains the behavior
oracle. Its inspected hash is:

- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup object is:

- `build/source-cleanup-20260915/preparation/baseline-build/task.obj`
  - SHA256: `f2dbadc0237fe15e47765fd5f2d5047d0243f28098e564010d67f2e5e34162eb`

## PDB inspection and name recovery

Every assigned procedure was inspected in `scoped_symbols.json`. Each has a
`this` register symbol in `ecx`. No assigned procedure has a function-static
symbol.

| VA | Function | PDB size | PDB stack symbols and offsets | Source result |
| --- | --- | ---: | --- | --- |
| `00508670` | `RGE_Task::RGE_Task` | 115 | `id_in` `+0x4` | Recovered `param_1` as `id_in`. |
| `005086F0` | `RGE_Task::~RGE_Task` | 1 | none | No parameter or local name to recover. |
| `00508700` | `RGE_Task::copy` | 189 | `other_task` `+0x4` | Recovered `src` as `other_task`. |
| `005087C0` | `RGE_Task::load(int, ...)` | 600 | `infile` `+0x4`; `sprites` `+0x8`; `sounds` `+0xc`; `short_val` `+0x8` | Recovered `fd` as `infile` and `id_value` as `short_val`. `sprites` and `sounds` already match. |
| `00508A20` | `RGE_Task::load(FILE*, ...)` | 389 | `infile` `+0x4`; `sprites` `+0x8`; `sounds` `+0xc`; `temp_combat_level` `-0x18`; `move_sprite_id` `-0xc`; `carry_sprite_id` `-0x6`; `temp_owner_type` `-0x12`; `work_sound2_id` `-0x2`; `temp_state_building` `-0xe`; `work_sound_id` `-0x4`; `work_sprite_id` `-0xa`; `work_sprite2_id` `-0x8`; `temp_holding_attr` `-0x10`; `temp_combat_level_flag` `-0x16`; `temp_search_flag` `-0x14`; `temp_is_default` `+0x8` | Recovered `file` as `infile`. All other PDB names already match the source. |
| `00508BB0` | `RGE_Task::save` | 582 | `outfile` `+0x4`; `short_val` `+0x8` | Recovered `fd` as `outfile` and `id_val` as `short_val`. |

The first `load` has a PDB `short_val` and the `sprites` parameter at the same
`+0x8` stack offset. The text `load` has `temp_is_default` and `sprites` at
the same `+0x8` offset. These are reused stack-slot records. The source keeps
separate declarations and does not force a storage or lifetime mapping.

The PDB does not record the local pointer names `selected_sprite` and
`selected_sound` in either load function. The source retains these existing
snake_case descriptive names. They are not claimed as recovered original
names. The `extern fscanf(FILE* file, ...)` declaration is not an assigned
procedure and has no PDB parameter record; its declaration name remains
unchanged.

## Recovered and existing names

Recovered original spellings:

- `id_in` in the constructor.
- `other_task` in `copy`.
- `infile` in both overloads of `load`.
- `short_val` in the binary `load` and `save` functions.

Existing names confirmed by PDB records:

- `sprites`, `sounds`.
- `temp_is_default`, `temp_combat_level`, `temp_combat_level_flag`,
  `temp_search_flag`, `temp_owner_type`, `temp_holding_attr`,
  `temp_state_building`.
- `move_sprite_id`, `work_sprite_id`, `work_sprite2_id`, `carry_sprite_id`,
  `work_sound_id`, and `work_sound2_id`.
- `this` in `ecx` for every procedure.

No PDB-backed parameter or local name remains unresolved. The pointer-local
names above remain an unresolved original-name mapping only.

## Constants, resources, and comments

No numeric constant changed. The `-1` values are preserved as the serialized
null-reference sentinel. The load packets show comparisons against `0xffff`
and null assignment on that value. The `1`, `2`, and `4` lengths remain the
original byte counts passed to `rge_read` and `rge_write`.

The existing save comments identify the six serialized sprite and sound IDs.
No new source comment was needed. No source comment was removed.

This module has no resource lookup and no resource ID. Therefore there is no
per-ID text, missing block, empty slot, language, lookup path, purpose, or
proposed cleanup name to report. No resource extraction was run. The supplied
resource files were not inputs to this module. For provenance, their hashes
are:

- `runtime/language.dll`: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- `runtime/languagex.dll`: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`:
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`

## Code-generation and ownership review

The source changes rename identifiers and move function-definition braces to
1TBS form. They do not change types, declaration scope, storage duration,
member order, evaluation order, calls, call targets, function boundaries,
relocations, ABI symbols, serialized field order, or literal types.

The `short_val` rename preserves the `short` type. The PDB's reused stack-slot
records remain represented by separate source declarations. No helper, wrapper,
layout change, assembly, or structural rewrite was added.

The source owner did not edit `include/task.h`. Header owner 04 may update its
parameter names, without changing types or ABI, to this recovered declaration
surface:

```cpp
RGE_Task(short id_in);
void copy(RGE_Task* other_task);
void load(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
void load(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds);
void save(int outfile);
```

No root-owned header or resource declaration request exists.

## Validation and unresolved questions

Evidence inspection and the complete assigned diff review were performed.
`git diff --check` was run before report creation.

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime harness was run.

Open question: the PDB does not preserve original names for
`selected_sprite` and `selected_sound`. Their current names are useful
inferred names, so the source leaves them unchanged.
