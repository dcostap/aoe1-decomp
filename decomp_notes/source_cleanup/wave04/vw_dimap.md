# `src/vw_dimap.cpp` cleanup report

## Scope and commits

- Module: `src/vw_dimap.cpp`.
- Header owner: owner 24 owns `include/vw_dimap.h`. This worker did not edit
  the header.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Source commit: `4cb1e213de2df2525ac7df95e07c82d562c09abe`.
- The report is committed separately after the source commit.

The module has twelve registered normal functions. The cleanup restores
procedure-scoped PDB names for ten functions. It also fixes indentation,
moves three opening braces to 1TBS style, and keeps the existing ABI notes.
It does not add or remove executable statements.

The deleting destructor at `0053D380` is compiler-generated. It has no source
body in this module and was not changed.

## Evidence identity

- Registry:
  `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/vw_dimap.cpp.json`.
  It assigns `0053D360` through `0053DA10` to this source with `matching`
  status.
- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`.
  SHA256:
  `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Original PDB:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`.
  SHA256:
  `3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
- Scoped PDB index:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
  SHA256:
  `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- Function packets:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0053/`.
- Original assembly reference:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/vw_dimap.cpp.asm`.
  SHA256:
  `ba85a4947eb3e6ca86ea13b63f98f1f7131316c30071baca454da406bb9f5f1b`.
- Original decompiler reference:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/vw_dimap.cpp.decomp`.
  SHA256:
  `514be6faf49f0a80b78591a109a7464b15f396efc194f5bfe3ff1d89eab22bac`.

The PDB records the source path as
`C:\msdev\work\age1_x1\vw_dimap.cpp`. The inspected function packets cover
these body ranges, sizes, and source spans:

| VA | Bytes | PDB lines | Function |
| --- | ---: | --- | --- |
| `0053D360` | 28 | 26-28 | constructor |
| `0053D3B0` | 80 | 34-44 | `handle_mouse_down` |
| `0053D400` | 126 | 50-63 | `mouse_left_down_action` |
| `0053D480` | 114 | 69-89 | `mouse_left_move_action` |
| `0053D500` | 284 | 95-148 | `mouse_left_up_action` |
| `0053D620` | 126 | 154-167 | `mouse_right_down_action` |
| `0053D6A0` | 114 | 173-200 | `mouse_right_move_action` |
| `0053D720` | 368 | 206-261 | `mouse_right_up_action` |
| `0053D890` | 68 | 267-275 | `draw` |
| `0053D8E0` | 141 | 281-295 | `command_make_do` |
| `0053D970` | 156 | 301-316 | `command_make_move` |
| `0053DA10` | 156 | 322-337 | `command_make_work` |

All twelve function records use `__thiscall`, have one body range, and have
no function statics. The PDB register record for each function names `this`.

## PDB coverage and name recovery

The PDB procedure records provide these parameter names and types:

- `0053D3B0` provides `mouse_button_in` (`unsigned char`), `x`, `y`,
  `ctrl_key`, and `shift_key` (`long`, `long`, `int`, `int`). It also provides
  local `tile` (`RGE_Tile*`), `row` (`short`), and `col` (`short`).
- Each mouse action at `0053D400`, `0053D480`, `0053D500`, `0053D620`,
  `0053D6A0`, and `0053D720` provides `x`, `y`, `ctrl_key`, and `shift_key`.
- `0053D720` provides local `tile`, `row`, and `col`.
- `0053D500` provides local `tile`, `row`, and `col`.
- Each command function at `0053D8E0`, `0053D970`, and `0053DA10` provides
  `x`, `y`, `tile`, `row`, and `col`.
- `0053D360` and `0053D890` have no named parameters or locals.

The source changes recover these names:

- `button`, `ctrl`, and `shift` became `mouse_button_in`, `ctrl_key`, and
  `shift_key` in `handle_mouse_down`.
- The six mouse action definitions now use the PDB names `ctrl_key` and
  `shift_key`. The names are unused in these bodies, but the records establish
  them.
- `param_3` and `param_4` became `ctrl_key` and `shift_key` in
  `mouse_right_up_action`.
- The two tile output variables in `handle_mouse_down` and
  `mouse_right_up_action` became `col` and `row`, as established by the PDB
  local records and the `pick_tile` output order.
- `a1` and `a2` became the PDB parameter names `x` and `y` in all three
  command functions.
- The command-local `x` and `y` names then became `world_y` and `world_x`.
  These are cleanup names, not PDB names. They avoid shadowing the recovered
  screen-coordinate parameters. Their declaration order and player-command
  argument order remain unchanged.

Existing `result`, `mode`, and `prog_mode` names remain unchanged. The PDB
records do not provide replacement names for those locals. No generated name
was forced into a declaration.

## Constants, resources, and comments

No constant or literal changed. The source has no resource lookup, resource ID,
function static, or resource mapping request.

The existing comments for player command virtual slots and the base-game
cleanup slot remain. No new source comment was needed. The known incomplete
virtual declarations and command-slot ABI gap remain outside this source-only
cleanup.

## Header request to owner 24

Owner 24 must align the unnamed parameters in `include/vw_dimap.h` with these
PDB-backed source definitions. The request changes parameter names only. It
does not change the types, virtual slots, or ABI:

```cpp
virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key);
virtual long mouse_left_down_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_left_move_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_left_up_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_right_down_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_right_move_action(long x, long y, int ctrl_key, int shift_key);
virtual long mouse_right_up_action(long x, long y, int ctrl_key, int shift_key);
virtual int command_make_do(long x, long y);
virtual int command_make_move(long x, long y);
virtual int command_make_work(long x, long y);
```

The PDB types are `unsigned char` for `mouse_button_in`, `long` for each `x`
and `y`, and `int` for each `ctrl_key` and `shift_key`. The command methods
use `long x`, `long y`, and return `int`.

## Correction history

- The initial report in commit `fe2aeb4321e2cf2cf31fd22aa1cfacb63706bd8d`
  incorrectly stated that no header request was needed.
- This correction records the required owner 24 request for all ten affected
  declarations. The worker still does not edit `include/vw_dimap.h`.

## Type and code-generation risks

The edits change parameter and local identifier spelling, indentation, brace
placement, and no executable structure. They preserve types, casts, scopes,
declaration order, storage, evaluation order, calls, literals, control flow,
virtual-slot comments, and source order. No layout, ABI symbol, or header
changed.

The source diff has no statement addition or removal. The module remains
unvalidated until the final comparison against the preserved pre-cleanup
build.

## Validation status

Evidence inspection, complete Git diff review, and `git diff --check` ran.
Compilation, builds, matching, audits, validation tools, tests, and games were
not run. No prohibited command started.
