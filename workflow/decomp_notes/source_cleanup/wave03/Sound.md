# `src/Sound.cpp` cleanup

## Delivery

- Module: `src/Sound.cpp`
- Slot and branch: 175, `cleanup/staging-20260915-175`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `2cd293369aa522d75889c3be17a4f2c593e0c5ff`
- Changed files: `src/Sound.cpp`, this report
- The source commit contains only the assigned source file. The report is committed separately.

The source owns the 14 registered procedures at `004BBE40` through `004BC540`.
The paired header `include/sound.h` was read but not changed.
The registry is `config/functions/src/Sound.cpp.json`, with module flags `gx`.

## PDB inspection and original-name recovery

I inspected every source-owned procedure in the scoped PDB record at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
All records use module object path `.\\Release\\Sound.obj`. Each member record
has `this` as `RGE_Sound*` in `ecx`. No function-static record or other register
record is present.

The registry-selected original packets are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BBE40_RGE_Sound.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BBF30_RGE_Sound.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC070_RGE_Sound.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC080_RGE_Sound.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC0F0_save.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC190_restart_sound.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC270_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC2D0_set_cache_time.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC2E0_play_at_update.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC2F0_update_play.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC310_play.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC470_get_file_name.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC4F0_stop.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/004B/004BC540_is_playing.txt`

The packet records use original source path `C:\\msdev\\work\\age1_x1\\Sound.cpp`.
They provide the original body ranges, line records, and assembly for every row.

| VA | Function | PDB source span and records | PDB parameters and locals | Cleanup result |
| --- | --- | --- | --- | --- |
| `004BBE40` | `RGE_Sound(_iobuf*, short)` | 35-58; 13 records | `infile` (`_iobuf*`, `+0x4`), `in_id` (`short`, `+0x8`), `index` (`long`, `+0xc`); `this` in `ecx` | Restored `infile`, `in_id`, and `index`. The source keeps the existing `int` type for the loop declaration. |
| `004BBF30` | `RGE_Sound(int, TSound_Driver*)` | 64-89; 17 records | `infile` (`int`, `+0x4`), `sound` (`TSound_Driver*`, `+0x8`); `this` in `ecx` | Restored `infile` and `sound`. |
| `004BC070` | `RGE_Sound()` | 94-98; 5 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |
| `004BC080` | `~RGE_Sound()` | 103-123; 4 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |
| `004BC0F0` | `save(int)` | 129-146; 12 records | `outfile` (`int`, `+0x4`); `this` in `ecx` | Restored `outfile`. |
| `004BC190` | `restart_sound(TSound_Driver*)` | 151-165; 12 records | `sound` (`TSound_Driver*`, `+0x4`); `this` in `ecx` | Restored `sound`. |
| `004BC270` | `update(unsigned long)` | 170-185; 4 records | `curr_time` (`unsigned long`, `+0x4`); `this` in `ecx` | Restored `curr_time`. |
| `004BC2D0` | `set_cache_time(unsigned long)` | 190-192; 2 records | `new_cache_time` (`unsigned long`, `+0x4`); `this` in `ecx` | Restored `new_cache_time`. |
| `004BC2E0` | `play_at_update()` | 197-199; 2 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |
| `004BC2F0` | `update_play()` | 204-210; 5 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |
| `004BC310` | `play(int)` | 215-273; 25 records | `add_to_play_list` (`int`, `+0x4`), `s` (`char[256]`, `-0x100`); `this` in `ecx` | Restored `add_to_play_list`; `s` already matched the PDB. |
| `004BC470` | `get_file_name()` | 278-299; 10 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |
| `004BC4F0` | `stop()` | 304-318; 6 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |
| `004BC540` | `is_playing()` | 323-339; 11 records | No stack parameters or locals; `this` in `ecx` | No source names to recover. |

The restored names are recovered original spellings from the PDB. No new
parameter or local name was invented. Existing locals without a reliable PDB
mapping remain unchanged: `i`, `count`, `digital`, `rand_val`, and
`saved_time_get`. The `s` array and the `index` loop have direct PDB mappings.
The PDB reports `index` as `long`, while the current source declaration is
`int`; this cleanup preserves the current type and records the difference.
No optimized stack slot was assigned to an unrelated source declaration.

## Constants, resources, comments, and formatting

No constant or resource ID changed. The source has no resource lookup. The
numeric values `0x24` and `0x0D` remain the proven allocation and serialized
name-byte widths shown by the original packets. The pinned CRT `STDLIB.H`
defines `RAND_MAX` as `0x7fff`, but the source keeps the original numeric
literal in the `debug_rand` scaling expression. No shared constant mapping is
requested.

No new comment was needed. The existing source-only declaration comment remains.
All 14 function definitions now use 1TBS braces. The edit keeps types, casts,
scopes, declaration order, storage, calls, evaluation order, literals, and
source order unchanged. It does not alter `include/sound.h`.

## Identity and validation risks

The edit changes recovered parameter and local identifiers and function-brace
formatting. It does not change a public symbol, function signature type,
calling convention, class layout, virtual slot, call target, or control flow.
Parameter names and brace placement can change debug metadata. The `index`
source type discrepancy remains an open review item. No generated output or
byte equality claim is made because this phase forbids compilation.

The current registry marks `004BC270` as `accepted_drift` and the other 13
procedures as `matching`. This cleanup does not change those claims.

For reference, the preserved baseline artifacts are:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Sound.obj`, SHA-256 `c9ad7a2ab5f87b34cb06a3010fc04645909932f13d7daf44a69b4df737fa74f4`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`, SHA-256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`, SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

No shared-file request or unresolved resource mapping remains.

`git diff --check` passed, and the complete source diff was reviewed.
Compilation, matching, audits, and tests were not run, as required for this wave.
