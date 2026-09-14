# Gameplay replay: first qualification

## Baseline and scope

Commit `437a9cf01` preserves the previous audited repairs, menu harness, tests, and evidence.
This phase changes harness code only. It does not repair game source or promote any function status.
The rebuilt executable remains SHA256 `95e46ebf03109684d589c24683974ac92607005756995f3835a04744f778b1a9`.

The new `game.cmd replay` command uses a configured script and method probes.
It navigates to a single-player random game, pans right, stops panning, and stops after thirty world-update calls.
These are call boundaries, not a claim of thirty simulation ticks.
It uses the same private desktops, assets, registry isolation, offline networking, and debug-clock policy on both programs.
It never injects original game-state or RNG results into rebuilt execution.

## Observations

The configured probes read receiver fields and selected scalar arguments at entry or return.
They cover world setup, Gaia setup, player setup, random-map generation, camera position, and world updates.
Each observation includes typed values, raw bytes, RNG prefix count and hash, and native stack addresses.
Native stacks can be partial. Nearest-symbol annotations do not prove frame ownership.

The full RNG stream is retained as eight-byte site/value records in each capture's `rng.bin`.
The original reference contains 1,220,903 records, or 9,767,224 bytes, for the final script.
This avoids the older menu trace's 10,000-entry limit.
The capture report retains a hash, count, and site dictionary. Raw source-path spelling remains in site events.

Reviewed headers provide the selected field layouts. Original instructions independently confirm important offsets:

- World update loads the RNG field at `+0x78` at `00542F6D`.
- Its player loops read the player count at `+0x3C`, including `005430A7`.
- Player camera setup stores coordinates at `+0x114` and `+0x118` at `004704D3` and `004704D9`.
- World object count is the reviewed `numberObjectsValue` field at `+0x8C`.

This is not a complete memory comparison. It does not traverse object graphs, watch writes, or restore process snapshots.

## Repeatability

The final normal runner defaults to three originals and three rebuilt runs.
It reports original variation and rebuilt variation separately. Incomplete captures remain a separate failure class.

The final three-plus-three batch is `build/runtime/replay-20260914T171258016306Z/report.json`.
Both executable groups pass repeatability, including full RNG recordings. Their cross-build state comparison fails as expected.
The saved recording's contract and input delivery match all six runs.

Parallel stress results:

- Ten originals: `build/runtime/replay-repeat-20260914T170941909346Z/report.json`.
- Ten rebuilt runs: `build/runtime/replay-repeat-20260914T171251657842Z/report.json`.

Both groups pass all within-executable comparisons.
Worker launches span approximately 16 milliseconds and 15 milliseconds, respectively.
All ten worker lifetimes overlap for at least 36 seconds and 32 seconds, respectively.
A live process check also observed eleven games while the rebuilt stress batch overlapped the normal replay batch.
Typical game working sets were about 78 MB during that check.
No variation was observed in the selected fields, input boundaries, or full debug RNG sequences in these stress groups.
This does not prove that every field or future recording is deterministic.

Earlier development batches each ran two originals and one rebuilt game:

- `build/runtime/replay-20260914T165509365894Z/report.json`
- `build/runtime/replay-20260914T165803434395Z/report.json`
- `build/runtime/replay-20260914T165939182546Z/report.json`

All six original captures also match the first original across batches.
Their 87 observations, input delivery boundaries, and complete RNG sequences match.
The third batch replays the second batch's saved `recording.json` and verifies its starting contract.

Camera input is not merely posted and assumed to work:

- The edge input dispatches at update count 5.
- Player 1 camera coordinates change from `(62.5, 127.5)` through `(79.5, 143)`.
- The center input dispatches at update count 15.
- No later camera change appears before the stop boundary.

## Confirmed observed difference

Each qualified batch reports the same rebuilt difference.
The first differing configured observation is `random_map`, return, ordinal 1.
This is the return from `RGE_Game_World::new_random_game`, original address `00542D10`.

| Field | Original | Rebuilt |
| --- | ---: | ---: |
| World object count | 5763 | 5968 |
| Stored random value | 21498 | 5932 |
| RNG records through this boundary | 1220483 | 1160879 |

The initial world seed agrees. Setup already differs before gameplay input begins.
The earliest RNG trace difference is zero-based event 75:

- Original: `rmm_dbct.cpp`, line 508, value 23971.
- Rebuilt: `rmm_tdbc.cpp`, line 185, value 23971.

That event differs in recorded call-site identity, not numeric value.
Later object counts and stored random values provide separate state evidence.
The result narrows the investigation to setup and generation paths. It does not prove the observed function owns the defect.
Its arguments, callees, shared data, and debug call-site labels still require investigation.

The report includes the caller near `RGE_Game_World::new_game` and the full paths to both capture reports.
The first-difference stack is a detection stack, not necessarily the stack that wrote the bad state.

## Rejected experiments

The first small setup-and-idle probe matched between two originals and exposed different rebuilt object counts.
Reports: `original-20260914T163344817625Z`, `original-20260914T163504041057Z`, and `rebuilt-20260914T163512590379Z` under `build/runtime/`.

The first full trace reported a source-path separator difference before a meaningful game-state difference.
`build/runtime/replay-20260914T164103262462Z/report.json` preserves it.
The final profile uses lowercase Windows separators for source-location identity and retains the raw spelling.
It does not normalize numeric state, RNG values, or arbitrary memory.

Stricter receipts then found the camera-stop input at update 16 in one original and 15 in another.
`build/runtime/replay-20260914T164538739443Z/report.json` correctly reports original non-repeatability.

Manual queue draining failed: the injected dispatch did not produce the expected receipt callback.
The original run at `build/runtime/original-20260914T165233677860Z/` retains its diagnostic and exact script.
The final harness does not manually dispatch game messages or skip update functions.

The source and original executable explain the missed scheduling boundary.
`RGE_Base_Game::handle_mouse_move` calls virtual idle at `004211B8`, using slot `+0xBC`.
That path can advance the world outside the main run-loop idle call.
The corrected replay scheduler observes those idle returns after gameplay starts.
Actual dispatch update counts remain part of comparison; late inputs cannot pass silently.

## Validation and next work

The full regression run passed 542 tests and 31 subtests.
Six additional replay tests then passed in the focused 30-test replay suite.
JavaScript syntax and `git diff --check` passed.
The unchanged 41-case menu suite passed completely.
Report: `build/runtime/ui-main-menu-20260914T165829393032Z/report.json`.
The final focused replay suite contains 35 passing tests, including independent variation classification for both executables.
The combined replay and launcher test run passed 51 tests after the final command changes.
Cleanup found no remaining game processes or private registry copies.

Useful next steps are object identity and pointer-aware snapshots, additional setup-input fields, and targeted writer tracing.
First investigate the differing setup interval without assuming its matching status proves its inputs or data are correct.
Do not extend these results to arbitrary human recordings, long sessions, networking, or full gameplay equivalence.
