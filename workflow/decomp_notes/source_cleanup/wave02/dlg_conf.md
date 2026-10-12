# Source cleanup report: `dlg_conf.cpp`

## Delivery

- Module: `src/dlg_conf.cpp`
- Base commit from `git rev-parse`: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Worker-local resource import provenance: `3caba12fa62d4d07a0626fcb9f77e3425b9181ff` (`include/resource_ids.h`)
- Root resource approval commit: `8c56055b7feee1526f296bd306036a4c34f38041`
- Final source commit from `git rev-parse`: `4bb1f30e5b844c4ea0c51cc29308ca22f2825333`
- Branch: `cleanup/staging-20260915-84`
- Changed files: `src/dlg_conf.cpp`; this report.
- Registry: `config/functions/src/dlg_conf.cpp.json`; build flags `gx`.
- Header owner: owner 10 owns `include/dlg_conf.h`. This worker did not edit it.

The cleanup covers all three handwritten procedures in the source registry:
`0043B560`, `0043C0C0`, and `0043C2B0`. The source registry marks the first
and second procedures `matching`. It marks the action procedure
`new_verified_logic`. The cleanup does not change those statuses.

The source changes recover procedure-scoped PDB names, substitute all approved
dialog resource macros, and apply 1TBS braces to the three definitions.
They do not change types, storage, declaration order, control flow, calls,
literal values, or ABI symbols.

## Evidence

Name evidence comes from the shared procedure-scoped PDB inventory:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- PDB source: `C:\\msdev\\work\\age1_x1\\dlg_conf.cpp`
- Module object: `.\\Release\\dlg_conf.obj`

I selected the procedures through
`config/functions/src/dlg_conf.cpp.json` and inspected every assigned packet:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043B560_TribeConfigDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043C0C0_TribeConfigDialog.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0043/0043C2B0_action.txt`

The packet records provide the original boundaries, source line bands, calls,
and assembly. The procedure-scoped PDB records provide the names, offsets,
types, and registers listed below.

The original executable remains the behavior oracle:

- Path: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
- SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`

Original procedure boundaries are:

- `0043B560-0043C09F`, constructor, 2,880 bytes, source lines 84-321.
- `0043C0C0-0043C2A4`, destructor, 485 bytes, source lines 326-371.
- `0043C2B0-0043C92A`, action, 1,659 bytes, source lines 377-647.

The PDB also records compiler-generated scalar deleting destructor
`0043C0A0`. It has no source body in this module and was not edited.

## Original-name recovery

The register record is `this` in `ecx` for each handwritten procedure. A name
already present in the source is listed as retained when the PDB confirms it.

| VA | Procedure | PDB stack records | Source result |
| --- | --- | --- | --- |
| `0043B560` | `TribeConfigDialog::TribeConfigDialog` | `m` `+0x4`, `Mode`; `parentPanel` `+0x8`, `TScreenPanel*`; `tabList` `-0x34`, `TPanel*[10]`; `string_id` `+0x8`, `long`; `val` `+0x8`, `unsigned char` | Renamed `mode` to recovered `m`; `parent` to recovered `parentPanel`; `tab_list` to recovered `tabList`; and `path_finding` to recovered `val`. The source `string_id` already matched. |
| `0043C0C0` | `TribeConfigDialog::~TribeConfigDialog` | none; register `this` only | No PDB source parameter or local name. Retained the existing inferred locals `text_panels`, `button_panels`, and `count`. |
| `0043C2B0` | `TribeConfigDialog::action` | `fromPanel` `+0x4`, `TPanel*`; `actionIn` `+0x8`, `long`; `a1` `+0xc`, `unsigned long`; `a2` `+0x10`, `unsigned long`; `new_speed` `-0x104`, `float`; `msg` `-0x100`, `char[256]` | Renamed `panel` to recovered `fromPanel`; `event` to recovered `actionIn`; `param_3` to recovered `a1`; and `param_4` to recovered `a2`. The source `new_speed` and `msg` already matched. |

The compiler-generated scalar deleting destructor `0043C0A0` has PDB stack
record `__flags` `+0x4`, `unsigned int`, and register `this` in `ecx`. It has no
handwritten declaration or source body here. No rename was possible.

The constructor PDB has three names at stack offset `+0x8`: the parameter
`parentPanel`, local `string_id`, and local `val`. This is optimized stack-slot
reuse, not one source object. The source keeps the three declarations separate.
The `val` mapping has direct instruction and type evidence beyond the reused
home. In packet `0043B560_TribeConfigDialog.txt`, `0043BFC6` calls
`RGE_Base_Game::mpPathFinding`, and `0043BFCD` calls
`RGE_Base_Game::pathFinding`; both return `uchar` in `AL`. The original
instructions then compare `AL` at `0043BFD2`, store it as one byte at
`0043BFD4` (`MOV byte ptr [ESP + param_1],AL`), reload it at `0043BFDA`,
mask it with `AND EDX,0xff` at `0043BFDE`, and use it as the
`pathFindingButton` index at `0043BFE4` before
`TButtonPanel::set_radio_button` at `0043BFEB`. The scoped PDB record names
that declaration `val` and gives it type `T_UCHAR(0020)`, `unsigned char`.
This byte store, byte-producing calls, narrow mask, and indexed use prove the
declaration mapping. No declaration, type, scope, or storage mapping was
changed.

The constructor's other existing locals are `i`, `y`, `speed`,
`music_system`, `sound_system`, `screen_width`, and `cancel_button`. The scoped
PDB record has no names for them. I retained those inferred names and did not
claim that they are original names. The destructor's loop locals are also
inferred names because its scoped PDB record has no local entries.

## Constants and resource evidence

The source now includes `include/resource_ids.h` and uses the existing reviewed
macros `STRING_ID_BUTTON_OK` and `STRING_ID_BUTTON_CANCEL` for numeric IDs `0x0FA1` and
`0x0FA2`. The macros expand to the same integer literals. Their runtime text
is `OK` and `Cancel`.

The source keeps `STRING_ID_PATH_FINDING_OPTION_BASE + i` for the contiguous path
finding range. It does not use separate names for the `Medium` or `High`
entries. The following table records the numeric ID, exact text, file hash,
language, lookup path, purpose, and approved cleanup name or expression. The
text uses `\\n` for the embedded newline in the resource payload.

The primary extraction is:

- File: `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
- SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`
- Resource type: `RT_STRING`
- Language: `0x0409` / `1033`
- Evidence output: `build/dlg_conf_language_all.json`

`TRIBE_Game::get_string` first tries `StringTableX`, then calls
`RGE_Base_Game::get_string`. `src/tribegam.cpp` records this fallback at lines
812-818. The `create_text` and `create_button` packet evidence shows that these
dialog calls pass IDs through `TPanel::get_string`. The targeted extraction of
the current expansion input `runtime/languagex.dll` has no matching entry for
any requested ID. This targeted result does not prove that the DLL has no other
string slots:

- SHA256: `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`
- Evidence output: `build/dlg_conf_languagex.json`
- Result: every requested ID is missing from this extraction. Other string
  slots were not part of this requested-ID result.

The pinned original expansion file also has no matching entries in its full
string listing:

- File: `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
- SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`
- Evidence output: `build/dlg_conf_original_languagex_list.json`
- Result for every requested ID: missing from the `RT_STRING` listing.

Thus, the current runtime lookup falls back to `runtime/language.dll` for these
English strings. The root owner must keep the expansion override and fallback
behavior when adding names.

Every row below uses this source-evidence tuple: file
`runtime/language.dll`, SHA256
`3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, and
language `0x0409` / `1033`.

| ID | Exact text in `runtime/language.dll` | File SHA256 and language | Lookup path | Purpose | Approved cleanup name or expression |
| --- | --- | --- | --- | --- | --- |
| `0x24D7` | `Game Settings` | as above | `create_text` -> `TRIBE_Game::get_string` | Configuration dialog title | `STRING_ID_GAME_SETTINGS_TITLE` |
| `0x24D8` | `Normal` | as above | `create_text` -> `TRIBE_Game::get_string` | Normal game-speed option | `STRING_ID_GAME_SPEED_NORMAL` |
| `0x24D9` | `Fast` | as above | `create_text` -> `TRIBE_Game::get_string` | Fast game-speed option | `STRING_ID_GAME_SPEED_FAST` |
| `0x24DA` | `Very Fast` | as above | `create_text` -> `TRIBE_Game::get_string` | Very-fast game-speed option | `STRING_ID_GAME_SPEED_VERY_FAST` |
| `0x24DB` | `Music\\nVolume` | as above | `create_text` -> `TRIBE_Game::get_string` | Music volume group title | `STRING_ID_MUSIC_VOLUME_TITLE` |
| `0x24DC` | `High` | as above | `create_text` -> `TRIBE_Game::get_string` | High setting for music and sound controls | `STRING_ID_AUDIO_VOLUME_HIGH` |
| `0x24DD` | `Off` | as above | `create_text` -> `TRIBE_Game::get_string` | Off setting for music and sound controls | `STRING_ID_AUDIO_VOLUME_OFF` |
| `0x24DE` | `Sound\\nVolume` | as above | `create_text` -> `TRIBE_Game::get_string` | Sound volume group title | `STRING_ID_SOUND_VOLUME_TITLE` |
| `0x24DF` | `Speed` | as above | `create_text` -> `TRIBE_Game::get_string` | Game-speed group title | `STRING_ID_GAME_SPEED_TITLE` |
| `0x24E0` | `Screen Size` | as above | `create_text` -> `TRIBE_Game::get_string` | Screen-size group title | `STRING_ID_SCREEN_SIZE_TITLE` |
| `0x24E7` | `640 x 480` | as above | `create_text` -> `TRIBE_Game::get_string` | 640-by-480 screen-size option | `STRING_ID_SCREEN_SIZE_640X480` |
| `0x24E8` | `800 x 600` | as above | `create_text` -> `TRIBE_Game::get_string` | 800-by-600 screen-size option | `STRING_ID_SCREEN_SIZE_800X600` |
| `0x24E9` | `1024 x 768` | as above | `create_text` -> `TRIBE_Game::get_string` | 1024-by-768 screen-size option | `STRING_ID_SCREEN_SIZE_1024X768` |
| `0x24EA` | `Mouse Interface` | as above | `create_text` -> `TRIBE_Game::get_string` | Mouse-interface group title | `STRING_ID_MOUSE_INTERFACE_TITLE` |
| `0x24EB` | `Two Buttons` | as above | `create_text` -> `TRIBE_Game::get_string` | Two-button mouse option | `STRING_ID_MOUSE_INTERFACE_TWO_BUTTONS` |
| `0x24EC` | `One Button` | as above | `create_text` -> `TRIBE_Game::get_string` | One-button mouse option | `STRING_ID_MOUSE_INTERFACE_ONE_BUTTON` |
| `0x24ED` | `Roll-over Help` | as above | `create_text` -> `TRIBE_Game::get_string` | Rollover-help group title | `STRING_ID_ROLLOVER_HELP_TITLE` |
| `0x24EE` | `On` | as above | `create_text` -> `TRIBE_Game::get_string` | Rollover-help enabled option | `STRING_ID_ROLLOVER_HELP_ON` |
| `0x24EF` | `Off` | as above | `create_text` -> `TRIBE_Game::get_string` | Rollover-help disabled option | `STRING_ID_ROLLOVER_HELP_OFF` |
| `0x24F0` | `Scroll\\nSpeed` | as above | `create_text` -> `TRIBE_Game::get_string` | Scroll-speed group title | `STRING_ID_SCROLL_SPEED_TITLE` |
| `0x24F1` | `Fast` | as above | `create_text` -> `TRIBE_Game::get_string` | Fast scroll-speed option | `STRING_ID_SCROLL_SPEED_FAST` |
| `0x24F2` | `Slow` | as above | `create_text` -> `TRIBE_Game::get_string` | Slow scroll-speed option | `STRING_ID_SCROLL_SPEED_SLOW` |
| `0x260D` | `Path Finding` | as above | `create_text` -> `TRIBE_Game::get_string` | Path-finding group title | `STRING_ID_PATH_FINDING_TITLE` |
| `0x260E` | `Default` | as above | `create_text` -> `TRIBE_Game::get_string` | First entry in the contiguous path-finding range | `STRING_ID_PATH_FINDING_OPTION_BASE` |
| `0x260F` | `Medium` | as above | `create_text` -> `TRIBE_Game::get_string` | Second entry in the contiguous path-finding range | `STRING_ID_PATH_FINDING_OPTION_BASE + 1` |
| `0x2610` | `High` | as above | `create_text` -> `TRIBE_Game::get_string` | Third entry in the contiguous path-finding range | `STRING_ID_PATH_FINDING_OPTION_BASE + 2` |
| `0x0BF3` | `Game speed changed.` | as above | `get_string` -> `TRIBE_Game::get_string` | Multiplayer game-speed notification text | `STRING_ID_GAME_SPEED_CHANGED` |

The source preserves the contiguous expression
`STRING_ID_PATH_FINDING_OPTION_BASE + i`. The approved base name records the range
owner. Separate `Medium` and `High` macros are omitted. They are not used or
requested. The expression must not expand into a switch or table.

No new resource macro was defined in this worker. The approved names are
cleanup names, not recovered original macro names. PDB records do not recover
preprocessor macro names.

No unexplained numeric API, file, or format constant was replaced. No source
comment was added. The existing comment about the three fixed `.rdata` float
literals remains because it records an evidence-backed compiler data detail.

## Recovered and invented names

Recovered original spellings from the PDB are:

- `m`
- `parentPanel`
- `tabList`
- `string_id`
- `val`
- `fromPanel`
- `actionIn`
- `a1`
- `a2`
- `new_speed`
- `msg`
- `this`

The source already used `string_id`, `new_speed`, and `msg`. The other recovered
names replace readable or generated substitutes. The approved `STRING_ID_*` names
come from the root resource approval commit
`8c56055b7feee1526f296bd306036a4c34f38041`. They are cleanup names, not
recovered original macro names. The worker-local import commit records
provenance only.

Existing inferred names retained without original-name evidence are `i`, `y`,
`speed`, `music_system`, `sound_system`, `screen_width`, `cancel_button`,
`text_panels`, `button_panels`, and `count`. They remain separate declarations.

## Code-generation concerns and review

The source edits rename parameters and locals. They do not change parameter or
local types, declaration scope, storage duration, initialization points,
expression order, casts, calls, control flow, layouts, function boundaries,
virtual slots, relocations, or ABI symbols. The explicit `this->` expressions
remain unchanged.

The approved resource macro replacements preserve the original integer values
and types. The include uses only reviewed preprocessor definitions. Brace
changes apply 1TBS without adding or removing scopes. The `val` rename
preserves the existing `unsigned char` declaration and its narrow comparison.

No helper, wrapper, structural rewrite, layout change, assembly, or generated
inventory change was made. I reviewed the complete source diff against the
base commit and ran `git diff --check`.

## Header and shared-file requests

Owner 10 has no declaration request for `include/dlg_conf.h`. Its declarations
are unnamed, and the definition uses the recovered PDB parameter spellings
without changing the public interface.

The approved definitions are present in `include/resource_ids.h` from root
approval commit `8c56055b7feee1526f296bd306036a4c34f38041`. The worker-local
import commit `3caba12fa62d4d07a0626fcb9f77e3425b9181ff` records local
provenance only. The source uses all approved `dlg_conf` macros. The existing
`STRING_ID_BUTTON_OK` and `STRING_ID_BUTTON_CANCEL` definitions cover `0x0FA1` and
`0x0FA2`. No separate `Medium` or `High` path finding macro is requested.

No other shared request is open. No header was edited in this commit sequence.

## Validation

Compilation, matching, audits, and tests were not run. No build, compiler
check, game, or runtime harness was run. Only PDB, source-registry, function
packet, resource, and Git diff evidence review was run.
