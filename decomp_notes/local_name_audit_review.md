# Review of eight local-name findings

## Scope and evidence

This is a sequential source review, not a source edit or a new build validation.
The review follows the eight functions in the [trial report](local_name_audit_trial.md).
The original executable supplies instruction behavior. The original PDB supplies reference names and types.

Pinned inputs:

- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
- `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/age1_x1.pdb`.

The trial's original and rebuilt records remain under `build/probes/local-name-trial/final/`.
The original instruction listings remain under `build/probes/local-name-trial/run-01/original-review/`.
The trial proved local byte agreement for those objects. This review does not repeat that check for the current tree.
Concurrent action-module and header changes remain outside this assignment.
Approval covers identifier mappings only, not current types, source structure, or complete function semantics.

In each section, a mapping means current source spelling to recovered original spelling.
`S` means ESP at function entry. Instruction addresses refer to the original executable.
CodeView coordinates do not always equal entry-ESP coordinates.

## Completed review

| Order | Function | Supported original-name substitutions | Main limit |
| --- | --- | ---: | --- |
| 1 | `loadConstructionPlan` | 8 | Unused `y` collision; buffer declarations differ |
| 2 | `DoChecksum` | 3 | Preserve checksum positions |
| 3 | `RGE_Master_Static_Object::save` | 6 | Preserve short widths and save order |
| 4 | `setupSinglePlayerPlayers` | 3 | Preserve conditional initialization and player replacement |
| 5 | `scenario_load` | 4 | Row-alias collision; retain narrow counter views |
| 6 | `preclean_elevation` | 14 | Twelve correct descriptive aliases have recorded original spellings |
| 7 | `load_map` | 3 | Original row names cannot be assigned to branches reliably |
| 8 | `get_border_type` | 8 | Shared storage resolved by direct use and lifetime review |
| Total | Eight functions | 49 | No source edits applied |

The total includes original-name recovery for descriptive aliases. It does not mean 49 behavior defects or wrong bindings.
Seventeen substitutions came from the trial's different-spelling findings.
Four mappings needed manual review beyond the automatic unknown result:

- `loadConstructionPlan`: `itemName` to `name`, despite the buffer-size difference.
- `scenario_load`: stored row `h` to `y`, and stored column `y` to `x`, without changing their current types.
- `get_border_type`: `ter_bot_rgt` to `ter_bot_lft`, despite the shared `yMax` location.

The positive-coordinate top-right mapping in `get_border_type` now has a completed lifetime review.
The original `load_map` row-name assignment remains unresolved; descriptive row names are a separate option.

## 1. `ConstructionAIModule::loadConstructionPlan` — `0040B690`

Owner: `src/aiconmod.cpp`.
Verdict: seven scalar names need recovery. The current coordinate and size names identify the wrong values.

| Current name | Original name | Scan field | Entry-ESP location |
| --- | --- | ---: | --- |
| `z` | `x` | 1 | `S - 0x16c` |
| `x` | `y` | 2 | `S - 0x170` |
| `zSize` | `z` | 3 | `S - 0x168` |
| `ySize` | `xSize` | 4 | `S - 0x158` |
| `item_arg_5` | `ySize` | 5 | `S - 0x154` |
| `item_arg_6` | `zSize` | 6 | `S - 0x164` |
| integer `xSize` | `id` | 7 | `S - 0x15c` |

At `0040B7D7`, ESP is `S - 0x184`. The following address instructions include pending argument pushes.
The scan at `0040B80C` uses `%f %f %f %f %f %f %d %s `.
`0040B81E`, `0040B830`, and `0040B846` store the three reference-adjusted coordinates back into the same locations.
The `lot` call at `0040B84A` receives the first two adjusted coordinates.
The constructor call at `0040B89D` receives all six floats, then the integer, then the name address.
Its original decorated symbol is `??0ConstructionItem@@QAE@MMMMMMHPAD@Z`.
The reviewed declaration and body in `include/aiconitm.h` and `src/aiconitm.cpp` support the argument roles.

The six parameter names and both comment-character names already agree with the original records.

### Declaration collision and remaining limits

The unused source declaration `float y` is not the live original `y`.
The live original `y` occupies the location currently named `x`.
A later rename must free that spelling without removing or moving the unused declaration.
`unused_y` is a possible cleanup name for that declaration, not a recovered original name.

`itemName` has the original `name` address: `S - 0x14c`.
The scan's eighth destination and the constructor's last argument both use that address.
Thus, its original name is supported by use, although the types differ: current `char[60]`, original `char[64]`.
A name-only edit can recover `name`; it must not copy the original buffer size.

Current `temp` starts four bytes before the original line buffer.
The original buffer is `char[256]` at `S - 0x10c`; the source uses `temp + 4` within `char[260]`.
The `sprintf`, `fopen`, `fgets`, and scan calls use the original line-buffer address.
Keep the declaration and `+4` expressions unchanged in a naming edit.
Buffer structure needs a separate review.

The records do not establish original names for `fp`, `plan`, `saved_plan`, `item`, or `prev`.
Their uses do not authorize invented original-name claims.

### Approved naming scope

Recover the seven scalar names and `name` as one coordinated identifier change.
Give the unused `y` a clearly separate cleanup name.
Preserve declarations, types, buffer sizes, scopes, expressions, argument order, and list operations.
Do not turn the unused declaration into the active coordinate or remove it.
Run fresh module code checks and a debug-name check after any later source edit.

## 2. `RGE_Communications_Synchronize::DoChecksum` — `00433290`

Owner: `src/com_sync.cpp`.
Verdict: confirmed three-name cycle. This is a source-name error, not evidence of a wire-order error.

| Current name | Original name | Entry-ESP location | Output position |
| --- | --- | --- | ---: |
| `cs4` | `cs2` | `S - 0x108` | 1 |
| `cs2` | `cs3` | `S - 0x10c` | 2 |
| `cs3` | `cs4` | `S - 0x104` | 3 |

The fixed frame between calls is `S - 0x11c`.
The address instructions at `00433300`, `00433307`, and `0043330C` establish the three output destinations.
At `0043330C`, one argument push is pending.
The stores at `00433318`, `0043331C`, and `00433320` initialize those same three locations to zero.
`00433324` calls the original `GetWorldChecksums` symbol with output positions 1, 2, and 3.

At `004333C3` through `004333DE`, the original loads and pushes preserve these values for `Add` at `004333ED`.
`004333F2` through `0043340A` preserve the same order for `SendChecksumMessage`.
The source currently spells that order `cs4, cs2, cs3` in all three calls.
After recovery, each call will spell it `cs2, cs3, cs4`, without moving an argument.

Supporting declarations and bodies are in `include/basegame.h`, `src/basegame.cpp`, and `src/com_hand.cpp`.
They identify the output roles as the new, position, and action checksums.
The original call order and the PDB locations establish the binding; the existing parameter names supply supporting descriptions.

`turn`, `tmp`, and `this` already agree with the original records.
The records do not establish original names for the other register-held source locals.

### Approved naming scope

Apply the three substitutions together within this function only.
Keep each `long` declaration, zero initializer, and argument expression in its current position.
Do not change checksum numbering, message fields, computation, or transmitted order.
No declaration collision or scope change is needed.

## 3. `RGE_Master_Static_Object::save` — `004536D0`

Owner: `src/m_s_obj.cpp`.
Verdict: confirmed six misplaced names. The save values and order agree with the original executable.

| Current name | Original name | Producing member | Entry-ESP location | Write call |
| --- | --- | --- | --- | --- |
| `temp_death_sprite` | `temp_sprite` | `sprite` at `+0x18` | `S - 0x1c` | `004537D5` |
| `temp_undead_sprite` | `temp_death_sprite` | `death_sprite` at `+0x1c` | `S - 0x18` | `004537E5` |
| `created_sound_num` | `temp_undead_sprite` | `undead_sprite` at `+0x20` | `S - 0x14` | `004537F5` |
| `temp_sprite` | `created_sound_num` | `created_sound` at `+0x40` | `S - 0x10` | `0045386E` |
| `death_sound_num` | `selected_sound_num` | `selected_sound` at `+0x3c` | `S - 0x8` | `00453BC4` |
| `selected_sound_num` | `death_sound_num` | `death_sound` at `+0x44` | `S - 0x4` | `00453BD4` |

The fixed frame between calls is `S - 0x30`.
The six initializers store the `-1` sentinel into distinct locations.
The member loads and stores at `00453703` through `00453752` establish the six producing values.
Sound IDs come from member offset `0xc`; sprite IDs come from member offset `0x72`.
The declarations in `include/m_s_obj.h` support the object-member names.
Every listed write consumes two bytes from the same location that received the corresponding ID.
After ID selection, none of these six locations receives another value before its final use.

`outfile`, `name_size`, and `this` already agree with the original records.
Keep the `short` declarations and two-byte writes, despite the compiler's four-byte local stores.
Keep the signed narrowing of `name_size`, its increment, and its later write length.
Do not change save-field order or the damage-sprite write widths.

### Other source names

The records do not recover names for the pointer aliases and loop counters.
Three existing aliases have misleading descriptions:

- `soundPtr` points to `attribute_flag`, not sound data.
- `selectedProb` points to `attribute_amount_held`, not selection probability.
- `selected` points to `attribute_type_held`, not a selected sound.

`00453AE9` through `00453B44` establish those three attribute-array addresses and their increments.
Possible later cleanup names are `attribute_flags`, `attribute_amounts`, and `attribute_types`.
These would be new descriptive names, not recovered original names.
The compiler reuses the `outfile` argument home for the flag pointer after retaining the descriptor in ESI.
Do not infer a single whole-function lifetime from the original parameter's debug location.

### Approved naming scope

Recover the six original scalar names together within this function.
No new scope, declaration, or type is needed.
Keep the member-read order, null checks, sentinels, write addresses, and write order unchanged.
Handle the three descriptive aliases separately from original-name recovery.

## 4. `TribeMPSetupScreen::setupSinglePlayerPlayers` — `004A5210`

Owner: `src/scr_mps.cpp`.
Verdict: recover three names, including the different-spelling finding for the color.

| Current name | Original name | Producing value | Entry-ESP location |
| --- | --- | --- | --- |
| `first_any_civ` | `first_any_player` | Scenario player index | `S - 0xc` |
| `first_any_color` | `first_any_civ` | `Get_player_Civ` result | `S - 0x8` |
| `first_any_color_index` | `first_any_color` | Scenario player index plus one | `S - 0x4` |

The fixed frame between calls is `S - 0x1c`.
The original initializes all three locations to `-1` at `004A5237` through `004A523F`.
It selects the first active scenario player whose `Get_player_Type` result equals `1`.
With one pending argument push, `004A52B2` stores ESI at the original `first_any_player` location.
After `Get_player_Civ` returns, `004A52BB` stores EAX at the original `first_any_civ` location.
`004A52BF` stores EDI, formed as the scenario player index plus one, at `first_any_color`.

`004A52C3` retains the selected player index in EDI.
The comparison at `004A5308` and the `setScenarioPlayer` call at `004A5370` consume that index.
`004A5382` consumes the saved civilization; `004A5394` consumes the saved color.
These distinct uses establish all three bindings, not just matching integer storage.
The current setters receive the correct values. Do not change their argument order or values.

`this` already agrees with the original records.
The original records do not name the register-held loop counters or short-lived getter results.

### Approved naming scope

Recover all three names together within the function.
Keep the three `int` declarations and the conditional `-1` initializers in their current positions.
Keep the active-player tests, scenario-index range, player replacement, and random branch unchanged.
No declaration collision or new scope is needed.

## 5. `RGE_Map::scenario_load` — `00455FF0`

Owner: `src/map.cpp`.
Verdict: confirmed width/height mislabeling. Instruction use also resolves the two narrow loop-coordinate records.

| Current name | Original name | Value role | Entry-ESP location |
| --- | --- | --- | --- |
| `map_height` | `w` | First dimension read; first `new_map` argument | `S - 0x4` |
| `w` | `h` | Second dimension read; second `new_map` argument | `S - 0x8` |
| outer `long h` | `y` | Row counter; its low word is the row coordinate | `S - 0xc` |
| inner `long y` | `x` | Column counter; its low word is the column coordinate | `S - 0x10` |

`00455FF9` and `0045600B` form the two dimension addresses.
`00456018` through `00456027` pass the second read as height and the first read as width.
The first source spelling `map_height` is therefore misleading, not merely a different abbreviation.

Before the loops, `00456033` initializes the outer counter at `S - 0xc`.
The loop then saves two more registers, making ESP `S - 0x24` between read calls.
`00456043` initializes the inner counter at `S - 0x10`.
`0045604D` sign-extends the outer counter's low word and scales it to select a row pointer.
`00456086` scales the inner coordinate by the tile size for access within that row.
`004560C4` through `004560CC` increment and sign-extend the inner counter.
`004560DF` through `004560E8` increment and sign-extend the outer counter.
These uses support original `x` and `y`, although the source's stored counters are `long`, not the PDB's `short`.

### Declaration collision and preserved behavior

Recovering dimension `h` requires renaming the current outer counter `h` in the same edit.
Recovering inner counter `x` also requires renaming the existing `short x` row alias.
That alias is a narrowed copy of the row counter, not the original column `x`.
`row_index` is a supported cleanup name for it, not an original PDB name.
Otherwise, the new `x` references inside its scope would bind to the wrong declaration.

Keep both stored counters as `long` and keep every narrowing cast and integer projection.
The original uses `map_height` for both loop bounds. Do not replace the inner bound with `map_width`.
The original reads `overlay_info` without applying it. Do not add an overlay assignment.

`infile`, `height_info`, `overlay_info`, and `this` already agree with the original records.
`zone_terrain` is an unused original parameter; leave its name and signature unchanged.
The original debug records give both `zone_terrain` and `terrain_info` coordinate `+8`.
However, `00456053` addresses `terrain_info` at entry-ESP `+4`, after the descriptor was retained in EBP.
This is another positive-local coordinate case; a raw debug offset is not a whole-function physical address.
The one-byte read and terrain-field assignment support the current `terrain_info` name.
The original records do not name `height_count`, `i`, or the narrowed row alias.

### Approved naming scope

Recover `w`, `h`, `x`, and `y` together, while giving the row alias a separate cleanup name.
Keep types, declarations, scopes, read order, loop bounds, narrowing, and final terrain calls unchanged.
The counter-name approval comes from instruction use, not from ignoring the audit's type mismatch.

## 6. `RGE_Map::preclean_elevation` — `004564E0`

Owner: `src/map.cpp`.
Verdict: confirmed index swap. Twelve other spellings have recoverable original names but correct directional meanings.
Directions here refer to tile-array row and column positions, not screen space.

| Current name | Original name | Entry-ESP location | Role |
| --- | --- | --- | --- |
| `index2` | `index1` | `S - 0x40` | Outer row index |
| `index1` | `index2` | `S - 0x44` | Inner column index |

The fixed frame is `S - 0x58`.
`00456542` loads `y1`; `00456575` stores it at the original `index1` location.
`0045658D` stores the starting column at the original `index2` location.
`00456591` selects a row with the outer index; `00456594` adds the starting column's byte offset.
`00456868` through `0045687A` increment the column and tile pointer.
`00456892` through `0045689D` increment the row.
These uses confirm both original index names throughout their loop lifetimes.

### Different spellings with established original names

| Current name | Original name | Entry-ESP location | Original value or use |
| --- | --- | --- | --- |
| `offset_northwest` | `offset1` | `S - 0x28` | `-1 - width` |
| `offset_north` | `offset2` | `S - 0x24` | `-width` |
| `offset_northeast` | `offset3` | `S - 0x1c` | `1 - width` |
| `offset_southeast` | `offset5` | `S - 0x14` | `width + 1` |
| `offset_southwest` | `offset7` | `S - 0x8` | `width - 1` |
| `northwest` | `place1` | `S - 0x2c` | Northwest height is greater |
| `northeast` | `place3` | `S - 0x20` | Northeast height is greater |
| `east` | `place4` | `S - 0x38` | East height is greater |
| `southeast` | `place5` | `S - 0x18` | Southeast height is greater |
| `south` | `place6` | `S - 0x34` | South height is greater |
| `southwest` | `place7` | `S - 0xc` | Southwest height is greater |
| `west` | `place8` | `S - 0x30` | West height is greater |

`004564EC` through `00456519` construct the five stored offsets from the narrowed map width.
`004565D4` through `0045670F` establish the corresponding neighboring-cell tests and stored flags.
`00456751` through `00456851` consume those flags and offsets for the matching neighbor writes.
The current directional descriptions are correct. They are not evidence of shifted neighbor values.
Original-name recovery should still restore the twelve PDB spellings without changing the expressions.

The full original procedure record contains no `place2`, `offset6`, or ordinary register-variable names.
Do not invent those names from the numbering pattern.
Original names remain unknown for `width`, `offset_south`, `north`, `tile`, `tile_byte`, `elevation`, and `conflict`.
The rebuilt `width` record at `S - 0x10` has no original counterpart.
`tile_byte` contains the decoded height in the source, not a complete packed tile byte.
`tile_height` would be a possible descriptive cleanup name, not a recovered original name.

All five parameter names, `change_flag`, and `this` already agree with the original records.
Keep the short offsets and flags, repeated boundary expansion, modification order, and repeat-until-unchanged loop.

### Approved naming scope

Swap the two index spellings together and recover the twelve recorded offset and flag spellings.
No declaration collision requires a new name or scope.
Do not change neighbor directions, offset arithmetic, height comparisons, or boundary expansion.
Leave unrecorded numbered names unknown.

## 7. `RGE_Map::load_map` — `004579C0`

Owner: `src/map.cpp`.
Verdict: confirmed two dimension names and the modern-format column name. The original row-name assignment remains ambiguous.

| Current name | Original name | Entry-ESP location | Lifetime |
| --- | --- | --- | --- |
| `map_height` | `w` | `S - 0x10` | Dimension reads and `new_map` call |
| `w` | `h` | `S - 0x14` | Dimension reads and `new_map` call |
| modern-branch `int y` | `x` | `S - 0x1c` | Per-tile read loop |

`004579D8` forms the first dimension address before the four saved-register pushes.
After those pushes, ESP is `S - 0x2c` between calls.
`004579F2` forms the second dimension address.
`004579FF` through `00457A0E` preserve width then height for `new_map`.

In the modern-format branch, `00457AB2` initializes the column counter at `S - 0x1c`.
`00457B82` through `00457BA2` reload, increment, store, and compare it with `map_width`.
The tile pointer advances by `0x18` at the same loop boundary.
This independently supports the original `x` binding for that branch's current `y`.

### Shared row location: not approved as a recovered name

The original PDB records both `int index1` and `int y` at `S - 0x18`.
The source declares a separate `long h` in each format branch.
The modern branch initializes and increments that location at `00457AA2` and `00457BB4`.
The old-format branch initializes and increments it at `00457BE2` and `00457C1C`.
Both values select a row and compare with `map_height`.
An earlier allocation temporary also uses the location at `00457A39`.

The original records supply no lexical block or live-range information to distinguish the two row names.
The likely assignment is modern `y` and old-format `index1`, but that is a hypothesis, not approved recovery.
Keep that original-name assignment unresolved.
`row_index` is a supported descriptive cleanup name for each branch's row counter.
It does not require changing the current `long` types or merging the declarations.

The old-format column counter runs in ECX at `00457BEB` through `00457C10`.
Its original name is not established by the single stack record for `x` in the modern branch.
If renamed later, `column_index` is a descriptive option, not a recovered original name.
Do not replace every `y` token in both branches with `x` and claim both as recovered.

`infile`, `c`, and `this` already agree with the original records.
For `c`, `00457AEE` forms entry-ESP `+4`; its CodeView coordinate is `+8`.
The original retains the input descriptor in EDI before reusing its argument home for these byte reads.
Keep that distinction between the parameter's entry use and the later local use.
Original names remain unknown for `old_zones`, `zones`, and the tile pointer.

### Approved naming scope

Recover dimension `w`, dimension `h`, and modern column `x` with scope-aware identifier changes.
The branch-local `h` declarations can shadow the recovered dimension `h`; no scope change is needed.
Descriptive row names can avoid that confusion without claiming an unproved original mapping.
Keep allocation, destruction, version selection, read widths, masks, initialization, and final visibility load unchanged.
Do not change the old-format reset to match the modern-format reset.

## 8. `RGE_Map::get_border_type` — `0045A030`

Owner: `src/map.cpp`.
Verdict: confirmed all eight misplaced terrain names. Direct lifetime review resolves the two special storage cases.

The fixed frame between calls is `S - 0x38`.
The neighbor positions below use column change, then row change.
They do not describe screen-space directions.

| Current name | Original name | Neighbor position | Entry-ESP location | Value store |
| --- | --- | --- | --- | --- |
| `ter_top_lft` | `ter_cur` | Current tile | `S - 0x4` | `0045A093` |
| `ter_lft` | `ter_top` | `(0, -1)` | `S - 0x28` | `0045A0A4` |
| `ter_rgt` | `ter_lft` | `(-1, 0)` | `S - 0x24` | `0045A0E1` |
| `ter_top_rgt` | `ter_rgt` | `(+1, 0)` | `S - 0x20` | `0045A107` |
| `ter_bot_lft` | `ter_top_lft` | `(-1, -1)` | `S - 0x14` | `0045A12C` |
| `ter_top` | `ter_top_rgt` | `(+1, -1)` | `S + 0x8` | `0045A14F` |
| `ter_bot_rgt` | `ter_bot_lft` | `(-1, +1)` | `S - 0x10` | `0045A174` |
| `ter_cur` | `ter_bot_rgt` | `(+1, +1)` | `S - 0xc` | `0045A199` |

`ter_bot` already names the `(0, +1)` value correctly, at `S - 0x1c`.
Each boundary fallback stores the current tile terrain into the same neighbor location.
The terrain values use the low five bits of tile byte `+5`.
The row-pointer changes of four bytes and tile-byte changes of `0x18` establish the neighbor positions.

### Positive coordinate: original `ter_top_rgt`

Both original and rebuilt debug records give this local CodeView coordinate `+0xc`.
The actual value occupies entry-ESP `+8`, the original `map_row` argument home.
`0045A059` loads the row argument before any overwrite.
Its sign-extended value remains in ECX during neighbor preparation.
The last row-argument-home test occurs at `0045A136`.
`0045A144` and `0045A148` fetch the preceding row's next column.
`0045A14F`, or the fallback at `0045A155`, writes that value into the old argument home.
The remaining row tests use ECX, not the overwritten argument home.

`0045A1E8` forms a reference to that same byte for `check_for_border` at `0045A1F0`.
`0045A237` reads it in neighbor selection.
`0045A3FC` through `0045A40C` use it for border shape `6`, after the top-left shape test.
No later instruction restores the argument value over the live terrain byte.
These uses resolve the earlier lifetime concern and approve `ter_top` to `ter_top_rgt`.
Do not change the source's uses of `map_row` or introduce explicit argument-home writes.

### Reused negative location: original `ter_bot_lft`

The rebuilt records place both `int yMax` and current `unsigned char ter_bot_rgt` at `S - 0x10`.
The automatic check correctly left the original `ter_bot_lft` record unknown.

`0045A0B4` first stores `map_height - 1` into that location.
`0045A159` retains the full value in EBP before the byte overwrite.
`0045A169` and `0045A16D` fetch the following row's preceding column.
`0045A174`, or the fallback at `0045A17A`, stores that terrain byte into the same location.
The next row-limit comparison at `0045A17E` still uses EBP.
Thus, the byte overwrite does not replace a row limit that a later stack load needs.

The byte then flows through the reference at `0045A1F5`, selection at `0045A23F`, and shape test at `0045A410`.
Its border-helper call at `0045A1FD` can modify the byte through the original reference contract.
No later integer store overwrites it before its terrain uses end.
This approves current `ter_bot_rgt` to original `ter_bot_lft` without merging it with `yMax`.

### Parameters and selected border terrain

`map_col`, `map_row`, `tile`, `ter_bot`, and `this` have supported original names.
The automatic unknown for `map_row` is not a wrong parameter name.
Its entry read and subsequent row operations agree with the original parameter role.

`bor_ter` is also a supported original name.
Its CodeView coordinate `+8` collides with the parameter record, but its physical location is entry-ESP `+4`.
`0045A20F` through `0045A24D` select the first differing neighbor after the eight helper calls.
`0045A259` stores that value into the retired `map_col` argument home.
`0045A267` through `0045A277` mask it and use it to select the border-table entry.
The input column is no longer needed there. Later compiler stores reuse the home after border selection ends.
Do not treat either positive debug coordinate as a permanent parameter address.

Original names remain unknown for `rows`, `xi`, `xMax`, `yMax`, `border_table`, `border`, and `edge`.
The unused `ter_top_rgt_unused` declaration has no original record and is not the active top-right value.
Keep it separate from the recovered `ter_top_rgt`; do not remove or activate it in a naming edit.

### Approved naming scope

Recover the eight terrain names together, leaving `ter_bot` and `bor_ter` unchanged.
Keep declarations, types, scopes, boundary fallbacks, and every neighbor expression in their current positions.
Preserve helper-call order and first-differing-neighbor priority.
Preserve the border validity checks, bit values, shape precedence, and packed-byte writes.
No declaration collision requires a new name or scope.

## Review checks and next step

All five reviewed source-file hashes match both trial build manifests:

| Source owner | SHA256 |
| --- | --- |
| `src/aiconmod.cpp` | `d364658a0b2e69a06f8a856212e12a50c63eb33854ad535538cbc357b3876daf` |
| `src/com_sync.cpp` | `d5459744e42c75fe030ecb4a5b6fe8ffa19df70937d1cf5735d56aae13641498` |
| `src/m_s_obj.cpp` | `e410ae63400486b0e8ca01b47a97796c83989c5b21091aeb685d7a593c456f65` |
| `src/scr_mps.cpp` | `0685eaf7aaf98cd99ceaea509638f742361202a1d40a319f98c85e14fd4a1249` |
| `src/map.cpp` | `f6e2e358d7e097e50eb4410a241209e9726b8ab38f8c8bcd88c2a9701ad14f4e` |

The original inputs, compiled objects, dumper, and checker also match every input hash in the five final module reports.
The first PowerShell hash command could not run because `Get-FileHash` was unavailable.
A Python hash comparison completed successfully. The failed command's partial output was not used as evidence.
These checks identify the reviewed artifacts; they do not validate changed headers or the current build.

No compiler, function audit, tool tests, linked audit, executable build, or runtime suite ran during this review.
No game source, header, registry, flags, or generated inventory changed in this assignment.
Only this review and its link from the trial report changed.

The next step is a scope-aware naming edit, one function at a time.
Apply only the supported mappings and the required collision fixes.
Keep unresolved original names visible; do not infer numbered names or branch assignments.
After an edit, compile the module's normal and `/Z7` objects and repeat both checks in a new directory.
Compare against the current pre-edit code as well as the original executable.
Leave buffer structure, type recovery, and control-flow changes for separate assignments.
