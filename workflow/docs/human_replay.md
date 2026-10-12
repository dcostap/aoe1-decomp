# Record and replay human play on the original game

This experimental profile records received input and produces game-window videos.
Recording uses only the pinned original beta executable.
Replay uses the original by default. A separate command explicitly selects the rebuilt game.

## Record anything as a test case

```cmd
game.cmd record
```

Play whatever you like: random map, saved game, scenarios, the scenario editor.
Press **F10** or close the game window to stop. The session is recorded with
deterministic traces and no time limit, then imported automatically as a local
traced case named `rec-<date>-<time>` (or `--name`). `game.cmd test-traces`
replays it on both executables from then on. See
[exact fast replay](#exact-fast-replay-from-a-traced-recording) for what is checked.

Do not drag, resize, or switch away from the game window while recording.
Switching away stops the recording.
Title-bar presses (caption, system menu, minimize, maximize) never reach the game. The recorder turns them
into `WM_NULL` before the trace stores them, so the window cannot be dragged. A real drag runs
the game inside Windows' move loop until the mouse is released, and replay cannot reproduce that.
Recordings made before this block can contain a drag. Their replay then fails on both
executables at that message with `update count differs`.

To keep the part of such a recording before the drag, cut it:

```cmd
game.cmd cut-trace CASE --at-update N --name NEW-CASE
```

The new case replays CASE only through world update N. Replay stops at the first message-pump
poll after that update. Each trace record carries the update, input, and RNG counts, so the new
oracle still comes from the recording. It checks the RNG count and the per-update RNG
checkpoints, update and input counts, world time, and the camera at the cut. It also checks the
per-update state hashes between executables. It does not know the final object count, the whole-trace
RNG hash, or which files the game had written by then. Remove the uncut case from
`local/harness/traces.json` if it can never pass.

Every file the game writes during the session, such as saves or scenarios, becomes
part of the check. Replay must write the same files with the same bytes.
Saved Game lists the pinned fixture pool plus every save in `local/harness/savegames/`.
A save made in one recording is not available when a later recording starts.
To start a recording from a personal save, copy it into that folder first.
A recording pins the save's hash. If the file changes later, that case fails its save check.

### Start from a chaos save

```cmd
game.cmd chaos-start
game.cmd record
```

`chaos-start` makes a stress-test start with the original game, then `record` records play from it.
It starts a normal random-map game with eight players and the game's own map generation.
The defaults are a Gigantic Continental map, Stone Age, and Hardest computer players.
At the first world update it adds, per player:

- villagers up to 20;
- 20,000 of each resource;
- a population limit of 200;
- a 200-unit army of randomly chosen land combat units in a block formation near the town centre.

By default the game is a forced free-for-all (`--diplomacy ffa`).
Without teams, the normal random-map setup starts every computer player neutral. About ten seconds
in, the computer AI turns every still-neutral computer into one alliance against the human
(`taimdmd.cpp`). Its tactical AI also drifts each update toward neutral or allied stances.
The generator makes every player an enemy of every other, turns allied victory off, and locks every
stance in each computer's diplomacy module. Locked stances cannot drift.
After reloading, it lets the game run for `--check-seconds` of game time (default 15) and
fails if any stance is not still enemy. Use `--diplomacy standard` to keep the normal random-map
diplomacy. Tributes you send can still change a computer's stance.

The army mixes infantry, archers, cavalry, chariots, elephants, siege, and priests.
Heroes and boats are left out. The engine's placement check accepts every unit, so a crowded or wet site
spreads the army over several blocks. The game's own save function writes the result
to `local/harness/savegames/chaos-<seed>.gmx`. The generator then reloads that save
and keeps screenshots under `build/chaos-start/`. In `record`, load it from
**Single Player > Saved Game**. Run `game.cmd chaos-start --help` for the map, age, army,
villager, resource, and seed options. A given seed repeats the civilizations and
the army mix and positions. It does not give a byte-identical save: a few hundred bytes of
clock-dependent computer-player state vary.

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
Saved Game shows the repository fixtures: `late_game_match`,
`late_game_match_2`, and `new_game_15mins_in`.
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
`workflow/decomp_notes/human_editor_recording_20260916.md`.

For the first human check, record camera movement, unit selection, a selection drag, movement orders, and gathering.
Keep that first session short. More gameplay coverage comes after input replay qualification.

The command prints paths for `recording.json`, `report.json`, and `video.mp4`.
Keep the whole recording directory and its referenced runtime capture directory.

### Chain a long game through save checkpoints

Each human recording starts in a fresh runtime. Use a save bundle to continue from
an earlier original capture:

```cmd
game.cmd save-bundle build/runtime/original-EXAMPLE/capture/report.json config/harness/save-bundles/chain-01/checkpoint-01
game.cmd record-original --no-time-limit --save-bundle config/harness/save-bundles/chain-01/checkpoint-01
```

The first command copies the original runtime save files and writes their hashes.
The second recording carries that bundle in its starting contract.
Each capture report lists changed `.gmx` and `.gam` files under `save_outputs`.
Original and rebuilt replay comparisons check those output hashes and sizes.
Create the next bundle from the original capture, not the rebuilt capture.

## Repository save inputs

Harness runs exclude the local runtime's entire `savegame` directory.
They copy only the files pinned by the selected save bundle into each new runtime.
Without `--save-bundle`, the selected bundle is `config/harness/savegames.json`.
Each run gets private copies. The harness checks their hashes before recording or replay.
Strict replay uses exactly the save files pinned by that recording's contract.
This keeps older recordings valid when the common fixture pool grows.
Missing, changed, or extra runtime saves stop the new profile before game startup.
Normal `game.cmd original` and `game.cmd rebuilt` launches still copy local saves.

The committed common fixture is `config/harness/savegames/late_game_match.gmx`.
The pool also pins the personal saves `late_game_match_2.gmx` and `new_game_15mins_in.gmx`,
which stay in the gitignored `local/harness/savegames/` folder. The pool omits them when absent.
See the [fixture notes](../../config/harness/savegames/README.md) for their hashes.
A save file alone is not an input sequence or proof of equal behavior.

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

Two untraced original-play recordings are kept locally in `local/harness/recordings/`.
They are not suite cases: paced replay of their dense mouse input would take hours.

- `human-late-game-match-2.json` starts from `late_game_match_2.gmx`.
  It records 19,101 messages over 102,516 milliseconds.
  Its SHA-256 is `65632e5ce39e01aec67a1aa0523775264844b5e437fcd3f2a7598c41495de837`.
- `human-new-game-15mins-in.json` starts from `new_game_15mins_in.gmx`.
  It records 17,239 messages over 75,484 milliseconds.
  Its SHA-256 is `bdf5af40dd40ad60d3c08a6f6ba6323b3c43959cae882bbb3cff512ddb901b82`.

Both recordings use v8 capture and support v9 controlled replay.
Neither is a standard suite case or has a parity pass.
The first controlled replay stopped at its 397-second limit after about 2,665 of 19,101 inputs.

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

## Exact fast replay from a traced recording

This is the preferred way to add gameplay regression cases. Record with traces:

```cmd
game.cmd record-original --deterministic-trace --no-time-limit
```

Play as usual and press **F10** to stop. The recorder stores every value the game
reads from its clock (`debug_timeGetTime`), every `PeekMessage` and `GetMessage`
result with its message, and the full RNG trace. It zero-fills game heap
allocations; `ManagedArray` reads uninitialized memory otherwise. After an empty
message poll, the recorder sleeps about 1 ms. The stock loop busy-polls, and every
spin would become trace data that replay must consume. The game reads only recorded
clocks, so replay needs no matching sleep.

Add the recording as a permanent case, then run it:

```cmd
game.cmd import-trace build/runtime/human-EXAMPLE --name my-case
game.cmd test-traces --case my-case
```

Import stores `recording.json.xz` and `messages.bin.xz` under
`local/harness/traces/<name>/` and pins both in `local/harness/traces.json`.
Traces are personal gameplay data: `local/` is gitignored, so the repository
ships the harness but not the recordings. Without local traces, `test-traces`
reports a skip, and `test-parity` records the traces worker as skipped.
The recording embeds an oracle from its own session: RNG count and hash,
per-update RNG checkpoints, update and input counts, world, camera, and every
file the game created, changed, or removed in its runtime folder. Import stores
the bytes of those files under `outputs/` in the case folder and pins them.
Each replay must write exactly the same files; a difference reports the path and
the first differing byte, against the recording and between the executables.
Recordings imported before write tracking compare written files only between
the two executables.
The RNG trace is not stored; any exact original replay regenerates it.

Replay uses a native engine (`trace_replay.c`, `trace_replay.js`) instead of the
paced V8 core. It never waits for wall time, so independent replays run in
parallel without drift. The engine reproduces the V8 replay's game-visible effects:
recorded clocks and pump results, no-op `TranslateMessage`, and virtual key and
cursor state. It also keeps zero-filled allocations and the same isolation.
Any extra or missing clock read, poll, or message stops the run at that trace
record with the update and input counts. That boundary is the first divergence.

`replay-original --fast` and `replay-rebuilt --fast` run one traced recording
directly. Fast replay captures only the terminal frame. For video, replay the same
recording without `--fast`; that path uses the paced JavaScript replay.

Evidence, 2026-09-27: an 81-second random-map session with 13,296 inputs,
3,308 world updates, and 1,034,079 RNG calls replayed exactly on both executables.
Both matched the RNG hash, world, camera, and trace consumption. Six parallel
original replays were identical. Native replay took about 16 to 30 s on a loaded
machine. A single recorded clock value changed by 50 ms stopped the replay at
update 1,778. Recordings made before the idle throttle still replay exactly, but
their traces are larger.

Before 2026-09-27, `human_alloc_fill.js` hooked `operator new` at the original's
address, `0x0054B6F0`, on both executables. On the rebuilt image that address
belongs to a different function, and its return values were zero-filled.
Earlier traced rebuilt replays are invalid. The hook now resolves `??2@YAPAXI@Z`
through the rebuilt map like every other hook.

## Replay the recording

Without an upgrade flag, replay preserves the recorded policy. V1/v2 timing is not repeatable in all runs.
Use the controlled-input mode below for repeatability checks.

Use the printed recording path:

```cmd
game.cmd replay-original build/runtime/human-EXAMPLE/recording.json
```

This runs three fresh originals one at a time on private desktops. Parallel runs
are disabled because they showed drift. `--jobs` set to one is allowed; higher values
are rejected. It does not switch your desktop.
Each run produces its own game-window video. Open the printed `video.mp4` files in your video player.
The command uses one worker by default.

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

This runs three fresh rebuilt processes one at a time. It keeps the recorded
inputs, clock policy, and starting-contract checks. Values above one for
`--jobs` are rejected while parallel drift is under review.
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
See `workflow/decomp_notes/human_rebuilt_replay_20260914.md` for the preserved checks.
See `workflow/decomp_notes/human_rng_investigation_20260914.md` for the later timing and civilization-effect findings.
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
See `workflow/decomp_notes/human_replay_20260914.md` for the measured limits. This is not exact replay qualification.

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
