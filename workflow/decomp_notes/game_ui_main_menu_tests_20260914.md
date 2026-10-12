# Game UI main menu tests: qualification

## Source repairs after initial qualification

Three defects were proved against the original executable and repaired in two natural source owners.

| Owner | Cause | Repair |
| --- | --- | --- |
| `src/Panel_ez.cpp`, `00466A90` | Popup positioning tested the filename instead of `full_screen` | Restore the original predicate |
| `src/pnl_lst.cpp`, `00478730` | Four key labels selected the wrong external switch entries | Restore Page Up, Page Down, Home, and End labels |
| `src/Panel_ez.cpp`, `00466A90` | The parser had 61 conversions but 65 output arguments | Restore the final state-color group |

The parser defect left the team button's second state color uninitialized.
Read-only probes found matching text positions and fonts but different shadow colors.
The difference existed before button drawing. No drawing function needed a source change.
The temporary probes were removed before final qualification; their scripts and reports remain preserved with the experiment record.

The list handler still passes local byte comparison after correcting its labels.
All 28 linked selector destinations now match the original by owning-function offset.
The parser repair also leaves local code unchanged; it changes format data.
These findings show why local instruction equality alone cannot prove data-dependent behavior.

Isolated closure checks found no exact-neighbor regressions. No registry status was promoted.
The final build compiled 226 sources and one assembly source, with no link errors or unresolved symbols.
Build report: `build/executable/user/20260914T155318269945Z/20260914T155318520959Z/report.json`.
Rebuilt SHA256: `95e46ebf03109684d589c24683974ac92607005756995f3835a04744f778b1a9`.

The full Python suite passed 518 tests and 31 subtests. JavaScript syntax and `git diff --check` passed.
Two new source-data tests cover the parser conversion count and key labels.
The parser test failed on the old source before integration.

Final report: `build/runtime/ui-main-menu-20260914T160004355887Z/report.json`.
All 41 cases passed in one batch, with two fresh originals and one rebuilt run per case.
All 38 UI cases passed original repeat and cross-build comparisons. All three safety cases stopped at their expected boundaries.
The test definitions stayed unchanged. No map loaded and no gameplay began.
The random-player-controls comparison passes every checkpoint, including the former 11-pixel team-button difference.
Cleanup checks found no remaining game processes or private registry copies.

The repaired group proves only its recorded menu checkpoints and guarded boundaries.
Connected multiplayer, provider dialogs, malformed input, and full gameplay remain outside this qualification.

Function evidence: `workflow/decomp_notes/functions/0046/00466A90.md` and `workflow/decomp_notes/functions/0047/00478730.md`.
All changes remain uncommitted. Earlier repairs, baselines, and rejected experiments remain preserved.

## Initial result before source repairs

The permanent group contains 41 cases: 38 UI cases and three safety cases.
Each qualification case used two fresh original runs and one rebuilt run.
All 38 original UI repeat comparisons passed.

The initial qualification had these results across the two batches below:

- 26 UI cases passed cross-build comparison.
- 11 UI cases failed image or control-state comparison.
- One rebuilt UI case failed its text-selection assertion.
- All three safety cases stopped at their expected boundary on all three runs.

Thus, 29 cases passed and 12 cases failed. These are not 12 independent source defects.
Several routes expose the same dialog-layout difference.
The harness keeps these failures. It does not accept them as matching output.

The full regression suite passed 516 tests and 31 subtests.
`git diff --check` passed.
This phase changed the harness, fixtures, tests, and documentation. It did not repair game source.

## Evidence

Full batch:

`build/runtime/ui-main-menu-20260914T150731624222Z/report.json`

That batch's lobby case included Refresh. Both originals and the rebuilt failed to complete that step.
The driver recorded the click dispatch, but no later idle checkpoint arrived.
The original process remained on Join Screen. The exact blocking cause remains unproved.

The corrected lobby case excludes Refresh:

`build/runtime/ui-main-menu-20260914T151119683450Z/report.json`

Both originals completed and matched. The rebuilt completed but differed at the Create Dialog.
Use this second result for the current lobby fixture. Keep the first failure as rejected script evidence.
The other 40 case definitions did not change between these batches.
The totals above combine those 40 cases with the corrected lobby case.
They do not describe one wholly successful batch.

With two original runs, `comparison-00` checks original repeatability.
`comparison-01` compares the first original with the rebuilt.
Each numbered checkpoint folder contains image pairs, differences, and control snapshots.
Image pairs show the reference on the left and the compared run on the right.

## Rebuilt failures

| Case | Result |
| --- | --- |
| multiplayer-offline-lobby | Create Dialog differs; use the corrected batch |
| main-help | Popup becomes a full-screen background |
| campaign-entry | New Name Dialog differs |
| scenario-selection | Page Down and End differ |
| random-player-controls | Team-button pixels differ despite equal recorded control state |
| builder-open-scenario | Scenario-list End checkpoint differs |
| campaign-name-edit | New Name Dialog differs |
| campaign-selection | Route includes the differing New Name Dialog |
| saved-delete-confirmation | Confirmation dialog differs |
| campaign-player-buttons | New Name and Remove Player dialogs differ |
| campaign-name-mouse | Rebuilt text becomes `HarnessUI`, not `UI` |
| multiplayer-name-validation | Name Error dialog differs |

Important measured differences:

- New Name Dialog: original bounds are `[70,125,500,230]`; rebuilt bounds are `[0,0,640,480]`.
- Its edit control starts at `[110,235]` in the original and `[51,229]` in the rebuilt.
- The same mouse drag selects the original text but leaves the rebuilt caret at its end.
- Scenario Page Down selects line 11 in the original and line 24 in the rebuilt.
- At that checkpoint, original top line is 0; rebuilt top line is 13. Both lists contain 25 lines.
- Team change differs in 11 pixels, within `[392,93,396,101]`. Palette entries and recorded control state match.

Sample evidence folders under the full batch:

- `campaign-player-buttons/comparison-01/001`: New Name Dialog.
- `scenario-selection/comparison-01/003`: Page Down.
- `random-player-controls/comparison-01/009`: team-button pixels.

At that point, a shared dialog-layout error was only a hypothesis.
The later source-repair section above records the proved causes and corrections.

## Input and network controls

The harness posts Windows messages instead of invoking control action methods.
It records message dispatch, key state, game cursor queries, and selected control state.
Native edit controls render into memory through `WM_PRINT`.
The composite images contain no desktop screenshot pixels.

Frida 17.8 returned the same import slot for three distinct input imports in a rejected probe.
The harness now reads their distinct IAT RVAs from the verified PE file.
It checks the bindings during execution. It does not replace the game's mouse-position helper.

Windows Firewall displayed prompts during earlier network-enabled lobby exploration.
New EXE paths caused repeated application prompts despite private game desktops.
The UI profile now rejects game `socket` and `WSASocketA/W` calls with `WSAEACCES`.
It preserves Frida's transport. It does not change firewall rules or interactive launches.
This is a bounded test profile, not a general network sandbox.

The offline original probe reached Join Screen and logged two blocked `dpwsockx.dll` socket calls:

`build/runtime/original-20260914T150433155657Z/capture/report.json`

The final offline batches used the same socket restriction on both programs.
No original rendering, RNG result, or simulation result entered the rebuilt process.

## Cleanup and limits

No `empiresx.exe` process remained after qualification.
One interrupted batch left a private registry namespace.
Its saved instrumentation identified it as this harness's batch; cleanup removed that exact namespace.
No private keys remained under `HKCU\Software\AoE1Harness` afterward.

Named checkpoints do not cover every drawing pass, memory value, or execution path.
The scope excludes maps, gameplay, audio, cinematics, and connected multiplayer sessions.
The scenario-launch guard exists, but only start, saved-load, and editor guards have dedicated cases.
Provider Refresh, native provider dialogs, system cursor shapes, and caret blink timing remain unqualified.

Next work: investigate the recorded source differences, rebuild, and rerun the affected cases.
