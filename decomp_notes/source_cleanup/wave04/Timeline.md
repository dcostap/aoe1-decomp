# `Timeline.cpp` source-cleanup report

## Scope and commits

- Module: `src/Timeline.cpp`.
- Branch: `cleanup/staging-20260915-249`.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Final source commit: `915cc2f3d97ec6f2fa35ddbb0be9aa30e91cddb5`.
- Base source blob: `8c3a5c69501539be1e8ce014c72face776a43560`.
- Final source blob: `8426e6ea927a502baa46d9165c41e19aad939de5`.
- Report commit: recorded in the delivery message after this report commit.
- Changed files: `src/Timeline.cpp` and this report only.
- Read-only header: `include/Timeline.h`.

The source keeps its natural owner and function order. The header keeps its
existing declaration parameter names because its owner is not this worker.

## Evidence paths and hashes

The original PDB is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`

Its SHA256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The procedure-scoped PDB dump used for this cleanup is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-249/build/evidence/age1_x1_cvdump_s.txt`

The generated scoped-symbol inventory is:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`

The PDB source path is `C:\msdev\work\age1_x1\Timeline.cpp`. Every scoped
record lists module object path `./Release/Timeline.obj` and register `ecx`
with name `this`. The raw PDB records and all stack names are in the scoped
symbols dump and the module-specific inventory files under:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/`

The original executable used as the behavior oracle is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The original listing evidence is:

`C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/timeline.cpp.asm`

The procedure-specific listing evidence is in:

`C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0050/`

The preserved pre-cleanup object is:

`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Timeline.obj`

Its SHA256 is
`c4fc4c57ccb1f0cec30e96e0b396b2a99a44606929c1b44417cb613bb0ab1ad2`.

The function registry is:

`config/functions/src/Timeline.cpp.json`

It records all 13 normal owners listed below. The compiler-generated scalar
deleting destructor at `0050D790` is not a handwritten source owner.

## PDB name-recovery coverage

The following table covers every function in `src/Timeline.cpp`. The sizes are
the PDB `S_GPROC32` `Cb` values. The stack names and types come from the raw
PDB records and `inventory/pdb/scoped_symbols.json`. The PDB records `this` in
`ecx` for every row.

| VA | PDB procedure and size | PDB parameters and locals | Source result |
| --- | --- | --- | --- |
| `0050D5B0` | `RGE_Timeline::RGE_Timeline`, 471 bytes | `infile` `int`; `gworld` `RGE_Game_World*`; `index` `long`; `target_player_id` `short`; `this_player_id` `short`; `temp2` `RGE_Time_Entry**` | Recovered `infile`, `gworld`, `index`, `target_player_id`, `this_player_id`, and `temp2`. |
| `0050D7B0` | `RGE_Timeline::RGE_Timeline`, 38 bytes | `gworld` `RGE_Game_World*` | Recovered `gworld`. |
| `0050D7E0` | `RGE_Timeline::~RGE_Timeline`, 70 bytes | none | No parameter or local name beyond `this`. |
| `0050D830` | `RGE_Timeline::save`, 355 bytes | `outfile` `int`; `target_player_id` `short`; `this_player_id` `short` | Recovered `outfile`, `target_player_id`, and `this_player_id`. |
| `0050D9A0` | `RGE_Timeline::update`, 364 bytes including the switch table | `time` `float` local | `time` already used the PDB name. No other PDB local exists. |
| `0050DB10` | `RGE_Timeline::mock_update`, 529 bytes | `time` `float` | Recovered `time`; no PDB locals exist. |
| `0050DD30` | `RGE_Timeline::find_id`, 51 bytes | `obj` `RGE_Static_Object*` | `obj` already used the PDB name. |
| `0050DD70` | `RGE_Timeline::add`, 136 bytes | `time` `float` | `time` already used the PDB name. No PDB locals exist. |
| `0050DE00` | `RGE_Timeline::add_attack`, 80 bytes | `time` `float`; `obj` `RGE_Static_Object*`; `target` `RGE_Static_Object*` | Recovered `obj`; `time` and `target` already used the PDB names. |
| `0050DE50` | `RGE_Timeline::add_create`, 149 bytes | `time` `float`; `obj_id` `short`; `player` `unsigned char`; `x`, `y`, `z` `float` | Recovered `obj_id`; all other parameters already used the PDB names. |
| `0050DEF0` | `RGE_Timeline::add_move`, 80 bytes | `time` `float`; `obj` `RGE_Static_Object*`; `x`, `y`, `z` `float` | Recovered `obj`; all other parameters already used the PDB names. |
| `0050DF40` | `RGE_Timeline::add_delete`, 144 bytes | `time` `float`; `obj` `RGE_Static_Object*` | Both parameters already used the PDB names. |
| `0050DFD0` | `RGE_Timeline::sub`, 100 bytes | `entry` `RGE_Time_Entry*`; `temp2` `RGE_Time_Entry*` | `entry` already used the PDB parameter name. The PDB local `temp2` has no safe mapping in the current natural body and remains unresolved. |

The PDB contains no function-static symbols for these procedures. It contains
no register names other than `this` in `ecx`.

## Renamed parameters and locals

Recovered original parameter names replaced prior descriptive names:

- `0050D5B0`: `fd` became `infile`; `world_arg` became `gworld`; `player_id` became `this_player_id`.
- `0050D7B0`: `world_arg` became `gworld`.
- `0050D830`: `file` became `outfile`; `source_player_id` became `this_player_id`.
- `0050DB10`: `t` became `time`.
- `0050DE00`: `object` became `obj`.
- `0050DE50`: `type` became `obj_id`.
- `0050DEF0`: `object` became `obj`.
- `0050D5B0`: `link` became `temp2`, based on its `RGE_Time_Entry**` type and its list-link use. The existing `old_link` variable has no PDB record and remains unchanged.

The PDB names `index`, `target_player_id`, `time`, `target`, `player`, `x`,
`y`, `z`, `obj`, and `entry` already matched source declarations in their
other procedures. Their coverage is listed in the table above.

These local names have no reliable PDB mapping. They remain unchanged unless
listed as new descriptive names below:

- `0050D5B0`: allocated `entry` and `old_link`.
- `0050D830`: `save_file`, `count_ptr`, `i`, and allocated `entry`.
- `0050D9A0`: `event`, `player`, `master`, `object`, `scan`, and `entry`.
- `0050DB10`: `list`.
- `0050DD30`: `entry`.
- `0050DD70`: `node`, `prev`, `new_node`, and `node_next`.
- `0050DE00`: allocated `entry`.
- `0050DE50`: `obj`, `node`, `player_record`, and `master`.
- `0050DEF0`: allocated `entry`.
- `0050DF40`: `node`, `entry`, and `command`.
- `0050DFD0`: `current` and `link`; the current body does not safely map the
  PDB local `temp2` to either declaration.

The cleanup assigns these new descriptive names to optimized or decompiler-
derived locals. They do not claim original spelling:

- In `0050DB10`, `e` became `entry`, `n` became `next_entry`, `obj` became
  `object`, `mo` became `master`, the nested `p` variables became `scan_entry`
  and `previous_entry`.
- In `0050DE50`, `p` became `player_record`.
- In `0050DF40`, `cur` became `entry` and `cmd` became `command`.

The source has no remaining `param_*`, `local_*`, or decompiler-register names.
The PDB local `temp2` in `0050DFD0` remains an explicit unresolved declaration
mapping. Reused and optimized storage prevents a safe reconstruction there.

## Constants, resources, and comments

No new constant or symbolic declaration was added. Existing numeric behavior
remains unchanged. This includes the 0x30-byte zero-filled event allocation,
command values 0, 1, 2, and 4, the object-state threshold 8, and the 0.001f
world-time scale. No type, width, signedness, declaration scope, storage
lifetime, cast, evaluation order, or call target changed.

`Timeline.cpp` has no resource-ID lookup and no resource DLL dependency. No
resource extraction was needed. No `inspect_pe_strings.py` lookup was run.
There are no resource-ID mappings or header requests.

The constructor comment now records the proven original lookup defect:
`0050D6DC` and `0050D715` load the two serialized player IDs, while the calls
at `0050D704` and `0050D73B` both index `players[target_player_id]`. The second
lookup ignores `this_player_id`. The `add_attack` comment records that the
calls at `0050DE28` and `0050DE3B` both pass `obj` to `find_id`, although the
second call supplies `target_obj_id`. These comments describe preserved
behavior. They do not claim a repair.

The source also uses 1TBS function braces and clearer signature wrapping. It
keeps source order and executable statements in place.

## Original names versus cleanup names

Recovered original names are `infile`, `gworld`, `index`,
`target_player_id`, `this_player_id`, `temp2`, `outfile`, `time`, `obj`,
`target`, `obj_id`, `player`, `x`, `y`, `z`, and `entry`, as listed by the PDB.
Names already present in the source are not claimed as recovered when the PDB
has no matching record.

New descriptive names are `entry`, `next_entry`, `object`, `master`,
`scan_entry`, `previous_entry`, `player_record`, and `command` in the specific
local scopes listed above. `entry` is both a PDB parameter name in `sub` and a
new local name in other functions; those scopes are distinct. `old_link`,
`save_file`, `count_ptr`, `node`, `prev`, and other existing source names remain
unclaimed original names when no PDB record supports them.

## Code-generation, type, layout, and symbol effects

The edits rename parameters and locals, adjust comments, and move existing
opening braces onto function-definition lines. They do not change a mangled
symbol, calling convention, parameter type, object layout, event-record size,
control flow, evaluation order, memory access, literal, cast, or call target.
The source-only `player_record`, `entry`, `command`, `next_entry`,
`scan_entry`, and `previous_entry` names keep their prior declarations and
scopes.

`0050DFD0 sub` remains the previously documented scratch owner. Its broad
control-flow and call-surface drift was not rewritten during this naming pass.
The constructor and `add` remain accepted-drift owners in the existing registry;
this cleanup does not make or remove a matching claim.

Compiler, matching, and linked-image checks remain required. This report does
not claim byte equality or semantic approval.

## Header requests and unresolved questions

No header change is requested. Definition parameter names can differ from the
read-only header parameter names without changing the interface. No shared
resource declaration is needed.

Open questions are the original spellings of PDB-unlisted locals and the exact
source declaration that produced the PDB local `temp2` in `0050DFD0`. The
current natural `sub` body preserves its existing structure instead of forcing
that local into a declaration. The original lookup defects remain intentional
compatibility behavior.

## Validation status

I reviewed the complete Git diff and ran `git diff --check`. I did not run a
compiler, build, matching check, audit, validation command, test, or game. I do
not claim byte equality, semantic approval, or validation.
