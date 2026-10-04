# Twelve-module local-name trial

## Result

The broader trial found the same name-mapping problem in eight additional functions.
The checker reported 28 original spellings at other typed locations in those functions.
Direct instruction review supports the misplaced-name finding in each function.
This review does not approve automatic renames or a complete source rewrite.

The checker also reported 55 different spellings. These are separate name-recovery findings, not proved variable swaps.
Some different spellings can still be misleading. They need separate review.

No game source, header, registry, or compiler recipe changed during this trial.

## Selection and code checks

Eight modules came from the same `wave02` cleanup.
Four additional modules supplied other compiler flags and frame forms.
The trial used the pinned VC5 compiler and each module's configured response file.
It compiled one normal object and one `/Z7` object per module.

| Module | Flag profile | Exact targets | Functions with misplaced original names |
| --- | --- | ---: | ---: |
| `aiconmod` | `gx` | 17 | 1 |
| `aimdmod` | `gx` | 20 | 0 |
| `com_loby` | `gx_directplay` | 13 | 0 |
| `com_sess` | `ole32_directplay` | 13 | 0 |
| `com_sync` | `default` | 11 | 1 |
| `task` | `default` | 6 | 0 |
| `m_s_obj` | `gx` | 21 | 1 |
| `scr_mps` | `gx` | 29 | 1 |
| `map` | `gx` | 54 | 4 |
| `dsutil` | `c_no_intrinsics` | 30 | 0 |
| `tech` | `unoptimized` | 29 | 0 |
| `dstring` | `gx_no_fpo` | 47 | 0 |
| Total | Seven profiles | 290 | 8 |

All 290 exact targets passed the existing original function check in both objects.
No eligible function failed the code requirement for name comparison.
These are local code checks, not linked-image or gameplay results.

The `map` sample includes EBP frames with aligned stack storage.
The `tech` sample includes `/Od` EBP frames, but its original procedure records are missing.
The `gx_no_fpo` profile does not guarantee an EBP frame; the actual instructions define the frame.

The batch recorded each module's transitive input fingerprint before and after the run.
All twelve fingerprints remained unchanged.

## Final counts

The final report covers 319 configured function entries:

- 196 functions had agreement for all compared records, without an extra-record gap.
- 8 functions had misplaced original names.
- 11 functions had other spellings, without a misplaced-original-name finding.
- 75 functions retained unknown name coverage.
- 29 nonmatching functions were not checked for names.

The original variable-record counts are:

- 790 agreements.
- 28 misplaced-original-name conflicts.
- 55 other spelling differences.
- 169 unknown records.

Eleven additional rebuilt records have no corresponding original location.
Those records remain unknown and are separate from the original-record counts.

## Reviewed misplaced-name functions

The offsets below are CodeView offsets. They are not one universal entry-ESP coordinate system.
Each mapping means current source spelling to original PDB spelling.

| Function | Current spelling | Original spelling | Original CodeView offset |
| --- | --- | --- | --- |
| `0040B690 ConstructionAIModule::loadConstructionPlan` | `xSize` | `id` | `-0x15c` |
| same | `zSize` | `z` | `-0x168` |
| same | `x` | `y` | `-0x170` |
| same | `z` | `x` | `-0x16c` |
| same | `ySize` | `xSize` | `-0x158` |
| `00433290 RGE_Communications_Synchronize::DoChecksum` | `cs3` | `cs4` | `-0x104` |
| same | `cs2` | `cs3` | `-0x10c` |
| same | `cs4` | `cs2` | `-0x108` |
| `004536D0 RGE_Master_Static_Object::save` | `temp_undead_sprite` | `temp_death_sprite` | `-0x18` |
| same | `temp_death_sprite` | `temp_sprite` | `-0x1c` |
| same | `created_sound_num` | `temp_undead_sprite` | `-0x14` |
| same | `death_sound_num` | `selected_sound_num` | `-0x8` |
| same | `temp_sprite` | `created_sound_num` | `-0x10` |
| same | `selected_sound_num` | `death_sound_num` | `-0x4` |
| `004A5210 TribeMPSetupScreen::setupSinglePlayerPlayers` | `first_any_color` | `first_any_civ` | `-0x8` |
| same | `first_any_civ` | `first_any_player` | `-0xc` |
| `00455FF0 RGE_Map::scenario_load` | `w` | `h` | `-0x8` |
| `004564E0 RGE_Map::preclean_elevation` | `index1` | `index2` | `-0x44` |
| same | `index2` | `index1` | `-0x40` |
| `004579C0 RGE_Map::load_map` | `w` | `h` | `-0x14` |
| same | `y` | `x` | `-0x1c` |
| `0045A030 RGE_Map::get_border_type` | `ter_bot_lft` | `ter_top_lft` | `-0x14` |
| same | `ter_rgt` | `ter_lft` | `-0x24` |
| same | `ter_cur` | `ter_bot_rgt` | `-0xc` |
| same | `ter_top_lft` | `ter_cur` | `-0x4` |
| same | `ter_top_rgt` | `ter_rgt` | `-0x20` |
| same | `ter_top` | `ter_top_rgt` | `+0xc` |
| same | `ter_lft` | `ter_top` | `-0x28` |

Related different-spelling findings complete several of these mappings:

- `loadConstructionPlan`: `item_arg_5` to `ySize`; `item_arg_6` to `zSize`.
- `setupSinglePlayerPlayers`: `first_any_color_index` to `first_any_color`.
- `scenario_load`: `map_height` to `w`.
- `load_map`: `map_height` to `w`.

Do not treat this table as an automatic edit script.
`loadConstructionPlan` has an unused source declaration named `y`, plus buffer and storage differences.
Several functions reuse stack storage. Resolve declaration collisions and lifetimes before a rename.
Preserve types, declaration order, widths, expressions, calls, and original behavior.

## Direct instruction review

The review used the pinned `XPack/empiresx.exe`, not Ghidra's local labels.
Original PDB records came from fresh `cvdump -s` and `cvdump -t` output.
The rebuilt debug records came from the same VC5 compiler that passed the code checks.

Let `S` be ESP at function entry for the following instruction examples.

### `loadConstructionPlan`

At the scan, ESP is `S - 0x184` before argument pushes.
`0040B7DB` forms the seventh field address at `S - 0x15c`.
The PDB names it `id`; the source names it `xSize`.
`0040B7F4` forms the second coordinate address at `S - 0x170`, with five argument pushes pending.
The PDB names it `y`; the source names it `x`.
`0040B7F9` forms the first coordinate address at `S - 0x16c`, with six pushes pending.
The PDB names it `x`; the source names it `z`.
`0040B873` through `0040B89D` pass the same storage to the `ConstructionItem` constructor.
The different buffer sizes and shifted `temp` declaration remain unknown in this name-only trial.

### `DoChecksum`

At the checksum call setup, ESP is `S - 0x11c` before argument pushes.
`00433300` forms `S - 0x104`, the original `cs4` location.
`00433307` forms `S - 0x10c`, the original `cs3` location.
With one push pending, `0043330C` forms `S - 0x108`, the original `cs2` location.
`00433324` calls `GetWorldChecksums` with these addresses.
The source call uses `cs4`, `cs2`, `cs3` where the original records identify `cs2`, `cs3`, `cs4`.

### `RGE_Master_Static_Object::save`

After the prologue, ESP is `S - 0x30`.
`00453707` stores the ID loaded through object offset `0x40` at `S - 0x10`.
The PDB names that location `created_sound_num`; the source names it `temp_sprite`.
`00453734`, `00453743`, and `00453752` store sprite IDs at `S - 0x1c`, `S - 0x18`, and `S - 0x14`.
Their original names are `temp_sprite`, `temp_death_sprite`, and `temp_undead_sprite`.
The original write calls at `004537D5`, `004537E5`, and `004537F5` consume those locations in that order.

### `setupSinglePlayerPlayers`

After the prologue, ESP is `S - 0x1c` between calls.
With one push pending, `004A52B2` stores the player index at `S - 0xc`.
The PDB names it `first_any_player`; the source names it `first_any_civ`.
After `Get_player_Civ`, `004A52BB` stores its result at `S - 0x8`.
`004A52BF` stores the color at `S - 0x4`.
The PDB names those locations `first_any_civ` and `first_any_color`.
The setter calls at `004A5382` and `004A5394` confirm their uses.

### `scenario_load`

Before its first read, ESP is `S - 0x1c`.
`00455FF9` forms `S - 0x4`, the original `w` location.
`0045600B` forms `S - 0x8`, the original `h` location.
The source reads into `map_height` and `w`, then passes them to `new_map`.
The different types of other loop locals remain unknown rather than forcing more mappings.

### `preclean_elevation`

After the prologue, ESP is `S - 0x58`.
`00456542` reads `y1`; `00456575` stores the row index at `S - 0x40`.
That is original `index1`, but the source names it `index2`.
`0045658D` stores the column index at `S - 0x44`, original `index2`.
The source names that column index `index1`.
The directional `place*` and `offset*` differences are separate descriptive spellings, not this index swap.

### `load_map`

`004579D8` forms `S - 0x10` before the saved-register pushes.
That is original `w`, currently named `map_height`.
`004579F2` forms `S - 0x14`, original `h`, currently named `w`.
With the normal frame restored between calls, `00457AB2` stores the column counter at `S - 0x1c`.
The PDB names it `x`; the source names it `y`.

### `get_border_type`

After the prologue, ESP is `S - 0x38`.
`0045A093` stores the current tile terrain byte at `S - 0x4`.
The PDB names it `ter_cur`; the source names it `ter_top_lft`.
`0045A0A4`, `0045A0E1`, and `0045A107` store the north, west, and east values at their original named locations.
The source uses different original spellings at all three locations.

The `+0xc` CodeView row needs special care: the instructions reuse the argument home at entry-ESP `+8`.
Do not convert every debug offset to entry ESP with one constant.
The top-right value's instruction use supports the name difference, but its lifetime needs review before a source edit.

## Unknowns and coverage limits

The 169 unknown original records include:

- 104 records with reused names or storage.
- 42 records with different resolved types.
- 12 records without a rebuilt variable at the original location.
- 10 records with an unresolved type.
- 1 record with a repeated rebuilt name.

All 29 exact `tech` targets lack original procedure records.
The rebuilt parser reads their records; this is missing original evidence, not a parser failure.

The original PDB dump contains no `S_BLOCK32` records.
Its 5,470 `S_REGISTER` records all name `this`; it supplies no named ordinary register locals.
Thus, the trial cannot validate original-name recovery for those cases.
Tests exercise the register-swap and nested-scope guards with synthetic records.
Unoptimized rebuilt `tech` records include real lexical blocks, but lack matching original procedure records.

This trial does not prove complete variable lifetimes, type layouts, or game behavior.
It does not check names in the 29 nonmatching functions.
No linked audit, full executable build, menu test, or gameplay test ran.

## Artifacts and tool changes

- Compiled objects and build commands: `build/probes/local-name-trial/run-01/<module>/`.
- Original instruction review: `build/probes/local-name-trial/run-01/original-review/`.
- Final module reports: `build/probes/local-name-trial/final/<module>/report.json` and `report.txt`.
- Final summary: `build/probes/local-name-trial/final/summary.json`.
- Misplaced-name records: `build/probes/local-name-trial/final/conflicts.json`.
- Other spelling differences: `build/probes/local-name-trial/final/name-differences.json`.
- Final known-error control: `build/probes/local-name-trial/final-known-error-control/report.json`.
- Final corrected control: `build/probes/local-name-trial/final-corrected-control/report.json`.
- Tool tests: `build/probes/local-name-trial/tests.xml`.

The first run compiled twelve modules with three workers.
The final run reused those objects after checking that their input fingerprints had not changed.
Each module report records the checker, dumper, original input, and object hashes.

The final checker separates `conflict` from `different_spelling` instead of treating every name difference as a swap.
It also distinguishes missing original records from missing rebuilt records.
The known-error control still detected all six old `loadBuildList` errors and returned the expected `1`.
The corrected control returned `0`: 98 agreements, no conflicts, and one extra rebuilt record still unknown.
The selected tool tests returned `0`: 24 passed, with no skips.

Repeat a fresh single-module check with:

```text
python tools/audit_local_name_records.py --help
python tools/audit_local_name_records.py --group MODULE --cvdump C:/path/to/cvdump.exe --output-dir build/probes/local-name-MODULE-RUN
```

Use a new output directory. Keep conflicts, spelling differences, and unknowns separate.
The eight reviewed functions are the next source-review targets. Do not apply automatic renames.
