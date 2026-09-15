# Source cleanup report: `src/Mouseptr.cpp`

## Delivery and scope

- Module: `src/Mouseptr.cpp`.
- Owner: owner 23, worker slot 203.
- Branch: `cleanup/staging-20260915-203`.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Final source commit: `bc965c6300baff1c6e00e5894ef6240cb08a3ce1`.
- Changed files:
  - `src/Mouseptr.cpp`
  - `decomp_notes/source_cleanup/wave04/Mouseptr.md`
- Paired header read only: `include/Mouseptr.h`.
- Registry: `config/functions/src/Mouseptr.cpp.json`.
- Registry build flags: `gx`.
- Source SHA-256 before cleanup: `6629579017fd4b84cd4e1146939870664fe2568fdce2068f4ad02e5c32a172a5`.
- Source SHA-256 after cleanup: `42c6c35b955ecd88c90e84e45c1fb2a3f4c02472fdda0de5e9b1202bca17bf42`.

The source keeps all 24 registry procedures in PDB source order. The cleanup
recovers procedure-scoped PDB parameter names and applies 1TBS function braces.
It keeps types, scopes, storage, declarations, expressions, calls, literals,
source order, and public symbols unchanged.

## Evidence inspected

I read the repository contract and all assigned cleanup guides:

- `C:/Projects/my_decomps/aoe1_attempt3/AGENTS.md`
- `C:/Projects/my_decomps/aoe1_attempt3/docs/source_cleanup.md`
- `C:/Projects/my_decomps/aoe1_attempt3/docs/source_comments.md`
- `C:/Projects/my_decomps/aoe1_attempt3/docs/resource_ids.md`
- `C:/Projects/my_decomps/aoe1_attempt3/docs/source_cleanup_owners.md`
- `C:/Projects/my_decomps/aoe1_attempt3/docs/testing.md`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/source_cleanup/wave04_assignments.md`

I inspected the assigned source, paired header, registry, prior module note,
and the existing function notes:

- `C:/Projects/my_decomps/aoe1_attempt3/src/Mouseptr.cpp`
- `C:/Projects/my_decomps/aoe1_attempt3/include/Mouseptr.h`
- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/Mouseptr.cpp.json`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/mouseptr.md`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/functions/0045/0045AE50.md`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/functions/0045/0045BE80.md`

I inspected all 24 original procedure packets under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0045/`:

- `0045AE50_TMousePointer.txt`
- `0045B000_TMousePointer.txt`
- `0045B040_Shutdown_Mouse.txt`
- `0045B0A0_Restore_Mouse.txt`
- `0045B120_setup.txt`
- `0045B290_set_game_mode.txt`
- `0045B2A0_set_game_enable.txt`
- `0045B2B0_get_game_enable.txt`
- `0045B2C0_in_game_mode.txt`
- `0045B2E0_set_game_window.txt`
- `0045B310_LoadCursors.txt`
- `0045B560_delete_surfaces.txt`
- `0045B5D0_create_surfaces.txt`
- `0045B760_update_mouse_position.txt`
- `0045BA60_draw.txt`
- `0045BD60_erase.txt`
- `0045BE20_set_facet.txt`
- `0045BE80_set_game_facet.txt`
- `0045BEE0_off.txt`
- `0045BF40_on.txt`
- `0045BF80_reset.txt`
- `0045BF90_center.txt`
- `0045C010_Poll.txt`
- `0045C300_GetDDBltError.txt`

The packets provide the original body ranges, source line spans, and assembly.
I also inspected the complete module decompiler and assembly references:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/mouseptr.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/mouseptr.cpp.asm`

The procedure-scoped PDB evidence is
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Its SHA-256 is `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The PDB source and line maps are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_line_changes.csv`

The original executable reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA-256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The original PDB is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`.
Its SHA-256 is `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.

The preserved pre-cleanup executable is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`.
Its SHA-256 is `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Mouseptr.obj`.
Its SHA-256 is `8cbb6bec400cb8aedd9a31e3e889fc326213530d5e178da0bcf8a78101bba3a1`.

## Original-name recovery coverage

Every assigned procedure has a PDB `this` register in `ecx` with type
`TMousePointer*`. The table lists every named PDB stack record. It preserves
mixed case, underscores, and terse original spellings.

| VA | Procedure and PDB span | Named parameters and locals | Source result |
| --- | --- | --- | --- |
| `0045AE50` | `TMousePointer::TMousePointer`, lines 27-106 | `+0x4 int MouseModeIn`; no named locals | Recovered `mode` as `MouseModeIn`. |
| `0045B000` | `TMousePointer::~TMousePointer`, lines 112-122 | No named stack records | No rename. |
| `0045B040` | `Shutdown_Mouse`, lines 129-157 | No named stack records | No rename. |
| `0045B0A0` | `Restore_Mouse`, lines 163-185 | `+0x4 TDrawArea* render_area_in` | Recovered `area` as `render_area_in`. |
| `0045B120` | `setup`, lines 192-275 | `+0x4 int custom_draw_in`; `+0x8 TDrawArea* render_area_in`; `+0xc char* cursor_file_name`; `+0x10 int cursor_resId`; `+0x14 int maxCursors_in`; `-0x110 char[260] file_name` | Recovered all five parameters. `file_name` already matched. |
| `0045B290` | `set_game_mode`, lines 281-283 | `+0x4 int mode` | Recovered `value` as `mode`. |
| `0045B2A0` | `set_game_enable`, lines 289-291 | `+0x4 int enable` | Recovered `value` as `enable`. |
| `0045B2B0` | `get_game_enable`, lines 298-300 | No named stack records | No rename. |
| `0045B2C0` | `in_game_mode`, lines 306-310 | No named stack records | No rename. |
| `0045B2E0` | `set_game_window`, lines 316-322 | `+0x4 int Left`; `+0x8 int Top`; `+0xc int Right`; `+0x10 int Bottom` | Recovered all four parameters with original case. |
| `0045B310` | `LoadCursors`, lines 372-484 | `+0x4 char* cursor_file_name`; `+0x8 int resId`; `+0xc int Reload`; `-0x10 int LoadOk` | Recovered all three parameters. `LoadOk` already matched. |
| `0045B560` | `delete_surfaces`, lines 494-520 | No named stack records | No rename. |
| `0045B5D0` | `create_surfaces`, lines 528-559 | `-0x2c char[32] NameBuf` | `NameBuf` already matched. |
| `0045B760` | `update_mouse_position`, lines 567-717 | `-0x8 tagPOINT point` | `point` already matched. |
| `0045BA60` | `draw`, lines 724-875 | `+0x4 int dMode`; `-0x4 IDirectDrawClipper* lplpDDClipper` | Recovered `forced` as `dMode`. `lplpDDClipper` already matched. |
| `0045BD60` | `erase`, lines 882-912 | No named stack records | No rename. |
| `0045BE20` | `set_facet`, lines 918-939 | `+0x4 int facet_in` | Recovered `f` as `facet_in`. |
| `0045BE80` | `set_game_facet`, lines 945-966 | `+0x4 int facet_in` | Already matched. |
| `0045BEE0` | `off`, lines 976-996 | No named stack records | No rename. |
| `0045BF40` | `on`, lines 1002-1014 | No named stack records | No rename. |
| `0045BF80` | `reset`, lines 1020-1023 | No named stack records | No rename. |
| `0045BF90` | `center`, lines 1029-1047 | `-0x10 tagRECT win_rect` | `win_rect` already matched. |
| `0045C010` | `Poll`, lines 1052-1211 | `-0x4 IDirectDrawClipper* lplpDDClipper` | `lplpDDClipper` already matched. |
| `0045C300` | `GetDDBltError`, lines 1215-1242 | `+0x4 long theError` | Recovered `a_hresult` as `theError`. |

The PDB records above are the complete named parameter, local, and register
coverage for all 24 functions. Unnamed EH slots and compiler bookkeeping slots
in the original packet listings are not source-name records. I left them and
their declaration structure unchanged.

### Renamed parameters and locals

All renamed identifiers are recovered original names from the scoped PDB. No
new parameter or local name was invented.

- `0045AE50`: `mode` -> `MouseModeIn`.
- `0045B0A0`: `area` -> `render_area_in`.
- `0045B120`: `custom_draw` -> `custom_draw_in`; `render_area` ->
  `render_area_in`; `base` -> `cursor_file_name`; `palette` -> `cursor_resId`;
  `max_cursors` -> `maxCursors_in`.
- `0045B290`: `value` -> `mode`.
- `0045B2A0`: `value` -> `enable`.
- `0045B2E0`: `left` -> `Left`; `top` -> `Top`; `right` -> `Right`;
  `bottom` -> `Bottom`.
- `0045B310`: `base` -> `cursor_file_name`; `file_id` -> `resId`;
  `keep_name` -> `Reload`.
- `0045BA60`: `forced` -> `dMode`.
- `0045BE20`: `f` -> `facet_in`.
- `0045C300`: `a_hresult` -> `theError`.

No PDB local name required a source rename. The PDB-backed names that already
matched the source are `file_name`, `LoadOk`, `NameBuf`, `point`,
`lplpDDClipper`, `facet_in`, `win_rect`, and the `this` register.

### Unresolved declaration mappings

The PDB has no named records for the remaining source locals. I did not force
optimized or reused stack slots into source declarations. I retained these
names and structures without claiming original provenance:

- `0045B000`: `shape`.
- `0045B310`: `count`, `old`, `shape`, `off`, `n`, `p`, `w`, `h`, `sh`, `si`,
  `cur`, and `pp`.
- `0045B560`: `self`, `t`, and `i`.
- `0045B5D0`: `i`.
- `0045B760`: `in_game`, `da`, `top`, and `t`.
- `0045BA60`: `t`, `err`, `ptVar1`, `p`, `f`, and `si`.
- `0045BE20`: `info`.
- `0045BE80`: `shape` and `info`.
- `0045BF90`: `draw_system`, `x`, and `y`.
- `0045C010`: `t`, `err`, `ptVar1`, `p`, and `si`.

The PDB does not prove whether these names are original, generated, or later
cleanup names. Their source declarations remain unchanged.

## Constants, resources, and comments

No numeric constant, enum, API flag, FourCC, or format value changed. Existing
literals such as `0x1000000`, `0x11`, `0x22`, `0x8000`, `0x10000`, `0x40`,
`0x30`, `-32767`, and the DirectDraw error values remain unchanged.

No string-table lookup occurs in this module. `cursor_resId` and `resId` are
integer arguments passed to `TShape`; they are not language string lookups.
No resource ID was inspected with `inspect_pe_strings.py`. No resource module,
DLL hash, language, numeric string ID, text, or lookup path applies. No new
resource mapping is requested.

The existing `LoadCursors` comment about the height check order remains. The
original packet shows the width read and check before the height read and check.
No source comment was added or removed.

## Code-generation, type, and layout review

The source changes rename parameters and move function opening braces onto the
definition lines. These edits do not change types, declaration order, scopes,
storage duration, casts, explicit `this->` access, control flow, evaluation
order, literals, calls, virtual slots, class layout, function boundaries,
calling conventions, relocations, or public symbols.

The names `cursor_resId`, `maxCursors_in`, `Reload`, `Left`, `Top`, `Right`,
`Bottom`, `dMode`, and `theError` retain their exact PDB spelling. The setup
signature remains a five-parameter `int`, `TDrawArea*`, `char*`, `int`, `int`
signature. The source keeps all existing declarations and does not add a
helper, alias, macro, type, or constant.

Brace movement reduces source line count and can change PDB line records. Name
changes can change debug names. Compiler output, program data, relocations,
call targets, and generated line metadata remain unvalidated.

## Shared-file requests and unresolved questions

I did not edit `include/Mouseptr.h`. Its owner may update parameter names only,
without changing types, order, access, or symbols:

```cpp
TMousePointer(int MouseModeIn);
int Restore_Mouse(TDrawArea* render_area_in);
int setup(int custom_draw_in, TDrawArea* render_area_in, char* cursor_file_name, int cursor_resId, int maxCursors_in);
void set_game_mode(int mode);
void set_game_enable(int enable);
void set_game_window(int Left, int Top, int Right, int Bottom);
int LoadCursors(char* cursor_file_name, int resId, int Reload);
void draw(int dMode);
void set_facet(int facet_in);
void set_game_facet(int facet_in);
int GetDDBltError(long theError);
```

This is a header parameter-name request only. It does not require an ABI or
layout change. No request targets `include/resource_ids.h`,
`include/game_globals.h`, or another shared file. No resource mapping request
was submitted.

The unresolved source-name questions are the optimized locals listed above.
The original source spelling for those locals is not established by the PDB.

## Validation status

I reviewed the complete source diff and the report diff. I ran only permitted
source, evidence, hash, and Git diff review commands. I did not run a compiler,
build, matching check, audit, validation command, test, or game.

Compilation, matching, audits, and tests were not run. Generated code, program
data, relocations, and call targets remain unvalidated.
