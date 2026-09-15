# `src/vw_main.cpp` cleanup report

## Delivery

- Module: `src/vw_main.cpp`
- PDB source: `C:\\msdev\\work\\age1_x1\\vw_main.cpp`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `99447c02545d8313a21bab928c9fd77bcb294e5b`
- Changed files:
  - `src/vw_main.cpp`
  - `decomp_notes/source_cleanup/wave04/vw_main.md`

The source commit changes only the assigned source. The report is the only
other assigned file. No header or registry file changed.

## Evidence

I inspected every normal procedure from `0053DAB0` through `00540700`.
The procedure-scoped PDB records are in:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The extracted review copy is in:

`build/vw_main_evidence/pdb_scoped.json`

All 27 procedures have a `this` record in `ecx`. The records include original
parameters and addressable locals. I kept reused homes separate when their
current declarations did not prove one mapping.

The source evidence files are:

- PDB: `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`
  - SHA256: `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`
- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`
  - SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`
- Preserved baseline object: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/vw_main.obj`
  - SHA256: `52260026491de4d10417103877c49ac09f6ef5d9e8efc1109a81c2491212aeef`

The pinned VC5 toolchain file, `FCNTL.H`, and `WINUSER.H` were read first.
The source has no new SDK constant use.

## Original-name recovery coverage

The following names came from the PDB. Names not listed as changed already
matched the current source.

| VA | Procedure | Recovered parameter and local names |
| --- | --- | --- |
| `0053DAB0` | `RGE_Main_View::RGE_Main_View` | No named stack record. `this` is `ecx`. |
| `0053DB40` | `handle_idle` | No named stack record. `this` is `ecx`. |
| `0053DBA0` | `do_auto_scroll` | `point`, `vert_scroll`, `rect`, `scroll_dist2` already matched. |
| `0053DEB0` | `handle_keys` | `pbKeyState` recovered from `keys`; `horz_scroll`, `vert_scroll`, and `scroll_dist2` matched. |
| `0053E280` | `handle_mouse_up` | `mouse_button_in`, `ctrl_key`, and `shift_key` recovered. `x` and `y` matched. |
| `0053E2F0` | `mouse_move_action` | `ctrl_key` and `shift_key` recovered. `x` and `y` matched. |
| `0053E340` | `mouse_left_down_action` | `x`, `y`, `ctrl_key`, `shift_key`, `pick_info`, `min_y`, `min_x`, `point`, `max_y`, and `max_x` matched. |
| `0053E7F0` | `mouse_left_move_action` | `ctrl_key` and `shift_key` recovered. `x` and `y` matched. |
| `0053E910` | `mouse_left_up_action` | `ctrl_key`, `shift_key`, `status`, `list`, and `list_num` recovered. `x`, `y`, and `pick_info` matched. |
| `0053F220` | `mouse_right_down_action` | `ctrl_key` and `shift_key` recovered. `x` and `y` matched. |
| `0053F2F0` | `mouse_right_move_action` | `ctrl_key` and `shift_key` recovered. `x` and `y` matched. |
| `0053F3D0` | `mouse_right_up_action` | `ctrl_key`, `shift_key`, `list`, and `list_num` recovered. `x`, `y`, and `pick_info` matched. |
| `0053F660` | `start_scroll_view` | `scroll_action_in`, `ctrl_key`, and `shift_key` recovered. `x` and `y` matched. |
| `0053F6B0` | `handle_scroll_view` | `x` and `y` matched. |
| `0053F6F0` | `draw` | No named stack record. `this` is `ecx`. |
| `0053F800` | `draw_multi_object_outline` | No named stack record. `this` is `ecx`. |
| `0053F810` | `command_place_object` | `reset_mode` and `check` recovered. `x`, `y`, and `pick_info` matched. |
| `0053FA10` | `command_make_do` | `work_on_tile` and `action_type` recovered. `x`, `y`, `pick_info`, `list`, `list_num`, and `attacking` matched. |
| `0053FBD0` | `pick1` | `pick_mode_in`, `last_picked_object`, `pick_dopples`, `target_count`, `picked_obj`, `scr_x`, `scr_y`, and `found_last` recovered. `select_level`, `x`, `y`, `pick_info`, and `i` matched. |
| `0053FFB0` | `pick_objects1` | `object_list` and `max_objects` recovered. `x`, `y`, and `pick_info` matched. |
| `00540010` | `pick_best_target` | `attacking_in`, `action_type`, and `master_obj` recovered. `x`, `y`, `selected_count`, `selected_objects`, `j`, `target_count`, `i`, `valid_target_count`, and `attacking` matched. |
| `00540350` | `command_make_move` | `x`, `y`, `pick_info`, `list`, and `list_num` matched. |
| `00540420` | `command_make_work` | `x`, `y`, `pick_info`, `list`, `list_num`, and `attacking` matched. |
| `005405C0` | `command_place_multi_object` | `x1`, `y1`, `x2`, `y2`, and `reset_mode` recovered. |
| `005405E0` | `get_help_info` | `string` recovered. `page`, `x`, `y`, and `pick_info` matched. |
| `00540680` | `fixup_pick_info` | `pick_info` recovered. |
| `00540700` | `reset_display_object_selection` | `reset_type` recovered. |

The PDB records `high_confidence` in `pick1`, but the current source has no
matching declaration. The existing `best_weight` is a score, not the PDB's
count-like symbol. I did not force that mapping or add a declaration.

The PDB records `master_obj` as an `RGE_Master_Action_Object*` in
`pick_best_target`. The current pointer `cur_target` had that role, so it now
uses `master_obj`. The old `int master_obj` held the picked-record count. It
now uses the inferred cleanup name `picked_count` to avoid a type collision.
This name is not claimed as an original.

The PDB records `status` at function scope in `mouse_left_up_action`. The
current behavior source has two branch-local status values. Both now use the
PDB spelling. I did not change their scope. The PDB also shows reused homes
for `status`, `list`, and `list_num`; I did not force one shared declaration.

The local `text` in `get_help_info` is a new cleanup name. It avoids a name
collision after recovering the `string` output parameter. The PDB has no
record for that local.

## Constants, resources, and comments

No resource ID or resource lookup occurs in this module. No DLL extraction was
needed. No resource hash, language, or payload record applies.

No new constant, macro, enum, or SDK symbol was added. Existing numeric modes,
status values, redraw values, object IDs, timer values, and fallback values
remain unchanged. Existing casts and literal types remain unchanged.

I added no comments. Existing comments remain sparse and useful. They explain
`RGE_Master_Action_Object` task ownership and the typed display-selection
record. No comment claims a behavior that this cleanup did not prove.

## Source and code-generation effects

The edits rename function parameters and locals. They do not change types,
scopes, storage, evaluation order, control flow, casts, calls, literals, or
public symbols. They do not change object layout or decorated symbols.

The source uses 1TBS formatting in changed signatures and calls. Formatting
can change PDB line records. The source has no `__LINE__` use. Generated code,
relocations, and call targets remain unvalidated because this phase forbids
compilation.

The inferred `picked_count` name and the local `text` name are source names,
not recovered original names. The unresolved `high_confidence` record and the
function-scope `status` difference remain open. No structural rewrite was
made.

## Shared requests and unresolved questions

- Header request to owner 24: no declaration change is required. `include/vw_main.h` has unnamed parameters. Please review the source names `mouse_button_in`, `scroll_action_in`, `pick_mode_in`, `last_picked_object`, `pick_dopples`, `reset_mode`, `work_on_tile`, `action_type`, `attacking_in`, `string`, and `reset_type` if header parameter names are added later. The header is shared with `tvw_main.cpp` and was not edited.
- Root shared declaration request: none.
- Root resource mapping request: none.
- Open PDB mapping: `pick1::high_confidence` has no current declaration. Do not add it without source or stack-lifetime evidence.
- Open scope mapping: `mouse_left_up_action::status` is function-scope in the PDB, but the current source keeps two branch-local declarations. Do not change scope in this naming pass.

Compilation, matching, audits, and tests were not run. Builds, validation
commands, and games were also not run.
