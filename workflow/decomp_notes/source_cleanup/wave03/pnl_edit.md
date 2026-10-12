# Source cleanup: `src/pnl_edit.cpp`

## Handoff

- Module: `src/pnl_edit.cpp`
- Branch: `cleanup/staging-20260915-150`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source-cleanup commit: `c358332aabaf6221c74ae2c8c054c0ac1111a878`
- Changed files:
  - `src/pnl_edit.cpp`
  - `workflow/decomp_notes/source_cleanup/wave03/pnl_edit.md`

The source commit contains only the assigned source file. This report is a
separate assigned-file commit.

## Scope and evidence

I read `AGENTS.md`, the complete source-cleanup, source-comment, resource-ID,
owner, testing, and wave assignment guides. I read `include/pnl_edit.h` and
did not edit it.

I inspected the registry at
`C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/pnl_edit.cpp.json`.
I inspected every registry-selected packet under
`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/`.
I inspected every procedure-scoped record for these VAs in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The packet and PDB source path is `C:\msdev\work\age1_x1\pnl_edit.cpp`.

All member procedures have a PDB `this` record in `ecx`. The file-local
`00475930` callback has no register record. The registry statuses are from the
selected registry file. No status was changed.

Evidence fingerprints inspected:

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`
  SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved baseline executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/executable/ai-rng-filename-repair/20260915T083203564911Z/empiresx.exe`
  SHA-256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- Preserved baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/executable/ai-rng-filename-repair/20260915T083203564911Z/pnl_edit.obj`
  SHA-256 `22e4420de154b4a650d175e15c3d58ac3c35ba887a8d9f02fc0dfe4fdaed19c0`.
- Baseline resource file:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/original.res`
  SHA-256 `edd8f671b15254db0be049b421947cda59bbffdeb46a1d4c93176e42bfe9ee3a`.
- Pinned expansion resource:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`
  SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.
- Staged base-language runtime:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/language.dll`
  SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
- Staged expansion-language runtime:
  `C:/Projects/my_decomps/aoe1_attempt3/runtime/languagex.dll`
  SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`.

The baseline build report is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`.
No source or build artifact outside the assigned files was changed.

## PDB recovery coverage

The following table covers every normal VA in the registry. Packet names are
the selected files under the absolute inventory path above. `this@ecx` applies
to each member row. The callback has no register record.

| VA | Registry status | Selected packet | PDB stack parameters and locals | Source result |
| --- | --- | --- | --- | --- |
| `004755C0` | `matching` | `004755C0_TEditPanel.txt` | None | No rename. |
| `00475690` | `matching` | `00475690_TEditPanel.txt` | None | No rename. |
| `00475770` | `matching` | `00475770_setup.txt` | Parameters: `render_area_in`, `parent_panel_in`, `x_in`, `y_in`, `wid_in`, `hgt_in`, `font_in`, `fixed_len_in`, `text_in`, `format_in`, `auto_sel_in`. | Restored all eleven exact PDB parameter names from `param_1` through `param_11`. |
| `00475930` | `matching` | `00475930_pnl_sub_wnd_proc.txt` | Parameters: `wnd`, `msg`, `wparam`, `lparam`. | Restored the callback's exact lowercase PDB names. |
| `00475970` | `matching` | `00475970_set_text.txt` | Parameter: `text_in`. | Restored `text_in` from `text`. |
| `00475A30` | `matching` | `00475A30_update_text.txt` | Locals: `start`, `end`. | Both names already matched. |
| `00475AF0` | `matching` | `00475AF0_get_text.txt` | None | No rename. |
| `00475B00` | `matching` | `00475B00_get_input_buffer.txt` | None | No rename. |
| `00475B10` | `matching` | `00475B10_currentLine.txt` | None | No rename. |
| `00475B20` | `matching` | `00475B20_set_active.txt` | Parameter: `activ_in`. | Restored `activ_in` from `active`. |
| `00475B60` | `matching` | `00475B60_set_focus.txt` | Parameter: `have_focus_in`. | Restored `have_focus_in` from `focus`. |
| `00475CC0` | `matching` | `00475CC0_set_rect.txt` | Parameters: `x_in`, `y_in`, `wid_in`, `hgt_in`. | Restored all four exact PDB names from `param_1` through `param_4`. |
| `00475DD0` | `matching` | `00475DD0_set_redraw.txt` | Parameter: `redraw_mode`. | Restored `redraw_mode` from `mode`. |
| `00475E10` | `matching` | `00475E10_set_text_color.txt` | Parameters: `val1`, `val2`. | Restored both exact PDB names from `a` and `b`. |
| `00475E30` | `matching` | `00475E30_set_highlight_text_color.txt` | Parameters: `val1`, `val2`. | Added both exact PDB names to the unnamed definition parameters. |
| `00475E40` | `matching` | `00475E40_set_back_color.txt` | Parameters: `brush_in`, `brush_color_in`, `color_in`. | Added all three exact PDB names to the unnamed definition parameters. |
| `00475E50` | `matching` | `00475E50_set_bevel_info.txt` | Parameters: `bevel_type_in`, `c1`, `c2`, `c3`, `c4`, `c5`, `c6`. | Restored `bevel_type_in` from `type`. The `c1` through `c6` names already matched. |
| `00475F20` | `matching` | `00475F20_set_ime_info.txt` | Parameters: `enable_ime_in`, `turn_ime_on_in`. | Restored both exact PDB names from `a` and `b`. |
| `00475F40` | `matching` | `00475F40_wnd_proc.txt` | Parameters: `hwnd`, `msg`, `wParam`, `lParam`. | Restored all four exact PDB names from `param_1` through `param_4`. |
| `00476040` | `new_verified_logic` | `00476040_sub_wnd_proc.txt` | Parameters: `hwnd`, `msg`, `wParam`, `lParam`. Locals: `check_sel`, `ctrl_key`, `new_end`, `old_end`, `rect`, `old_start`, `new_start`. | Restored the four parameter names and `check_sel`. Existing selection names and `rect` already matched. Reused-slot mappings remain unresolved. |
| `00476440` | `matching` | `00476440_verify_char.txt` | Parameter: `key`. | Restored `key` from `ch`. |
| `00476680` | `matching` | `00476680_draw.txt` | Locals: `temp_color`, `old_font`, `r`. | Restored `temp_color` from `color` and `r` from `rect`. `old_font` already matched. |
| `00476A50` | `matching` | `00476A50_paint.txt` | None | No rename. |
| `00476A60` | `matching` | `00476A60_is_blank.txt` | None | No rename. |
| `00476AB0` | `matching` | `00476AB0_get_trimmed_str.txt` | Parameters: `str`, `str_len`. Local: `temp_str`. | Restored `str` and `str_len` from `dst` and `maxlen`. `temp_str` already matched. |
| `00476BB0` | `matching` | `00476BB0_handle_reactivate.txt` | None | No rename. |
| `00476BE0` | `matching` | `00476BE0_handle_mouse_down.txt` | Parameters: `mouse_button_in`, `x`, `y`, `ctrl_key`, `shift_key`. | Restored `mouse_button_in` from `button`. Restored `ctrl_key` and `shift_key` from `flags` and `area`. `x` and `y` already matched. |

The PDB has no procedure-scoped stack record for several existing locals. I
kept those names because no original mapping is proved. These include `result`,
`style`, `text_buffer`, `old_focus`, `hwnd`, `context`, `redraw`, `bevel`,
`left`, `top`, `width`, `height`, `format`, `notification`, `alt_down`,
`control_down`, `shift_down`, `result`, `x`, `y`, `position`,
`validation_result`, `p`, `dc`, `base`, `p`, and `cur`.

The `00476040` PDB record places `ctrl_key` at `+0x10`, the same stack home as
`lParam`. It places `new_start` at `+0xc`, the same home as `wParam`. I did not
force either reused-slot record onto a different source declaration. The source
keeps `control_down` as an inferred name and keeps the existing `new_start`
declaration. The `00476680` records place `temp_color` and `old_font` at the
same `-0x18` home. The source keeps their separate declarations and scopes.

## Recovered and invented names

Recovered names come from the procedure-scoped PDB records listed above. I
preserved the original mixed spelling, including `activ_in`, `wParam`,
`lParam`, `val1`, `val2`, `c1` through `c6`, `currentLine`, and
`mouse_button_in`.

I changed `styleVal` to `style` and `textBuf` to `text_buffer`. These are new
cleanup names, not recovered PDB names. The source keeps existing inferred
names such as `alt_down`, `control_down`, `shift_down`, `notification`, and
`validation_result`. It does not claim those names as original source names.
No public function, class, member, global, or decorated symbol was renamed.

## Constants, resources, comments, and formatting

No numeric constant or enum was added, removed, or replaced. I checked the
pinned VC5 definitions in `WINUSER.H`, `WINGDI.H`, and `IMM.H` before retaining
opaque API values. The source keeps the original message values, style masks,
window offsets, stock-object index, IME values, redraw modes, and sentinels.
This preserves their effective types and limits code-generation risk.

No resource lookup or resource ID occurs in this module. The resource files
listed above were fingerprinted as provenance only. No string extraction was
needed. No resource mapping request is open. I did not edit
`include/resource_ids.h`.

No source comment was added. Existing source-span comments remain unchanged.
They identify the original PDB line bands. No `__LINE__` or other line-dependent
macro appears in this source.

Function definitions now use 1TBS braces. Short definitions and calls remain
on one line where practical. No statement moved, and no scope changed.

## Code-generation-sensitive points

- Parameter and local spelling changes do not change types, storage, scope, or ABI.
- Added names on unused parameters do not add operations or data.
- Brace and wrapping changes can alter PDB line records. They can affect debug
  metadata, but this was not validated.
- No cast, literal, string, expression, declaration order, call target, direct
  target, relocation, vtable surface, class layout, or public symbol changed.
- The source retains the two existing local `extern` declarations for
  `MouseCursorInChildContol` and `imc_retval`.
- The existing module note records the unresolved canonical publication of
  those globals. This cleanup does not change that state.

## Header and shared requests

No header edit is required. `include/pnl_edit.h` keeps its existing unnamed
parameter declarations. Definition parameter names can differ without an ABI
change. The owner should not add competing local declarations.

No shared resource-ID definition is requested. No `include/resource_ids.h` or
`include/game_globals.h` change is requested from this module.

## Unresolved questions

- The `00476040` PDB records for `ctrl_key` and `new_start` reuse parameter
  stack homes. Their source declarations remain unresolved by design.
- The `00476680` `temp_color` and `old_font` records reuse one stack home. The
  source keeps separate declarations and does not infer a merged object.
- The natural source form of the `00476040` switch and forwarding schedule
  remains a behavior-recovery question recorded by the existing module notes.
- No resource purpose question exists because this module performs no resource
  lookup.

## Validation status

I ran only evidence inspection, local-header inspection, SHA-256 fingerprinting,
Git diff review, and `git diff --check`.

Compilation, matching, audits, tests, and games were **not run**. I did not run
a compiler, build, matching check, audit, test, or game command. Generated code,
program data, relocations, call-target identity, and runtime behavior remain
unvalidated.
