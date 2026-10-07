# Program-mode names and compiler context

Base commit: `6d23f1a047d02eda39778de788ccc4b60dc15ffb`.

## Change

Named all 47 remaining program-mode comparisons:

- `src/vw_main.cpp`: 46 numeric field and local-copy comparisons.
- `src/tribegam.cpp`: one comparison with a return-code local that held the video-mode value.

Changed headers:

- `include/basegame.h`
- `include/program_mode.h`

This report is the only new tracked file.
No compiler flags, layouts, registry entries, signatures, field types, or local names changed.
Program-mode storage, local copies, and the setter parameter remain `int`.

## One value owner and the existing enum

`include/basegame.h` owns the numeric IDs because it owns `RGE_Base_Game::prog_mode`.
The definitions use unsuffixed integer macros. They introduce no storage or enum type into additional modules.

| Value | Numeric ID | Existing enum entry |
| --- | --- | --- |
| 0 | `RGE_PROGRAM_MODE_NONE` | `ProgModeNone` |
| 1 | `RGE_PROGRAM_MODE_VIDEO` | `ProgModeVideo` |
| 2 | `RGE_PROGRAM_MODE_MENU` | `ProgModeMenu` |
| 3 | `RGE_PROGRAM_MODE_MULTIPLAYER_WAIT` | `ProgModeMultiplayerWait` |
| 4 | `RGE_PROGRAM_MODE_GAME` | `ProgModeGame` |
| 5 | `RGE_PROGRAM_MODE_GAME_OVER` | `ProgModeGameOver` |
| 6 | `RGE_PROGRAM_MODE_GAME_TEMP_PAUSED` | `ProgModeGameTempPaused` |
| 7 | `RGE_PROGRAM_MODE_SCENARIO_EDITOR` | `ProgModeScenarioEditor` |

`include/program_mode.h` includes the value owner.
Its existing `RGE_Program_Mode` enum refers to these IDs instead of repeating their numeric definitions.
The enum type, entry names, values, and current users remain unchanged.
The numeric ID names are descriptive cleanup names, not recovered original names.

The main view already includes `basegame.h`.
It uses the numeric IDs without adding the standalone enum header or a new declaration type.
Other modules retain their existing enum includes and enum expressions.
This preserves both compiler contexts without duplicate numeric mappings or conditional header forms.

## Source scope

The main-view changes cover scrolling, keyboard handling, mouse handlers, deletion, and command guards.
They include local copies of `prog_mode`, not only direct field comparisons.
Comparison order, repeated field reads, short-circuit order, and surrounding conditions remain unchanged.

The main view reuses some `mode` locals for `game_mode` after the program-mode guard.
Those later comparisons and switches remain unchanged.
Game modes, scroll actions, pick results, timing categories, and return values remain separate domains.

`TRIBE_Game::handle_query_new_palette` now uses `ProgModeVideo` instead of its return-code local:

```cpp
result = 1;
mode = this->prog_mode;
if (mode == ProgModeVideo) {
```

The old comparison used `mode == result` when `result` held 1.
`ProgModeVideo` also has value 1.
The numeric return-code initialization remains because it is not a program-mode assignment.
Both locals and the return path remain unchanged.

Applied clang-format 21.1.8 with the existing project settings to the headers and main-view source.
Only longer program-mode conditions needed new source wrapping.
LF line endings remain unchanged.
Inverse substitutions restore both complete source owners after reversing the accounted formatting.

Inspected all `prog_mode` uses under `src/` and `include/`, including their local copies.
No direct numeric program-mode comparisons, assignments, or setter arguments remain in that scope.
Existing casts elsewhere remain unchanged.
Generated inventories, original listings, and historical notes are outside the source-edit scope.

An unrelated comment appeared in `src/basegame.cpp` during this work.
It explains timer message timing. This task did not author or change it.
Fresh compiler reports include its current bytes.

## Original evidence

Read instructions directly from the pinned original executable:

`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`

SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

- `RGE_Main_View::do_auto_scroll`, `0053DBA0`, reads program mode at base-game offset `1B0`.
  It compares with 4, 6, 7, and 5 at `0053DBB5` through `0053DBC4`, in that order.
- `RGE_Main_View::mouse_move_action`, `0053E2F0`, first reads program mode at offset `1B0`.
  At `0053E315`, it reads game mode at offset `1B4`.
  The following comparisons with 1, 6, and 8 belong to game mode.
- `TRIBE_Game::handle_query_new_palette`, `00529980`, reads the program-mode field.
  It loads 1 into ESI at `00529987` and compares with ESI at `0052998C`.
  This proves the value represented by the old return-code alias.

Addresses and offsets use hexadecimal notation. Mode values use decimal notation.
Existing declarations and instruction listings supply supporting symbol names, not a separate behavior oracle.

## Compiler-context investigation

The first complete candidate added `program_mode.h` to the main view and named all 47 comparisons.
All 225 groups compiled, but one exact claim failed.
`mouse_left_down_action` changed 26 bytes and lost its exact claim.
The untouched `draw` changed two bytes and changed from nonmatching to matching.
Neither output difference was accepted.

Including the enum without changing numeric comparisons also changed the main-view object.
Moving the include, adding integer casts, and using macros in that new header did not restore parity.
Moving the enum to the existing base-game header also changed the main-view object.

Replacing the enum entirely with macros in the base-game header restored the main view.
However, the complete check found six changed objects and two failed exact claims:

- Changed objects: `basegame`, `scr_ach`, `stat_obj`, `tplayer`, `tribegam`, and `view`.
- Failed claims: `RGE_Static_Object::draw_frame` and `TRIBE_Player::objectCostByType`.

A second focused investigation tested:

- Seventeen ordinary source include positions.
- Three C/C++ enum declaration forms.
- Six include positions within the existing owner/view headers.
- Three source line-count and wrapping controls.
- Two self-contained compatibility-header forms across the seven sensitive objects.

None restored the complete affected set.
The successful form keeps the numeric owner and the existing typed enum interface.
All seven sensitive object payloads then matched, including after final main-view formatting.
This result supports the retained declaration form, not an assumed internal compiler implementation.

No include-order selection macro, extra declaration, cast workaround, assembly, or matching-status change remains.
No candidate source wrapper or fragment enters the build.

## Validation

Current investigation artifacts are under `build/prog-mode-context/`.
Earlier rejected artifacts remain under `build/prog-mode-cleanup/`.
The final complete check passed under `build/prog-mode-context/final/`.

- All 225 function groups compiled with no compile errors.
- All 5,013 exact claims passed.
- All 5,426 observations and summary counts remain unchanged.
- All 226 C/C++ non-debug object payloads match the verified baseline.
- Section bytes, sizes, flags, relocation targets, and allocated symbol identities match.
- The owner audit found no owner mismatches, class/free mismatches, or repair entries.

The comparison baseline is `build/prog-mode-cleanup/retained-functions/`.
That baseline already matches the pre-cleanup culture report across all 226 object payloads.
Thus, the full 47-comparison cleanup preserves the original pre-cleanup output, not only the palette-only intermediate.
No existing original-versus-rebuilt difference changed.

Final compiler-input freshness checking passed for all 225 groups in `build/prog-mode-context/final-inputs.json`.
Recorded inputs, fingerprints, and object hashes match the current source and reports.

Scope checking passed for all eight values, preserved enum entries, and all 47 substitutions.
The integration-global fingerprint, all 78 recorded inputs, and object hash match the current report.
`git diff --check` passed.

Only parity and matching validation is authorized for this task.
No linked executable build, linked-image audit, assembly rebuild, automated test suite, or runtime suite ran.
Parity does not establish complete game correctness.
