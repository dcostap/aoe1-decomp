# Source cleanup report: `tpnl_inv.cpp`

## Delivery

- Module: `src/tpnl_inv.cpp`
- Branch: `cleanup/staging-20260915-168`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `88cf53624dc23936c7f1ab13521a7132a9156591`
- Report commit: separate commit after the source commit
- Changed files:
  - `src/tpnl_inv.cpp`
  - `decomp_notes/source_cleanup/wave03/tpnl_inv.md`
- Header owner: owner 19 owns `include/tpnl_inv.h`. I did not edit it.

The source keeps the eight normal functions in PDB source order. It also keeps
all existing calls, expressions, types, storage, scopes, literals, and data.
The cleanup restores PDB parameter names and one SDK constant name.

## Scope and evidence

I inspected the complete source-cleanup, source-comment, resource-ID, owner,
assignment, and testing guides. I read the pinned VC5 headers before changing
the SDK literal.

The source registry is:

- `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tpnl_inv.cpp.json`
- PDB source path: `C:\msdev\work\age1_x1\tpnl_inv.cpp`
- Build flags: `config/flags/gx_no_fpo.rsp` (`/nologo /c /O2 /GX`)

The original PDB evidence is:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
- SHA-256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- Scoped index: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- Scoped index SHA-256: `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`

I inspected each registry-selected packet. The packets are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051A5C0_TRIBE_Panel_Inven.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051A6B0_set_text_color.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051A6D0_TRIBE_Panel_Inven.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051A770_draw.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051AAD0_handle_idle.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051ABF0_set_player.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051AC10_save_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051ACA0_get_help_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051A690_scalar_deleting_destructor.txt`

The original executable remains the behavior oracle:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`
- SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

The preserved pre-cleanup evidence is:

- Build report: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`
- Baseline object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tpnl_inv.obj`
- Baseline object SHA-256: `f50c6d869528b5ffbae9fa4901d306d7c31fdb0ed00f8adcece3b2b9ffd9de65`
- Baseline executable: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
- Baseline executable SHA-256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Systematic PDB coverage

All eight registry functions have one procedure-scoped PDB record. Each record
has an empty `function_statics` list and a `this` register in `ecx`.
The table lists every stack and register record.

| VA | Function | PDB source span | Stack symbols | Register symbols |
| --- | --- | --- | --- | --- |
| `0051A5C0` | `TRIBE_Panel_Inven` | `33-61` | `render_area_in` `+0x4` `TDrawArea*`; `parent_panel_in` `+0x8` `TPanel*`; `font_in` `+0xC` `void*`; `player_in` `+0x10` `TRIBE_Player*` | `this` in `ecx` |
| `0051A6B0` | `set_text_color` | `67-71` | `font_color_in` `+0x4` `unsigned long`; `back_color_in` `+0x8` `unsigned long` | `this` in `ecx` |
| `0051A6D0` | `~TRIBE_Panel_Inven` | `77-91` | none | `this` in `ecx` |
| `0051A770` | `draw` | `97-158` | `old_font` `-0x1C` `void*`; `x` `-0x24` `long`; `str` `-0x14` `char[20]` | `this` in `ecx` |
| `0051AAD0` | `handle_idle` | `164-198` | `changed` `-0x8` `int` | `this` in `ecx` |
| `0051ABF0` | `set_player` | `204-208` | `player_in` `+0x4` `TRIBE_Player*` | `this` in `ecx` |
| `0051AC10` | `save_info` | `214-230` | none | `this` in `ecx` |
| `0051ACA0` | `get_help_info` | `236-265` | `string` `+0x4` `char*&`; `page` `+0x8` `long&`; `x` `+0xC` `long`; `y` `+0x10` `long` | `this` in `ecx` |

The generated scalar deleting destructor at `0051A690` has a separate packet
and scoped PDB record. It has `__flags` at `+0x4` as `unsigned int` and `this`
in `ecx`. It has no PDB source span or standalone source body. The registry
selects the eight normal functions only.

## Original-name recovery

The names below are recovered original spellings from the procedure-scoped PDB.
They are not new descriptive names.

- `0051A5C0`: `area` became `render_area_in`; `parent` became
  `parent_panel_in`; `font_` became `font_in`; and `player_` became `player_in`.
- `0051A6B0`: `color1` became `font_color_in`; `color2` became
  `back_color_in`.
- `0051ABF0`: `player` became `player_in`.
- `0051ACA0`: `out_str` became `string`; `out_val` became `page`.
  `x` and `y` already match the PDB.

The `draw` PDB names `old_font`, `x`, and `str` already match the source.
The `handle_idle` PDB name `changed` already matches the source.
The destructor and `save_info` records have no stack names.

The PDB does not name the source local `y` in `draw`. It also does not name
`mode`, `now`, `i`, `saved`, or `values` in `handle_idle`, or `i` in
`save_info`. These names remain unchanged. They are existing descriptive names,
not recovered PDB names. I did not force a mapping from an optimized or reused
stack slot. The unnamed compiler EH locals in the constructor and destructor
also remain unclaimed.

## Constants and resource IDs

I replaced `SetBkMode(this->render_area->DrawDc, 1)` with
`SetBkMode(this->render_area->DrawDc, TRANSPARENT)`. The pinned VC5 SDK defines
`TRANSPARENT` as `1` in:

- `C:/Program Files (x86)/DevStudio/VC/Include/WINGDI.H`, line 1302

This keeps the original value and effective integer type. No new constant was
created. Existing `TPanel::RedrawNone` and `TPanel::RedrawNormal` names remain.
Other numeric values remain unchanged because no shared symbol has a proved
matching role.

The four IDs in `get_help_info` are resource lookup IDs. Root owns
`include/resource_ids.h`, so I did not define macros. The source keeps the
numeric IDs until root reviews the requests below.

The lookup path is established by these source owners:

- `C:/Projects/my_decomps/aoe1_attempt3/src/Panel.cpp`: `TPanel::get_string`
  calls `rge_base_game->get_string`.
- `C:/Projects/my_decomps/aoe1_attempt3/src/tribegam.cpp`:
  `TRIBE_Game::get_string` checks `StringTableX` first and then falls back to
  `RGE_Base_Game::get_string`.
- `C:/Projects/my_decomps/aoe1_attempt3/src/basegame.cpp`:
  `RGE_Base_Game::get_string` reads `StringTable` with `LoadStringA` and clears
  the destination buffer on a miss.

I ran `tools/inspect_pe_strings.py --help` before extraction. I checked each
ID with `--language 0x0409`. The extraction files are under this worker build
folder:

- `build/resource-strings/tpnl_inv-language.json`
- `build/resource-strings/tpnl_inv-languagex.json`
- `build/resource-strings/tpnl_inv-original-languagex.json`

Each checked file uses resource type `RT_STRING`. Every ID below is missing.
A missing ID has no returned language or text record. This is not an empty slot.

| ID | Proposed cleanup name | Proven purpose | Base runtime result | Runtime expansion result | Pinned XPack expansion result |
| --- | --- | --- | --- | --- | --- |
| `0x1D4ED` | `IDS_HELP_FOOD` | Help format for `attributes[0]`, the food field | Missing; no text | Missing; no text | Missing; no text |
| `0x1D4EE` | `IDS_HELP_WOOD` | Help format for `attributes[1]`, the wood field | Missing; no text | Missing; no text | Missing; no text |
| `0x1D4EF` | `IDS_HELP_GOLD` | Help format for `attributes[3]`, the gold field | Missing; no text | Missing; no text | Missing; no text |
| `0x1D4F0` | `IDS_HELP_STONE` | Help format for `attributes[2]`, the stone field | Missing; no text | Missing; no text | Missing; no text |

Resource file provenance and hashes:

- Base runtime: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
  Checked language `0x0409`.
- Runtime expansion: `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.
  Checked language `0x0409`; all four IDs are missing.
- Pinned original expansion: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
  Checked language `0x0409`; all four IDs are missing.

The proposed names are new cleanup names. No original macro spelling is known.
The purpose is proven by the four hit bands in the original packet and by the
resource indices in `src/tplayer.cpp`. The text remains unknown.

## Comments and unusual behavior

I added no comment. The existing destructor comment is useful. The original
packet shows two calls to `TPanel::~TPanel`; the source keeps both calls.
The source also keeps the original narrow `short` snapshot values and the
`(short)(int)` conversion. No behavior repair was made.

## Code generation, type, layout, and symbol review

The source changes only parameter names, local identifier uses, one SDK macro
that expands to the same integer literal, and brace or signature formatting.
It does not change any public function name, decorated symbol, ABI type, call
target, cast, declaration scope, storage, member layout, statement order,
control flow, literal value, string, function boundary, or relocation source.
The `TRANSPARENT` macro keeps the original `1` value and type. Generated code,
program data, relocations, and call targets remain unvalidated.

## Header requests and unresolved questions

I did not edit `include/tpnl_inv.h`. Owner 19 may add these PDB-backed parameter
names without changing types or ABI:

```cpp
TRIBE_Panel_Inven(TDrawArea* render_area_in, TPanel* parent_panel_in,
                 void* font_in, TRIBE_Player* player_in);
void set_text_color(unsigned long font_color_in, unsigned long back_color_in);
virtual unsigned char get_help_info(char*& string, long& page, long x, long y);
void set_player(TRIBE_Player* player_in);
```

Root owns `include/resource_ids.h`. Please review these four new shared
resource mappings:

- `0x1D4ED` -> `IDS_HELP_FOOD`
- `0x1D4EE` -> `IDS_HELP_WOOD`
- `0x1D4EF` -> `IDS_HELP_GOLD`
- `0x1D4F0` -> `IDS_HELP_STONE`

The source does not apply these names until root provides the shared macros.
No other header request is open. The resource text is missing in all three
checked DLLs. The purpose remains established; the exact historical text does
not.

## Validation

I ran evidence extraction, resource hash checks, and a complete Git diff review.
I ran `git diff --check`.

Compilation, matching, audits, and tests were not run. I also did not run a
build, compiler check, game, or runtime harness.
