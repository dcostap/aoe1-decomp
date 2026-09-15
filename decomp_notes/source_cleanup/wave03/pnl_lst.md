# `src/pnl_lst.cpp` cleanup report

## Delivery

- Module: `src/pnl_lst.cpp`
- Branch: `cleanup/staging-20260915-151`
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `be24585a0b8ea3828e55704f40b0af80fbd67917`
- Report commit: recorded in the delivery message after this report commit.
- Changed files:
  - `src/pnl_lst.cpp`
  - `decomp_notes/source_cleanup/wave03/pnl_lst.md`
- No header changed. `include/pnl_lst.h` was read only.

The base source SHA256 is `63c0c05e172367f9cd639784dc67ea6f20dd1ad5d6189c1e4be393b7bb0f2858`.
The final source SHA256 is `56b8ee94140ffac684c1460524ef96c41d1d5dfc40980cc2e476cac4c7735b9b`.
The base source hash matches `C:/Projects/my_decomps/aoe1_attempt3/src/pnl_lst.cpp`.

The preserved baseline object is:
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/pnl_lst.obj`
with SHA256 `d9c2e496688fcca5a7f687b4f603320e88b95d713024fc44d9e57c5d3dfaf919`.

## Scope and evidence

I read these project guides before editing:

- `docs/source_cleanup.md`
- `docs/source_comments.md`
- `docs/resource_ids.md`
- `docs/source_cleanup_owners.md`
- `docs/testing.md`
- `decomp_notes/source_cleanup/wave03_assignments.md`

I read `C:/Projects/my_decomps/aoe1_attempt3/include/pnl_lst.h` without editing it.
I used these source and binary evidence files:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004782A0_TListPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478330_TListPanel.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478340_set_auto_track.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478350_set_bevel_info.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004783F0_handle_idle.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004784A0_mouse_move_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478510_mouse_left_down_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478540_mouse_left_move_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478610_mouse_left_up_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478660_mouse_left_dbl_click_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/004786B0_item_at.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478700_goto_item.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478730_key_down_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478850_char_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478900_action.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478920_scroll_cur_line.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478BA0_draw.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478CD0_draw_highlight_bar.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478EE0_setDrawHighlightBar.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0047/00478EF0_set_focus.txt`
- `C:/Projects/my_decomps/aoe1_attempt3/decomp_notes/pnl_lst.md`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/pnl_lst.cpp.asm`
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/pnl_lst.cpp.decomp`

The original executable reference is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its recorded SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The packets above supplied the original bytes and source spans.
The PDB supplied procedure names, types, stack slots, and registers.

## PDB coverage

The registry selects 20 source functions in `config/functions/src/pnl_lst.cpp.json`.
I inspected each procedure record in `scoped_symbols.json` and each selected packet.
Every procedure has register `this` in `ecx` with type `TListPanel*`.
The PDB records no function statics for these procedures.

| VA | Function | PDB stack parameters | PDB locals | Change |
| --- | --- | --- | --- | --- |
| `004782A0` | `TListPanel::TListPanel` | none | none | unchanged |
| `00478330` | `TListPanel::~TListPanel` | none | none | unchanged |
| `00478340` | `set_auto_track` | `auto_track_in: int` | none | recovered parameter |
| `00478350` | `set_bevel_info` | `bevel_type_in, c1`–`c6: int` | none | recovered parameters |
| `004783F0` | `handle_idle` | none | none | unchanged |
| `004784A0` | `mouse_move_action` | `x, y: long`; `ctrl_key, shift_key: int` | none | recovered parameters |
| `00478510` | `mouse_left_down_action` | `x, y: long`; `ctrl_key, shift_key: int` | none | recovered parameters |
| `00478540` | `mouse_left_move_action` | `x, y: long`; `ctrl_key, shift_key: int` | none | recovered parameters |
| `00478610` | `mouse_left_up_action` | `x, y: long`; `ctrl_key, shift_key: int` | none | recovered parameters |
| `00478660` | `mouse_left_dbl_click_action` | `x, y: long`; `ctrl_key, shift_key: int` | none | recovered parameters |
| `004786B0` | `item_at` | `x, y: long` | none | recovered parameters |
| `00478700` | `goto_item` | `x, y: long` | none | recovered parameters |
| `00478730` | `key_down_action` | `key: long`; `count: short`; `alt_key, ctrl_key, shift_key: int` | none | recovered parameters |
| `00478850` | `char_action` | `key: long`; `count: short` | none | recovered parameters |
| `00478900` | `action` | `from_panel: TPanel*`; `action_in: long`; `action_val1, action_val2: unsigned long` | none | recovered parameters |
| `00478920` | `scroll_cur_line` | `scroll_type: unsigned char`; `scroll_val: short`; `update_scrollbar: int` | none | recovered parameters |
| `00478BA0` | `draw` | none | `old_font: void*` | unchanged; already matched |
| `00478CD0` | `draw_highlight_bar` | none | `r: tagRECT` | unchanged; already matched |
| `00478EE0` | `setDrawHighlightBar` | `v: int` | none | unchanged; already matched |
| `00478EF0` | `set_focus` | `have_focus_in: int` | none | recovered parameter |

The compiler-generated scalar deleting destructor at `00478310` was also inspected.
Its packet has no PDB source or procedure record. It has no source body in this module.
No source change was made for that emitted function.

The PDB names above are recovered original names.
No new descriptive parameter or local names were invented.
The existing locals `now`, `item`, `rowsize`, `ch`, `node`, `i`, `old_cur`, `new_cur`,
`cur`, `line`, and `line_index` have no procedure-scoped PDB records here.
I did not force an original mapping for those names.
The `old_font` and `r` locals already use the PDB names.

## Cleanup changes

I replaced generated or substitute parameter names with the exact PDB spellings.
The changes cover 47 parameters in 13 source functions.
The parameter types, order, storage, and calls remain unchanged.
The unused mouse and keyboard parameters now have their recorded names.
The source keeps the existing 1TBS layout and readable line wrapping.

I made no structural rewrite.
I kept the direct member accesses, casts, scopes, evaluation order, and call targets.
I did not alter the known `item_at` accepted drift.
The earlier module note records its member-load scheduling difference at `004786B0`.

## Constants, resources, and comments

No constant was added, removed, or replaced.
The constructor interval `0x32`, debug source line values `0x6C`, `0xB1`, and `0xBA`,
scroll action values, key values, and draw value `0xFF` remain unchanged.
The selected packets prove those literal values and call arguments.

No resource ID or resource lookup changed.
This source has no resource lookup call site.
No shared resource mapping request is needed.
No resource DLL extraction was needed.

No comment was added.
The comment guide calls for sparse comments.
This module has no new fact that needs a source comment.

## Effects and requests

The edits change parameter identifiers and source formatting only.
They do not change public function names, decorated symbols, ABI types, class layouts,
member offsets, storage duration, or direct call identity.
They can change debug name and line metadata after a later compile.
No compiler output was produced in this cleanup phase.

No header change is requested.
The unassigned parameter names in `include/pnl_lst.h` do not block definition names.
The header owner should keep the current declarations and layout.

Open questions remain for the unrecorded local names listed above.
The PDB does not support a stronger mapping.
The prior `004786B0` accepted-drift scheduling difference remains unresolved.

Compilation, matching, audits, and tests were not run.
