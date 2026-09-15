# `tpnl_pop.cpp` cleanup report

## Module and commits

- Module: `src/tpnl_pop.cpp`
- Registry: `config/functions/src/tpnl_pop.cpp.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\tpnl_pop.cpp`
- Build flags: `config/flags/gx.rsp`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final module commit: `0371f2d3521df1cc4c835dfc526b099694686695`
- The report is a follow-up report-only commit after the module commit.
- Changed files:
  - `src/tpnl_pop.cpp`
  - `decomp_notes/source_cleanup/wave03/tpnl_pop.md`
- Read-only header: `include/tpnl_pop.h`

The registry selects nine source owners. Eight have `matching` status. The
protected `render_to_image_buffer` owner at `0051D4F0` has
`new_verified_logic` status. No registry status changed. The scalar deleting
destructor at `0051CD90` is compiler-generated and has no source owner.

## Original-name recovery coverage

I inspected procedure-scoped parameters, locals, and registers for every
assigned source owner in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The PDB records `this` in `ecx` for every procedure below. The PDB module path
is `.\\Release\\tpnl_pop.obj`.

| VA | Owner | PDB span and size | PDB parameters and locals | Registers |
| --- | --- | --- | --- | --- |
| `0051CCA0` | `TRIBE_Panel_Pop` | lines 32-57; 232 bytes | `render_area_in` `+0x4`, `TDrawArea*`; `parent_in` `+0x8`, `TPanel*` | `this` in `ecx` |
| `0051CD90` | scalar deleting destructor | no source span; 30 bytes | `__flags` `+0x4`, `unsigned int` | `this` in `ecx` |
| `0051CDB0` | `~TRIBE_Panel_Pop` | lines 64-78; 139 bytes | none recorded | `this` in `ecx` |
| `0051CE40` | `set_rect` | lines 85-129; 389 bytes | `x_in`, `y_in`, `wid_in`, `hgt_in`, all `long` at `+0x4`, `+0x8`, `+0xC`, `+0x10` | `this` in `ecx` |
| `0051CFD0` | `startup` | lines 135-142; 107 bytes | none recorded | `this` in `ecx` |
| `0051D040` | `get_player_id` | lines 148-153; 18 bytes | none recorded | `this` in `ecx` |
| `0051D060` | `draw` | lines 159-293; 1033 bytes | `str` `-0x100`, `char[256]`; `old_font` `-0x104`, `void*`; `rect` `-0x120`, `tagRECT`; `changed_mode` `-0x12D`, `unsigned char` | `this` in `ecx` |
| `0051D470` | `get_true_render_rect` | lines 299-307; 101 bytes | `drawRect` `+0x4`, `tagRECT&` | `this` in `ecx` |
| `0051D4E0` | `handle_idle` | lines 313-328; 8 bytes | none recorded | `this` in `ecx` |
| `0051D4F0` | `render_to_image_buffer` | lines 334-412; 668 bytes | `str` `-0x100`, `char[256]`; `old_font` `-0x104`, `void*`; `rect` `-0x114`, `tagRECT` | `this` in `ecx` |

The PDB has no function statics for these procedures. It has no named source
local for the constructor font, the startup player or population limit, either
`buf` temporary, or the descriptive locals in `draw`. I did not force a name
from reused or optimized storage.

Recovered source names are:

- Constructor `area` became the PDB name `render_area_in`.
- Constructor `parent` became the PDB name `parent_in`.
- `set_rect` parameters `param_1` through `param_4` became the PDB names
  `x_in`, `y_in`, `wid_in`, and `hgt_in`.
- `get_true_render_rect` parameter `rect` became the PDB spelling `drawRect`.
- Existing `draw` locals `str`, `old_font`, `rect`, and `changed_mode` already
  match the PDB records.
- Existing `render_to_image_buffer` locals `str`, `old_font`, and `rect`
  already match the PDB records.

The unnamed local spellings `f`, `p`, and `limit` remain unchanged. Terse
spelling alone does not prove a generated name. Existing locals without PDB
records remain unchanged. No public function, class, member, global, ABI
symbol, source order, declaration scope, storage, or type changed.

## Constants and source changes

The source now uses the pinned VC5 SDK symbols for the drawing calls:

- `SetBkMode` uses `TRANSPARENT` instead of `1`. The pinned
  `C:/Program Files (x86)/DevStudio/VC/Include/WINGDI.H` defines
  `TRANSPARENT` as `1` at line 1302.
- All ten `DrawTextA` calls use `DT_CENTER | DT_SINGLELINE` instead of
  `0x21`. The pinned
  `C:/Program Files (x86)/DevStudio/VC/Include/WINUSER.H` defines
  `DT_CENTER` as `0x00000001` and `DT_SINGLELINE` as `0x00000020` at lines
  4880 and 4885. Their bitwise OR is the original `0x21` integer value.

These replacements preserve the argument value and its conversion to the
`UINT` flag parameter. No helper, layout, cast, call target, evaluation order,
control flow, or behavior repair was added. No source comment was added. The
existing `tpnl_tim` debug strings remain unchanged because the original
packets show those literal values.

## Resource ID investigation and request

The source investigates resource ID `0x2B2A` (decimal `11050`). Its call sites
format `"%s%ld/%ld"` with the returned text and the current and maximum
population values. This proves the purpose as a population label prefix. I
propose the new cleanup name `IDS_POPULATION_PREFIX`. This is not an original
macro name.

`TPanel::get_string(int)` calls the virtual buffer lookup. The expansion
`TRIBE_Game::get_string` path calls `LoadStringA(StringTableX, ...)` first and
then falls back to `RGE_Base_Game::get_string`, which reads the base string
module. The checked resource results are:

| DLL and full SHA256 | Language | ID result | Lookup role |
| --- | --- | --- | --- |
| `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll` (`4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`) | `0x0409` / 1033 | `RT_STRING`, block 691, slot 10, exact text `pop: `, UTF-16 length 5 | First expansion lookup; supplies the checked runtime text |
| `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll` (`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`) | no matching language record | `RT_STRING` ID missing; no empty slot record | Base fallback; not reached for this ID in the checked runtime |
| `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll` (`a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`) | `0x0409` / 1033 | `RT_STRING`, block 691, slot 10, exact text `pop: `, UTF-16 length 5 | Pinned original XPack expansion reference |

Extraction outputs are in the worker build directory:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-170/build/resource-strings/tpnl_pop-language-20260915.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-170/build/resource-strings/tpnl_pop-languagex-20260915.json`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-170/build/resource-strings/tpnl_pop-xpack-languagex-20260915.json`

Header requests:

- Root owns `include/resource_ids.h`. Add one shared logical game-string
  namespace mapping: `#define IDS_POPULATION_PREFIX 0x2B2A`. The lookup checks
  the expansion string table first and uses the base table as fallback.
- Owner 19 owns `include/tpnl_pop.h`. Preserve these recovered declaration
  parameter names:
  - `TRIBE_Panel_Pop(TDrawArea* render_area_in, TPanel* parent_in);`
  - `virtual void set_rect(long x_in, long y_in, long wid_in, long hgt_in);`
  - `virtual void get_true_render_rect(tagRECT& drawRect);`
- The source keeps the numeric ID until the shared mapping is reviewed. No
  competing macro or local resource definition was added.

## Supporting evidence

The assigned registry file is
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tpnl_pop.cpp.json`.
The original scoped-PDB inventory SHA256 is
`adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
The registry-selected original packets and hashes are:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051CCA0_TRIBE_Panel_Pop.txt` — `142e7d5a1a9696ac071635d60d2ec50dd8ddde043d192f38e2e3c4bec9cc6d3b`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051CD90_scalar_deleting_destructor.txt` — `59a8b857bd0d01d4971bd225f7db198e8223a7813ced58c5ec4bcf71a19ea2dc`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051CDB0_TRIBE_Panel_Pop.txt` — `076824cedba6d5215327ff02eb1e6616abc5825fe94952f9e3b069e06285d9eb`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051CE40_set_rect.txt` — `d8eed37a533417a8cddaf29b799d21b1b7f2efce22533981f00dfc620d4aff92`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051CFD0_startup.txt` — `ff7cab9439239e0af39209d99b38c40bfbd46a84e92d1a281940587a0d54ca0e`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051D040_get_player_id.txt` — `cf45fdc0e732f7caa6aac78d691f018ad0e33e0c02c859b784990de5b2668f3f`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051D060_draw.txt` — `b33be0d87bcbd440e5df9ab65840de92294b60da07c4ccddff6d3b54146c478e`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051D470_get_true_render_rect.txt` — `4373c01f1defc84d17fa7555dc8dee00648fd53a3628068f18d309412c75be3e`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051D4E0_handle_idle.txt` — `30fdfe66dee33a818f9123182cb2cb647b0dca6601e21bcd17c930618e77d1d5`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0051/0051D4F0_render_to_image_buffer.txt` — `5ab76cdba605f52535055f4c25289e5abbf0056bc77b50478427fa236870a8fd`

The original executable reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`,
SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tpnl_pop.obj`,
SHA256 `94af6d0b793b142407c0e0f34992656f03fa0ccfe73c6b3cb4ad128afff65ec4`.

## Validation limits

I reviewed the complete source diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime command was run.
