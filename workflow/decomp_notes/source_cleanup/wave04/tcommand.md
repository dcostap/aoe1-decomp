# `src/tcommand.cpp` cleanup report

## Scope and hashes

- Module: `src/tcommand.cpp`
- Header owner: owner 25 owns `include/tcommand.h`. This worker did not edit it.
- Base commit from `git rev-parse`: `c22ba4258c45b1178181e185d60a3b09a1add617`
- Base source SHA-256 from Git: `8dd89f30402634a6bb4fe47fc8a9b57055b3e10162a186841b71fe20f661e899`
- Final source SHA-256: `6f8af1ccdf56cf445f74cd2880d4c7df18d875c9df2136a59fbf2cc57c95b2a7`
- Delivery history: commit `47c1f1ba9015c9bd92c144a13b2555694ed0976e` contains `src/tcommand.cpp` and the initial version of this report. The current commit contains this report correction only.
- Changed files:
  - `src/tcommand.cpp`
  - `workflow/decomp_notes/source_cleanup/wave04/tcommand.md`

The source keeps one natural owner and the original source order. The registry
contains 42 normal owners for this module. No registry or header change is part
of this commit.

## Evidence identity

- Original executable: `C:/Projects/my_decomps/aoe1_attempt3/orig/empiresx.exe`, SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
- Registry: `C:/Projects/my_decomps/aoe1_attempt3/config/functions/src/tcommand.cpp.json`.
- Preserved baseline report: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/report.json`, SHA-256 `fddd62868626e21ec7282183fa1cf84ad5b0b14fc719c8830a266d6ed0f155b3`.
- Scoped PDB records: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`, SHA-256 `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.
- PDB source map: `C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`.
- Original assembly and decompiler listing: `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tcommand.cpp.asm` and `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/tcommand.cpp.decomp`.
- Pinned compiler headers read before review: `C:/Program Files (x86)/DevStudio/VC/include/STDIO.H`, `STDLIB.H`, `WINDOWS.H`, and `WINUSER.H`.

The registry and PDB records were compared with a read-only Python query. All
42 registry VAs have a PDB record. All 42 records name `this` in `ecx`. No
record has a function static. The adjacent compiler-generated destructors at
`00509740` and `00509760` have no source body and remain outside this owner.

## Original-name recovery coverage

The table lists every assigned normal owner. Names in the last column come from
the procedure-scoped PDB record. The list includes parameters and named locals.
Each row also has the register symbol `this` in `ecx`.

| VA | Function and binary range | PDB source span | PDB parameters and locals |
| --- | --- | --- | --- |
| `00509720` | `TRIBE_Command::TRIBE_Command`, `00509720-00509740` | 56-57 | `world`, `com_hand` |
| `00509770` | `TRIBE_Command::do_command`, `00509770-0050990C` | 62-125; fragment `00509859` | `order` |
| `00509910` | `do_command_tribe_create`, `00509910-0050997C` | 130-139 | `order` |
| `00509980` | `do_command_make`, `00509980-00509AEE` | 143-205 | `order`, `work_name`, `work_target`, `work_type`, `progress` |
| `00509AF0` | `do_command_research`, `00509AF0-00509C5C` | 209-251 | `order`, `work_name`, `work_target`, `work_type`, `progress` |
| `00509C60` | `do_command_build`, `00509C60-00509E02` | 256-331 | `order`, `unitNum`, `blockingObject`, `placementResult` |
| `00509E10` | `do_command_build_wall`, `00509E10-0050A004` | 337-450 | `order`, `unitNum`, `first_wall`, `units` |
| `0050A010` | `place_line_of_walls`, `0050A010-0050A133` | 456-503 | `player`, `master_obj`, `unique_id`, `x1`, `y1`, `x2`, `y2`, `first_wall`, `y`, `x`, `world_y`, `world_x`, `y_skip`, `x_skip` |
| `0050A140` | `do_command_explore`, `0050A140-0050A1C8` | 508-527 | `order`, `i` |
| `0050A1D0` | `do_command_game`, `0050A1D0-0050A48C` | 531-665; fragment `0050A465` | `order`, `fileName` |
| `0050A490` | `do_command_cancel_build`, `0050A490-0050A4B1` | 671-683 | `order` |
| `0050A4C0` | `do_command_attack_ground`, `0050A4C0-0050A509` | 688-703 | `order` |
| `0050A510` | `do_command_give_attribute`, `0050A510-0050A695` | 708-770 | `order`, `cost`, `tribute_amount` |
| `0050A6A0` | `do_command_trade_attribute`, `0050A6A0-0050A6DB` | 776-789 | `order` |
| `0050A6E0` | `do_command_repair`, `0050A6E0-0050A728` | 795-815 | `order` |
| `0050A730` | `do_command_unload`, `0050A730-0050A7A9` | 820-846 | `order` |
| `0050A7B0` | `do_command_queue`, `0050A7B0-0050A7F0` | 852-867 | `order` |
| `0050A7F0` | `command_make`, `0050A7F0-0050A85F` | 872-900 | `unit`, `obj_id` |
| `0050A860` | `command_make`, `0050A860-0050A8C1` | 906-938 | `playerID`, `buildingID`, `objID`, `uniqueID` |
| `0050A8D0` | `command_research`, `0050A8D0-0050A93F` | 944-972 | `unit`, `tech_id` |
| `0050A940` | `command_research`, `0050A940-0050A9A1` | 978-1009 | `playerID`, `buildingID`, `techID`, `uniqueID` |
| `0050A9B0` | `command_build`, `0050A9B0-0050AA88` | 1015-1060 | `unit`, `list_num`, `obj_id`, `location_x`, `location_y` |
| `0050AA90` | `command_build`, `0050AA90-0050AB30` | 1066-1110 | `playerID`, `unitID`, `numUnits`, `objectID`, `xLoc`, `yLoc`, `uniqueID` |
| `0050AB30` | `command_build_wall`, `0050AB30-0050AC64` | 1116-1176 | `unit`, `list_num`, `obj_id`, `x1`, `y1`, `x2`, `y2`, `size` |
| `0050AC70` | `command_explore`, `0050AC70-0050ACFC` | 1182-1221 | `playerID`, `unitID`, `numUnits`, `x`, `y` |
| `0050AD00` | `command_allied_victory`, `0050AD00-0050AD67` | 1227-1250 | `player`, `flag` |
| `0050AD70` | `command_relation`, `0050AD70-0050ADE3` | 1256-1281 | `player`, `target_player`, `relation` |
| `0050ADF0` | `command_game_speed`, `0050ADF0-0050AE37` | 1287-1308 | `gamespeed` |
| `0050AE40` | `command_save_game`, `0050AE40-0050AE7D` | 1314-1334 | none beyond `this` |
| `0050AE80` | `command_inventory`, `0050AE80-0050AEE0` | 1340-1363 | `player`, `inventory`, `amount` |
| `0050AEE0` | `command_upgrade_town`, `0050AEE0-0050AF29` | 1369-1390 | `player` |
| `0050AF30` | `command_quick_build`, `0050AF30-0050AF79` | 1396-1417 | `quick_build` |
| `0050AF80` | `command_shared_los`, `0050AF80-0050AFC9` | 1423-1444 | `player` |
| `0050AFD0` | `command_cancel_build`, `0050AFD0-0050B016` | 1450-1471 | `unit` |
| `0050B020` | `command_attack_ground`, `0050B020-0050B0C2` | 1477-1519 | `unit`, `list_num`, `x`, `y` |
| `0050B0D0` | `command_cheat`, `0050B0D0-0050B126` | 1525-1547 | `player`, `cheat_code` |
| `0050B130` | `command_give_attribute`, `0050B130-0050B18C` | 1553-1579 | `player_id`, `to_player_id`, `attr_id`, `attr_amount`, `attr_cost` |
| `0050B190` | `command_trade_attribute`, `0050B190-0050B227` | 1585-1625 | `unit`, `list_num`, `attribute` |
| `0050B230` | `command_trade_attribute`, `0050B230-0050B283` | 1632-1660 | `unitID`, `playerID`, `attribute` |
| `0050B290` | `command_repair`, `0050B290-0050B32A` | 1666-1716 | `unit`, `unit_count`, `target` |
| `0050B330` | `command_unload`, `0050B330-0050B3D2` | 1722-1764 | `unit`, `list_num`, `x`, `y` |
| `0050B3E0` | `command_queue`, `0050B3E0-0050B443` | 1770-1796 | `bldg_obj`, `train_id`, `train_count` |

The recovery edits restore the PDB spellings in the source definitions. They
include mixed styles such as `unitNum`, `fileName`, `playerID`, and `obj_id`.
The following changes are direct PDB recoveries:

- `cmd` becomes `order` in the dispatch and command handlers.
- `work_state` becomes `work_type` in both work-status handlers.
- `count`, `foundation`, and `ids` become `unitNum`, `first_wall`, and `units` in `do_command_build_wall`.
- The wall-placement parameters become `master_obj`, `unique_id`, `x1`, `y1`, `x2`, `y2`, and `first_wall`. The two world-coordinate locals become `world_x` and `world_y`.
- `file_name` becomes `fileName`. `v_this`, `v_ids`, and `v_count` become the descriptive `command`, `ids`, and `count` names in `do_command_unload`.
- `v` becomes `tribute_amount` in `do_command_give_attribute`.
- Packet-builder parameters restore the PDB spellings listed in the table. This includes `playerID`, `buildingID`, `objID`, `uniqueID`, `unitID`, `numUnits`, `objectID`, `xLoc`, `yLoc`, `quick_build`, and `bldg_obj`.

PDB stack homes `x` and `y` in `place_line_of_walls` overlap other
parameter homes. The source does not force those records into new declarations.
The current `temp` swap local remains. Other locals absent from the PDB record
also remain in their existing source form. Those names are not claimed as
original names.

## Behavior and presentation review

The cleanup changes identifier spelling, brace placement, and local presentation
only. It keeps the original source order, casts, types, scopes, storage,
expressions, literals, packet layout, call targets, and evaluation order.

- The command dispatch still selects the same command values and fallback call.
- Work, build, wall, explore, game, attribute, repair, unload, and queue handlers
  keep their existing branches and virtual calls.
- Variable packet cursors and packet sizes remain unchanged.
- The wall placement loop keeps its coordinate swap and skip calculations.
- The out-of-sync path keeps its save name, cleanup calls, dialog ID, and order.

The existing comment about `draw_system` and `quick_build` remains. No new source
comment was needed.

## Constants and resource evidence

No numeric constant or enum was replaced. The source keeps command codes,
attribute values, action values, notification values, dialog dimensions, and
original debug line values.

The out-of-sync dialog passes string ID `0x0966` to
`TEasy_Panel::popupOKDialog(long, char*, int, int)`. The lookup path is:

1. `src/Panel_ez.cpp` calls the virtual panel `get_string` path.
2. `TRIBE_Game::get_string` in `src/tribegam.cpp` calls `LoadStringA(StringTableX, 0x0966, ...)`.
3. On a miss, it calls `RGE_Base_Game::get_string`.
4. `RGE_Base_Game::get_string` calls `LoadStringA(StringTable, 0x0966, ...)`.
5. `RGE_Base_Game::setup` loads `language.dll`. `TRIBE_Game::setup` loads
   `languagex.dll` by default, or the DLL named by `STRING=`.

The inspected resources are:

- `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260915T131345059786Z/language.dll`, SHA-256 `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`, language `0x0409`, ID `0x0966`, exact text `You were dropped from the game because of a sync error. Your network connection may have been lost.`
- `C:/Projects/my_decomps/aoe1_attempt3/build/runtime/original-20260915T131345059786Z/languagex.dll`, SHA-256 `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`, ID `0x0966` missing.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`, SHA-256 `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`, ID `0x0966` missing.

The extraction outputs are `build/tcommand_resource_language.json`,
`build/tcommand_resource_languagex.json`, and
`build/tcommand_resource_pinned_languagex.json` in this worktree.

The purpose is known from the dialog call and the fallback path. The base DLL
supplies the text. The expansion DLLs do not. Root approved the direct source
substitution with `STRING_ID_ERROR_SYNC`.

## Code-generation risks and unresolved mappings

The source changes do not alter ABI symbols, public types, layouts, packet
records, declaration scope, storage duration, field offsets, literals, control
flow, or calls. Parameter and local spelling can alter debug names and line
records. Brace movement can alter line records. No line-dependent macro occurs
in this module.

The PDB does not provide reliable names for many optimized locals. The source
leaves those declarations unchanged. This includes `player_offset`,
`category_offset`, `building`, `placement`, `obj`, `idp`, `n`, `dy`, `dx`,
`temp`, packet allocation locals, and cursor locals. No reused stack slot was
forced into a declaration.

The registry marks the existing function statuses. This cleanup does not claim a
new matching or logic result. The older module note and registry disagree about
the `0050A6A0` status; this worker did not change either file.

## Shared-file requests

### Header request to owner 25

Please review declaration-only parameter names in `include/tcommand.h`. The
source worker did not edit the header. Use the PDB names from the table for the
following declarations:

- Constructor: `world`, `com_hand`.
- Private handlers: `order` for every packet parameter; `player`, `master_obj`,
  `unique_id`, `x1`, `y1`, `x2`, `y2`, and `first_wall` for
  `place_line_of_walls`.
- `command_give_attribute`: `player_id`, `to_player_id`, `attr_id`,
  `attr_amount`, `attr_cost`.
- Object overloads: `unit`, `obj_id`; `unit`, `tech_id`; `unit`, `list_num`,
  `obj_id`, `location_x`, `location_y`; `unit`, `list_num`, `obj_id`, `x1`,
  `y1`, `x2`, `y2`; `unit`, `list_num`, `x`, `y`; `unit`, `unit_count`,
  `target`; `unit`, `list_num`, `x`, `y`; and `bldg_obj`, `train_id`,
  `train_count`.
- Integer overloads: `playerID`, `buildingID`, `objID`, `uniqueID`;
  `playerID`, `buildingID`, `techID`, `uniqueID`; `playerID`, `unitID`,
  `numUnits`, `objectID`, `xLoc`, `yLoc`, `uniqueID`; `playerID`, `unitID`,
  `numUnits`, `x`, `y`; and `unitID`, `playerID`, `attribute`.
- Scalar commands: `player`, `flag`; `player`, `target_player`, `relation`;
  `gamespeed`; `player`, `inventory`, `amount`; `player`; `quick_build`;
  `player`; `unit`; and `player`, `cheat_code`.

These names do not change the ABI. The request is non-blocking for this source.

### Resource mapping provenance from root

Root provided and approved this base-language mapping in the root-owned
`include/resource_ids.h` import:

```cpp
#define STRING_ID_ERROR_SYNC 0x0966
```

Evidence: the out-of-sync path passes `0x0966` to the string overload of
`popupOKDialog`; the base `language.dll` supplies the exact English text listed
above; the expansion DLLs miss the ID; and the fallback order is established in
`TRIBE_Game::get_string` and `RGE_Base_Game::get_string`. This is a new cleanup
name, not a recovered original macro. This worker did not edit the resource
header. The source now uses `STRING_ID_ERROR_SYNC` at the same call site. The cast,
buffer, call, arguments, order, control flow, and fallback remain unchanged.

## Validation status

Compilation, matching, audits, validation, and tests were not run. No compiler,
build, matching, audit, validation, test, or game command was run for this
assignment. The complete source diff was reviewed. `git diff --check` passed.

## Correction history

- Initial delivery: commit `47c1f1ba9015c9bd92c144a13b2555694ed0976e` contained the source cleanup and the initial report.
- This correction updates the delivery-history entry in this report only.
