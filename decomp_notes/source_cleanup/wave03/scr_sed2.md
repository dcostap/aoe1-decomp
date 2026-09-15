# `src/scr_sed2.cpp` cleanup report

## Scope and hashes

- Module: `src/scr_sed2.cpp`
- Header owner: owner 21 owns `include/scr_sed2.h` and `include/scr_sed.h`.
  This worker did not edit either header.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Final source commit: `990afb1a237c12b38a9b88ccbf3bd0d56f7c5bb1`
- Base source SHA-256: `5364db9db498eab6059cc5be8229d3539bdc3ea9f35a2e0b0e1807c4fdac5ebe`
- Final source SHA-256: `da8c8a4b3ac5a3500fecf916b281a2233df4d2048a42334e606151b7c32bb9df`
- Changed files:
  - `src/scr_sed2.cpp`
  - `decomp_notes/source_cleanup/wave03/scr_sed2.md`

The source keeps all 19 normal owners in PDB source order. It keeps the three
padding-only fragments outside the source owner. It does not add wrappers,
fragments, context macros, or new functions.

## Original-name recovery coverage

I inspected all 19 procedure records in
`inventory/pdb/scoped_symbols.json`. The source now uses these exact PDB
parameter names:

- `004AE620 load_victory_cond_from_scenario`: `which` replaces `index`.
- `004AECB0 save_diplomacy_in_scenario`: `which` replaces `param_1`.
- `004AED50 load_diplomacy_from_scenario`: `which` replaces `player`.
- `004AEE10 activate_victory_proper_fields`: `TypeOfVictory` and `activate`
  were already present.
- `004B2AA0 MakeFileList`: `drop_down`, `dir`, `extension`, `append_none`,
  and `append_random` replace the descriptive substitutes. The local
  `_finddata_t` name is the exact PDB spelling `fileInfo`.
- `004B2BC0 Set_player_advance_civilization_text`: the unnamed parameter is
  now `newmode`.
- `004B2DD0 create_check_box` and `004B2E60 create_radio_button`: `button`
  replaces `out`; `parent` was already present.

The PDB names `x1`, `y1`, `x2`, `y2`, `VictoryType`, and `ObjectNumber` in
`004AE070` were already present. The names `str`, `destobj`, `Amount`,
`VictoryType`, `AttributeType`, `x1`, `y1`, `x2`, and `y2` in `004AE620` were
also already present.

The PDB has no local records for `init_module_variables`. Its obvious
decompiler names are now the cleanup names `button_cursor` and `index`.
The same function keeps every declaration, loop bound, store, and scope.
Other new descriptive cleanup names are `player_number`, `all_players`,
`attitude`, `allied_victory`, and `state`. They are not claimed as original
names.

`004AF6C0 create_all_buttons_etc` retains the PDB names `i`, `str4`, `str3`,
`str2`, `str1`, `str`, and `ptr`. Its other locals `pp`, `count`, `cur`, `tt`,
and `group` have no procedure-scoped PDB records and remain unresolved.
The remaining short locals have no reliable PDB declaration mapping. I did not
force a new declaration or merge any storage slots.

## Constants, resources, comments, and formatting

The source now uses existing `TPanel::PositionMode` names from
`include/panel.h`:

- `PositionLeftTop` retains value `7`.
- `PositionLeftBottom` retains value `8`.
- `PositionRightTop` retains value `9`.
- `PositionRightBottom` retains value `10`.

The old casts to these enum values were replaced only by their established
symbols. Their type, value, call order, and panel arguments remain unchanged.

No resource ID was changed. The source keeps all numeric resource and help
IDs, including the `0x2775` and `0x277B` file-list entries, the contiguous
`0x2865` player-name range, and the `0x1069` through `0x106D` civilization
entries. No shared resource declaration was added.

The incomplete comment before `LoadDisabledItemsFromScenario` was removed.
Existing comments about victory-condition behavior, diplomacy state clearing,
and the proven panel-array layout remain. No new source comment was added.
Function definitions now use 1TBS braces. The only control-style change joins
an existing `else` brace to its preceding brace.

## Code-generation risks and unresolved issues

Parameter and local renames do not change an ABI symbol, type, storage,
control flow, field offset, or call target. The enum replacements keep the
original enum values and parameter type. Formatting changes can change debug
line records, but this file has no `__LINE__` or `__FILE__` use.

The existing source-recovery note still records `004AE070` as the only
non-exact normal owner. Its unresolved VC5 merge and local-home permutation
were not changed by this cleanup.

The source diff was reviewed. `git diff --check` passed. No output claim is
made from this source-only review.

## Shared-file requests

Owner 21 can add the recovered parameter names to the canonical declarations
in `include/scr_sed.h`:

- `load_victory_cond_from_scenario(int which)`
- `save_diplomacy_in_scenario(int which)`
- `load_diplomacy_from_scenario(int which)`
- `activate_victory_proper_fields(int TypeOfVictory, int activate)`
- `MakeFileList(TDropDownPanel* drop_down, char* dir, char* extension,
  unsigned char append_none, unsigned char append_random)`
- `Set_player_advance_civilization_text(int newmode)`
- `create_check_box(TPanel* parent, TButtonPanel** button)`
- `create_radio_button(TPanel* parent, TButtonPanel** button)`

Evidence for these requests is the procedure-scoped PDB record at each VA in
`inventory/pdb/scoped_symbols.json`. No resource-ID header request is made.

## Validation status

Compilation, matching, audits, and tests were not run. No compiler, build,
matching, audit, test, or game command was run for this assignment.
