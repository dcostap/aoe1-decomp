# Command packet ID cleanup

Base commit: `b9f41b1502439a8f8794851c8f888527bec11452`.

## Changes

- `include/Command.h`: define 18 `RGE_COMMAND_ID_*` macros.
- `include/tcommand.h`: define 13 `TRIBE_COMMAND_ID_*` macros and nine `TRIBE_GAME_COMMAND_ID_*` macros.
- `src/Command.cpp`: name packet IDs in dispatch, duplicate checks, and packet writers.
- `src/tcommand.cpp`: name packet IDs and game subcommands in dispatch and packet writers.
- `src/world.cpp`: retain the user's call wrapping and remove its trailing space.
- `decomp_notes/source_cleanup/command_ids.md`: record scope, evidence, and validation.

These are new cleanup names, not recovered original macro names.
No parameter, local, member, type, interface, or function name changes.
All declarations remain in their existing command headers.

The earlier commit contains only formatting changes in `com_hand.cpp`, `mst_play.cpp`, and `tcommand.cpp`.
Review found no changed non-whitespace characters.
The shared headers contain no `__LINE__` or `__COUNTER__` uses.
The constructor also lost a trailing space.

## ID evidence

The original executable remains the behavior oracle.
The packet writers establish IDs; dispatcher call targets establish their command roles.
PDB-qualified procedure names support the new names.
The existing source and function registry provide the source-to-symbol mapping.

The pinned executable is `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA256 is `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The extraction tool uses `orig/_original_empiresx_from_beta_that_was_decompiled.exe`.
Both files have this same hash.
Fresh extraction covers dispatchers `00433E20`, `00509770`, and `0050A1D0` under `build/asm/`.
The inventory listings supply supporting call-target and packet-writer evidence, not a separate behavior oracle.

### Base packet IDs

`RGE_Command::do_command` at `00433E20` dispatches IDs 0 through 17.
ID 13 has no dispatcher case; `command_pause` at `004355A0` writes `0x0D` at `004355EA`.
The cleanup does not add a missing dispatcher case.
`close_check_for_duplicate_orders` retains its four cases: order, work, move, and stop.
TRIBE's create override uses the same base create ID, 4.

| ID | `RGE_COMMAND_ID_` suffix |
| --- | --- |
| 0 | `ORDER` |
| 1 | `STOP` |
| 2 | `WORK` |
| 3 | `MOVE` |
| 4 | `CREATE` |
| 5 | `ADD_ATTRIBUTE` |
| 6 | `FORMATION` |
| 7 | `GIVE_ATTRIBUTE` |
| 8 | `CREATE_GROUP` |
| 9 | `DESTROY_GROUP` |
| 10 | `AI_ORDER` |
| 11 | `RESIGN` |
| 12 | `ADD_WAYPOINT` |
| 13 | `PAUSE` |
| 14 | `ADD_TO_GROUP` |
| 15 | `REMOVE_FROM_GROUP` |
| 16 | `GROUP_WAYPOINT` |
| 17 | `GROUP_AI_ORDER` |

### TRIBE packet IDs

`TRIBE_Command::do_command` at `00509770` selects these handlers.
The corresponding `command_*` packet writers store the same IDs.

| ID | `TRIBE_COMMAND_ID_` suffix | Original writer VA |
| --- | --- | --- |
| `0x64` | `MAKE` | `0050A7F0`, `0050A860` |
| `0x65` | `RESEARCH` | `0050A8D0`, `0050A940` |
| `0x66` | `BUILD` | `0050A9B0`, `0050AA90` |
| `0x67` | `GAME` | All game-subcommand writers below |
| `0x68` | `EXPLORE` | `0050AC70` |
| `0x69` | `BUILD_WALL` | `0050AB30` |
| `0x6A` | `CANCEL_BUILD` | `0050AFD0` |
| `0x6B` | `ATTACK_GROUND` | `0050B020` |
| `0x6C` | `GIVE_ATTRIBUTE` | `0050B130` |
| `0x6D` | `TRADE_ATTRIBUTE` | `0050B190`, `0050B230` |
| `0x6E` | `REPAIR` | `0050B290` |
| `0x6F` | `UNLOAD` | `0050B330` |
| `0x77` | `QUEUE` | `0050B3E0` |

### Game subcommands

`TRIBE_Command::do_command_game` at `0050A1D0` selects the existing subcommand handlers.
`UPGRADE_TOWN` has a writer but no handler case. The cleanup retains that gap.
`SAVE_GAME` follows the original sender name.
Its handler saves `syncerr%d.gam`, sets `out_of_sync2`, and ends the game.
The name does not imply a normal save operation.

| ID | `TRIBE_GAME_COMMAND_ID_` suffix | Original writer VA |
| --- | --- | --- |
| 0 | `RELATION` | `0050AD70` |
| 1 | `GAME_SPEED` | `0050ADF0` |
| 2 | `INVENTORY` | `0050AE80` |
| 3 | `UPGRADE_TOWN` | `0050AEE0` |
| 4 | `QUICK_BUILD` | `0050AF30` |
| 5 | `ALLIED_VICTORY` | `0050AD00` |
| 6 | `CHEAT` | `0050B0D0` |
| 7 | `SHARED_LOS` | `0050AF80` |
| 8 | `SAVE_GAME` | `0050AE40` |

## Scope and types

Macros expand to unsuffixed integer literals. Every value fits the original `int` type.
Decimal and hexadecimal spellings in this range have the same value and type.
The macros add no objects, enum types, initializers, or storage.
Packet fields remain `unsigned char`. Layouts, casts, statement order, and calls remain unchanged.

The source search found packet ID literals only in these two modules.
Other command domains remain separate: effects, AI orders, timeline events, victory conditions, drawing, and communication messages.
Equal numeric values do not make these domains interchangeable.
Work progress values `0x66` and `0x67` remain numeric; they are not packet IDs.
Lengths, priorities, null values, and Boolean flags remain unchanged.

## Compiled baseline

Baseline objects: `build/validation/civilization-ids-followup-20261004-024848/functions/objects/`.
Before editing, the baseline check verified all 225 input fingerprints and recorded object hashes.
222 fingerprints matched directly.
The other three matched after substituting the reviewed pre-formatting source hashes and sizes.
Those source files contained only the formatting changes listed above.
No other compiler input differed.

Check: `python build/command-id-cleanup/check_baseline.py`, exit code 0.
Report: `build/command-id-cleanup/baseline.json`.

## Validation

Source and registry validation returned exit code 0.
Command: `python tools/validate_translation_units.py --no-build-checks`.

The full VC5 function audit returned exit code 0.
All 225 modules compiled. All 5,013 exact claims passed among 5,426 normal functions.
The remaining 413 functions retain these categories:

- 217 `new_verified_logic_observed`.
- 140 `accepted_drift_observed`.
- 44 `grouped_mismatch`.
- 12 `boundary_problem`.

Command: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/command-ids-20261004-042228/functions`.
Report: `build/validation/command-ids-20261004-042228/functions/report.json`.

The before/after object comparison returned exit code 0. No object differs.
All 225 objects retain identical non-debug section bytes, sizes, flags, relocation targets, and allocated symbol identities.
The comparison normalizes private compiler-label serial numbers by section and offset.
It excludes debug metadata and COFF timestamps.
This comparison also covers header consumers and nonmatching function payloads.
It also confirms that the earlier formatting commit did not change these compiled payloads.

Command: `python build/object-state-cleanup/compare_objects.py --before build/validation/civilization-ids-followup-20261004-024848/functions/objects --after build/validation/command-ids-20261004-042228/functions/objects --output build/validation/command-ids-20261004-042228/object-comparison.json`.
Report: `build/validation/command-ids-20261004-042228/object-comparison.json`.

`git diff --check` passed. All four source and header files retain LF line endings.
No registry configuration, function status, stored type, or public signature changed.
No separate owner audit, linked executable build, linked audits, automated regression tests, or gameplay tests ran.
The object comparison proves unchanged compiled payloads, not complete agreement with the original game.
Existing matching and behavior coverage limits remain.

## User formatting included in the commit

After validation, the user changed call wrapping in `RGE_Game_World::load_scenario3`.
Review found no changed non-whitespace characters in `src/world.cpp`.
The source and shared headers contain no `__LINE__` or `__COUNTER__` uses.
The trailing space was removed; the user's wrapping remains.
No compiler check repeated after this formatting-only change.
