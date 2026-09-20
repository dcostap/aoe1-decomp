# Record and replay human play on the original game

This experimental profile records received input and produces game-window videos.
Recording uses only the pinned original beta executable.
Replay uses the original by default. A separate command explicitly selects the rebuilt game.

## Record a short session

Run from the repository directory:

```cmd
game.cmd record-original --seconds 60
```

Recording starts at launch. This includes the menu inputs needed to start the match.
Select Single Player, then Random Map or Saved Game. Play in the game window.
Press **F10** to stop. The recorder reserves this key; the game does not receive it.
The normal window close button also saves the recording before the worker closes the game.

The responsive recording limit uses elapsed wall time. Loading and capture overhead remain part of the session.
The default limit is 60 seconds. The maximum requested limit is 180 seconds.
An independent process deadline stops a stalled worker and its game and encoder processes.
Use `--no-time-limit` to stop only with F10 or window close. A 24-hour worker deadline remains.
Recordings have no artificial input-count or file-size limit. Available memory and disk space still apply.

Do not resize or move the game window. Do not switch applications during recording.
Saved Game shows only the repository fixtures, currently `late_game_match`.
Scenarios and the editor remain blocked in this profile.
The profile blocks game network sockets and disables sound and music.

### Record with the scenario editor

```cmd
game.cmd record-original --editor --seconds 120
```

`--editor` selects the responsive v10 editor profile for new recordings.
The scenario editor and scenarios open normally. F10 stops, and the mouse wheel is supported.
The frozen permanent editor recording keeps its v7 profile.
The recording carries its profile, so replay uses the editor profile without another flag.

The responsive editor recording is `config/harness/human-editor-responsive-20260920.json`.
It contains 91,284 inputs, including six mouse-wheel messages. Its SHA-256 is
`36c09dbab2d0fadeefcebca2853f49e06d94fbc474579d3f439ba766524963bd`.
Controlled replay upgrades v10 input to v11. V11 controls timers and paints.
It also samples the game surface during dense input sequences. This keeps review video near 20 FPS.
The default parity suite runs three original and three rebuilt V11 replays.
It compares all 15 pairs for exact inputs, clocks, camera receipts, RNG prefix and count, and RGB samples.
It does not capture complete RNG or world observations for this editor case.
The first V11 qualification passed all 15 pairs. Its batch reports are
`build/runtime/responsive-editor-suite-original/report.json` and
`build/runtime/responsive-editor-suite-rebuilt/report.json`.
A v7 recording compares delivered inputs and video frames. It does not claim world or RNG observation.

The permanent V7 recording is `config/harness/human-editor-20260916.json`.
It contains 3,729 delivered inputs and has SHA-256
`4cac2eb68eb4ef6202eecbf3dacf23fb7c4bc9c48d08fc34618f8976779ed953`.
Run `game.cmd test-parity --editor` to run three original and three rebuilt
replays. This case compares delivered inputs, camera values and receipts, and
exact pre-encode RGB hashes. It does not install world or RNG observers.
The first qualification completed all six runs and preserved all input
messages and game boundaries. Its camera and RGB checks found differences,
including differences between original runs. See
`decomp_notes/human_editor_recording_20260916.md`.

For the first human check, record camera movement, unit selection, a selection drag, movement orders, and gathering.
Keep that first session short. More gameplay coverage comes after input replay qualification.

The command prints paths for `recording.json`, `report.json`, and `video.mp4`.
Keep the whole recording directory and its referenced runtime capture directory.

## Repository save inputs

Harness runs exclude the local runtime's entire `savegame` directory.
They copy only the files pinned by `config/harness/savegames.json` into each new runtime.
Each run gets private copies. The harness checks their hashes before recording or replay.
Missing, changed, or extra runtime saves stop the new profile before game startup.
Normal `game.cmd original` and `game.cmd rebuilt` launches still copy local saves.

The supplied save is `config/harness/savegames/late_game_match.gmx`.
See its [fixture notes](../config/harness/savegames/README.md) for identity and clone setup.
The save file alone is not an input sequence or proof of equal behavior.

New recordings use v8. V8 uses the real elapsed clock and does not sleep the game thread.
It maps delivered input to a 20-millisecond replay schedule without limiting recording input.
Their starting contracts include all saves. Save changes no longer pass as unused inputs.
`--controlled` upgrades v8 recordings to v9. V9 uses the existing controlled timer and paint rules.
The frozen v5 and v6 profiles remain available for their existing recordings.

The frozen v1 through v4 profiles retain their exact script hashes and loading blocks.
The permanent new-game recordings remain unchanged.
`human-v2-core.js` preserves the old shared input code for v2 through v4.
Do not edit that frozen file when changing the current recorder.

The saved-game input case is `config/harness/human-late-game-match.json`.
It preserves 559 messages from a 180,027-millisecond recording.
Its SHA-256 is `07f2a4900af0f0c769224f1c9d5c9f561fce7d2aff16cdfdcaf300797f0fb5a6`.
It is a default case in `game.cmd test-parity`. No recording path or extra option is required.
The suite runs three originals and three rebuilt games with v6 control and checks all 15 pairs.
See [the saved-game check record](../decomp_notes/saved_game_fixture_20260916.md) for results and limits.

Run the strict observation mode before checking saved-game repeatability:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-late-game-match.json --target original --runs 3 --observe --combat --controlled
```

The strict checker requires clock-call counters. The current observer enables those counters only with `--combat`.
`--observe` alone captures world events, but does not supply those counters.
Do not treat equal observations from that mode as a strict repeatability pass.

## Permanent regression case

The accepted recording is now `config/harness/human-accepted-20260914.json`.
It preserves all 324 messages and the original file SHA256:
`a320c5d68b8b6f2e49d5d9963e60bc3455c177deac2909d5795ab19e02510e4d`.
The copy does not replace or change the historical recording.

Run `game.cmd test-parity` for the standard gameplay parity suite.
This command always includes the accepted recording. It needs no recording path.
See [the suite contract](behavior_replay.md#standard-gameplay-parity-suite) for checks and failure rules.

The first standard run completed on 2026-09-14:
`build/runtime/parity-20260914T230838502031Z/report.json`.
The short script passed. All six human runs preserved the 324 messages and their game boundaries.
The human comparison failed. Clock and RGB differences remain visible, including differences between original runs.
Two rebuilt runs matched the complete original RNG stream of 1,224,935 records.
The other rebuilt run first differed at RNG index 1,221,307: equal value 13910, but different callers.
It ended after 329 updates; the original ended after 330.
These observations do not establish the cause or prove a game-code defect.
The suite returned one. It did not treat completed captures as a parity pass.

## Replay the recording

Without an upgrade flag, replay preserves the recorded policy. V1/v2 timing is not repeatable in all runs.
Use the controlled-input mode below for repeatability checks.

Use the printed recording path:

```cmd
game.cmd replay-original build/runtime/human-EXAMPLE/recording.json
```

This runs three fresh originals in parallel by default, on private desktops. It does not switch your desktop.
Each run produces its own game-window video. Open the printed `video.mp4` files in your video player.
Set `--jobs` to one for a serial diagnostic run.

For a targeted development check, use one run:

```cmd
game.cmd replay-original build/runtime/human-EXAMPLE/recording.json --runs 1
```

One run cannot establish repeatability.

## Compare with the rebuilt game

After accepting the original replay, run the same recording on the selected rebuilt executable:

```cmd
game.cmd replay-rebuilt build/runtime/human-EXAMPLE/recording.json
```

This runs three fresh rebuilt processes in parallel by default. It keeps the recorded inputs, clock policy, and starting-contract checks.
The harness validates the rebuilt executable and linker map before resolving its corresponding function hooks.
It does not insert original game state, RNG results, or rendered output into rebuilt execution.
The accepted recording does not need to change when selecting the other executable.

`tools/harness/human_compare.py` compares complete three-run original and rebuilt batch reports.
Use its `--help` output for command syntax.
It checks within-executable variation before reporting cross-build input, camera, counter, RNG-prefix, and video differences.

Use this explicit diagnostic for an existing v1 recording that needs the serialized scheduler:

```cmd
game.cmd replay-original config/harness/human-candidate-20260915.json --runs 1 --upgrade-v1-to-v2
```

The command checks the v1 starting contract against the frozen v1 control template.
The asset comparison excludes unused saves, as described below.
It then uses the v2 scheduler without changing the recording.
The report records both policies, both template hashes, the upgrade rule, and the recording hash.
It also records `same_policy_replay` as false.
The legacy same-policy suite rejects upgraded captures. The current standard suite requires its explicit v4 profile instead.
The generic human comparison labels them as an explicit v1-to-v2 upgrade comparison.

The default profile saves only the first 10,000 RNG observations, plus the total count.
An equal prefix is not a complete RNG match. The comparison reports this limit explicitly.
Video comparison uses recorded pre-encode RGB hashes, with no pixel tolerance or masks.
Equal video timestamps are not necessarily equal simulation boundaries.
The comparison's `complete` flag means all comparisons ran, not that the executables matched.

## Controlled-input replay (v4)

```cmd
game.cmd replay-original build/runtime/human-EXAMPLE/recording.json --controlled
game.cmd replay-rebuilt build/runtime/human-EXAMPLE/recording.json --controlled
```

This accepts unchanged v1 or v2 recordings as input scenarios under explicit v4 control.
New user recordings use v8; their controlled replays use v9.
V4 still handles the preserved v1/v2 recordings. Controlled profiles support replay, not recording.
The lower-level session tool also accepts the v1-only `--upgrade-v1-to-v4` flag.
The `--upgrade-v1-to-v3` flag preserves the rejected timer-only experiment for reproduction.

V4 suppresses dispatched `WM_TIMER` messages on the game thread.
It discards queued root-window paints and validates their complete dirty region. It does not save that region for later.
It sends a new synchronous paint after each eligible idle, including nested idle calls inside input handlers.
It skips another injected paint while one is active. Synchronous game-requested paints remain intact.
The original game still updates through its own idle paths. The harness does not inject simulation state or RNG results.
The replay stops at a Paint boundary eight idle turns after the last recorded input.
The worker retains its independent wall-time deadline.
The old recording duration remains visible as historical metadata; it does not control this new test's terminal turn.

V4 does not reconstruct the old recording's missing timer and paint history.
Reports identify both policies, both script hashes, the unchanged recording hash, and the explicit upgrade rule.
They correctly report `same_policy_replay: false`.
The standard suite compares original and rebuilt runs under this common profile, including their exact new clock values.
The recorded messages, routes, turns, and target panels remain required.
Historical clocks and world-update counts remain visible, but are not expected outputs under a different clock profile.
Fresh original/rebuilt executions must agree exactly on every compared clock and world-update count.

For complete RNG and per-update state evidence, use the lower-level session tool:

```cmd
build\harness-env\Scripts\python.exe tools/harness/human_session.py --recording config/harness/human-candidate-20260915.json --target original --runs 3 --observe --combat --controlled
```

Use `tools/harness/human_repeatability.py --help` to compare complete capture reports.
It checks every pair and returns failure for any difference or missing world/RNG evidence.
Use `game.cmd test-parity` to run all three permanent cases on both executables with these observations.

The session tool's `--message-noise` option adds queued timers and paints every 37 wall-time milliseconds.
This is an explicit robustness stimulus, not a read-only observer or recorded user input.
Reports retain its script hash and posted-message counts. Standard parity rejects these diagnostic captures.
Marked noise requires v4. The checker pins its script hash and requires suppressed-dispatch receipts for both message types.
The repeatability tool requires matching perturbation modes unless the explicit robustness mode applies.
Use its explicit `--noise-resistance` flag to compare quiet and perturbed captures without relaxing any output check.
That mode requires both quiet and perturbed captures. Earlier unmarked noise evidence remains preserved but cannot meet this stronger gate.

The suite covers bounded new-game scenarios and the pinned saved-game recording.
This does not establish general saved-game compatibility. Native blocking modal loops remain unqualified.
The new save profiles permit loading, but this permission is not replay qualification.
Do not interpret a stalled unsupported recording as a game-code defect.
Observer neutrality and complete hidden-state equality remain separate questions.
See [the repair record](../decomp_notes/replay_control_repair_20260915.md) for experiments and exact results.

## Optional read-only diagnostics

`human_session.py --observe` adds full debug RNG tracing and focused state observations during replay.
Add `--rng-only` to omit the additional state hooks. Neither option can record a new human session.
Alternatively, add `--combat` for the focused civilization-effect investigation. It cannot accompany `--rng-only`.
This mode targets the accepted recording's attack updates, sprite changes, and villager 4969.
It also records clock-advance counts. Its observation ranges appear in the report's `observer-ready` event.
Use the tool's `--help` output for the complete command syntax.

These diagnostics remain experimental and disabled by default.
The first original checks changed clock values and RNG totals, although input boundaries and camera positions stayed equal.
They did not establish observer neutrality. Do not use those runs alone to prove another game-code defect.
See `decomp_notes/human_rebuilt_replay_20260914.md` for the preserved checks.
See `decomp_notes/human_rng_investigation_20260914.md` for the later timing and civilization-effect findings.
Use `rng_investigate.py --help` for diagnostic comparisons. The tool requires equal observer scripts and modes.

The optional script does not change recorded inputs or replay controls. It does not replace game outputs.
The report records separate control-script, observer-script, and full injected-script hashes.
Observer overhead can still change execution timing under the current clock policy.

`rng.bin` stores each observed debug RNG result or seed as two little-endian 32-bit values: site ID and value.
`rng_recording.sites` resolves each site ID. The report includes the file hash and record count.
The collector checks the terminal RNG counter against the complete file.
The ten-million-record limit stops the run rather than publishing a complete truncated trace.
The comparison checks complete RNG files when both reports contain them.

State diagnostics record registration and removal, world counters, minimap picks, and camera arguments.
Object snapshots contain ID, master ID, owner, position, hit points, and state at the observed call.
They do not trace every object change or prove complete object lifetime coverage.
Each event records its RNG position, update count, input position, and clock value.
The collector checks event counts and sequence numbers.

The historical terminal `objects` field reads the world's registration counter, not a complete live-object inventory.
Do not infer a missing live object from that counter alone.

## Read the result

The report separates these results:

- `complete`: all requested sessions reached their terminal boundary and produced videos.
- `input_sequence_preserved`: replay received the same message parameters and owned-window routes.
- `recording_fidelity`: timing, update-count, and panel differences from your original session.
- `input_repeatable`: repeated replays received inputs at equal recorded boundaries. One run reports `null`.
- `game_boundaries_repeatable`: idle counts, world-update counts, and panels agree, even when clock values differ.
- `dropped_unrequested_messages`: additional queued input messages blocked during replay.

`complete` does not mean exact replay or equivalent hidden game state.
An equal message sequence can remain useful when its timing differs from the recording.
Review those timing differences and the videos before accepting the scenario.
The current smoke test repeats game input boundaries, but controlled clock values still differ between some runs.
See `decomp_notes/human_replay_20260914.md` for the measured limits. This is not exact replay qualification.

Receipts identify `DispatchMessage` entry, not proof that the handler completed its intended action.
The videos provide an independent visible check. This profile does not yet compare complete object or AI state.

## Clock and input policy

The responsive v8 recording clock starts at 1000 milliseconds and follows wall time.
It does not sleep the game thread. It maps input times to 20-millisecond replay turns.
Controlled replay advances 20 milliseconds at each main-loop idle return and one millisecond per debug-clock call.
The harness paces the controlled replay clock against wall time. Slow execution does not skip controlled time.
Idle advancement prevents the controlled clock from stopping in static menus.
New recordings use the v8 save-fixture policy with the serialized scheduler.
A frozen editor recording uses v7. A new editor recording uses responsive v10.
Controlled editor parity replay uses deterministic v11.
A new editor recording uses responsive v10. Controlled parity replay uses deterministic v11.
A normal replay uses its recorded policy. Neither replaces RNG values or restores original game state.

Recording captures queued mouse movement, button transitions, double-clicks, keyboard transitions, and character messages.
Both modes derive game cursor and key polling from received messages, not unrelated desktop input.
Cursor polling uses the pinned graphics wrapper's logical game coordinates, not desktop coordinates.
This normalized polling model does not reproduce every Windows keyboard-state feature.

A routed input names its target by control id, window class, and visibility.
The editor creates one native edit window for each edit panel, and a hidden panel keeps its window.
So one control id and one class can repeat among the siblings.
Visibility separates them, and Windows sends mouse input to the visible window only.
The same rule drops the game's hidden `InputDisabledWindow`.

The v2 scheduler keeps one recorded message in flight.
It resolves the next window after the exact prior `DispatchMessage` call returns.
This permits a prior handler to create, destroy, or replace a native child control.
It does not retry a missing or ambiguous route.

The accepted 2026-09-14 recording keeps its frozen v1 grouped scheduler and exact template hash.
This compatibility path keeps its existing message ordering.

Input can run in a nested modal message loop.
The v2 scheduler releases input after the matching nested dispatch returns.
An unrelated nested dispatch or A/W forwarding call cannot release it.
The recording does not store dispatch depth, so replay does not prove equal modal-loop nesting.
A handler can enter a modal loop that needs another recorded input before that handler returns.
V2 withholds that input while the handler remains pending. Such a replay can stall and fail its deadline.
Do not treat this unsupported case as a game-code defect.

Replay schedules messages at recorded idle-return boundaries, including nested idle calls during mouse handling.
The normal game loop dispatches them through Windows. The harness checks receipts without calling game command functions directly.
Replay suppresses automatic character translation because the recording already contains character messages.

Native input targets must have an unambiguous owned-window identity.
Unsupported input messages, including wheel and extra mouse-button messages, stop this first version.
Input records have explicit size, count, route, and time limits. Limit failures cannot produce a complete recording.

The starting contract checks assets, graphics configuration, registry inputs, instrumentation, and the original executable.
Legacy new-game replay checks exclude `.gmx` and `.gam` files beneath `savegame`.
The v5/v6 and v8/v9 profiles instead check all save inputs exactly.
Adding, removing, or changing these unused saves does not block replay. All other asset checks remain.
Recording files and full asset manifests remain unchanged for reference.
An incompatible contract stops replay before the game resumes. The harness does not silently update the contract.
An explicit v1-to-v2 upgrade retains the recorded contract and reports the different executed policy.

## Video files

The encoder streams H264 MP4 at 20 frames per controlled second. FFmpeg must be available on `PATH`.
It does not create a large directory of frame images.

Capture reads the game surface and composites visible owned native controls through memory bitmaps.
It never reads the desktop. Videos exclude window borders, title bars, audio, and blinking native text carets.

Video time starts at the first captured Paint boundary.
The capture report records this offset as `video_origin_time_ms` against the input timeline.
The encoder repeats the previous image across capture gaps. It preserves the final image at the next frame boundary.
H264 video is a viewing artifact, not an exact-pixel equality oracle.

Each runtime capture directory contains:

- `video.mp4`: the viewable recording or replay.
- `video.json`: video timing, dimensions, frame counts, and file hash.
- `video-frames.jsonl`: source-frame timestamps and hashes.
- `video.log`: the encoder command and diagnostics.
- `report.json`: input receipts, terminal observations, isolation checks, errors, and video metadata.
- `instrumentation.js`: the exact injected script.

The private automated smoke mode tests the recording machinery. It is not a substitute for your human acceptance recording.
