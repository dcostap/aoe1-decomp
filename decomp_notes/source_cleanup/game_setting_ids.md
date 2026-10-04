# Game-setting ID cleanup

Base commit: `de8419376e54b1efeca570f0357bd42afffa0c14`.
The user requested map-size, map-type, victory-type, and related setting names.
This pass changes names, not setting values or lookup behavior.

## Changed files

Headers: `include/basegame.h`, `include/game_globals.h`, `include/tribegam.h`, and `include/resource_ids.h`.

Source modules:

- `src/basegame.cpp`, `src/tribegam.cpp`, and `src/tworld.cpp`.
- `src/scr_mps.cpp`, `src/scr_set.cpp`, `src/scr_cams.cpp`, `src/scr_sed.cpp`, and `src/scr_sed2.cpp`.
- `src/scr_game.cpp` and `src/tpnl_tml.cpp` use the same age-name resources as the settings lists.
- `src/dlg_conf.cpp`, `src/rmm_tdbc.cpp`, and `src/tplayer.cpp`.
- `src/aiuaimod.cpp`, `src/taimdmd.cpp`, `src/taitacmd.cpp`, and `src/taiuaimd.cpp`.
- `decomp_notes/source_cleanup/game_setting_ids.md` records evidence and validation.

Reuse the existing map-size, map-type, starting-age, resource-level, victory-type, and editor-mode enums.
Keep existing spelling, including `Humongous` and `Isthmas`.
Keep the existing `TRIBE_Game::VictoryType` enum unchanged; integer macros name its five unlisted values.
Add integer macros for difficulty, path-finding options, map dimensions, and fixed string IDs.
The existing `game_globals.h` shares difficulty values without new imports or class declarations.
Path-finding values remain with the game options in `basegame.h`.
Rename five age-name resources to share one name across dropdowns, help calls, and timeline labels.
Reuse the existing six time-limit string names; add only the missing 15,000-year name.
Name all nine default-terrain strings in both editor lists.

New names are cleanup names, not recovered original macro names.
No parameter, local, member, procedure, public signature, or stored-field name changes.
No new enum type, object, array, helper function, or runtime storage is introduced.
All existing enum declarations remain unchanged.

The user also changed formatting in `src/tplayer.cpp` after the base commit.
Review found no changed non-whitespace characters before this pass edited that file.
The user's wrapping and joined declarations remain. One trailing space was removed.

## Keep domains separate

Map-size options use indices 0 through 5; tile dimensions use 72 through 250.
The editor's map and victory modes differ from game option values.
World runtime victory states also differ from `TRIBE_Game::VictoryType`.
Do not replace one domain's constants with another domain's constants.

Fixed string lookups now use named IDs, not `BASE + literal`.
Variable-index lookups retain arithmetic. No switch or table replaces those expressions.
Boolean settings, null values, allocation lengths, numeric labels, and general loop indices remain unchanged.
Reveal-map strings already have names. Its Boolean tests do not need a separate enum.

The AI briefly stores a strategy-rule result in `workingMapType`.
Its `workingMapType > 0` test remains numeric; that value is not a map-type comparison.
Later tests follow `workingMapType = mapType` and use map-type names.
The AI's adjusted map-size scores remain numeric, including negative cases.
Random-choice thresholds remain numeric where they are not actual map-type IDs.

## Binary evidence

The pinned executable is `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The extraction tool's configured original executable has the same hash.
Fresh extraction covers `0052EF30`, `00529200`, and `004A5060` under `build/asm/`.
Inventory listings supply supporting call-target and switch-label evidence, not a separate behavior oracle.

`TRIBE_World::new_game` at `0052EF30` proves the missing victory roles:

| Value | New macro | Original setter call |
| --- | --- | --- |
| 2 | `TRIBE_VICTORY_TYPE_EXPLORATION` | `0052F89B`: `T_Scenario::Set_Multi_Exploration` |
| 3 | `TRIBE_VICTORY_TYPE_RUINS` | `0052F87A`: `T_Scenario::Set_Multi_Ruins` |
| 4 | `TRIBE_VICTORY_TYPE_ARTIFACTS` | `0052F885`: `T_Scenario::Set_Multi_Artifacts` |
| 5 | `TRIBE_VICTORY_TYPE_DISCOVERIES` | `0052F890`: `T_Scenario::Set_Multi_Discoveries` |
| 6 | `TRIBE_VICTORY_TYPE_GOLD` | `0052F8A6`: `T_Scenario::Set_Multi_Gold` |

`TribeMPSetupScreen::activateVictoryPanels` at `004A5060` supplies the corresponding amount-label roles.
It uses a percentage for exploration, counts for ruins/artifacts/discoveries, and a quantity for gold.
The cleanup retains those paths, including the old victory options absent from the current settings list.

`TRIBE_Game::setMapSize` at `00529200` proves the square tile dimensions:

| Option | Index | Dimension macro value |
| --- | --- | --- |
| `Tiny` | 0 | 72 |
| `Small` | 1 | 96 |
| `Medium` | 2 | 120 |
| `Large` | 3 | 144 |
| `Huge` | 4 | 200 |
| `Humongous` | 5 | 250 |

All six calls retain the third argument, 8.
The same named dimensions serve editor generation and random-map cliff thresholds.

The settings and campaign lists establish difficulty values: Hardest=0, Hard=1, Moderate=2, Easy=3, Easiest=4.
`RGE_Game_World::difficultyLevel` supplies the same value to the reviewed AI comparisons.
The settings list and path-finding setters establish Default=0, Medium=1, High=2.
The path-finding paths retain their original iteration counts and fallback behavior.

## String resource evidence

`TRIBE_Game::get_string` tries the expansion string table before the base table.
The cleanup keeps that lookup path, buffer sizes, and localization.

Checked modules:

- Base runtime input: `runtime/language.dll`.
  SHA256: `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`.
  This staged runtime module is not claimed as a pinned original asset.
  The pinned original game tree contains `languagex.dll`, but no base `language.dll`.
- Pinned expansion input: `orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/languagex.dll`.
  SHA256: `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`.

Language: `0x0409` for all found entries below.
An empty expansion slot makes `LoadStringA` return zero and permits the base fallback.
A missing block differs from an empty slot.
Names describe the proven call-site roles, not necessarily the current English text.

### Map labels

The existing enum cases and dropdown indices establish each ID's role.
Some old comments did not match the checked resource text. Those repeated map-label comments were removed.
The lookup IDs and payloads remain unchanged.

| ID | `STRING_ID_MAP_` suffix | Base text | Expansion text |
| --- | --- | --- | --- |
| `0x296A` | `TYPE_ALL_WATER` | `Small Islands` | Empty |
| `0x296B` | `TYPE_MOSTLY_WATER` | `Large Islands` | Empty |
| `0x296C` | `TYPE_WATER_AND_LAND` | `Coastal` | Empty |
| `0x296D` | `TYPE_MOSTLY_LAND` | `Inland` | Empty |
| `0x296E` | `TYPE_ALL_LAND` | `Highland` | Empty |
| `0x296F` | `TYPE_CONTINENTAL` | Empty | Empty |
| `0x2970` | `TYPE_LAKE` | Empty | Empty |
| `0x2971` | `TYPE_HILLY` | Empty | Empty |
| `0x2972` | `TYPE_ISTHMAS` | `******* SIZE *******` | Empty |
| `0x2973` | `SIZE_TINY` | `Tiny` | Empty |
| `0x2974` | `SIZE_SMALL` | `Small` | Empty |
| `0x2975` | `SIZE_MEDIUM` | `Medium` | Empty |
| `0x2976` | `SIZE_LARGE` | `Large` | Empty |
| `0x2977` | `SIZE_HUGE` | `Huge` | Empty |
| `0x2978` | `SIZE_HUMONGOUS` | Empty | `Gigantic` |

The size marker at `0x2972` is not silently replaced with an invented map label.
The enum-to-ID mapping proves its role at these callers despite that unexpected payload.
The `_BASE` aliases remain for the variable-index status-log lookups.

### Default-terrain labels

Both editor default-terrain lists use these fixed IDs.
The existing `STRING_ID_DEFAULT_TERRAIN_BASE` had no variable-index caller and was replaced, not retained as an alias.
Each name begins with `STRING_ID_TERRAIN_`.

| ID | Suffix | Base text | Expansion text |
| --- | --- | --- | --- |
| `0x297D` | `GRASS` | `Grass` | Empty |
| `0x297E` | `DESERT` | `Desert` | Empty |
| `0x297F` | `FOREST` | `Forest` | Empty |
| `0x2980` | `WATER` | `Water` | Missing |
| `0x2981` | `PALM_DESERT` | `Palm Desert` | Missing |
| `0x2982` | `JUNGLE` | `Jungle` | Missing |
| `0x2983` | `SHALLOWS` | `Shallows` | Missing |
| `0x2984` | `PINE_FOREST` | `Pine Forest` | Missing |
| `0x2985` | `DEEP_WATER` | `Deep Water` | Missing |

### Editor victory-condition labels

`TRIBE_Screen_Sed::create_drop_down` fills `victory_drop_down` with this fixed range.
All expansion entries are missing. The base strings contain the exact text below, including leading spaces.
Each suffix belongs to `STRING_ID_VICTORY_CONDITION_`.

| ID | Suffix | Base text |
| --- | --- | --- |
| `0x2851` | `NONE` | `         < None >` |
| `0x2852` | `BRING_OBJECT_TO_OBJECT` | ` Bring Object to Object` |
| `0x2853` | `BRING_OBJECT_TO_AREA` | ` Bring Object to Area` |
| `0x2854` | `CREATE_OBJECT_COUNT` | ` Create # of Objects` |
| `0x2855` | `CREATE_OBJECTS_IN_AREA` | ` Create Objects in Area` |
| `0x2856` | `DESTROY_OBJECT_COUNT` | ` Destroy # of Objects` |
| `0x2857` | `DESTROY_SPECIFIC_OBJECT` | ` Destroy Specific Object` |
| `0x2858` | `DESTROY_ALL_OBJECTS` | ` Destroy All Objects` |
| `0x2859` | `DESTROY_PLAYER` | ` Destroy Player` |
| `0x285A` | `CAPTURE_OBJECT` | ` Capture Object` |
| `0x285B` | `GOLD_STOCKPILE` | ` Gold Stockpile` |
| `0x285C` | `FOOD_STOCKPILE` | ` Food Stockpile` |
| `0x285D` | `WOOD_STOCKPILE` | ` Wood Stockpile` |
| `0x285E` | `STONE_STOCKPILE` | ` Stone Stockpile` |
| `0x285F` | `POPULATION` | ` Population` |
| `0x2860` | `AGE` | ` Age` |
| `0x2861` | `EXPLORATION` | ` Exploration` |
| `0x2862` | `OTHER_ATTRIBUTES` | ` Other Attributes` |

The following technology-list entry remains separate.
The editor still assigns zero to each list entry's stored ID and uses the line index for selection.

### Time, age, and path-finding labels

The settings and editor time dropdowns establish the year values.
All expansion entries in this table are missing.

| ID | Name | Base text |
| --- | --- | --- |
| `0x2634` | `STRING_ID_TIME_LIMIT_15000` | `15,000 years (2:00 hr)` |
| `0x2635` | Existing `STRING_ID_TIME_LIMIT_13000` | `13,000 years (1:45 hr)` |
| `0x2636` | Existing `STRING_ID_TIME_LIMIT_11000` | `11,000 years (1:30 hr)` |
| `0x2637` | Existing `STRING_ID_TIME_LIMIT_9000` | `9,000 years (1:15 hr)` |
| `0x2638` | Existing `STRING_ID_TIME_LIMIT_7000` | `7,000 years (60 min)` |
| `0x2639` | Existing `STRING_ID_TIME_LIMIT_5000` | `5,000 years (40 min)` |
| `0x263A` | Existing `STRING_ID_TIME_LIMIT_3000` | `3,000 years (25 min)` |
| `0x1069` | `STRING_ID_AGE_STONE` | `Stone Age` |
| `0x106A` | `STRING_ID_AGE_TOOL` | `Tool Age` |
| `0x106B` | `STRING_ID_AGE_BRONZE` | `Bronze Age` |
| `0x106C` | `STRING_ID_AGE_IRON` | `Iron Age` |
| `0x106D` | `STRING_ID_AGE_POST_IRON` | `Post-Iron Age` |
| `0x260E` | `STRING_ID_PATH_FINDING_DEFAULT` | `Default` |
| `0x260F` | Existing `STRING_ID_PATH_FINDING_MEDIUM` | `Medium` |
| `0x2610` | Existing `STRING_ID_PATH_FINDING_HIGH` | `High` |

The age dropdowns and `TRIBE_Game::get_string2` age-name path establish the age-name roles.
Their old `HELP_AGE_` names came from earlier cleanup, not proved original macros.
Help calls and timeline text retain the same IDs and behavior. General help IDs remain unchanged.

The checked base entries `0x25E6` through `0x25E8` contain `Low`, `Medium`, and `High`.
The existing resource-level string macros already name those entries.
The checked base entries `0x2BD0` through `0x2BD4` contain `Hardest`, `Hard`, `Moderate`, `Easy`, and `Easiest`.
The existing difficulty string macros already name those entries.
The expansion contains neither range.

### Legacy victory log range

`TRIBE_World::logStatus` uses `victoryType() + 0x28A6` for its victory-condition log text.
`STRING_ID_VICTORY_LOG_BASE` names that role and preserves the arithmetic lookup.
All ten base slots `0x28A6` through `0x28AF` are empty. All ten expansion entries are missing.
The intended text remains unknown; no text or alternative lookup is invented.

Resource extraction artifacts remain under `build/game-setting-cleanup/`.
The table above records the durable ID-to-role conclusions independently of those ignored artifacts.

## Baseline and validation

Compiled baseline: `build/validation/command-ids-20261004-042228/functions/objects/`.
Before editing, the baseline check verified all 225 input fingerprints and recorded object hashes.
223 fingerprints matched directly.
The other two matched after substituting reviewed pre-formatting hashes and sizes for `world.cpp` and `tplayer.cpp`.
The first check reported the new `tplayer.cpp` formatting difference. Review and the repeated check resolved it.
No non-formatting compiler input differed before this cleanup.

Check: `python build/game-setting-cleanup/check_baseline.py`, final exit code 0.
Report: `build/game-setting-cleanup/baseline.json`.

Source and registry validation returned exit code 0.
Command: `python tools/validate_translation_units.py --no-build-checks`.

### Rejected intermediate builds

The first full sweep compiled 221 of 225 groups and returned exit code 1.
Three groups still used old age resource names. The tactical AI lacked the difficulty definitions.
It also reported a matching regression in the unchanged `objectCostByType` function.
Object comparison found three payload differences, plus four missing objects from the compile failures.
Report: `build/validation/game-setting-ids-20261004-044745/functions/report.json`.

Adding five enum members changed VC5 output in `tplayer`, `rmm_tdbc`, and `tribegam`.
Replacing those new members with integer macros removed those differences.
The repair sweep compiled nine groups and passed all 582 exact claims.
Eight objects matched the baseline; `taitacmd` still differed after importing all of `basegame.h`.
Its `taskActiveSoldiers` and `idleCivilian` functions had changed code despite no source edits in those bodies.
Report: `build/validation/game-setting-ids-repair/object-comparison.json`.

The next full sweep used a new constant-only header.
All 225 groups compiled, but seven matching claims regressed and 13 objects differed.
Report: `build/validation/game-setting-ids-final/functions/report.json`.
That source form was also rejected, including differences in otherwise untouched modules.

The final source uses existing headers only. The tactical AI already imports `game_globals.h`.
These failures are not accepted drift. Final validation must compare every object with the baseline.

### Final checks

Final report directory: `build/validation/game-setting-ids-shared/`.

The full VC5 sweep compiled all 225 modules and returned exit code 0.
Command: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/game-setting-ids-shared/functions`.
All 5,013 exact claims passed among 5,426 included normal functions.
There were no compile errors or matching regressions.
Report: `functions/report.json` in the final report directory.

The remaining categories match the compiled baseline:
217 `new_verified_logic_observed`, 140 `accepted_drift_observed`, 44 `grouped_mismatch`, and 12 `boundary_problem`.
Those existing gaps remain visible. Compilation does not prove their behavior against the original executable.

The owner audit checked the same report and returned exit code 0.
It found zero owner mismatches, zero class/free mismatches, and an empty repair queue for all 5,013 exact claims.
Reports: `owners.json` and `owners.txt` in the final report directory.

The complete object comparison returned exit code 0: 225 objects, zero differences.
Command: `python build/object-state-cleanup/compare_objects.py --before build/validation/command-ids-20261004-042228/functions/objects --after build/validation/game-setting-ids-shared/functions/objects --output build/validation/game-setting-ids-shared/object-comparison.json`.
The comparison covers non-debug section bytes, sizes, flags, relocation targets, and allocated symbol identities.
It normalizes private label serials by section and offset, without changing external symbol identities.
It excludes debug records and build timestamps. No source cleanup difference was accepted as drift.

The current-input check returned exit code 0 for all 225 groups.
It recomputed every input fingerprint and verified every object hash against the fresh compiler report.
Report: `current-inputs.json` in the final report directory.
The check found no input changes at verification time.
A later diff review found new user comments in `src/aibldmod.cpp`.
They remain untouched and are outside this cleanup's compiled snapshot and commit.
That diff changes no code tokens. The module contains no `__LINE__` or `__COUNTER__` uses.

Final cleanup diff review and `git diff --check` found no whitespace errors.
All changed source and header files retain LF line endings.
No fixed `STRING_ID_*_BASE + literal` expressions remain in `src/` or `include/`.

No linked build, linked-image audit, automated regression tests, menu suite, or gameplay suite ran in this pass.
These compiler and object checks do not establish whole-game correctness or complete linked reference proof.
No validation expectation, function registry, build recipe, runtime asset, or approved binary dependency changed.
