# `src/main.cpp` source-cleanup report

## Delivery

- Module: `src/main.cpp`
- Branch: `cleanup/staging-20260915-238`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Prior source commit: `7ee16156ed3c8ed8e0e13d3df57432e8b6200d90`
- Prior report correction commit: `fea76f18237366684de41e8f7e934b9d500d3872`
- Root resource mapping approval: `0aa69b43219d638bf1a6667b832257d633635ccf`
- Final source commit: `553533156bea1d6ae75661158e9e079d54e1d5e4`
- Base source blob: `77d20e3caa52ee276138a8b5f7a53cb82a3df977`
- Final source blob: `40c0ef4236cbc942a1b72e08b771cf49e4fb4872`
- Report commit: recorded in the delivery message after this report commit.
- Changed files:
  - `src/main.cpp`
  - `decomp_notes/source_cleanup/wave04/main.md`
- Header read but not changed: `include/main.h`

The registry entry is `config/functions/src/main.cpp.json`. It assigns one
function with the `gx` flag profile:

- `004549E0`, symbol `_WinMain@16`, status `matching`.

## Evidence paths

I read the repository and source-cleanup guides before editing. I used these
absolute evidence paths:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0045/004549E0_WinMain_16.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0054/0054F870_entry.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/build/direct-tas/original-pdb-types.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/include/main.h`
- `C:/Projects/my_decomps/aoe1_attempt3/include/tribegam.h`
- `C:/Projects/my_decomps/aoe1_attempt3/src/tribegam.cpp`
- `C:/Projects/my_decomps/aoe1_attempt3/src/basegame.cpp`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/main.cpp.json`

The original executable is the behavior oracle:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup executable is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## PDB coverage and name recovery

The source has one function. I inspected its complete procedure-scoped PDB
record, original assembly, line records, parameters, locals, and registers.

| VA | Function | Original span | PDB line records | PDB parameters and locals |
| --- | --- | --- | ---: | --- |
| `004549E0` | `WinMain` | `004549E0-00454FF0`, 1553 bytes | 39, source lines 66-192 | Parameters and locals listed below |

The PDB function type is `0x201D`. The original type record gives a `STD Near`
function that returns `int` and has four parameters. The argument list uses
`void*`, `void*`, `char*`, and `int`. The current `HINSTANCE` spelling keeps the
Windows API declaration while preserving the same pointer ABI.

PDB parameter records:

| PDB name | Offset | PDB type | Source result |
| --- | ---: | --- | --- |
| `prog_inst` | `+0x4` | `void*` | Recovered from `hInst`. |
| `prev_inst` | `+0x8` | `void*` | Recovered from `hPrev`. |
| `cmd_line` | `+0xC` | `char*` | Recovered from `cmdLine`. |
| `show_wnd_flag` | `+0x10` | `int` | Recovered from `nShow`. |

PDB local records:

| PDB name | Offset | PDB type | Source result |
| --- | ---: | --- | --- |
| `title` | `-0x20C` | `char[256]` | Already matched. |
| `msg` | `-0x10C` | `char[256]` | Already matched. |
| `retval` | `-0x144C` | `int` | Recovered from the outer `error_code`. |
| `info` | `-0x1444` | `RGE_Prog_Info` | Already matched. |
| `error_code` | `-0x1448` | `int` | Recovered from the inner `result`. |

The PDB records no function statics and no register symbols. The `game`
variable has no PDB declaration or register record. I kept its existing
`TRIBE_Game*` declaration and spelling. Its type is supported by the direct
constructor call at `00454F3F` and the current `TRIBE_Game` declaration. I did
not force a PDB name into this optimized declaration.

The entry procedure at `0054F870` calls `_WinMain@16` at `0054F9AA`. It pushes
four startup arguments in the expected order. No source caller declares an
additional `WinMain` interface. The function boundary and symbol remain
unchanged.

Recovered original spellings in `src/main.cpp` are:

- `prog_inst`, `prev_inst`, `cmd_line`, and `show_wnd_flag` for the four PDB parameters.
- `retval` for the returned status local.
- `error_code` for the constructor status local.

No new inferred name was added. `game` remains an existing descriptive name,
not a claimed original spelling. No reused stack-slot mapping was forced.

## Constants, resources, and comments

The call `MessageBoxA(0, msg, title, 0x10)` now uses `MB_ICONHAND`. The pinned
VC5 SDK header defines this macro at:

- `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H`, lines 5609-5610.

It expands to `0x00000010L`. The API converts it to its `UINT` parameter. The
effective flag value stays `0x10`. I did not use the newer `MB_ICONERROR` alias.

The source now includes the existing `resource_ids.h` header. It replaces only
the title lookup argument with the exact unsuffixed macro `STRING_ID_ERROR_TITLE`.
Both `0x100` buffer lengths and all other literals remain unchanged.

Root approved this mapping in commit
`0aa69b43219d638bf1a6667b832257d633635ccf`:

```cpp
#define STRING_ID_ERROR_TITLE 0x07D1
```

`STRING_ID_ERROR_TITLE` is a new cleanup name, not a proved original name. The error
path passes this ID to `TRIBE_Game::get_string`. The purpose is an error-dialog
title.

I checked the override and fallback lookup path. `TRIBE_Game::setup` loads the
default override `languagex.dll` at `src/tribegam.cpp:388-406`. The base setup
loads `language.dll` at `src/basegame.cpp:160,318`. `TRIBE_Game::get_string`
tries `StringTableX` first, then calls the base lookup when that result is zero.

I used `tools/inspect_pe_strings.py` after reading its `--help` output. The
checked files and results are:

| DLL and provenance | SHA256 | Language | ID result |
| --- | --- | --- | --- |
| `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/languagex.dll`, staged runtime override | `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39` | `0x0409` | `0x07D1`: empty slot, block 126 slot 1 |
| `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260914T230838850570Z/language.dll`, staged runtime fallback | `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5` | `0x0409` | `0x07D1`: `Error`, block 126 slot 1 |
| `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, pinned expansion override | `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2` | No returned language entry | `0x07D1`: missing |

The staged override has an empty `0x07D1` slot. `LoadStringA` returns zero for
that slot, so the base `language.dll` supplies `Error`. The pinned original
expansion has no `0x07D1` entry. The staged runtime fallback is the actual
checked base input. The loaded `Error` text is passed as `title` to
`MessageBoxA`, so it is the message-box caption.

I added one sparse comment before the second discarded `get_error_code()` call.
The original assembly at `00454F75` proves this status query is called and its
return value is discarded. The call order and call target remain unchanged.
No other comment was added or changed.

## Shared requests and unresolved mappings

- Root approval: `STRING_ID_ERROR_TITLE` is approved as `0x07D1` in commit `0aa69b43219d638bf1a6667b832257d633635ccf`.
- No `include/main.h` request is needed. It has no `WinMain` declaration.
- The original spelling of the optimized `game` declaration is unresolved.
  Its current type and source name remain unchanged.
- The original spelling of the `MB_ICONHAND` use is not recoverable from PDB
  records. The macro replaces a verified numeric API flag only.

## Code-generation and symbol effects

The source edits recover parameter and local names. They move the function
brace to 1TBS style and remove one leading blank line. They add one comment.
These changes can alter debug names and PDB line records.

The edits do not change the function boundary, `_WinMain@16` symbol, calling
convention, parameter types, local types, storage duration, scope, evaluation
order, call targets, literals except the equivalent message-box macro, or
structure layout. The `MB_ICONHAND` macro keeps the effective `0x10` flag.
Generated output and relocations remain unvalidated.

I reviewed the complete assigned diff. `git diff --check` passed before the
source commit. No unassigned file was edited.

Compilation, matching, audits, and tests were not run. No build, compiler
check, validation command, game, or runtime harness was run.
