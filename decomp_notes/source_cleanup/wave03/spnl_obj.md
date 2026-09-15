# Source-cleanup report: `src/spnl_obj.cpp`

## Scope

- Module: `src/spnl_obj.cpp`
- Sole source owner: `src/spnl_obj.cpp`
- Header owner: `include/spnl_obj.h` (not changed)
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Changed files: `src/spnl_obj.cpp`, this report
- Final commit: recorded after commit

The source owns the seven normal `TRIBE_Scenario_Editor_Panel_Object` bodies at
`004BEDC0`, `004BEE30`, `004BEE40`, `004BEE70`, `004BF4D0`, `004BF6C0`, and
`004BF6E0`. The PDB source map places them at the expected `spnl_obj.cpp` line
bands. The scalar deleting destructor at `004BEE10` is compiler-generated and
has no source body in this module.

## Original-name recovery

Evidence source: the procedure-scoped records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Each record also identifies `this` as the
`TRIBE_Scenario_Editor_Panel_Object*` register parameter. No function statics
are recorded for these seven bodies.

| VA | Function | Recovered names |
| --- | --- | --- |
| `004BEDC0` | Constructor | `render_area_in`, `parent_panel_in`, `font_in`, `font_wid_in`, `font_hgt_in`, `unit_pics_in`, `bldg_pics_in`, `player_in` |
| `004BEE30` | Destructor | No stack parameters or locals |
| `004BEE40` | `set_master_info` | `master_game_object_in`, `master_player_in` |
| `004BEE70` | `draw` | Existing names `old_font`, `min_x`, `min_y`, `max_x`, `max_y`, `name`, `str`, and `text_flag` match the PDB record. No rename was needed. |
| `004BF4D0` | `draw_item` | `row`, `pic_index`, `val_type`, `val1`, `val2`; local `val_str` restored from the PDB record. Existing local `old_font` matches. |
| `004BF6C0` | `mouse_left_up_action` | Existing `x` and `y` match. `ctrl` and `shift` were restored to `ctrl_key` and `shift_key`. |
| `004BF6E0` | `get_pierce_armor` | No stack parameters or locals are recorded. Existing inferred local names remain unchanged. |

The `draw_item` PDB record places `val2` and the nested `old_font` at the same
stack offset. This is a reused slot, not evidence for a declaration merge. The
source keeps the parameter and nested local separate.

All renamed identifiers above are recovered original names. No new descriptive
cleanup names were assigned to variables.

## Formatting and comments

Function opening braces now use 1TBS. The existing source-order comments and
the comment that identifies the building-master facet were retained. No new
comment was needed. No executable statement, declaration type, scope, storage
duration, cast, call target, literal, or evaluation order was changed.

No resource IDs, constants, or shared declarations were added or changed.
There are no shared-file requests.

## Code-generation and ABI notes

The edits rename parameters and one PDB-recorded local, and adjust whitespace
and brace placement. They do not change types, layouts, signatures, symbol
names, call targets, or executable expressions. The shorter wrapped signatures
can move later source line numbers, so debug line records can change. Final
compiler and generated-output comparison remains required.

## Validation status

Compilation, matching, audits, and tests were not run, as required for this
cleanup wave. Only source evidence review and Git diff review were performed.
