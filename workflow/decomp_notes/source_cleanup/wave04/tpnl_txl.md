# Source cleanup: `src/tpnl_txl.cpp`

## Handoff

- Module: `src/tpnl_txl.cpp`
- Branch: `cleanup/staging-20260915-251`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source-cleanup commit: `9350ce7e589cf658334099f4c7681edd6e511df3`
- Changed files:
  - `src/tpnl_txl.cpp`
  - `workflow/decomp_notes/source_cleanup/wave04/tpnl_txl.md`

The final source-cleanup commit covers the source file. The report is committed separately.
The final report commit hash is returned in the handoff response.

## Scope and method

This work performed source cleanup only. It did not perform matching or behavior recovery.

I read the repository contract and all required source-cleanup, comment, resource-ID, owner, and testing guides.

I inspected the procedure-scoped PDB data in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_line_changes.csv`

I inspected the three function packets under:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/00520D70_TRIBE_Panel_Text_Line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/00520E30_set_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0052/00520ED0_draw.txt`

I also inspected the original Ghidra source and assembly evidence:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tpnl_txl.cpp.decomp`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tpnl_txl.cpp.asm`

The original executable and PDB have these hashes:

- `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`
  - SHA-256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
  - SHA-256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`

The matching copies under the pinned original XPack directory have the same hashes.

The preserved cleanup baseline is:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/tpnl_txl.obj`
  - SHA-256: `8ef40f47823972faf20677a92813c0f5e0a95ad3d69bec4f721a94da0f258a26`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  - SHA-256: `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`

## Original-name recovery

The PDB source path is `C:\msdev\work\age1_x1\tpnl_txl.cpp`.
All three normal source owners use the PDB module `.\\Release\\tpnl_txl.obj`.
The PDB records `this` in `ecx` for each owner.

### `00520D70` — `TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line`

The PDB records these parameters:

- `render_area_in`, `TDrawArea*`, stack offset `+0x4`.
- `parent_panel_in`, `TPanel*`, stack offset `+0x8`.
- `font_in`, `void*`, stack offset `+0xc`.

The source now uses all three recovered original spellings:

- `draw_area` became `render_area_in`.
- `parent` became `parent_panel_in`.
- `font_arg` became `font_in`.

The PDB records no function local or static for this owner.
The packet maps the owner to `tpnl_txl.cpp` lines 23-34.
The original body range is `00520D70-00520DF1`, with size 130 bytes.

### `00520E00` — generated scalar deleting destructor

This compiler-generated owner has no standalone source body.
The PDB records `this` in `ecx` and `__flags`, `unsigned int`, at stack offset `+0x4`.
The original FPO table records the same owner at RVA `00120E00`.
No source declaration changed.

### `00520E20` — generated destructor

This compiler-generated owner has no standalone source body.
The PDB records only `this` in `ecx`.
The original FPO table records the same owner at RVA `00120E20`.
No source declaration changed.

### `00520E30` — `TRIBE_Panel_Text_Line::set_info`

The PDB records these parameters:

- `text_type_in`, `unsigned char`, stack offset `+0x4`.
- `text_in`, `char*`, stack offset `+0x8`.
- `id_in`, `long`, stack offset `+0xc`.

The source now uses all three recovered original spellings:

- `type` became `text_type_in`.
- `str` became `text_in`.
- `new_id` became `id_in`.

The PDB records no function local or static for this owner.
The packet maps the owner to `tpnl_txl.cpp` lines 40-47.
The original body range is `00520E30-00520ECE`, with size 159 bytes.

### `00520ED0` — `TRIBE_Panel_Text_Line::draw`

The PDB records no explicit parameter, local, or static symbols.
It records only `this` in `ecx`.
The packet maps the owner to `tpnl_txl.cpp` lines 53-79.
The original body range is `00520ED0-00520FB8`, with size 233 bytes.

The source keeps the existing local `old_font`.
This local has no procedure-scoped PDB name.
Its role is inferred from the `SelectObject` return value and the later restore call.
I did not claim `old_font` as an original name.
I did not force a PDB name or change its scope, type, or storage.

No parameter or local mappings remain unresolved for the three normal source owners.
No source function was omitted from PDB review.

## Source changes

- Restored six parameter names from procedure-scoped PDB records.
- Applied 1TBS braces to `set_info` and `draw`.
- Joined the short `TextOutA` call onto one line.
- Removed empty comment lines.
- Removed an unsupported stale code-generation comment.
- Preserved source order, types, casts, explicit `this->` uses, calls, literals, and storage.
- Preserved the imported API declarations and the `s_tpnl_txl_draw` symbol.

The changed names are recovered original names.
No new descriptive parameter or local name was added.
The existing `old_font` name remains a descriptive source name, not a claimed original name.

## Constants, resources, and comments

No new constant or symbolic resource ID was added.
The existing `TPanel::RedrawNormal` symbol remains unchanged.
The existing numeric setup, state, and Win32 values remain unchanged.
The header size assertion remains unchanged.

I ran `python tools/inspect_pe_strings.py --help` before resource review.
This source has no string-table lookup, resource-ID argument, language DLL lookup, or resource fallback.
No relevant DLL exists for this module's cleanup.
No resource extraction was required.

The removed stale comment claimed that `set_redraw` lacked `ecx=this`.
The original packet shows `00520EC3` loading `ecx` from `ebp` before the virtual call.
The comment was therefore not reliable and was removed.
The other removed comment described register-save instructions.
It did not explain behavior to a source reader.
No new source comment was needed.

## Code-generation, type, layout, and symbol effects

Parameter-name changes do not change types, calling convention, layout, or linkage names.
Brace and line-wrap changes can change debug line records.
Comment removal can also change debug line records.
No executable statement, expression order, call target, literal, or data declaration changed.

The PDB uses source line records for the original lines.
The cleanup changes presentation and can move those records.
Compiler output, relocations, and direct-call target identity remain unvalidated.

## Header and shared-file requests

The header was read-only for this worker and was not changed.

Request to the group owner for `include/tpnl_txl.h`:

- Rename declaration-only parameters to `render_area_in`, `parent_panel_in`, and `font_in`.
- Rename declaration-only parameters to `text_type_in`, `text_in`, and `id_in`.

The PDB records these exact spellings at `00520D70` and `00520E30`.
This request changes names only.
It does not change the header types, order, layout, ABI, or symbols.

No shared resource-ID mapping request is needed.

## Unresolved questions

- `draw` has no PDB local name for `old_font`.
  The existing descriptive name remains because its declaration maps to the `SelectObject` result.
- The header declaration names still differ from the recovered definition names.
  The group owner should review the request above.
- No resource-ID purpose or resource text was present in this module.

No structural rewrite, helper extraction, bug repair, assembly change, layout change, or source-owner change was made.

## Validation status

Compilation, matching, audits, validation commands, tests, and games were **not run**.
I did not invoke a compiler, build command, matching check, audit, or test command.
I performed evidence inspection, resource-tool help inspection, Git diff review, and `git diff --check` only.
This report does not claim byte equality, semantic approval, or validation.
