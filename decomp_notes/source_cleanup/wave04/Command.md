# Command.cpp cleanup report

## Delivery

- Module: `src/Command.cpp`
- Read-only header: `include/Command.h`
- Worktree: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-223`
- Branch: `cleanup/staging-20260915-223`
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Final source commit: `559ed5444e83cf575323b39bb3aecbb39d123b9c`
- Changed files: `src/Command.cpp`, this report
- No header was changed.

The source commit changes names and presentation only. The normalized C++ token
stream matches the base source after identifier normalization. This is a local
review result. It is not a compiler or matching result.

## PDB coverage

I inspected all procedure-scoped records for `\\Release\\Command.obj` in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The source PDB is
`C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`.
The PDB SHA256 is
`3acf0034af3aae3636c37746d3336d76f737855963fabf64e66b22e3c3e46e40`.
The scoped dump SHA256 is
`e43dffc948e217f652b957c20734601eb3fc8baf10a6d0905b812e0fb41f5930`.

The PDB has 52 procedures for this module. It has 51 source definitions and
one compiler-generated scalar deleting destructor. Every record was inspected.
Every record has `this` in ECX. The following list records every procedure and
its scoped stack names. An empty list means that the PDB has no stack name for
that procedure.

- `00433D40` `RGE_Command::RGE_Command`: `gworld`, `com_handler`.
- `00433D70` scalar deleting destructor: `__flags`; compiler-generated.
- `00433D90` `RGE_Command::~RGE_Command`: none.
- `00433DB0` `reset_communications`: `com_hand_in`.
- `00433DC0` `get_obj`: `info`.
- `00433DE0` `do_commands`: none.
- `00433E20` `do_command`: `order`.
- `00433F20` `do_command_order`: `order`, `target`, `units`, `index`,
  `unit_num`, `maxY`, `maxX`, `minY`, `minX`, `i`, `totalX`, `totalY`,
  `adjustedXLocation`, `adjustedYLocation`.
- `00434290` `do_command_stop`: `order`.
- `004342E0` `do_command_pause`: `order`.
- `00434320` `do_command_work`: `order`, `target`, `units`, `index`,
  `unit_num`.
- `00434400` `do_command_move`: `order`, `target`, `units`, `index`,
  `unit_num`, `maxY`, `maxX`, `minY`, `minX`, `i`, `totalX`, `totalY`,
  `adjustedXLocation`, `adjustedYLocation`.
- `004348B0` `do_command_create`: `order`.
- `004348F0` `do_command_add_attribute`: `order`.
- `00434920` `do_command_give_attribute`: `order`.
- `00434A00` `do_command_formation`: `fCommand`, `unitNum`, `units`,
  `tempCount`, `i`, `tempY`, `tempX`, `distance`, `referenceUnit`,
  `adjustedXLocation`, `adjustedYLocation`.
- `00434D40` `do_command_ai_order`: `aiOrder`.
- `00434DC0` `do_command_group_ai_order`: `aiOrder`, `targetX`, `targetZ`,
  `targetY`.
- `00434EB0` `do_command_resign`: `order`.
- `00434F70` `do_command_add_waypoint`: `wOrder`.
- `00434FB0` `do_command_group_waypoint`: `order`, `p`.
- `00435020` `do_command_create_group`: `gCommand`.
- `00435060` `do_command_add_to_group`: `gCommand`.
- `004350A0` `do_command_remove_from_group`: `gCommand`.
- `004350E0` `do_command_destroy_group`: `gCommand`.
- `00435110` `duplicate_check_command_order`: `order`, `units`, `last_units`.
- `004351B0` `duplicate_check_command_stop`: `order`.
- `00435210` `close_check_for_duplicate_orders`: `order`.
- `00435260` `check_for_duplicate_orders`: `order`, `order_size`.
- `004352C0` `submit`: `order`, `order_size`.
- `00435320` `command_order`: `unit`, `unit_count`, `target`, `location_x`,
  `location_y`, `size`.
- `00435420` pointer `command_stop`: `unit`, `unit_count`, `size`.
- `004354F0` array `command_stop`: `playerID`, `unitID`, `numUnits`, `size`.
- `004355A0` `command_pause`: `playerID`, `unitID`, `numUnits`.
- `00435620` pointer `command_work`: `unit`, `unit_count`, `target`,
  `location_x`, `location_y`, `size`.
- `00435720` array `command_work`: `playerID`, `unitID`, `numUnits`,
  `targetID`, `targetPlayerID`, `xLoc`, `yLoc`, `size`.
- `00435810` pointer `command_move`: `unit`, `unit_count`, `target`,
  `location_x`, `location_y`, `size`.
- `00435900` array `command_move`: `playerID`, `unitID`, `numUnits`,
  `targetID`, `targetPlayerID`, `xLoc`, `yLoc`, `size`.
- `004359C0` `command_create`: `obj_catagory`, `player_id`, `location_x`,
  `location_y`, `location_z`.
- `00435A30` `command_add_attribute`: `player_id`, `attr_id`, `attr_amount`.
- `00435A80` `command_give_attribute`: `player_id`, `to_player_id`, `attr_id`,
  `attr_amount`.
- `00435AE0` `command_formation`: `unit`, `unitCount`, `formationID`, `size`.
- `00435BB0` `command_create_group`: `playerID`, `groupCommander`, `units`,
  `unitCount`, `range`.
- `00435C50` `command_add_to_group`: `playerID`, `groupCommander`, `newUnit`,
  `range`.
- `00435CD0` `command_remove_from_group`: `playerID`, `commander`, `unit`.
- `00435D40` `command_destroy_group`: `playerID`, `groupCommander`.
- `00435D90` `command_ai_order`: `playerID`, `issuer`, `recipient`, `orderType`,
  `target`, `targetOwner`, `targetX`, `targetY`, `targetZ`, `range`,
  `immediate`, `inFront`, `priority`, `temp_rec`.
- `00435EA0` `command_group_ai_order`: `playerID`, `issuer`, `recipient`,
  `recipient_count`, `orderType`, `target`, `targetOwner`, `targetX`,
  `targetY`, `targetZ`, `range`, `immediate`, `inFront`, `priority`, `size`.
- `00435FE0` `command_resign`: `player_id`, `comm_player_id`, `dropped`.
- `00436030` array `command_add_waypoint`: `playerID`, `recipient`,
  `waypoint`, `numWaypoints`.
- `004360D0` byte `command_add_waypoint`: `playerID`, `recipient`, `x`, `y`, `z`.
- `00436150` `command_group_waypoint`: `unit`, `unit_count`, `location_x`,
  `location_y`, `size`.

The report list preserves PDB spelling, including mixed camelCase and snake_case.
The PDB records reuse stack offsets in several functions. I did not force one
name across reused lifetimes.

## Recovered names

I restored names when the PDB record mapped to the declaration and use:

- Constructor and communication names: `gworld`, `com_handler`, `com_hand_in`.
- Command packet parameters: `order`, `fCommand`, `aiOrder`, `wOrder`, and
  `gCommand`.
- Formation and group names: `unitNum`, `referenceUnit`, `tempCount`, `tempX`,
  `adjustedXLocation`, `adjustedYLocation`, `playerID`, `groupCommander`,
  `newUnit`, `range`, and `commander`.
- Order, target, coordinate, priority, and waypoint names from all sender
  procedures, including `unit_count`, `targetPlayerID`, `targetID`, `xLoc`,
  `yLoc`, `targetOwner`, `inFront`, `priority`, `waypoint`, and
  `numWaypoints`.
- The exact PDB spelling `obj_catagory` remains unchanged from the record.

The following cleanup names are descriptive names, not recovered original names.
They replace decompiler temporaries where the PDB has no reliable declaration
record: `object`, `unit`, `other_index`, and `other_unit` in the move paths.
No new variable or parameter was added.

Unresolved mappings remain for stack-slot or register-only temporaries without a
reliable PDB declaration. Examples include `count`, `cnt`, `width`, `height`,
`alternate`, `selector`, `n`, `last_n`, `order_y`, packet `ids`, and packet
locals named `cmd`. I left their types, scope, declaration order, and storage
unchanged. The PDB does not prove original names for these locals.

## Constants, resources, and comments

- No resource lookup occurs in `src/Command.cpp`.
- No resource ID was investigated. No DLL path, language, ID, or payload applies.
- No shared resource mapping request is needed.
- No new constant or macro was added.
- Existing command tags, `DAT_0056f4d8`, `DAT_0056f4e0`, `DAT_0056f4e8`,
  `0x2c6`, `0x262`, and `0x20A` remain unchanged. The coordinate sentinel is
  now written as `-1.0f`; its original bit pattern is `0xBF800000`.
- No comments were added.

## Type and code-generation risks

The source edits change identifier spelling, whitespace, line wrapping, brace
placement, and the spelling of the coordinate sentinel. The normalized token
review found equal token streams after identifier normalization. The sentinel
value, types, layouts, scopes, storage, calls, evaluation order, and control
flow remain unchanged.
The parameter names in the unedited header remain unchanged.

The original source uses reused stack slots. The cleanup keeps separate source
declarations where they existed. Compiler output still needs final validation.

## Evidence inputs

- Original executable:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/_original_empiresx_from_beta_that_was_decompiled.exe`
  SHA256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Preserved PDB:
  `C:/Projects/my_decomps/aoe1_attempt3/orig/age1_x1.pdb`.
- Baseline object:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/Command.obj`
  SHA256 `3fbfa19e5215d05bdb2082a3c7c0c95fbe72087b32ae76c706835fb9144365ff`.
- Baseline executable:
  `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe`
  SHA256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- PDB scoped evidence:
  `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.

## Shared requests and validation

- Header request: none.
- Resource mapping request: none.
- Unresolved question: final compiler output for the renamed and reformatted
  module remains untested.

Compilation, matching, audits, validation tools, builds, tests, and games were
not run. Only permitted evidence extraction, Git review, token review, and
`git diff --check` were run.
